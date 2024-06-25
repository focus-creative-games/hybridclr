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
#define SUPPORT_PRIMITIVE_TYPE_CACHE 1

	constexpr int kMaxPrimitiveType = (int)IL2CPP_TYPE_OBJECT;

	static Il2CppType s_primitiveTypes[(int)kMaxPrimitiveType + 1];
	static Il2CppType s_byRefPrimitiveTypes[(int)kMaxPrimitiveType + 1];

	static void InitPrimitiveTypes()
	{
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
	}

	static const Il2CppType* TryGetPrimitiveType(const Il2CppType& originalType)
	{
#if SUPPORT_PRIMITIVE_TYPE_CACHE
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
#else
		return nullptr;
#endif
	}

	void MetadataPool::Initialize()
	{
		InitPrimitiveTypes();

		//s_Il2CppTypePool.resize(1024 * 64);
		//s_Il2CppArrayTypePool.resize(1024);
		//s_Il2CppGenericInstPool.resize(10240);
		//s_Il2CppGenericClassPool.resize(10240);
		//s_Il2CppGenericMethodPool.resize(10240);
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
		return DeepCloneIl2CppType(type);
	}

	Il2CppType* MetadataPool::ShallowCloneIl2CppType(const Il2CppType* type)
	{
		Il2CppType* newType = MetadataMallocT<Il2CppType>();
		*newType = *type;

		return newType;
	}

}
}