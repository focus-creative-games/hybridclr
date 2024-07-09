#include "MetadataPool.h"

#include "utils/MemoryPool.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataLock.h"
#include "vm/GlobalMetadata.h"

#include "MetadataModule.h"

namespace hybridclr
{
namespace metadata
{

	using il2cpp::utils::HashUtils;

	constexpr int kMaxPrimitiveType = (int)IL2CPP_TYPE_OBJECT;

	static bool s_initializedMetadataPool = false;

	static Il2CppType s_primitiveTypes[(int)kMaxPrimitiveType + 1];
	static Il2CppType s_byRefPrimitiveTypes[(int)kMaxPrimitiveType + 1];

	class Il2CppArrayTypeHash
	{
	public:
		size_t operator()(const Il2CppArrayType* t1) const
		{
			return Hash(t1);
		}

		static size_t Hash(const Il2CppArrayType* t1);
	};

	class Il2CppTypeFullHash
	{
	public:
		size_t operator()(const Il2CppType* t1) const
		{
			return Hash(t1);
		}

		static size_t Hash(const Il2CppType* t1)
		{
			size_t hash = t1->type;

			hash = HashUtils::Combine(hash, t1->byref);

			hash = il2cpp::utils::HashUtils::Combine(hash, t1->attrs);
			//hash = il2cpp::utils::HashUtils::Combine(hash, t1->num_mods);
			hash = il2cpp::utils::HashUtils::Combine(hash, t1->pinned);
			//hash = il2cpp::utils::HashUtils::Combine(hash, t1->valuetype);

			switch (t1->type)
			{
			case IL2CPP_TYPE_VALUETYPE:
			case IL2CPP_TYPE_CLASS:
			{
				return HashUtils::Combine(hash, reinterpret_cast<size_t>(t1->data.typeHandle));
			}
			case IL2CPP_TYPE_SZARRAY:
			case IL2CPP_TYPE_PTR:
			{
				return HashUtils::Combine(hash, Hash(t1->data.type));
			}
			case IL2CPP_TYPE_ARRAY:
			{
				const Il2CppArrayType* a = t1->data.array;
				// dont' compute sizes and lobounds
				hash = HashUtils::Combine(hash, Il2CppArrayTypeHash::Hash(a));
				return hash;
			}
			case IL2CPP_TYPE_GENERICINST:
			{
				return HashUtils::Combine(hash, (size_t)t1->data.generic_class);
			}
			case IL2CPP_TYPE_VAR:
			case IL2CPP_TYPE_MVAR:
				return HashUtils::Combine(hash, reinterpret_cast<size_t>(t1->data.genericParameterHandle));
			default:
				return hash;
			}
			return hash;
		}
	};

	size_t Il2CppArrayTypeHash::Hash(const Il2CppArrayType* t1)
	{
		size_t hash = t1->rank;
		hash = HashUtils::Combine(hash, t1->numsizes);
		hash = HashUtils::Combine(hash, t1->numlobounds);
		hash = HashUtils::Combine(hash, Il2CppTypeFullHash::Hash(t1->etype));

		for (uint8_t i = 0; i < t1->numsizes; ++i)
		{
			hash = HashUtils::Combine(hash, t1->sizes[i]);
		}
		for (uint8_t i = 0; i < t1->numlobounds; ++i)
		{
			hash = HashUtils::Combine(hash, t1->lobounds[i]);
		}
		return hash;
	}

	class Il2CppArrayTypeEqualityComparer
	{
	public:
		bool operator()(const Il2CppArrayType* t1, const Il2CppArrayType* t2) const
		{
			return AreEqual(t1, t2);
		}

		static bool AreEqual(const Il2CppArrayType* t1, const Il2CppArrayType* t2);
	};

	class Il2CppTypeFullEqualityComparer
	{
	public:
		bool operator()(const Il2CppType* t1, const Il2CppType* t2) const
		{
			return AreEqual(t1, t2);
		}

