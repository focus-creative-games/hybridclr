#include "TransformContext.h"

#include "metadata/GenericMetadata.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/String.h"
#include "vm/Field.h"

#include "../metadata/MethodBodyCache.h"
#include "../interpreter/InterpreterUtil.h"

namespace hybridclr
{
namespace transform
{
	constexpr int32_t MAX_STACK_SIZE = (2 << 16) - 1;
	constexpr int32_t MAX_VALUE_TYPE_SIZE = (2 << 16) - 1;

	template<typename T>
	void AllocResolvedData(il2cpp::utils::dynamic_array<uint64_t>& resolvedDatas, int32_t size, int32_t& index, T*& buf)
	{
		if (size > 0)
		{
			int32_t oldSize = index = (int32_t)resolvedDatas.size();
			resolvedDatas.resize_initialized(oldSize + size);
			buf = (T*)&resolvedDatas[oldSize];
		}
		else
		{
			index = 0;
			buf = nullptr;
		}
	}

	IRCommon* CreateInitLocals(TemporaryMemoryArena& pool, uint32_t size, int32_t offset)
	{
		if (offset == 0)
		{
			CreateIR(ir, InitLocals_n_4);
			ir->size = size;
			return ir;
		}
		else
		{
			CreateIR(ir, InitInlineLocals_n_4);
			ir->size = size;
			ir->offset = offset;
			return ir;
		}
	}

	IRCommon* CreateLoadExpandDataToStackVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, const Il2CppType* type, int32_t size);
	IRCommon* CreateAssignVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, int32_t size);

	interpreter::IRCommon* CreateClassLdfld(TemporaryMemoryArena& pool, int32_t dstIdx, int32_t objIdx, const FieldInfo* fieldInfo);

	interpreter::IRCommon* CreateValueTypeLdfld(TemporaryMemoryArena& pool, int32_t dstIdx, int32_t objIdx, const FieldInfo* fieldInfo);
	interpreter::IRCommon* CreateStfld(TemporaryMemoryArena& pool, int32_t objIdx, const FieldInfo* fieldInfo, int32_t dataIdx);

	interpreter::IRCommon* CreateLdsfld(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent);
	interpreter::IRCommon* CreateStsfld(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx);
	interpreter::IRCommon* CreateLdthreadlocal(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent);
	interpreter::IRCommon* CreateStthreadlocal(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx);

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

	LocationDescInfo ComputValueTypeDescInfo(int32_t size, bool hasReference)
	{
#if HYBRIDCLR_ENABLE_WRITE_BARRIERS
		if (hasReference)
		{
			return { LocationDescType::StructContainsRef, size };
		}
#endif
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
			return{ NATIVE_INT_DESC_TYPE, 0 };
		case IL2CPP_TYPE_STRING:
		case IL2CPP_TYPE_ARRAY:
		case IL2CPP_TYPE_SZARRAY:
		case IL2CPP_TYPE_OBJECT:
		case IL2CPP_TYPE_CLASS:
			return{ LocationDescType::Ref, 0 };
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
			return ComputValueTypeDescInfo(il2cpp::vm::Class::GetValueSize(klass, nullptr), klass->has_references);
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			Il2CppGenericClass* genericClass = type->data.generic_class;
			if (genericClass->type->type == IL2CPP_TYPE_CLASS)
			{
				IL2CPP_ASSERT(!IS_CLASS_VALUE_TYPE(il2cpp::vm::Class::FromIl2CppType(type)));
				return{ LocationDescType::Ref, 0 };
			}
			else
			{
				Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
				IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
				if (klass->enumtype)
				{
					return ComputLocationDescInfo(&klass->castClass->byval_arg);
				}
				return ComputValueTypeDescInfo(il2cpp::vm::Class::GetValueSize(klass, nullptr), klass->has_references);
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
		IL2CPP_ASSERT(dstOffset >= 0 && dstOffset < 0x10000);
		IL2CPP_ASSERT(srcOffset >= 0 && srcOffset < 0x10000);
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
		case LocationDescType::Ref:
		{
			ir->type = ARCH_ARGUMENT(HiOpcodeEnum::LdfldVarVar_i4, HiOpcodeEnum::LdfldVarVar_i8);
			return ir;
		}
		case LocationDescType::S:
		case LocationDescType::StructContainsRef:
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
			case 20:
			{
				ir->type = HiOpcodeEnum::LdfldVarVar_size_20;
				return ir;
			}
			case 24:
			{
				ir->type = HiOpcodeEnum::LdfldVarVar_size_24;
				return ir;
			}
			case 28:
			{
				ir->type = HiOpcodeEnum::LdfldVarVar_size_28;
				return ir;
			}
			case 32:
			{
				ir->type = HiOpcodeEnum::LdfldVarVar_size_32;
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
		case LocationDescType::Ref:
		{
			ir->type = ARCH_ARGUMENT(HiOpcodeEnum::LdfldValueTypeVarVar_i4, HiOpcodeEnum::LdfldValueTypeVarVar_i8);
			return ir;
		}
		case LocationDescType::S:
		case LocationDescType::StructContainsRef:
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
			case 20:
			{
				ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_size_20;
				return ir;
			}
			case 24:
			{
				ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_size_24;
				return ir;
			}
			case 28:
			{
				ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_size_28;
				return ir;
			}
			case 32:
			{
				ir->type = HiOpcodeEnum::LdfldValueTypeVarVar_size_32;
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
		case LocationDescType::Ref:
		{
			ir->type = HiOpcodeEnum::StfldVarVar_ref;
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
			case 20:
			{
				ir->type = HiOpcodeEnum::StfldVarVar_size_20;
				return ir;
			}
			case 24:
			{
				ir->type = HiOpcodeEnum::StfldVarVar_size_24;
				return ir;
			}
			case 28:
			{
				ir->type = HiOpcodeEnum::StfldVarVar_size_28;
				return ir;
			}
			case 32:
			{
				ir->type = HiOpcodeEnum::StfldVarVar_size_32;
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
		case LocationDescType::StructContainsRef:
		{
			CreateIR(irn, StfldVarVar_WriteBarrier_n_4);
			irn->data = dataIdx;
			irn->obj = objIdx;
			irn->offset = offset;
			irn->size = desc.size;
			return irn;
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
		case LocationDescType::Ref:
		{
			ir->type = ARCH_ARGUMENT(HiOpcodeEnum::LdsfldVarVar_i4, HiOpcodeEnum::LdsfldVarVar_i8);
			return ir;
		}
		case LocationDescType::S:
		case LocationDescType::StructContainsRef:
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
			case 20:
			{
				ir->type = HiOpcodeEnum::LdsfldVarVar_size_20;
				return ir;
			}
			case 24:
			{
				ir->type = HiOpcodeEnum::LdsfldVarVar_size_24;
				return ir;
			}
			case 28:
			{
				ir->type = HiOpcodeEnum::LdsfldVarVar_size_28;
				return ir;
			}
			case 32:
			{
				ir->type = HiOpcodeEnum::LdsfldVarVar_size_32;
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
		case LocationDescType::Ref:
		{
			ir->type = HiOpcodeEnum::StsfldVarVar_ref;
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
			case 20:
			{
				ir->type = HiOpcodeEnum::StsfldVarVar_size_20;
				return ir;
			}
			case 24: 
			{
				ir->type = HiOpcodeEnum::StsfldVarVar_size_24;
				return ir;
			}
			case 28: 
			{
				ir->type = HiOpcodeEnum::StsfldVarVar_size_28;
				return ir;
			}
			case 32: 
			{
				ir->type = HiOpcodeEnum::StsfldVarVar_size_32;
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
		case LocationDescType::StructContainsRef:
		{
			CreateIR(irn, StsfldVarVar_WriteBarrier_n_4);
			irn->klass = parent;
			irn->offset = offset;
			irn->data = dataIdx;
			irn->size = desc.size;
			return irn;
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
		case LocationDescType::Ref:
		{
			ir->type = ARCH_ARGUMENT(HiOpcodeEnum::LdthreadlocalVarVar_i4, HiOpcodeEnum::LdthreadlocalVarVar_i8);
			return ir;
		}
		case LocationDescType::S:
		case LocationDescType::StructContainsRef:
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
			case 20:
			{
				ir->type = HiOpcodeEnum::LdthreadlocalVarVar_size_20;
				return ir;
			}
			case 24:
			{
				ir->type = HiOpcodeEnum::LdthreadlocalVarVar_size_24;
				return ir;
			}
			case 28:
			{
				ir->type = HiOpcodeEnum::LdthreadlocalVarVar_size_28;
				return ir;
			}
			case 32:
			{
				ir->type = HiOpcodeEnum::LdthreadlocalVarVar_size_32;
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
		case LocationDescType::Ref:
		{
			ir->type = HiOpcodeEnum::StthreadlocalVarVar_ref;
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
			case 20: 
			{
				ir->type = HiOpcodeEnum::StthreadlocalVarVar_size_20;
				return ir;
			}
			case 24: 
			{
				ir->type = HiOpcodeEnum::StthreadlocalVarVar_size_24;
				return ir;
			}
			case 28: 
			{
				ir->type = HiOpcodeEnum::StthreadlocalVarVar_size_28;
				return ir;
			}
			case 32: 
			{
				ir->type = HiOpcodeEnum::StthreadlocalVarVar_size_32;
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
		case LocationDescType::StructContainsRef:
		{
			CreateIR(irn, StthreadlocalVarVar_WriteBarrier_n_4);
			irn->klass = parent;
			irn->offset = offset;
			irn->data = dataIdx;
			irn->size = desc.size;
			return irn;
		}
		default:
		{
			RaiseExecutionEngineException("field");
			return ir;
		}
		}
	}

	// TransformContext implements


	HiOpcodeEnum TransformContext::CalcGetMdArrElementVarVarOpcode(const Il2CppType* type)
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
		case LocationDescType::Ref: return ARCH_ARGUMENT(HiOpcodeEnum::GetMdArrElementVarVar_i4, HiOpcodeEnum::GetMdArrElementVarVar_i8);
		case LocationDescType::S:
		case LocationDescType::StructContainsRef: return HiOpcodeEnum::GetMdArrElementVarVar_n;
		default:
		{
			RaiseExecutionEngineException("CalcGetMdArrElementVarVarOpcode");
			return (HiOpcodeEnum)0;
		}
		}
	}

	TransformContext::TransformContext(hybridclr::metadata::Image* image, const MethodInfo* methodInfo, metadata::MethodBody& body, TemporaryMemoryArena& pool, il2cpp::utils::dynamic_array<uint64_t>& resolveDatas)
		: image(image), methodInfo(methodInfo), body(body), pool(pool), resolveDatas(resolveDatas),
		actualParamCount(0), ip2bb(nullptr), curbb(nullptr), args(nullptr), locals(nullptr), evalStack(nullptr),
		evalStackTop(0), evalStackBaseOffset(0), curStackSize(0), maxStackSize(0),
		nextFlowIdx(0), ipBase(nullptr), ip(nullptr), ipOffset(0), ir2offsetMap(nullptr),
		prefixFlags(0), shareMethod(nullptr), totalIRSize(0), totalArgSize(0), totalArgLocalSize(0), initLocals(false)
	{

	}

	TransformContext::~TransformContext()
	{
		for (IRBasicBlock* bb : irbbs)
		{
			bb->~IRBasicBlock();
		}
		if (ir2offsetMap)
		{
			delete ir2offsetMap;
		}
	}

	uint32_t TransformContext::GetOrAddResolveDataIndex(const void* ptr)
	{
		auto it = ptr2DataIdxs.find(ptr);
		if (it != ptr2DataIdxs.end())
		{
			return it->second;
		}
		else
		{
			uint32_t newIndex = (uint32_t)resolveDatas.size();
			resolveDatas.push_back((uint64_t)ptr);
			ptr2DataIdxs.insert({ ptr, newIndex });
			return newIndex;
		}
	}

	void TransformContext::PushStackByType(const Il2CppType* type)
	{
		int32_t byteSize = GetTypeValueSize(type);
		int32_t stackSize = GetStackSizeByByteSize(byteSize);
		evalStack[evalStackTop].reduceType = GetEvalStackReduceDataType(type);
		evalStack[evalStackTop].byteSize = byteSize;
		evalStack[evalStackTop].locOffset = GetEvalStackNewTopOffset();
		evalStackTop++;
		curStackSize += stackSize;
		maxStackSize = std::max(curStackSize, maxStackSize);
		IL2CPP_ASSERT(maxStackSize < MAX_STACK_SIZE);
	}

	void TransformContext::PushStackByReduceType(EvalStackReduceDataType t)
	{
		int32_t byteSize = GetSizeByReduceType(t);
		int32_t stackSize = GetStackSizeByByteSize(byteSize);
		evalStack[evalStackTop].reduceType = t;
		evalStack[evalStackTop].byteSize = byteSize;
		evalStack[evalStackTop].locOffset = GetEvalStackNewTopOffset();
		evalStackTop++; curStackSize += stackSize;
		maxStackSize = std::max(curStackSize, maxStackSize);
		IL2CPP_ASSERT(maxStackSize < MAX_STACK_SIZE);
	}

	void TransformContext::DuplicateStack()
	{
		IL2CPP_ASSERT(evalStackTop > 0);
		EvalStackVarInfo& oldTop = evalStack[evalStackTop - 1];
		int32_t stackSize = GetStackSizeByByteSize(oldTop.byteSize);
		EvalStackVarInfo& newTop = evalStack[evalStackTop++];
		newTop.reduceType = oldTop.reduceType;
		newTop.byteSize = oldTop.byteSize;
		newTop.locOffset = curStackSize;
		curStackSize += stackSize;
		maxStackSize = std::max(curStackSize, maxStackSize);
		IL2CPP_ASSERT(maxStackSize < MAX_STACK_SIZE);
	}

	void TransformContext::PopStack()
	{
		IL2CPP_ASSERT(evalStackTop > 0);
		--evalStackTop;
		curStackSize = evalStack[evalStackTop].locOffset;
	}

	void TransformContext::PopStackN(int32_t n)
	{
		IL2CPP_ASSERT(evalStackTop >= n && n >= 0);
		if (n > 0)
		{
			evalStackTop -= n;
			curStackSize = evalStack[evalStackTop].locOffset;
		}
	}

	void TransformContext::PopAllStack()
	{
		if (evalStackTop > 0)
		{
			evalStackTop = 0;
			curStackSize = evalStackBaseOffset;
		}
		else
		{
			IL2CPP_ASSERT(curStackSize == evalStackBaseOffset);
		}
	}

	void TransformContext::InsertMemoryBarrier()
	{
		if (prefixFlags & (int32_t)PrefixFlags::Volatile)
		{
			CreateAddIR(_mb, MemoryBarrier);
		}
	}

	void TransformContext::ResetPrefixFlags()
	{
		prefixFlags = 0;
	}

	void TransformContext::Add_ldind(HiOpcodeEnum opCode, EvalStackReduceDataType dataType)
	{
		CreateAddIR(ir, LdindVarVar_i1);
		ir->type = opCode;
		ir->dst = ir->src = GetEvalStackTopOffset();
		PopStack();
		PushStackByReduceType(dataType);
		InsertMemoryBarrier();
		ResetPrefixFlags();
		ip++;
	}

	void TransformContext::Add_stind(HiOpcodeEnum opCode)
	{
		IL2CPP_ASSERT(evalStackTop >= 2);
		InsertMemoryBarrier();
		ResetPrefixFlags();
		CreateAddIR(ir, StindVarVar_i1);
		ir->type = opCode;
		ir->dst = evalStack[evalStackTop - 2].locOffset;
		ir->src = evalStack[evalStackTop - 1].locOffset;
		PopStackN(2);
		ip++;
	}

	void TransformContext::PushOffset(int32_t* offsetPtr)
	{
		IL2CPP_ASSERT(splitOffsets.find(*(offsetPtr)) != splitOffsets.end());
		relocationOffsets.push_back(offsetPtr);
	}

	void TransformContext::PushBranch(int32_t targetOffset)
	{
		IL2CPP_ASSERT(splitOffsets.find(targetOffset) != splitOffsets.end());
		IRBasicBlock* targetBb = ip2bb[targetOffset];
		if (!targetBb->inPending)
		{
			targetBb->inPending = true;
			FlowInfo* fi = pool.NewAny<FlowInfo>();
			fi->offset = targetOffset;
			fi->curStackSize = curStackSize;
			if (evalStackTop > 0)
			{
				fi->evalStack.insert(fi->evalStack.end(), evalStack, evalStack + evalStackTop);
			}
			else
			{
				IL2CPP_ASSERT(curStackSize == evalStackBaseOffset);
			}
			pendingFlows.push_back(fi);
		}
	}

	bool TransformContext::FindNextFlow()
	{
		for (; nextFlowIdx < (int32_t)pendingFlows.size(); )
		{
			FlowInfo* fi = pendingFlows[nextFlowIdx++];
			IRBasicBlock* nextBb = ip2bb[fi->offset];
			if (!nextBb->visited)
			{
				ip = ipBase + fi->offset;
				if (!fi->evalStack.empty()) {

					std::memcpy(evalStack, &fi->evalStack[0], sizeof(EvalStackVarInfo) * fi->evalStack.size());
				}
				curStackSize = fi->curStackSize;
				IL2CPP_ASSERT(curStackSize >= evalStackBaseOffset);
				evalStackTop = (int32_t)fi->evalStack.size();
				return true;
			}
		}
		return false;
	}

	void TransformContext::AddInst(IRCommon* ir)
	{
		IL2CPP_ASSERT(ir->type != HiOpcodeEnum::None);
		curbb->insts.push_back(ir);
		if (ir2offsetMap)
		{
			ir2offsetMap->insert({ ir, ipOffset });
		}
	}

	void TransformContext::AddInst_ldarg(int32_t argIdx)
	{
		ArgVarInfo& __arg = args[argIdx];
		IRCommon* ir = CreateLoadExpandDataToStackVarVar(pool, GetEvalStackNewTopOffset(), __arg.argLocOffset, __arg.type, GetTypeValueSize(__arg.type));
		AddInst(ir);
		PushStackByType(__arg.type);
	}

	bool TransformContext::IsCreateNotNullObjectInstrument(IRCommon* ir)
	{
		switch (ir->type)
		{
		case HiOpcodeEnum::BoxVarVar:
		{
			IRBoxVarVar* irBox = (IRBoxVarVar*)ir;
			Il2CppClass* klass = ((Il2CppClass*)resolveDatas[irBox->klass]);
			return IS_CLASS_VALUE_TYPE(klass) && !il2cpp::vm::Class::IsNullable(klass);
		}
		case HiOpcodeEnum::NewSystemObjectVar:
		case HiOpcodeEnum::NewString:
		case HiOpcodeEnum::NewString_2:
		case HiOpcodeEnum::NewString_3:
		case HiOpcodeEnum::CtorDelegate:
		case HiOpcodeEnum::NewDelegate:
			//case HiOpcodeEnum::NewClassInterpVar_Ctor_0:
			//case HiOpcodeEnum::NewClassInterpVar:
			//case HiOpcodeEnum::NewClassVar:
			//case HiOpcodeEnum::NewClassVar_Ctor_0:
			//case HiOpcodeEnum::NewClassVar_NotCtor:
		case HiOpcodeEnum::NewMdArrVarVar_length:
		case HiOpcodeEnum::NewMdArrVarVar_length_bound:
		case HiOpcodeEnum::NewArrVarVar:
		case HiOpcodeEnum::LdsfldaFromFieldDataVarVar:
		case HiOpcodeEnum::LdsfldaVarVar:
		case HiOpcodeEnum::LdthreadlocalaVarVar:
		case HiOpcodeEnum::LdlocVarAddress:
			return true;
		default:
			return false;
		}
	}

	void TransformContext::RemoveLastInstrument()
	{
		IL2CPP_ASSERT(!curbb->insts.empty());
		curbb->insts.pop_back();
	}

	void TransformContext::AddInst_ldarga(int32_t argIdx)
	{
		IL2CPP_ASSERT(argIdx < actualParamCount);
		ArgVarInfo& argInfo = args[argIdx];
		CreateAddIR(ir, LdlocVarAddress);
		ir->dst = GetEvalStackNewTopOffset();
		ir->src = argInfo.argLocOffset;
		PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
	}

	void TransformContext::AddInst_starg(int32_t argIdx)
	{
		IL2CPP_ASSERT(argIdx < actualParamCount);
		ArgVarInfo& __arg = args[argIdx];
		IRCommon* ir = CreateAssignVarVar(pool, __arg.argLocOffset, GetEvalStackTopOffset(), GetTypeValueSize(__arg.type));
		AddInst(ir);
		PopStack();
	}

	void TransformContext::CreateAddInst_ldloc(int32_t locIdx)
	{
		LocVarInfo& __loc = locals[locIdx];
		IRCommon* ir = CreateLoadExpandDataToStackVarVar(pool, GetEvalStackNewTopOffset(), __loc.locOffset, __loc.type, GetTypeValueSize(__loc.type));
		AddInst(ir);
		PushStackByType(__loc.type);
	}

	void TransformContext::CreateAddInst_stloc(int32_t locIdx)
	{
		LocVarInfo& __loc = locals[locIdx];
		IRCommon* ir = CreateAssignVarVar(pool, __loc.locOffset, GetEvalStackTopOffset(), GetTypeValueSize(__loc.type));
		AddInst(ir);
		PopStack();
	}

	void TransformContext::CreateAddInst_ldloca(int32_t locIdx)
	{
		CreateAddIR(ir, LdlocVarAddress);
		LocVarInfo& __loc = locals[locIdx];
		ir->dst = GetEvalStackNewTopOffset();
		ir->src = __loc.locOffset;
		PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
	}

	void TransformContext::CreateAddInst_ldc4(int32_t c, EvalStackReduceDataType rtype)
	{
		CreateAddIR(ir, LdcVarConst_4);
		ir->dst = GetEvalStackNewTopOffset();
		ir->src = c;
		PushStackByReduceType(rtype);
	}

	void TransformContext::CreateAddInst_ldc8(int64_t c, EvalStackReduceDataType rtype)
	{
		CreateAddIR(ir, LdcVarConst_8);
		ir->dst = GetEvalStackNewTopOffset();
		ir->src = c;
		PushStackByReduceType(rtype);
	}

	void TransformContext::Add_brtruefalse(bool c, int32_t targetOffset)
	{
		EvalStackVarInfo& top = evalStack[evalStackTop - 1];
		IRCommon* lastIR = GetLastInstrument();
		if (lastIR == nullptr || !IsCreateNotNullObjectInstrument(lastIR))
		{
			if (top.byteSize <= 4)
			{
				CreateAddIR(ir, BranchTrueVar_i4);
				ir->type = c ? HiOpcodeEnum::BranchTrueVar_i4 : HiOpcodeEnum::BranchFalseVar_i4;
				ir->op = top.locOffset;
				ir->offset = targetOffset;
				PushOffset(&ir->offset);
			}
			else
			{
				CreateAddIR(ir, BranchTrueVar_i8);
				ir->type = c ? HiOpcodeEnum::BranchTrueVar_i8 : HiOpcodeEnum::BranchFalseVar_i8;
				ir->op = top.locOffset;
				ir->offset = targetOffset;
				PushOffset(&ir->offset);
			}
		}
		else
		{
			// optimize instrument sequence like` box T!; brtrue`
			// this optimization is not semanticly equals to origin instrument because may ommit `Class::InitRuntime`.
			// but it's ok in most occasions.
			RemoveLastInstrument();
			if (c)
			{
				// brtrue always true, replace with br
				CreateAddIR(ir, BranchUncondition_4);
				ir->offset = targetOffset;
				PushOffset(&ir->offset);
			}
			else
			{
				// brfalse always false, run throughtly.
			}
		}
		PopStack();
		PushBranch(targetOffset);
	}

	void TransformContext::Add_bc(int32_t ipOffset, int32_t brOffset, int32_t opSize, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
	{
		int32_t targetOffset = ipOffset + brOffset + opSize;
		EvalStackVarInfo& op1 = evalStack[evalStackTop - 2];
		EvalStackVarInfo& op2 = evalStack[evalStackTop - 1];
		IRBranchVarVar_Ceq_i4* ir = pool.AllocIR<IRBranchVarVar_Ceq_i4>();
		ir->type = (HiOpcodeEnum)0;
		ir->op1 = op1.locOffset;
		ir->op2 = op2.locOffset;
		ir->offset = targetOffset;
		PushOffset(&ir->offset);
		switch (op1.reduceType)
		{
		case EvalStackReduceDataType::I4:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				CreateAddIR(irConv, ConvertVarVar_i4_i8);
				irConv->dst = irConv->src = op1.locOffset;
				ir->type = opI8;
				break;
			}
			default:
			{
				IL2CPP_ASSERT(false && "I4 not match");
				break;
			}
			}
			break;
		}
		case EvalStackReduceDataType::I8:
		{
			IL2CPP_ASSERT(op2.reduceType == EvalStackReduceDataType::I8);
			ir->type = opI8;
			break;
		}
		case EvalStackReduceDataType::R4:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::R4:
			{
				ir->type = opR4;
				break;
			}
			default:
			{
				IL2CPP_ASSERT(false && "R4 not match");
				break;
			}
			}
			break;
		}
		case EvalStackReduceDataType::R8:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::R8:
			{
				ir->type = opR8;
				break;
			}
			default:
			{
				IL2CPP_ASSERT(false && "R8 not match");
				break;
			}
			}
			break;
		}
		default:
		{
			IL2CPP_ASSERT(false && "nothing match");
		}
		}
		AddInst(ir);
		PopStackN(2);
		PushBranch(targetOffset);
	}

	void TransformContext::Add_conv(int32_t dstTypeSize, EvalStackReduceDataType dstReduceType, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
	{
		IL2CPP_ASSERT(evalStackTop > 0);
		EvalStackVarInfo& top = evalStack[evalStackTop - 1];
		//if (top.reduceType != dstReduceType)
		{
			CreateIR(ir, ConvertVarVar_i4_u4);
			ir->type = (HiOpcodeEnum)0;
			ir->dst = ir->src = GetEvalStackTopOffset();
			switch (top.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4;
				AddInst(ir);
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				ir->type = opI8;
				AddInst(ir);
				break;
			}
			case EvalStackReduceDataType::R4:
			{
				ir->type = opR4;
				AddInst(ir);
				break;
			}
			case EvalStackReduceDataType::R8:
			{
				ir->type = opR8;
				AddInst(ir);
				break;
			}
			default:
			{
				RaiseExecutionEngineException("conv");
				break;
			}
			}
		}

		top.reduceType = dstReduceType;
		top.byteSize = dstTypeSize;
		ip++;
	}

	void TransformContext::Add_conv_ovf(int32_t dstTypeSize, EvalStackReduceDataType dstReduceType, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
	{
		IL2CPP_ASSERT(evalStackTop > 0);
		EvalStackVarInfo& top = evalStack[evalStackTop - 1];
		//if (top.reduceType != dstReduceType)
		{
			CreateIR(ir, ConvertOverflowVarVar_i4_u4);
			ir->type = (HiOpcodeEnum)0;
			ir->dst = ir->src = GetEvalStackTopOffset();
			switch (top.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4;
				AddInst(ir);
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				ir->type = opI8;
				AddInst(ir);
				break;
			}
			case EvalStackReduceDataType::R4:
			{
				ir->type = opR4;
				AddInst(ir);
				break;
			}
			case EvalStackReduceDataType::R8:
			{
				ir->type = opR8;
				AddInst(ir);
				break;
			}
			default:
			{
				RaiseExecutionEngineException("conv_ovf");
				break;
			}
			}
		}

		top.reduceType = dstReduceType;
		top.byteSize = dstTypeSize;
		ip++;
	}

	void TransformContext::Add_binop(HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
	{
		IL2CPP_ASSERT(evalStackTop >= 2);
		EvalStackVarInfo& op1 = evalStack[evalStackTop - 2];
		EvalStackVarInfo& op2 = evalStack[evalStackTop - 1];
		CreateIR(ir, BinOpVarVarVar_Add_i4);
		ir->op1 = op1.locOffset;
		ir->op2 = op2.locOffset;
		ir->ret = op1.locOffset;
		EvalStackReduceDataType resultType;
		switch (op1.reduceType)
		{
		case EvalStackReduceDataType::I4:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				resultType = EvalStackReduceDataType::I4;
				ir->type = opI4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				CreateAddIR(irConv, ConvertVarVar_i4_i8);
				irConv->dst = irConv->src = op1.locOffset;
				ir->type = opI8;
				resultType = EvalStackReduceDataType::I8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("Add_bin_op I4 op unknown");
				resultType = (EvalStackReduceDataType)-1;
			}
			}
			break;
		}
		case EvalStackReduceDataType::I8:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				CreateAddIR(irConv, ConvertVarVar_i4_i8);
				irConv->dst = irConv->src = op2.locOffset;
				resultType = EvalStackReduceDataType::I8;
				ir->type = opI8;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				resultType = EvalStackReduceDataType::I8;
				ir->type = opI8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("Add_bin_op I8 op unknown");
				resultType = (EvalStackReduceDataType)-1;
				break;
			}
			}
			break;
		}
		case EvalStackReduceDataType::R4:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::R4:
			{
				resultType = EvalStackReduceDataType::R4;
				ir->type = opR4;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("Add_bin_op R4 op unknown");
				resultType = (EvalStackReduceDataType)-1;
				break;
			}
			}
			break;
		}
		case EvalStackReduceDataType::R8:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::R8:
			{
				resultType = EvalStackReduceDataType::R8;
				ir->type = opR8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("Add_bin_op R8 op unknown");
				resultType = (EvalStackReduceDataType)-1;
				break;
			}
			}
			break;
		}
		default:
		{
			RaiseExecutionEngineException("Add_bin_op unknown");
			resultType = (EvalStackReduceDataType)-1;
			break;
		}
		}
		PopStack();
		op1.reduceType = resultType;
		op1.byteSize = GetSizeByReduceType(resultType);
		AddInst(ir);
		ip++;
	}

	void TransformContext::Add_shiftop(HiOpcodeEnum opI4I4, HiOpcodeEnum opI4I8, HiOpcodeEnum opI8I4, HiOpcodeEnum opI8I8)
	{
		IL2CPP_ASSERT(evalStackTop >= 2);
		EvalStackVarInfo& op1 = evalStack[evalStackTop - 2];
		EvalStackVarInfo& op2 = evalStack[evalStackTop - 1];
		CreateAddIR(ir, BitShiftBinOpVarVarVar_Shr_i4_i4);
		ir->ret = op1.locOffset;
		ir->value = op1.locOffset;
		ir->shiftAmount = op2.locOffset;
		switch (op1.reduceType)
		{
		case EvalStackReduceDataType::I4:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4I4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				ir->type = opI4I8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("shitf i4");
			}
			}
			break;
		}
		case EvalStackReduceDataType::I8:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI8I4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{

				ir->type = opI8I8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("shitf i8");
				break;
			}
			}
			break;
		}
		default:
		{
			RaiseExecutionEngineException("shitf i");
			break;
		}
		}
		PopStack();
		ip++;
	}

	void TransformContext::Add_compare(HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
	{
		IL2CPP_ASSERT(evalStackTop >= 2);
		EvalStackVarInfo& op1 = evalStack[evalStackTop - 2];
		EvalStackVarInfo& op2 = evalStack[evalStackTop - 1];
		CreateIR(ir, CompOpVarVarVar_Ceq_i4);
		ir->c1 = op1.locOffset;
		ir->c2 = op2.locOffset;
		ir->ret = op1.locOffset;
		switch (op1.reduceType)
		{
		case EvalStackReduceDataType::I4:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				CreateAddIR(irConv, ConvertVarVar_i4_i8);
				irConv->dst = irConv->src = op1.locOffset;
				ir->type = opI8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("compare i4");
				break;
			}
			}
			break;
		}
		case EvalStackReduceDataType::I8:
		{
			switch (op2.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				CreateAddIR(irConv, ConvertVarVar_i4_i8);
				irConv->dst = irConv->src = op2.locOffset;
				ir->type = opI8;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				ir->type = opI8;
				break;
			}
			default:
			{
				RaiseExecutionEngineException("compare i8");
				break;
			}
			}
			break;
		}
		case EvalStackReduceDataType::R4:
		{
			if (op2.reduceType == EvalStackReduceDataType::R4)
			{
				ir->type = opR4;
			}
			else
			{
				RaiseExecutionEngineException("compare r4");
			}
			break;
		}
		case EvalStackReduceDataType::R8:
		{
			if (op2.reduceType == EvalStackReduceDataType::R8)
			{
				ir->type = opR8;
			}
			else
			{
				RaiseExecutionEngineException("compare r8");
			}
			break;
		}
		default:
		{
			RaiseExecutionEngineException("compare");
			break;
		}
		}
		PopStackN(2);
		AddInst(ir);
		PushStackByReduceType(EvalStackReduceDataType::I4);
	}

	void TransformContext::Add_ldelem(EvalStackReduceDataType resultType, HiOpcodeEnum opI4)
	{
		IL2CPP_ASSERT(evalStackTop >= 2);
		EvalStackVarInfo& arr = evalStack[evalStackTop - 2];
		EvalStackVarInfo& index = evalStack[evalStackTop - 1];

		CreateAddIR(ir, GetArrayElementVarVar_i1);
		ir->type = opI4;
		ir->arr = arr.locOffset;
		ir->index = index.locOffset;
		ir->dst = arr.locOffset;

		PopStackN(2);
		PushStackByReduceType(resultType);
		ip++;
	}

	void TransformContext::Add_stelem(HiOpcodeEnum opI4)
	{
		IL2CPP_ASSERT(evalStackTop >= 3);
		EvalStackVarInfo& arr = evalStack[evalStackTop - 3];
		EvalStackVarInfo& index = evalStack[evalStackTop - 2];
		EvalStackVarInfo& ele = evalStack[evalStackTop - 1];

		CreateAddIR(ir, SetArrayElementVarVar_i1);
		ir->type = opI4;
		ir->arr = arr.locOffset;
		ir->index = index.locOffset;
		ir->ele = ele.locOffset;

		PopStackN(3);
		ip++;
	}


	bool TransformContext::FindFirstLeaveHandlerIndex(const std::vector<ExceptionClause>& exceptionClauses, uint32_t leaveOffset, uint32_t targetOffset, uint16_t& index)
	{
		index = 0;
		for (const ExceptionClause& ec : exceptionClauses)
		{
			if (ec.flags == CorILExceptionClauseType::Finally)
			{
				if (ec.tryOffset <= leaveOffset && leaveOffset < ec.tryOffset + ec.tryLength)
					return !(ec.tryOffset <= targetOffset && targetOffset < ec.tryOffset + ec.tryLength);
			}
			++index;
		}
		return false;
	}

	bool TransformContext::IsLeaveInTryBlock(const std::vector<ExceptionClause>& exceptionClauses, uint32_t leaveOffset)
	{
		for (const ExceptionClause& ec : exceptionClauses)
		{
			if (ec.tryOffset <= leaveOffset && leaveOffset < ec.tryOffset + ec.tryLength)
			{
				return true;
			}
			if (ec.handlerOffsets <= leaveOffset && leaveOffset < ec.handlerOffsets + ec.handlerLength)
			{
				return false;
			}
		}
		return false;
	}

	void TransformContext::Add_leave(uint32_t targetOffset)
	{
		uint32_t leaveOffset = (uint32_t)(ip - ipBase);
		uint16_t firstHandlerIndex;
		if (FindFirstLeaveHandlerIndex(body.exceptionClauses, leaveOffset, targetOffset, firstHandlerIndex))
		{
			CreateAddIR(ir, LeaveEx);
			ir->target = targetOffset;
			ir->firstHandlerIndex = firstHandlerIndex;
			PushOffset(&ir->target);
		}
		else if (!IsLeaveInTryBlock(body.exceptionClauses, leaveOffset))
		{
			CreateAddIR(ir, LeaveEx_Directly);
			ir->target = targetOffset;
			PushOffset(&ir->target);
		}
		else
		{
			CreateAddIR(ir, BranchUncondition_4);
			ir->offset = targetOffset;
			PushOffset(&ir->offset);
		}
		PopAllStack();
		PushBranch(targetOffset);
	}

	uint16_t TransformContext::FindFirstThrowHandlerIndex(const std::vector<ExceptionClause>& exceptionClauses, uint32_t throwOffset)
	{
		uint16_t index = 0;
		for (const ExceptionClause& ec : exceptionClauses)
		{
			if (ec.flags == CorILExceptionClauseType::Finally || ec.flags == CorILExceptionClauseType::Exception || ec.flags == CorILExceptionClauseType::Filter)
			{
				if (ec.tryOffset <= throwOffset && throwOffset < ec.tryOffset + ec.tryLength)
					return index;
			}
			++index;
		}
		return index;
	}

	inline const Il2CppType* InflateIfNeeded(const Il2CppType* type, const Il2CppGenericContext* context, bool inflateMethodVars)
	{
		if (context == nullptr)
		{
			return type;
		}
		else
		{
			return il2cpp::metadata::GenericMetadata::InflateIfNeeded(type, context, inflateMethodVars);
		}
	}

