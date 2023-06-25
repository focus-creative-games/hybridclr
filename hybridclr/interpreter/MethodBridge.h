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

	extern Managed2NativeMethodInfo g_managed2nativeStub[];
	extern Native2ManagedMethodInfo g_native2managedStub[];
	extern NativeAdjustThunkMethodInfo g_adjustThunkStub[];


	template<int N>
	struct WebGLSpeicalValueType
	{
		union
		{
			struct
			{
			};
			uint8_t __padding[N];
		};
	};

	template<int N>
	struct WebGLSpeicalValueTypeAlign2
	{
		union
		{
			struct
			{
			};
			uint16_t __padding[N/2];
		};
	};

	template<int N>
	struct WebGLSpeicalValueTypeAlign4
	{
		union
		{
			struct
			{
			};
			uint32_t __padding[N / 4];
		};
	};

	template<int N>
	struct WebGLSpeicalValueTypeAlign8
	{
		union
		{
			struct
			{
			};
			uint64_t __padding[N / 8];
		};
	};

	template<int N>
	struct ValueTypeSize
	{
		uint8_t  __value[N];
	};

	template<int N>
	struct ValueTypeSizeAlign2
	{
		static_assert(N % 2 == 0, "need align 2");
		uint16_t  __value[N/2];
	};

	template<int N>
	struct ValueTypeSizeAlign4
	{
		static_assert(N % 4 == 0, "need align 4");
		uint32_t  __value[N/4];
	};

	template<int N>
	struct ValueTypeSizeAlign8
	{
		static_assert(N % 8 == 0, "need align 8");
		uint64_t  __value[N/8];
	};

	struct ValueTypeSize16
	{
		uint64_t low;
		uint64_t high;
	};

	void CopyArgs(StackObject* dstBase, StackObject* argBase, MethodArgDesc* args, uint32_t paramCount);
	void ConvertInvokeArgs(StackObject* resultArgs, const MethodInfo* method, MethodArgDesc* argDescs, void** args);

	bool ComputeSignature(const MethodInfo* method, bool call, char* sigBuf, size_t bufferSize);
	bool ComputeSignature(const Il2CppMethodDefinition* method, bool call, char* sigBuf, size_t bufferSize);
	bool ComputeSignature(const Il2CppType* ret, const Il2CppType* params, uint32_t paramCount, bool instanceCall, char* sigBuf, size_t bufferSize);

	struct HFATypeInfo
	{
		const Il2CppType* eleType;
		int32_t count;
	};

	bool ComputeHFATypeInfo(Il2CppClass* klass, HFATypeInfo& typeInfo);
}
}