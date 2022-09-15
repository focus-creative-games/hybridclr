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

		static void NotSupportNative2Managed()
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("NotSupportNative2Managed"));
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
			return it != g_native2manageds.end() ? it->second : NotSupportNative2Managed;
		}

		template<typename T>
		const Il2CppMethodPointer GetNativeAdjustMethodMethod(const T* method, bool forceStatic)
		{
			char sigName[1000];
			ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
			auto it = g_adjustThunks.find(sigName);
			return it != g_adjustThunks.end() ? it->second : NotSupportNative2Managed;
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

		void Managed2NativeCallByReflectionInvoke(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
		{
			if (hybridclr::metadata::IsInterpreterMethod(method) || method->invoker_method == nullptr)
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
				void* argValuePtr;
				if (!argType->byref && hybridclr::metadata::IsValueType(argType))
				{
					argValuePtr = argValue;
				}
				else
				{
					argValuePtr = argValue->ptr;
				}
				invokeParams[i] = argValuePtr;
			}
#if HYBRIDCLR_UNITY_2021_OR_NEW
			method->invoker_method(method->methodPointer, method, thisPtr, invokeParams, ret);
#else
			void* retObj = method->invoker_method(method->methodPointer, method, thisPtr, invokeParams);
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
			char sigName[1000];
			ComputeSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
			auto it = g_managed2natives.find(sigName);
			return it != g_managed2natives.end() ? it->second : Managed2NativeCallByReflectionInvoke;
		}

		Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const metadata::ResolveStandAloneMethodSig& method)
		{
			char sigName[1000];
			ComputeSignature(&method.returnType, method.params, method.paramCount, false, sigName, sizeof(sigName) - 1);
			auto it = g_managed2natives.find(sigName);
			return it != g_managed2natives.end()? it->second : Managed2NativeCallByReflectionInvoke;
		}

		inline void* AdjustValueTypeSelfPointer(Il2CppObject* __this)
		{
			return __this + IS_CLASS_VALUE_TYPE(__this->klass);
		}

#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
	static void InterpterInvoke(Il2CppMethodPointer, const MethodInfo* method, void* __this, void** __args, void* __ret)
	{
		bool isInstanceMethod = metadata::IsInstanceMethod(method);
		int32_t argumentCountIncludeThis = isInstanceMethod;
		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			argumentCountIncludeThis += GetTypeArgDesc(GET_METHOD_PARAMETER_TYPE(method->parameters[i])).stackObjectSize;
		}
		StackObject* args = (StackObject*)alloca(sizeof(StackObject) * argumentCountIncludeThis);
		if (isInstanceMethod)
		{
			args[0].ptr = __this;
		}
		ConvertInvokeArgs(args + isInstanceMethod, method, __args);
		Interpreter::Execute(method, args, __ret);
	}
#else
	static void* InterpterInvoke(Il2CppMethodPointer, const MethodInfo* method, void* __this, void** __args)
	{
		bool isInstanceMethod = metadata::IsInstanceMethod(method);
		int32_t argumentCountIncludeThis = isInstanceMethod;
		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			argumentCountIncludeThis += GetTypeArgDesc(GET_METHOD_PARAMETER_TYPE(method->parameters[i])).stackObjectSize;
		}
		if (isInstanceMethod)
		{
			__this = AdjustValueTypeSelfPointer((Il2CppObject*)__this);
		}
		if (method->return_type->type == IL2CPP_TYPE_VOID)
		{
			StackObject* args = (StackObject*)alloca(sizeof(StackObject) * argumentCountIncludeThis);
			if (isInstanceMethod)
			{
				args[0].ptr = __this;
			}
			ConvertInvokeArgs(args + isInstanceMethod, method, __args);
			Interpreter::Execute(method, args, nullptr);
			return nullptr;
		}
		else
		{
			int32_t returnTypeSize = GetTypeArgDesc(method->return_type).stackObjectSize;
			StackObject* args = (StackObject*)alloca(sizeof(StackObject) * (argumentCountIncludeThis + returnTypeSize));
			if (isInstanceMethod)
			{
				args[0].ptr = __this;
			}
			ConvertInvokeArgs(args + isInstanceMethod, method, __args);
			StackObject* ret = args + argumentCountIncludeThis;
			Interpreter::Execute(method, args, ret);
			return TranslateNativeValueToBoxValue(method->return_type, ret);
		}
	}
#endif

	InvokerMethod InterpreterModule::GetMethodInvoker(const Il2CppMethodDefinition* method)
	{
		return InterpterInvoke;
	}

	InvokerMethod InterpreterModule::GetMethodInvoker(const MethodInfo* method)
	{
		return InterpterInvoke;
	}

	InterpMethodInfo* InterpreterModule::GetInterpMethodInfo(const MethodInfo* methodInfo)
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

		if (methodInfo->interpData)
		{
			return (InterpMethodInfo*)methodInfo->interpData;
		}
		RuntimeInitClassCCtor(methodInfo);
		IL2CPP_ASSERT(methodInfo->isInterpterImpl);

		metadata::Image* image = metadata::IsInterpreterMethod(methodInfo) ? hybridclr::metadata::MetadataModule::GetImage(methodInfo->klass)
			: (metadata::Image*)hybridclr::metadata::AOTHomologousImage::FindImageByAssembly(
				methodInfo->klass->rank ? il2cpp_defaults.corlib->assembly : methodInfo->klass->image->assembly);
		IL2CPP_ASSERT(image);

		metadata::MethodBody* methodBody = image->GetMethodBody(methodInfo->token);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			TEMP_FORMAT(errMsg, "%s.%s::%s method body is null. not support external method currently.", methodInfo->klass->namespaze, methodInfo->klass->name, methodInfo->name);
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

