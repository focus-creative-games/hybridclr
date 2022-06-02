#include "CommonDef.h"

#include "metadata/AOTHomologousImage.h"
#include "HuatuoConfig.h"


IL2CPP_EXPORT int32_t HuatuoApi_LoadMetadataForAOTAssembly(Il2CppReflectionAssembly* aotAssembly, void* dllBytes, uint32_t dllSize)
{
	return huatuo::metadata::AOTHomologousImage::LoadMetadataForAOTAssembly(aotAssembly, dllBytes, dllSize);
}

IL2CPP_EXPORT uint32_t HuatuoApi_GetInterpreterThreadObjectStackSize()
{
	return huatuo::HuatuoConfig::GetInterpreterThreadObjectStackSize();
}

IL2CPP_EXPORT void HuatuoApi_GetInterpreterThreadObjectStackSize(uint32_t size)
{
	huatuo::HuatuoConfig::SetInterpreterThreadObjectStackSize(size);
}

IL2CPP_EXPORT uint32_t HuatuoApi_GetInterpreterThreadFrameStackSize()
{
	return huatuo::HuatuoConfig::GetInterpreterThreadFrameStackSize();
}

IL2CPP_EXPORT void HuatuoApi_SetInterpreterThreadFrameStackSize(uint32_t size)
{
	huatuo::HuatuoConfig::SetInterpreterThreadFrameStackSize(size);
}