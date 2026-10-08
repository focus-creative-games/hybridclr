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

#include "../CommonDef.h"
#include "InterpreterDefs.h"

namespace hybridclr
{
namespace interpreter
{
union StackObject;

typedef void (*Managed2NativeCallMethod)(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret);
typedef void (*NativeClassCtor0)(Il2CppObject* obj, const MethodInfo* method);

struct Managed2NativeMethodInfo
{
    const char* signature;
    Managed2NativeCallMethod method;
};

struct Native2ManagedMethodInfo
{
    const char* signature;
    Il2CppMethodPointer method;
};

struct NativeAdjustThunkMethodInfo
{
    const char* signature;
    Il2CppMethodPointer method;
};

struct FullName2Signature
{
    const char* fullName;
    const char* signature;
};

extern const Managed2NativeMethodInfo g_managed2nativeStub[];
extern const Native2ManagedMethodInfo g_native2managedStub[];
extern const NativeAdjustThunkMethodInfo g_adjustThunkStub[];
extern const FullName2Signature g_fullName2SignatureStub[];

struct ReversePInvokeInfo
{
    int32_t index;
    Il2CppMethodPointer methodPointer;
    const MethodInfo* methodInfo;
};

struct ReversePInvokeMethodData
{
    const char* methodSig;
    Il2CppMethodPointer methodPointer;
};

extern const ReversePInvokeMethodData g_reversePInvokeMethodStub[];

typedef void (*PInvokeMethodPointer)(intptr_t method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret);

struct PInvokeMethodData
{
    const char* methodSig;
    PInvokeMethodPointer methodPointer;
};

extern const PInvokeMethodData g_PInvokeMethodStub[];

typedef void (*Managed2NativeFunctionPointerCallMethod)(Il2CppMethodPointer methodPointer, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret);

struct Managed2NativeFunctionPointerCallData
{
    const char* methodSig;
    Managed2NativeFunctionPointerCallMethod methodPointer;
};

extern const Managed2NativeFunctionPointerCallData g_managed2NativeFunctionPointerCallStub[];

void ConvertInvokeArgs(StackObject* resultArgs, const MethodInfo* method, MethodArgDesc* argDescs, void** args);

bool ComputeSignature(const MethodInfo* method, bool call, char* sigBuf, size_t bufferSize);
bool ComputeSignature(const Il2CppMethodDefinition* method, bool call, char* sigBuf, size_t bufferSize);
bool ComputeSignature(const Il2CppType* ret, const il2cpp::utils::dynamic_array<const Il2CppType*>& params, bool instanceCall, char* sigBuf, size_t bufferSize);

template <typename T>
uint64_t N2MAsUint64ValueOrAddress(T& value)
{
    return sizeof(T) <= 8 ? *(uint64_t*)&value : (uint64_t)&value;
}

template <typename T>
T& M2NFromValueOrAddress(void* value)
{
    // return sizeof(T) <= 8 ? *(T*)value : **(T**)value;
    return *(T*)value;
}

} // namespace interpreter
} // namespace hybridclr