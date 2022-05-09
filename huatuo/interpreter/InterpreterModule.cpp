#include "InterpreterModule.h"

#include "Interpreter.h"

#include <unordered_map>

#include "vm/GlobalMetadata.h"
#include "vm/MetadataLock.h"
#include "vm/Class.h"

#include "MethodBridge.h"
#include "../metadata/MetadataModule.h"
#include "../metadata/MetadataUtil.h"
#include "../transform/Transform.h"

namespace huatuo
{
namespace interpreter
{
	il2cpp::os::ThreadLocalValue InterpreterModule::s_machineState;

	static std::unordered_map<const char*, NativeCallMethod, CStringHash, CStringEqualTo> s_calls;
	static std::unordered_map<const char*, NativeInvokeMethod, CStringHash, CStringEqualTo> s_invokes;


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

	void AppendString(char* sigBuf, size_t bufSize, size_t& pos, const char* str)
	{
		size_t len = std::strlen(str);
		if (pos + len < bufSize)
		{
			std::strcpy(sigBuf + pos, str);
			pos += len;
		}
		else
		{
			IL2CPP_ASSERT(false);
		}
	}


	static void AppendValueTypeSignature(int typeSize, bool returnType, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		if (returnType)
		{
			pos += std::sprintf(sigBuf + pos, "s%d", typeSize);
		}
		else
		{
			AppendString(sigBuf, bufferSize, pos, "i");
		}
	}

	void AppendSignature(const Il2CppType* type, bool returnType, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		if (type->byref)
		{
			AppendString(sigBuf, bufferSize, pos, "i");
			return;
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_VOID: AppendString(sigBuf, bufferSize, pos, "v"); break;
		case IL2CPP_TYPE_R4:
		case IL2CPP_TYPE_R8: AppendString(sigBuf, bufferSize, pos, "f"); break;
		case IL2CPP_TYPE_TYPEDBYREF:
		{
			IL2CPP_ASSERT(sizeof(Il2CppTypedRef) == sizeof(void*) * 3);
			AppendValueTypeSignature(sizeof(Il2CppTypedRef), returnType, sigBuf, bufferSize, pos);
			break;
		}
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
			AppendValueTypeSignature(il2cpp::vm::Class::GetValueSize(klass, nullptr), returnType, sigBuf, bufferSize, pos);
			break;
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			const Il2CppType* underlyingGenericType = type->data.generic_class->type;
			if (underlyingGenericType->type == IL2CPP_TYPE_CLASS)
			{
				AppendString(sigBuf, bufferSize, pos, "i");
			}
			else
			{
				IL2CPP_ASSERT(underlyingGenericType->type == IL2CPP_TYPE_VALUETYPE);
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
				AppendValueTypeSignature(il2cpp::vm::Class::GetValueSize(klass, nullptr), returnType, sigBuf, bufferSize, pos);
			}
			break;
		}
		default: AppendString(sigBuf, bufferSize, pos, "i"); break;
		}
	}

