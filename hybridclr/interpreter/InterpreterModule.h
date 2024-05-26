#pragma once

#include "os/ThreadLocalValue.h"

#include "../CommonDef.h"
#include "MethodBridge.h"
#include "Engine.h"
#include "../metadata/Image.h"

namespace hybridclr
{
namespace interpreter
{

	class InterpreterModule
	{
	public:
		static void Initialize();

		static MachineState& GetCurrentThreadMachineState()
		{
			MachineState* state = nullptr;
			s_machineState.GetValue((void**)&state);
			if (!state)
			{
				state = new MachineState();
				s_machineState.SetValue(state);
			}
			return *state;
		}

		static void FreeThreadLocalMachineState()
		{
			MachineState* state = nullptr;
			s_machineState.GetValue((void**)&state);
			if (state)
			{
				delete state;
				s_machineState.SetValue(nullptr);
			}
		}

		static InterpMethodInfo* GetInterpMethodInfo(const MethodInfo* methodInfo);

		static Il2CppMethodPointer GetMethodPointer(const Il2CppMethodDefinition* method);
		static Il2CppMethodPointer GetMethodPointer(const MethodInfo* method);
		static Il2CppMethodPointer GetAdjustThunkMethodPointer(const Il2CppMethodDefinition* method);
		static Il2CppMethodPointer GetAdjustThunkMethodPointer(const MethodInfo* method);
		static Managed2NativeCallMethod GetManaged2NativeMethodPointer(const MethodInfo* method, bool forceStatic);
		static Managed2NativeCallMethod GetManaged2NativeMethodPointer(const metadata::ResolveStandAloneMethodSig& methodSig);

		static InvokerMethod GetMethodInvoker(const Il2CppMethodDefinition* method);
		static InvokerMethod GetMethodInvoker(const MethodInfo* method);

		static bool IsImplementsByInterpreter(const MethodInfo* method);

		static bool HasImplementCallNative2Managed(const MethodInfo* method)
		{
			IL2CPP_ASSERT(method->methodPointerCallByInterp != NotSupportAdjustorThunk);
			return method->methodPointerCallByInterp != (Il2CppMethodPointer)NotSupportNative2Managed;
		}

		static bool HasImplementCallVirtualNative2Managed(const MethodInfo* method)
		{
			IL2CPP_ASSERT(method->virtualMethodPointerCallByInterp != NotSupportNative2Managed);
			return method->virtualMethodPointerCallByInterp != (Il2CppMethodPointer)NotSupportAdjustorThunk;
		}

		static void Managed2NativeCallByReflectionInvoke(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret);

		static void NotSupportNative2Managed();
		static void NotSupportAdjustorThunk();

		static Il2CppMethodPointer GetReversePInvokeWrapper(const Il2CppImage* image, const MethodInfo* method, Il2CppCallConvention callConvention);
		static const MethodInfo* GetMethodInfoByReversePInvokeWrapperIndex(int32_t index);
		static const MethodInfo* GetMethodInfoByReversePInvokeWrapperMethodPointer(Il2CppMethodPointer methodPointer);
		static int32_t GetWrapperIndexByReversePInvokeWrapperMethodPointer(Il2CppMethodPointer methodPointer);

		static const char* GetValueTypeSignature(const char* fullName);
		
	private:
		static il2cpp::os::ThreadLocalValue s_machineState;
	};
}
}
