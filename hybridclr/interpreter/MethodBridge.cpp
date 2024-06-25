#include "MethodBridge.h"

#include "vm/Object.h"
#include "vm/Class.h"
#include "metadata/GenericMetadata.h"

#include "../metadata/MetadataModule.h"
#include "../metadata/MetadataUtil.h"

#include "Interpreter.h"
#include "InterpreterModule.h"
#include "MemoryUtil.h"

namespace hybridclr
{
namespace interpreter
{

	void ConvertInvokeArgs(StackObject* resultArgs, const MethodInfo* method, MethodArgDesc* argDescs, void** args)
	{
		int32_t dstIdx = 0;
		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			StackObject* dst = resultArgs + dstIdx;
			MethodArgDesc& argDesc = argDescs[i];
			if (argDesc.passbyValWhenInvoke)
			{
				dst->ptr = args[i];
				++dstIdx;
			}
			else
			{
#if SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS
				CopyStackObject(dst, args[i], argDesc.stackObjectSize);
#else
				std::memcpy(dst, args[i], argDesc.stackObjectSize * sizeof(StackObject));
#endif
				dstIdx += argDesc.stackObjectSize;
			}
		}
	}
	
	static void AppendString(char* sigBuf, size_t bufSize, size_t& pos, const char* str)
	{
		size_t len = std::strlen(str);
		if (pos + len < bufSize)
		{
			std::strcpy(sigBuf + pos, str);
			pos += len;
		}
		else
		{
			RaiseExecutionEngineException("");
		}
	}

	inline void AppendSignatureObjOrRefOrPointer(char* sigBuf, size_t bufSize, size_t& pos)
	{
		AppendString(sigBuf, bufSize, pos, "u");
	}

	inline void AppendSignatureInterpreterValueType(char* sigBuf, size_t bufSize, size_t& pos)
	{
		AppendString(sigBuf, bufSize, pos, "$");
	}

	static void AppendSignature(const Il2CppType* type, char* sigBuf, size_t bufferSize, size_t& pos, bool convertTypeName2SigName = true);

	static bool IsSystemOrUnityAssembly(const Il2CppImage* image)
	{
		const char* assName = image->nameNoExt;
		if (std::strcmp(assName, "mscorlib") == 0)
		{
			return true;
		}
		if (std::strncmp(assName, "System.", 7) == 0)
		{
			return true;
		}
		if (std::strncmp(assName, "UnityEngine.", 12) == 0)
		{
			return true;
		}
		return false;
	}

	static void BuildValueTypeFullName(const Il2CppClass* klass, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		if (klass->declaringType)
		{
			BuildValueTypeFullName(klass->declaringType, sigBuf, bufferSize, pos);
			AppendString(sigBuf, bufferSize, pos, "/");
			AppendString(sigBuf, bufferSize, pos, klass->name);
			return;
		}
		if (!IsSystemOrUnityAssembly(klass->image))
		{
			AppendString(sigBuf, bufferSize, pos, klass->image->nameNoExt);
			AppendString(sigBuf, bufferSize, pos, ":");
		}
		if (klass->namespaze[0])
		{
			AppendString(sigBuf, bufferSize, pos, klass->namespaze);
			AppendString(sigBuf, bufferSize, pos, ".");
		}
		AppendString(sigBuf, bufferSize, pos, klass->name);
	}

	static void BuildGenericValueTypeFullName(const Il2CppType* type, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		const Il2CppType* underlyingGenericType = type->data.generic_class->type;
		const Il2CppClass* underlyingGenericClass = il2cpp::vm::Class::FromIl2CppType(underlyingGenericType);
		BuildValueTypeFullName(underlyingGenericClass, sigBuf, bufferSize, pos);
		AppendString(sigBuf, bufferSize, pos, "<");
		const Il2CppGenericInst* classInst = type->data.generic_class->context.class_inst;
		for (uint32_t i = 0 ; i < classInst->type_argc; ++i)
		{
			if (i != 0)
			{
				AppendString(sigBuf, bufferSize, pos, ",");
			}
			AppendSignature(classInst->type_argv[i], sigBuf, bufferSize, pos, false);
		}
		AppendString(sigBuf, bufferSize, pos, ">");
	}

