#include "CommonDef.h"

#include "metadata/MetadataModule.h"
#include "Config.h"

extern "C"
{

	IL2CPP_EXPORT int32_t DEFAULT_CALL RuntimeApi_LoadMetadataForAOTAssembly(void* dllBytes, uint32_t dllSize, int32_t mode)
	{
		return (int32_t)hybridclr::metadata::MetadataModule::LoadMetadataForAOTAssembly(dllBytes, dllSize, (hybridclr::metadata::HomologousImageMode)mode);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadObjectStackSize()
	{
		return hybridclr::Config::GetIns().GetInterpreterThreadObjectStackSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadObjectStackSize(uint32_t size)
	{
		hybridclr::Config::GetIns().SetInterpreterThreadObjectStackSize(size);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadFrameStackSize()
	{
		return hybridclr::Config::GetIns().GetInterpreterThreadFrameStackSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadFrameStackSize(uint32_t size)
	{
		hybridclr::Config::GetIns().SetInterpreterThreadFrameStackSize(size);
	}

	IL2CPP_EXPORT uint32_t DEFAULT_CALL RuntimeApi_GetInterpreterThreadExceptionFlowSize()
	{
		return hybridclr::Config::GetIns().GetInterpreterThreadExceptionFlowSize();
	}

	IL2CPP_EXPORT void DEFAULT_CALL RuntimeApi_SetInterpreterThreadExceptionFlowSize(uint32_t size)
	{
		hybridclr::Config::GetIns().SetInterpreterThreadExceptionFlowSize(size);
	}
}
