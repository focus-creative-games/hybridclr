#include "ReversePInvokeMethodStub.h"
#include "MetadataModule.h"

namespace hybridclr
{
namespace metadata
{
	//!!!{{REVERSE_PINVOKE_METHOD_STUB

	void CallLuaFunction(void* xState, int32_t wrapperIndex)
	{
		const MethodInfo* method = MetadataModule::GetMethodInfoByReversePInvokeWrapperIndex(wrapperIndex);
		typedef void (*Callback)(void* xState, const MethodInfo* method);
		((Callback)GetInterpreterDirectlyCallMethodPointer(method))(xState, method);
	}

	void __ReversePInvokeMethod_0(void* xState)
	{
		CallLuaFunction(xState, 0);
	}

	void __ReversePInvokeMethod_1(void* xState)
	{
		CallLuaFunction(xState, 1);
	}

	void __ReversePInvokeMethod_2(void* xState)
	{
		CallLuaFunction(xState, 2);
	}

	void __ReversePInvokeMethod_3(void* xState)
	{
		CallLuaFunction(xState, 3);
	}

	void __ReversePInvokeMethod_4(void* xState)
	{
		CallLuaFunction(xState, 4);
	}

	void __ReversePInvokeMethod_5(void* xState)
	{
		CallLuaFunction(xState, 5);
	}

	void __ReversePInvokeMethod_6(void* xState)
	{
		CallLuaFunction(xState, 6);
	}

	void __ReversePInvokeMethod_7(void* xState)
	{
		CallLuaFunction(xState, 7);
	}

	void __ReversePInvokeMethod_8(void* xState)
	{
		CallLuaFunction(xState, 8);
	}

	void __ReversePInvokeMethod_9(void* xState)
	{
		CallLuaFunction(xState, 9);
	}

    Il2CppMethodPointer s_ReversePInvokeMethodStub[]
	{
		(Il2CppMethodPointer)__ReversePInvokeMethod_0,
		(Il2CppMethodPointer)__ReversePInvokeMethod_1,
		(Il2CppMethodPointer)__ReversePInvokeMethod_2,
		(Il2CppMethodPointer)__ReversePInvokeMethod_3,
		(Il2CppMethodPointer)__ReversePInvokeMethod_4,
		(Il2CppMethodPointer)__ReversePInvokeMethod_5,
		(Il2CppMethodPointer)__ReversePInvokeMethod_6,
		(Il2CppMethodPointer)__ReversePInvokeMethod_7,
		(Il2CppMethodPointer)__ReversePInvokeMethod_8,
		(Il2CppMethodPointer)__ReversePInvokeMethod_9,

		nullptr,
	};


	//!!!}}REVERSE_PINVOKE_METHOD_STUB
}
}