#include "InterpreterModule.h"

#include "Interpreter.h"

#include <unordered_map>

#include "vm/GlobalMetadata.h"
#include "vm/MetadataCache.h"
#include "vm/MetadataLock.h"
#include "vm/Class.h"
#include "vm/Object.h"
#include "vm/Method.h"

#include "../metadata/MetadataModule.h"
#include "../metadata/MetadataUtil.h"
#include "../metadata/InterpreterImage.h"
#include "../transform/Transform.h"

#include "MethodBridge.h"
#include "InterpreterUtil.h"

namespace hybridclr
{
namespace interpreter
{
	il2cpp::os::ThreadLocalValue InterpreterModule::s_machineState;

	static std::unordered_map<const char*, Managed2NativeCallMethod, CStringHash, CStringEqualTo> g_managed2natives;
	static std::unordered_map<const char*, Il2CppMethodPointer, CStringHash, CStringEqualTo> g_native2manageds;
	static std::unordered_map<const char*, Il2CppMethodPointer, CStringHash, CStringEqualTo> g_adjustThunks;

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

	void InterpreterModule::FreeThreadLocalMachineState()
	{
		MachineState* state = nullptr;
		s_machineState.GetValue((void**)&state);
		if (state)
		{
			delete state;
			s_machineState.SetValue(nullptr);
		}
	}

	void InterpreterModule::Initialize()
	{
		for (size_t i = 0; ; i++)
		{
			Managed2NativeMethodInfo& method = g_managed2nativeStub[i];
			if (!method.signature)
			{
				break;
			}
			g_managed2natives.insert({ method.signature, method.method });
		}
		for (size_t i = 0; ; i++)
		{
			Native2ManagedMethodInfo& method = g_native2managedStub[i];
			if (!method.signature)
			{
				break;
			}
			g_native2manageds.insert({ method.signature, method.method });
		}

		for (size_t i = 0; ; i++)
		{
			NativeAdjustThunkMethodInfo& method = g_adjustThunkStub[i];
			if (!method.signature)
			{
				break;
			}
			g_adjustThunks.insert({ method.signature, method.method });
		}
	}

	void InterpreterModule::NotSupportNative2Managed()
	{
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("NotSupportNative2Managed"));
	}

