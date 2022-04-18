#pragma once

#include <stdint.h>
#include <cstring>
#include <memory>

#include "codegen/il2cpp-codegen.h"
#include "utils/Memory.h"
#include "utils/StringView.h"
#include "vm/GlobalMetadataFileInternals.h"
#include "vm/Exception.h"
#include "vm/Class.h"
#include "icalls/mscorlib/System/Type.h"
#include "icalls/mscorlib/System/MonoType.h"

namespace huatuo
{

#if IL2CPP_BYTE_ORDER != IL2CPP_LITTLE_ENDIAN
#error "only support litten endian"
#endif

#if	PLATFORM_ARCH_64 != 1
#error "only support 64bit"
#endif


#ifndef ENABLE_PLACEHOLDER_DLL
#define ENABLE_PLACEHOLDER_DLL 1
#endif

    typedef uint8_t byte;

#define TEMP_FORMAT(var, fmt, ...) char var[600]; \
	snprintf(var, sizeof(var), fmt, __VA_ARGS__);

    void LogPanic(const char* errMsg);

    const char* GetAssemblyNameFromPath(const char* assPath);

    const char* CopyString(const char* src);

    const char* ConcatNewString(const char* s1, const char* s2);

	void* CopyBytes(const void* src, size_t length);

	struct CStringHash
	{
		size_t operator()(const char* s) const noexcept
		{
			uint32_t hash = 0;

			for (; *s; ++s)
			{
				hash += *s;
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}

			hash += (hash << 3);
			hash ^= (hash >> 11);
			hash += (hash << 15);

			return hash;
		}
	};

	struct CStringEqualTo
	{
		bool operator()(const char* _Left, const char* _Right) const
		{
			return std::strcmp(_Left, _Right) == 0;
		}
	};

	inline il2cpp::utils::StringView<char> CStringToStringView(const char* str)
	{
		return il2cpp::utils::StringView<char>(str, std::strlen(str));
	}

	inline void RaiseHuatuoNotSupportedException(const char* msg)
	{
		return il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetNotSupportedException(msg));
	}

	inline void RaiseHuatuoExecutionEngineException(const char* msg)
	{
		return il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(msg));
	}

	inline Il2CppString* GetKlassFullName(const Il2CppType* type)
	{
		Il2CppReflectionType* refType = il2cpp::icalls::mscorlib::System::Type::internal_from_handle((intptr_t)type);
		return il2cpp::icalls::mscorlib::System::MonoType::getFullName(refType, true, false);
	}

	inline void RaiseMethodNotFindException(const Il2CppType* type, const char* methodName)
	{
		if (!type)
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException("type not exists"));
		}

		Il2CppString* fullName = GetKlassFullName(type);
		std::string stdFullName = il2cpp::utils::StringUtils::Utf16ToUtf8(fullName->chars);
		TEMP_FORMAT(errMsg, "MethodNotFind %s::%s", stdFullName.c_str(), methodName);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingMethodException(errMsg));
	}

	inline void AppendTypeName(std::string& s, const Il2CppType* type)
	{
		Il2CppString* typeName = GetKlassFullName(type);
		s.append(il2cpp::utils::StringUtils::Utf16ToUtf8(typeName->chars));
	}

	inline std::string GetMethodNameWithSignature(const MethodInfo* method)
	{
		std::string name;
		AppendTypeName(name, method->return_type);
		name.append(" ");
		
		Il2CppString* klassName = GetKlassFullName(&method->klass->byval_arg);
		name.append(il2cpp::utils::StringUtils::Utf16ToUtf8(klassName->chars));
		name.append("::");
		name.append(method->name);
		if (method->genericMethod && method->genericMethod->context.method_inst)
		{
			name.append("<");
			const Il2CppGenericInst* gi= method->genericMethod->context.method_inst;
			for (uint32_t i = 0; i < gi->type_argc; i++)
			{
				if (i > 0)
				{
					name.append(",");
				}
				AppendTypeName(name, gi->type_argv[i]);
			}
			name.append(">");
		}
		name.append("(");
		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			if (i > 0)
			{
				name.append(",");
			}
			AppendTypeName(name, method->parameters[i].parameter_type);
		}
		name.append(")");
		return name;
	}

	inline void RaiseMethodPointerNotImplementException(const MethodInfo* method)
	{
		std::string methodName = GetMethodNameWithSignature(method);
		TEMP_FORMAT(errMsg, "MethodPointerNotImplement %s", methodName.c_str());
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingMethodException(errMsg));
	}

	inline void RaiseMissingFieldException(const Il2CppType* type, const char* fieldName)
	{
		if (!type)
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException("type not exists"));
		}
		Il2CppString* fullName = GetKlassFullName(type);
		std::string stdFullName = il2cpp::utils::StringUtils::Utf16ToUtf8(fullName->chars);
		TEMP_FORMAT(errMsg, "field %s::%s not exists", stdFullName.c_str(), fieldName);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingFieldException(errMsg));
	}

}


