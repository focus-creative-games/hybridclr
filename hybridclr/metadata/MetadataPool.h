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
		return (T*)HYBRIDCLR_MALLOC_ZERO(sizeof(T));
	}

	template<typename T>
	T* MetadataCallocT(size_t count)
	{
		return (T*)HYBRIDCLR_CALLOC(count, sizeof(T));
	}

	class MetadataPool
	{
	public:
		static void Initialize();
		static const Il2CppType* GetPooledIl2CppType(const Il2CppType& type);
		static Il2CppType* ShallowCloneIl2CppType(const Il2CppType* type);
	};
}
}