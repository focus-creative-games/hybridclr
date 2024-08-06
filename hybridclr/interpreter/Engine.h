#pragma once

#include <stack>

#include "../CommonDef.h"

#include "gc/GarbageCollector.h"
#include "vm/Exception.h"
#include "vm/StackTrace.h"

#include "../metadata/MetadataUtil.h"
#include "../RuntimeConfig.h"

#include "InterpreterDefs.h"
#include "MemoryUtil.h"
#include "MethodBridge.h"
#include <algorithm>

namespace hybridclr
{
namespace interpreter
{

	class MachineState
	{
	public:
		MachineState()
		{
			_stackSize = -1;
			_stackBase = nullptr;
			_stackTopIdx = 0;
			_localPoolBottomIdx = -1;

			_frameBase = nullptr;
			_frameCount = -1;
			_frameTopIdx = 0;

			_exceptionFlowBase = nullptr;
			_exceptionFlowCount = -1;
			_exceptionFlowTopIdx = 0;
		}

		~MachineState()
		{
			if (_stackBase)
			{
				//il2cpp::gc::GarbageCollector::FreeFixed(_stackBase);
				il2cpp::gc::GarbageCollector::UnregisterDynamicRoot(this);
				HYBRIDCLR_FREE(_stackBase);
			}
			if (_frameBase)
			{
				HYBRIDCLR_FREE(_frameBase);
			}
			if (_exceptionFlowBase)
			{
				HYBRIDCLR_FREE(_exceptionFlowBase);
			}
		}

		static std::pair<char*, size_t> GetGCRootData(void* root)
		{
			MachineState* machineState = (MachineState*)root;
			if (machineState->_stackBase && machineState->_stackTopIdx > 0)
			{
				return std::make_pair((char*)machineState->_stackBase, machineState->_stackTopIdx * sizeof(StackObject));
			}
			else
			{
				return std::make_pair(nullptr, 0);
			}
		}

		StackObject* AllocArgments(int32_t argCount)
		{
			return AllocStackSlot(argCount);
		}

		StackObject* GetStackBasePtr() const
		{
			return _stackBase;
		}

		int32_t GetStackTop() const
		{
			return _stackTopIdx;
		}

		StackObject* AllocStackSlot(int32_t slotNum)
		{
			if (_stackTopIdx + slotNum > _localPoolBottomIdx)
			{
				if (!_stackBase)
				{
					InitEvalStack();
				}
				if (_stackTopIdx + slotNum > _localPoolBottomIdx)
				{
					il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetStackOverflowException("AllocStackSlot"));
				}
			}
			StackObject* dataPtr = _stackBase + _stackTopIdx;
			_stackTopIdx += slotNum;
#if DEBUG
			std::memset(dataPtr, 0xEA, slotNum * sizeof(StackObject));
#endif
			return dataPtr;
		}

		void* AllocLocalloc(size_t size)
		{
			IL2CPP_ASSERT(size % 8 == 0);
			int32_t slotNum = (int32_t)(size / 8);
			IL2CPP_ASSERT(slotNum > 0);
			if (_stackTopIdx + slotNum > _localPoolBottomIdx)
			{
				if (!_stackBase)
				{
					InitEvalStack();
				}
				if (_stackTopIdx + slotNum > _localPoolBottomIdx)
				{
					il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetStackOverflowException("AllocLocalloc"));
				}
			}
			_localPoolBottomIdx -= slotNum;
			return _stackBase + _localPoolBottomIdx;
		}

		void SetStackTop(int32_t oldTop)
		{
			_stackTopIdx = oldTop;
		}

		uint32_t GetFrameTopIdx() const
		{
			return _frameTopIdx;
		}

		int32_t GetLocalPoolBottomIdx() const
		{
			return _localPoolBottomIdx;
		}

		void SetLocalPoolBottomIdx(int32_t idx)
		{
			_localPoolBottomIdx = idx;
		}

		InterpFrame* PushFrame()
		{
			if (_frameTopIdx >= _frameCount)
			{
				if (!_frameBase)
				{
					InitFrames();
				}
				else
				{
					il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetStackOverflowException("AllocFrame"));
				}
			}
			return _frameBase + _frameTopIdx++;
		}

		void PopFrame()
		{
			IL2CPP_ASSERT(_frameTopIdx > 0);
			--_frameTopIdx;
		}

		void PopFrameN(int32_t count)
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
			if (_exceptionFlowTopIdx + count >= _exceptionFlowCount)
			{
				if (!_exceptionFlowBase)
				{
					InitExceptionFlows();
				}
				if (_exceptionFlowTopIdx + count >= _exceptionFlowCount)
				{
					il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("AllocExceptionFlowZero"));
				}
			}
			ExceptionFlowInfo* efi = _exceptionFlowBase + _exceptionFlowTopIdx;
			_exceptionFlowTopIdx += count;
			return efi;
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

		void CollectFrames(il2cpp::vm::StackFrames* stackFrames);
		void SetupFramesDebugInfo(il2cpp::vm::StackFrames* stackFrames);

	private:


		void InitEvalStack()
		{
			_stackSize = (int32_t)RuntimeConfig::GetInterpreterThreadObjectStackSize();
			_stackBase = (StackObject*)HYBRIDCLR_MALLOC_ZERO(RuntimeConfig::GetInterpreterThreadObjectStackSize() * sizeof(StackObject));
			_stackTopIdx = 0;
			_localPoolBottomIdx = _stackSize;
			il2cpp::gc::GarbageCollector::RegisterDynamicRoot(this, GetGCRootData);
		}

		void InitFrames()
		{
			_frameBase = (InterpFrame*)HYBRIDCLR_CALLOC(RuntimeConfig::GetInterpreterThreadFrameStackSize(), sizeof(InterpFrame));
			_frameCount = (int32_t)RuntimeConfig::GetInterpreterThreadFrameStackSize();
			_frameTopIdx = 0;
		}

		void InitExceptionFlows()
		{
			_exceptionFlowBase = (ExceptionFlowInfo*)HYBRIDCLR_CALLOC(RuntimeConfig::GetInterpreterThreadExceptionFlowSize(), sizeof(ExceptionFlowInfo));
			_exceptionFlowCount = (int32_t)RuntimeConfig::GetInterpreterThreadExceptionFlowSize();
			_exceptionFlowTopIdx = 0;
		}

		StackObject* _stackBase;
		int32_t _stackSize;
		int32_t _stackTopIdx;
		int32_t _localPoolBottomIdx;

		InterpFrame* _frameBase;
		int32_t _frameTopIdx;
		int32_t _frameCount;

		ExceptionFlowInfo* _exceptionFlowBase;
		int32_t _exceptionFlowTopIdx;
		int32_t _exceptionFlowCount;


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

		InterpFrame* EnterFrameFromInterpreter(const MethodInfo* method, StackObject* argBase);

		InterpFrame* EnterFrameFromNative(const MethodInfo* method, StackObject* argBase);

		InterpFrame* LeaveFrame();

		void* AllocLoc(size_t originSize, bool fillZero)
		{
			if (originSize == 0)
			{
				return nullptr;
			}
			size_t size = (originSize + 7) & ~(size_t)7;
			void* data = _machineState.AllocLocalloc(size);
			if (fillZero)
			{
				std::memset(data, 0, size);
			}
			return data;
 		}

		size_t GetFrameCount() const { return _machineState.GetFrameTopIdx() - _frameBaseIdx; }
	private:
		MachineState& _machineState;
		int32_t _stackBaseIdx;
		uint32_t _frameBaseIdx;
	};
}
}