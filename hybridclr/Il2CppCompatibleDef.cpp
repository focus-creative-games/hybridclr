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

#include "Il2CppCompatibleDef.h"

#include "vm/Runtime.h"

#include "metadata/MetadataModule.h"
#include "interpreter/InterpreterModule.h"

namespace hybridclr
{
Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointerSlow(MethodInfo* method)
{
    IL2CPP_ASSERT(!method->initInterpCallMethodPointer);
    method->initInterpCallMethodPointer = 1;
    bool isAdjustorThunkMethod = IS_CLASS_VALUE_TYPE(method->klass) && hybridclr::metadata::IsInstanceMethod(method);
    if (hybridclr::metadata::MetadataModule::IsImplementedByInterpreter(method))
    {
        method->methodPointerCallByInterp = interpreter::InterpreterModule::GetMethodPointer(method);
        if (isAdjustorThunkMethod)
        {
            method->virtualMethodPointerCallByInterp = interpreter::InterpreterModule::GetAdjustThunkMethodPointer(method);
        }
        else
        {
            method->virtualMethodPointerCallByInterp = method->methodPointerCallByInterp;
        }
        if (method->invoker_method == nullptr || method->invoker_method == il2cpp::vm::Runtime::GetMissingMethodInvoker() ||
            method->has_full_generic_sharing_signature)
        {
            method->invoker_method = hybridclr::interpreter::InterpreterModule::GetMethodInvoker(method);
        }
        if (method->methodPointer == nullptr || method->has_full_generic_sharing_signature)
        {
            method->methodPointer = method->methodPointerCallByInterp;
        }
        if (method->virtualMethodPointer == nullptr || method->has_full_generic_sharing_signature)
        {
            method->virtualMethodPointer = method->virtualMethodPointerCallByInterp;
        }
        method->isInterpterImpl = 1;
    }
    return method->methodPointerCallByInterp;
}
} // namespace hybridclr