
#include "../metadata/MetadataUtil.h"

#include "MemoryUtil.h"


namespace huatuo
{
namespace interpreter
{
	ArgDesc GetValueTypeArgDescBySize(uint32_t size)
	{
		switch (size)
		{
		case 1:
		case 2:
		case 4:
		case 8: return { LocationDataType::U8, 1 };
		case 12: return { LocationDataType::S_12, 2 };
		case 16: return { LocationDataType::S_16, 2 };
		case 20: return { LocationDataType::S_20, 3 };
		case 24: return { LocationDataType::S_24, 3 };
		case 28: return { LocationDataType::S_28, 4 };
		case 32: return { LocationDataType::S_32, 4 };
		default: return { LocationDataType::S_N, (uint32_t)metadata::GetStackSizeByByteSize(size) };
		}
	}

	ArgDesc GetTypeArgDesc(const Il2CppType* type)
	{
		if (type->byref)
		{
			return { LocationDataType::U8, 1 };
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_U1:
			return{ LocationDataType::U1, 1 };
		case IL2CPP_TYPE_I1:
			return{ LocationDataType::I1, 1 };
		case IL2CPP_TYPE_I2:
			return{ LocationDataType::I2, 1 };
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_U2:
			return{ LocationDataType::U2, 1 };
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
		case IL2CPP_TYPE_R4:
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R8:
		case IL2CPP_TYPE_I:
		case IL2CPP_TYPE_U:
		case IL2CPP_TYPE_FNPTR:
		case IL2CPP_TYPE_PTR:
		case IL2CPP_TYPE_BYREF:
		case IL2CPP_TYPE_STRING:
		case IL2CPP_TYPE_ARRAY:
		case IL2CPP_TYPE_SZARRAY:
		case IL2CPP_TYPE_OBJECT:
		case IL2CPP_TYPE_CLASS:
			return{ LocationDataType::U8, 1 };
		case IL2CPP_TYPE_TYPEDBYREF:
			return GetValueTypeArgDescBySize(sizeof(Il2CppTypedRef));
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
			if (klass->enumtype)
			{
				return GetTypeArgDesc(&klass->castClass->byval_arg);
			}
			return GetValueTypeArgDescBySize(il2cpp::vm::Class::GetValueSize(klass, nullptr));
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			Il2CppGenericClass* genericClass = type->data.generic_class;
			if (genericClass->type->type == IL2CPP_TYPE_CLASS)
			{
				IL2CPP_ASSERT(!IS_CLASS_VALUE_TYPE(il2cpp::vm::Class::FromIl2CppType(type)));
				return{ LocationDataType::U8, 1 };
			}
			else
			{
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
				return GetValueTypeArgDescBySize(il2cpp::vm::Class::GetValueSize(klass, nullptr));
			}
		}
		default:
		{
			RaiseHuatuoExecutionEngineException("not support arg type");
			return{ LocationDataType::U8, 1 };
		}
		}
	}

	void CopyArgs(StackObject* dstBase, StackObject* argBase, ArgDesc* args, uint32_t paramCount, uint32_t totalParamStackObjectSize)
	{
		uint32_t argOffset = 0;
		for (uint32_t i = 0, n = paramCount; i < n; i++)
		{
			ArgDesc& arg = args[i];
			StackObject* dst = dstBase + argOffset;
			StackObject* src = argBase + i;
			switch (arg.type)
			{
			case LocationDataType::I1:
			{
				dst->i64 = *(int8_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::U1:
			{
				dst->i64 = *(uint8_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::I2:
			{
				dst->i64 = *(int16_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::U2:
			{
				dst->i64 = *(uint16_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::U8:
			{
				dst->i64 = *(int64_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::S_12:
			{
				// when size > 8, arg is ref to struct
				Copy12(dst, src->ptr);
				argOffset += 2;
				break;
			}
			case LocationDataType::S_16:
			{
				// when size > 8, arg is ref to struct
				Copy16(dst, src->ptr);
				argOffset += 2;
				break;
			}
			case LocationDataType::S_20:
			{
				Copy20(dst, src->ptr);
				argOffset += 3;
				break;
			}
			case LocationDataType::S_24:
			{
				Copy24(dst, src->ptr);
				argOffset += 3;
				break;
			}
			case LocationDataType::S_28:
			{
				Copy28(dst, src->ptr);
				argOffset += 4;
				break;
			}
			case LocationDataType::S_32:
			{
				Copy32(dst, src->ptr);
				argOffset += 4;
				break;
			}
			default:
			{
				std::memcpy(dst, src->ptr, arg.stackObjectSize * sizeof(StackObject));
				argOffset += arg.stackObjectSize;
				break;
			}
			}
		}
		IL2CPP_ASSERT(argOffset == totalParamStackObjectSize);
	}

}
}