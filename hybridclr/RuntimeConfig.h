#pragma once

#include "CommonDef.h"

namespace hybridclr
{
	enum class RuntimeOptionId
	{
		InterpreterThreadObjectStackSize = 1,
		InterpreterThreadFrameStackSize = 2,
		InterpreterThreadExceptionFlowSize = 3,
	};

	class RuntimeConfig
	{

	public:

		static int32_t GetRuntimeOption(RuntimeOptionId optionId);
		static void SetRuntimeOption(RuntimeOptionId optionId, int32_t value);

		static uint32_t GetInterpreterThreadObjectStackSize()
		{
			return (uint32_t)GetRuntimeOption(RuntimeOptionId::InterpreterThreadObjectStackSize);
		}

		static uint32_t GetInterpreterThreadFrameStackSize()
		{
			return (uint32_t)GetRuntimeOption(RuntimeOptionId::InterpreterThreadFrameStackSize);
		}

		static uint32_t GetInterpreterThreadExceptionFlowSize()
		{
			return (uint32_t)GetRuntimeOption(RuntimeOptionId::InterpreterThreadExceptionFlowSize);
		}
	};
}



