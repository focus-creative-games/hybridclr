#include "ReversePInvokeMethodStub.h"
#include "MetadataModule.h"

namespace huatuo
{
namespace metadata
{
	//!!!{{REVERSE_PINVOKE_METHOD_STUB

	void __ReversePInvokeMethod_0(void* xState)
	{
		// for xLua developer
		int32_t wrapperIndex = 0;
		const MethodInfo* method = MetadataModule::GetMethodInfoByReversePInvokeWrapperIndex(wrapperIndex);
		typedef void (*Callback)(void* xState, const MethodInfo* method);
		((Callback)method->methodPointer)(xState, method);
	}

	void __ReversePInvokeMethod_1(void* xState)
	{
		// for xLua developer
		int32_t wrapperIndex = 1;
		const MethodInfo* method = MetadataModule::GetMethodInfoByReversePInvokeWrapperIndex(wrapperIndex);
		typedef void (*Callback)(void* xState, const MethodInfo* method);
		((Callback)method->methodPointer)(xState, method);
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