		static bool AreEqual(const Il2CppType* t1, const Il2CppType* t2)
		{
			if (t1->type != t2->type)
			{
				return false;
			}

			if (t1->byref != t2->byref
				|| t1->attrs != t2->attrs
				|| t1->pinned != t2->pinned)
			{
				return false;
			}

			switch (t1->type)
			{
			case IL2CPP_TYPE_VALUETYPE:
			case IL2CPP_TYPE_CLASS:
				return t1->data.typeHandle == t2->data.typeHandle;
			case IL2CPP_TYPE_PTR:
			case IL2CPP_TYPE_SZARRAY:
				return AreEqual(t1->data.type, t2->data.type);

			case IL2CPP_TYPE_ARRAY:
			{
				const Il2CppArrayType* a1 = t1->data.array;
				const Il2CppArrayType* a2 = t2->data.array;
				return Il2CppArrayTypeEqualityComparer::AreEqual(a1, a2);
			}
			case IL2CPP_TYPE_GENERICINST:
			{
				return t1->data.generic_class == t2->data.generic_class;
			}
			case IL2CPP_TYPE_VAR:
			case IL2CPP_TYPE_MVAR:
				return t1->data.genericParameterHandle == t2->data.genericParameterHandle;
			default:
				return true;
			}
			return true;
		}
	};

	bool Il2CppArrayTypeEqualityComparer::AreEqual(const Il2CppArrayType* a1, const Il2CppArrayType* a2)
	{
		if (a1->rank != a2->rank || a1->numsizes != a2->numsizes || a1->numlobounds != a2->numlobounds)
		{
			return false;
		}
		for (uint8_t i = 0; i < a1->numsizes; ++i)
		{
			if (a1->sizes[i] != a2->sizes[i])
				return false;
		}
		for (uint8_t i = 0; i < a1->numlobounds; ++i)
		{
			if (a1->lobounds[i] != a2->lobounds[i])
				return false;
		}
		return Il2CppTypeFullEqualityComparer::AreEqual(a1->etype, a2->etype);
	}


	class Il2CppArrayTypeHash2
	{
	public:
		size_t operator()(const Il2CppArrayType* t1) const
		{
			return Hash(t1);
		}

		static size_t Hash(const Il2CppArrayType* t1)
		{
			size_t hash = t1->rank;
			hash = HashUtils::Combine(hash, Il2CppTypeFullHash::Hash(t1->etype));
			return hash;
		}
	};

	class Il2CppArrayTypeEqualityComparer2
	{
	public:
		bool operator()(const Il2CppArrayType* t1, const Il2CppArrayType* t2) const
		{
			return AreEqual(t1, t2);
		}

		static bool AreEqual(const Il2CppArrayType* a1, const Il2CppArrayType* a2)
		{
			if (a1->rank != a2->rank)
			{
				return false;
			}
			return Il2CppTypeFullEqualityComparer::AreEqual(a1->etype, a2->etype);
		}
	};


	typedef Il2CppHashSet<const Il2CppType*, Il2CppTypeFullHash, Il2CppTypeFullEqualityComparer> Il2CppTypeHashSet;
	static Il2CppTypeHashSet* s_Il2CppTypePool = nullptr;

	typedef Il2CppHashSet<const Il2CppArrayType*, Il2CppArrayTypeHash2, Il2CppArrayTypeEqualityComparer2> Il2CppArrayTypeHashSet;
	Il2CppArrayTypeHashSet* s_Il2CppArrayTypePool = nullptr;


	static void InitMetadataPool()
	{
		IL2CPP_ASSERT(!s_initializedMetadataPool);
		s_initializedMetadataPool = true;
		std::memset(s_primitiveTypes, 0, sizeof(s_primitiveTypes));
		std::memset(s_byRefPrimitiveTypes, 0, sizeof(s_byRefPrimitiveTypes));

		for (int i = 0; i <= kMaxPrimitiveType; i++)
		{
			Il2CppType& type = s_primitiveTypes[i];
			type.type = (Il2CppTypeEnum)i;
			bool isValueType = i != IL2CPP_TYPE_OBJECT && i != IL2CPP_TYPE_STRING && i != IL2CPP_TYPE_VOID;
			SET_IL2CPPTYPE_VALUE_TYPE(type, isValueType);

			Il2CppType& byRefType = s_byRefPrimitiveTypes[i];
			byRefType.type = (Il2CppTypeEnum)i;
			byRefType.byref = 1;
		}
		s_Il2CppTypePool = new Il2CppTypeHashSet();
		s_Il2CppArrayTypePool = new Il2CppArrayTypeHashSet();
	}

