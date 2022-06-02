#pragma once
#include "Image.h"

namespace huatuo
{
namespace metadata
{
	class AOTHomologousImage : public Image
	{
	public:

		static int32_t LoadMetadataForAOTAssembly(Il2CppReflectionAssembly* aotAssembly, void* dllBytes, uint32_t dllSize);

		static AOTHomologousImage* FindImageByAssembly(const Il2CppAssembly* ass);

		AOTHomologousImage(const Il2CppAssembly* aotAssembly) : _aotAssembly(aotAssembly)
		{

		}

		LoadImageErrorCode Load(const byte* imageData, size_t length)
		{
			return _rawImage.Load(imageData, length);
		}

		void InitRuntimeMetadatas();

		MethodBody* GetMethodBody(uint32_t token) override;

		uint32_t AddIl2CppTypeCache(Il2CppType& type) override;
		const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index) override;
		Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index) override;
		const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index) override;
		const Il2CppType* GetIl2CppTypeFromRawIndex(uint32_t index) const override;
		const Il2CppTypeDefinition* GetTypeFromRawIndex(uint32_t index) const override;
		const FieldDetail& GetFieldDetailFromRawIndex(uint32_t index) override;

		Il2CppString* GetIl2CppUserStringFromRawIndex(StringIndex index) override;
		Il2CppClass* GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		const MethodInfo* GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		const FieldInfo* GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		const void* GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) override;
		void GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig) override;

		const MethodInfo* FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod) override;

	private:
		const Il2CppAssembly* _aotAssembly;
	};
}
}