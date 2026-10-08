// Copyright 2026 Code Philosophy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
    static Managed2NativeFunctionPointerCallMethod GetManaged2NativeFunctionPointerMethodPointer(const MethodInfo* method, Il2CppCallConvention callConvention);
    static Managed2NativeFunctionPointerCallMethod GetManaged2NativeFunctionPointerMethodPointer(const metadata::ResolveStandAloneMethodSig& methodSig);

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

    static bool IsMethodInfoPointer(void* pointer);

  private:
    static il2cpp::os::ThreadLocalValue s_machineState;
};
} // namespace interpreter
} // namespace hybridclr
