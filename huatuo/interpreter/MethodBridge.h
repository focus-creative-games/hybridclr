#pragma once

#include "../CommonDef.h"

namespace huatuo
{
namespace interpreter
{
	union StackObject;

	typedef void (*Managed2NativeCallMethod)(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret);
	typedef void (*NativeClassCtor0)(Il2CppObject* obj, const MethodInfo* method);

	struct NativeCallMethod
	{
		const char* signature;
		Il2CppMethodPointer method;
		Il2CppMethodPointer adjustThunkMethod;
		Managed2NativeCallMethod managed2NativeMethod;
	};

	struct NativeInvokeMethod
	{
		const char* signature;
		InvokerMethod instanceMethod;
		InvokerMethod staticMethod;
	};

	extern NativeCallMethod g_callStub[];
	extern NativeInvokeMethod g_invokeStub[];

}
}