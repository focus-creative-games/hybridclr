#include <unordered_map>

#include "MethodBodyCache.h"

#include "MetadataModule.h"
#include "AOTHomologousImage.h"
#include "Opcodes.h"
#include "MetadataDef.h"

#include "utils/HashUtils.h"
#include "../RuntimeConfig.h"

namespace hybridclr
{
namespace metadata
{
	struct ImageTokenPair
	{
		hybridclr::metadata::Image* image;
		uint32_t token;
	};

	struct ImageTokenPairHash
	{
		size_t operator()(const ImageTokenPair& s) const noexcept
		{
			return il2cpp::utils::HashUtils::Combine((size_t)s.image, (size_t)s.token);
		}
	};

	struct ImageTokenPairEqualTo
	{
		bool operator()(const ImageTokenPair& p1, const ImageTokenPair& p2) const
		{
			return p1.image == p2.image && p1.token == p2.token;
		}
	};

	enum class InlineMode : uint8_t
	{
		None,
		Inlineable,
		NotInlineable,
	};

	struct MethodBodyCacheInfo
	{
		MethodBody* methodBody;
		int32_t accessVersion;
		uint16_t accessCount;
		InlineMode inlineMode;
	};

	constexpr int32_t kMinShrinkMethodBodyCacheInterval = 256;
	static bool s_enableShrinkMethodBodyCache = true;
	static int32_t s_methodBodyCacheVersion = 0;
	static Il2CppHashMap<ImageTokenPair, MethodBodyCacheInfo*, ImageTokenPairHash, ImageTokenPairEqualTo> s_methodBodyCache;


	static MethodBodyCacheInfo* GetOrInitMethodBodyCache(hybridclr::metadata::Image* image, uint32_t token)
	{
		ImageTokenPair key = { image, token };
		auto it = s_methodBodyCache.find(key);
		if (it != s_methodBodyCache.end())
		{
			return it->second;
		}
		MethodBody* methodBody = image->GetMethodBody(token);
		MethodBodyCacheInfo* ci = (MethodBodyCacheInfo*)HYBRIDCLR_MALLOC_ZERO(sizeof(MethodBodyCacheInfo));
		*ci = { methodBody, s_methodBodyCacheVersion, 0, InlineMode::None};
		s_methodBodyCache[key] = ci;
		return ci;
	}

	MethodBody* MethodBodyCache::GetMethodBody(hybridclr::metadata::Image* image, uint32_t token)
	{
		MethodBodyCacheInfo* ci = GetOrInitMethodBodyCache(image, token);
		ci->accessVersion = s_methodBodyCacheVersion;
		++ci->accessCount;
		return ci->methodBody;
	}

	static void ShrinkMethodBodyCache(int32_t shrinkMethodBodyCacheInterval)
	{
		if (s_methodBodyCache.size() <= RuntimeConfig::GetMaxMethodBodyCacheSize())
		{
			return;
		}

		int32_t expiredVersion = s_methodBodyCacheVersion - shrinkMethodBodyCacheInterval;
		for (auto it = s_methodBodyCache.begin(); it != s_methodBodyCache.end(); )
		{
			MethodBodyCacheInfo* ci = it->second;
			// add extra interval when accessCount exceeded 1
			int32_t accessVersion = ci->accessVersion + (ci->accessCount - 1) * shrinkMethodBodyCacheInterval;
			if (accessVersion < expiredVersion)
			{
				if (ci->methodBody)
				{
					ci->methodBody->~MethodBody();
					HYBRIDCLR_FREE(ci->methodBody);
				}
				HYBRIDCLR_FREE(ci);
				s_methodBodyCache.erase(it++);
			}
			else
			{
				++it;
			}
		}
	}

	void MethodBodyCache::EnableShrinkMethodBodyCache(bool shrink)
	{
		s_enableShrinkMethodBodyCache = shrink;
		if (shrink)
		{
			++s_methodBodyCacheVersion;

			int32_t shrinkMethodBodyCacheInterval = std::max(RuntimeConfig::GetMaxMethodBodyCacheSize() / 2, kMinShrinkMethodBodyCacheInterval);
			if (s_methodBodyCacheVersion % shrinkMethodBodyCacheInterval == 0)
			{
				ShrinkMethodBodyCache(shrinkMethodBodyCacheInterval);
			}
		}
	}

	static bool IsILCodeInlineable(const byte* ilcodeStart, uint32_t codeSize)
	{
		const byte* codeEnd = ilcodeStart + codeSize;
		const byte* ip = ilcodeStart;

		while (ip < codeEnd)
		{
			const OpCodeInfo* oc = DecodeOpCodeInfo(ip, codeEnd);
			IL2CPP_ASSERT(oc);
			int32_t opCodeSize = GetOpCodeSize(ip, oc);
			ip += opCodeSize;
			int32_t nextOffset = (int32_t)(ip - ilcodeStart);
			IL2CPP_ASSERT(nextOffset >= 0 && nextOffset <= (int32_t)codeSize);

			switch (oc->flow)
			{
			case FlowType::Branch:
			case FlowType::CondBranch:
			case FlowType::Throw:
			{
				return false;
			}
			}
		}
		IL2CPP_ASSERT(ip == codeEnd);
		return true;
	}

	static bool ComputeInlinable(metadata::Image* image, uint32_t token)
	{
		metadata::MethodBody* methodBody = MethodBodyCache::GetMethodBody(image, token);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			return false;
		}

		if (methodBody->codeSize > RuntimeConfig::GetMaxInlineableMethodBodySize() || !methodBody->exceptionClauses.empty())
		{
			return false;
		}

		return IsILCodeInlineable(methodBody->ilcodes, methodBody->codeSize);
	}

	bool MethodBodyCache::IsInlineable(const MethodInfo* methodInfo)
	{
		IL2CPP_ASSERT(methodInfo->isInterpterImpl);

		metadata::Image* image = MetadataModule::GetUnderlyingInterpreterImage(methodInfo);
		IL2CPP_ASSERT(image);
		MethodBodyCacheInfo* ci = GetOrInitMethodBodyCache(image, methodInfo->token);
		ci->accessVersion = s_methodBodyCacheVersion;
		++ci->accessCount;
		if (ci->inlineMode != InlineMode::None)
		{
			return ci->inlineMode == InlineMode::Inlineable;
		}
		bool inlineable = ComputeInlinable(image, methodInfo->token);
		ci->inlineMode = inlineable ? InlineMode::Inlineable : InlineMode::NotInlineable;
		return inlineable;
	}

	void MethodBodyCache::DisableInline(const MethodInfo* methodInfo)
	{
		IL2CPP_ASSERT(methodInfo->isInterpterImpl);
		metadata::Image* image = MetadataModule::GetUnderlyingInterpreterImage(methodInfo);
		IL2CPP_ASSERT(image);
		MethodBodyCacheInfo* ci = GetOrInitMethodBodyCache(image, methodInfo->token);
		ci->inlineMode = InlineMode::NotInlineable;
	}
}
}