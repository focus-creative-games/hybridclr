#pragma once

#include "Image.h"
#include "IAssemblyMetadataResolver.h"

namespace huatuo
{
namespace metadata
{
	class InterpreterAssemblyMetadataResolver : public IAssemblyMetadataResolver
	{
	public:
		InterpreterAssemblyMetadataResolver(Image* image) : _image(image) {}
		Il2CppString* GetIl2CppUserStringFromRawIndex(StringIndex index) override;
		Il2CppClass* GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		const MethodInfo* GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		const FieldInfo* GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		const void* GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		void GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig) override;

		const MethodInfo* FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod) override;

	private:
		Image* const _image;
	};
}
}