#pragma once

#include <stdint.h>
#include <cstring>
#include <memory>

#include "Il2CppCompatibleDef.h"

#include "codegen/il2cpp-codegen.h"
#include "utils/Memory.h"
#include "utils/StringView.h"
#include "vm/GlobalMetadataFileInternals.h"
#include "vm/Exception.h"
#include "vm/Class.h"
#include "icalls/mscorlib/System/Type.h"
#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
#include "icalls/mscorlib/System/RuntimeType.h"
#else
#include "icalls/mscorlib/System/MonoType.h"
#endif

namespace hybridclr
{
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

	inline std::string GetKlassCStringFullName(const Il2CppType* type)
	{
		Il2CppString* typeName = GetKlassFullName(type);
		return il2cpp::utils::StringUtils::Utf16ToUtf8(typeName->chars);
	}

	inline void RaiseNotSupportedException(const char* msg)
	{
		TEMP_FORMAT(errMsg, "hybridclr doesn't support %s", msg);
		return il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetNotSupportedException(errMsg));
	}

	inline void RaiseExecutionEngineException(const char* msg)
	{
		return il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(msg));
	}

	inline void RaiseMethodNotFindException(const Il2CppType* type, const char* methodName)
	{
		if (!type)
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException("type not exists"));
		}

		std::string fullName = GetKlassCStringFullName(type);
		TEMP_FORMAT(errMsg, "MethodNotFind %s::%s", fullName.c_str(), methodName);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingMethodException(errMsg));
	}

	inline void AppendTypeName(std::string& s, const Il2CppType* type)
	{
		s.append(GetKlassCStringFullName(type));
	}

	inline std::string GetMethodNameWithSignature(const MethodInfo* method)
	{
		std::string name;
		AppendTypeName(name, method->return_type);
		name.append(" ");
		
		name.append(GetKlassCStringFullName(&method->klass->byval_arg));
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
			AppendTypeName(name, GET_METHOD_PARAMETER_TYPE(method->parameters[i]));
		}
		name.append(")");
		return name;
	}

	inline void RaiseAOTGenericMethodNotInstantiatedException(const MethodInfo* method)
	{
		std::string methodName = GetMethodNameWithSignature(method);
		TEMP_FORMAT(errMsg, "AOT generic method not instantiated in aot. assembly:%s, method:%s", method->klass->image->name, methodName.c_str());
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingMethodException(errMsg));
	}

	inline void RaiseMissingFieldException(const Il2CppType* type, const char* fieldName)
	{
		if (!type)
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException("type not exists"));
		}
		std::string stdFullName = GetKlassCStringFullName(type);
		TEMP_FORMAT(errMsg, "field %s::%s not exists", stdFullName.c_str(), fieldName);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingFieldException(errMsg));
	}

}