	static const Il2CppType* TryGetPrimitiveType(const Il2CppType& originalType)
	{
		if (!s_initializedMetadataPool)
		{
			InitMetadataPool();
		}
		if (originalType.attrs || originalType.num_mods || originalType.pinned)
		{
			return nullptr;
		}
		Il2CppTypeEnum type = originalType.type;
		switch (type)
		{
		case IL2CPP_TYPE_VOID:
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R4:
		case IL2CPP_TYPE_R8:
		case IL2CPP_TYPE_STRING:
		case IL2CPP_TYPE_I:
		case IL2CPP_TYPE_U:
		case IL2CPP_TYPE_OBJECT:
			return originalType.byref ? s_byRefPrimitiveTypes + (int)type : s_primitiveTypes + (int)type;
		case IL2CPP_TYPE_VALUETYPE:
		case IL2CPP_TYPE_CLASS:
		{
			const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)originalType.data.typeHandle;
			if (typeDef)
			{
				if (originalType.byref)
				{
#if HYBRIDCLR_UNITY_2019
					return il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->byrefTypeIndex);
#endif
				}
				else
				{
					return il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->byvalTypeIndex);
				}
			}
			return nullptr;
		}
		default:
			return nullptr;
		}
	}

	void MetadataPool::Initialize()
	{
		//InitMetadataPool();

	}

	static bool NeedCache(const Il2CppType& originalType)
	{
		Il2CppTypeEnum type = originalType.type;
		switch (type)
		{
		case IL2CPP_TYPE_VOID:
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R4:
		case IL2CPP_TYPE_R8:
		case IL2CPP_TYPE_STRING:
		case IL2CPP_TYPE_I:
		case IL2CPP_TYPE_U:
		case IL2CPP_TYPE_OBJECT:
			return true;
		case IL2CPP_TYPE_PTR:
		case IL2CPP_TYPE_SZARRAY:
			return NeedCache(*originalType.data.type);
		case IL2CPP_TYPE_VALUETYPE:
		case IL2CPP_TYPE_CLASS:
		{
			return originalType.data.typeHandle == nullptr;
		}
		default:
			return false;
		}
	}

	static Il2CppType* DeepCloneIl2CppType(const Il2CppType& type)
	{
		Il2CppType* newType = MetadataMallocT<Il2CppType>();
		*newType = type;

		return newType;
	}

	const Il2CppType* MetadataPool::GetPooledIl2CppType(const Il2CppType& type)
	{
		const Il2CppType* pooledType = TryGetPrimitiveType(type);
		if (pooledType)
		{
			return pooledType;
		}

		bool needCache = NeedCache(type);

		if (needCache)
		{
			auto it = s_Il2CppTypePool->find(&type);
			if (it != s_Il2CppTypePool->end())
				return *it;
		}
		Il2CppType* newType = DeepCloneIl2CppType(type);
		if (needCache)
		{
			auto ret = s_Il2CppTypePool->insert(newType);
			IL2CPP_ASSERT(ret.second);
		}
		return newType;
	}

	Il2CppType* MetadataPool::ShallowCloneIl2CppType(const Il2CppType* type)
	{
		Il2CppType* newType = MetadataMallocT<Il2CppType>();
		*newType = *type;

		return newType;
	}

	const Il2CppArrayType* MetadataPool::GetPooledIl2CppArrayType(const Il2CppType* elementType, uint32_t rank)
	{
		Il2CppArrayType type = {};
		type.etype = elementType;
		type.rank = rank;

		bool needCache = NeedCache(*elementType);

		if (needCache)
		{
			auto it = s_Il2CppArrayTypePool->find(&type);
			if (it != s_Il2CppArrayTypePool->end())
				return *it;
		}

		Il2CppArrayType* newType = MetadataMallocT<Il2CppArrayType>();
		*newType = type;

		if (needCache)
		{
			auto ret = s_Il2CppArrayTypePool->insert(newType);
			IL2CPP_ASSERT(ret.second);
		}
		return newType;
	}
}
}