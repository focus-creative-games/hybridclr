#include "CommonDef.h"

#include "metadata/AOTHomologousImage.h"
#include "HybridCLRConfig.h"

extern "C"
{

	IL2CPP_EXPORT int32_t DEFAULT_CALL RuntimeApi_LoadMetadataForAOTAssembly(void* dllBytes, uint32_t dllSize)
	{
		return hybridclr::metadata::AOTHomologousImage::LoadMetadataForAOTAssembly(dllBytes, dllSize);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadObjectStackSize()
	{
		return hybridclr::HybridCLRConfig::GetInterpreterThreadObjectStackSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadObjectStackSize(uint32_t size)
	{
		hybridclr::HybridCLRConfig::SetInterpreterThreadObjectStackSize(size);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadFrameStackSize()
	{
		return hybridclr::HybridCLRConfig::GetInterpreterThreadFrameStackSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadFrameStackSize(uint32_t size)
	{
		hybridclr::HybridCLRConfig::SetInterpreterThreadFrameStackSize(size);
	}
}
