#include "RuntimeConfig.h"

#include "vm/Exception.h"

namespace hybridclr
{
	static int32_t s_threadObjectStackSize = 1024 * 128;
	static int32_t s_threadFrameStackSize = 1024 * 2;
	static int32_t s_threadExceptionFlowSize = 512;



	int32_t RuntimeConfig::GetRuntimeOption(RuntimeOptionId optionId)
	{
		switch (optionId)
		{	
		case hybridclr::RuntimeOptionId::InterpreterThreadObjectStackSize:
			return s_threadObjectStackSize;
		case hybridclr::RuntimeOptionId::InterpreterThreadFrameStackSize:
			return s_threadFrameStackSize;
		case hybridclr::RuntimeOptionId::InterpreterThreadExceptionFlowSize:
			return s_threadExceptionFlowSize;
		default:
		{
			TEMP_FORMAT(optionIdStr, "%d", optionId);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException(optionIdStr, "invalid runtime option id"));
			return 0;
		}
		}
	}

	void RuntimeConfig::SetRuntimeOption(RuntimeOptionId optionId, int32_t value)
	{
		switch (optionId)
		{
		case hybridclr::RuntimeOptionId::InterpreterThreadObjectStackSize:
			s_threadObjectStackSize = value;
			break;
		case hybridclr::RuntimeOptionId::InterpreterThreadFrameStackSize:
			s_threadFrameStackSize = value;
			break;
		case hybridclr::RuntimeOptionId::InterpreterThreadExceptionFlowSize:
			s_threadExceptionFlowSize = value;
			break;
		default:
		{
			TEMP_FORMAT(optionIdStr, "%d", optionId);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException(optionIdStr, "invalid runtime option id"));
			break;
		}
		}
	}
}
