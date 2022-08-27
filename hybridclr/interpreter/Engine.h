#pragma once

#include <stack>

#include "../CommonDef.h"

#include "gc/GarbageCollector.h"
#include "vm/Exception.h"
#include "vm/StackTrace.h"

#include "../metadata/MetadataUtil.h"
#include "../HybridCLRConfig.h"

#include "InterpreterDefs.h"
#include "MemoryUtil.h"
#include "MethodBridge.h"


//#if DEBUG
//#define PUSH_STACK_FRAME(method) do { \
//	Il2CppStackFrameInfo stackFrameInfo = { method, (uintptr_t)method->methodPointer }; \
//	il2cpp::vm::StackTrace::PushFrame(stackFrameInfo); \
//} while(0)
//
//#define POP_STACK_FRAME() do { il2cpp::vm::StackTrace::PopFrame(); } while(0)
//
//#else 
#define PUSH_STACK_FRAME(method)
#define POP_STACK_FRAME() 
//#endif

namespace hybridclr
{
namespace interpreter
{

	class MachineState
	{
	public:
		MachineState()
		{
			HybridCLRConfig& hc = HybridCLRConfig::GetIns();
			_stackSize = hc.GetInterpreterThreadObjectStackSize();
			_stackBase = (StackObject*)il2cpp::gc::GarbageCollector::AllocateFixed(hc.GetInterpreterThreadObjectStackSize() * sizeof(StackObject), nullptr);
			std::memset(_stackBase, 0, _stackSize * sizeof(StackObject));
			_stackTopIdx = 0;

			_frameBase = (InterpFrame*)IL2CPP_CALLOC(hc.GetInterpreterThreadFrameStackSize(), sizeof(InterpFrame));
			_frameCount = hc.GetInterpreterThreadFrameStackSize();
			_frameTopIdx = 0;

			_exceptionFlowBase = (ExceptionFlowInfo*)IL2CPP_CALLOC(hc.GetInterpreterThreadExceptionFlowSize(), sizeof(ExceptionFlowInfo));
			_exceptionFlowCount = hc.GetInterpreterThreadExceptionFlowSize();
			_exceptionFlowTopIdx = 0;
		}

		~MachineState()
		{
			il2cpp::gc::GarbageCollector::FreeFixed(_stackBase);
		}

		StackObject* AllocArgments(uint32_t argCount)
		{
			if (_stackTopIdx + argCount > _stackSize)
			{
				il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetStackOverflowException("AllocArguments"));
			}
			StackObject* args = _stackBase + _stackTopIdx;
			_stackTopIdx += argCount;
			return args;
		}

		StackObject* GetStackBasePtr() const
		{
			return _stackBase;
		}

		ptrdiff_t GetStackTop() const
		{
			return _stackTopIdx;
		}

		StackObject* AllocStackSlot(uint32_t slotNum)
		{
			if (_stackTopIdx + slotNum > _stackSize)
			{
				il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetStackOverflowException("AllocStackSlot"));
			}
			StackObject* dataPtr = _stackBase + _stackTopIdx;
			_stackTopIdx += slotNum;
#if DEBUG
			std::memset(dataPtr, 0xEA, slotNum * sizeof(StackObject));
#endif
			return dataPtr;
		}

		void SetStackTop(ptrdiff_t oldTop)
		{
			_stackTopIdx = oldTop;
		}

		uint32_t GetFrameTopIdx() const
		{
			return _frameTopIdx;
		}

