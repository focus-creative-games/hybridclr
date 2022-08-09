#pragma once
#include "../hybridclr-compatible-config.h"

#include "il2cpp-config.h"
#include "il2cpp-class-internals.h"

#include "Baselib.h"
#include "vm/Array.h"
#include "vm/Type.h"
#include "vm/Runtime.h"
#include "icalls/mscorlib/System/Type.h"

#if HYBRIDCLR_UNITY_2020
#include "icalls/mscorlib/System/MonoType.h"
#elif HYBRIDCLR_UNITY_2021
#include "icalls/mscorlib/System/RuntimeType.h"
#include "icalls/mscorlib/System/RuntimeTypeHandle.h"
#else
#error "not suppport unity version"
#endif

#if IL2CPP_BYTE_ORDER != IL2CPP_LITTLE_ENDIAN
#error "only support litten endian"
#endif

#if IL2CPP_TARGET_ARM64
#define HYBRIDCLR_TARGET_ARM64 1
#elif IL2CPP_TARGET_ARMV7
#define HYBRIDCLR_TARGET_ARMV7 1
#elif IL2CPP_TARGET_WINDOWS || IL2CPP_TARGET_DARWIN
#if PLATFORM_ARCH_64
#define HYBRIDCLR_TARGET_X64 1
#else
#define HYBRIDCLR_TARGET_X86 1
#endif
#elif IL2CPP_TARGET_JAVASCRIPT
#define HYBRIDCLR_TARGET_JAVASCRIPT 1
#else
#error "not support platform"
#endif

#if	PLATFORM_ARCH_64
#define HYBRIDCLR_ARCH_64 1
#if IL2CPP_TARGET_ARM64
#define HYBRIDCLR_ABI_ARM_64 1
#define HYBRIDCLR_ABI_UNIVERSAL_64 0
#define HYBRIDCLR_ABI_NAME "Arm64"
#else
#define HYBRIDCLR_ABI_UNIVERSAL_64 1
#define HYBRIDCLR_ABI_NAME "General64"
#endif
#define HYBRIDCLR_ABI_UNIVERSAL_32 0
#else
#define HYBRIDCLR_ARCH_64 0
#define HYBRIDCLR_ABI_UNIVERSAL_64 0
#define HYBRIDCLR_ABI_UNIVERSAL_32 1
#define HYBRIDCLR_ABI_NAME "General32"
#endif

#define PTR_SIZE IL2CPP_SIZEOF_VOID_P

#define SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS  (HYBRIDCLR_ARCH_64 || HYBRIDCLR_TARGET_X86)

#ifndef ENABLE_PLACEHOLDER_DLL
#define ENABLE_PLACEHOLDER_DLL 1
#endif

#if HYBRIDCLR_UNITY_2020

#define IS_CLASS_VALUE_TYPE(klass) ((klass)->valuetype)
#define IS_CCTOR_FINISH_OR_NO_CCTOR(klass) ((klass)->cctor_finished) || !((klass)->has_cctor)
#define GET_METHOD_PARAMETER_TYPE(param) param.parameter_type
#define GET_ARRAY_ELEMENT_ADDRESS load_array_elema
#define GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(tr) ((tr).start)

#define SET_IL2CPPTYPE_VALUE_TYPE(type, v) 
#define GET_IL2CPPTYPE_VALUE_TYPE(type)

#define VALUE_TYPE_METHOD_POINTER_IS_ADJUST_METHOD 1

//#define ADJUST_VALUE_TYPE_THIS_POINTER(newPtr, oldPtr) newPtr = oldPtr - 1
//// #define RECOVERY_VALUE_TYPE_THIS_POINTER(newPtr, oldPtr) newPtr = oldPtr + 1
//#define CHECK_UNADJUST_VALUE_TYPE_THIS_POINTER(klass, ptr)

namespace hybridclr
{
	Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointerSlow(MethodInfo* method);

	inline Il2CppMethodPointer GetInterpreterDirectlyCallMethodPointer(const MethodInfo* method)
	{
		Il2CppMethodPointer methodPointer = method->methodPointer;
		if (methodPointer || method->initInterpCallMethodPointer)
		{
			return methodPointer;
		}
		return InitAndGetInterpreterDirectlyCallMethodPointerSlow(const_cast<MethodInfo*>(method));
	}

