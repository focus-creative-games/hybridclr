#include "InterpreterAssemblyMetadataResolver.h"

namespace huatuo
{
namespace metadata
{
	
	Il2CppString* InterpreterAssemblyMetadataResolver::GetIl2CppUserStringFromRawIndex(StringIndex index)
	{
		return _image->GetIl2CppUserStringFromRawIndex(index);
	}

	Il2CppClass* InterpreterAssemblyMetadataResolver::GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		return _image->GetClassFromToken(token, klassGenericContainer, methodGenericContainer, genericContext);
	}

	const MethodInfo* InterpreterAssemblyMetadataResolver::GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		return _image->GetMethodInfoFromToken(token, klassGenericContainer, methodGenericContainer, genericContext);
	}

	const FieldInfo* InterpreterAssemblyMetadataResolver::GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		return _image->GetFieldInfoFromToken(token, klassGenericContainer, methodGenericContainer, genericContext);
	}

	const void* InterpreterAssemblyMetadataResolver::GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		return _image->GetRuntimeHandleFromToken(token, klassGenericContainer, methodGenericContainer, genericContext);
	}

	void InterpreterAssemblyMetadataResolver::GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig)
	{
		_image->GetStandAloneMethodSigFromToken(token, klassGenericContainer, methodGenericContainer, genericContext, methodSig);
	}

	const MethodInfo* InterpreterAssemblyMetadataResolver::FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod)
	{
		return _image->FindImplMethod(klass, matchMethod);
	}
}
}