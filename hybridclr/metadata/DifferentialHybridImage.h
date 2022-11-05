#pragma once
#include <unordered_set>
#include <unordered_map>

#include "InterpreterImage.h"

namespace hybridclr
{
namespace metadata
{


	struct DifferentialHybridOption
	{
		std::vector<uint32_t> notChangeTokens;


		bool Unmarshal(BlobReader& reader)
		{
			uint32_t signature;
			if (!reader.TryRead32(signature) || signature != 0xABCDABCD)
			{
				return false;
			}
			uint32_t count;
			if (!reader.TryRead32(count))
			{
				return false;
			}
			for (uint32_t i = 0; i < count; i++)
			{
				uint32_t token;
				if (!reader.TryRead32(token))
				{
					return false;
				}
				notChangeTokens.push_back(token);
			}
			
			return reader.IsEmpty();
		}
	};

	struct TypeMapping
	{
		bool inited;
		const char* name;
		const Il2CppTypeDefinition* interpType;
		const Il2CppTypeDefinition* aotType;
	};

	struct MethodMapping
	{
		const Il2CppMethodDefinition* interpMethod;
		const Il2CppMethodDefinition* aotMethod;
		Il2CppMethodPointer aotMethodPointer;
		Il2CppMethodPointer aotAdjustorThunk;
		InvokerMethod aotMethodInvoker;
	};

	class DifferentialHybridImage : public InterpreterImage
	{
	public:
		DifferentialHybridImage(uint32_t imageIndex, const DifferentialHybridOption& options) : InterpreterImage(imageIndex),
			_notChangeMethodTokens(options.notChangeTokens.begin(), options.notChangeTokens.end())
		{
		}

		virtual bool IsHotPatch() const override
		{
			return true;
		}

		const Il2CppTypeDefinition* GetOriginType(const Il2CppTypeDefinition* type)
		{
			uint32_t index = GetTypeRawIndex(type);
			IL2CPP_ASSERT(index < (uint32_t)_typeMappings.size());
			return _typeMappings[index].aotType;
		}

		Il2CppMethodPointer TryGetMethodPointer(const Il2CppMethodDefinition* method);
		Il2CppMethodPointer TryGetMethodPointer(const MethodInfo* method);
		Il2CppMethodPointer TryGetAdjustThunkMethodPointer(const Il2CppMethodDefinition* method);
		Il2CppMethodPointer TryGetAdjustThunkMethodPointer(const MethodInfo* method);
		InvokerMethod TryGetMethodInvoker(const Il2CppMethodDefinition* method);

		void BuildIl2CppImage(Il2CppImage* image, Il2CppAssembly* originAssembly);

		void InitRuntimeMetadatas() override;
	private:
		void InitTypeMapping(TypeMapping& type);
		void InitTypeMappings();
		void InitMethodMappings();

		const Il2CppAssembly* _originAssembly;
		const Il2CppImage* _originImage;
		std::unordered_set<uint32_t> _notChangeMethodTokens;
		std::unordered_map<uint32_t, const Il2CppMethodDefinition*> _hotPatchMethodToken2OriginAOTMethodDefs;
		std::vector<TypeMapping> _typeMappings;
		std::vector<MethodMapping> _methodMappings;
	};
}
}