	inline Il2CppReflectionType* GetReflectionTypeFromName(Il2CppString* name)
	{
		return il2cpp::icalls::mscorlib::System::Type::internal_from_name(name, true, false);
	}

	inline void ConstructDelegate(Il2CppDelegate* delegate, Il2CppObject* target, const MethodInfo* method)
	{
		il2cpp::vm::Type::ConstructDelegate(delegate, target, GetInterpreterDirectlyCallMethodPointer(method), method);
	}

	inline const MethodInfo* GetGenericVirtualMethod(const MethodInfo* result, const MethodInfo* inflateMethod)
	{
		return il2cpp::vm::Runtime::GetGenericVirtualMethod(result, inflateMethod);
	}

	inline void* GetNulllableDataOffset(void* nullableObj, uint32_t size)
	{
		return nullableObj;
	}

	inline uint8_t* GetNulllableHasValueOffset(void* nullableObj, uint32_t size)
	{
		return (uint8_t*)nullableObj + size;
	}

	inline Il2CppString* GetKlassFullName(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::MonoType::getFullName(refType, false, false);
	}
}
#elif HYBRIDCLR_UNITY_2021

#define IS_CLASS_VALUE_TYPE(klass) ((klass)->byval_arg.valuetype)
#define IS_CCTOR_FINISH_OR_NO_CCTOR(klass) ((klass)->cctor_finished_or_no_cctor)
#define GET_METHOD_PARAMETER_TYPE(param) param
#define GET_ARRAY_ELEMENT_ADDRESS il2cpp_array_addr_with_size
#define GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(tr) ((tr).startOffset)

#define DECLARE_INVOKE_METHOD_BEGIN(__methodName__) void __methodName__(Il2CppMethodPointer methodPtr, const MethodInfo* method, void* __this, void** __args, void* __ret)
#define DECLARE_INVOKE_METHOD_RET(__ret__) __ret = __ret__
#define SET_IL2CPPTYPE_VALUE_TYPE(type, v) (type).valuetype = v
#define GET_IL2CPPTYPE_VALUE_TYPE(type) (type).valuetype

#define VALUE_TYPE_METHOD_POINTER_IS_ADJUST_METHOD 0

namespace hybridclr
{
	Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointerSlow(MethodInfo* method);

	inline Il2CppMethodPointer GetInterpreterDirectlyCallMethodPointer(const MethodInfo* method)
	{
		Il2CppMethodPointer methodPointer = method->indirect_call_via_invokers ? method->interpCallMethodPointer : method->methodPointer;
		if (methodPointer || method->initInterpCallMethodPointer)
		{
			return methodPointer;
		}
		return InitAndGetInterpreterDirectlyCallMethodPointerSlow(const_cast<MethodInfo*>(method));
	}

	inline Il2CppReflectionType* GetReflectionTypeFromName(Il2CppString* name)
	{
		return il2cpp::icalls::mscorlib::System::RuntimeTypeHandle::internal_from_name(name, nullptr, nullptr, true, false, false);
	}

	inline void ConstructDelegate(Il2CppDelegate* delegate, Il2CppObject* target, const MethodInfo* method)
	{
		il2cpp::vm::Type::InvokeDelegateConstructor(delegate, target, method);
	}

	inline const MethodInfo* GetGenericVirtualMethod(const MethodInfo* result, const MethodInfo* inflateMethod)
	{
		VirtualInvokeData vid;
		il2cpp::vm::Runtime::GetGenericVirtualMethod(result, inflateMethod, &vid);
		return vid.method;
	}

	inline void* GetNulllableDataOffset(void* nullableObj, uint32_t size)
	{
		return (uint8_t*)nullableObj + size;
	}

	inline uint8_t* GetNulllableHasValueOffset(void* nullableObj, uint32_t size)
	{
		return (uint8_t*)nullableObj;
	}

	inline Il2CppString* GetKlassFullName(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::RuntimeType::getFullName((Il2CppReflectionRuntimeType*)refType, false, false);
	}

}
#endif