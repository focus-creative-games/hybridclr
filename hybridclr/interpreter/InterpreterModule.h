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


		static MachineState& GetCurrentThreadMachineState();
		static void FreeThreadLocalMachineState();

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
			return method->methodPointerCallByInterp != (Il2CppMethodPointer)NotSupportNative2Managed;
		}

		static bool HasImplementCallVirtualNative2Managed(const MethodInfo* method)
		{
			return method->virtualMethodPointerCallByInterp != (Il2CppMethodPointer)NotSupportAdjustorThunk;
		}

		static void Managed2NativeCallByReflectionInvoke(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret);

		static void NotSupportNative2Managed();
		static void NotSupportAdjustorThunk();
	private:

		static il2cpp::os::ThreadLocalValue s_machineState;
	};
}
}
