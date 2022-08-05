#include "InterpreterModule.h"

#include "Interpreter.h"

#include <unordered_map>

#include "vm/GlobalMetadata.h"
#include "vm/MetadataLock.h"
#include "vm/Class.h"
#include "vm/Object.h"

#include "../metadata/MetadataModule.h"
#include "../metadata/MetadataUtil.h"
#include "../transform/Transform.h"

#include "MethodBridge.h"

namespace huatuo
{
namespace interpreter
{
	il2cpp::os::ThreadLocalValue InterpreterModule::s_machineState;

	static std::unordered_map<const char*, NativeCallMethod, CStringHash, CStringEqualTo> s_calls;
	static std::unordered_map<const char*, NativeInvokeMethod, CStringHash, CStringEqualTo> s_invokes;

	MachineState& InterpreterModule::GetCurrentThreadMachineState()
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

	void InterpreterModule::Initialize()
	{
		for (size_t i = 0; ; i++)
		{
			NativeCallMethod& method = g_callStub[i];
			if (!method.signature)
			{
				break;
			}
			s_calls.insert({ method.signature, method });
		}

		for (size_t i = 0; ; i++)
		{
			NativeInvokeMethod& method = g_invokeStub[i];
			if (!method.signature)
			{
				break;
			}
			s_invokes.insert({ method.signature, method });
		}
	}

	template<typename T>
	const NativeCallMethod* GetNativeCallMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = s_calls.find(sigName);
		return (it != s_calls.end()) ? &it->second : nullptr;
	}

	template<typename T>
	const NativeInvokeMethod* GetNativeInvokeMethod(const T* method)
	{
		char sigName[1000];
		ComputeSignature(method, false, sigName, sizeof(sigName) - 1);
		auto it = s_invokes.find(sigName);
		return (it != s_invokes.end()) ? &it->second : nullptr;
	}

	static void RaiseMethodNotSupportException(const MethodInfo* method, const char* desc)
	{
		TEMP_FORMAT(errMsg, "%s. %s.%s::%s", desc, method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
	}

	static void RaiseMethodNotSupportException(const Il2CppMethodDefinition* method, const char* desc)
	{
		Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeDefinitionIndex(method->declaringType);
		TEMP_FORMAT(errMsg, "%s. %s.%s::%s", desc, klass->namespaze, klass->name, il2cpp::vm::GlobalMetadata::GetStringFromIndex(method->nameIndex));
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
	}

	static void NotSupportNative2Managed()
	{
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("NotSupportNative2Managed"));
	}

	static void* NotSupportInvoke(Il2CppMethodPointer, const MethodInfo* method, void*, void**)
	{
		char sigName[1000];
		ComputeSignature(method, false, sigName, sizeof(sigName) - 1);
		TEMP_FORMAT(errMsg, "Invoke method missing. ABI:%s sinature:%s %s.%s::%s", HUATUO_ABI_NAME, sigName, method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		return nullptr;
	}

	Il2CppMethodPointer InterpreterModule::GetMethodPointer(const Il2CppMethodDefinition* method)
	{
		const NativeCallMethod* ncm = GetNativeCallMethod(method, false);
		if (ncm)
		{
			return ncm->method;
		}
		//RaiseMethodNotSupportException(method, "GetMethodPointer");
		return (Il2CppMethodPointer)NotSupportNative2Managed;
	}

	Il2CppMethodPointer InterpreterModule::GetMethodPointer(const MethodInfo* method)
	{
		const NativeCallMethod* ncm = GetNativeCallMethod(method, false);
		if (ncm)
		{
			return ncm->method;
		}
		//RaiseMethodNotSupportException(method, "GetMethodPointer");
		return (Il2CppMethodPointer)NotSupportNative2Managed;
	}

	Il2CppMethodPointer InterpreterModule::GetAdjustThunkMethodPointer(const Il2CppMethodDefinition* method)
	{
		if (!huatuo::metadata::IsInstanceMethod(method))
		{
			return nullptr;
		}
		const NativeCallMethod* ncm = GetNativeCallMethod(method, false);
		if (ncm)
		{
			return ncm->adjustThunkMethod;
		}
		//RaiseMethodNotSupportException(method, "GetAdjustThunkMethodPointer");
		return (Il2CppMethodPointer)NotSupportNative2Managed;
	}

	Il2CppMethodPointer InterpreterModule::GetAdjustThunkMethodPointer(const MethodInfo* method)
	{
		if (!huatuo::metadata::IsInstanceMethod(method))
		{
			return nullptr;
		}
		const NativeCallMethod* ncm = GetNativeCallMethod(method, false);
		if (ncm)
		{
			return ncm->adjustThunkMethod;
		}
		//RaiseMethodNotSupportException(method, "GetAdjustThunkMethodPointer");
		return (Il2CppMethodPointer)NotSupportNative2Managed;
	}

	void Managed2NativeCallByReflectionInvokeImpl(const MethodInfo* method, bool forceStatic, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
	{
		if (huatuo::metadata::IsInterpreterMethod(method) || method->invoker_method == nullptr)
		{
			char sigName[1000];
			ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);

			TEMP_FORMAT(errMsg, "GetManaged2NativeMethodPointer. ABI:%s sinature:%s not support.", HUATUO_ABI_NAME, sigName);
			RaiseMethodNotSupportException(method, errMsg);
		}
		void* thisPtr;
		uint16_t* argVarIndexBase;
		if (huatuo::metadata::IsInstanceMethod(method))
		{
			thisPtr = localVarBase[argVarIndexs[0]].obj;
			argVarIndexBase = argVarIndexs + 1;
		}
		else
		{
			thisPtr = nullptr;
			argVarIndexBase = argVarIndexs;
		}
		void* invokeParams[256];
		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			const Il2CppType* argType = GET_METHOD_PARAMETER_TYPE(method->parameters[i]);
			StackObject* argValue = localVarBase + argVarIndexBase[i];
			void* argValuePtr;
			if (!argType->byref && huatuo::metadata::IsValueType(argType))
			{
				argValuePtr = argValue;
			}
			else
			{
				argValuePtr = argValue->ptr;
			}
			invokeParams[i] = argValuePtr;
		}
#if HUATUO_UNITY_2021_OR_NEW
		method->invoker_method(method->methodPointer, method, thisPtr, invokeParams, ret);
#else
		void* retObj = method->invoker_method(method->methodPointer, method, thisPtr, invokeParams);
		if (ret)
		{
			const Il2CppType* returnType = method->return_type;
			if (huatuo::metadata::IsValueType(returnType))
			{
				Il2CppClass* returnKlass = il2cpp::vm::Class::FromIl2CppType(returnType);
				if (il2cpp::vm::Class::IsNullable(returnKlass))
				{
					il2cpp::vm::Object::UnboxNullable((Il2CppObject*)retObj, returnKlass->element_class, ret);
				}
				else
				{
					std::memcpy(ret, il2cpp::vm::Object::Unbox((Il2CppObject*)retObj), il2cpp::vm::Class::GetValueSize(returnKlass, nullptr));
				}
			}
			else
			{
				*(void**)ret = retObj;
			}
		}
#endif
	}

