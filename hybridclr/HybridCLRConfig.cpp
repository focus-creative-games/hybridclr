#include "HybridCLRConfig.h"

namespace hybridclr
{
	HybridCLRConfig HybridCLRConfig::_ins;

	uint32_t HybridCLRConfig::s_threadObjectStackSize = 1024 * 128;
	uint32_t HybridCLRConfig::s_threadFrameStackSize = 1024 * 2;
}