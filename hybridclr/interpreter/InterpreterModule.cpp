#include "InterpreterModule.h"

#include "Interpreter.h"

#include <unordered_map>

#include "Baselib.h"
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

	static Il2CppHashMap<const char*, Managed2NativeCallMethod, CStringHash, CStringEqualTo> s_managed2natives;
	static Il2CppHashMap<const char*, Il2CppMethodPointer, CStringHash, CStringEqualTo> s_native2manageds;
	static Il2CppHashMap<const char*, Il2CppMethodPointer, CStringHash, CStringEqualTo> s_adjustThunks;
	static Il2CppHashMap<const char*, const char*, CStringHash, CStringEqualTo> s_fullName2signature;

	static Il2CppHashMap<const MethodInfo*, const ReversePInvokeInfo*, il2cpp::utils::PointerHash<MethodInfo>> s_methodInfo2ReverseInfos;
	static Il2CppHashMap<Il2CppMethodPointer, const ReversePInvokeInfo*, il2cpp::utils::PassThroughHash<Il2CppMethodPointer>> s_methodPointer2ReverseInfos;
	static Il2CppHashMap<const char*, int32_t, CStringHash, CStringEqualTo> s_methodSig2Indexs;
	static std::vector<ReversePInvokeInfo> s_reverseInfos;

	static baselib::ReentrantLock s_reversePInvokeMethodLock;

	const MethodInfo* InterpreterModule::GetMethodInfoByReversePInvokeWrapperIndex(int32_t index)
	{
		return s_reverseInfos[index].methodInfo;
	}

	const MethodInfo* InterpreterModule::GetMethodInfoByReversePInvokeWrapperMethodPointer(Il2CppMethodPointer methodPointer)
	{
		auto it = s_methodPointer2ReverseInfos.find(methodPointer);
		return it != s_methodPointer2ReverseInfos.end() ? it->second->methodInfo : nullptr;
	}

	int32_t InterpreterModule::GetWrapperIndexByReversePInvokeWrapperMethodPointer(Il2CppMethodPointer methodPointer)
	{
		auto it = s_methodPointer2ReverseInfos.find(methodPointer);
		return it != s_methodPointer2ReverseInfos.end() ? it->second->index : -1;
	}

	static void InitReversePInvokeInfo()
	{
		for (int32_t i = 0; ; i++)
		{
			const ReversePInvokeMethodData& data = g_reversePInvokeMethodStub[i];
			if (data.methodPointer == nullptr)
			{
				break;
			}
			s_reverseInfos.push_back({ i, data.methodPointer, nullptr });
			auto it = s_methodSig2Indexs.find(data.methodSig);
			if (it == s_methodSig2Indexs.end())
			{
				s_methodSig2Indexs.insert({ data.methodSig, i });
			}
		}
		s_methodInfo2ReverseInfos.resize(s_reverseInfos.size() * 2);
		s_methodPointer2ReverseInfos.resize(s_reverseInfos.size() * 2);
		for (ReversePInvokeInfo& rpi : s_reverseInfos)
		{
			s_methodPointer2ReverseInfos.insert({ rpi.methodPointer, &rpi });
		}
	}

	Il2CppMethodPointer InterpreterModule::GetReversePInvokeWrapper(const Il2CppImage* image, const MethodInfo* method, Il2CppCallConvention callConvention)
	{
		if (!hybridclr::metadata::IsStaticMethod(method))
		{
			return nullptr;
		}

		{
			il2cpp::os::FastAutoLock lock(&s_reversePInvokeMethodLock);
			auto it = s_methodInfo2ReverseInfos.find(method);
			if (it != s_methodInfo2ReverseInfos.end())
			{
				return it->second->methodPointer;
			}
		}

		char sigName[1000];
		sigName[0] = 'A' + callConvention;
		ComputeSignature(method, false, sigName + 1, sizeof(sigName) - 2);

		il2cpp::os::FastAutoLock lock(&s_reversePInvokeMethodLock);


		auto it = s_methodInfo2ReverseInfos.find(method);
		if (it != s_methodInfo2ReverseInfos.end())
		{
			return it->second->methodPointer;
		}

		auto it2 = s_methodSig2Indexs.find(sigName);
		if (it2 == s_methodSig2Indexs.end())
		{
			TEMP_FORMAT(methodSigBuf, "GetReversePInvokeWrapper fail. not find wrapper of method:%s", GetMethodNameWithSignature(method).c_str());
			RaiseExecutionEngineException(methodSigBuf);
		}
		int32_t wrapperIndex = it2->second;
		const ReversePInvokeMethodData& data = g_reversePInvokeMethodStub[wrapperIndex];
		if (data.methodPointer == nullptr || std::strcmp(data.methodSig, sigName))
		{
			TEMP_FORMAT(methodSigBuf, "GetReversePInvokeWrapper fail. exceed max wrapper num of method:%s", GetMethodNameWithSignature(method).c_str());
			RaiseExecutionEngineException(methodSigBuf);
		}

		s_methodSig2Indexs[sigName] = wrapperIndex + 1;

		ReversePInvokeInfo& rpi = s_reverseInfos[wrapperIndex];
		rpi.methodInfo = method;
		s_methodInfo2ReverseInfos.insert({ method, &rpi });
		return rpi.methodPointer;
	}

	static void InitMethodBridge()
	{
		for (size_t i = 0; ; i++)
		{
			const Managed2NativeMethodInfo& method = g_managed2nativeStub[i];
			if (!method.signature)
			{
				break;
			}
			s_managed2natives.insert({ method.signature, method.method });
		}
		for (size_t i = 0; ; i++)
		{
			const Native2ManagedMethodInfo& method = g_native2managedStub[i];
			if (!method.signature)
			{
				break;
			}
			s_native2manageds.insert({ method.signature, method.method });
		}

		for (size_t i = 0; ; i++)
		{
			const NativeAdjustThunkMethodInfo& method = g_adjustThunkStub[i];
			if (!method.signature)
			{
				break;
			}
			s_adjustThunks.insert({ method.signature, method.method });
		}
		for (size_t i = 0; ; i++)
		{
			const FullName2Signature& nameSig = g_fullName2SignatureStub[i];
			if (!nameSig.fullName)
			{
				break;
			}
			s_fullName2signature.insert({ nameSig.fullName, nameSig.signature });
		}
	}

	void InterpreterModule::Initialize()
	{
		InitMethodBridge();
		InitReversePInvokeInfo();
	}

	void InterpreterModule::NotSupportNative2Managed()
	{
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("NotSupportNative2Managed"));
	}

	void InterpreterModule::NotSupportAdjustorThunk()
	{
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("NotSupportAdjustorThunk"));
	}

	const char* InterpreterModule::GetValueTypeSignature(const char* fullName)
	{
		auto it = s_fullName2signature.find(fullName);
		return it != s_fullName2signature.end() ? it->second : "$";
	}

	static void* NotSupportInvoke(Il2CppMethodPointer, const MethodInfo* method, void*, void**)
	{
		char sigName[1000];
		ComputeSignature(method, true, sigName, sizeof(sigName) - 1);
		TEMP_FORMAT(errMsg, "Invoke method missing. sinature:%s %s.%s::%s", sigName, method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		return nullptr;
	}

	template<typename T>
	const Managed2NativeCallMethod GetManaged2NativeMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = s_managed2natives.find(sigName);
		return it != s_managed2natives.end() ? it->second : nullptr;
	}

	template<typename T>
	const Il2CppMethodPointer GetNative2ManagedMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = s_native2manageds.find(sigName);
		return it != s_native2manageds.end() ? it->second : InterpreterModule::NotSupportNative2Managed;
	}

	template<typename T>
	const Il2CppMethodPointer GetNativeAdjustMethodMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = s_adjustThunks.find(sigName);
		return it != s_adjustThunks.end() ? it->second : InterpreterModule::NotSupportAdjustorThunk;
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
			Interpreter::Execute(method,  localVarBase + argVarIndexs[0], ret);
			return;
		}
		if (method->invoker_method == nullptr)
		{
			char sigName[1000];
			ComputeSignature(method, true, sigName, sizeof(sigName) - 1);

			TEMP_FORMAT(errMsg, "GetManaged2NativeMethodPointer. sinature:%s not support.", sigName);
			RaiseMethodNotSupportException(method, errMsg);
		}
		if (!InitAndGetInterpreterDirectlyCallMethodPointer(method))
		{
			RaiseAOTGenericMethodNotInstantiatedException(method);
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
		auto it = s_managed2natives.find(sigName);
		return it != s_managed2natives.end() ? it->second : Managed2NativeCallByReflectionInvoke;
	}

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const metadata::ResolveStandAloneMethodSig& method)
	{
		char sigName[1000];
		ComputeSignature(method.returnType, method.params, metadata::IsPrologHasThis(method.flags), sigName, sizeof(sigName) - 1);
		auto it = s_managed2natives.find(sigName);
		return it != s_managed2natives.end() ? it->second : Managed2NativeCallByReflectionInvoke;
	}

	static void RaiseExecutionEngineExceptionMethodIsNotFound(const MethodInfo* method)
	{
		if (il2cpp::vm::Method::GetClass(method))
			RaiseExecutionEngineException(il2cpp::vm::Method::GetFullName(method).c_str());
		else
			RaiseExecutionEngineException(il2cpp::vm::Method::GetNameWithGenericTypes(method).c_str());
	}

	#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
	
	static void InterpreterInvoke(Il2CppMethodPointer methodPointer, const MethodInfo* method, void* __this, void** __args, void* __ret)
	{
		InterpMethodInfo* imi = method->interpData ? (InterpMethodInfo*)method->interpData : InterpreterModule::GetInterpMethodInfo(method);
		bool isInstanceMethod = metadata::IsInstanceMethod(method);
		StackObject* args = (StackObject*)alloca(sizeof(StackObject) * imi->argStackObjectSize);
		if (isInstanceMethod)
		{
			if (IS_CLASS_VALUE_TYPE(method->klass))
			{
				__this = (Il2CppObject*)__this + (methodPointer != method->methodPointerCallByInterp);
			}
			args[0].ptr = __this;
		}
		
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
			if (!InitAndGetInterpreterDirectlyCallMethodPointer(curMethod))
			{
				RaiseAOTGenericMethodNotInstantiatedException(curMethod);
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
				void** newArgs = (void**)alloca(sizeof(void*) * (size_t)(curMethod->parameters_count + 1));
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
	static void* InterpreterInvoke(Il2CppMethodPointer methodPointer, const MethodInfo* method, void* __this, void** __args)
	{
		InterpMethodInfo* imi = method->interpData ? (InterpMethodInfo*)method->interpData : InterpreterModule::GetInterpMethodInfo(method);
		StackObject* args = (StackObject*)alloca(sizeof(StackObject) * imi->argStackObjectSize);
		bool isInstanceMethod = metadata::IsInstanceMethod(method);
		if (isInstanceMethod)
		{
			if (IS_CLASS_VALUE_TYPE(method->klass))
			{
				__this = (Il2CppObject*)__this + (methodPointer != method->methodPointerCallByInterp);
			}
			args[0].ptr = __this;
		}
		MethodArgDesc* argDescs = imi->args + isInstanceMethod;
		ConvertInvokeArgs(args + isInstanceMethod, method, argDescs, __args);
		if (method->return_type->type == IL2CPP_TYPE_VOID)
		{
			Interpreter::Execute(method, args, nullptr);
			return nullptr;
		}
		else
		{
			StackObject* ret = (StackObject*)alloca(sizeof(StackObject) * imi->retStackObjectSize);
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
			if (!InitAndGetInterpreterDirectlyCallMethodPointer(curMethod))
			{
				RaiseAOTGenericMethodNotInstantiatedException(curMethod);
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
				void** newArgs = (void**)alloca(sizeof(void*) * (size_t)(curMethod->parameters_count + 1));
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
		return !klass || !metadata::IsChildTypeOfMulticastDelegate(klass) || strcmp(methodName, "Invoke") ? InterpreterInvoke : InterpreterDelegateInvoke;
	}

	InvokerMethod InterpreterModule::GetMethodInvoker(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		return !klass || !metadata::IsChildTypeOfMulticastDelegate(klass) || strcmp(method->name, "Invoke") ? InterpreterInvoke : InterpreterDelegateInvoke;
	}

	bool InterpreterModule::IsImplementsByInterpreter(const MethodInfo* method)
	{
		return method->invoker_method == InterpreterDelegateInvoke || method->invoker_method == InterpreterInvoke;
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

		metadata::MethodBody tempMethodBody = {};
		metadata::MethodBody* methodBody = image->GetMethodBody(methodInfo->token, tempMethodBody);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			TEMP_FORMAT(errMsg, "Method body is null. %s.%s::%s", methodInfo->klass->namespaze, methodInfo->klass->name, methodInfo->name);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		}
		InterpMethodInfo* imi = new (HYBRIDCLR_METADATA_MALLOC(sizeof(InterpMethodInfo))) InterpMethodInfo;
		transform::HiTransform::Transform(image, methodInfo, *methodBody, *imi);
		il2cpp::os::Atomic::FullMemoryBarrier();
		const_cast<MethodInfo*>(methodInfo)->interpData = imi;
		return imi;
	}
}
}

