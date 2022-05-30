#pragma once
#include "../CommonDef.h"

#include "MetadataDef.h"

namespace huatuo
{
namespace metadata
{

	class IAssemblyMetadataResolver
	{
	public:
		virtual Il2CppString* GetIl2CppUserStringFromRawIndex(StringIndex index) = 0;
		virtual Il2CppClass* GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual const MethodInfo* GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual const FieldInfo* GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual const void* GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual void GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig) = 0;
		virtual const MethodInfo* FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod) = 0;
	};
}
}