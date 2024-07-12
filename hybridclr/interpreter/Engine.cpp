#include "Engine.h"

#include "codegen/il2cpp-codegen.h"

#include "Interpreter.h"
#include "MemoryUtil.h"

namespace hybridclr
{
namespace interpreter
{
	InterpFrame* InterpFrameGroup::EnterFrameFromInterpreter(const MethodInfo* method, StackObject* argBase)
	{
#if IL2CPP_ENABLE_PROFILER
		il2cpp_codegen_profiler_method_enter(method);
#endif
		const InterpMethodInfo* imi = (const InterpMethodInfo*)method->interpData;
		int32_t oldStackTop = _machineState.GetStackTop();
		StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize - imi->argStackObjectSize);
		InterpFrame* newFrame = _machineState.PushFrame();
		*newFrame = { method, argBase, oldStackTop, nullptr, nullptr, nullptr, 0, 0, _machineState.GetLocalPoolBottomIdx() };
		PUSH_STACK_FRAME(method);
		return newFrame;
	}


	InterpFrame* InterpFrameGroup::EnterFrameFromNative(const MethodInfo* method, StackObject* argBase)
	{
#if IL2CPP_ENABLE_PROFILER
		il2cpp_codegen_profiler_method_enter(method);
#endif
		const InterpMethodInfo* imi = (const InterpMethodInfo*)method->interpData;
		int32_t oldStackTop = _machineState.GetStackTop();
		StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize);
		InterpFrame* newFrame = _machineState.PushFrame();
		*newFrame = { method, stackBasePtr, oldStackTop, nullptr, nullptr, nullptr, 0, 0, _machineState.GetLocalPoolBottomIdx() };

		// if not prepare arg stack. copy from args
		if (imi->args)
		{
			IL2CPP_ASSERT(imi->argCount == metadata::GetActualArgumentNum(method));
			CopyStackObject(stackBasePtr, argBase, imi->argStackObjectSize);
		}
		PUSH_STACK_FRAME(method);
		return newFrame;
	}

	InterpFrame* InterpFrameGroup::LeaveFrame()
	{
		IL2CPP_ASSERT(_machineState.GetFrameTopIdx() > _frameBaseIdx);
		POP_STACK_FRAME();
		InterpFrame* frame = _machineState.GetTopFrame();
#if IL2CPP_ENABLE_PROFILER
		il2cpp_codegen_profiler_method_exit(frame->method);
#endif
		if (frame->exFlowBase)
		{
			_machineState.SetExceptionFlowTop(frame->exFlowBase);
		}
		_machineState.PopFrame();
		_machineState.SetStackTop(frame->oldStackTop);
		_machineState.SetLocalPoolBottomIdx(frame->oldLocalPoolBottomIdx);
		return _machineState.GetFrameTopIdx() > _frameBaseIdx ? _machineState.GetTopFrame() : nullptr;
	}
}
}