	static void AppendSignature(const Il2CppType* type, char* sigBuf, size_t bufferSize, size_t& pos, bool convertTypeName2SigName)
	{
		if (type->byref)
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
			return;
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_VOID: AppendString(sigBuf, bufferSize, pos, "v"); break;
		case IL2CPP_TYPE_BOOLEAN: AppendString(sigBuf, bufferSize, pos, "u1"); break;
		case IL2CPP_TYPE_I1: AppendString(sigBuf, bufferSize, pos, "i1"); break;
		case IL2CPP_TYPE_U1: AppendString(sigBuf, bufferSize, pos, "u1"); break;
		case IL2CPP_TYPE_I2: AppendString(sigBuf, bufferSize, pos, "i2"); break;
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_CHAR: AppendString(sigBuf, bufferSize, pos, "u2"); break;
		case IL2CPP_TYPE_I4: AppendString(sigBuf, bufferSize, pos, "i4"); break;
		case IL2CPP_TYPE_U4: AppendString(sigBuf, bufferSize, pos, "u4"); break;
		case IL2CPP_TYPE_R4: AppendString(sigBuf, bufferSize, pos, "r4"); break;
		case IL2CPP_TYPE_R8: AppendString(sigBuf, bufferSize, pos, "r8"); break;
		case IL2CPP_TYPE_I8: AppendString(sigBuf, bufferSize, pos, "i8"); break;
		case IL2CPP_TYPE_U8: AppendString(sigBuf, bufferSize, pos, "u8"); break;
		case IL2CPP_TYPE_I: AppendString(sigBuf, bufferSize, pos, "i"); break;
		case IL2CPP_TYPE_U: AppendString(sigBuf, bufferSize, pos, "u"); break;
		case IL2CPP_TYPE_TYPEDBYREF:
		{
			IL2CPP_ASSERT(sizeof(Il2CppTypedRef) == sizeof(void*) * 3);
			AppendString(sigBuf, bufferSize, pos, "typedbyref");
			break;
		}
		case IL2CPP_TYPE_VALUETYPE:
		{
			const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)type->data.typeHandle;
			if (hybridclr::metadata::IsEnumType(typeDef))
			{
				AppendSignature(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->elementTypeIndex), sigBuf, bufferSize, pos);
				break;
			}
			if (hybridclr::metadata::IsInterpreterType(typeDef))
			{
				AppendSignatureInterpreterValueType(sigBuf, bufferSize, pos);
				break;
			}
			char tempFullName[1024];
			size_t fullNamePos = 0;
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			BuildValueTypeFullName(klass, tempFullName, sizeof(tempFullName) - 1, fullNamePos);
			tempFullName[fullNamePos] = 0;
			AppendString(sigBuf, bufferSize, pos, convertTypeName2SigName ? InterpreterModule::GetValueTypeSignature(tempFullName) : tempFullName);
			break;
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			const Il2CppType* underlyingGenericType = type->data.generic_class->type;
			if (underlyingGenericType->type == IL2CPP_TYPE_CLASS)
			{
				AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
				break;
			}
			const Il2CppTypeDefinition* underlyingTypeDef = (const Il2CppTypeDefinition*)underlyingGenericType->data.typeHandle;
			if (hybridclr::metadata::IsEnumType(underlyingTypeDef))
			{
				AppendSignature(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(underlyingTypeDef->elementTypeIndex), sigBuf, bufferSize, pos);
				break;
			}
			IL2CPP_ASSERT(underlyingGenericType->type == IL2CPP_TYPE_VALUETYPE);
			if (hybridclr::metadata::IsInterpreterType(underlyingTypeDef))
			{
				AppendSignatureInterpreterValueType(sigBuf, bufferSize, pos);
				break;
			}
			
			char tempFullName[1024];
			size_t fullNamePos = 0;
			BuildGenericValueTypeFullName(type, tempFullName, sizeof(tempFullName) - 1, fullNamePos);
			tempFullName[fullNamePos] = 0;
			AppendString(sigBuf, bufferSize, pos, convertTypeName2SigName ? InterpreterModule::GetValueTypeSignature(tempFullName) : tempFullName);
			break;
		}
		case IL2CPP_TYPE_VAR:
		case IL2CPP_TYPE_MVAR:
		{
			AppendString(sigBuf, bufferSize, pos, "!");
			break;
		}
		default: AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos); break;
		}
	}

	bool ComputeSignature(const Il2CppType* ret, const il2cpp::utils::dynamic_array<const Il2CppType*>& params, bool instanceCall, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;
		AppendSignature(ret, sigBuf, bufferSize, pos);

		if (instanceCall)
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
		}

		for (uint32_t i = 0, paramCount = (uint32_t)params.size(); i < paramCount; i++)
		{
			AppendSignature(params[i], sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	bool ComputeSignature(const Il2CppMethodDefinition* method, bool call, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;
		if (method->genericContainerIndex != kGenericContainerIndexInvalid)
		{
			AppendString(sigBuf, bufferSize, pos, "!");
			return true;
		}

		const Il2CppImage* image = hybridclr::metadata::MetadataModule::GetImage(method)->GetIl2CppImage();

		AppendSignature(hybridclr::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(method->returnType), sigBuf, bufferSize, pos);

		if (call && metadata::IsInstanceMethod(method))
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
		}

		for (uint8_t i = 0; i < method->parameterCount; i++)
		{
			TypeIndex paramTypeIndex = hybridclr::metadata::MetadataModule::GetParameterDefinitionFromIndex(image, method->parameterStart + i)->typeIndex;
			AppendSignature(hybridclr::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(paramTypeIndex), sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	inline bool ContainsGenericParameters(const MethodInfo* method)
	{
		IL2CPP_ASSERT(method->is_inflated);
		auto& ctx = method->genericMethod->context;
		if (ctx.class_inst && il2cpp::metadata::GenericMetadata::ContainsGenericParameters(ctx.class_inst))
		{
			return true;
		}
		if (ctx.method_inst && il2cpp::metadata::GenericMetadata::ContainsGenericParameters(ctx.method_inst))
		{
			return true;
		}
		return false;
	}

	bool ComputeSignature(const MethodInfo* method, bool call, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;
		if (method->is_generic || (method->is_inflated && ContainsGenericParameters(method)))
		{
			AppendString(sigBuf, bufferSize, pos, "!");
			return true;
		}

		AppendSignature(method->return_type, sigBuf, bufferSize, pos);

		if (call && metadata::IsInstanceMethod(method))
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
		}

		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			AppendSignature(GET_METHOD_PARAMETER_TYPE(method->parameters[i]), sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

}
}
