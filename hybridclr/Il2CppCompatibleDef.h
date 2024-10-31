#pragma once

#include "il2cpp-config.h"
#include "codegen/il2cpp-codegen-metadata.h"
#include "il2cpp-class-internals.h"

#include "vm/Array.h"
#include "vm/Type.h"
#include "vm/Runtime.h"
#include "vm/GlobalMetadataFileInternals.h"
#include "vm/MetadataAlloc.h"
#include "icalls/mscorlib/System/Type.h"
#include "gc/GarbageCollector.h"

#if HYBRIDCLR_UNITY_2020
#include "icalls/mscorlib/System/MonoType.h"
#elif HYBRIDCLR_UNITY_2021_OR_NEW
#include "icalls/mscorlib/System/RuntimeType.h"
#include "icalls/mscorlib/System/RuntimeTypeHandle.h"
#elif HYBRIDCLR_UNITY_2019
#include "icalls/mscorlib/System/MonoType.h"
#if IL2CPP_SIZEOF_VOID_P == 8
#define PLATFORM_ARCH_64 1
#else
#define PLATFORM_ARCH_64 0
#endif
#elif !defined(HYBRIDCLR_UNITY_VERSION)
#error "please run 'HybridCLR/Generate/All' before building"
#else
#error "unsupported unity version"
#endif

#if IL2CPP_BYTE_ORDER != IL2CPP_LITTLE_ENDIAN
#error "only support litten endian"
#endif

#if	PLATFORM_ARCH_64
#define HYBRIDCLR_ARCH_64 1
#else
#define HYBRIDCLR_ARCH_64 0
#endif

#define PTR_SIZE IL2CPP_SIZEOF_VOID_P

#if HYBRIDCLR_ARCH_64 || HYBRIDCLR_TARGET_X86
#define SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS  1
#else
#define SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS  0
#endif

#ifndef ENABLE_PLACEHOLDER_DLL
#define ENABLE_PLACEHOLDER_DLL 1
#endif

#if IL2CPP_ENABLE_WRITE_BARRIERS
#define HYBRIDCLR_ENABLE_WRITE_BARRIERS 1
#else
#define HYBRIDCLR_ENABLE_WRITE_BARRIERS 0
#endif

#ifndef HYBRIDCLR_ENABLE_PROFILER
#define HYBRIDCLR_ENABLE_PROFILER  (IL2CPP_ENABLE_PROFILER && (IL2CPP_DEBUG || HYBRIDCLR_ENABLE_PROFILER_IN_RELEASE_BUILD))
#endif

#ifndef HYBRIDCLR_ENABLE_STRACKTRACE
#define HYBRIDCLR_ENABLE_STRACKTRACE (IL2CPP_ENABLE_STACKTRACE_SENTRIES && (IL2CPP_DEBUG || HYBRIDCLR_ENABLE_STRACE_TRACE_IN_WEBGL_RELEASE_BUILD))
#endif

#if UNITY_ENGINE_TUANJIE
#define HYBRIDCLR_MALLOC(size) IL2CPP_MALLOC(size, IL2CPP_MEM_META_POOL)
#define HYBRIDCLR_MALLOC_ALIGNED(size, alignment) IL2CPP_MALLOC_ALIGNED(size, alignment, IL2CPP_MEM_META_POOL)
#define HYBRIDCLR_MALLOC_ZERO(size) IL2CPP_MALLOC_ZERO(size, IL2CPP_MEM_META_POOL)
#define HYBRIDCLR_CALLOC(count, size) IL2CPP_CALLOC(count, size, IL2CPP_MEM_META_POOL)
#define HYBRIDCLR_FREE(ptr) IL2CPP_FREE(ptr, IL2CPP_MEM_META_POOL)
#define HYBRIDCLR_FREE_ALIGNED(ptr) IL2CPP_FREE_ALIGNED(ptr, IL2CPP_MEM_META_POOL)
#define HYBRIDCLR_METADATA_MALLOC(size) il2cpp::vm::MetadataMalloc(size, IL2CPP_MSTAT_TYPE)
#define HYBRIDCLR_METADATA_CALLOC(count, size) il2cpp::vm::MetadataCalloc(count, size, IL2CPP_MSTAT_TYPE)
#else
#define HYBRIDCLR_MALLOC(size) IL2CPP_MALLOC(size)
#define HYBRIDCLR_MALLOC_ALIGNED(size, alignment) IL2CPP_MALLOC_ALIGNED(size, alignment)
#define HYBRIDCLR_MALLOC_ZERO(size) IL2CPP_MALLOC_ZERO(size)
#define HYBRIDCLR_CALLOC(count, size) IL2CPP_CALLOC(count, size)
#define HYBRIDCLR_FREE(ptr) IL2CPP_FREE(ptr)
#define HYBRIDCLR_FREE_ALIGNED(ptr) IL2CPP_FREE_ALIGNED(ptr)
#define HYBRIDCLR_METADATA_MALLOC(size) il2cpp::vm::MetadataMalloc(size)
#define HYBRIDCLR_METADATA_CALLOC(count, size) il2cpp::vm::MetadataCalloc(count, size)
#endif


