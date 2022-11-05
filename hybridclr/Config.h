#pragma once

#include "CommonDef.h"

namespace hybridclr
{
	class Config
	{

	public:
		Config()
		{
			_threadObjectStackSize = 1024 * 128;
			_threadFrameStackSize = 1024 * 2;
			_threadExceptionFlowSize = 512;
		}

		static Config& GetIns()
		{
			return s_ins;
		}

		uint32_t GetInterpreterThreadObjectStackSize()
		{
			return _threadObjectStackSize;
		}

		void SetInterpreterThreadObjectStackSize(uint32_t count)
		{
			_threadObjectStackSize = count;
		}

		uint32_t GetInterpreterThreadFrameStackSize()
		{
			return _threadFrameStackSize;
		}

		void SetInterpreterThreadFrameStackSize(uint32_t count)
		{
			_threadFrameStackSize = count;
		}

		uint32_t GetInterpreterThreadExceptionFlowSize()
		{
			return _threadExceptionFlowSize;
		}

		void SetInterpreterThreadExceptionFlowSize(uint32_t count)
		{
			_threadExceptionFlowSize = count;
		}

	private:
		static Config s_ins;

	private:
		uint32_t _threadObjectStackSize;
		uint32_t _threadFrameStackSize;
		uint32_t _threadExceptionFlowSize;
	};
}



