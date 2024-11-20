#pragma once

#include "CommonDef.h"

namespace hybridclr
{
	enum class RuntimeOptionId
	{
		InterpreterThreadObjectStackSize = 1,
		InterpreterThreadFrameStackSize = 2,
		InterpreterThreadExceptionFlowSize = 3,
		MaxMethodBodyCacheSize = 4,
		MaxMethodInlineDepth = 5,
		MaxInlineableMethodBodySize = 6,
	};

	class RuntimeConfig
	{

	public:

		static int32_t GetRuntimeOption(RuntimeOptionId optionId);
		static void SetRuntimeOption(RuntimeOptionId optionId, int32_t value);

		static uint32_t GetInterpreterThreadObjectStackSize();
		static uint32_t GetInterpreterThreadFrameStackSize();
		static uint32_t GetInterpreterThreadExceptionFlowSize();
		static int32_t GetMaxMethodBodyCacheSize();
		static int32_t GetMaxMethodInlineDepth();
		static int32_t GetMaxInlineableMethodBodySize();
	};
}



