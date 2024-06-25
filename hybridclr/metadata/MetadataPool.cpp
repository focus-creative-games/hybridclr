#include "MetadataPool.h"

#include "utils/Il2CppHashMap.h"
#include "utils/Il2CppHashSet.h"
#include "utils/HashUtils.h"
#include "utils/MemoryPool.h"
#include "metadata/Il2CppTypeHash.h"
#include "metadata/Il2CppTypeCompare.h"
#include "metadata/Il2CppGenericInstHash.h"
#include "metadata/Il2CppGenericInstCompare.h"
#include "metadata/Il2CppGenericMethodHash.h"
#include "metadata/Il2CppGenericMethodCompare.h"
#include "metadata/Il2CppGenericClassHash.h"
#include "metadata/Il2CppGenericClassCompare.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataLock.h"
#include "vm/GlobalMetadata.h"

#include "MetadataModule.h"

namespace hybridclr
{
namespace metadata
{
	using il2cpp::utils::HashUtils;

	
	static size_t s_methodInfoSize = 0;

	static il2cpp::utils::MemoryPool* s_metadataPool = nullptr;

	baselib::ReentrantLock s_metadataPoolLock;

#define USE_METAPOOL_LOCK() il2cpp::os::FastAutoLock lock(&s_metadataPoolLock)


	template<typename T>
	T* MetadataMallocT()
	{
		return (T*)s_metadataPool->Malloc(sizeof(T));
	}

	template<typename T>
	T* MetadataCallocT(size_t count)
	{
		return (T*)s_metadataPool->Calloc(count, sizeof(T));
	}

	void MetadataPool::Initialize()
	{
		s_metadataPool = new il2cpp::utils::MemoryPool();
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