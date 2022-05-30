#include "AOTAssemblyMetadataResolver.h"

namespace huatuo
{
	namespace metadata
	{

		Il2CppString* AOTAssemblyMetadataResolver::GetIl2CppUserStringFromRawIndex(StringIndex index)
		{
			return nullptr;
		}

		Il2CppClass* AOTAssemblyMetadataResolver::GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
		{
			return nullptr;
		}

		const MethodInfo* AOTAssemblyMetadataResolver::GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
		{

			return nullptr;
		}

		const FieldInfo* AOTAssemblyMetadataResolver::GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
		{

			return nullptr;
		}

		const void* AOTAssemblyMetadataResolver::GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
		{

			return nullptr;
		}

		void AOTAssemblyMetadataResolver::GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig)
		{

		}

		const MethodInfo* AOTAssemblyMetadataResolver::FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod)
		{

			return nullptr;
		}
	}
}