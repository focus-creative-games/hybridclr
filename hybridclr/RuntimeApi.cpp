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
		return hybridclr::HybridCLRConfig::GetIns().GetInterpreterThreadObjectStackSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadObjectStackSize(uint32_t size)
	{
		hybridclr::HybridCLRConfig::GetIns().SetInterpreterThreadObjectStackSize(size);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadFrameStackSize()
	{
		return hybridclr::HybridCLRConfig::GetIns().GetInterpreterThreadFrameStackSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadFrameStackSize(uint32_t size)
	{
		hybridclr::HybridCLRConfig::GetIns().SetInterpreterThreadFrameStackSize(size);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadExceptionFlowSize()
	{
		return hybridclr::HybridCLRConfig::GetIns().GetInterpreterThreadExceptionFlowSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadExceptionFlowSize(uint32_t size)
	{
		hybridclr::HybridCLRConfig::GetIns().SetInterpreterThreadExceptionFlowSize(size);
	}
}
