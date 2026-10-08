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

#include "Engine.h"

#include "codegen/il2cpp-codegen.h"

#include "Interpreter.h"
#include "MemoryUtil.h"
#include "../metadata/InterpreterImage.h"
#include "../metadata/MetadataModule.h"

namespace hybridclr
{
namespace interpreter
{

#if HYBRIDCLR_ENABLE_STRACKTRACE

#define PUSH_STACK_FRAME(method, rawIp)                        \
    do                                                         \
    {                                                          \
        Il2CppStackFrameInfo stackFrameInfo = {method, rawIp}; \
        il2cpp::vm::StackTrace::PushFrame(stackFrameInfo);     \
    } while (0)

#define POP_STACK_FRAME()                   \
    do                                      \
    {                                       \
        il2cpp::vm::StackTrace::PopFrame(); \
    } while (0)

#else
#define PUSH_STACK_FRAME(method, rawIp)
#define POP_STACK_FRAME()
#endif

InterpFrame* InterpFrameGroup::EnterFrameFromInterpreter(const MethodInfo* method, StackObject* argBase)
{
#if HYBRIDCLR_ENABLE_PROFILER
    il2cpp_codegen_profiler_method_enter(method);
#endif
    const InterpMethodInfo* imi = (const InterpMethodInfo*)method->interpData;
    int32_t oldStackTop = _machineState.GetStackTop();
    StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize - imi->argStackObjectSize);
    InterpFrame* newFrame = _machineState.PushFrame();
    *newFrame = {method, argBase, oldStackTop, nullptr, nullptr, nullptr, 0, 0, _machineState.GetLocalPoolBottomIdx()};
    PUSH_STACK_FRAME(method, (uintptr_t)newFrame);
    return newFrame;
}

InterpFrame* InterpFrameGroup::EnterFrameFromNative(const MethodInfo* method, StackObject* argBase)
{
#if HYBRIDCLR_ENABLE_PROFILER
    il2cpp_codegen_profiler_method_enter(method);
#endif
    const InterpMethodInfo* imi = (const InterpMethodInfo*)method->interpData;
    int32_t oldStackTop = _machineState.GetStackTop();
    StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize);
    InterpFrame* newFrame = _machineState.PushFrame();
    *newFrame = {method, stackBasePtr, oldStackTop, nullptr, nullptr, nullptr, 0, 0, _machineState.GetLocalPoolBottomIdx()};

    // if not prepare arg stack. copy from args
    if (imi->args)
    {
        IL2CPP_ASSERT(imi->argCount == metadata::GetActualArgumentNum(method));
        CopyStackObject(stackBasePtr, argBase, imi->argStackObjectSize);
    }
    PUSH_STACK_FRAME(method, (uintptr_t)newFrame);
    return newFrame;
}

InterpFrame* InterpFrameGroup::LeaveFrame()
{
    IL2CPP_ASSERT(_machineState.GetFrameTopIdx() > _frameBaseIdx);
    POP_STACK_FRAME();
    InterpFrame* frame = _machineState.GetTopFrame();
#if HYBRIDCLR_ENABLE_PROFILER
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

static bool FrameNeedsSkipped(const Il2CppStackFrameInfo& frame)
{
    const MethodInfo* method = frame.method;
    const Il2CppClass* klass = method->klass;
    return (strcmp(klass->namespaze, "System.Diagnostics") == 0 && (strcmp(klass->name, "StackFrame") == 0 || strcmp(klass->name, "StackTrace") == 0)) ||
           (strcmp(klass->namespaze, "UnityEngine") == 0 && (strcmp(klass->name, "StackTraceUtility") == 0 || strcmp(klass->name, "Debug") == 0 ||
                                                             strcmp(klass->name, "Logger") == 0 || strcmp(klass->name, "DebugLogHandler") == 0));
}

static void SetupStackFrameInfo(const InterpFrame* frame, Il2CppStackFrameInfo& stackFrame)
{
    const MethodInfo* method = frame->method;
    const InterpMethodInfo* imi = (const InterpMethodInfo*)method->interpData;
    const byte* actualIp = (const byte*)frame->ip;

    stackFrame.method = method;
    stackFrame.raw_ip = (uintptr_t)frame;

    if (!hybridclr::metadata::IsInterpreterMethod(method))
    {
        return;
    }

    hybridclr::metadata::InterpreterImage* interpImage = hybridclr::metadata::MetadataModule::GetImage(method);
    if (!interpImage)
    {
        return;
    }

    hybridclr::metadata::PDBImage* pdbImage = interpImage->GetPDBImage();
    if (!pdbImage)
    {
        return;
    }
    pdbImage->SetupStackFrameInfo(method, actualIp, stackFrame);
}

void MachineState::CollectFrames(il2cpp::vm::StackFrames* stackFrames)
{
    if (_frameTopIdx <= 0)
    {
        return;
    }
    size_t insertIndex = 0;
    for (; insertIndex < stackFrames->size(); insertIndex++)
    {
        if (FrameNeedsSkipped((*stackFrames)[insertIndex]))
        {
            break;
        }
    }
    stackFrames->insert(stackFrames->begin() + insertIndex, _frameTopIdx, Il2CppStackFrameInfo());
    for (int32_t i = 0; i < _frameTopIdx; i++)
    {
        SetupStackFrameInfo(_frameBase + i, (*stackFrames)[insertIndex + i]);
    }
}

void MachineState::SetupFramesDebugInfo(il2cpp::vm::StackFrames* stackFrames)
{
    for (Il2CppStackFrameInfo& frame : *stackFrames)
    {
        if (frame.method && hybridclr::metadata::IsInterpreterImplement(frame.method))
        {
            hybridclr::metadata::InterpreterImage* interpImage = hybridclr::metadata::MetadataModule::GetImage(frame.method);
            if (interpImage)
            {
                hybridclr::metadata::PDBImage* pdbImage = interpImage->GetPDBImage();
                if (pdbImage)
                {
                    pdbImage->SetupStackFrameInfo(frame.method, (const byte*)(((InterpFrame*)frame.raw_ip)->ip), frame);
                }
            }
        }
    }
}
} // namespace interpreter
} // namespace hybridclr
