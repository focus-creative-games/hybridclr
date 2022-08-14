#include "Engine.h"

#include "Interpreter.h"
#include "MemoryUtil.h"

namespace hybridclr
{
namespace interpreter
{

	InterpFrame* InterpFrameGroup::EnterFrame(const InterpMethodInfo* imi, StackObject* argBase, bool withArgStack)
	{
		ptrdiff_t oldStackTop = _machineState.GetStackTop();
		InterpFrame* newFrame;
		if (withArgStack)
		{
			StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize - imi->argStackObjectSize);

			newFrame = _machineState.PushFrame();
			*newFrame = { imi, argBase, oldStackTop, nullptr, nullptr, nullptr, 0, 0 };
		}
		else
		{
			StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize);

			newFrame = _machineState.PushFrame();
			*newFrame = { imi, stackBasePtr, oldStackTop, nullptr, nullptr, nullptr, 0, 0 };

			// if not prepare arg stack. copy from args
			if (!withArgStack && imi->args)
			{
				IL2CPP_ASSERT(imi->argCount == metadata::GetActualArgumentNum(imi->method));
				if (imi->isTrivialCopyArgs)
				{
					CopyStackObject(stackBasePtr, argBase, imi->argStackObjectSize);
				}
				else
				{
					CopyArgs(stackBasePtr, argBase, imi->args, imi->argCount, imi->argStackObjectSize);
				}
			}
		}
		PUSH_STACK_FRAME(imi->method);
		return newFrame;
	}

}
}

