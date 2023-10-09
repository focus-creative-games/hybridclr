#pragma once

#include <stdint.h>
#include "CommonDef.h"

namespace hybridclr
{
	class RuntimeApi
	{
	public:
		static void RegisterInternalCalls();

		static int32_t LoadMetadataForAOTAssembly(Il2CppArray* dllData, int32_t mode);

		static uint32_t GetInterpreterThreadObjectStackSize();
		static void SetInterpreterThreadObjectStackSize(uint32_t size);

		static uint32_t GetInterpreterThreadFrameStackSize();
		static void SetInterpreterThreadFrameStackSize(uint32_t size);

		static uint32_t GetInterpreterThreadExceptionFlowSize();
		static void SetInterpreterThreadExceptionFlowSize(uint32_t size);
	};
}