#include "TransformContext.h"

#include "../interpreter/MethodBridge.h"

namespace hybridclr
{
namespace transform
{
	enum class ArgCommonType
	{
		VOID,
		I1,
		U1,
		I2,
		U2,
		I4,
		I8,
		R4,
		R8,
		I,
		U,
		STRUCT,
		NOT_SUPPORT,
	};

#if HYBRIDCLR_ARCH_64
#define NATIVE_INT_COMMON_TYPE ArgCommonType::I8
#else
#define NATIVE_INT_COMMON_TYPE ArgCommonType::I4
#endif


	static ArgCommonType ComputValueTypeArgCommonType(const Il2CppClass* klass)
	{
		return ArgCommonType::STRUCT;
	}


	static ArgCommonType ComputArgCommonType(const Il2CppType* type)
	{
		if (type->byref)
		{
			return NATIVE_INT_COMMON_TYPE;
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_VOID:
			return ArgCommonType::VOID;
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_U1:
			return ArgCommonType::U1;
		case IL2CPP_TYPE_I1:
			return ArgCommonType::I1;
		case IL2CPP_TYPE_I2:
			return ArgCommonType::I2;
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_U2:
			return ArgCommonType::U2;
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
			return ArgCommonType::I4;
		case IL2CPP_TYPE_R4:
			return ArgCommonType::R4;
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
			return ArgCommonType::I8;
		case IL2CPP_TYPE_R8:
			return ArgCommonType::R8;
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
			return NATIVE_INT_COMMON_TYPE;
		case IL2CPP_TYPE_TYPEDBYREF:
			return ArgCommonType::NOT_SUPPORT;
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
			if (klass->enumtype)
			{
				return ComputArgCommonType(&klass->castClass->byval_arg);
			}
			return ComputValueTypeArgCommonType(klass);
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			Il2CppGenericClass* genericClass = type->data.generic_class;
			if (genericClass->type->type == IL2CPP_TYPE_CLASS)
			{
				IL2CPP_ASSERT(!IS_CLASS_VALUE_TYPE(il2cpp::vm::Class::FromIl2CppType(type)));
				return NATIVE_INT_COMMON_TYPE;
			}
			else
			{
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
				if (klass->enumtype)
				{
					return ComputArgCommonType(&klass->castClass->byval_arg);
				}
				return ComputValueTypeArgCommonType(klass);
			}
		}
		default:
		{
			RaiseExecutionEngineException("not support arg type");
			return ArgCommonType::NOT_SUPPORT;
		}
		}
	}

	ArgCommonType ComputMethodArgHomoType(const MethodInfo* method)
	{
		ArgCommonType homoType = ComputArgCommonType(GET_METHOD_PARAMETER_TYPE(method->parameters[0]));
		if (homoType == ArgCommonType::NOT_SUPPORT)
		{
			return homoType;
		}
		for (uint8_t i = 1; i < method->parameters_count; i++)
		{
			ArgCommonType pt = ComputArgCommonType(GET_METHOD_PARAMETER_TYPE(method->parameters[i]));
			if (pt != homoType)
			{
				return ArgCommonType::NOT_SUPPORT;
			}
		}
		return homoType;
	}

	constexpr int MAX_COMMON_PARAM_NUM = 4;

	bool TransformContext::TryAddCallCommonInstanceInstruments(const MethodInfo* method, uint32_t methodDataIndex)
	{
		const Il2CppType* returnType = method->return_type;
		int32_t paramCount = shareMethod->parameters_count;
		int32_t resolvedTotalArgdNum = paramCount + 1;
		int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgdNum;
		uint16_t argBaseOffset = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);

		ArgCommonType actRet = ComputArgCommonType(returnType);
		if (actRet == ArgCommonType::NOT_SUPPORT || actRet == ArgCommonType::STRUCT)
		{
			return false;
		}
		if (paramCount == 0)
		{
			// (void,u1,i1,i2,u2,i4, i8, f4, f8, v2, v3, v4} func(object x);
			if (actRet == ArgCommonType::VOID)
			{
				CreateAddIR(ir, CallCommonNativeInstance_v_0);
				ir->method = methodDataIndex;
				ir->self = argBaseOffset;
				return true;
			}

			CreateAddIR(ir, CallCommonNativeInstance_i1_0);
			ir->method = methodDataIndex;
			ir->self = argBaseOffset;
			ir->ret = argBaseOffset;
			switch (actRet)
			{
			case ArgCommonType::I1:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_i1_0;
				break;
			}
			case ArgCommonType::U1:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_u1_0;
				break;
			}
			case ArgCommonType::I2:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_i2_0;
				break;
			}
			case ArgCommonType::U2:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_u2_0;
				break;
			}
			case ArgCommonType::I4:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_i4_0;
				break;
			}
			case ArgCommonType::I8:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_i8_0;
				break;
			}
			case ArgCommonType::R4:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_f4_0;
				break;
			}
			case ArgCommonType::R8:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeInstance_f8_0;
				break;
			}
			default:
				RaiseExecutionEngineException("TryAddCallCommonInstanceInstruments. unknown ArgCommonType ");
				break;
			}

			return true;
		}

		if (paramCount > MAX_COMMON_PARAM_NUM)
		{
			return false;
		}

		ArgCommonType actParam = ComputMethodArgHomoType(method);
		if (actParam == ArgCommonType::NOT_SUPPORT)
		{
			return false;
		}

