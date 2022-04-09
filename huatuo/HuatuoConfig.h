#pragma once

#include "CommonDef.h"

namespace huatuo
{
	class HuatuoConfig
	{

	public:
		static HuatuoConfig& GetIns()
		{
			return _ins;
		}

		static uint32_t GetMaxStackObjectCount()
		{
			return kMaxStackObjectCount;
		}

		static uint32_t GetMaxFrameCount()
		{
			return kMaxFrameCount;
		}

	private:
		static HuatuoConfig _ins;



	private:
		static const uint32_t kMaxStackObjectCount = 1024 * 128;
		static const uint32_t kMaxFrameCount = 1024;
	};
}