		InterpFrame* PushFrame()
		{
			if (_frameTopIdx >= _frameCount)
			{
				il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetStackOverflowException("AllocFrame"));
			}
			return _frameBase + _frameTopIdx++;
		}

		void PopFrame()
		{
			IL2CPP_ASSERT(_frameTopIdx > 0);
			--_frameTopIdx;
		}

		void PopFrameN(uint32_t count)
		{
			IL2CPP_ASSERT(count > 0 && _frameTopIdx >= count);
			_frameTopIdx -= count;
		}

		InterpFrame* GetTopFrame() const
		{
			if (_frameTopIdx > 0)
			{
				return _frameBase + _frameTopIdx - 1;
			}
			else
			{
				return nullptr;
			}
		}

		ExceptionFlowInfo* AllocExceptionFlow(int32_t count)
		{
			if (_exceptionFlowTopIdx + count < _exceptionFlowCount)
			{
				ExceptionFlowInfo* efi = _exceptionFlowBase + _exceptionFlowTopIdx;
				_exceptionFlowTopIdx += count;
				return efi;
			}
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("AllocExceptionFlowZero"));
			return nullptr;
		}

		uint32_t GetExceptionFlowTopIdx() const
		{
			return _exceptionFlowTopIdx;
		}

		void SetExceptionFlowTopIdx(uint32_t exTopIdx)
		{
			_exceptionFlowTopIdx = exTopIdx;
		}

		void SetExceptionFlowTop(ExceptionFlowInfo* top)
		{
			_exceptionFlowTopIdx = (int32_t)(top - _exceptionFlowBase);
			IL2CPP_ASSERT(_exceptionFlowTopIdx >= 0 && _exceptionFlowTopIdx <= _exceptionFlowCount);
		}

		void PushExecutingImage(const Il2CppImage* image)
		{
			_executingImageStack.push(image);
		}

		void PopExecutingImage()
		{
			_executingImageStack.pop();
		}

		const Il2CppImage* GetTopExecutingImage() const
		{
			if (_executingImageStack.empty())
			{
				return nullptr;
			}
			else
			{
				return _executingImageStack.top();
			}
		}

		void CollectFrames(il2cpp::vm::StackFrames* stackFrames)
		{
			for (uint32_t i = 0; i < _frameTopIdx; i++)
			{
				InterpFrame* frame = _frameBase + i;
				const MethodInfo* method = frame->method->method;
				Il2CppStackFrameInfo stackFrameInfo = {
					method
#if HYBRIDCLR_UNITY_2020_OR_NEW
					, (uintptr_t)method->methodPointer
#endif
				};
				stackFrames->push_back(stackFrameInfo);
			}
		}

	private:

		StackObject* _stackBase;
		ptrdiff_t _stackSize;
		ptrdiff_t _stackTopIdx;

		InterpFrame* _frameBase;
		uint32_t _frameTopIdx;
		uint32_t _frameCount;

		ExceptionFlowInfo* _exceptionFlowBase;
		uint32_t _exceptionFlowTopIdx;
		uint32_t _exceptionFlowCount;


		std::stack<const Il2CppImage*> _executingImageStack;
	};

	class ExecutingInterpImageScope
	{
	public:
		ExecutingInterpImageScope(MachineState& state, const Il2CppImage* image) : _state(state)
		{
			_state.PushExecutingImage(image);
		}

		~ExecutingInterpImageScope()
		{
			_state.PopExecutingImage();
		}
		
	private:
		MachineState& _state;
	};

	class InterpFrameGroup
	{
	public:
		InterpFrameGroup(MachineState& ms) : _machineState(ms), _stackBaseIdx(ms.GetStackTop()), _frameBaseIdx(ms.GetFrameTopIdx())
		{

		}

		void CleanUpFrames()
		{
			IL2CPP_ASSERT(_machineState.GetFrameTopIdx() >= _frameBaseIdx);
			uint32_t n = _machineState.GetFrameTopIdx() - _frameBaseIdx;
			if (n > 0)
			{
				for (uint32_t i = 0; i < n; i++)
				{
					LeaveFrame();
				}
			}
		}

		InterpFrame* EnterFrameFromInterpreter(const InterpMethodInfo* imi, StackObject* argBase)
		{
			ptrdiff_t oldStackTop = _machineState.GetStackTop();
			StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize - imi->argStackObjectSize);
			InterpFrame* newFrame = _machineState.PushFrame();
			*newFrame = { imi, argBase, oldStackTop, nullptr, nullptr, nullptr, 0, 0 };
			PUSH_STACK_FRAME(imi->method);
			return newFrame;
		}


		InterpFrame* EnterFrameFromNative(const InterpMethodInfo* imi, StackObject* argBase)
		{
			ptrdiff_t oldStackTop = _machineState.GetStackTop();
			StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize);
			InterpFrame* newFrame = _machineState.PushFrame();
			*newFrame = { imi, stackBasePtr, oldStackTop, nullptr, nullptr, nullptr, 0, 0 };

			// if not prepare arg stack. copy from args
			if (imi->args)
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
			PUSH_STACK_FRAME(imi->method);
			return newFrame;
		}

		InterpFrame* LeaveFrame()
		{
			IL2CPP_ASSERT(_machineState.GetFrameTopIdx() > _frameBaseIdx);
			POP_STACK_FRAME();
			InterpFrame* frame = _machineState.GetTopFrame();
			if (frame->exFlowBase)
			{
				_machineState.SetExceptionFlowTop(frame->exFlowBase);
			}
			_machineState.PopFrame();
			_machineState.SetStackTop(frame->oldStackTop);
			return _machineState.GetFrameTopIdx() > _frameBaseIdx ? _machineState.GetTopFrame() : nullptr;
		}

		void* AllocLoc(size_t size)
		{
			uint32_t soNum = (uint32_t)((size + sizeof(StackObject) - 1) / sizeof(StackObject));
			//void* data = _machineState.AllocStackSlot(soNum);
			//std::memset(data, 0, soNum * 8);
			void* data = IL2CPP_MALLOC_ZERO(size);
			return data;
 		}

		size_t GetFrameCount() const { return _machineState.GetFrameTopIdx() - _frameBaseIdx; }
	private:
		MachineState& _machineState;
		ptrdiff_t _stackBaseIdx;
		uint32_t _frameBaseIdx;
	};
}
}