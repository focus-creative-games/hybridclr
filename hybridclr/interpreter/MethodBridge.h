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
	
	void ConvertInvokeArgs(StackObject* resultArgs, const MethodInfo* method, MethodArgDesc* argDescs, void** args);

	bool ComputeSignature(const MethodInfo* method, bool call, char* sigBuf, size_t bufferSize);
	bool ComputeSignature(const Il2CppMethodDefinition* method, bool call, char* sigBuf, size_t bufferSize);
	bool ComputeSignature(const Il2CppType* ret, const il2cpp::utils::dynamic_array<const Il2CppType*>& params, bool instanceCall, char* sigBuf, size_t bufferSize);
	
	template<typename T> uint64_t N2MAsUint64ValueOrAddress(T& value)
	{
		return sizeof(T) <= 8 ? *(uint64_t*)&value : (uint64_t)&value;
	}

	template<typename T> T& M2NFromValueOrAddress(void* value)
	{
		//return sizeof(T) <= 8 ? *(T*)value : **(T**)value;
		return *(T*)value;
	}
	
}
}