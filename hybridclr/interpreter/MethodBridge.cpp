#include "MethodBridge.h"

#include "vm/Object.h"
#include "vm/Class.h"

#include "../metadata/MetadataModule.h"
#include "../metadata/MetadataUtil.h"

#include "Interpreter.h"
#include "InterpreterModule.h"
#include "MemoryUtil.h"
#include "InterpreterUtil.h"

namespace hybridclr
{
namespace interpreter
{
	
	void CopyArgs(StackObject* dstBase, StackObject* argBase, MethodArgDesc* args, uint32_t paramCount)
	{
		uint32_t dstOffset = 0;
		for (uint32_t i = 0, n = paramCount; i < n; i++)
		{
			MethodArgDesc& arg = args[i];
			StackObject* dst = dstBase + dstOffset;
			StackObject* src = argBase + i;
			switch (arg.type)
			{
			case LocationDataType::I1:
			case LocationDataType::U1:
			case LocationDataType::I2:
			case LocationDataType::U2:
			case LocationDataType::U8:
			{
				dst->i64 = *(int64_t*)src;
				++dstOffset;
				break;
			}
			case LocationDataType::SR:
			{
				CopyStackObject(dst, src->ptr, arg.stackObjectSize);
				dstOffset += arg.stackObjectSize;
				break;
			}
			case LocationDataType::S_16:
			{
				// when size > 8, arg is ref to struct
				Copy16(dst, src->ptr);
				dstOffset += 2;
				break;
			}
			case LocationDataType::S_24:
			{
				Copy24(dst, src->ptr);
				dstOffset += 3;
				break;
			}
			case LocationDataType::S_32:
			{
				Copy32(dst, src->ptr);
				dstOffset += 4;
				break;
			}
			case LocationDataType::S_N:
			{
				CopyStackObject(dst, src->ptr, arg.stackObjectSize);
				dstOffset += arg.stackObjectSize;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("CopyArgs not support data type");
			}
			}
		}
	}

	void ConvertInvokeArgs(StackObject* resultArgs, const MethodInfo* method, MethodArgDesc* argDescs, void** args)
	{
		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			StackObject* dst = resultArgs + i;
			if (argDescs[i].passbyValWhenInvoke)
			{
				dst->i64 = *(uint64_t*)args[i];
			}
			else
			{
				dst->ptr = args[i];
			}
		}
	}

