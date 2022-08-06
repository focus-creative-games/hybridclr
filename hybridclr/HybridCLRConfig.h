#pragma once

#include "CommonDef.h"

namespace hybridclr
{
	class HybridCLRConfig
	{

	public:
		static HybridCLRConfig& GetIns()
		{
			return _ins;
		}

		static uint32_t GetInterpreterThreadObjectStackSize()
		{
			return s_threadObjectStackSize;
		}

		static void SetInterpreterThreadObjectStackSize(uint32_t count)
		{
			s_threadObjectStackSize = count;
		}

		static uint32_t GetInterpreterThreadFrameStackSize()
		{
			return s_threadFrameStackSize;
		}

		static void SetInterpreterThreadFrameStackSize(uint32_t count)
		{
			s_threadFrameStackSize = count;
		}

	private:
		static HybridCLRConfig _ins;

	private:
		static uint32_t s_threadObjectStackSize;
		static uint32_t s_threadFrameStackSize;
	};
}



