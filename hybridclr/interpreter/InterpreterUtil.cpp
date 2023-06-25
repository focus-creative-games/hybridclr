#include "InterpreterUtil.h"

#include "vm/Object.h"

#include "../metadata/MetadataUtil.h"

namespace hybridclr
{
namespace interpreter
{
	TypeDesc GetValueTypeArgDescBySize(uint32_t size)
	{
#if HYBRIDCLR_ABI_ARM_64
		if (size <= 8)
		{
			return { LocationDataType::U8, 1 };
		}
		else if (size <= 16)
		{
			return { LocationDataType::S_16, 2 };
		}
		else
		{
			return { LocationDataType::SR, (uint32_t)metadata::GetStackSizeByByteSize(size) };
		}
#elif HYBRIDCLR_ABI_UNIVERSAL_64 || HYBRIDCLR_ABI_UNIVERSAL_32 || HYBRIDCLR_ABI_WEBGL32
		if (size <= 8)
		{
			return { LocationDataType::U8, 1 };
		}
		else if (size <= 16)
		{
			return { LocationDataType::S_16, 2 };
		}
		else if (size <= 24)
		{
			return { LocationDataType::S_24, 3 };
		}
		else if (size <= 32)
		{
			return { LocationDataType::S_32, 4 };
		}
		else
		{
			return { LocationDataType::S_N, (uint32_t)metadata::GetStackSizeByByteSize(size) };
		}
#else
#error "not support ABI"
#endif
	}

	TypeDesc GetTypeArgDesc(const Il2CppType* type)
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
				if (klass->enumtype)
				{
					return GetTypeArgDesc(&klass->castClass->byval_arg);
				}
				return GetValueTypeArgDescBySize(il2cpp::vm::Class::GetValueSize(klass, nullptr));
			}
		}
		default:
		{
			RaiseExecutionEngineException("not support arg type");
			return{ LocationDataType::U8, 1 };
		}
		}
	}

	bool IsPassByValWhenInvoke(const Il2CppType* type, bool passByValWhenCall)
	{
		if (type->byref)
		{
			return false;
		}
		if (hybridclr::metadata::IsValueType(type))
		{
			return passByValWhenCall;
		}
		return false;
	}

	Il2CppObject* TranslateNativeValueToBoxValue(const Il2CppType* type, void* value)
	{
		if (type->byref)
		{
			RaiseExecutionEngineException("TranslateNativeValueToBoxValue can't box ref");
			return nullptr;
		}
		Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
		return il2cpp::vm::Object::Box(klass, value);
	}
}
}