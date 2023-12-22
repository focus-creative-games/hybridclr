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

		static int32_t GetRuntimeOption(int32_t optionId);
		static void SetRuntimeOption(int32_t optionId, int32_t value);
	};
}