namespace hybridclr
{

	extern const char* g_placeHolderAssemblies[];

	Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointerSlow(MethodInfo* method);

	inline Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointer(const MethodInfo* method)
	{
		Il2CppMethodPointer methodPointer = method->methodPointerCallByInterp;
		if (methodPointer)
		{
			return methodPointer;
		}
		if (method->initInterpCallMethodPointer)
		{
			return methodPointer;
		}
		return InitAndGetInterpreterDirectlyCallMethodPointerSlow(const_cast<MethodInfo*>(method));
	}

	inline Il2CppMethodPointer InitAndGetInterpreterDirectlyCallVirtualMethodPointer(const MethodInfo* method)
	{
		Il2CppMethodPointer methodPointer = method->virtualMethodPointerCallByInterp;
		if (methodPointer)
		{
			return methodPointer;
		}
		if (method->initInterpCallMethodPointer)
		{
			return methodPointer;
		}
		InitAndGetInterpreterDirectlyCallMethodPointerSlow(const_cast<MethodInfo*>(method));
		return method->virtualMethodPointerCallByInterp;
	}

	inline void HYBRIDCLR_SET_WRITE_BARRIER(void** ptr)
	{
#if HYBRIDCLR_ENABLE_WRITE_BARRIERS
		il2cpp::gc::GarbageCollector::SetWriteBarrier(ptr);
#endif
	}

	inline void HYBRIDCLR_SET_WRITE_BARRIER(void** ptr, size_t size)
	{
#if HYBRIDCLR_ENABLE_WRITE_BARRIERS
		il2cpp::gc::GarbageCollector::SetWriteBarrier(ptr, size);
#endif
	}
}

#if HYBRIDCLR_UNITY_2019 || HYBRIDCLR_UNITY_2020

inline bool IS_CLASS_VALUE_TYPE(const Il2CppClass* klass)
{
	return klass->valuetype;
}

inline bool IS_CCTOR_FINISH_OR_NO_CCTOR(const Il2CppClass* klass)
{
	return (klass->cctor_finished) || !(klass->has_cctor);
}

inline const Il2CppType* GET_METHOD_PARAMETER_TYPE(const ParameterInfo& param)
{
	return param.parameter_type;
}

inline uint32_t GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(const Il2CppCustomAttributeTypeRange& tr)
{
	return tr.start;
}

inline void SET_IL2CPPTYPE_VALUE_TYPE(Il2CppType& type, bool v)
{

}

inline void COPY_IL2CPPTYPE_VALUE_TYPE_FLAG(Il2CppType& dst, const Il2CppType& src)
{

}

#define GET_ARRAY_ELEMENT_ADDRESS load_array_elema
#define VALUE_TYPE_METHOD_POINTER_IS_ADJUST_METHOD 1

namespace hybridclr
{
	inline Il2CppReflectionType* GetReflectionTypeFromName(Il2CppString* name)
	{
		return il2cpp::icalls::mscorlib::System::Type::internal_from_name(name, true, false);
	}

	inline void ConstructDelegate(Il2CppDelegate* delegate, Il2CppObject* target, const MethodInfo* method)
	{
		delegate->method_ptr = InitAndGetInterpreterDirectlyCallVirtualMethodPointer(method);
		delegate->method = method;
		delegate->target = target;
#if HYBRIDCLR_ENABLE_WRITE_BARRIERS
		if (target)
		{
			HYBRIDCLR_SET_WRITE_BARRIER((void**)&delegate->target);
		}
#endif
		//il2cpp::vm::Type::ConstructDelegate(delegate, target, InitAndGetInterpreterDirectlyCallMethodPointer(method), method);
	}

