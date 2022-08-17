#pragma once

#include "BasicBlockSpliter.h"

#include "../metadata/Image.h"
#include "../interpreter/Instruction.h"
#include "../interpreter/Engine.h"

namespace hybridclr
{
namespace transform
{
	class HiTransform
	{
	public:
		static void Transform(metadata::Image* image, const MethodInfo* methodInfo, metadata::MethodBody& body, interpreter::InterpMethodInfo& result);
	};
}
}