#pragma region conv

#define CI_conv(dstTypeName, dstReduceType, dstTypeSize)   \
	Add_conv(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertVarVar_i4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_i8_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f8_##dstTypeName);

#define CI_conv_un(dstTypeName, dstReduceType, dstTypeSize)   \
	Add_conv(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertVarVar_u4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_u8_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f8_##dstTypeName);

#define CI_conv_ovf(dstTypeName, dstReduceType, dstTypeSize)   \
	Add_conv_ovf(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertOverflowVarVar_i4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_i8_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f8_##dstTypeName);

#define CI_conv_un_ovf(dstTypeName, dstReduceType, dstTypeSize)   \
	Add_conv_ovf(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertOverflowVarVar_u4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_u8_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f8_##dstTypeName);


#pragma endregion

#pragma region branch

#define CI_branch1(opName) IL2CPP_ASSERT(evalStackTop >= 2); \
brOffset = GetI1(ip+1); \
if (brOffset != 0) \
{\
	Add_bc(ipOffset, brOffset, 2, HiOpcodeEnum::BranchVarVar_##opName##_i4, HiOpcodeEnum::BranchVarVar_##opName##_i8, HiOpcodeEnum::BranchVarVar_##opName##_f4, HiOpcodeEnum::BranchVarVar_##opName##_f8); \
}\
else\
{\
	PopStackN(2);\
}\
ip += 2;

#define CI_branch4(opName) IL2CPP_ASSERT(evalStackTop >= 2); \
brOffset = GetI4LittleEndian(ip + 1); \
if (brOffset != 0) \
{ \
	Add_bc(ipOffset, brOffset, 5, HiOpcodeEnum::BranchVarVar_##opName##_i4, HiOpcodeEnum::BranchVarVar_##opName##_i8, HiOpcodeEnum::BranchVarVar_##opName##_f4, HiOpcodeEnum::BranchVarVar_##opName##_f8); \
}\
else \
{\
	PopStackN(2);\
}\
ip += 5;

#define PopBranch() { \
if (FindNextFlow()) \
{ \
    continue; \
} \
else \
{ \
    goto finish_transform; \
} \
}

#pragma endregion

#pragma region binop
#define CI_binOp(op) Add_binop(HiOpcodeEnum::BinOpVarVarVar_##op##_i4, HiOpcodeEnum::BinOpVarVarVar_##op##_i8, HiOpcodeEnum::BinOpVarVarVar_##op##_f4, HiOpcodeEnum::BinOpVarVarVar_##op##_f8);
#define CI_binOpUn(op) Add_binop(HiOpcodeEnum::BinOpVarVarVar_##op##_i4, HiOpcodeEnum::BinOpVarVarVar_##op##_i8, (HiOpcodeEnum)0, (HiOpcodeEnum)0);
#define CI_binOpOvf(op) Add_binop(HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_i4, HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_i8, (HiOpcodeEnum)0, (HiOpcodeEnum)0);
#define CI_binOpUnOvf(op) Add_binop(HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_u4, HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_u8, (HiOpcodeEnum)0, (HiOpcodeEnum)0);
#pragma endregion

#pragma region shiftop
#define	CI_binOpShift(op) Add_shiftop(HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i4_i4, HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i4_i8, HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i8_i4, HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i8_i8);
#pragma endregion

#define CI_compare(op) Add_compare(HiOpcodeEnum::CompOpVarVarVar_##op##_i4, HiOpcodeEnum::CompOpVarVarVar_##op##_i8, HiOpcodeEnum::CompOpVarVarVar_##op##_f4, HiOpcodeEnum::CompOpVarVarVar_##op##_f8);

#define CI_ldele(eleType, resultType) Add_ldelem(EvalStackReduceDataType::resultType, HiOpcodeEnum::GetArrayElementVarVar_##eleType);
#define CI_stele(eleType) Add_stelem(HiOpcodeEnum::SetArrayElementVarVar_##eleType);

	static const MethodInfo* FindRedirectCreateString(const MethodInfo* shareMethod)
	{
		int32_t paramCount = shareMethod->parameters_count;
		void* iter = nullptr;
		for (const MethodInfo* searchMethod; (searchMethod = il2cpp::vm::Class::GetMethods(il2cpp_defaults.string_class, &iter)) != nullptr;)
		{
			if (searchMethod->parameters_count != paramCount || std::strcmp(searchMethod->name, "CreateString"))
			{
				continue;
			}
			bool sigMatch = true;
			for (uint8_t i = 0; i < paramCount; i++)
			{
				if (!IsTypeEqual(GET_METHOD_PARAMETER_TYPE(searchMethod->parameters[i]), GET_METHOD_PARAMETER_TYPE(shareMethod->parameters[i])))
				{
					sigMatch = false;
					break;
				}
			}
			if (sigMatch)
			{
				return searchMethod;
			}
		}
		return nullptr;
	}

	static bool ShouldBeInlined(const MethodInfo* method, int32_t depth)
	{
		if (depth >= RuntimeConfig::GetMaxMethodInlineDepth())
		{
			return false;
		}
		return metadata::MethodBodyCache::IsInlineable(method);
	}


	void TransformContext::TransformBody(int32_t depth, int32_t localVarOffset, interpreter::InterpMethodInfo& result)
	{
		TransformBodyImpl(depth, localVarOffset);
		BuildInterpMethodInfo(result);
	}

	void TransformContext::TransformBodyImpl(int32_t depth, int32_t localVarOffset)
	{
#pragma region header

		const Il2CppGenericContext* genericContext = methodInfo->is_inflated ? &methodInfo->genericMethod->context : nullptr;
		const Il2CppGenericContainer* klassContainer = GetGenericContainerFromIl2CppType(&methodInfo->klass->byval_arg);
		const Il2CppGenericContainer* methodContainer = methodInfo->is_inflated ?
			(const Il2CppGenericContainer*)methodInfo->genericMethod->methodDefinition->genericContainerHandle :
			(const Il2CppGenericContainer*)methodInfo->genericContainerHandle;

		BasicBlockSpliter bbc(body);
		bbc.SplitBasicBlocks();


		splitOffsets = bbc.GetSplitOffsets();

		ip2bb = pool.NewNAny<IRBasicBlock*>(body.codeSize + 1);
		uint32_t lastSplitBegin = 0;

		for (uint32_t offset : splitOffsets)
		{
			IRBasicBlock* bb = pool.NewAny<IRBasicBlock>();
			bb->visited = false;
			bb->ilOffset = lastSplitBegin;
			irbbs.push_back(bb);
			for (uint32_t idx = lastSplitBegin; idx < offset; idx++)
			{
				ip2bb[idx] = bb;
			}
			lastSplitBegin = offset;
		}
		IRBasicBlock* endBb = pool.NewAny<IRBasicBlock>();
		*endBb = { true, false, body.codeSize, 0 };
		ip2bb[body.codeSize] = endBb;
		irbbs.push_back(endBb);

		curbb = irbbs[0];

		IL2CPP_ASSERT(lastSplitBegin == body.codeSize);

		bool instanceCall = IsInstanceMethod(methodInfo);
		actualParamCount = methodInfo->parameters_count + instanceCall;

		args = pool.NewNAny<ArgVarInfo>(actualParamCount);
		locals = pool.NewNAny<LocVarInfo>((int)body.localVars.size());
		evalStack = pool.NewNAny<EvalStackVarInfo>(body.maxStack + 100);

		nextFlowIdx = 0;

		totalArgSize = 0;
		{
			int32_t idx = 0;
			if (instanceCall)
			{
				ArgVarInfo& self = args[0];
				self.klass = methodInfo->klass;
				self.type = IS_CLASS_VALUE_TYPE(self.klass) ? &self.klass->this_arg : &self.klass->byval_arg;
				self.argOffset = idx;
				self.argLocOffset = localVarOffset + totalArgSize;
				totalArgSize += GetTypeValueStackObjectCount(self.type);
				idx = 1;
			}

			for (uint32_t i = 0; i < methodInfo->parameters_count; i++)
			{
				ArgVarInfo& arg = args[idx + i];
				arg.type = GET_METHOD_PARAMETER_TYPE(methodInfo->parameters[i]);
				arg.klass = il2cpp::vm::Class::FromIl2CppType(arg.type);
				arg.argOffset = idx + i;
				arg.argLocOffset = localVarOffset + totalArgSize;
				il2cpp::vm::Class::SetupFields(arg.klass);
				totalArgSize += GetTypeValueStackObjectCount(arg.type);
			}
		}

		totalArgLocalSize = totalArgSize;
		for (size_t i = 0; i < body.localVars.size(); i++)
		{
			LocVarInfo& local = locals[i];
			local.type = InflateIfNeeded(body.localVars[i], genericContext, true);
			local.klass = il2cpp::vm::Class::FromIl2CppType(local.type);
			il2cpp::vm::Class::SetupFields(local.klass);
			local.locOffset = localVarOffset + totalArgLocalSize;
			totalArgLocalSize += GetTypeValueStackObjectCount(local.type);
		}

		evalStackBaseOffset = localVarOffset + totalArgLocalSize;
		int32_t totalLocalSize = totalArgLocalSize - totalArgSize;

		maxStackSize = evalStackBaseOffset;
		curStackSize = evalStackBaseOffset;



		ipBase = body.ilcodes;
		ip = body.ilcodes;
		ipOffset = 0;

		evalStackTop = 0;
		prefixFlags = 0;

		int32_t argIdx = 0;
		int32_t varKst = 0;
		int64_t varKst8 = 0;
		int32_t brOffset = 0;

		shareMethod = nullptr;

		Token2RuntimeHandleMap tokenCache(64);

		bool inMethodInlining = depth > 0;

		hybridclr::metadata::PDBImage* pdbImage = image->GetPDBImage();
		ir2offsetMap = pdbImage && !inMethodInlining ? new IR2OffsetMap(body.codeSize) : nullptr;

		if (inMethodInlining)
		{
			if (instanceCall)
			{
				if (std::strcmp(methodInfo->name, ".ctor"))
				{
					CreateAddIR(irCheckNull, CheckThrowIfNullVar);
					irCheckNull->obj = args[0].argLocOffset;
				}
			}
			else
			{
				if (!IS_CCTOR_FINISH_OR_NO_CCTOR(methodInfo->klass))
				{
					CreateAddIR(irInitStaticCtor, InitClassStaticCtor);
					irInitStaticCtor->klass = (uint64_t)methodInfo->klass;
				}
			}
		}

		initLocals = (body.flags & (uint32_t)CorILMethodFormat::InitLocals) != 0;
		// init local vars
		if (initLocals && totalLocalSize > 0)
		{
			AddInst(CreateInitLocals(pool, totalLocalSize * sizeof(StackObject), locals[0].locOffset));
		}

		exClauses.resize_initialized(body.exceptionClauses.size());
		int clauseIdx = 0;
		for (ExceptionClause& ec : body.exceptionClauses)
		{
			InterpExceptionClause* iec = &exClauses[clauseIdx++];
			iec->flags = ec.flags;
			iec->tryBeginOffset = ec.tryOffset;
			iec->tryEndOffset = ec.tryOffset + ec.tryLength;
			iec->handlerBeginOffset = ec.handlerOffsets;
			iec->handlerEndOffset = ec.handlerOffsets + ec.handlerLength;
			PushOffset(&iec->tryBeginOffset);
			PushOffset(&iec->tryEndOffset);
			PushOffset(&iec->handlerBeginOffset);
			PushOffset(&iec->handlerEndOffset);
			if (ec.flags == CorILExceptionClauseType::Exception)
			{
				iec->filterBeginOffset = 0;
				iec->exKlass = image->GetClassFromToken(tokenCache, ec.classTokenOrFilterOffset, klassContainer, methodContainer, genericContext);
			}
			else if (ec.flags == CorILExceptionClauseType::Filter)
			{
				iec->filterBeginOffset = ec.classTokenOrFilterOffset;
				PushOffset(&iec->filterBeginOffset);
				iec->exKlass = nullptr;
			}
			else
			{
				IL2CPP_ASSERT(ec.classTokenOrFilterOffset == 0);
				iec->filterBeginOffset = 0;
				iec->exKlass = nullptr;
			}

			switch (ec.flags)
			{
			case CorILExceptionClauseType::Exception:
			{
				IRBasicBlock* bb = ip2bb[iec->handlerBeginOffset];
				IL2CPP_ASSERT(!bb->inPending);
				bb->inPending = true;
				FlowInfo* fi = pool.NewAny<FlowInfo>();
				fi->offset = ec.handlerOffsets;
				fi->curStackSize = evalStackBaseOffset + 1;
				fi->evalStack.push_back({ NATIVE_INT_REDUCE_TYPE, PTR_SIZE, evalStackBaseOffset });
				pendingFlows.push_back(fi);
				break;
			}
			case CorILExceptionClauseType::Filter:
			{
				IRBasicBlock* bb = ip2bb[iec->filterBeginOffset];
				IL2CPP_ASSERT(!bb->inPending);
				bb->inPending = true;
				{
					FlowInfo* fi = pool.NewAny<FlowInfo>();
					IL2CPP_ASSERT(ec.classTokenOrFilterOffset);
					fi->offset = ec.classTokenOrFilterOffset;
					fi->curStackSize = evalStackBaseOffset + 1;
					fi->evalStack.push_back({ NATIVE_INT_REDUCE_TYPE, PTR_SIZE, evalStackBaseOffset });
					pendingFlows.push_back(fi);
				}
				{
					FlowInfo* fi = pool.NewAny<FlowInfo>();
					IL2CPP_ASSERT(ec.handlerOffsets);
					fi->offset = ec.handlerOffsets;
					fi->curStackSize = evalStackBaseOffset + 1;
					fi->evalStack.push_back({ NATIVE_INT_REDUCE_TYPE, PTR_SIZE, evalStackBaseOffset });
					pendingFlows.push_back(fi);
				}

				break;
			}
			case CorILExceptionClauseType::Fault:
			case CorILExceptionClauseType::Finally:
			{
				IRBasicBlock* bb = ip2bb[iec->handlerBeginOffset];
				IL2CPP_ASSERT(!bb->inPending);
				bb->inPending = true;
				FlowInfo* fi = pool.NewAny<FlowInfo>();
				fi->offset = ec.handlerOffsets;
				fi->curStackSize = evalStackBaseOffset;
				pendingFlows.push_back(fi);
				break;
			}
			default:
			{
				RaiseExecutionEngineException("");
			}
			}
		}

#pragma endregion

		IRBasicBlock* lastBb = nullptr;
		for (;;)
		{
			ipOffset = (uint32_t)(ip - ipBase);
			curbb = ip2bb[ipOffset];
			if (curbb != lastBb)
			{
				if (curbb && !curbb->visited)
				{
					curbb->visited = true;
					lastBb = curbb;
				}
				else
				{
					PopBranch();
				}
			}

			switch ((OpcodeValue)*ip)
			{
			case OpcodeValue::NOP:
			{
				ip++;
				continue;
			}
			case OpcodeValue::BREAK:
			{
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_0:
			{
				AddInst_ldarg(0);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_1:
			{
				AddInst_ldarg(1);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_2:
			{
				AddInst_ldarg(2);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_3:
			{
				AddInst_ldarg(3);
				ip++;
				continue;
			}

			case OpcodeValue::LDLOC_0:
			{
				CreateAddInst_ldloc(0);
				ip++;
				continue;
			}
			case OpcodeValue::LDLOC_1:
			{
				CreateAddInst_ldloc(1);
				ip++;
				continue;
			}
			case OpcodeValue::LDLOC_2:
			{
				CreateAddInst_ldloc(2);
				ip++;
				continue;
			}
			case OpcodeValue::LDLOC_3:
			{
				CreateAddInst_ldloc(3);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_0:
			{
				CreateAddInst_stloc(0);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_1:
			{
				CreateAddInst_stloc(1);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_2:
			{
				CreateAddInst_stloc(2);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_3:
			{
				CreateAddInst_stloc(3);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_S:
			{
				argIdx = ip[1];
				AddInst_ldarg(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDARGA_S:
			{
				argIdx = ip[1];
				AddInst_ldarga(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::STARG_S:
			{
				argIdx = ip[1];
				AddInst_starg(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDLOC_S:
			{
				argIdx = ip[1];
				CreateAddInst_ldloc(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDLOCA_S:
			{
				argIdx = ip[1];
				CreateAddInst_ldloca(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::STLOC_S:
			{
				argIdx = ip[1];
				CreateAddInst_stloc(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDNULL:
			{
				CreateAddIR(ir, LdnullVar);
				ir->dst = curStackSize;
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_M1:
			{
				CreateAddInst_ldc4(-1, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_0:
			{
				CreateAddInst_ldc4(0, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_1:
			{
				CreateAddInst_ldc4(1, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_2:
			{
				CreateAddInst_ldc4(2, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_3:
			{
				CreateAddInst_ldc4(3, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_4:
			{
				CreateAddInst_ldc4(4, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_5:
			{
				CreateAddInst_ldc4(5, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_6:
			{
				CreateAddInst_ldc4(6, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_7:
			{
				CreateAddInst_ldc4(7, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_8:
			{
				CreateAddInst_ldc4(8, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_S:
			{
				varKst = GetI1(ip + 1);
				CreateAddInst_ldc4(varKst, EvalStackReduceDataType::I4);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDC_I4:
			{
				varKst = GetI4LittleEndian(ip + 1);
				CreateAddInst_ldc4(varKst, EvalStackReduceDataType::I4);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDC_I8:
			{
				varKst8 = GetI8LittleEndian(ip + 1);
				CreateAddInst_ldc8(varKst8, EvalStackReduceDataType::I8);
				ip += 9;
				continue;
			}
			case OpcodeValue::LDC_R4:
			{
				varKst = GetI4LittleEndian(ip + 1);
				CreateAddInst_ldc4(varKst, EvalStackReduceDataType::R4);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDC_R8:
			{
				varKst8 = GetI8LittleEndian(ip + 1);
				CreateAddInst_ldc8(varKst8, EvalStackReduceDataType::R8);
				ip += 9;
				continue;
			}
			case OpcodeValue::DUP:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& __eval = evalStack[evalStackTop - 1];
				IRCommon* ir = CreateAssignVarVar(pool, GetEvalStackNewTopOffset(), __eval.locOffset, __eval.byteSize);
				AddInst(ir);
				DuplicateStack();
				ip++;
				continue;
			}
			case OpcodeValue::POP:
			{
				PopStack();
				ip++;
				continue;
			}
			case OpcodeValue::JMP:
			{
				/*  auto& x = ir.jump;
					x.type = IRType::Jmp;
					x.methodToken = GetI4LittleEndian(ip + 1);
					irs.push_back(ir);
					ip += 5;*/
				RaiseNotSupportedException("not support jmp");
				continue;
			}
			case OpcodeValue::CALL:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				ip += 5;
				shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(shareMethod);
			}

		LabelCall:
			{
				if (TryAddInstinctInstruments(shareMethod))
				{
					continue;
				}

#if HYBRIDCLR_UNITY_2021_OR_NEW
				if (!shareMethod->has_full_generic_sharing_signature)
#endif
				{
					if (!InitAndGetInterpreterDirectlyCallMethodPointer(shareMethod))
					{
						RaiseAOTGenericMethodNotInstantiatedException(shareMethod);
					}
				}

				bool resolvedIsInstanceMethod = IsInstanceMethod(shareMethod);
				int32_t resolvedTotalArgNum = shareMethod->parameters_count + resolvedIsInstanceMethod;
				int32_t needDataSlotNum = (resolvedTotalArgNum + 3) / 4;
				int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgNum;
				uint32_t methodDataIndex = GetOrAddResolveDataIndex(shareMethod);

				if (hybridclr::metadata::IsInterpreterImplement(shareMethod))
				{
					uint16_t argBaseOffset = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);

					if (ShouldBeInlined(shareMethod, depth) && TransformSubMethodBody(*this, shareMethod, depth + 1, argBaseOffset))
					{

					}
					else
					{
						if (IsReturnVoidMethod(shareMethod))
						{
							CreateAddIR(ir, CallInterp_void);
							ir->methodInfo = methodDataIndex;
							ir->argBase = argBaseOffset;
						}
						else
						{
							CreateAddIR(ir, CallInterp_ret);
							ir->methodInfo = methodDataIndex;
							ir->argBase = argBaseOffset;
							ir->ret = argBaseOffset;
						}
					}
					PopStackN(resolvedTotalArgNum);
					if (!IsReturnVoidMethod(shareMethod))
					{
						PushStackByType(shareMethod->return_type);
					}
					continue;
				}
#if HYBRIDCLR_UNITY_2021_OR_NEW
				if (!shareMethod->has_full_generic_sharing_signature)
#endif
				{
					if (TryAddCallCommonInstruments(shareMethod, methodDataIndex))
					{
						continue;
					}
				}



				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex((void*)managed2NativeMethod);

				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);

				if (resolvedIsInstanceMethod)
				{
					__argIdxs[0] = GetEvalStackOffset(callArgEvalStackIdxBase);
				}

				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + resolvedIsInstanceMethod;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				PopStackN(resolvedTotalArgNum);

				if (!IsReturnVoidMethod(shareMethod))
				{
					PushStackByType(shareMethod->return_type);
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(shareMethod->return_type);
					if (interpreter::IsNeedExpandLocationType(locDataType))
					{
						CreateAddIR(ir, CallNativeInstance_ret_expand);
						ir->type = resolvedIsInstanceMethod ? HiOpcodeEnum::CallNativeInstance_ret_expand : HiOpcodeEnum::CallNativeStatic_ret_expand;
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = GetEvalStackTopOffset();
						ir->retLocationType = (uint8_t)locDataType;
					}
					else
					{
						CreateAddIR(ir, CallNativeInstance_ret);
						ir->type = resolvedIsInstanceMethod ? HiOpcodeEnum::CallNativeInstance_ret : HiOpcodeEnum::CallNativeStatic_ret;
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = GetEvalStackTopOffset();
					}
				}
				else
				{
					CreateAddIR(ir, CallNativeInstance_void);
					ir->type = resolvedIsInstanceMethod ? HiOpcodeEnum::CallNativeInstance_void : HiOpcodeEnum::CallNativeStatic_void;
					ir->managed2NativeMethod = managed2NativeMethodDataIdx;
					ir->methodInfo = methodDataIndex;
					ir->argIdxs = argIdxDataIndex;
				}
				continue;
			}
			case OpcodeValue::CALLVIRT:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				ip += 5;
				shareMethod = image->GetMethodInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
			}
		LabelCallVir:
			{
				IL2CPP_ASSERT(shareMethod);
				IL2CPP_ASSERT(hybridclr::metadata::IsInstanceMethod(shareMethod));
				if ((!metadata::IsVirtualMethod(shareMethod->flags)) || metadata::IsSealed(shareMethod->flags))
				{
					goto LabelCall;
				}

				int32_t resolvedTotalArgNum = shareMethod->parameters_count + 1;
				int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgNum;
				uint32_t methodDataIndex = GetOrAddResolveDataIndex(shareMethod);

				bool isMultiDelegate = IsChildTypeOfMulticastDelegate(shareMethod->klass);
				if (!isMultiDelegate && IsInterpreterMethod(shareMethod) && !IsInterface(shareMethod->klass->flags))
				{
					PopStackN(resolvedTotalArgNum);

					uint16_t argBaseOffset = (uint16_t)GetEvalStackOffset(callArgEvalStackIdxBase);
					if (IsReturnVoidMethod(shareMethod))
					{
						CreateAddIR(ir, CallInterpVirtual_void);
						ir->method = methodDataIndex;
						ir->argBase = argBaseOffset;
					}
					else
					{
						CreateAddIR(ir, CallInterpVirtual_ret);
						ir->method = methodDataIndex;
						ir->argBase = argBaseOffset;
						ir->ret = argBaseOffset;
						PushStackByType(shareMethod->return_type);
					}
					continue;
				}

				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex((void*)managed2NativeMethod);


				int32_t needDataSlotNum = (resolvedTotalArgNum + 3) / 4;
				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);

				__argIdxs[0] = GetEvalStackOffset(callArgEvalStackIdxBase);
				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + 1;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				PopStackN(resolvedTotalArgNum);

				const Il2CppType* returnType = shareMethod->return_type;
				int32_t retIdx;

				if (returnType->type != IL2CPP_TYPE_VOID)
				{
					PushStackByType(returnType);
					retIdx = GetEvalStackTopOffset();
				}
				else
				{
					retIdx = -1;
				}
				if (isMultiDelegate)
				{
					if (std::strcmp(shareMethod->name, "Invoke") == 0)
					{
						Managed2NativeCallMethod staticManaged2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, true);
						IL2CPP_ASSERT(staticManaged2NativeMethod);
						uint32_t staticManaged2NativeMethodDataIdx = GetOrAddResolveDataIndex((void*)staticManaged2NativeMethod);
						if (retIdx < 0)
						{
							CreateAddIR(ir, CallDelegateInvoke_void);
							ir->managed2NativeStaticMethod = staticManaged2NativeMethodDataIdx;
							ir->managed2NativeInstanceMethod = managed2NativeMethodDataIdx;
							ir->argIdxs = argIdxDataIndex;
							ir->invokeParamCount = shareMethod->parameters_count;
						}
						else
						{
							interpreter::TypeDesc retDesc = GetTypeArgDesc(returnType);
							if (IsNeedExpandLocationType(retDesc.type))
							{
								CreateAddIR(ir, CallDelegateInvoke_ret_expand);
								ir->managed2NativeStaticMethod = staticManaged2NativeMethodDataIdx;
								ir->managed2NativeInstanceMethod = managed2NativeMethodDataIdx;
								ir->argIdxs = argIdxDataIndex;
								ir->ret = retIdx;
								ir->invokeParamCount = shareMethod->parameters_count;
								ir->retLocationType = (uint8_t)retDesc.type;
							}
							else
							{
								CreateAddIR(ir, CallDelegateInvoke_ret);
								ir->managed2NativeStaticMethod = staticManaged2NativeMethodDataIdx;
								ir->managed2NativeInstanceMethod = managed2NativeMethodDataIdx;
								ir->argIdxs = argIdxDataIndex;
								ir->ret = retIdx;
								ir->retTypeStackObjectSize = retDesc.stackObjectSize;
								ir->invokeParamCount = shareMethod->parameters_count;
							}
						}
						continue;
					}
					Il2CppMethodPointer directlyCallMethodPointer = InitAndGetInterpreterDirectlyCallMethodPointer(shareMethod);
					if (std::strcmp(shareMethod->name, "BeginInvoke") == 0)
					{
						if (IsInterpreterMethod(shareMethod) || directlyCallMethodPointer == nullptr)
						{
							CreateAddIR(ir, CallDelegateBeginInvoke);
							ir->methodInfo = methodDataIndex;
							ir->result = retIdx;
							ir->argIdxs = argIdxDataIndex;
							continue;
						}
					}
					else if (std::strcmp(shareMethod->name, "EndInvoke") == 0)
					{
						if (IsInterpreterMethod(shareMethod) || directlyCallMethodPointer == nullptr)
						{
							if (retIdx < 0)
							{
								CreateAddIR(ir, CallDelegateEndInvoke_void);
								ir->methodInfo = methodDataIndex;
								ir->asyncResult = __argIdxs[1];
							}
							else
							{
								CreateAddIR(ir, CallDelegateEndInvoke_ret);
								ir->methodInfo = methodDataIndex;
								ir->asyncResult = __argIdxs[1];
								ir->ret = retIdx;
							}
							continue;
						}
					}
				}

				if (retIdx < 0)
				{
					CreateAddIR(ir, CallVirtual_void);
					ir->managed2NativeMethod = managed2NativeMethodDataIdx;
					ir->methodInfo = methodDataIndex;
					ir->argIdxs = argIdxDataIndex;
				}
				else
				{
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(returnType);
					if (IsNeedExpandLocationType(locDataType))
					{
						CreateAddIR(ir, CallVirtual_ret_expand);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = retIdx;
						ir->retLocationType = (uint8_t)locDataType;
					}
					else
					{
						CreateAddIR(ir, CallVirtual_ret);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = retIdx;
					}
				}
				continue;
			}
			case OpcodeValue::CALLI:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);

				ResolveStandAloneMethodSig methodSig;
				image->GetStandAloneMethodSigFromToken(token, klassContainer, methodContainer, genericContext, methodSig);
				if (IsPrologExplicitThis(methodSig.flags))
				{
					RaiseNotSupportedException("not support StandAloneMethodSig flags:EXPLICITTHIS");
				}

				int32_t methodIdx = GetEvalStackTopOffset();
				//uint32_t methodDataIndex = GetOrAddResolveDataIndex(shareMethod);
				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(methodSig);
				Managed2NativeFunctionPointerCallMethod managed2NativeFunctionPointerMethod = InterpreterModule::GetManaged2NativeFunctionPointerMethodPointer(methodSig);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex((void*)managed2NativeMethod);
				uint32_t managed2NativeFunctionPointerMethodDataIdx = GetOrAddResolveDataIndex((void*)managed2NativeFunctionPointerMethod);
				bool hasThis = metadata::IsPrologHasThis(methodSig.flags);

				int32_t resolvedTotalArgNum = (int32_t)methodSig.params.size() + hasThis;
				int32_t needDataSlotNum = (resolvedTotalArgNum + 3) / 4;
				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;

				// we need at least one slot for argBasePtr when resolvedTotalArgNum == 0
				AllocResolvedData(resolveDatas, std::max(needDataSlotNum, 1), argIdxDataIndex, __argIdxs);

				int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgNum - 1 /*funtion ptr*/;

				// CallInd need know the argBasePtr when resolvedTotalArgNum == 0
				if (needDataSlotNum == 0)
				{
					__argIdxs[0] = evalStack[callArgEvalStackIdxBase].locOffset;
				}

				if (hasThis)
				{
					__argIdxs[0] = evalStack[callArgEvalStackIdxBase].locOffset;
				}

				for (size_t i = 0; i < methodSig.params.size(); i++)
				{
					size_t curArgIdx = i + hasThis;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				PopStackN(resolvedTotalArgNum + 1);

				if (!IsVoidType(methodSig.returnType))
				{
					PushStackByType(methodSig.returnType);
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(methodSig.returnType);
					if (interpreter::IsNeedExpandLocationType(locDataType))
					{
						CreateAddIR(ir, CallInd_ret_expand);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->managed2NativeFunctionPointerMethod = managed2NativeFunctionPointerMethodDataIdx;
						ir->methodInfo = methodIdx;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = GetEvalStackTopOffset();
						ir->retLocationType = (uint8_t)locDataType;
					}
					else
					{
						CreateAddIR(ir, CallInd_ret);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->managed2NativeFunctionPointerMethod = managed2NativeFunctionPointerMethodDataIdx;
						ir->methodInfo = methodIdx;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = GetEvalStackTopOffset();
					}
				}
				else
				{
					CreateAddIR(ir, CallInd_void);
					ir->managed2NativeMethod = managed2NativeMethodDataIdx;
					ir->managed2NativeFunctionPointerMethod = managed2NativeFunctionPointerMethodDataIdx;
					ir->methodInfo = methodIdx;
					ir->argIdxs = argIdxDataIndex;
				}

				ip += 5;
				continue;
			}
			case OpcodeValue::RET:
			{
				bool isVoidReturnType = methodInfo->return_type->type == IL2CPP_TYPE_VOID;
				if (inMethodInlining)
				{
					if (!isVoidReturnType)
					{
						uint16_t retVarIdx = GetEvalStackTopOffset();
						if (retVarIdx != localVarOffset)
						{
							IRCommon* ir = CreateAssignVarVar(pool, localVarOffset, retVarIdx, GetTypeValueSize(methodInfo->return_type));
							AddInst(ir);
						}
					}
				}
				else if (isVoidReturnType)
				{
					CreateAddIR(ir, RetVar_void);
				}
				else
				{
					// ms.ret = nullptr;
					IL2CPP_ASSERT(evalStackTop == 1);
					int32_t size = GetTypeValueSize(methodInfo->return_type);
					switch (size)
					{
					case 1:
					{
						CreateAddIR(ir, RetVar_ret_1);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 2:
					{
						CreateAddIR(ir, RetVar_ret_2);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 4:
					{
						CreateAddIR(ir, RetVar_ret_4);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 8:
					{
						CreateAddIR(ir, RetVar_ret_8);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 12:
					{
						CreateAddIR(ir, RetVar_ret_12);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 16:
					{
						CreateAddIR(ir, RetVar_ret_16);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 20:
					{
						CreateAddIR(ir, RetVar_ret_20);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 24:
					{
						CreateAddIR(ir, RetVar_ret_24);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 28:
					{
						CreateAddIR(ir, RetVar_ret_28);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					case 32:
					{
						CreateAddIR(ir, RetVar_ret_32);
						ir->ret = GetEvalStackTopOffset();
						break;
					}
					default:
					{
						CreateAddIR(ir, RetVar_ret_n);
						ir->ret = GetEvalStackTopOffset();
						ir->size = size;
						break;
					}
					}
				}
				ip++;
				PopBranch();
				continue;
			}
			case OpcodeValue::BR_S:
			{
				brOffset = GetI1(ip + 1);
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 2;
					CreateAddIR(ir, BranchUncondition_4);
					ir->offset = targetOffset;
					PushOffset(&ir->offset);

					PushBranch(targetOffset);
					PopBranch();
				}
				else
				{
					ip += 2;
				}
				continue;
			}
			case OpcodeValue::LEAVE_S:
			{
				brOffset = GetI1(ip + 1);
				int32_t targetOffset = ipOffset + brOffset + 2;
				Add_leave((uint32_t)targetOffset);
				PopBranch();
				continue;
			}
			case OpcodeValue::BRFALSE_S:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI1(ip + 1);
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 2;
					Add_brtruefalse(false, targetOffset);
				}
				else
				{
					PopStack();
				}
				ip += 2;
				continue;
			}
			case OpcodeValue::BRTRUE_S:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI1(ip + 1);
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 2;
					Add_brtruefalse(true, targetOffset);
				}
				else
				{
					PopStack();
				}
				ip += 2;
				continue;
			}
			case OpcodeValue::BEQ_S:
			{
				CI_branch1(Ceq);
				continue;
			}
			case OpcodeValue::BGE_S:
			{
				CI_branch1(Cge);
				continue;
			}
			case OpcodeValue::BGT_S:
			{
				CI_branch1(Cgt);
				continue;
			}
			case OpcodeValue::BLE_S:
			{
				CI_branch1(Cle);
				continue;
			}
			case OpcodeValue::BLT_S:
			{
				CI_branch1(Clt);
				continue;
			}
			case OpcodeValue::BNE_UN_S:
			{
				CI_branch1(CneUn);
				continue;
			}
			case OpcodeValue::BGE_UN_S:
			{
				CI_branch1(CgeUn);
				continue;
			}
			case OpcodeValue::BGT_UN_S:
			{
				CI_branch1(CgtUn);
				continue;
			}
			case OpcodeValue::BLE_UN_S:
			{
				CI_branch1(CleUn);
				continue;
			}
			case OpcodeValue::BLT_UN_S:
			{
				CI_branch1(CltUn);
				continue;
			}
			case OpcodeValue::BR:
			{
				brOffset = GetI4LittleEndian(ip + 1);
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 5;
					CreateAddIR(ir, BranchUncondition_4);
					ir->offset = targetOffset;
					PushOffset(&ir->offset);

					PushBranch(targetOffset);
					PopBranch();
				}
				else
				{
					ip += 5;
				}
				continue;
			}
			case OpcodeValue::LEAVE:
			{
				brOffset = GetI4LittleEndian(ip + 1);
				int32_t targetOffset = ipOffset + brOffset + 5;
				Add_leave((uint32_t)targetOffset);
				PopBranch();
				continue;
			}
			case OpcodeValue::BRFALSE:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI4LittleEndian(ip + 1);
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 5;
					Add_brtruefalse(false, targetOffset);
				}
				else
				{
					PopStack();
				}
				ip += 5;
				continue;
			}
			case OpcodeValue::BRTRUE:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI4LittleEndian(ip + 1);
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 5;
					Add_brtruefalse(true, targetOffset);
				}
				else
				{
					PopStack();
				}
				ip += 5;
				continue;
			}

			case OpcodeValue::BEQ:
			{
				CI_branch4(Ceq);
				continue;
			}
			case OpcodeValue::BGE:
			{
				CI_branch4(Cge);
				continue;
			}
			case OpcodeValue::BGT:
			{
				CI_branch4(Cgt);
				continue;
			}
			case OpcodeValue::BLE:
			{
				CI_branch4(Cle);
				continue;
			}
			case OpcodeValue::BLT:
			{
				CI_branch4(Clt);
				continue;
			}
			case OpcodeValue::BNE_UN:
			{
				CI_branch4(CneUn);
				continue;
			}
			case OpcodeValue::BGE_UN:
			{
				CI_branch4(CgeUn);
				continue;
			}
			case OpcodeValue::BGT_UN:
			{
				CI_branch4(CgtUn);
				continue;
			}
			case OpcodeValue::BLE_UN:
			{
				CI_branch4(CleUn);
				continue;
			}
			case OpcodeValue::BLT_UN:
			{
				CI_branch4(CltUn);
				continue;
			}
			case OpcodeValue::SWITCH:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				CreateIR(ir, BranchSwitch);

				uint32_t switchValue = GetEvalStackTopOffset();
				uint32_t n = (uint32_t)GetI4LittleEndian(ip + 1);
				ir->value = GetEvalStackTopOffset();
				ir->caseNum = n;

				int32_t* caseOffsets;
				AllocResolvedData(resolveDatas, (n + 1) / 2, *(int32_t*)&ir->caseOffsets, caseOffsets);
				PopStack();

				uint32_t instrSize = 1 + (n + 1) * 4;
				const byte* caseOffsetIp = ip + 5;

				// remove this instrument if all target is same to default.
				uint32_t nextInstrumentOffset = ipOffset + instrSize;
				bool anyNotDefaultCase = false;
				for (uint32_t caseIdx = 0; caseIdx < n; caseIdx++)
				{
					int32_t targetOffset = (int32_t)(nextInstrumentOffset + GetI4LittleEndian(caseOffsetIp + caseIdx * 4));
					caseOffsets[caseIdx] = targetOffset;
					//PushOffset(caseOffsets + caseIdx);
					if (targetOffset != nextInstrumentOffset)
					{
						anyNotDefaultCase = true;
						PushBranch(targetOffset);
					}
				}
				if (anyNotDefaultCase)
				{
					switchOffsetsInResolveData.push_back({ ir->caseOffsets, n });
					AddInst(ir);
				}
				ip += instrSize;
				continue;
			}
			case OpcodeValue::LDIND_I1:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_i1, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_U1:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_u1, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_I2:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_i2, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_U2:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_u2, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_I4:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_i4, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_U4:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_u4, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_I8:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_i8, EvalStackReduceDataType::I8);
				continue;
			}
			case OpcodeValue::LDIND_I:
			{
				Add_ldind(ARCH_ARGUMENT(HiOpcodeEnum::LdindVarVar_i4, HiOpcodeEnum::LdindVarVar_i8), NATIVE_INT_REDUCE_TYPE);
				continue;
			}
			case OpcodeValue::LDIND_R4:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_f4, EvalStackReduceDataType::R4);
				continue;
			}
			case OpcodeValue::LDIND_R8:
			{
				Add_ldind(HiOpcodeEnum::LdindVarVar_f8, EvalStackReduceDataType::R8);
				continue;
			}
			case OpcodeValue::LDIND_REF:
			{
				Add_ldind(ARCH_ARGUMENT(HiOpcodeEnum::LdindVarVar_i4, HiOpcodeEnum::LdindVarVar_i8), NATIVE_INT_REDUCE_TYPE);
				continue;
			}
			case OpcodeValue::STIND_REF:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_ref);
				continue;
			}
			case OpcodeValue::STIND_I1:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_i1);
				continue;
			}
			case OpcodeValue::STIND_I2:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_i2);
				continue;
			}
			case OpcodeValue::STIND_I4:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_i4);
				continue;
			}
			case OpcodeValue::STIND_I8:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_i8);
				continue;
			}
			case OpcodeValue::STIND_R4:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_f4);
				continue;
			}
			case OpcodeValue::STIND_R8:
			{
				Add_stind(HiOpcodeEnum::StindVarVar_f8);
				continue;
			}
			case OpcodeValue::ADD:
			{
				CI_binOp(Add);
				continue;
			}
			case OpcodeValue::SUB:
			{
				CI_binOp(Sub);
				continue;
			}
			case OpcodeValue::MUL:
			{
				CI_binOp(Mul);
				continue;
			}
			case OpcodeValue::DIV:
			{
				CI_binOp(Div);
				continue;
			}
			case OpcodeValue::DIV_UN:
			{
				CI_binOpUn(DivUn);
				continue;
			}
			case OpcodeValue::REM:
			{
				CI_binOp(Rem);
				continue;
			}
			case OpcodeValue::REM_UN:
			{
				CI_binOpUn(RemUn);
				continue;
			}
			case OpcodeValue::AND:
			{
				CI_binOpUn(And);
				continue;
			}
			case OpcodeValue::OR:
			{
				CI_binOpUn(Or);
				continue;
			}
			case OpcodeValue::XOR:
			{
				CI_binOpUn(Xor);
				continue;
			}
			case OpcodeValue::SHL:
			{
				CI_binOpShift(Shl);
				continue;
			}
			case OpcodeValue::SHR:
			{
				CI_binOpShift(Shr);
				continue;
			}
			case OpcodeValue::SHR_UN:
			{
				CI_binOpShift(ShrUn);
				continue;
			}
			case OpcodeValue::NEG:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& op = evalStack[evalStackTop - 1];
				CreateAddIR(ir, UnaryOpVarVar_Neg_i4);
				ir->dst = ir->src = op.locOffset;

				switch (op.reduceType)
				{
				case EvalStackReduceDataType::I4:
				{
					ir->type = HiOpcodeEnum::UnaryOpVarVar_Neg_i4;
					break;
				}
				case EvalStackReduceDataType::I8:
				{
					ir->type = HiOpcodeEnum::UnaryOpVarVar_Neg_i8;
					break;
				}
				case EvalStackReduceDataType::R4:
				{
					ir->type = HiOpcodeEnum::UnaryOpVarVar_Neg_f4;
					break;
				}
				case EvalStackReduceDataType::R8:
				{
					ir->type = HiOpcodeEnum::UnaryOpVarVar_Neg_f8;
					break;
				}
				default:
				{
					RaiseExecutionEngineException("NEG not suppport type");
					break;
				}
				}
				ip++;
				continue;
			}
			case OpcodeValue::NOT:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& op = evalStack[evalStackTop - 1];
				CreateAddIR(ir, UnaryOpVarVar_Not_i4);
				ir->dst = ir->src = op.locOffset;

				switch (op.reduceType)
				{
				case EvalStackReduceDataType::I4:
				{
					ir->type = HiOpcodeEnum::UnaryOpVarVar_Not_i4;
					break;
				}
				case EvalStackReduceDataType::I8:
				{
					ir->type = HiOpcodeEnum::UnaryOpVarVar_Not_i8;
					break;
				}
				default:
				{
					RaiseExecutionEngineException("NOT not suppport type");
					break;
				}
				}
				ip++;
				continue;
			}
			case OpcodeValue::CONV_I1:
			{
				CI_conv(i1, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_I2:
			{
				CI_conv(i2, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_I4:
			{
				CI_conv(i4, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_I8:
			{
				CI_conv(i8, I8, 8);
				continue;
			}
			case OpcodeValue::CONV_R4:
			{
				CI_conv(f4, R4, 4);
				continue;
			}
			case OpcodeValue::CONV_R8:
			{
				CI_conv(f8, R8, 8);
				continue;
			}
			case OpcodeValue::CONV_U4:
			{
				CI_conv(u4, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_U8:
			{
				CI_conv(u8, I8, 8);
				continue;
			}
			case OpcodeValue::CPOBJ:
			{
				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& dst = evalStack[evalStackTop - 2];
				EvalStackVarInfo& src = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);
				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					uint32_t size = GetTypeValueSize(objKlass);
					if (!HYBRIDCLR_ENABLE_WRITE_BARRIERS || !objKlass->has_references)
					{
						switch (size)
						{
						case 1:
						{
							CreateAddIR(ir, CpobjVarVar_1);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 2:
						{
							CreateAddIR(ir, CpobjVarVar_2);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 4:
						{
							CreateAddIR(ir, CpobjVarVar_4);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 8:
						{
							CreateAddIR(ir, CpobjVarVar_8);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 12:
						{
							CreateAddIR(ir, CpobjVarVar_12);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 16:
						{
							CreateAddIR(ir, CpobjVarVar_16);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						default:
						{
							CreateAddIR(ir, CpobjVarVar_n_4);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							ir->size = size;
							break;
						}
						}
					}
					else
					{
						CreateAddIR(ir, CpobjVarVar_WriteBarrier_n_4);
						ir->dst = dst.locOffset;
						ir->src = src.locOffset;
						ir->size = size;
					}
				}
				else
				{
					CreateAddIR(ir, CpobjVarVar_ref);
					ir->dst = dst.locOffset;
					ir->src = src.locOffset;
				}

				PopStackN(2);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDOBJ:
			{
				IL2CPP_ASSERT(evalStackTop >= 1);
				EvalStackVarInfo& top = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);
				LocationDescInfo desc = ComputLocationDescInfo(&objKlass->byval_arg);

				switch (desc.type)
				{
				case LocationDescType::I1:
				{
					CreateAddIR(ir, LdindVarVar_i1);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::U1:
				{
					CreateAddIR(ir, LdindVarVar_u1);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::I2:
				{
					CreateAddIR(ir, LdindVarVar_i2);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::U2:
				{
					CreateAddIR(ir, LdindVarVar_u2);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::I4:
				{
					CreateAddIR(ir, LdindVarVar_i4);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::I8:
				{
					CreateAddIR(ir, LdindVarVar_i8);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::Ref:
				{
					CreateAddIR(ir, LdobjVarVar_ref);
					ir->dst = ir->src = top.locOffset;
					break;
				}
				case LocationDescType::S:
				case LocationDescType::StructContainsRef:
				{
					uint32_t size = GetTypeValueSize(objKlass);
					switch (size)
					{
					case 1:
					{
						CreateAddIR(ir, LdobjVarVar_1);
						ir->dst = ir->src = top.locOffset;
						break;
					}
					case 2:
					{
						CreateAddIR(ir, LdobjVarVar_2);
						ir->dst = ir->src = top.locOffset;
						break;
					}
					case 4:
					{
						CreateAddIR(ir, LdobjVarVar_4);
						ir->dst = ir->src = top.locOffset;
						break;
					}
					case 8:
					{
						CreateAddIR(ir, LdobjVarVar_8);
						ir->dst = ir->src = top.locOffset;
						break;
					}
					case 12:
					{
						CreateAddIR(ir, LdobjVarVar_12);
						ir->dst = ir->src = top.locOffset;
						break;
					}
					case 16:
					{
						CreateAddIR(ir, LdobjVarVar_16);
						ir->dst = ir->src = top.locOffset;
						break;
					}
					default:
					{
						CreateAddIR(ir, LdobjVarVar_n_4);
						ir->dst = ir->src = top.locOffset;
						ir->size = size;
						break;
					}
					}
					break;
				}
				default:
				{
					RaiseExecutionEngineException("field");
				}
				}

				PopStack();
				PushStackByType(&objKlass->byval_arg);
				InsertMemoryBarrier();
				ResetPrefixFlags();
				ip += 5;
				continue;
			}
			case OpcodeValue::LDSTR:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppString* str = image->GetIl2CppUserStringFromRawIndex(DecodeTokenRowIndex(token));
				uint32_t dataIdx = GetOrAddResolveDataIndex(str);

				CreateAddIR(ir, LdstrVar);
				ir->dst = GetEvalStackNewTopOffset();
				ir->str = dataIdx;
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::NEWOBJ:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				ip += 5;
				// TODO token cache optimistic
				shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(shareMethod);
				IL2CPP_ASSERT(!std::strcmp(shareMethod->name, ".ctor"));
				IL2CPP_ASSERT(hybridclr::metadata::IsInstanceMethod(shareMethod));
				if (TryAddInstinctCtorInstruments(shareMethod))
				{
					continue;
				}
				Il2CppClass* klass = shareMethod->klass;
				uint8_t paramCount = shareMethod->parameters_count;
				if (klass == il2cpp_defaults.string_class)
				{
					const MethodInfo* searchMethod = FindRedirectCreateString(shareMethod);
					if (searchMethod)
					{
						// insert nullptr to eval stack
						int32_t thisIdx = evalStackTop - paramCount;
						for (int32_t i = evalStackTop; i > thisIdx; i--)
						{
							evalStack[i] = evalStack[i - 1];
						}
						// locOffset of this is not important. You only need make sure the value is not equal to nullptr.
						evalStack[thisIdx] = { NATIVE_INT_REDUCE_TYPE, PTR_SIZE, GetEvalStackOffset(thisIdx) };
						++evalStackTop;
						shareMethod = searchMethod;
						goto LabelCall;
					}
				}
				if (!InitAndGetInterpreterDirectlyCallMethodPointer(shareMethod))
				{
					RaiseAOTGenericMethodNotInstantiatedException(shareMethod);
				}
				int32_t callArgEvalStackIdxBase = evalStackTop - shareMethod->parameters_count;
				IL2CPP_ASSERT(callArgEvalStackIdxBase >= 0);
				uint16_t objIdx = GetEvalStackOffset(callArgEvalStackIdxBase);

				int32_t resolvedTotalArgNum = shareMethod->parameters_count + 1;

				uint32_t methodDataIndex = GetOrAddResolveDataIndex(shareMethod);

				if (IsInterpreterImplement(shareMethod))
				{
					if (IS_CLASS_VALUE_TYPE(klass))
					{
						CreateAddIR(ir, NewValueTypeInterpVar);
						ir->obj = GetEvalStackOffset(callArgEvalStackIdxBase);
						ir->method = methodDataIndex;
						ir->argBase = ir->obj;
						ir->argStackObjectNum = curStackSize - ir->argBase;
						// IL2CPP_ASSERT(ir->argStackObjectNum > 0); may 0
						PopStackN(shareMethod->parameters_count);
						PushStackByType(&klass->byval_arg);
						ir->ctorFrameBase = GetEvalStackNewTopOffset();
						maxStackSize = std::max(maxStackSize, curStackSize + ir->argStackObjectNum + 1);
					}
					else
					{
						if (shareMethod->parameters_count == 0)
						{
							CreateAddIR(ir, NewClassInterpVar_Ctor_0);
							ir->obj = GetEvalStackNewTopOffset();
							ir->method = methodDataIndex;
							PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
							ir->ctorFrameBase = GetEvalStackNewTopOffset();
							maxStackSize = std::max(maxStackSize, curStackSize + 1); // 1 for __this
						}
						else
						{
							CreateAddIR(ir, NewClassInterpVar);
							ir->obj = GetEvalStackOffset(callArgEvalStackIdxBase);
							ir->method = methodDataIndex;
							ir->argBase = ir->obj;
							ir->argStackObjectNum = curStackSize - ir->argBase;
							IL2CPP_ASSERT(ir->argStackObjectNum > 0);
							PopStackN(shareMethod->parameters_count);
							PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
							ir->ctorFrameBase = GetEvalStackNewTopOffset();
							maxStackSize = std::max(maxStackSize, curStackSize + ir->argStackObjectNum + 1); // 1 for __this
						}
					}
					IL2CPP_ASSERT(maxStackSize < MAX_STACK_SIZE);
					continue;
				}

				// optimize when argv == 0
				if (shareMethod->parameters_count == 0 && !IS_CLASS_VALUE_TYPE(klass))
				{
					CreateAddIR(ir, NewClassVar_Ctor_0);
					ir->method = methodDataIndex;
					ir->obj = GetEvalStackNewTopOffset();
					PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					continue;
				}

				int32_t needDataSlotNum = (resolvedTotalArgNum + 3) / 4;
				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT((void*)managed2NativeMethod);
				//uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex(managed2NativeMethod);



				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);
				//
				// arg1, arg2, arg3 ..., argN, obj or valuetype, __this(= obj or ref valuetype)
				// obj on new top
				PushStackByType(&klass->byval_arg);
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				__argIdxs[0] = GetEvalStackTopOffset(); // this

				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + 1;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + i].locOffset;
				}
				PopStackN(resolvedTotalArgNum + 1); // args + obj + this
				PushStackByType(&klass->byval_arg);
				CreateAddIR(ir, NewClassVar);
				ir->type = IS_CLASS_VALUE_TYPE(shareMethod->klass) ? HiOpcodeEnum::NewValueTypeVar : HiOpcodeEnum::NewClassVar;
				ir->managed2NativeMethod = GetOrAddResolveDataIndex((void*)managed2NativeMethod);
				ir->method = methodDataIndex;
				ir->argIdxs = argIdxDataIndex;
				ir->obj = objIdx;

				continue;
			}
			case OpcodeValue::CASTCLASS:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (il2cpp::vm::Class::IsNullable(objKlass))
				{
					objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				}
				uint32_t klassDataIdx = GetOrAddResolveDataIndex(objKlass);

				CreateAddIR(ir, CastclassVar);
				ir->obj = GetEvalStackTopOffset();
				ir->klass = klassDataIdx;
				ip += 5;
				continue;
			}
			case OpcodeValue::ISINST:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (il2cpp::vm::Class::IsNullable(objKlass))
				{
					objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				}
				uint32_t klassDataIdx = GetOrAddResolveDataIndex(objKlass);

				CreateAddIR(ir, IsInstVar);
				ir->obj = GetEvalStackTopOffset();
				ir->klass = klassDataIdx;
				ip += 5;
				continue;
			}
			case OpcodeValue::CONV_R_UN:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& top = evalStack[evalStackTop - 1];
				switch (top.reduceType)
				{
				case EvalStackReduceDataType::I4:
				{
					CreateAddIR(ir, ConvertVarVar_u4_f8);
					ir->dst = ir->src = GetEvalStackTopOffset();
					break;
				}
				case EvalStackReduceDataType::I8:
				{
					CreateAddIR(ir, ConvertVarVar_u8_f8);
					ir->dst = ir->src = GetEvalStackTopOffset();
					break;
				}
				default:
				{
					RaiseExecutionEngineException("");
					break;
				}
				}
				top.reduceType = EvalStackReduceDataType::R8;
				top.byteSize = 8;
				ip++;
				continue;
			}
			case OpcodeValue::UNBOX:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				//if (il2cpp::vm::Class::IsNullable(objKlass))
				//{
				//    objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				//}
				CreateAddIR(ir, UnBoxVarVar);
				ir->addr = ir->obj = GetEvalStackTopOffset();
				ir->klass = GetOrAddResolveDataIndex(objKlass);

				PopStack();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::THROW:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				CreateAddIR(ir, ThrowEx);
				ir->exceptionObj = GetEvalStackTopOffset();
				ir->firstHandlerIndex = FindFirstThrowHandlerIndex(body.exceptionClauses, ipOffset);
				PopAllStack();
				PopBranch();
				continue;
			}
			case OpcodeValue::LDFLD:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);
				// ldfld obj may be obj or or valuetype or ref valuetype....
				EvalStackVarInfo& obj = evalStack[evalStackTop - 1];
				uint16_t topIdx = GetEvalStackTopOffset();
				IRCommon* ir = obj.reduceType != NATIVE_INT_REDUCE_TYPE && IS_CLASS_VALUE_TYPE(fieldInfo->parent) ? CreateValueTypeLdfld(pool, topIdx, topIdx, fieldInfo) : CreateClassLdfld(pool, topIdx, topIdx, fieldInfo);
				AddInst(ir);
				PopStack();
				PushStackByType(fieldInfo->type);

				InsertMemoryBarrier();
				ResetPrefixFlags();

				ip += 5;
				continue;
			}
			case OpcodeValue::LDFLDA:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint16_t topIdx = GetEvalStackTopOffset();
				CreateAddIR(ir, LdfldaVarVar);
				ir->dst = topIdx;
				ir->obj = topIdx;
				ir->offset = GetFieldOffset(fieldInfo);

				PopStack();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip += 5;
				continue;
			}
			case OpcodeValue::STFLD:
			{
				InsertMemoryBarrier();
				ResetPrefixFlags();

				IL2CPP_ASSERT(evalStackTop >= 2);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				IRCommon* ir = CreateStfld(pool, GetEvalStackOffset_2(), fieldInfo, GetEvalStackOffset_1());
				AddInst(ir);
				PopStackN(2);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDSFLD:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);
				uint32_t parentIndex = GetOrAddResolveDataIndex(fieldInfo->parent);
				uint16_t dstIdx = GetEvalStackNewTopOffset();
				IRCommon* ir = fieldInfo->offset != THREAD_STATIC_FIELD_OFFSET ?
					CreateLdsfld(pool, dstIdx, fieldInfo, parentIndex)
					: CreateLdthreadlocal(pool, dstIdx, fieldInfo, parentIndex);
				AddInst(ir);
				PushStackByType(fieldInfo->type);

				InsertMemoryBarrier();
				ResetPrefixFlags();

				ip += 5;
				continue;
			}
			case OpcodeValue::LDSFLDA:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint16_t dstIdx = GetEvalStackNewTopOffset();
				if (fieldInfo->offset != THREAD_STATIC_FIELD_OFFSET)
				{
					bool ldfldFromFieldData = false;
					if (hybridclr::metadata::IsInterpreterType(fieldInfo->parent))
					{
						const FieldDetail& fieldDet = hybridclr::metadata::MetadataModule::GetImage(fieldInfo->parent)
							->GetFieldDetailFromRawIndex(hybridclr::metadata::DecodeTokenRowIndex(fieldInfo->token - 1));
						if (fieldDet.defaultValueIndex != kDefaultValueIndexNull)
						{
							ldfldFromFieldData = true;
							CreateAddIR(ir, LdsfldaFromFieldDataVarVar);
							ir->dst = dstIdx;
							ir->src = GetOrAddResolveDataIndex(il2cpp::vm::Field::GetData(fieldInfo));
						}
					}
					if (!ldfldFromFieldData)
					{
						CreateAddIR(ir, LdsfldaVarVar);
						ir->dst = dstIdx;
						ir->klass = GetOrAddResolveDataIndex(fieldInfo->parent);
						ir->offset = fieldInfo->offset;
					}
				}
				else
				{
					CreateAddIR(ir, LdthreadlocalaVarVar);
					ir->dst = dstIdx;
					ir->klass = GetOrAddResolveDataIndex(fieldInfo->parent);
					ir->offset = GetThreadStaticFieldOffset(fieldInfo);
				}
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::STSFLD:
			{
				InsertMemoryBarrier();
				ResetPrefixFlags();
				IL2CPP_ASSERT(evalStackTop >= 1);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint32_t klassIndex = GetOrAddResolveDataIndex(fieldInfo->parent);
				uint16_t dataIdx = GetEvalStackTopOffset();
				IRCommon* ir = fieldInfo->offset != THREAD_STATIC_FIELD_OFFSET ?
					CreateStsfld(pool, fieldInfo, klassIndex, dataIdx)
					: CreateStthreadlocal(pool, fieldInfo, klassIndex, dataIdx);
				AddInst(ir);

				PopStack();
				ip += 5;
				continue;
			}
			case OpcodeValue::STOBJ:
			{
				InsertMemoryBarrier();
				ResetPrefixFlags();

				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& dst = evalStack[evalStackTop - 2];
				EvalStackVarInfo& src = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);

				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);

				IL2CPP_ASSERT(objKlass);
				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					uint32_t size = GetTypeValueSize(objKlass);
					if (!HYBRIDCLR_ENABLE_WRITE_BARRIERS || !objKlass->has_references)
					{
						switch (size)
						{
						case 1:
						{
							CreateAddIR(ir, StobjVarVar_1);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 2:
						{
							CreateAddIR(ir, StobjVarVar_2);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 4:
						{
							CreateAddIR(ir, StobjVarVar_4);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 8:
						{
							CreateAddIR(ir, StobjVarVar_8);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 12:
						{
							CreateAddIR(ir, StobjVarVar_12);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						case 16:
						{
							CreateAddIR(ir, StobjVarVar_16);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							break;
						}
						default:
						{
							CreateAddIR(ir, StobjVarVar_n_4);
							ir->dst = dst.locOffset;
							ir->src = src.locOffset;
							ir->size = size;
							break;
						}
						}
					}
					else
					{
						CreateAddIR(ir, StobjVarVar_WriteBarrier_n_4);
						ir->dst = dst.locOffset;
						ir->src = src.locOffset;
						ir->size = size;
					}
				}
				else
				{
					CreateAddIR(ir, StobjVarVar_ref);
					ir->dst = dst.locOffset;
					ir->src = src.locOffset;
				}

				PopStackN(2);
				ip += 5;
				continue;
			}
			case OpcodeValue::CONV_OVF_I1_UN:
			{
				CI_conv_un_ovf(i1, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_I2_UN:
			{
				CI_conv_un_ovf(i2, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_I4_UN:
			{
				CI_conv_un_ovf(i4, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_I8_UN:
			{
				CI_conv_un_ovf(i8, I8, 8);
				continue;
			}
			case OpcodeValue::CONV_OVF_U1_UN:
			{
				CI_conv_un_ovf(u1, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_U2_UN:
			{
				CI_conv_un_ovf(u2, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_U4_UN:
			{
				CI_conv_un_ovf(u4, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_U8_UN:
			{
				CI_conv_un_ovf(u8, I8, 8);
				continue;
			}
			case OpcodeValue::CONV_OVF_I_UN:
			{
#if HYBRIDCLR_ARCH_64
				CI_conv_un_ovf(i8, I8, 8);
#else
				CI_conv_un_ovf(i4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::CONV_OVF_U_UN:
			{
#if HYBRIDCLR_ARCH_64
				CI_conv_un_ovf(u8, I8, 8);
#else
				CI_conv_un_ovf(u4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::BOX:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				/*	if (il2cpp::vm::Class::IsNullable(objKlass))
					{
						objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
					}*/
				PopStack();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					CreateAddIR(ir, BoxVarVar);
					ir->dst = ir->data = GetEvalStackTopOffset();
					ir->klass = GetOrAddResolveDataIndex(objKlass);
				}
				else
				{
					// ignore class
				}

				ip += 5;
				continue;
			}
			case OpcodeValue::NEWARR:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& varSize = evalStack[evalStackTop - 1];
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* eleKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(eleKlass);
				Il2CppClass* arrKlass = il2cpp::vm::Class::GetArrayClass(eleKlass, 1);
				uint32_t arrKlassIndex = GetOrAddResolveDataIndex(arrKlass);

				CreateAddIR(ir, NewArrVarVar);
				ir->arr = ir->size = varSize.locOffset;
				ir->klass = arrKlassIndex;

				PopStack();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::LDLEN:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				CreateAddIR(ir, GetArrayLengthVarVar);
				ir->arr = ir->len = GetEvalStackTopOffset();
				PopStack();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip++;
				continue;
			}
			case OpcodeValue::LDELEMA:
			{
				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& arr = evalStack[evalStackTop - 2];
				EvalStackVarInfo& index = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* eleKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				uint32_t eleKlassIndex = GetOrAddResolveDataIndex(eleKlass);

				if (prefixFlags & (int32_t)PrefixFlags::ReadOnly)
				{
					CreateAddIR(ir, GetArrayElementAddressAddrVarVar);
					ir->arr = ir->addr = arr.locOffset;
					ir->index = index.locOffset;
				}
				else
				{
					CreateAddIR(ir, GetArrayElementAddressCheckAddrVarVar);
					ir->arr = ir->addr = arr.locOffset;
					ir->index = index.locOffset;
					ir->eleKlass = eleKlassIndex;
				}
				ResetPrefixFlags();
				PopStackN(2);
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDELEM_I1:
			{
				CI_ldele(i1, I4);
				continue;
			}
			case OpcodeValue::LDELEM_U1:
			{
				CI_ldele(u1, I4);
				continue;
			}
			case OpcodeValue::LDELEM_I2:
			{
				CI_ldele(i2, I4);
				continue;
			}
			case OpcodeValue::LDELEM_U2:
			{
				CI_ldele(u2, I4);
				continue;
			}
			case OpcodeValue::LDELEM_I4:
			{
				CI_ldele(i4, I4);
				continue;
			}
			case OpcodeValue::LDELEM_U4:
			{
				CI_ldele(u4, I4);
				continue;
			}
			case OpcodeValue::LDELEM_I8:
			{
				CI_ldele(i8, I8);
				continue;
			}
			case OpcodeValue::LDELEM_I:
			{
#if HYBRIDCLR_ARCH_64
				CI_ldele(i8, I8);
#else
				CI_ldele(i4, I4);
#endif
				continue;
			}
			case OpcodeValue::LDELEM_R4:
			{
				CI_ldele(i4, R4);
				continue;
			}
			case OpcodeValue::LDELEM_R8:
			{
				CI_ldele(i8, R8);
				continue;
			}
			case OpcodeValue::LDELEM_REF:
			{
#if HYBRIDCLR_ARCH_64
				CI_ldele(i8, I8);
#else
				CI_ldele(i4, I4);
#endif
				continue;
			}
			case OpcodeValue::STELEM_I:
			{
#if HYBRIDCLR_ARCH_64
				CI_stele(i8)
#else
				CI_stele(i4)
#endif
					continue;
			}
			case OpcodeValue::STELEM_I1:
			{
				CI_stele(i1);
				continue;
			}
			case OpcodeValue::STELEM_I2:
			{
				CI_stele(i2);
				continue;
			}
			case OpcodeValue::STELEM_I4:
			{
				CI_stele(i4);
				continue;
			}
			case OpcodeValue::STELEM_I8:
			{
				CI_stele(i8);
				continue;
			}
			case OpcodeValue::STELEM_R4:
			{
				CI_stele(i4);
				continue;
			}
			case OpcodeValue::STELEM_R8:
			{
				CI_stele(i8);
				continue;
			}
			case OpcodeValue::STELEM_REF:
			{
				CI_stele(ref);
				continue;
			}

#define CI_ldele0(eleType) \
CreateAddIR(ir,  GetArrayElementVarVar_##eleType); \
ir->arr = arr.locOffset; \
ir->index = index.locOffset; \
ir->dst = arr.locOffset;


			case OpcodeValue::LDELEM:
			{
				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& arr = evalStack[evalStackTop - 2];
				EvalStackVarInfo& index = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				const Il2CppType* eleType = &objKlass->byval_arg;

				IL2CPP_ASSERT(index.reduceType == EvalStackReduceDataType::I4 || index.reduceType == EvalStackReduceDataType::I8);
				bool isIndexInt32Type = index.reduceType == EvalStackReduceDataType::I4;
				LocationDescInfo desc = ComputLocationDescInfo(eleType);
				switch (desc.type)
				{
				case LocationDescType::I1: { CI_ldele0(i1); break; }
				case LocationDescType::U1: { CI_ldele0(u1); break; }
				case LocationDescType::I2: { CI_ldele0(i2); break; }
				case LocationDescType::U2: { CI_ldele0(u2); break; }
				case LocationDescType::I4: { CI_ldele0(i4); break; }
				case LocationDescType::I8: { CI_ldele0(i8); break; }
				case LocationDescType::Ref:
				{
					if (HYBRIDCLR_ARCH_64)
					{
						CI_ldele0(i8);
					}
					else
					{
						CI_ldele0(i4);
					}
					break;
				}
				case LocationDescType::S:
				case LocationDescType::StructContainsRef:
				{
					CreateAddIR(ir, GetArrayElementVarVar_size_1);
					ir->arr = arr.locOffset;
					ir->index = index.locOffset;
					ir->dst = arr.locOffset;
					uint32_t size = il2cpp::vm::Class::GetValueSize(objKlass, nullptr);
					switch (size)
					{
					case 1:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_1;
						break;
					}
					case 2:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_2;
						break;
					}
					case 4:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_4;
						break;
					}
					case 8:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_8;
						break;
					}
					case 12:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_12;
						break;
					}
					case 16:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_16;
						break;
					}
					case 20:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_20;
						break;
					}
					case 24:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_24;
						break;
					}
					case 28:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_28;
						break;
					}
					case 32:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_size_32;
						break;
					}
					default:
					{
						ir->type = HiOpcodeEnum::GetArrayElementVarVar_n;
					}
					}
					break;
				}
				default:
				{
					RaiseExecutionEngineException("ldelem not support type");
				}
				}
				PopStackN(2);
				PushStackByType(eleType);

				ip += 5;
				continue;
			}


#define CI_stele0(eleType) \
CreateAddIR(ir, SetArrayElementVarVar_##eleType); \
ir->arr = arr.locOffset; \
ir->index = index.locOffset; \
ir->ele = ele.locOffset; 

			case OpcodeValue::STELEM:
			{
				IL2CPP_ASSERT(evalStackTop >= 3);
				EvalStackVarInfo& arr = evalStack[evalStackTop - 3];
				EvalStackVarInfo& index = evalStack[evalStackTop - 2];
				EvalStackVarInfo& ele = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				const Il2CppType* eleType = &objKlass->byval_arg;

				IL2CPP_ASSERT(index.reduceType == EvalStackReduceDataType::I4 || index.reduceType == EvalStackReduceDataType::I8);
				bool isIndexInt32Type = index.reduceType == EvalStackReduceDataType::I4;
				LocationDescInfo desc = ComputLocationDescInfo(eleType);
				switch (desc.type)
				{
				case LocationDescType::I1: { CI_stele0(i1); break; }
				case LocationDescType::U1: { CI_stele0(u1); break; }
				case LocationDescType::I2: { CI_stele0(i2); break; }
				case LocationDescType::U2: { CI_stele0(u2); break; }
				case LocationDescType::I4: { CI_stele0(i4); break; }
				case LocationDescType::I8: { CI_stele0(i8); break; }
				case LocationDescType::Ref: { CI_stele0(ref); break; }
				case LocationDescType::S:
				{
					uint32_t size = il2cpp::vm::Class::GetValueSize(objKlass, nullptr);
					switch (size)
					{
					case 12:
					{
						CreateAddIR(ir, SetArrayElementVarVar_size_12);
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->ele = ele.locOffset;
						break;
					}
					case 16:
					{
						CreateAddIR(ir, SetArrayElementVarVar_size_16);
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->ele = ele.locOffset;
						break;
					}
					default:
					{
						CreateAddIR(ir, SetArrayElementVarVar_n);
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->ele = ele.locOffset;
						break;
					}
					}
					break;
				}
				case LocationDescType::StructContainsRef:
				{
					CreateAddIR(ir, SetArrayElementVarVar_WriteBarrier_n);
					ir->arr = arr.locOffset;
					ir->index = index.locOffset;
					ir->ele = ele.locOffset;
					break;
				}
				default:
				{
					RaiseExecutionEngineException("stelem not support type");
				}
				}
				PopStackN(3);

				ip += 5;
				continue;
			}
			case OpcodeValue::UNBOX_ANY:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					CreateAddIR(ir, UnBoxAnyVarVar);
					ir->dst = ir->obj = GetEvalStackTopOffset();
					ir->klass = GetOrAddResolveDataIndex(objKlass);

					PopStack();
					PushStackByType(&objKlass->byval_arg);
				}
				else
				{
					CreateAddIR(ir, CastclassVar);
					ir->obj = GetEvalStackTopOffset();
					ir->klass = GetOrAddResolveDataIndex(objKlass);
				}

				ip += 5;
				continue;
			}
			case OpcodeValue::CONV_OVF_I1:
			{
				CI_conv_ovf(i1, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_U1:
			{
				CI_conv_ovf(u1, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_I2:
			{
				CI_conv_ovf(i2, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_U2:
			{
				CI_conv_ovf(u2, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_I4:
			{
				CI_conv_ovf(i4, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_U4:
			{
				CI_conv_ovf(u4, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_OVF_I8:
			{
				CI_conv_ovf(i8, I8, 8);
				continue;
			}
			case OpcodeValue::CONV_OVF_U8:
			{
				CI_conv_ovf(u8, I8, 8);
				continue;
			}
			case OpcodeValue::REFANYVAL:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				CreateAddIR(ir, RefAnyValueVarVar);
				ir->addr = ir->typedRef = GetEvalStackTopOffset();
				ir->klass = GetOrAddResolveDataIndex(objKlass);
				PopStack();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip += 5;
				continue;
			}
			case OpcodeValue::CKFINITE:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& top = evalStack[evalStackTop - 1];
				switch (top.reduceType)
				{
				case EvalStackReduceDataType::R4:
				{
					CreateAddIR(ir, CheckFiniteVar_f4);
					ir->src = GetEvalStackTopOffset();
					break;
				}
				case EvalStackReduceDataType::R8:
				{
					CreateAddIR(ir, CheckFiniteVar_f8);
					ir->src = GetEvalStackTopOffset();
					break;
				}
				default:
				{
					RaiseExecutionEngineException("CKFINITE invalid reduceType");
					break;
				}
				}

				ip++;
				continue;
			}
			case OpcodeValue::MKREFANY:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);
				CreateAddIR(ir, MakeRefVarVar);
				ir->dst = ir->data = GetEvalStackTopOffset();
				ir->klass = GetOrAddResolveDataIndex(objKlass);
				PopStack();

				Il2CppType typedRef = {};
				typedRef.type = IL2CPP_TYPE_TYPEDBYREF;
				PushStackByType(&typedRef);

				ip += 5;
				continue;
			}
			case OpcodeValue::LDTOKEN:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				void* runtimeHandle = (void*)image->GetRuntimeHandleFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);

				CreateAddIR(ir, LdtokenVar);
				ir->runtimeHandle = GetEvalStackNewTopOffset();
				ir->token = GetOrAddResolveDataIndex(runtimeHandle);
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip += 5;
				continue;
			}
			case OpcodeValue::CONV_U2:
			{
				CI_conv(u2, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_U1:
			{
				CI_conv(u1, I4, 4);
				continue;
			}
			case OpcodeValue::CONV_I:
			{
#if HYBRIDCLR_ARCH_64
				CI_conv(i8, I8, 8);
#else
				CI_conv(i4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::CONV_OVF_I:
			{
#if HYBRIDCLR_ARCH_64
				CI_conv_ovf(i8, I8, 8);
#else
				CI_conv_ovf(i4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::CONV_OVF_U:
			{
#if HYBRIDCLR_ARCH_64
				CI_conv_ovf(u8, I8, 8);
#else
				CI_conv_ovf(u4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::ADD_OVF:
			{
				CI_binOpOvf(Add);
				continue;
			}
			case OpcodeValue::ADD_OVF_UN:
			{
				CI_binOpUnOvf(Add);
				continue;
			}
			case OpcodeValue::MUL_OVF:
			{
				CI_binOpOvf(Mul);
				continue;
			}
			case OpcodeValue::MUL_OVF_UN:
			{
				CI_binOpUnOvf(Mul);
				continue;
			}
			case OpcodeValue::SUB_OVF:
			{
				CI_binOpOvf(Sub);
				continue;
			}
			case OpcodeValue::SUB_OVF_UN:
			{
				CI_binOpUnOvf(Sub);
				continue;
			}
			case OpcodeValue::ENDFINALLY:
			{
				CreateAddIR(ir, EndFinallyEx);
				PopBranch();
				continue;
			}
			case OpcodeValue::STIND_I:
			{
				Add_stind(ARCH_ARGUMENT(HiOpcodeEnum::StindVarVar_i4, HiOpcodeEnum::StindVarVar_i8));
				continue;
			}
			case OpcodeValue::CONV_U:
			{
#if HYBRIDCLR_ARCH_64
				CI_conv(u8, I8, 8);
#else
				CI_conv(u4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::PREFIX7:
			case OpcodeValue::PREFIX6:
			case OpcodeValue::PREFIX5:
			case OpcodeValue::PREFIX4:
			case OpcodeValue::PREFIX3:
			case OpcodeValue::PREFIX2:
			{
				ip++;
				continue;
			}
			case OpcodeValue::PREFIX1:
			{
				// This is the prefix for all the 2-byte opcodes.
				// Figure out the second byte of the 2-byte opcode.
				byte ops = *(ip + 1);

				switch ((OpcodeValue)ops)
				{

				case OpcodeValue::ARGLIST:
				{
					RaiseExecutionEngineException("");
					ip += 2;
					continue;
				}
				case OpcodeValue::CEQ:
				{
					CI_compare(Ceq);
					ip += 2;
					continue;
				}
				case OpcodeValue::CGT:
				{
					CI_compare(Cgt);
					ip += 2;
					continue;
				}
				case OpcodeValue::CGT_UN:
				{
					CI_compare(CgtUn);
					ip += 2;
					continue;
				}
				case OpcodeValue::CLT:
				{
					CI_compare(Clt);
					ip += 2;
					continue;
				}
				case OpcodeValue::CLT_UN:
				{
					CI_compare(CltUn);
					ip += 2;
					continue;
				}
				case OpcodeValue::LDFTN:
				{
					uint32_t methodToken = (uint32_t)GetI4LittleEndian(ip + 2);
					MethodInfo* methodInfo = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(tokenCache, methodToken, klassContainer, methodContainer, genericContext));
					IL2CPP_ASSERT(methodInfo);
					CreateAddIR(ir, LdcVarConst_8);
					ir->dst = GetEvalStackNewTopOffset();
					ir->src = (uint64_t)methodInfo;
					PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					ip += 6;
					continue;
				}
				case OpcodeValue::LDVIRTFTN:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					uint32_t methodToken = (uint32_t)GetI4LittleEndian(ip + 2);
					MethodInfo* methodInfo = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(tokenCache, methodToken, klassContainer, methodContainer, genericContext));
					IL2CPP_ASSERT(methodInfo);

					CreateAddIR(ir, LdvirftnVarVar);
					ir->resultMethod = ir->obj = GetEvalStackTopOffset();
					ir->virtualMethod = GetOrAddResolveDataIndex(methodInfo);

					PopStack();
					PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					ip += 6;
					continue;
				}
				case OpcodeValue::UNUSED56:
				{
					ip += 2;
					continue;
				}
				case OpcodeValue::LDARG:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					AddInst_ldarg(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LDARGA:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					AddInst_ldarga(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::STARG:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					AddInst_starg(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LDLOC:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					CreateAddInst_ldloc(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LDLOCA:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					CreateAddInst_ldloca(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::STLOC:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					CreateAddInst_stloc(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LOCALLOC:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					EvalStackVarInfo& top = evalStack[evalStackTop - 1];

					switch (top.reduceType)
					{
					case EvalStackReduceDataType::I4:
					case EvalStackReduceDataType::I8: // FIXE ME
					{
						CreateAddIR(ir, LocalAllocVarVar_n_4);
						ir->dst = ir->size = GetEvalStackTopOffset();
						break;
					}
					default:
					{
						RaiseExecutionEngineException("LOCALLOC invalid reduceType");
						break;
					}
					}
					PopStack();
					PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

					ip += 2;
					continue;
				}
				case OpcodeValue::UNUSED57:
				{
					ip += 2;
					continue;
				}
				case OpcodeValue::ENDFILTER:
				{
					CreateAddIR(ir, EndFilterEx);
					ir->value = GetEvalStackTopOffset();
					PopAllStack();

					PopBranch();
					continue;
				}
				case OpcodeValue::UNALIGNED_:
				{
					// Nothing to do here.
					prefixFlags |= (int32_t)PrefixFlags::Unaligned;
					uint8_t alignment = ip[2];
					IL2CPP_ASSERT(alignment == 1 || alignment == 2 || alignment == 4);
					ip += 3;
					continue;
				}
				case OpcodeValue::VOLATILE_:
				{
					// Set a flag that causes a memory barrier to be associated with the next load or store.
					//CI_volatileFlag = true;
					prefixFlags |= (int32_t)PrefixFlags::Volatile;
					ip += 2;
					continue;
				}
				case OpcodeValue::TAIL_:
				{
					prefixFlags |= (int32_t)PrefixFlags::Tail;
					ip += 2;
					continue;
				}
				case OpcodeValue::INITOBJ:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					uint32_t token = (uint32_t)GetI4LittleEndian(ip + 2);
					Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
					if (IS_CLASS_VALUE_TYPE(objKlass))
					{
						uint32_t objSize = GetTypeValueSize(objKlass);
						if ((HYBRIDCLR_ENABLE_WRITE_BARRIERS && objKlass->has_references))
						{
							CreateAddIR(ir, InitobjVar_WriteBarrier_n_4);
							ir->obj = GetEvalStackTopOffset();
							ir->size = objSize;
						}
						else
						{
							bool convert = false;
							switch (objSize)
							{
							case 1:
							{
								CreateAddIR(ir, InitobjVar_1);
								ir->obj = GetEvalStackTopOffset();
								convert = true;
								break;
							}
							case 2:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 2)
								{
									CreateAddIR(ir, InitobjVar_2);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 4:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_4);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 8:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_8);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 12:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_12);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 16:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_16);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 20:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_20);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 24:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_24);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 28:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_28);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 32:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_32);
									ir->obj = GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							}
							if (!convert)
							{
								CreateAddIR(ir, InitobjVar_n_4);
								ir->obj = GetEvalStackTopOffset();
								ir->size = objSize;
							}
						}
					}
					else
					{
						CreateAddIR(ir, InitobjVar_ref);
						ir->obj = GetEvalStackTopOffset();
					}
					PopStack();

					ip += 6;
					break;
				}
				case OpcodeValue::CONSTRAINED_:
				{
					uint32_t typeToken = (uint32_t)GetI4LittleEndian(ip + 2);
					Il2CppClass* conKlass = image->GetClassFromToken(tokenCache, typeToken, klassContainer, methodContainer, genericContext);
					IL2CPP_ASSERT(conKlass);
					ip += 6;

					IL2CPP_ASSERT(*ip == (uint8_t)OpcodeValue::CALLVIRT);
					uint32_t methodToken = (uint32_t)GetI4LittleEndian(ip + 1);
					ip += 5;

					// TODO token cache optimistic
					shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(tokenCache, methodToken, klassContainer, methodContainer, genericContext));
					IL2CPP_ASSERT(shareMethod);


					int32_t resolvedTotalArgNum = shareMethod->parameters_count + 1;

					int32_t selfIdx = evalStackTop - resolvedTotalArgNum;
					EvalStackVarInfo& self = evalStack[selfIdx];
					if (IS_CLASS_VALUE_TYPE(conKlass))
					{
						// impl in self
						const MethodInfo* implMethod = image->FindImplMethod(conKlass, shareMethod);
						if (implMethod->klass == conKlass)
						{
							shareMethod = implMethod;
							goto LabelCall;
						}
						else if (conKlass->enumtype && !std::strcmp(shareMethod->name, "GetHashCode"))
						{
							Il2CppTypeEnum typeEnum = conKlass->element_class->byval_arg.type;
							self.reduceType = EvalStackReduceDataType::I4;
							if (typeEnum == IL2CPP_TYPE_I8 || typeEnum == IL2CPP_TYPE_U8)
							{
								CreateAddIR(ir, GetEnumHashCode);
								ir->dst = ir->src = self.locOffset;
							}
							else
							{
								CreateAddIR(ir, LdindVarVar_i1);
								ir->dst = ir->src = self.locOffset;
								switch (conKlass->element_class->byval_arg.type)
								{
								case IL2CPP_TYPE_U1: ir->type = HiOpcodeEnum::LdindVarVar_u1; break;
								case IL2CPP_TYPE_I1: ir->type = HiOpcodeEnum::LdindVarVar_i1; break;
								case IL2CPP_TYPE_U2: ir->type = HiOpcodeEnum::LdindVarVar_u2; break;
								case IL2CPP_TYPE_I2: ir->type = HiOpcodeEnum::LdindVarVar_u2; break;
								case IL2CPP_TYPE_U4: ir->type = HiOpcodeEnum::LdindVarVar_u4; break;
								case IL2CPP_TYPE_I4: ir->type = HiOpcodeEnum::LdindVarVar_i4; break;
								case IL2CPP_TYPE_CHAR: ir->type = HiOpcodeEnum::LdindVarVar_u2; break;
								case IL2CPP_TYPE_BOOLEAN: ir->type = HiOpcodeEnum::LdindVarVar_i1; break;
								default:
									IL2CPP_ASSERT(false && "GetHashCode");
									break;
								}
							}
						}
						else
						{
							CreateAddIR(ir, BoxRefVarVar);
							ir->dst = ir->src = self.locOffset;
							ir->klass = GetOrAddResolveDataIndex(conKlass);

							self.reduceType = NATIVE_INT_REDUCE_TYPE;
							self.byteSize = GetSizeByReduceType(self.reduceType);
							goto LabelCallVir;
						}
					}
					else
					{
#if HYBRIDCLR_ARCH_64
						CreateAddIR(ir, LdindVarVar_i8);
#else
						CreateAddIR(ir, LdindVarVar_i4);
#endif
						ir->dst = ir->src = self.locOffset;
						self.reduceType = NATIVE_INT_REDUCE_TYPE;
						self.byteSize = GetSizeByReduceType(self.reduceType);
						goto LabelCallVir;
					}
					continue;
				}
				case OpcodeValue::CPBLK:
				{
					// we don't sure dst or src is volatile. so insert memory barrier ahead and end.
					IL2CPP_ASSERT(evalStackTop >= 3);
					InsertMemoryBarrier();
					ResetPrefixFlags();
					CreateAddIR(ir, CpblkVarVar);
					ir->dst = GetEvalStackOffset_3();
					ir->src = GetEvalStackOffset_2();
					ir->size = GetEvalStackOffset_1();
					PopStackN(3);
					InsertMemoryBarrier();
					ResetPrefixFlags();
					ip += 2;
					continue;
				}
				case OpcodeValue::INITBLK:
				{
					IL2CPP_ASSERT(evalStackTop >= 3);
					InsertMemoryBarrier();
					ResetPrefixFlags();
					CreateAddIR(ir, InitblkVarVarVar);
					ir->addr = GetEvalStackOffset_3();
					ir->value = GetEvalStackOffset_2();
					ir->size = GetEvalStackOffset_1();
					PopStackN(3);
					ip += 2;
					continue;
				}
				case OpcodeValue::NO_:
				{
					uint8_t checkType = ip[2];
					// {typecheck:0x1} | {rangecheck:0x2} | {nullcheck:0x4}
					IL2CPP_ASSERT(checkType < 8);
					ip += 3;
					continue;
				}
				case OpcodeValue::RETHROW:
				{
					CreateAddIR(ir, RethrowEx);
					AddInst(ir);
					PopAllStack();
					PopBranch();
					continue;
				}
				case OpcodeValue::UNUSED:
				{
					ip += 2;
					continue;
				}
				case OpcodeValue::SIZEOF:
				{
					uint32_t token = (uint32_t)GetI4LittleEndian(ip + 2);
					Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
					IL2CPP_ASSERT(objKlass);
					int32_t typeSize = GetTypeValueSize(&objKlass->byval_arg);
					CreateAddInst_ldc4(typeSize, EvalStackReduceDataType::I4);
					ip += 6;
					continue;
				}
				case OpcodeValue::REFANYTYPE:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					CreateAddIR(ir, RefAnyTypeVarVar);
					ir->dst = ir->typedRef = GetEvalStackOffset_1();
					PopStack();
					PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

					ip += 2;
					continue;
				}
				case OpcodeValue::READONLY_:
				{
					prefixFlags |= (int32_t)PrefixFlags::ReadOnly;
					ip += 2;
					// generic md array also can follow readonly
					//IL2CPP_ASSERT(*ip == (byte)OpcodeValue::LDELEMA && "According to the ECMA spec, READONLY may only precede LDELEMA");
					continue;
				}
				case OpcodeValue::UNUSED53:
				case OpcodeValue::UNUSED54:
				case OpcodeValue::UNUSED55:
				case OpcodeValue::UNUSED70:
				{
					ip += 2;
					continue;
				}
				default:
				{
					//UNREACHABLE();
					RaiseExecutionEngineException("not support instruction");
					continue;
				}
				}
				continue;
			}
			case OpcodeValue::PREFIXREF:
			{
				ip++;
				continue;
			}
			default:
			{
				RaiseExecutionEngineException("not support instruction");
				continue;
			}
			}
			ip++;
		}
	finish_transform:


		totalIRSize = 0;
		for (IRBasicBlock* bb : irbbs)
		{
			bb->codeOffset = totalIRSize;
			for (IRCommon* ir : bb->insts)
			{
				totalIRSize += g_instructionSizes[(int)ir->type];
			}
		}
		endBb->codeOffset = totalIRSize;

		for (int32_t* relocOffsetPtr : relocationOffsets)
		{
			int32_t relocOffset = *relocOffsetPtr;
			IL2CPP_ASSERT(splitOffsets.find(relocOffset) != splitOffsets.end());
			*relocOffsetPtr = ip2bb[relocOffset]->codeOffset;
		}

		for (auto switchOffsetPair : switchOffsetsInResolveData)
		{
			int32_t* offsetStartPtr = (int32_t*)&resolveDatas[switchOffsetPair.first];
			for (int32_t i = 0; i < switchOffsetPair.second; i++)
			{
				int32_t relocOffset = offsetStartPtr[i];
				IL2CPP_ASSERT(splitOffsets.find(relocOffset) != splitOffsets.end());
				offsetStartPtr[i] = ip2bb[relocOffset]->codeOffset;
			}
		}
	}

	void TransformContext::BuildInterpMethodInfo(interpreter::InterpMethodInfo& result)
	{
		il2cpp::utils::dynamic_array<hybridclr::metadata::ILMapper>* ilMappers;
		if (ir2offsetMap)
		{
			ilMappers = new il2cpp::utils::dynamic_array<hybridclr::metadata::ILMapper>();
			ilMappers->reserve(ir2offsetMap->size());
		}
		else
		{
			ilMappers = nullptr;
		}
		byte* tranCodes = (byte*)HYBRIDCLR_METADATA_MALLOC(totalIRSize);

		uint32_t tranOffset = 0;
		for (IRBasicBlock* bb : irbbs)
		{
			//bb->codeOffset = tranOffset;
			for (IRCommon* ir : bb->insts)
			{
				if (ilMappers)
				{
					auto it = ir2offsetMap->find(ir);
					if (it != ir2offsetMap->end())
					{
						hybridclr::metadata::ILMapper ilMapper;
						ilMapper.irOffset = tranOffset;
						ilMapper.ilOffset = it->second;
						ilMappers->push_back(ilMapper);
					}
				}
				uint32_t irSize = g_instructionSizes[(int)ir->type];
				std::memcpy(tranCodes + tranOffset, &ir->type, irSize);
				tranOffset += irSize;
			}
		}
		IL2CPP_ASSERT(tranOffset == totalIRSize);

		for (FlowInfo* fi : pendingFlows)
		{
			fi->~FlowInfo();
		}

		MethodArgDesc* argDescs;
		if (actualParamCount > 0)
		{
			argDescs = (MethodArgDesc*)HYBRIDCLR_METADATA_CALLOC(actualParamCount, sizeof(MethodArgDesc));
			for (int32_t i = 0; i < actualParamCount; i++)
			{
				const Il2CppType* argType = args[i].type;
				TypeDesc typeDesc = GetTypeArgDesc(argType);
				MethodArgDesc& argDesc = argDescs[i];
				argDesc.type = typeDesc.type;
				IL2CPP_ASSERT(typeDesc.stackObjectSize < 0x10000);
				argDesc.stackObjectSize = (uint16_t)typeDesc.stackObjectSize;
				argDesc.passbyValWhenInvoke = argType->byref || !IsValueType(argType);
			}
		}
		else
		{
			argDescs = nullptr;
		}

		result.args = argDescs;
		result.argCount = actualParamCount;
		result.argStackObjectSize = totalArgSize;
		result.retStackObjectSize = IsVoidType(methodInfo->return_type) ? 0 : GetTypeArgDesc(methodInfo->return_type).stackObjectSize;
		result.codes = tranCodes;
		result.codeLength = totalIRSize;
		result.evalStackBaseOffset = evalStackBaseOffset;
		result.localVarBaseOffset = totalArgSize;
		result.localStackSize = totalArgLocalSize;
		result.maxStackSize = maxStackSize;
		result.initLocals = initLocals;

		if (resolveDatas.empty())
		{
			result.resolveDatas = nullptr;
		}
		else
		{
			//result.resolveData = (uint8_t*)HYBRIDCLR_MALLOC(resolveDatas.size() * sizeof(uint8_t));
			size_t dataSize = resolveDatas.size() * sizeof(uint64_t);
			uint64_t* data = (uint64_t*)HYBRIDCLR_METADATA_MALLOC(dataSize);
			std::memcpy(data, resolveDatas.data(), dataSize);
			result.resolveDatas = data;
		}
		if (exClauses.empty())
		{
			result.exClauses = nullptr;
			result.exClauseCount = 0;
		}
		else
		{
			size_t dataSize = exClauses.size() * sizeof(InterpExceptionClause);
			InterpExceptionClause* data = (InterpExceptionClause*)HYBRIDCLR_METADATA_MALLOC(dataSize);
			std::memcpy(data, exClauses.data(), dataSize);
			result.exClauses = data;
			result.exClauseCount = (uint32_t)exClauses.size();
		}

		if (ilMappers)
		{
			image->GetPDBImage()->SetMethodDebugInfo(methodInfo, *ilMappers);
		}
	}

	bool TransformContext::TransformSubMethodBody(TransformContext& callingCtx, const MethodInfo* methodInfo, int32_t depth, int32_t localVarOffset)
	{
		metadata::Image* image = metadata::MetadataModule::GetUnderlyingInterpreterImage(methodInfo);
		IL2CPP_ASSERT(image);

		metadata::MethodBody* methodBody = metadata::MethodBodyCache::GetMethodBody(image, methodInfo->token);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			TEMP_FORMAT(errMsg, "Method body is null. %s.%s::%s", methodInfo->klass->namespaze, methodInfo->klass->name, methodInfo->name);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		}

		TransformContext ctx(image, methodInfo, *methodBody, callingCtx.pool, callingCtx.resolveDatas);

		try
		{
			ctx.TransformBodyImpl(depth, localVarOffset);
			callingCtx.maxStackSize = std::max(callingCtx.maxStackSize, ctx.maxStackSize);
			callingCtx.curbb->insts.insert(callingCtx.curbb->insts.end(), ctx.curbb->insts.begin(), ctx.curbb->insts.end());
			return true;
		}
		catch (Il2CppExceptionWrapper&)
		{
			//LOG_ERROR("TransformSubMethodBody failed: %s", ex.what());
			metadata::MethodBodyCache::DisableInline(methodInfo);
			return false;
		}

		return false;
	}

}
}