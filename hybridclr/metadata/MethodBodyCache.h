#pragma once

#include "Image.h"

namespace hybridclr
{
namespace metadata
{
	class MethodBodyCache
	{
	public:
		static MethodBody* GetMethodBody(hybridclr::metadata::Image* image, uint32_t token);
		static void EnableShrinkMethodBodyCache(bool shrink);

		static bool IsInlineable(const MethodInfo* method);
		static void DisableInline(const MethodInfo* method);
	};
}
}