	inline const MethodInfo* GetGenericVirtualMethod(const MethodInfo* result, const MethodInfo* inflateMethod)
	{
		return il2cpp::vm::Runtime::GetGenericVirtualMethod(result, inflateMethod);
	}

	inline void* GetNulllableDataOffset(void* nullableObj, Il2CppClass* nullableClass)
	{
		uint32_t field_offset = nullableClass->fields[0].offset - sizeof(Il2CppObject); // offset of value field
		return (uint8_t*)nullableObj + field_offset;
	}

	inline uint8_t* GetNulllableHasValueOffset(void* nullableObj, Il2CppClass* nullableClass)
	{
		uint32_t field_offset = nullableClass->fields[1].offset - sizeof(Il2CppObject); // offset of has_value field
		return (uint8_t*)nullableObj + field_offset;
	}

	inline Il2CppString* GetKlassFullName(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::MonoType::getFullName(refType, false, false);
	}

	inline std::string GetKlassFullName2(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::MonoType::getFullName2(refType, false, false);
	}
}
#elif HYBRIDCLR_UNITY_2021_OR_NEW

inline bool IS_CLASS_VALUE_TYPE(const Il2CppClass* klass)
{
	return klass->byval_arg.valuetype;
}

inline bool IS_CCTOR_FINISH_OR_NO_CCTOR(const Il2CppClass* klass)
{
	return klass->cctor_finished_or_no_cctor;
}

inline const Il2CppType* GET_METHOD_PARAMETER_TYPE(const Il2CppType* param)
{
	return param;
}

inline uint32_t GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(const Il2CppCustomAttributeTypeRange& tr)
{
	return tr.startOffset;
}

inline void SET_IL2CPPTYPE_VALUE_TYPE(Il2CppType& type, bool v)
{
	type.valuetype = v;
}

inline void COPY_IL2CPPTYPE_VALUE_TYPE_FLAG(Il2CppType& dst, const Il2CppType& src)
{
	dst.valuetype = src.valuetype;
}

#define GET_ARRAY_ELEMENT_ADDRESS il2cpp_array_addr_with_size
#define VALUE_TYPE_METHOD_POINTER_IS_ADJUST_METHOD 0

namespace hybridclr
{

	inline Il2CppReflectionType* GetReflectionTypeFromName(Il2CppString* name)
	{
		return il2cpp::icalls::mscorlib::System::RuntimeTypeHandle::internal_from_name(name, nullptr, nullptr, true, false, false);
	}

	inline void ConstructDelegate(Il2CppDelegate* delegate, Il2CppObject* target, const MethodInfo* method)
	{
		delegate->target = target;
		delegate->method = method;
		delegate->invoke_impl = InitAndGetInterpreterDirectlyCallVirtualMethodPointer(method);
		delegate->invoke_impl_this = target;
#if HYBRIDCLR_ENABLE_WRITE_BARRIERS
		if (target)
		{
			HYBRIDCLR_SET_WRITE_BARRIER((void**)&delegate->target);
			HYBRIDCLR_SET_WRITE_BARRIER((void**)&delegate->invoke_impl_this);
		}
#endif
	}

	inline const MethodInfo* GetGenericVirtualMethod(const MethodInfo* result, const MethodInfo* inflateMethod)
	{
#if HYBRIDCLR_UNITY_2021
		VirtualInvokeData vid;
		il2cpp::vm::Runtime::GetGenericVirtualMethod(result, inflateMethod, &vid);
		return vid.method;
#else
		return il2cpp::metadata::GenericMethod::GetGenericVirtualMethod(result, inflateMethod);
#endif
	}

	inline void* GetNulllableDataOffset(void* nullableObj, Il2CppClass* nullableClass)
	{
		uint32_t field_offset = nullableClass->fields[1].offset - sizeof(Il2CppObject); // offset of value field
		return (uint8_t*)nullableObj + field_offset;
	}

	inline uint8_t* GetNulllableHasValueOffset(void* nullableObj, Il2CppClass* nullableClass)
	{
		uint32_t field_offset = nullableClass->fields[0].offset - sizeof(Il2CppObject); // offset of has_value field
		return (uint8_t*)nullableObj + field_offset;
	}

	inline Il2CppString* GetKlassFullName(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::RuntimeType::getFullName((Il2CppReflectionRuntimeType*)refType, false, false);
	}

	inline std::string GetKlassFullName2(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::RuntimeType::getFullName2((Il2CppReflectionRuntimeType*)refType, false, false);
	}

}
#endif