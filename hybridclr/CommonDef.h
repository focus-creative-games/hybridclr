// Copyright 2026 Code Philosophy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <stdint.h>
#include <cstring>
#include <memory>

#include "Il2CppCompatibleDef.h"

#include "utils/Memory.h"
#include "utils/StringView.h"
#include "utils/Il2CppHashSet.h"
#include "utils/Il2CppHashMap.h"
#include "utils/HashUtils.h"
#include "vm/GlobalMetadataFileInternals.h"
#include "vm/Exception.h"
#include "vm/Class.h"
#include "icalls/mscorlib/System/Type.h"
#include "icalls/mscorlib/System/RuntimeType.h"

namespace hybridclr
{
typedef uint8_t byte;

#define TEMP_FORMAT(var, fmt, ...) \
    char var[600];                 \
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
    return GetKlassFullName2(type);
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
        const Il2CppGenericInst* gi = method->genericMethod->context.method_inst;
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

} // namespace hybridclr