#define SWITCH_INSTANCE_VOID(argType, argNum) \
switch (argNum) \
{\
case 1:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_v_##argType##_1);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	return true;\
}\
case 2:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_v_##argType##_2);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
	return true;\
}\
case 3:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_v_##argType##_3);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
	ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 3);\
	return true;\
}\
case 4:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_v_##argType##_4);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
	ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 3);\
	ir->param3 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 4);\
	return true;\
}\
default: return false;\
}

		// (void, u1, i4, i8, f4, f8} func(object this, T x1, ,, T xN); T={i4,i8,f4,f8}, N =[1,4]
		if (actRet == ArgCommonType::VOID)
		{
			switch (actParam)
			{
			case hybridclr::transform::ArgCommonType::I4:
			{
				SWITCH_INSTANCE_VOID(i4, paramCount);
				break;
			}
			case hybridclr::transform::ArgCommonType::I8:
			{
				SWITCH_INSTANCE_VOID(i8, paramCount);
				break;
			}
			case hybridclr::transform::ArgCommonType::R4:
			{
				SWITCH_INSTANCE_VOID(f4, paramCount);
				break;
			}
			case hybridclr::transform::ArgCommonType::R8:
			{
				SWITCH_INSTANCE_VOID(f8, paramCount);
				break;
			}
			default:
				return false;
			}
		}

#define SWITCH_INSTANCE_RET(retType, argType, argNum) \
switch (argNum) \
{\
case 1:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_##retType##_##argType##_1);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->ret = argBaseOffset;\
	return true;\
}\
case 2:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_##retType##_##argType##_2);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
	ir->ret = argBaseOffset;\
	return true;\
}\
case 3:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_##retType##_##argType##_3);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
	ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 3);\
	ir->ret = argBaseOffset;\
	return true;\
}\
case 4:\
{\
	CreateAddIR(ir, CallCommonNativeInstance_##retType##_##argType##_4);\
	ir->method = methodDataIndex;\
	ir->self = argBaseOffset;\
	ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
	ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
	ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 3);\
	ir->param3 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 4);\
	ir->ret = argBaseOffset;\
	return true;\
}\
default: return false;\
}

#define SWTCH_INSTANCE_RET2(retType) \
switch (actParam)\
{\
case hybridclr::transform::ArgCommonType::I4:\
{\
	SWITCH_INSTANCE_RET(retType, i4, paramCount);\
	break;\
}\
case hybridclr::transform::ArgCommonType::I8:\
{\
	SWITCH_INSTANCE_RET(retType, i8, paramCount);\
	break;\
}\
case hybridclr::transform::ArgCommonType::R4:\
{\
	SWITCH_INSTANCE_RET(retType, f4, paramCount);\
	break;\
}\
case hybridclr::transform::ArgCommonType::R8:\
{\
	SWITCH_INSTANCE_RET(retType, f8, paramCount);\
	break;\
}\
default:\
	return false;\
}

		switch (actRet)
		{
		case ArgCommonType::U1:
		{
			SWTCH_INSTANCE_RET2(u1);
			break;
		}
		case ArgCommonType::I4:
		{
			SWTCH_INSTANCE_RET2(i4);
			break;
		}
		case ArgCommonType::I8:
		{
			SWTCH_INSTANCE_RET2(i8);
			break;
		}
		case ArgCommonType::R4:
		{
			SWTCH_INSTANCE_RET2(f4);
			break;
		}
		case ArgCommonType::R8:
		{
			SWTCH_INSTANCE_RET2(f8);
			break;
		}
		}

		return false;
	}

	bool TransformContext::TryAddCallCommonStaticInstruments(const MethodInfo* method, uint32_t methodDataIndex)
	{
		const Il2CppType* returnType = method->return_type;
		int32_t paramCount = shareMethod->parameters_count;
		int32_t resolvedTotalArgdNum = paramCount;
		int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgdNum;
		uint16_t argBaseOffset = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);

		ArgCommonType actRet = ComputArgCommonType(returnType);
		if (actRet == ArgCommonType::NOT_SUPPORT || actRet == ArgCommonType::STRUCT)
		{
			return false;
		}
		if (paramCount == 0)
		{
			// (void,u1,i1,i2,u2,i4, i8, f4, f8, v2, v3, v4} func();
			if (actRet == ArgCommonType::VOID)
			{
				CreateAddIR(ir, CallCommonNativeStatic_v_0);
				ir->method = methodDataIndex;
				return true;
			}

			CreateAddIR(ir, CallCommonNativeStatic_i1_0);
			ir->method = methodDataIndex;
			ir->ret = argBaseOffset;
			switch (actRet)
			{
			case ArgCommonType::I1:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_i1_0;
				break;
			}
			case ArgCommonType::U1:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_u1_0;
				break;
			}
			case ArgCommonType::I2:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_i2_0;
				break;
			}
			case ArgCommonType::U2:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_u2_0;
				break;
			}
			case ArgCommonType::I4:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_i4_0;
				break;
			}
			case ArgCommonType::I8:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_i8_0;
				break;
			}
			case ArgCommonType::R4:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_f4_0;
				break;
			}
			case ArgCommonType::R8:
			{
				ir->type = HiOpcodeEnum::CallCommonNativeStatic_f8_0;
				break;
			}
			default:
				RaiseExecutionEngineException("TryAddCallCommonStaticInstruments. unknown ArgCommonType ");
				break;
			}

			return true;
		}

		if (paramCount > MAX_COMMON_PARAM_NUM)
		{
			return false;
		}

		ArgCommonType actParam = ComputMethodArgHomoType(method);
		if (actParam == ArgCommonType::NOT_SUPPORT)
		{
			return false;
		}