	bool ComputSignature(const Il2CppType* ret, const Il2CppType* params, uint32_t paramCount, bool instanceCall, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;
		AppendSignature(ret, true, sigBuf, bufferSize, pos);

		if (instanceCall)
		{
			AppendString(sigBuf, bufferSize, pos, "i");
		}

		for (uint8_t i = 0; i < paramCount; i++)
		{
			AppendSignature(params + i, false, sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	bool ComputSignature(const Il2CppMethodDefinition* method, bool call, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;

		const Il2CppImage* image = huatuo::metadata::MetadataModule::GetImage(method)->GetIl2CppImage();

		AppendSignature(huatuo::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(method->returnType), true, sigBuf, bufferSize, pos);

		if (call && metadata::IsInstanceMethod(method))
		{
			AppendString(sigBuf, bufferSize, pos, "i");
		}

		for (uint8_t i = 0; i < method->parameterCount; i++)
		{
			TypeIndex paramTypeIndex = huatuo::metadata::MetadataModule::GetParameterDefinitionFromIndex(image, method->parameterStart + i)->typeIndex;
			AppendSignature(huatuo::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(paramTypeIndex), false, sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	bool ComputSignature(const MethodInfo* method, bool call, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;

		AppendSignature(method->return_type, true, sigBuf, bufferSize, pos);

		if (call && metadata::IsInstanceMethod(method))
		{
			AppendString(sigBuf, bufferSize, pos, "i");
		}

		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			AppendSignature(GET_METHOD_PARAMETER_TYPE(method->parameters[i]), false, sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	template<typename T>
	const NativeCallMethod* GetNativeCallMethod(const T* method, bool forceStatic)
	{
		char sigName[1000];
		ComputSignature(method, !forceStatic, sigName, sizeof(sigName) - 1);
		auto it = s_calls.find(sigName);
		return (it != s_calls.end()) ? &it->second : nullptr;
	}

	template<typename T>
	const NativeInvokeMethod* GetNativeInvokeMethod(const T* method)
	{
		char sigName[1000];
		ComputSignature(method, false, sigName, sizeof(sigName) - 1);
		auto it = s_invokes.find(sigName);
		return (it != s_invokes.end()) ? &it->second : nullptr;
	}

	static void RaiseMethodNotSupportException(const MethodInfo* method, const char* desc)
	{
		TEMP_FORMAT(errMsg, "%s not support. %s.%s::%s", desc, method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
	}

	static void RaiseMethodNotSupportException(const Il2CppMethodDefinition* method, const char* desc)
	{
		Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeDefinitionIndex(method->declaringType);
		TEMP_FORMAT(errMsg, "%s not support. %s.%s::%s", desc, klass->namespaze, klass->name, il2cpp::vm::GlobalMetadata::GetStringFromIndex(method->nameIndex));
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
	}

	static void NotSupportAOTSignature()
	{
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeInitializationException("", nullptr));
	}

	void NotSupportManaged2Native(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
	{
		TEMP_FORMAT(errMsg, "Managed2Native method missing. %s.%s::%s", method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
	}

	static void* NotSupportInvoke(Il2CppMethodPointer, const MethodInfo* method, void*, void**)
	{
		TEMP_FORMAT(errMsg, "Invoke method missing. %s.%s::%s", method->klass->namespaze, method->klass->name, method->name);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
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
		return (Il2CppMethodPointer)NotSupportManaged2Native;
	}

	Il2CppMethodPointer InterpreterModule::GetMethodPointer(const MethodInfo* method)
	{
		const NativeCallMethod* ncm = GetNativeCallMethod(method, false);
		if (ncm)
		{
			return ncm->method;
		}
		//RaiseMethodNotSupportException(method, "GetMethodPointer");
		return (Il2CppMethodPointer)NotSupportManaged2Native;
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
		return (Il2CppMethodPointer)NotSupportManaged2Native;
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
		return (Il2CppMethodPointer)NotSupportManaged2Native;
	}

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const MethodInfo* method, bool forceStatic)
	{
		const NativeCallMethod* ncm = GetNativeCallMethod(method, forceStatic);
		if (ncm)
		{
			return ncm->managed2NativeMethod;
		}
		RaiseMethodNotSupportException(method, "GetManaged2NativeMethodPointer");
		return nullptr;
	}

	Managed2NativeCallMethod InterpreterModule::GetManaged2NativeMethodPointer(const metadata::ResolveStandAloneMethodSig& method)
	{
		char sigName[1000];
		ComputSignature(&method.returnType, method.params, method.paramCount, false, sigName, sizeof(sigName) - 1);
		auto it = s_calls.find(sigName);
		if (it != s_calls.end())
		{
			return it->second.managed2NativeMethod;
		}
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingMethodException(sigName));
		return nullptr;
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

	InterpMethodInfo* InterpreterModule::GetInterpMethodInfo(metadata::Image* image, const MethodInfo* methodInfo)
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

		if (methodInfo->huatuoData)
		{
			return (InterpMethodInfo*)methodInfo->huatuoData;
		}

		metadata::MethodBody& originMethod = image->GetMethodBody(methodInfo->token);
		InterpMethodInfo* imi = new (IL2CPP_MALLOC_ZERO(sizeof(InterpMethodInfo))) InterpMethodInfo;
		transform::HiTransform::Transform(image, methodInfo, originMethod, *imi);
		il2cpp::os::Atomic::FullMemoryBarrier();
		const_cast<MethodInfo*>(methodInfo)->huatuoData = imi;
		return imi;
	}
}
}

