#include "AOTHomologousImage.h"

#include "vm/MetadataLock.h"

namespace huatuo
{
namespace metadata
{
	std::vector<AOTHomologousImage*> s_images;

	enum LoadAOTMetadataErrorCode
	{
		EXIST = 10,
	};

	int32_t AOTHomologousImage::LoadMetadataForAOTAssembly(Il2CppReflectionAssembly* aotAssembly, void* dllBytes, uint32_t dllSize)
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
		if (FindImageByAssembly(aotAssembly->assembly))
		{
			return (int)LoadAOTMetadataErrorCode::EXIST;
		}

		AOTHomologousImage* image = new AOTHomologousImage(aotAssembly->assembly);
		LoadImageErrorCode err = image->Load((byte*)CopyBytes(dllBytes, dllSize), dllSize);
		if (err != LoadImageErrorCode::OK)
		{
			return (int)err;
		}
		image->InitRuntimeMetadatas();
		s_images.push_back(image);
		return 0;
	}

	AOTHomologousImage* AOTHomologousImage::FindImageByAssembly(const Il2CppAssembly* ass)
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
		for (AOTHomologousImage* image : s_images)
		{
			if (image->_aotAssembly == ass)
			{
				return image;
			}
		}
		return nullptr;
	}

	void AOTHomologousImage::InitRuntimeMetadatas()
	{

	}

	MethodBody* AOTHomologousImage::GetMethodBody(uint32_t token)
	{
		return nullptr;
	}

	uint32_t AOTHomologousImage::AddIl2CppTypeCache(Il2CppType& type)
	{
		return 0;
	}

	const Il2CppType* AOTHomologousImage::GetIl2CppTypeFromRawTypeDefIndex(uint32_t index)
	{
		return nullptr;
	}

	Il2CppGenericContainer* AOTHomologousImage::GetGenericContainerByRawIndex(uint32_t index)
	{
		return nullptr;
	}

	const Il2CppMethodDefinition* AOTHomologousImage::GetMethodDefinitionFromRawIndex(uint32_t index)
	{
		return nullptr;
	}

	const Il2CppType* AOTHomologousImage::GetIl2CppTypeFromRawIndex(uint32_t index) const
	{
		return nullptr;
	}

	const Il2CppTypeDefinition* AOTHomologousImage::GetTypeFromRawIndex(uint32_t index) const
	{
		return nullptr;
	}

	const FieldDetail& AOTHomologousImage::GetFieldDetailFromRawIndex(uint32_t index)
	{
		return *(FieldDetail*)nullptr;
	}

	Il2CppString* AOTHomologousImage::GetIl2CppUserStringFromRawIndex(StringIndex index)
	{
		return nullptr;
	}

	Il2CppClass* AOTHomologousImage::GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		return nullptr;
	}

	const MethodInfo* AOTHomologousImage::GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{

		return nullptr;
	}

	const FieldInfo* AOTHomologousImage::GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{

		return nullptr;
	}

	const void* AOTHomologousImage::GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{

		return nullptr;
	}

	void AOTHomologousImage::GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig)
	{

	}

	const MethodInfo* AOTHomologousImage::FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod)
	{

		return nullptr;
	}

}
}