	void Managed2NativeCallByReflectionInvoke(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
	{
		Managed2NativeCallByReflectionInvokeImpl(method, false, argVarIndexs, localVarBase, ret);
	}

	void Managed2NativeCallByReflectionInvokeIgnoreThisObj(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
	{
		Managed2NativeCallByReflectionInvokeImpl(method, false, argVarIndexs, localVarBase, ret);
	}

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const MethodInfo* method, bool forceStatic)
	{
		const NativeCallMethod* ncm = GetNativeCallMethod(method, forceStatic);
		if (ncm)
		{
			return ncm->managed2NativeMethod;
		}
		return forceStatic ? Managed2NativeCallByReflectionInvokeIgnoreThisObj : Managed2NativeCallByReflectionInvoke;
	}

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const metadata::ResolveStandAloneMethodSig& method)
	{
		char sigName[1000];
		ComputeSignature(&method.returnType, method.params, method.paramCount, false, sigName, sizeof(sigName) - 1);
		auto it = s_calls.find(sigName);
		if (it != s_calls.end())
		{
			return it->second.managed2NativeMethod;
		}
		return Managed2NativeCallByReflectionInvokeIgnoreThisObj;
	}

	InvokerMethod InterpreterModule::GetMethodInvoker(const Il2CppMethodDefinition* method)
	{
		const NativeInvokeMethod* nim = GetNativeInvokeMethod(method);
		if (nim)
		{
			return huatuo::metadata::IsInstanceMethod(method) ? nim->instanceMethod : nim->staticMethod;
		}
		//RaiseMethodNotSupportException(method, "GetMethodInvoker");
		return (InvokerMethod)NotSupportInvoke;
	}

	InvokerMethod InterpreterModule::GetMethodInvoker(const MethodInfo* method)
	{
		const NativeInvokeMethod* nim = GetNativeInvokeMethod(method);
		if (nim)
		{
			return huatuo::metadata::IsInstanceMethod(method) ? nim->instanceMethod : nim->staticMethod;
		}
		//RaiseMethodNotSupportException(method, "GetMethodInvoker");
		return (InvokerMethod)NotSupportInvoke;
	}

	InterpMethodInfo* InterpreterModule::GetInterpMethodInfo(const MethodInfo* methodInfo)
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

		if (methodInfo->huatuoData)
		{
			return (InterpMethodInfo*)methodInfo->huatuoData;
		}

		metadata::Image* image = metadata::IsInterpreterMethod(methodInfo) ? huatuo::metadata::MetadataModule::GetImage(methodInfo->klass)
			: (metadata::Image*)huatuo::metadata::AOTHomologousImage::FindImageByAssembly(
				methodInfo->klass->rank ? il2cpp_defaults.corlib->assembly : methodInfo->klass->image->assembly);
		IL2CPP_ASSERT(image);

		metadata::MethodBody* methodBody = image->GetMethodBody(methodInfo);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			TEMP_FORMAT(errMsg, "%s.%s::%s method body is null. not support external method currently.", methodInfo->klass->namespaze, methodInfo->klass->name, methodInfo->name);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		}
		InterpMethodInfo* imi = new (IL2CPP_MALLOC_ZERO(sizeof(InterpMethodInfo))) InterpMethodInfo;
		transform::HiTransform::Transform(image, methodInfo, *methodBody, *imi);
		il2cpp::os::Atomic::FullMemoryBarrier();
		const_cast<MethodInfo*>(methodInfo)->huatuoData = imi;
		return imi;
	}
}
}

