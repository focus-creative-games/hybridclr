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

	Il2CppMethodPointer s_ReversePInvokeMethodStub[]
	{
		(Il2CppMethodPointer)__ReversePInvokeMethod_0,
		(Il2CppMethodPointer)__ReversePInvokeMethod_1,
		nullptr,
	};

	//!!!}}REVERSE_PINVOKE_METHOD_STUB
}
}