#define SWITCH_STATIC_VOID(argType, argNum) \
	switch (argNum) \
	{\
	case 1:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_v_##argType##_1);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		return true;\
	}\
	case 2:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_v_##argType##_2);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
		return true;\
	}\
	case 3:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_v_##argType##_3);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
		ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
		return true;\
	}\
	case 4:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_v_##argType##_4);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
		ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
		ir->param3 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 3);\
		return true;\
	}\
	default: return false;\
	}

		// (void, u1, i4, i8, f4, f8} func(object this, T x1, ,, T xN); T={i4,i8,f4,f8}, N =[1,4]
		if (actRet == ArgCommonType::VOID)
		{
			switch (actParam)
			{
			case hybridclr::transform::ArgCommonType::I4:
			{
				SWITCH_STATIC_VOID(i4, paramCount);
				break;
			}
			case hybridclr::transform::ArgCommonType::I8:
			{
				SWITCH_STATIC_VOID(i8, paramCount);
				break;
			}
			case hybridclr::transform::ArgCommonType::R4:
			{
				SWITCH_STATIC_VOID(f4, paramCount);
				break;
			}
			case hybridclr::transform::ArgCommonType::R8:
			{
				SWITCH_STATIC_VOID(f8, paramCount);
				break;
			}
			default:
				return false;
			}
		}

#define SWITCH_STATIC_RET(retType, argType, argNum) \
	switch (argNum) \
	{\
	case 1:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_##retType##_##argType##_1);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->ret = argBaseOffset;\
		return true;\
	}\
	case 2:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_##retType##_##argType##_2);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
		ir->ret = argBaseOffset;\
		return true;\
	}\
	case 3:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_##retType##_##argType##_3);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
		ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
		ir->ret = argBaseOffset;\
		return true;\
	}\
	case 4:\
	{\
		CreateAddIR(ir, CallCommonNativeStatic_##retType##_##argType##_4);\
		ir->method = methodDataIndex;\
		ir->param0 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);\
		ir->param1 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 1);\
		ir->param2 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 2);\
		ir->param3 = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase + 3);\
		ir->ret = argBaseOffset;\
		return true;\
	}\
	default: return false;\
	}

#define SWTCH_STATIC_RET2(retType) \
	switch (actParam)\
	{\
	case hybridclr::transform::ArgCommonType::I4:\
	{\
		SWITCH_STATIC_RET(retType, i4, paramCount);\
		break;\
	}\
	case hybridclr::transform::ArgCommonType::I8:\
	{\
		SWITCH_STATIC_RET(retType, i8, paramCount);\
		break;\
	}\
	case hybridclr::transform::ArgCommonType::R4:\
	{\
		SWITCH_STATIC_RET(retType, f4, paramCount);\
		break;\
	}\
	case hybridclr::transform::ArgCommonType::R8:\
	{\
		SWITCH_STATIC_RET(retType, f8, paramCount);\
		break;\
	}\
	default:\
		return false;\
	}

		switch (actRet)
		{
		case ArgCommonType::U1:
		{
			SWTCH_STATIC_RET2(u1);
			break;
		}
		case ArgCommonType::I4:
		{
			SWTCH_STATIC_RET2(i4);
			break;
		}
		case ArgCommonType::I8:
		{
			SWTCH_STATIC_RET2(i8);
			break;
		}
		case ArgCommonType::R4:
		{
			SWTCH_STATIC_RET2(f4);
			break;
		}
		case ArgCommonType::R8:
		{
			SWTCH_STATIC_RET2(f8);
			break;
		}
		}
		return false;
	}
}
}