	void InterpreterModule::NotSupportAdjustorThunk()
	{
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("NotSupportAdjustorThunk"));
	}

	static void* NotSupportInvoke(Il2CppMethodPointer, const MethodInfo* method, void*, void**)
	{
		char sigName[1000];
		ComputeSignature(method, true, sigName, sizeof(sigName) - 1);
		TEMP_FORMAT(errMsg, "Invoke method missing. ABI:%s sinature:%s %s.%s::%s", HYBRIDCLR_ABI_NAME, sigName, method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		return nullptr;
	}

	template<typename T>
	const Managed2NativeCallMethod GetManaged2NativeMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = g_managed2natives.find(sigName);
		return it != g_managed2natives.end() ? it->second : nullptr;
	}

	template<typename T>
	const Il2CppMethodPointer GetNative2ManagedMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = g_native2manageds.find(sigName);
		return it != g_native2manageds.end() ? it->second : InterpreterModule::NotSupportNative2Managed;
	}

	template<typename T>
	const Il2CppMethodPointer GetNativeAdjustMethodMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = g_adjustThunks.find(sigName);
		return it != g_adjustThunks.end() ? it->second : InterpreterModule::NotSupportAdjustorThunk;
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

	Il2CppMethodPointer InterpreterModule::GetMethodPointer(const Il2CppMethodDefinition* method)
	{
		Il2CppMethodPointer ncm = GetNative2ManagedMethod(method, false);
		return ncm ? ncm : (Il2CppMethodPointer)NotSupportNative2Managed;
	}

	Il2CppMethodPointer InterpreterModule::GetMethodPointer(const MethodInfo* method)
	{
		Il2CppMethodPointer ncm = GetNative2ManagedMethod(method, false);
		return ncm ? ncm : (Il2CppMethodPointer)NotSupportNative2Managed;
	}

	Il2CppMethodPointer InterpreterModule::GetAdjustThunkMethodPointer(const Il2CppMethodDefinition* method)
	{
		return GetNativeAdjustMethodMethod(method, false);
	}

	Il2CppMethodPointer InterpreterModule::GetAdjustThunkMethodPointer(const MethodInfo* method)
	{
		return GetNativeAdjustMethodMethod(method, false);
	}

	void InterpreterModule::Managed2NativeCallByReflectionInvoke(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
	{
		if (hybridclr::metadata::IsInterpreterImplement(method))
		{
			IL2CPP_ASSERT(method->parameters_count <= 32);
			StackObject newArgs[32];
			int32_t argBaseOffset;
			if (hybridclr::metadata::IsInstanceMethod(method))
			{
				newArgs[0] = localVarBase[argVarIndexs[0]];
				argBaseOffset = 1;
			}
			else
			{
				argBaseOffset = 0;
			}
			InterpMethodInfo* imi = method->interpData ? (InterpMethodInfo*)method->interpData : GetInterpMethodInfo(method);
			MethodArgDesc* argDescs = imi->args;
			for (uint8_t i = 0; i < method->parameters_count; i++)
			{
				int32_t argOffset = argBaseOffset + i;
				StackObject* argValue = localVarBase + argVarIndexs[argOffset];
				if (argDescs[argOffset].passByValWhenCall)
				{
					newArgs[argOffset] = *argValue;
				}
				else
				{
					newArgs[argOffset].ptr = argValue;
				}
			}
			Interpreter::Execute(method, newArgs, ret);
			return;
		}
		if (method->invoker_method == nullptr)
		{
			char sigName[1000];
			ComputeSignature(method, true, sigName, sizeof(sigName) - 1);

			TEMP_FORMAT(errMsg, "GetManaged2NativeMethodPointer. ABI:%s sinature:%s not support.", HYBRIDCLR_ABI_NAME, sigName);
			RaiseMethodNotSupportException(method, errMsg);
		}
		void* thisPtr;
		uint16_t* argVarIndexBase;
		if (hybridclr::metadata::IsInstanceMethod(method))
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
			if (!argType->byref && hybridclr::metadata::IsValueType(argType))
			{
				invokeParams[i] = argValue;
			}
			else
			{
				invokeParams[i] = argValue->ptr;
			}
		}
#if HYBRIDCLR_UNITY_2021_OR_NEW
		method->invoker_method(method->methodPointerCallByInterp, method, thisPtr, invokeParams, ret);
#else
		void* retObj = method->invoker_method(method->methodPointerCallByInterp, method, thisPtr, invokeParams);
		if (ret)
		{
			const Il2CppType* returnType = method->return_type;
			if (hybridclr::metadata::IsValueType(returnType))
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

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const MethodInfo* method, bool forceStatic)
	{
		if (method->methodPointerCallByInterp == NotSupportNative2Managed 
#if HYBRIDCLR_UNITY_2021_OR_NEW
			|| method->has_full_generic_sharing_signature
#endif
			)
		{
			return Managed2NativeCallByReflectionInvoke;
		}
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = g_managed2natives.find(sigName);
		return it != g_managed2natives.end() ? it->second : Managed2NativeCallByReflectionInvoke;
	}

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const metadata::ResolveStandAloneMethodSig& method)
	{
		char sigName[1000];
		ComputeSignature(&method.returnType, method.params, method.paramCount, metadata::IsPrologHasThis(method.flags), sigName, sizeof(sigName) - 1);
		auto it = g_managed2natives.find(sigName);
		return it != g_managed2natives.end() ? it->second : Managed2NativeCallByReflectionInvoke;
	}

	static void RaiseExecutionEngineExceptionMethodIsNotFound(const MethodInfo* method)
	{
		if (il2cpp::vm::Method::GetClass(method))
			RaiseExecutionEngineException(il2cpp::vm::Method::GetFullName(method).c_str());
		else
			RaiseExecutionEngineException(il2cpp::vm::Method::GetNameWithGenericTypes(method).c_str());
	}

	#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
	
	static void InterpterInvoke(Il2CppMethodPointer methodPointer, const MethodInfo* method, void* __this, void** __args, void* __ret)
	{
		bool isInstanceMethod = metadata::IsInstanceMethod(method);
		StackObject args[256];
		if (isInstanceMethod)
		{
			__this = (Il2CppObject*)__this + (methodPointer != method->methodPointerCallByInterp);
			args[0].ptr = __this;
		}
		
		InterpMethodInfo* imi = method->interpData ? (InterpMethodInfo*)method->interpData : InterpreterModule::GetInterpMethodInfo(method);
		MethodArgDesc* argDescs = imi->args + isInstanceMethod;
		ConvertInvokeArgs(args + isInstanceMethod, method, argDescs, __args);
		Interpreter::Execute(method, args, __ret);
	}

	static void InterpreterDelegateInvoke(Il2CppMethodPointer, const MethodInfo* method, void* __this, void** __args, void* __ret)
	{
		Il2CppMulticastDelegate* del = (Il2CppMulticastDelegate*)__this;
		Il2CppDelegate** firstSubDel;
		int32_t subDelCount;
		if (del->delegates)
		{
			firstSubDel = (Il2CppDelegate**)il2cpp::vm::Array::GetFirstElementAddress(del->delegates);
			subDelCount = il2cpp::vm::Array::GetLength(del->delegates);
		}
		else
		{
			firstSubDel = (Il2CppDelegate**)&del;
			subDelCount = 1;
		}

		for (int32_t i = 0; i < subDelCount; i++)
		{
			Il2CppDelegate* cur = firstSubDel[i];
			const MethodInfo* curMethod = cur->method;
			Il2CppObject* curTarget = cur->target;
			if (curMethod->invoker_method == nullptr)
			{
				RaiseExecutionEngineExceptionMethodIsNotFound(curMethod);
			}
			switch ((int)(method->parameters_count - curMethod->parameters_count))
			{
			case 0:
			{
				if (metadata::IsInstanceMethod(curMethod) && !curTarget)
				{
					il2cpp::vm::Exception::RaiseNullReferenceException();
				}
				curTarget += (IS_CLASS_VALUE_TYPE(curMethod->klass));
				curMethod->invoker_method(curMethod->methodPointerCallByInterp, curMethod, curTarget, __args, __ret);
				break;
			}
			case -1:
			{
				IL2CPP_ASSERT(!hybridclr::metadata::IsInstanceMethod(curMethod));
				void** newArgs = (void**)alloca(sizeof(void*) * (size_t)curMethod->parameters_count);
				newArgs[0] = curTarget;
				for (int k = 0, endK = curMethod->parameters_count; k < endK; k++)
				{
					newArgs[k + 1] = __args[k];
				}
				curMethod->invoker_method(curMethod->methodPointerCallByInterp, curMethod, nullptr, newArgs, __ret);
				break;
			}
			case 1:
			{
				IL2CPP_ASSERT(hybridclr::metadata::IsInstanceMethod(curMethod) && curMethod->parameters_count);
				curTarget = (Il2CppObject*)__args[0];
				if (!curTarget)
				{
					il2cpp::vm::Exception::RaiseNullReferenceException();
				}
				curMethod->invoker_method(curMethod->methodPointerCallByInterp, curMethod, curTarget, __args + 1, __ret);
				break;
			}
			default:
			{
				RaiseExecutionEngineException("bad delegate method");
				break;
			}
			}
		}
	}
	#else
	static void* InterpterInvoke(Il2CppMethodPointer methodPointer, const MethodInfo* method, void* __this, void** __args)
	{
		StackObject args[256];
		bool isInstanceMethod = metadata::IsInstanceMethod(method);
		if (isInstanceMethod)
		{
			__this = (Il2CppObject*)__this + (methodPointer != method->methodPointerCallByInterp);
			args[0].ptr = __this;
		}
		InterpMethodInfo* imi = method->interpData ? (InterpMethodInfo*)method->interpData : InterpreterModule::GetInterpMethodInfo(method);
		MethodArgDesc* argDescs = imi->args + isInstanceMethod;
		ConvertInvokeArgs(args + isInstanceMethod, method, argDescs, __args);
		if (method->return_type->type == IL2CPP_TYPE_VOID)
		{
			Interpreter::Execute(method, args, nullptr);
			return nullptr;
		}
		else
		{
			IL2CPP_ASSERT(GetTypeArgDesc(method->return_type).stackObjectSize <= hybridclr::metadata::kMaxRetValueTypeStackObjectSize);
			StackObject ret[hybridclr::metadata::kMaxRetValueTypeStackObjectSize];
			Interpreter::Execute(method, args, ret);
			return TranslateNativeValueToBoxValue(method->return_type, ret);
		}
	}

	static void* InterpreterDelegateInvoke(Il2CppMethodPointer, const MethodInfo* method, void* __this, void** __args)
	{
		Il2CppMulticastDelegate* del = (Il2CppMulticastDelegate*)__this;
		Il2CppDelegate** firstSubDel;
		int32_t subDelCount;
		if (del->delegates)
		{
			firstSubDel = (Il2CppDelegate**)il2cpp::vm::Array::GetFirstElementAddress(del->delegates);
			subDelCount = il2cpp::vm::Array::GetLength(del->delegates);
		}
		else
		{
			firstSubDel = (Il2CppDelegate**)&del;
			subDelCount = 1;
		}
		void* ret = nullptr;
		for (int32_t i = 0; i < subDelCount; i++)
		{
			Il2CppDelegate* cur = firstSubDel[i];
			const MethodInfo* curMethod = cur->method;
			Il2CppObject* curTarget = cur->target;
			if (curMethod->invoker_method == nullptr)
			{
				RaiseExecutionEngineExceptionMethodIsNotFound(curMethod);
			}
			switch ((int)(method->parameters_count - curMethod->parameters_count))
			{
			case 0:
			{
				if (metadata::IsInstanceMethod(curMethod) && !curTarget)
				{
					il2cpp::vm::Exception::RaiseNullReferenceException();
				}
				curTarget += (IS_CLASS_VALUE_TYPE(curMethod->klass));
				ret = curMethod->invoker_method(curMethod->methodPointerCallByInterp, curMethod, curTarget, __args);
				break;
			}
			case -1:
			{
				IL2CPP_ASSERT(!hybridclr::metadata::IsInstanceMethod(curMethod));
				void** newArgs = (void**)alloca(sizeof(void*) * (size_t)curMethod->parameters_count);
				newArgs[0] = curTarget;
				for (int k = 0, endK = curMethod->parameters_count; k < endK; k++)
				{
					newArgs[k + 1] = __args[k];
				}
				ret = curMethod->invoker_method(curMethod->methodPointerCallByInterp, curMethod, nullptr, newArgs);
				break;
			}
			case 1:
			{
				IL2CPP_ASSERT(hybridclr::metadata::IsInstanceMethod(curMethod) && curMethod->parameters_count);
				curTarget = (Il2CppObject*)__args[0];
				if (!curTarget)
				{
					il2cpp::vm::Exception::RaiseNullReferenceException();
				}
				ret = curMethod->invoker_method(curMethod->methodPointerCallByInterp, curMethod, curTarget, __args + 1);
				break;
			}
			default:
			{
				RaiseExecutionEngineException("bad delegate method");
				break;
			}
			}
		}
		return ret;
	}
	#endif

	InvokerMethod InterpreterModule::GetMethodInvoker(const Il2CppMethodDefinition* method)
	{
		Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeDefinitionIndex(method->declaringType);
		const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(method->nameIndex);
		// special for Delegate::DynamicInvoke
		return !klass || !metadata::IsChildTypeOfMulticastDelegate(klass) || strcmp(methodName, "Invoke") ? InterpterInvoke : InterpreterDelegateInvoke;
	}

	InvokerMethod InterpreterModule::GetMethodInvoker(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		return !klass || !metadata::IsChildTypeOfMulticastDelegate(klass) || strcmp(method->name, "Invoke") ? InterpterInvoke : InterpreterDelegateInvoke;
	}

	bool InterpreterModule::IsImplementsByInterpreter(const MethodInfo* method)
	{
		return method->invoker_method == InterpreterDelegateInvoke || method->invoker_method == InterpterInvoke;
	}

	InterpMethodInfo* InterpreterModule::GetInterpMethodInfo(const MethodInfo* methodInfo)
	{
		RuntimeInitClassCCtor(methodInfo);
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

		if (methodInfo->interpData)
		{
			return (InterpMethodInfo*)methodInfo->interpData;
		}
		IL2CPP_ASSERT(methodInfo->isInterpterImpl);

		metadata::Image* image = metadata::IsInterpreterMethod(methodInfo) ? hybridclr::metadata::MetadataModule::GetImage(methodInfo->klass)
			: (metadata::Image*)hybridclr::metadata::AOTHomologousImage::FindImageByAssembly(
				methodInfo->klass->rank ? il2cpp_defaults.corlib->assembly : methodInfo->klass->image->assembly);
		IL2CPP_ASSERT(image);

		metadata::MethodBody* methodBody = image->GetMethodBody(methodInfo->token);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			TEMP_FORMAT(errMsg, "Method body is null. %s.%s::%s", methodInfo->klass->namespaze, methodInfo->klass->name, methodInfo->name);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		}
		InterpMethodInfo* imi = new (IL2CPP_MALLOC_ZERO(sizeof(InterpMethodInfo))) InterpMethodInfo;
		transform::HiTransform::Transform(image, methodInfo, *methodBody, *imi);
		il2cpp::os::Atomic::FullMemoryBarrier();
		const_cast<MethodInfo*>(methodInfo)->interpData = imi;
		return imi;
	}
}
}

