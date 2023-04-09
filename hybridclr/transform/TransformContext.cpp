#include "TransformContext.h"

namespace hybridclr
{
namespace transform
{
	EvalStackReduceDataType GetEvalStackReduceDataType(const Il2CppType* type)
	{
		if (type->byref)
		{
			return NATIVE_INT_REDUCE_TYPE;
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
			return EvalStackReduceDataType::I4;
		case IL2CPP_TYPE_R4:
			return EvalStackReduceDataType::R4;

		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
			return EvalStackReduceDataType::I8;
		case IL2CPP_TYPE_R8:
			return EvalStackReduceDataType::R8;
		case IL2CPP_TYPE_I:
		case IL2CPP_TYPE_U:
		case IL2CPP_TYPE_FNPTR:
		case IL2CPP_TYPE_PTR:
		case IL2CPP_TYPE_BYREF:
		case IL2CPP_TYPE_STRING:
		case IL2CPP_TYPE_CLASS:
		case IL2CPP_TYPE_ARRAY:
		case IL2CPP_TYPE_SZARRAY:
		case IL2CPP_TYPE_OBJECT:
			return NATIVE_INT_REDUCE_TYPE;
		case IL2CPP_TYPE_TYPEDBYREF:
			return EvalStackReduceDataType::Other;
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			return klass->enumtype ? GetEvalStackReduceDataType(&klass->element_class->byval_arg) : EvalStackReduceDataType::Other;
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			Il2CppGenericClass* genericClass = type->data.generic_class;
			if (genericClass->type->type == IL2CPP_TYPE_CLASS)
			{
				return NATIVE_INT_REDUCE_TYPE;
			}
			else
			{
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				return klass->enumtype ? GetEvalStackReduceDataType(&klass->element_class->byval_arg) : EvalStackReduceDataType::Other;
			}
		}
		default:
		{
			RaiseExecutionEngineException("GetEvalStackReduceDataType invalid type");
			return EvalStackReduceDataType::Other;
		}
		}
	}

	int32_t GetSizeByReduceType(EvalStackReduceDataType type)
	{
		switch (type)
		{
		case hybridclr::transform::EvalStackReduceDataType::I4:
		case hybridclr::transform::EvalStackReduceDataType::R4:
			return 4;
		case hybridclr::transform::EvalStackReduceDataType::I8:
		case hybridclr::transform::EvalStackReduceDataType::R8:
			return 8;
		default:
		{
			RaiseExecutionEngineException("GetSizeByReduceType not support type");
			return PTR_SIZE;
		}
		}
	}

	LocationDescInfo ComputValueTypeDescInfo(int32_t size)
	{
		switch (size)
		{
		case 1: return { LocationDescType::U1, 0 };
		case 2: return { LocationDescType::U2, 0 };
		case 4: return { LocationDescType::I4, 0 };
		case 8: return { LocationDescType::I8, 0 };
		default: return { LocationDescType::S, size };
		}
	}

