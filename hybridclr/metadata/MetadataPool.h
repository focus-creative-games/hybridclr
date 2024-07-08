#pragma once

#include "../CommonDef.h"

#include "metadata/GenericMetadata.h"
#include "vm/MetadataAlloc.h"

namespace hybridclr
{
namespace metadata
{

	template<typename T>
	T* MetadataMallocT()
	{
		return (T*)HYBRIDCLR_METADATA_MALLOC(sizeof(T));
	}

	template<typename T>
	T* MetadataCallocT(size_t count)
	{
		return (T*)HYBRIDCLR_METADATA_CALLOC(count, sizeof(T));
	}

	class MetadataPool
	{
	public:
		static void Initialize();
		static const Il2CppType* GetPooledIl2CppType(const Il2CppType& type);
		static Il2CppType* ShallowCloneIl2CppType(const Il2CppType* type);
		static const Il2CppArrayType* GetPooledIl2CppArrayType(const Il2CppType* elementType, uint32_t rank);
	};
}
}