	static bool ComputeHFATypeInfo0(Il2CppClass* klass, HFATypeInfo& typeInfo)
	{
		il2cpp::vm::Class::SetupFields(klass);
		for (uint16_t i = 0; i < klass->field_count; i++)
		{
			FieldInfo* field = klass->fields + i;
			const Il2CppType* ftype = field->type;
			if (!metadata::IsInstanceField(ftype))
			{
				continue;
			}
			if (ftype->byref)
			{
				return false;
			}
			if ((ftype->type != IL2CPP_TYPE_R4 && ftype->type != IL2CPP_TYPE_R8))
			{
				if (ftype->type == IL2CPP_TYPE_VALUETYPE || (ftype->type == IL2CPP_TYPE_GENERICINST && ftype->data.generic_class->type->type == IL2CPP_TYPE_VALUETYPE))
				{
					Il2CppClass* fieldKlass = il2cpp::vm::Class::FromIl2CppType(ftype);
					if (!ComputeHFATypeInfo0(fieldKlass, typeInfo))
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else if (typeInfo.eleType == nullptr || metadata::IsTypeEqual(ftype, typeInfo.eleType))
			{
				typeInfo.eleType = ftype;
				++typeInfo.count;
			}
			else
			{
				return false;
			}
		}
		return typeInfo.count <= 4;
	}

	bool ComputeHFATypeInfo(Il2CppClass* klass, HFATypeInfo& typeInfo)
	{
		typeInfo = {};
		int32_t size = metadata::GetTypeValueSize(klass);
		switch (size)
		{
		case 4:
		case 8:
		case 12:
		case 16:
		case 24:
		case 32: break;
		default: return false;
		}
		
		bool isHFA = ComputeHFATypeInfo0(klass, typeInfo);
		if (isHFA && typeInfo.count >= 1 && typeInfo.count <= 4)
		{
			int32_t fieldSize = typeInfo.eleType->type == IL2CPP_TYPE_R4 ? 4 : 8;
			return size == fieldSize * typeInfo.count;
		}
		return false;
	}

	struct SingletonStruct
	{
		const Il2CppType* type;
	};

	static bool ComputSingletonStruct0(Il2CppClass* klass, SingletonStruct& ss)
	{
		il2cpp::vm::Class::SetupFields(klass);
		if (klass->enumtype)
		{
			if (ss.type == nullptr)
			{
				ss.type = &klass->castClass->byval_arg;
				return true;
			}
			else
			{
				return false;
			}
		}
		for (uint16_t i = 0; i < klass->field_count; i++)
		{
			FieldInfo* field = klass->fields + i;
			const Il2CppType* ftype = field->type;
			if (!metadata::IsInstanceField(ftype))
			{
				continue;
			}
			switch (ftype->type)
			{
			case IL2CPP_TYPE_TYPEDBYREF: return false;
			case IL2CPP_TYPE_VALUETYPE:
			{
				if (!ComputSingletonStruct0(il2cpp::vm::Class::FromIl2CppType(ftype), ss))
				{
					return false;
				}
				break;
			}
			case IL2CPP_TYPE_GENERICINST:
			{
				Il2CppClass* fieldKlass = il2cpp::vm::Class::FromIl2CppType(ftype);
				if (IS_CLASS_VALUE_TYPE(fieldKlass))
				{
					if (!ComputSingletonStruct0(fieldKlass, ss))
					{
						return false;
					}
					break;
				}
				// else fallback
			}
			default:
			{
				if (ss.type == nullptr)
				{
					ss.type = ftype;
				}
				else
				{
					return false;
				}
			}
			}
		}
		return true;
	}

	static bool TryComputSingletonStruct(Il2CppClass* klass, int32_t typeAligment, int32_t typeSize, Il2CppTypeEnum& wasmType)
	{
		if (typeAligment > 8 || typeSize > 8)
		{
			return false;
		}
		SingletonStruct ss = {};
		if (ComputSingletonStruct0(klass, ss) && ss.type)
		{
			if (ss.type->byref)
			{
				wasmType = IL2CPP_TYPE_I4;
				return true;
			}
			switch (ss.type->type)
			{
			case IL2CPP_TYPE_BOOLEAN:
			case IL2CPP_TYPE_CHAR:
			case IL2CPP_TYPE_I1:
			case IL2CPP_TYPE_U1:
			case IL2CPP_TYPE_I2:
			case IL2CPP_TYPE_U2:
			case IL2CPP_TYPE_I4:
			case IL2CPP_TYPE_U4:
			case IL2CPP_TYPE_I:
			case IL2CPP_TYPE_U:
			case IL2CPP_TYPE_STRING:
			case IL2CPP_TYPE_PTR:
			case IL2CPP_TYPE_CLASS:
			case IL2CPP_TYPE_ARRAY:
			case IL2CPP_TYPE_GENERICINST:
			case IL2CPP_TYPE_FNPTR:
			case IL2CPP_TYPE_OBJECT:
			case IL2CPP_TYPE_SZARRAY:
			{
				if (typeAligment <= 4 && typeSize <= 4)
				{
					wasmType = IL2CPP_TYPE_I4;
					return true;
				}
				break;
			}
			case IL2CPP_TYPE_I8:
			case IL2CPP_TYPE_U8:
			{
				if (typeAligment <= 8 && typeSize <= 8)
				{
					wasmType = IL2CPP_TYPE_I8;
					return true;
				}
				break;
			}
			case IL2CPP_TYPE_R4:
			{
				if (typeAligment <= 4 && typeSize <= 4)
				{
					wasmType = IL2CPP_TYPE_R4;
					return true;
				}
				break;
			}
			case IL2CPP_TYPE_R8:
			{
				if (typeAligment <= 8 && typeSize <= 8)
				{
					wasmType = IL2CPP_TYPE_R8;
					return true;
				}
				break;
			}
			default:
				break;
			}
		}
		return false;
	}

	static bool IsWebGLSpecialValueType(Il2CppClass* klass)
	{
		if (klass->enumtype)
		{
			return false;
		}
		if (klass->field_count == 0)
		{
			return true;
		}
		il2cpp::vm::Class::SetupFields(klass);
		int32_t instanceFieldCount = 0;
		for (uint16_t i = 0; i < klass->field_count; i++)
		{
			FieldInfo* field = klass->fields + i;
			const Il2CppType* ftype = field->type;
			instanceFieldCount += metadata::IsInstanceField(ftype);
		}
		return (instanceFieldCount == 0 || ((klass->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT) && instanceFieldCount > 1));
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

	static void AppendSignatureObjOrRefOrPointer(char* sigBuf, size_t bufSize, size_t& pos)
	{
#if HYBRIDCLR_ARCH_64
		const char* str = "i8";
#else
		const char* str = "i4";
#endif
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

	static void AppendValueTypeSignatureByAligmentAndSize(int32_t typeSize, uint8_t aligment, bool returnValue, char* sigBuf, size_t bufferSize, size_t& pos)
	{
#if HYBRIDCLR_ABI_UNIVERSAL_32 || HYBRIDCLR_ABI_UNIVERSAL_64 || HYBRIDCLR_ABI_WEBGL32
		switch (aligment)
		{
		case 0:
		case 1:
		{
			pos += std::sprintf(sigBuf + pos, "S%d", typeSize);
			break;
		}
		case 2:
		{
			pos += std::sprintf(sigBuf + pos, "A%d", typeSize);
			break;
		}
		case 4:
		{
			pos += std::sprintf(sigBuf + pos, "B%d", typeSize);
			break;
		}
		case 8:
		{
			pos += std::sprintf(sigBuf + pos, "C%d", typeSize);
			break;
		}
		default:
		{
			TEMP_FORMAT(errMsg, "not support aligment:%d size:%d", aligment, typeSize);
			RaiseExecutionEngineException(errMsg);
		}
		}
#elif HYBRIDCLR_ABI_ARM_64
		if (typeSize <= 8)
		{
			AppendString(sigBuf, bufferSize, pos, "i8");
		}
		else if (typeSize <= 16)
		{
			AppendString(sigBuf, bufferSize, pos, "i16");
		}
		else if (!returnValue)
		{
			AppendString(sigBuf, bufferSize, pos, "sr");
		}
		else
		{
			pos += std::sprintf(sigBuf + pos, "S%d", typeSize);
		}
#else
#error "not support ABI"
#endif
	}

	static void AppendEmptyValueTypeSignatureByAligmentAndSize(int32_t typeSize, uint8_t aligment, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		switch (aligment)
		{
		case 0:
		case 1:
		{
			pos += std::sprintf(sigBuf + pos, "X%d", typeSize);
			break;
		}
		case 2:
		{
			pos += std::sprintf(sigBuf + pos, "Y%d", typeSize);
			break;
		}
		case 4:
		{
			pos += std::sprintf(sigBuf + pos, "Z%d", typeSize);
			break;
		}
		case 8:
		{
			pos += std::sprintf(sigBuf + pos, "W%d", typeSize);
			break;
		}
		default:
		{
			TEMP_FORMAT(errMsg, "not support aligment:%d size:%d", aligment, typeSize);
			RaiseExecutionEngineException(errMsg);
		}
		}
	}

	static void AppendSignature(const Il2CppType* type, bool returnType, char* sigBuf, size_t bufferSize, size_t& pos);

	static void AppendValueTypeSignature(Il2CppClass* klass, bool returnType, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		int32_t typeSize = il2cpp::vm::Class::GetValueSize(klass, nullptr);
#if HYBRIDCLR_ABI_ARM_64
		HFATypeInfo typeInfo = {};
		if (ComputeHFATypeInfo(klass, typeInfo))
		{
			if (typeInfo.eleType->type == IL2CPP_TYPE_R4)
			{
				switch (typeInfo.count)
				{
				case 1:
				{
					AppendString(sigBuf, bufferSize, pos, "r4");
					return;
				}
				case 2:
				{
					AppendString(sigBuf, bufferSize, pos, "vf2");
					return;
				}
				case 3:
				{
					AppendString(sigBuf, bufferSize, pos, "vf3");
					return;
				}
				case 4:
				{
					AppendString(sigBuf, bufferSize, pos, "vf4");
					return;
				}
				}
			}
			else
			{
				IL2CPP_ASSERT(typeInfo.eleType->type == IL2CPP_TYPE_R8);
				switch (typeInfo.count)
				{
				case 1:
				{
					AppendString(sigBuf, bufferSize, pos, "r8");
					return;
				}
				case 2:
				{
					AppendString(sigBuf, bufferSize, pos, "vd2");
					return;
				}
				case 3:
				{
					AppendString(sigBuf, bufferSize, pos, "vd3");
					return;
				}
				case 4:
				{
					AppendString(sigBuf, bufferSize, pos, "vd4");
					return;
				}
				}
			}
		}
		// FIXME HSV
		uint8_t actualAligment = 1;
		AppendValueTypeSignatureByAligmentAndSize(typeSize, actualAligment, returnType, sigBuf, bufferSize, pos);
#elif HYBRIDCLR_ABI_UNIVERSAL_64
		uint8_t actualAligment = 1;
		AppendValueTypeSignatureByAligmentAndSize(typeSize, actualAligment, returnType, sigBuf, bufferSize, pos);
#elif HYBRIDCLR_ABI_UNIVERSAL_32
		uint8_t actualAligment = klass->minimumAlignment <= 4 ? 1 : 8;
		AppendValueTypeSignatureByAligmentAndSize(typeSize, actualAligment, returnType, sigBuf, bufferSize, pos);
#elif HYBRIDCLR_ABI_WEBGL32
		uint8_t actualAligment = klass->minimumAlignment;
		if (IsWebGLSpecialValueType(klass))
		{
			AppendEmptyValueTypeSignatureByAligmentAndSize(typeSize, actualAligment, sigBuf, bufferSize, pos);
			return;
		}
		Il2CppTypeEnum wasmType;
		if (TryComputSingletonStruct(klass, actualAligment, typeSize, wasmType))
		{
			Il2CppType tempType = {};
			tempType.type = wasmType;
			AppendSignature(&tempType, returnType, sigBuf, bufferSize, pos);
		}
		else
		{
			AppendValueTypeSignatureByAligmentAndSize(typeSize, actualAligment, returnType, sigBuf, bufferSize, pos);
		}
#else
#error "not support platform"
#endif
	}

	static bool IsGenericFullInstantiate(const Il2CppType* type)
	{
		switch (type->type)
		{
		case IL2CPP_TYPE_VAR:
		case IL2CPP_TYPE_MVAR: return false;
		case IL2CPP_TYPE_GENERICINST:
		{
			Il2CppGenericContext& gctx = type->data.generic_class->context;
			const Il2CppGenericInst* gis[] = { gctx.class_inst, gctx.method_inst };

			for (const Il2CppGenericInst* gi : gis)
			{
				if (!gi)
				{
					continue;
				}
				for (uint8_t i = 0; i < gi->type_argc; i++)
				{
					const Il2CppType* gtype = gi->type_argv[i];
					if (!IsGenericFullInstantiate(gtype))
					{
						return false;
					}
				}
			}
			return true;
		}
		default: return true;

		}
	}

	static void AppendSignature(const Il2CppType* type, bool returnType, char* sigBuf, size_t bufferSize, size_t& pos)
	{
		if (type->byref)
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
			return;
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_VOID: AppendString(sigBuf, bufferSize, pos, "v"); break;
#if HYBRIDCLR_ABI_ARM_64 || HYBRIDCLR_ABI_UNIVERSAL_64 || HYBRIDCLR_ABI_UNIVERSAL_32 || HYBRIDCLR_ABI_WEBGL32
		case IL2CPP_TYPE_BOOLEAN: AppendString(sigBuf, bufferSize, pos, "u1"); break;
		case IL2CPP_TYPE_I1: AppendString(sigBuf, bufferSize, pos, "i1"); break;
		case IL2CPP_TYPE_U1: AppendString(sigBuf, bufferSize, pos, "u1"); break;
		case IL2CPP_TYPE_I2: AppendString(sigBuf, bufferSize, pos, "i2"); break;
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_CHAR: AppendString(sigBuf, bufferSize, pos, "u2"); break;
		case IL2CPP_TYPE_I4: AppendString(sigBuf, bufferSize, pos, "i4"); break;
		case IL2CPP_TYPE_U4: AppendString(sigBuf, bufferSize, pos, "u4"); break;
		case IL2CPP_TYPE_R4: AppendString(sigBuf, bufferSize, pos, "r4"); break;
#else
#error "not suppport platform"
#endif
		case IL2CPP_TYPE_R8: AppendString(sigBuf, bufferSize, pos, "r8"); break;
		case IL2CPP_TYPE_I8: AppendString(sigBuf, bufferSize, pos, "i8"); break;
		case IL2CPP_TYPE_U8: AppendString(sigBuf, bufferSize, pos, "u8"); break;
		case IL2CPP_TYPE_TYPEDBYREF:
		{
			IL2CPP_ASSERT(sizeof(Il2CppTypedRef) == sizeof(void*) * 3);
			AppendValueTypeSignatureByAligmentAndSize(sizeof(Il2CppTypedRef), PTR_SIZE, returnType, sigBuf, bufferSize, pos);
			break;
		}
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
			if (klass->enumtype)
			{
				AppendSignature(&klass->castClass->byval_arg, returnType, sigBuf, bufferSize, pos);
			}
			else
			{
				AppendValueTypeSignature(klass, returnType, sigBuf, bufferSize, pos);
			}
			break;
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			const Il2CppType* underlyingGenericType = type->data.generic_class->type;
			if (underlyingGenericType->type == IL2CPP_TYPE_CLASS)
			{
				AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
			}
			else
			{
				IL2CPP_ASSERT(underlyingGenericType->type == IL2CPP_TYPE_VALUETYPE);
				if (!IsGenericFullInstantiate(type))
				{
					AppendString(sigBuf, bufferSize, pos, "#not_full_generic#");
					return;
				}
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
				if (klass->enumtype)
				{
					AppendSignature(&klass->castClass->byval_arg, returnType, sigBuf, bufferSize, pos);
				}
				else
				{
					AppendValueTypeSignature(klass, returnType, sigBuf, bufferSize, pos);
				}
			}
			break;
		}
		default: AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos); break;
		}
	}

	bool ComputeSignature(const Il2CppType* ret, const Il2CppType* params, uint32_t paramCount, bool instanceCall, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;
		AppendSignature(ret, true, sigBuf, bufferSize, pos);

		if (instanceCall)
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
		}

		for (uint8_t i = 0; i < paramCount; i++)
		{
			AppendSignature(params + i, false, sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	bool ComputeSignature(const Il2CppMethodDefinition* method, bool call, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;

		const Il2CppImage* image = hybridclr::metadata::MetadataModule::GetImage(method)->GetIl2CppImage();

		AppendSignature(hybridclr::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(method->returnType), true, sigBuf, bufferSize, pos);

		if (call && metadata::IsInstanceMethod(method))
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
		}

		for (uint8_t i = 0; i < method->parameterCount; i++)
		{
			TypeIndex paramTypeIndex = hybridclr::metadata::MetadataModule::GetParameterDefinitionFromIndex(image, method->parameterStart + i)->typeIndex;
			AppendSignature(hybridclr::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(paramTypeIndex), false, sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

	bool ComputeSignature(const MethodInfo* method, bool call, char* sigBuf, size_t bufferSize)
	{
		size_t pos = 0;

		AppendSignature(method->return_type, true, sigBuf, bufferSize, pos);

		if (call && metadata::IsInstanceMethod(method))
		{
			AppendSignatureObjOrRefOrPointer(sigBuf, bufferSize, pos);
		}

		for (uint8_t i = 0; i < method->parameters_count; i++)
		{
			AppendSignature(GET_METHOD_PARAMETER_TYPE(method->parameters[i]), false, sigBuf, bufferSize, pos);
		}
		sigBuf[pos] = 0;
		return true;
	}

}
}