	LocationDescInfo ComputLocationDescInfo(const Il2CppType* type)
	{
		if (type->byref)
		{
			return { NATIVE_INT_DESC_TYPE, 0 };
		}
		switch (type->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_U1:
			return{ LocationDescType::U1, 0 };
		case IL2CPP_TYPE_I1:
			return{ LocationDescType::I1, 0 };
		case IL2CPP_TYPE_I2:
			return{ LocationDescType::I2, 0 };
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_U2:
			return{ LocationDescType::U2, 0 };
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
		case IL2CPP_TYPE_R4:
			return{ LocationDescType::I4, 0 };
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R8:
			return{ LocationDescType::I8, 0 };
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
			return{ NATIVE_INT_DESC_TYPE, 0 };
		case IL2CPP_TYPE_TYPEDBYREF:
			return { LocationDescType::S, sizeof(Il2CppTypedRef) };
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
			if (klass->enumtype)
			{
				return ComputLocationDescInfo(&klass->castClass->byval_arg);
			}
			return ComputValueTypeDescInfo(il2cpp::vm::Class::GetValueSize(klass, nullptr));
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			Il2CppGenericClass* genericClass = type->data.generic_class;
			if (genericClass->type->type == IL2CPP_TYPE_CLASS)
			{
				IL2CPP_ASSERT(!IS_CLASS_VALUE_TYPE(il2cpp::vm::Class::FromIl2CppType(type)));
				return{ NATIVE_INT_DESC_TYPE, 0 };
			}
			else
			{
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
				if (klass->enumtype)
				{
					return ComputLocationDescInfo(&klass->castClass->byval_arg);
				}
				return ComputValueTypeDescInfo(il2cpp::vm::Class::GetValueSize(klass, nullptr));
			}
		}
		default:
		{
			RaiseExecutionEngineException("not support arg type");
			return{ NATIVE_INT_DESC_TYPE, 0 };
		}
		}
	}

	IRCommon* CreateLoadExpandDataToStackVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, const Il2CppType* type, int32_t size)
	{
		if (type->byref)
		{
			CreateIR(ir, LdlocVarVar);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		switch (type->type)
		{
		case Il2CppTypeEnum::IL2CPP_TYPE_I1:
		{
			CreateIR(ir, LdlocExpandVarVar_i1);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		case Il2CppTypeEnum::IL2CPP_TYPE_BOOLEAN:
		case Il2CppTypeEnum::IL2CPP_TYPE_U1:
		{
			CreateIR(ir, LdlocExpandVarVar_u1);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		case Il2CppTypeEnum::IL2CPP_TYPE_I2:
		{
			CreateIR(ir, LdlocExpandVarVar_i2);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_U2:
		{
			CreateIR(ir, LdlocExpandVarVar_u2);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			if (klass->enumtype)
			{
				return CreateLoadExpandDataToStackVarVar(pool, dstOffset, srcOffset, &klass->element_class->byval_arg, size);
			}
			break;
		}
		default: break;
		}
		if (size <= 8)
		{
			CreateIR(ir, LdlocVarVar);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		else
		{
			IL2CPP_ASSERT(size <= MAX_VALUE_TYPE_SIZE);
			CreateIR(ir, LdlocVarVarSize);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			ir->size = size;
			return ir;
		}
	}

	IRCommon* CreateAssignVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, int32_t size)
	{
		if (size <= 8)
		{
			CreateIR(ir, LdlocVarVar);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			return ir;
		}
		else
		{
			IL2CPP_ASSERT(size <= MAX_VALUE_TYPE_SIZE);
			CreateIR(ir, LdlocVarVarSize);
			ir->dst = dstOffset;
			ir->src = srcOffset;
			ir->size = size;
			return ir;
		}
	}

	interpreter::IRCommon* CreateClassLdfld(TemporaryMemoryArena& pool, int32_t dstIdx, int32_t objIdx, const FieldInfo* fieldInfo)
	{
		uint16_t offset = (uint16_t)GetFieldOffset(fieldInfo);

		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, LdfldVarVar_i1);
		ir->dst = dstIdx;
		ir->obj = objIdx;
		ir->offset = offset;
		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::LdfldVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::LdfldVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::LdfldVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::LdfldVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::LdfldVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::LdfldVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::LdfldVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::LdfldVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, LdfldVarVar_n_4);
				irn->dst = dstIdx;
				irn->obj = objIdx;
				irn->offset = offset;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	interpreter::IRCommon* CreateValueTypeLdfld(TemporaryMemoryArena& pool, int32_t dstIdx, int32_t objIdx, const FieldInfo* fieldInfo)
	{
		uint16_t offset = (uint16_t)GetFieldOffset(fieldInfo);

		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, LdfldValueTypeVarVar_i1);
		ir->dst = dstIdx;
		ir->obj = objIdx;
		ir->offset = offset;
		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, LdfldValueTypeVarVar_n_4);
				irn->dst = dstIdx;
				irn->obj = objIdx;
				irn->offset = offset;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	interpreter::IRCommon* CreateStfld(TemporaryMemoryArena& pool, int32_t objIdx, const FieldInfo* fieldInfo, int32_t dataIdx)
	{
		uint16_t offset = (uint16_t)GetFieldOffset(fieldInfo);

		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, StfldVarVar_i1);
		ir->data = dataIdx;
		ir->obj = objIdx;
		ir->offset = offset;
		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::StfldVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::StfldVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, StfldVarVar_n_4);
				irn->data = dataIdx;
				irn->obj = objIdx;
				irn->offset = offset;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	interpreter::IRCommon* CreateLdsfld(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent)
	{
		IL2CPP_ASSERT(fieldInfo->offset < (1 << 16));
		uint16_t offset = (uint16_t)fieldInfo->offset;

		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, LdsfldVarVar_i1);
		ir->dst = dstIdx;
		ir->klass = parent;
		ir->offset = offset;
		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::LdsfldVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::LdsfldVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::LdsfldVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::LdsfldVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::LdsfldVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::LdsfldVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::LdsfldVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::LdsfldVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, LdsfldVarVar_n_4);
				irn->dst = dstIdx;
				irn->klass = parent;
				irn->offset = offset;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	interpreter::IRCommon* CreateStsfld(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx)
	{
		IL2CPP_ASSERT(fieldInfo->offset < (1 << 16));
		uint16_t offset = (uint16_t)fieldInfo->offset;


		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, StsfldVarVar_i1);
		ir->klass = parent;
		ir->offset = offset;
		ir->data = dataIdx;
		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::StsfldVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::StsfldVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, StsfldVarVar_n_4);
				irn->klass = parent;
				irn->offset = offset;
				irn->data = dataIdx;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	interpreter::IRCommon* CreateLdthreadlocal(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent)
	{
		IL2CPP_ASSERT(fieldInfo->offset == THREAD_STATIC_FIELD_OFFSET);
		int32_t offset = GetThreadStaticFieldOffset(fieldInfo);

		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, LdthreadlocalVarVar_i1);
		ir->dst = dstIdx;
		ir->klass = parent;
		ir->offset = offset;

		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::LdthreadlocalVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::LdthreadlocalVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::LdthreadlocalVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::LdthreadlocalVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::LdthreadlocalVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::LdthreadlocalVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::LdthreadlocalVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::LdthreadlocalVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, LdthreadlocalVarVar_n_4);
				irn->dst = dstIdx;
				irn->klass = parent;
				irn->offset = offset;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	interpreter::IRCommon* CreateStthreadlocal(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx)
	{
		IL2CPP_ASSERT(fieldInfo->offset == THREAD_STATIC_FIELD_OFFSET);
		int32_t offset = GetThreadStaticFieldOffset(fieldInfo);

		const Il2CppType* type = fieldInfo->type;
		LocationDescInfo desc = ComputLocationDescInfo(type);

		CreateIR(ir, StthreadlocalVarVar_i1);
		ir->klass = parent;
		ir->offset = offset;
		ir->data = dataIdx;

		switch (desc.type)
		{
		case LocationDescType::I1:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_i1;
			return ir;
		}
		case LocationDescType::U1:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_u1;
			return ir;
		}
		case LocationDescType::I2:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_i2;
			return ir;
		}
		case LocationDescType::U2:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_u2;
			return ir;
		}
		case LocationDescType::I4:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_i4;
			return ir;
		}
		case LocationDescType::I8:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_i8;
			return ir;
		}
		case LocationDescType::S:
		{
			switch (desc.size)
			{
			case 12:
			{
				ir->type = HiOpcodeEnum::StthreadlocalVarVar_size_12;
				return ir;
			}
			case 16:
			{
				ir->type = HiOpcodeEnum::StthreadlocalVarVar_size_16;
				return ir;
			}
			default:
			{
				CreateIR(irn, StthreadlocalVarVar_n_4);
				irn->klass = parent;
				irn->offset = offset;
				irn->data = dataIdx;
				irn->size = desc.size;
				return irn;
			}
			}
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	HiOpcodeEnum CalcGetMdArrElementVarVarOpcode(const Il2CppType* type)
	{
		LocationDescInfo desc = ComputLocationDescInfo(type);
		switch (desc.type)
		{
		case LocationDescType::I1: return HiOpcodeEnum::GetMdArrElementVarVar_i1;
		case LocationDescType::U1: return HiOpcodeEnum::GetMdArrElementVarVar_u1;
		case LocationDescType::I2: return HiOpcodeEnum::GetMdArrElementVarVar_i2;
		case LocationDescType::U2: return HiOpcodeEnum::GetMdArrElementVarVar_u2;
		case LocationDescType::I4: return HiOpcodeEnum::GetMdArrElementVarVar_i4;
		case LocationDescType::I8: return HiOpcodeEnum::GetMdArrElementVarVar_i8;
		case LocationDescType::S: return HiOpcodeEnum::GetMdArrElementVarVar_size;
		default:
		{
			RaiseExecutionEngineException("CalcGetMdArrElementVarVarOpcode");
			return (HiOpcodeEnum)0;
		}
		}
	}

}
}