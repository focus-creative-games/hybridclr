#pragma once

#include "BasicBlockSpliter.h"

#include "../metadata/Image.h"
#include "../interpreter/Instruction.h"
#include "../interpreter/Engine.h"
#include "../interpreter/InterpreterDefs.h"

namespace hybridclr
{
namespace transform
{
	class HiTransform
	{
	public:
		static interpreter::InterpMethodInfo* Transform(const MethodInfo* methodInfo);
	};
}
}