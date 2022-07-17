
#include "Transform.h"

#include "metadata/GenericMetadata.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/String.h"

#include "TemporaryMemoryArena.h"
#include "../metadata/MetadataUtil.h"
#include "../metadata/Opcodes.h"
#include "../metadata/MetadataModule.h"
#include "../interpreter/Instruction.h"
#include "../interpreter/Interpreter.h"
#include "../interpreter/InterpreterModule.h"

using namespace huatuo::metadata;
using namespace huatuo::interpreter;

namespace huatuo
{
namespace transform
{
	const int32_t MAX_STACK_SIZE = (2 << 16) - 1;
	const int32_t MAX_VALUE_TYPE_SIZE = (2 << 16) - 1;

#if HUATUO_ARCH_64
#define NATIVE_INT_OP opI8
	constexpr EvalStackReduceDataType NATIVE_INT_REDUCE_TYPE = EvalStackReduceDataType::I8;
#else
#define NATIVE_INT_OP opI4
	constexpr EvalStackReduceDataType NATIVE_INT_REDUCE_TYPE = EvalStackReduceDataType::I4;
#endif

#define CreateIR(varName, typeName) IR##typeName* varName = pool.AllocIR<IR##typeName>(); varName->type = HiOpcodeEnum::typeName;
#define CreateAddIR(varName, typeName) IR##typeName* varName = pool.AllocIR<IR##typeName>(); varName->type = HiOpcodeEnum::typeName; curbb->insts.push_back(varName);


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
			RaiseHuatuoExecutionEngineException("GetEvalStackReduceDataType invalid type");
			return EvalStackReduceDataType::Other;
		}
		}
	}

	int32_t GetSizeByReduceType(EvalStackReduceDataType type)
	{
		switch (type)
		{
		case huatuo::transform::EvalStackReduceDataType::I4:
		case huatuo::transform::EvalStackReduceDataType::R4:
			return 4;
		case huatuo::transform::EvalStackReduceDataType::I8:
		case huatuo::transform::EvalStackReduceDataType::R8:
			return 8;
		default:
		{
			RaiseHuatuoExecutionEngineException("GetSizeByReduceType not support type");
			return PTR_SIZE;
		}
		}
	}

	inline int32_t GetActualParamCount(const MethodInfo* methodInfo)
	{
		return IsInstanceMethod(methodInfo) ? (methodInfo->parameters_count + 1) : methodInfo->parameters_count;
	}

	inline int32_t GetFieldOffset(const FieldInfo* fieldInfo)
	{
		Il2CppClass* klass = fieldInfo->parent;
		return IS_CLASS_VALUE_TYPE(klass) ? (fieldInfo->offset - sizeof(Il2CppObject)) : fieldInfo->offset;
	}

	inline uint32_t GetOrAddResolveDataIndex(std::unordered_map<const void*, uint32_t>& ptr2Index, std::vector<uint64_t>& resolvedDatas, const void* ptr)
	{
		auto it = ptr2Index.find(ptr);
		if (it != ptr2Index.end())
		{
			return it->second;
		}
		else
		{
			uint32_t newIndex = (uint32_t)resolvedDatas.size();
			resolvedDatas.push_back((uint64_t)ptr);
			ptr2Index.insert({ ptr, newIndex });
			return newIndex;
		}
	}

	template<typename T>
	void AllocResolvedData(std::vector<uint64_t>& resolvedDatas, int32_t size, int32_t& index, T*& buf)
	{
		if (size > 0)
		{
			int32_t oldSize = index = (int32_t)resolvedDatas.size();
			resolvedDatas.resize(oldSize + size);
			buf = (T*)&resolvedDatas[oldSize];
		}
		else
		{
			index = 0;
			buf = nullptr;
		}
	}

	inline IRCommon* CreateInitLocals(TemporaryMemoryArena& pool, uint32_t size)
	{
		CreateIR(ir, InitLocals_n_4);
		ir->size = size;
		return ir;
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

	inline IRCommon* CreateAssignVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, int32_t size)
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

	enum class LocationDescType
	{
		I1,
		U1,
		I2,
		U2,
		I4,
		I8,
		S,
	};

	struct LocationDescInfo
	{
		LocationDescType type;
		int32_t size;
	};

#if HUATUO_ARCH_64
#define NATIVE_INT_DESC_TYPE LocationDescType::I8
#else
#define NATIVE_INT_DESC_TYPE LocationDescType::I4
#endif

	inline LocationDescInfo ComputValueTypeDescInfo(int32_t size)
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
			RaiseHuatuoExecutionEngineException("not support arg type");
			return{ NATIVE_INT_DESC_TYPE, 0 };
		}
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
			RaiseHuatuoExecutionEngineException("field");
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
			RaiseHuatuoExecutionEngineException("field");
			return ir;
		}
		}
	}

	inline interpreter::IRCommon* CreateStfld(TemporaryMemoryArena& pool, int32_t objIdx, const FieldInfo* fieldInfo, int32_t dataIdx)
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
			RaiseHuatuoExecutionEngineException("field");
			return ir;
		}
		}
	}

	inline interpreter::IRCommon* CreateLdsfld(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent)
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
			RaiseHuatuoExecutionEngineException("field");
			return ir;
		}
		}
	}

	inline interpreter::IRCommon* CreateStsfld(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx)
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
			RaiseHuatuoExecutionEngineException("field");
			return ir;
		}
		}
	}

	inline int32_t GetThreadStaticFieldOffset(const FieldInfo* fieldInfo)
	{
		return il2cpp::vm::MetadataCache::GetThreadLocalStaticOffsetForField(const_cast<FieldInfo*>(fieldInfo));
	}

	inline interpreter::IRCommon* CreateLdthreadlocal(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent)
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
			RaiseHuatuoExecutionEngineException("field");
			return ir;
		}
	}
	}

	inline interpreter::IRCommon* CreateStthreadlocal(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx)
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
			RaiseHuatuoExecutionEngineException("field");
			return ir;
		}
		}
	}

	HiOpcodeEnum CalcGetMdArrElementVarVarOpcode(const Il2CppType* type)
	{
		LocationDescInfo desc = ComputLocationDescInfo(type);
		switch(desc.type)
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
			RaiseHuatuoExecutionEngineException("CalcGetMdArrElementVarVarOpcode");
			return (HiOpcodeEnum)0;
		}
		}
	}

	struct FlowInfo
	{
		uint32_t curStackSize;
		uint32_t offset;
		std::vector<EvalStackVarInfo> evalStack;
	};

	inline bool IsMulticastDelegate(const MethodInfo* method)
	{
		return  (method->klass) && method->klass->parent == il2cpp_defaults.multicastdelegate_class;
	}

	inline const Il2CppType* InflateIfNeeded(const Il2CppType* type, const Il2CppGenericContext* context, bool inflateMethodVars)
	{
		if (context == nullptr)
		{
			return type;
		}
		else
		{
			// FIXME memory leak
			return il2cpp::metadata::GenericMetadata::InflateIfNeeded(type, context, inflateMethodVars);
		}
	}

	struct TransformContext
	{
		metadata::Image* image;
		const MethodInfo* methodInfo;
		metadata::MethodBody& body;

		const Il2CppGenericContext* genericContext;
		const Il2CppGenericContainer* klassContainer;
		const Il2CppGenericContainer* methodContainer;
		int32_t actualParamCount;

		TemporaryMemoryArena& pool;
		const std::set<uint32_t>& splitOffsets;
		IRBasicBlock*& curbb;
		IRBasicBlock** ip2bb;

		ArgVarInfo* args;
		LocVarInfo* locals;
		EvalStackVarInfo* evalStack;
		int32_t evalStackBaseOffset;
		std::vector<uint64_t>& resolveDatas;
		std::unordered_map<uint32_t, uint32_t>& token2DataIdxs;
		std::unordered_map<const void*, uint32_t>& ptr2DataIdxs;
		std::vector<int32_t*>& relocationOffsets;
		std::vector<std::pair<int32_t, int32_t>>& switchOffsetsInResolveData;
		std::vector<FlowInfo*>& pendingFlows;
		int32_t& nextFlowIdx;

		int32_t& maxStackSize;
		int32_t& curStackSize;
		const byte* ipBase;
		const byte*& ip;
		int32_t& evalStackTop;

		int32_t& prefixFlags;
		uint32_t& argIdx;
		int32_t& varKst;
		int64_t& varKst8;
		int32_t& brOffset;

		const MethodInfo*& shareMethod;

		int32_t GetArgOffset(int32_t idx)
		{
			return args[idx].argOffset;
		}

		int32_t GetArgLocOffset(int32_t idx)
		{
			return args[idx].argLocOffset;
		}

		int32_t GetLocOffset(int32_t idx)
		{
			return locals[idx].locOffset;
		}

		int32_t GetEvalStackOffset(int32_t idx)
		{
			return idx < evalStackTop ? evalStack[idx].locOffset : curStackSize;
		}

		int32_t GetEvalStackTopOffset()
		{
			return evalStackTop > 0 ? evalStack[evalStackTop - 1].locOffset : curStackSize;
		}

		int32_t GetEvalStackNewTopOffset()
		{
			return curStackSize;
		}

		int32_t GetEvalStackOffset_5()
		{
			return evalStack[evalStackTop - 5].locOffset;
		}

		int32_t GetEvalStackOffset_4()
		{
			return evalStack[evalStackTop - 4].locOffset;
		}

		int32_t GetEvalStackOffset_3()
		{
			return evalStack[evalStackTop - 3].locOffset;
		}

		int32_t GetEvalStackOffset_2()
		{
			return evalStack[evalStackTop - 2].locOffset;
		}

		int32_t GetEvalStackOffset_1()
		{
			return evalStack[evalStackTop - 1].locOffset;
		}

		void PushStackByType(const Il2CppType* type)
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

		void PushStackByReduceType(EvalStackReduceDataType t)
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

		void DuplicateStack()
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

		void PopStack()
		{
			IL2CPP_ASSERT(evalStackTop > 0);
			--evalStackTop;
			curStackSize = evalStack[evalStackTop].locOffset;
		}

		void PopStackN(int32_t n)
		{
			IL2CPP_ASSERT(evalStackTop >= n && n >= 0);
			if (n > 0)
			{
				evalStackTop -= n;
				curStackSize = evalStack[evalStackTop].locOffset;
			}
		}

		void PopAllStack()
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

		void InsertMemoryBarrier()
		{
			if (prefixFlags & (int32_t)PrefixFlags::Volatile)
			{
				CreateAddIR(_mb, MemoryBarrier);
			}
		}

		void ResetPrefixFlags()
		{
			prefixFlags = 0;
		}

		void Add_ldind(HiOpcodeEnum opCode, EvalStackReduceDataType dataType)
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

		void Add_stind(HiOpcodeEnum opCode)
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

		void PushOffset(int32_t* offsetPtr)
		{
			IL2CPP_ASSERT(splitOffsets.find(*(offsetPtr)) != splitOffsets.end());
			relocationOffsets.push_back(offsetPtr);
		}

		void PushBranch(int32_t targetOffset)
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

		bool FindNextFlow()
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

		void AddInst(IRCommon* ir)
		{
			IL2CPP_ASSERT(ir->type);
			curbb->insts.push_back(ir);
		}

		void AddInst_ldarg(int32_t argIdx)
		{
			ArgVarInfo& __arg = args[argIdx];
			IRCommon* ir = CreateLoadExpandDataToStackVarVar(pool, GetEvalStackNewTopOffset(), __arg.argLocOffset, __arg.type, GetTypeValueSize(__arg.type));
			AddInst(ir);
			PushStackByType(__arg.type);
		}

		void AddInst_ldarga(int32_t argIdx)
		{
			IL2CPP_ASSERT(argIdx < actualParamCount);
			ArgVarInfo& argInfo = args[argIdx];
			CreateAddIR(ir, LdlocVarAddress);
			ir->dst = GetEvalStackNewTopOffset();
			ir->src = argInfo.argLocOffset;
			PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		}

		void AddInst_starg(int32_t argIdx)
		{
			IL2CPP_ASSERT(argIdx < actualParamCount);
			ArgVarInfo& __arg = args[argIdx];
			IRCommon* ir = CreateAssignVarVar(pool, __arg.argLocOffset, GetEvalStackTopOffset(), GetTypeValueSize(__arg.type));
			AddInst(ir);
			PopStack();
		}

		void CreateAddInst_ldloc(int32_t locIdx)
		{
			LocVarInfo& __loc = locals[locIdx];
			IRCommon* ir = CreateLoadExpandDataToStackVarVar(pool, GetEvalStackNewTopOffset(), __loc.locOffset, __loc.type, GetTypeValueSize(__loc.type));
			AddInst(ir);
			PushStackByType(__loc.type);
		}

		void CreateAddInst_stloc(int32_t locIdx)
		{
			LocVarInfo& __loc = locals[locIdx];
			IRCommon* ir = CreateAssignVarVar(pool, __loc.locOffset, GetEvalStackTopOffset(), GetTypeValueSize(__loc.type));
			AddInst(ir);
			PopStack();
		}

		void CreateAddInst_ldloca(int32_t locIdx)
		{
			CreateAddIR(ir, LdlocVarAddress);
			LocVarInfo& __loc = locals[locIdx];
			ir->dst = GetEvalStackNewTopOffset();
			ir->src = __loc.locOffset;
			PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		}

		void CreateAddInst_ldc4(int32_t c, EvalStackReduceDataType rtype)
		{
			CreateAddIR(ir, LdcVarConst_4);
			ir->dst = GetEvalStackNewTopOffset();
			ir->src = c;
			PushStackByReduceType(rtype);
		}

		void CreateAddInst_ldc8(int64_t c, EvalStackReduceDataType rtype)
		{
			CreateAddIR(ir, LdcVarConst_8);
			ir->dst = GetEvalStackNewTopOffset();
			ir->src = c;
			PushStackByReduceType(rtype);
		}

		void Add_brtruefalse(bool c, int32_t targetOffset)
		{
			EvalStackVarInfo& top = evalStack[evalStackTop - 1];
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
			PopStack();
			PushBranch(targetOffset);
		}

		void Add_bc(int32_t ipOffset, int32_t brOffset, int32_t opSize, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
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

		void Add_conv(int32_t dstTypeSize, EvalStackReduceDataType dstReduceType, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
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
					RaiseHuatuoExecutionEngineException("conv");
					break;
				}
				}
			}

			top.reduceType = dstReduceType;
			top.byteSize = dstTypeSize;
			ip++;
		}

		void Add_conv_ovf(int32_t dstTypeSize, EvalStackReduceDataType dstReduceType, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
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
					RaiseHuatuoExecutionEngineException("conv_ovf");
					break;
				}
				}
			}

			top.reduceType = dstReduceType;
			top.byteSize = dstTypeSize;
			ip++;
		}

		void Add_binop(HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
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
					RaiseHuatuoExecutionEngineException("Add_bin_op I4 op unknown");
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
					RaiseHuatuoExecutionEngineException("Add_bin_op I8 op unknown");
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
					RaiseHuatuoExecutionEngineException("Add_bin_op R4 op unknown");
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
					RaiseHuatuoExecutionEngineException("Add_bin_op R8 op unknown");
					break;
				}
				}
				break;
			}
			default:
			{
				RaiseHuatuoExecutionEngineException("Add_bin_op unknown");
				break;
			}
			}
			PopStack();
			op1.reduceType = resultType;
			op1.byteSize = GetSizeByReduceType(resultType);
			AddInst(ir);
			ip++;
		}
	
		void Add_shiftop(HiOpcodeEnum opI4I4, HiOpcodeEnum opI4I8, HiOpcodeEnum opI8I4, HiOpcodeEnum opI8I8)
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
					RaiseHuatuoExecutionEngineException("shitf i4");
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
					RaiseHuatuoExecutionEngineException("shitf i8");
					break;
				}
				}
				break;
			}
			default:
			{
				RaiseHuatuoExecutionEngineException("shitf i");
				break;
			}
			}
			PopStack();
			ip++;
		}
	
		void Add_compare(HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8)
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
					RaiseHuatuoExecutionEngineException("compare i4");
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
					RaiseHuatuoExecutionEngineException("compare i8");
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
					RaiseHuatuoExecutionEngineException("compare r4");
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
					RaiseHuatuoExecutionEngineException("compare r8");
				}
				break;
			}
			default:
			{
				RaiseHuatuoExecutionEngineException("compare");
				break;
			}
			}
			PopStackN(2);
			AddInst(ir);
			PushStackByReduceType(EvalStackReduceDataType::I4);
		}

		void Add_ldelem(EvalStackReduceDataType resultType, HiOpcodeEnum opI4, HiOpcodeEnum opI8)
		{
			IL2CPP_ASSERT(evalStackTop >= 2);
			EvalStackVarInfo& arr = evalStack[evalStackTop - 2];
			EvalStackVarInfo& index = evalStack[evalStackTop - 1];

			CreateAddIR(ir, GetArrayElementVarVar_i1_8);
			ir->arr = arr.locOffset;
			ir->index = index.locOffset;
			ir->dst = arr.locOffset;

			switch (index.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				ir->type = opI8;
				break;
			}
			default:
			{
				RaiseHuatuoExecutionEngineException("ldelem");
			}
			}
			PopStackN(2);
			PushStackByReduceType(resultType);
			ip++;
		}

		void Add_stelem(HiOpcodeEnum opI4, HiOpcodeEnum opI8)
		{
			IL2CPP_ASSERT(evalStackTop >= 3); 
			EvalStackVarInfo& arr = evalStack[evalStackTop - 3];
			EvalStackVarInfo& index = evalStack[evalStackTop - 2];
			EvalStackVarInfo& ele = evalStack[evalStackTop - 1];

			CreateAddIR(ir, SetArrayElementVarVar_i1_4);
			ir->arr = arr.locOffset;
			ir->index = index.locOffset;
			ir->ele = ele.locOffset;

			switch (index.reduceType)
			{
			case EvalStackReduceDataType::I4:
			{
				ir->type = opI4;
				break;
			}
			case EvalStackReduceDataType::I8:
			{
				ir->type = opI8;
				break;
			}
			default:
			{
				RaiseHuatuoExecutionEngineException("stelem");
			}
			}
			PopStackN(3);
			ip++;
		}


		bool FindFirstLeaveHandlerIndex(const std::vector<ExceptionClause>& exceptionClauses, uint32_t leaveOffset, uint32_t targetOffset, uint16_t& index)
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

		bool IsLeaveInTryBlock(const std::vector<ExceptionClause>& exceptionClauses, uint32_t leaveOffset)
		{
			for (const ExceptionClause& ec : exceptionClauses)
			{
				if (ec.tryOffset <= leaveOffset && leaveOffset < ec.tryOffset + ec.tryLength)
				{
					return true;
				}
				if (ec.handlerOffsets <= leaveOffset && leaveOffset < ec.handlerLength + ec.handlerLength)
				{
					return false;
				}
			}
			return false;
		}

		void Add_leave(uint32_t targetOffset)
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

		uint16_t FindFirstThrowHandlerIndex(const std::vector<ExceptionClause>& exceptionClauses, uint32_t throwOffset)
		{
			uint16_t index = 0;
			for (const ExceptionClause& ec : exceptionClauses)
			{
				if (ec.flags == CorILExceptionClauseType::Finally)
				{
					if (ec.tryOffset <= throwOffset && throwOffset < ec.tryOffset + ec.tryLength)
						return index;
				}
				++index;
			}
			return index;
		}
	};

#pragma region conv

#define CI_conv(dstTypeName, dstReduceType, dstTypeSize)   \
	ctx.Add_conv(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertVarVar_i4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_i8_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f8_##dstTypeName);

#define CI_conv_un(dstTypeName, dstReduceType, dstTypeSize)   \
	ctx.Add_conv(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertVarVar_u4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_u8_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertVarVar_f8_##dstTypeName);

#define CI_conv_ovf(dstTypeName, dstReduceType, dstTypeSize)   \
	ctx.Add_conv_ovf(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertOverflowVarVar_i4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_i8_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f8_##dstTypeName);

#define CI_conv_un_ovf(dstTypeName, dstReduceType, dstTypeSize)   \
	ctx.Add_conv_ovf(dstTypeSize, EvalStackReduceDataType::dstReduceType, \
		HiOpcodeEnum::ConvertOverflowVarVar_u4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_u8_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f4_##dstTypeName,\
		HiOpcodeEnum::ConvertOverflowVarVar_f8_##dstTypeName);


#pragma endregion

#pragma region branch

#define CI_branch1(opName) IL2CPP_ASSERT(evalStackTop >= 2); \
brOffset = GetI1(ip+1); \
ctx.Add_bc(ipOffset, brOffset, 2, HiOpcodeEnum::BranchVarVar_##opName##_i4, HiOpcodeEnum::BranchVarVar_##opName##_i8, HiOpcodeEnum::BranchVarVar_##opName##_f4, HiOpcodeEnum::BranchVarVar_##opName##_f8); \
ip += 2;

#define CI_branch4(opName) IL2CPP_ASSERT(evalStackTop >= 2); \
brOffset = GetI4LittleEndian(ip + 1); \
ctx.Add_bc(ipOffset, brOffset, 5, HiOpcodeEnum::BranchVarVar_##opName##_i4, HiOpcodeEnum::BranchVarVar_##opName##_i8, HiOpcodeEnum::BranchVarVar_##opName##_f4, HiOpcodeEnum::BranchVarVar_##opName##_f8); \
ip += 5;

#define PopBranch() { \
if (ctx.FindNextFlow()) \
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
#define CI_binOp(op) ctx.Add_binop(HiOpcodeEnum::BinOpVarVarVar_##op##_i4, HiOpcodeEnum::BinOpVarVarVar_##op##_i8, HiOpcodeEnum::BinOpVarVarVar_##op##_f4, HiOpcodeEnum::BinOpVarVarVar_##op##_f8);
#define CI_binOpUn(op) ctx.Add_binop(HiOpcodeEnum::BinOpVarVarVar_##op##_i4, HiOpcodeEnum::BinOpVarVarVar_##op##_i8, (HiOpcodeEnum)0, (HiOpcodeEnum)0);
#define CI_binOpOvf(op) ctx.Add_binop(HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_i4, HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_i8, (HiOpcodeEnum)0, (HiOpcodeEnum)0);
#define CI_binOpUnOvf(op) ctx.Add_binop(HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_u4, HiOpcodeEnum::BinOpOverflowVarVarVar_##op##_u8, (HiOpcodeEnum)0, (HiOpcodeEnum)0);
#pragma endregion

#pragma region shiftop
#define	CI_binOpShift(op) ctx.Add_shiftop(HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i4_i4, HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i4_i8, HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i8_i4, HiOpcodeEnum::BitShiftBinOpVarVarVar_##op##_i8_i8);
#pragma endregion

#define CI_compare(op) ctx.Add_compare(HiOpcodeEnum::CompOpVarVarVar_##op##_i4, HiOpcodeEnum::CompOpVarVarVar_##op##_i8, HiOpcodeEnum::CompOpVarVarVar_##op##_f4, HiOpcodeEnum::CompOpVarVarVar_##op##_f8);

#define CI_ldele(eleType, resultType) ctx.Add_ldelem(EvalStackReduceDataType::resultType, HiOpcodeEnum::GetArrayElementVarVar_##eleType##_4, HiOpcodeEnum::GetArrayElementVarVar_##eleType##_8);
#define CI_stele(eleType) ctx.Add_stelem(HiOpcodeEnum::SetArrayElementVarVar_##eleType##_4, HiOpcodeEnum::SetArrayElementVarVar_##eleType##_8);


	void HiTransform::Transform(metadata::Image* image, const MethodInfo* methodInfo, metadata::MethodBody& body, interpreter::InterpMethodInfo& result)
	{
#pragma region header
		const Il2CppGenericContext* genericContext = methodInfo->is_inflated ? &methodInfo->genericMethod->context : nullptr;
		const Il2CppGenericContainer* klassContainer = GetGenericContainerFromIl2CppType(&methodInfo->klass->byval_arg);
		const Il2CppGenericContainer* methodContainer = methodInfo->is_inflated ?
			(const Il2CppGenericContainer*)methodInfo->genericMethod->methodDefinition->genericContainerHandle :
			(const Il2CppGenericContainer*)methodInfo->genericContainerHandle;

		TemporaryMemoryArena pool;
		BasicBlockSpliter bbc(body);
		bbc.SplitBasicBlocks();

		const std::set<uint32_t>& splitOffsets = bbc.GetSplitOffsets();

		IRBasicBlock** ip2bb = pool.NewNAny<IRBasicBlock*>(body.codeSize + 1);
		uint32_t lastSplitBegin = 0;

		std::vector<IRBasicBlock*> irbbs;
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
		IRBasicBlock endBb = { true, false, body.codeSize, 0 };
		ip2bb[body.codeSize] = &endBb;

		IRBasicBlock* curbb = irbbs[0];

		IL2CPP_ASSERT(lastSplitBegin == body.codeSize);

		bool instanceCall = IsInstanceMethod(methodInfo);
		int32_t actualParamCount = methodInfo->parameters_count + instanceCall;

		ArgVarInfo* args = pool.NewNAny<ArgVarInfo>(actualParamCount);
		LocVarInfo* locals = pool.NewNAny<LocVarInfo>(body.localVarCount);
		// FIXME may exceed max size
		// TODO MEMORY OPTIMISTIC
		EvalStackVarInfo* evalStack = pool.NewNAny<EvalStackVarInfo>(body.maxStack + 100);

		std::vector<uint64_t>& resolveDatas = result.resolveDatas;
		// TODO. alloc use pool
		std::unordered_map<uint32_t, uint32_t> token2DataIdxs;
		// TOTO. alloc use pool
		std::unordered_map<const void*, uint32_t> ptr2DataIdxs;

		resolveDatas.push_back(0); // reserved


		std::vector<int32_t*> relocationOffsets;
		// index, count 
		std::vector<std::pair<int32_t, int32_t>> switchOffsetsInResolveData;
		std::vector<FlowInfo*> pendingFlows;
		int32_t nextFlowIdx = 0;

		int32_t totalArgSize = 0;
		{
			int32_t idx = 0;
			if (instanceCall)
			{
				ArgVarInfo& self = args[0];
				self.klass = methodInfo->klass;
				self.type = IS_CLASS_VALUE_TYPE(self.klass) ? &self.klass->this_arg : &self.klass->byval_arg;
				self.argOffset = idx;
				self.argLocOffset = totalArgSize;
				totalArgSize += GetTypeValueStackObjectCount(self.type);
				idx = 1;
			}

			for (uint32_t i = 0; i < methodInfo->parameters_count; i++)
			{
				ArgVarInfo& arg = args[idx + i];
				arg.type = InflateIfNeeded((Il2CppType*)(GET_METHOD_PARAMETER_TYPE(methodInfo->parameters[i])), genericContext, true);
				arg.klass = il2cpp::vm::Class::FromIl2CppType(arg.type);
				arg.argOffset = idx + i;
				arg.argLocOffset = totalArgSize;
				il2cpp::vm::Class::SetupFields(arg.klass);
				totalArgSize += GetTypeValueStackObjectCount(arg.type);
			}
		}

		int32_t totalArgLocalSize = totalArgSize;
		for (uint32_t i = 0; i < body.localVarCount; i++)
		{
			LocVarInfo& local = locals[i];
			// FIXME memory leak
			local.type = InflateIfNeeded(body.localVars + i, genericContext, true);
			local.klass = il2cpp::vm::Class::FromIl2CppType(local.type);
			il2cpp::vm::Class::SetupFields(local.klass);
			local.locOffset = totalArgLocalSize;
			totalArgLocalSize += GetTypeValueStackObjectCount(local.type);
		}

		int32_t evalStackBaseOffset = totalArgLocalSize;
		int32_t totalLocalSize = totalArgLocalSize - totalArgSize;

		int32_t maxStackSize = evalStackBaseOffset;
		int32_t curStackSize = evalStackBaseOffset;



		const byte* ipBase = body.ilcodes;

		const byte* ip = body.ilcodes;

		int32_t evalStackTop = 0;
		int32_t prefixFlags = 0;

		uint32_t argIdx = 0;
		int32_t varKst = 0;
		int64_t varKst8 = 0;
		int32_t brOffset = 0;
		const MethodInfo* shareMethod = nullptr;

		TransformContext ctx =
		{
			image,
			methodInfo,
			body,
			genericContext,
			klassContainer,
			methodContainer,
			actualParamCount,

			pool,
			splitOffsets,
			curbb,
			ip2bb,
			args,
			locals,
			evalStack,
			evalStackBaseOffset,
			resolveDatas,
			token2DataIdxs,
			ptr2DataIdxs,
			relocationOffsets,
			switchOffsetsInResolveData,
			pendingFlows,
			nextFlowIdx,

			maxStackSize,
			curStackSize,
			ipBase,
			ip,
			evalStackTop,

			prefixFlags,
			argIdx,
			varKst,
			varKst8,
			brOffset,
			shareMethod,
		};


		// init local vars
		if (body.flags & (uint32_t)CorILMethodFormat::InitLocals)
		{
			ctx.AddInst(CreateInitLocals(pool, totalLocalSize * sizeof(StackObject)));
		}

		for (ExceptionClause& ec : body.exceptionClauses)
		{
			InterpExceptionClause* iec = (InterpExceptionClause*)IL2CPP_MALLOC_ZERO(sizeof(InterpExceptionClause));
			iec->flags = ec.flags;
			iec->tryBeginOffset = ec.tryOffset;
			iec->tryEndOffset = ec.tryOffset + ec.tryLength;
			iec->handlerBeginOffset = ec.handlerOffsets;
			iec->handlerEndOffset = ec.handlerOffsets + ec.handlerLength;
			ctx.PushOffset(&iec->tryBeginOffset);
			ctx.PushOffset(&iec->tryEndOffset);
			ctx.PushOffset(&iec->handlerBeginOffset);
			ctx.PushOffset(&iec->handlerEndOffset);
			if (ec.flags == CorILExceptionClauseType::Exception)
			{
				iec->filterBeginOffset = 0;
				iec->exKlass = image->GetClassFromToken(ec.classTokenOrFilterOffset, klassContainer, methodContainer, genericContext);
			}
			else if (ec.flags == CorILExceptionClauseType::Filter)
			{
				iec->filterBeginOffset = ec.classTokenOrFilterOffset;
				ctx.PushOffset(&iec->filterBeginOffset);
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
				RaiseHuatuoExecutionEngineException("");
			}
			}
			result.exClauses.push_back(iec);
		}

#pragma endregion

		IRBasicBlock* lastBb = nullptr;
		for (;;)
		{
			int32_t ipOffset = (int32_t)(ip - ipBase);
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
				ctx.AddInst_ldarg(0);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_1:
			{
				ctx.AddInst_ldarg(1);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_2:
			{
				ctx.AddInst_ldarg(2);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_3:
			{
				ctx.AddInst_ldarg(3);
				ip++;
				continue;
			}

			case OpcodeValue::LDLOC_0:
			{
				ctx.CreateAddInst_ldloc(0);
				ip++;
				continue;
			}
			case OpcodeValue::LDLOC_1:
			{
				ctx.CreateAddInst_ldloc(1);
				ip++;
				continue;
			}
			case OpcodeValue::LDLOC_2:
			{
				ctx.CreateAddInst_ldloc(2);
				ip++;
				continue;
			}
			case OpcodeValue::LDLOC_3:
			{
				ctx.CreateAddInst_ldloc(3);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_0:
			{
				ctx.CreateAddInst_stloc(0);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_1:
			{
				ctx.CreateAddInst_stloc(1);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_2:
			{
				ctx.CreateAddInst_stloc(2);
				ip++;
				continue;
			}
			case OpcodeValue::STLOC_3:
			{
				ctx.CreateAddInst_stloc(3);
				ip++;
				continue;
			}
			case OpcodeValue::LDARG_S:
			{
				argIdx = ip[1];
				ctx.AddInst_ldarg(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDARGA_S:
			{
				argIdx = ip[1];
				ctx.AddInst_ldarga(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::STARG_S:
			{
				argIdx = ip[1];
				ctx.AddInst_starg(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDLOC_S:
			{
				argIdx = ip[1];
				ctx.CreateAddInst_ldloc(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDLOCA_S:
			{
				argIdx = ip[1];
				ctx.CreateAddInst_ldloca(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::STLOC_S:
			{
				argIdx = ip[1];
				ctx.CreateAddInst_stloc(argIdx);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDNULL:
			{
				CreateAddIR(ir, LdnullVar);
				ir->dst = curStackSize;
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_M1:
			{
				ctx.CreateAddInst_ldc4(-1, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_0:
			{
				ctx.CreateAddInst_ldc4(0, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_1:
			{
				ctx.CreateAddInst_ldc4(1, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_2:
			{
				ctx.CreateAddInst_ldc4(2, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_3:
			{
				ctx.CreateAddInst_ldc4(3, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_4:
			{
				ctx.CreateAddInst_ldc4(4, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_5:
			{
				ctx.CreateAddInst_ldc4(5, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_6:
			{
				ctx.CreateAddInst_ldc4(6, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_7:
			{
				ctx.CreateAddInst_ldc4(7, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_8:
			{
				ctx.CreateAddInst_ldc4(8, EvalStackReduceDataType::I4);
				ip++;
				continue;
			}
			case OpcodeValue::LDC_I4_S:
			{
				varKst = GetI1(ip + 1);
				ctx.CreateAddInst_ldc4(varKst, EvalStackReduceDataType::I4);
				ip += 2;
				continue;
			}
			case OpcodeValue::LDC_I4:
			{
				varKst = GetI4LittleEndian(ip + 1);
				ctx.CreateAddInst_ldc4(varKst, EvalStackReduceDataType::I4);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDC_I8:
			{
				varKst8 = GetI8LittleEndian(ip + 1);
				ctx.CreateAddInst_ldc8(varKst8, EvalStackReduceDataType::I8);
				ip += 9;
				continue;
			}
			case OpcodeValue::LDC_R4:
			{
				varKst = GetI4LittleEndian(ip + 1);
				ctx.CreateAddInst_ldc4(varKst, EvalStackReduceDataType::R4);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDC_R8:
			{
				varKst8 = GetI8LittleEndian(ip + 1);
				ctx.CreateAddInst_ldc8(varKst8, EvalStackReduceDataType::R8);
				ip += 9;
				continue;
			}
			case OpcodeValue::DUP:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				EvalStackVarInfo& __eval = evalStack[evalStackTop - 1];
				IRCommon* ir = CreateAssignVarVar(pool, ctx.GetEvalStackNewTopOffset(), __eval.locOffset, __eval.byteSize);
				ctx.AddInst(ir);
				ctx.DuplicateStack();
				ip++;
				continue;
			}
			case OpcodeValue::POP:
			{
				ctx.PopStack();
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
				RaiseHuatuoNotSupportedException("not support jmp");
				continue;
			}
			case OpcodeValue::CALL:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				ip += 5;
				shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(shareMethod);
			}

		LabelCall:
			{
				IL2CPP_ASSERT(shareMethod);
				Il2CppClass* klass = shareMethod->klass;
				const char* klassName = klass->name;
				const char* methodName = shareMethod->name;
				uint32_t paramCount = shareMethod->parameters_count;
#pragma region instrinct
				if (std::strcmp(klass->namespaze, "System") == 0)
				{
					if (std::strcmp(klassName, "Object") == 0)
					{
						// special handle
						if (strcmp(methodName, ".ctor") == 0)
						{
							ctx.PopStack();
							continue;
						}
						// get_HasValue
						// do nothing
					}
					else if (std::strcmp(klassName, "Nullable`1") == 0)
					{
						il2cpp::vm::Class::SetupFields(klass);
						uint16_t topOffset = ctx.GetEvalStackTopOffset();
						uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
						if (strcmp(methodName, ".ctor") == 0)
						{
							if (paramCount == 1)
							{
								CreateAddIR(ir, NullableCtorVarVar);
								ir->dst = ctx.GetEvalStackOffset_2();
								ir->data = ctx.GetEvalStackOffset_1();
								ir->klass = classIndirectIndex;

								ctx.PopStackN(2);
								continue;
							}
						}
						else if (strcmp(methodName, "GetValueOrDefault") == 0)
						{
							uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
							if (paramCount == 0)
							{
								CreateAddIR(ir, NullableGetValueOrDefaultVarVar);
								ir->dst = topOffset;
								ir->obj = topOffset;
								ir->klass = classIndirectIndex;

								// pop this, push value
								ctx.PopStack();
								ctx.PushStackByType(&klass->castClass->byval_arg);
								continue;
							}
							else if (paramCount == 1)
							{
								CreateAddIR(ir, NullableGetValueOrDefaultVarVar_1);
								ir->dst = ir->obj = ctx.GetEvalStackOffset_2();
								ir->defaultValue = topOffset;
								ir->klass = classIndirectIndex;

								// pop this, default value then push value
								ctx.PopStackN(2);
								ctx.PushStackByType(&klass->castClass->byval_arg);
								continue;
							}
						}
						else if (strcmp(methodName, "get_HasValue") == 0)
						{
							uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
							CreateAddIR(ir, NullableHasValueVar);
							ir->result = topOffset;
							ir->obj = topOffset;
							ir->klass = classIndirectIndex;

							// pop this, push value
							ctx.PopStack();
							ctx.PushStackByReduceType(EvalStackReduceDataType::I4);
							continue;
						}
						else if (strcmp(methodName, "get_Value") == 0)
						{
							uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
							CreateAddIR(ir, NullableGetValueVarVar);
							ir->dst = topOffset;
							ir->obj = topOffset;
							ir->klass = classIndirectIndex;

							// pop this, push value
							ctx.PopStack();
							ctx.PushStackByType(&klass->castClass->byval_arg);
							continue;
						}
					}
				}
				else if (strcmp(klass->namespaze, "System.Threading") == 0)
				{
					if (strcmp(klassName, "Interlocked") == 0)
					{
						if (strcmp(methodName, "CompareExchange") == 0)
						{
							IL2CPP_ASSERT(evalStackTop >= 3);
							uint16_t retIdx = ctx.GetEvalStackOffset_3();
							uint16_t locationIdx = retIdx;
							uint16_t valueIdx = ctx.GetEvalStackOffset_2();
							uint16_t comparandIdx = ctx.GetEvalStackOffset_1();

							CreateAddIR(ir, InterlockedCompareExchangeVarVarVarVar_pointer);
							ir->ret = retIdx;
							ir->location = locationIdx;
							ir->value = valueIdx;
							ir->comparand = comparandIdx;

							const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(shareMethod->parameters[1]);
							if (!paramType->byref)
							{
								Il2CppClass* paramKlass = il2cpp::vm::Class::FromIl2CppType(paramType);
								if (IS_CLASS_VALUE_TYPE(paramKlass))
								{
									uint32_t valueSize = GetTypeValueSize(paramKlass);
									if (valueSize == 4)
									{
										ir->type = HiOpcodeEnum::InterlockedCompareExchangeVarVarVarVar_i4;
									}
									else if (valueSize == 8)
									{
										ir->type = HiOpcodeEnum::InterlockedCompareExchangeVarVarVarVar_i8;
									}
									else
									{
										RaiseHuatuoExecutionEngineException("not support System.Threading.Interlocked.CompareExchange");
									}
								}
							}
							ctx.PopStackN(3);
							ctx.PushStackByType(paramType);

							continue;
						}
						else if (strcmp(methodName, "Exchange") == 0)
						{
							IL2CPP_ASSERT(evalStackTop >= 3);
							uint16_t retIdx = ctx.GetEvalStackOffset_2();
							uint16_t locationIdx = retIdx;
							uint16_t valueIdx = ctx.GetEvalStackOffset_1();

							CreateAddIR(ir, InterlockedExchangeVarVarVar_pointer);
							ir->ret = retIdx;
							ir->location = locationIdx;
							ir->value = valueIdx;

							const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(shareMethod->parameters[1]);
							if (!paramType->byref)
							{
								Il2CppClass* paramKlass = il2cpp::vm::Class::FromIl2CppType(paramType);
								if (IS_CLASS_VALUE_TYPE(paramKlass))
								{
									uint32_t valueSize = GetTypeValueSize(paramKlass);
									if (valueSize == 4)
									{
										ir->type = HiOpcodeEnum::InterlockedExchangeVarVarVar_i4;
									}
									else if (valueSize == 8)
									{
										ir->type = HiOpcodeEnum::InterlockedExchangeVarVarVar_i8;
									}
									else
									{
										RaiseHuatuoExecutionEngineException("not support System.Threading.Interlocked.Exchange");
									}
								}
							}
							ctx.PopStackN(2);
							ctx.PushStackByType(paramType);
							continue;
						}
					}
				}
				else if (strcmp(klass->namespaze, "UnityEngine") == 0)
				{
					if (strcmp(methodName, ".ctor") == 0)
					{
						if (strcmp(klassName, "Vector2") == 0)
						{
							if (paramCount == 3)
							{
								IL2CPP_ASSERT(evalStackTop >= 3);
								CreateAddIR(ir, NewVector2);
								ir->obj = ctx.GetEvalStackOffset_3();
								ir->x = ctx.GetEvalStackOffset_2();
								ir->y = ctx.GetEvalStackOffset_1();
								ctx.PopStackN(3);
								continue;
							}
						}
						else if (strcmp(klassName, "Vector3") == 0)
						{
							switch (paramCount)
							{
							case 2:
							{
								IL2CPP_ASSERT(evalStackTop >= 3);
								CreateAddIR(ir, NewVector3_2);
								ir->obj = ctx.GetEvalStackOffset_3();
								ir->x = ctx.GetEvalStackOffset_2();
								ir->y = ctx.GetEvalStackOffset_1();
								ctx.PopStackN(3);
								continue;
							}
							case 3:
							{
								IL2CPP_ASSERT(evalStackTop >= 4);
								CreateAddIR(ir, NewVector3_3);
								ir->obj = ctx.GetEvalStackOffset_4();
								ir->x = ctx.GetEvalStackOffset_3();
								ir->y = ctx.GetEvalStackOffset_2();
								ir->z = ctx.GetEvalStackOffset_1();
								ctx.PopStackN(4);
								continue;
							}
							default:
								break;
							}
						}
						else if (strcmp(klassName, "Vector4") == 0)
						{
							switch (paramCount)
							{
							case 2:
							{
								IL2CPP_ASSERT(evalStackTop >= 3);
								CreateAddIR(ir, NewVector4_2);
								ir->obj = ctx.GetEvalStackOffset_3();
								ir->x = ctx.GetEvalStackOffset_2();
								ir->y = ctx.GetEvalStackOffset_1();
								ctx.PopStackN(3);
								continue;
							}
							case 3:
							{
								IL2CPP_ASSERT(evalStackTop >= 4);
								CreateAddIR(ir, NewVector4_3);
								ir->obj = ctx.GetEvalStackOffset_4();
								ir->x = ctx.GetEvalStackOffset_3();
								ir->y = ctx.GetEvalStackOffset_2();
								ir->z = ctx.GetEvalStackOffset_1();
								ctx.PopStackN(4);
								continue;
							}
							case 4:
							{
								IL2CPP_ASSERT(evalStackTop >= 5);
								CreateAddIR(ir, NewVector4_4);
								ir->obj = ctx.GetEvalStackOffset_5();
								ir->x = ctx.GetEvalStackOffset_4();
								ir->y = ctx.GetEvalStackOffset_3();
								ir->z = ctx.GetEvalStackOffset_2();
								ir->w = ctx.GetEvalStackOffset_1();
								ctx.PopStackN(5);
								continue;
							}
							default:
								break;
							}
						}
					}
				}

				// warn! can't change to else if. because namespace == system
				if (klass->byval_arg.type == IL2CPP_TYPE_ARRAY)
				{
					const char* methodName = shareMethod->name;
					uint8_t paramCount = shareMethod->parameters_count + 1;
					if (strcmp(methodName, "Get") == 0)
					{
						CreateAddIR(ir, GetMdArrElementVarVar_size);
						ir->type = CalcGetMdArrElementVarVarOpcode(&klass->element_class->byval_arg);
						ir->arr = ctx.GetEvalStackOffset(evalStackTop - paramCount);
						ir->lengthIdxs = ir->arr + 1;
						ctx.PopStackN(paramCount);
						ctx.PushStackByType(&klass->element_class->byval_arg);
						ir->value = ctx.GetEvalStackTopOffset();
						continue;
					}
					else if (strcmp(methodName, "Address") == 0)
					{
						CreateAddIR(ir, GetMdArrElementAddressVarVar);
						ir->arr = ctx.GetEvalStackOffset(evalStackTop - paramCount);
						ir->lengthIdxs = ir->arr + 1;
						ctx.PopStackN(paramCount);
						ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
						ir->addr = ctx.GetEvalStackTopOffset();
						continue;
					}
					else if (strcmp(methodName, "Set") == 0)
					{
						CreateAddIR(ir, SetMdArrElementVarVar);
						ir->arr = ctx.GetEvalStackOffset(evalStackTop - paramCount);
						ir->lengthIdxs = ir->arr + 1;
						ir->value = ctx.GetEvalStackTopOffset();
						ctx.PopStackN(paramCount);
						continue;
					}
				}


#pragma endregion

				bool resolvedIsInstanceMethod = IsInstanceMethod(shareMethod);
				int32_t resolvedTotalArgdNum = shareMethod->parameters_count + resolvedIsInstanceMethod;
				int32_t needDataSlotNum = (resolvedTotalArgdNum + 3) / 4;
				int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgdNum;
				uint32_t methodDataIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, shareMethod);

				if (huatuo::metadata::IsInterpreterType(klass))
				{
					ctx.PopStackN(resolvedTotalArgdNum);

					uint16_t argBaseOffset = (uint16_t)ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
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
						ctx.PushStackByType(shareMethod->return_type);
					}
					continue;
				}

				if (!shareMethod->invoker_method || !shareMethod->methodPointer)
				{
					RaiseAOTGenericMethodNotInstantiatedException(shareMethod);
				}

				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, (void*)managed2NativeMethod);

				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);

				if (resolvedIsInstanceMethod)
				{
					__argIdxs[0] = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
#if VALUE_TYPE_METHOD_POINTER_IS_ADJUST_METHOD
					if (IS_CLASS_VALUE_TYPE(shareMethod->klass))
					{
						CreateAddIR(ir, AdjustValueTypeRefVar);
						ir->data = __argIdxs[0];
					}
#endif
				}

				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + resolvedIsInstanceMethod;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				ctx.PopStackN(resolvedTotalArgdNum);

				if (!IsReturnVoidMethod(shareMethod))
				{
					ctx.PushStackByType(shareMethod->return_type);
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(shareMethod->return_type);
					if (interpreter::IsNeedExpandLocationType(locDataType))
					{
						CreateAddIR(ir, CallNative_ret_expand);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = ctx.GetEvalStackTopOffset();
						ir->retLocationType = (uint8_t)locDataType;
					}
					else
					{
						CreateAddIR(ir, CallNative_ret);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = ctx.GetEvalStackTopOffset();
					}
				}
				else
				{
					CreateAddIR(ir, CallNative_void);
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
				shareMethod = image->GetMethodInfoFromToken(token, klassContainer, methodContainer, genericContext);
			}
		LabelCallVir:
			{
				// TODO token cache optimistic
				IL2CPP_ASSERT(shareMethod);
				IL2CPP_ASSERT(huatuo::metadata::IsInstanceMethod(shareMethod));

				int32_t resolvedTotalArgdNum = shareMethod->parameters_count + 1;
				int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgdNum;
				uint32_t methodDataIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, shareMethod);

				bool isMultiDelegate = IsMulticastDelegate(shareMethod);
				if (!isMultiDelegate && IsInterpreterMethod(shareMethod))
				{
					ctx.PopStackN(resolvedTotalArgdNum);

					uint16_t argBaseOffset = (uint16_t)ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
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
						ctx.PushStackByType(shareMethod->return_type);
					}
					continue;
				}

				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, (void*)managed2NativeMethod);


				int32_t needDataSlotNum = (resolvedTotalArgdNum + 3) / 4;
				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);

				__argIdxs[0] = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + 1;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				ctx.PopStackN(resolvedTotalArgdNum);

				const Il2CppType* returnType = shareMethod->return_type;
				int32_t retIdx;

				if (returnType->type != IL2CPP_TYPE_VOID)
				{
					ctx.PushStackByType(returnType);
					retIdx = ctx.GetEvalStackTopOffset();
				}
				else
				{
					retIdx = -1;
				}
				if (!isMultiDelegate)
				{
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
				}
				else
				{

					Managed2NativeCallMethod staticManaged2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, true);
					IL2CPP_ASSERT(staticManaged2NativeMethod);
					uint32_t staticManaged2NativeMethodDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, (void*)staticManaged2NativeMethod);
					if (retIdx < 0)
					{
						CreateAddIR(ir, CallDelegate_void);
						ir->managed2NativeStaticMethod = staticManaged2NativeMethodDataIdx;
						ir->managed2NativeInstanceMethod = managed2NativeMethodDataIdx;
						ir->argIdxs = argIdxDataIndex;
						ir->invokeParamCount = shareMethod->parameters_count;
					}
					else
					{
						interpreter::LocationDataType locDataType = GetLocationDataTypeByType(returnType);
						if (IsNeedExpandLocationType(locDataType))
						{
							CreateAddIR(ir, CallDelegate_ret_expand);
							ir->managed2NativeStaticMethod = staticManaged2NativeMethodDataIdx;
							ir->managed2NativeInstanceMethod = managed2NativeMethodDataIdx;
							ir->argIdxs = argIdxDataIndex;
							ir->ret = retIdx;
							ir->invokeParamCount = shareMethod->parameters_count;
							ir->retLocationType = (uint8_t)locDataType;
						}
						else
						{
							CreateAddIR(ir, CallDelegate_ret);
							ir->managed2NativeStaticMethod = staticManaged2NativeMethodDataIdx;
							ir->managed2NativeInstanceMethod = managed2NativeMethodDataIdx;
							ir->argIdxs = argIdxDataIndex;
							ir->ret = retIdx;
							ir->invokeParamCount = shareMethod->parameters_count;
						}
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

				int32_t methodIdx = ctx.GetEvalStackTopOffset();
				//uint32_t methodDataIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, shareMethod);
				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(methodSig);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, (void*)managed2NativeMethod);


				int32_t resolvedTotalArgdNum = methodSig.paramCount;
				int32_t needDataSlotNum = (resolvedTotalArgdNum + 3) / 4;
				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);


				int32_t callArgEvalStackIdxBase = evalStackTop - resolvedTotalArgdNum - 1 /*funtion ptr*/;
				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				ctx.PopStackN(resolvedTotalArgdNum + 1);

				if (!IsReturnVoidMethod(shareMethod))
				{
					ctx.PushStackByType(shareMethod->return_type);
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(shareMethod->return_type);
					if (interpreter::IsNeedExpandLocationType(locDataType))
					{
						CreateAddIR(ir, CallInd_ret_expand);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodIdx;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = ctx.GetEvalStackTopOffset();
						ir->retLocationType = (uint8_t)locDataType;
					}
					else
					{
						CreateAddIR(ir, CallInd_ret);
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodIdx;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = ctx.GetEvalStackTopOffset();
					}
				}
				else
				{
					CreateAddIR(ir, CallInd_void);
					ir->managed2NativeMethod = managed2NativeMethodDataIdx;
					ir->methodInfo = methodIdx;
					ir->argIdxs = argIdxDataIndex;
				}

				ip += 5;
				continue;
			}
			case OpcodeValue::RET:
			{
				if (methodInfo->return_type->type == IL2CPP_TYPE_VOID)
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
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 2:
					{
						CreateAddIR(ir, RetVar_ret_2);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 4:
					{
						CreateAddIR(ir, RetVar_ret_4);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 8:
					{
						CreateAddIR(ir, RetVar_ret_8);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 12:
					{
						CreateAddIR(ir, RetVar_ret_12);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 16:
					{
						CreateAddIR(ir, RetVar_ret_16);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 20:
					{
						CreateAddIR(ir, RetVar_ret_20);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 24:
					{
						CreateAddIR(ir, RetVar_ret_24);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 28:
					{
						CreateAddIR(ir, RetVar_ret_28);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					case 32:
					{
						CreateAddIR(ir, RetVar_ret_32);
						ir->ret = ctx.GetEvalStackTopOffset();
						break;
					}
					default:
					{
						CreateAddIR(ir, RetVar_ret_n);
						ir->ret = ctx.GetEvalStackTopOffset();
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
					ctx.PushOffset(&ir->offset);

					ctx.PushBranch(targetOffset);
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
				ctx.Add_leave((uint32_t)targetOffset);
				PopBranch();
				continue;
			}
			case OpcodeValue::BRFALSE_S:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI1(ip + 1);
				int32_t targetOffset = ipOffset + brOffset + 2;
				ctx.Add_brtruefalse(false, targetOffset);
				ip += 2;
				continue;
			}
			case OpcodeValue::BRTRUE_S:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI1(ip + 1);
				int32_t targetOffset = ipOffset + brOffset + 2;
				ctx.Add_brtruefalse(true, targetOffset);
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
					ctx.PushOffset(&ir->offset);

					ctx.PushBranch(targetOffset);
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
				ctx.Add_leave((uint32_t)targetOffset);
				PopBranch();
				continue;
			}
			case OpcodeValue::BRFALSE:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI4LittleEndian(ip + 1);
				int32_t targetOffset = ipOffset + brOffset + 5;
				ctx.Add_brtruefalse(false, targetOffset);
				ip += 5;
				continue;
			}
			case OpcodeValue::BRTRUE:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				brOffset = GetI4LittleEndian(ip + 1);
				int32_t targetOffset = ipOffset + brOffset + 5;
				ctx.Add_brtruefalse(true, targetOffset);
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

				uint32_t switchValue = ctx.GetEvalStackTopOffset();
				uint32_t n = (uint32_t)GetI4LittleEndian(ip + 1);
				ir->value = ctx.GetEvalStackTopOffset();
				ir->caseNum = n;
				ir->caseOffsets;

				int32_t* caseOffsets;
				AllocResolvedData(resolveDatas, (n + 1) / 2, *(int32_t*)&ir->caseOffsets, caseOffsets);
				ctx.PopStack();

				uint32_t instrSize = 1 + (n + 1) * 4;
				const byte* caseOffsetIp = ip + 5;

				// remove this instrument if all target is same to default.
				uint32_t nextInstrumentOffset = ipOffset + instrSize;
				bool anyNotDefaultCase = false;
				for (uint32_t caseIdx = 0; caseIdx < n; caseIdx++)
				{
					int32_t targetOffset = (int32_t)(nextInstrumentOffset + GetI4LittleEndian(caseOffsetIp + caseIdx * 4));
					caseOffsets[caseIdx] = targetOffset;
					//ctx.PushOffset(caseOffsets + caseIdx);
					if (targetOffset != nextInstrumentOffset)
					{
						anyNotDefaultCase = true;
						ctx.PushBranch(targetOffset);
					}
				}
				if (anyNotDefaultCase)
				{
					switchOffsetsInResolveData.push_back({ ir->caseOffsets, n });
					ctx.AddInst(ir);
				}
				ip += instrSize;
				continue;
			}
			case OpcodeValue::LDIND_I1:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i1, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_U1:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_u1, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_I2:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i2, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_U2:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_u2, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_I4:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i4, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_U4:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_u4, EvalStackReduceDataType::I4);
				continue;
			}
			case OpcodeValue::LDIND_I8:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i8, EvalStackReduceDataType::I8);
				continue;
			}
			case OpcodeValue::LDIND_I:
			{
#if HUATUO_ARCH_64
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i8, NATIVE_INT_REDUCE_TYPE);
#else
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i4, NATIVE_INT_REDUCE_TYPE);
#endif
				continue;
			}
			case OpcodeValue::LDIND_R4:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_f4, EvalStackReduceDataType::R4);
				continue;
			}
			case OpcodeValue::LDIND_R8:
			{
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_f8, EvalStackReduceDataType::R8);
				continue;
			}
			case OpcodeValue::LDIND_REF:
			{
#if HUATUO_ARCH_64
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i8, NATIVE_INT_REDUCE_TYPE);
#else
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i4, NATIVE_INT_REDUCE_TYPE);
#endif
				continue;
			}
			case OpcodeValue::STIND_REF:
			{
#if HUATUO_ARCH_64
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i8);
#else
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i4);
#endif
				continue;
			}
			case OpcodeValue::STIND_I1:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i1);
				continue;
			}
			case OpcodeValue::STIND_I2:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i2);
				continue;
			}
			case OpcodeValue::STIND_I4:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i4);
				continue;
			}
			case OpcodeValue::STIND_I8:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i8);
				continue;
			}
			case OpcodeValue::STIND_R4:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_f4);
				continue;
			}
			case OpcodeValue::STIND_R8:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_f8);
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
					RaiseHuatuoExecutionEngineException("NEG not suppport type");
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
					RaiseHuatuoExecutionEngineException("NOT not suppport type");
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
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				uint32_t size = GetTypeValueSize(objKlass);
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
				ctx.PopStackN(2);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDOBJ:
			{
				IL2CPP_ASSERT(evalStackTop >= 1);
				EvalStackVarInfo& top = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

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
				ctx.PopStack();
				ctx.PushStackByType(&objKlass->byval_arg);
				IL2CPP_ASSERT(size == GetTypeValueSize(&objKlass->byval_arg));
				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();
				ip += 5;
				continue;
			}
			case OpcodeValue::LDSTR:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppString* str = image->GetIl2CppUserStringFromRawIndex(DecodeTokenRowIndex(token));
				uint32_t dataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, str);

				CreateAddIR(ir, LdstrVar);
				ir->dst = ctx.GetEvalStackNewTopOffset();
				ir->str = dataIdx;
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::NEWOBJ:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				ip += 5;
				// TODO token cache optimistic
				shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(shareMethod);
				Il2CppClass* klass = shareMethod->klass;

				IL2CPP_ASSERT(huatuo::metadata::IsInstanceMethod(shareMethod));
				if (strcmp(klass->namespaze, "System") == 0)
				{
					if (klass == il2cpp_defaults.object_class)
					{
						IL2CPP_ASSERT(!IS_CLASS_VALUE_TYPE(klass));
						CreateAddIR(ir, NewSystemObjectVar);
						ir->obj = ctx.GetEvalStackNewTopOffset();
						ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
						continue;
					}
					if (strcmp(klass->name, "Nullable`1") == 0)
					{
						IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
						IL2CPP_ASSERT(evalStackTop > 0);
						il2cpp::vm::Class::SetupFields(klass);
						CreateAddIR(ir, NullableNewVarVar);
						ir->dst = ir->data = ctx.GetEvalStackTopOffset();
						ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
						ctx.PopStack();
						ctx.PushStackByType(&klass->byval_arg);
						continue;
					}
				}

				if (klass->byval_arg.type == IL2CPP_TYPE_ARRAY)
				{
					const char* methodName = shareMethod->name;
					uint8_t paramCount = shareMethod->parameters_count;
					if (strcmp(methodName, ".ctor") == 0)
					{
						if (klass->rank == paramCount)
						{
							CreateAddIR(ir, NewMdArrVarVar_length);
							ir->lengthIdxs = ctx.GetEvalStackOffset(evalStackTop - paramCount);
							ctx.PopStackN(paramCount);
							ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
							ir->arr = ctx.GetEvalStackTopOffset();
							ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
						}
						else if (klass->rank * 2 == paramCount)
						{
							CreateAddIR(ir, NewMdArrVarVar_length_bound);
							ir->lengthIdxs = ctx.GetEvalStackOffset(evalStackTop - paramCount);
							ir->lowerBoundIdxs = ctx.GetEvalStackOffset(evalStackTop - klass->rank);
							ctx.PopStackN(paramCount);
							ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
							ir->arr = ctx.GetEvalStackTopOffset();
							ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
						}
						else
						{
							RaiseHuatuoExecutionEngineException("not support array ctor");
						}
						continue;
					}
				}

				if (IsMulticastDelegate(shareMethod))
				{
					IL2CPP_ASSERT(evalStackTop >= 2);
					CreateAddIR(ir, NewDelegate);
					ir->dst = ir->obj = ctx.GetEvalStackOffset_2();
					ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
					ir->method = ctx.GetEvalStackOffset_1();
					ctx.PopStackN(2);
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					continue;
				}

				if (!shareMethod->methodPointer)
				{
					RaiseAOTGenericMethodNotInstantiatedException(shareMethod);
				}
				int32_t callArgEvalStackIdxBase = evalStackTop - shareMethod->parameters_count;
				IL2CPP_ASSERT(callArgEvalStackIdxBase >= 0);
				uint16_t objIdx = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);

				int32_t resolvedTotalArgdNum = shareMethod->parameters_count + 1;

				uint32_t methodDataIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, shareMethod);

				if (IsInterpreterType(klass))
				{
					if (IS_CLASS_VALUE_TYPE(klass))
					{
						CreateAddIR(ir, NewValueTypeInterpVar);
						ir->obj = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
						ir->method = methodDataIndex;
						ir->argBase = ir->obj;
						ir->argStackObjectNum = curStackSize - ir->argBase;
						// IL2CPP_ASSERT(ir->argStackObjectNum > 0); may 0
						ctx.PopStackN(shareMethod->parameters_count);
						ctx.PushStackByType(&klass->byval_arg);
						ir->ctorFrameBase = ctx.GetEvalStackNewTopOffset();
						maxStackSize = std::max(maxStackSize, curStackSize + ir->argStackObjectNum + 1);
					}
					else
					{
						if (shareMethod->parameters_count == 0)
						{
							CreateAddIR(ir, NewClassInterpVar_Ctor_0);
							ir->obj = ctx.GetEvalStackNewTopOffset();
							ir->method = methodDataIndex;
							ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
							ir->ctorFrameBase = ctx.GetEvalStackNewTopOffset();
							maxStackSize = std::max(maxStackSize, curStackSize + 1); // 1 for __this
						}
						else
						{
							CreateAddIR(ir, NewClassInterpVar);
							ir->obj = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
							ir->method = methodDataIndex;
							ir->argBase = ir->obj;
							ir->argStackObjectNum = curStackSize - ir->argBase;
							IL2CPP_ASSERT(ir->argStackObjectNum > 0);
							ctx.PopStackN(shareMethod->parameters_count);
							ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
							ir->ctorFrameBase = ctx.GetEvalStackNewTopOffset();
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
					ir->obj = ctx.GetEvalStackNewTopOffset();
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					continue;
				}

				int32_t needDataSlotNum = (resolvedTotalArgdNum + 3) / 4;
				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT((void*)managed2NativeMethod);
				//uint32_t managed2NativeMethodDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, managed2NativeMethod);



				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);
				//
				// arg1, arg2, arg3 ..., argN, obj or valuetype, __this(= obj or ref valuetype)
				// obj on new top
				ctx.PushStackByType(&klass->byval_arg);
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				__argIdxs[0] = ctx.GetEvalStackTopOffset(); // this

				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + 1;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + i].locOffset;
				}
				ctx.PopStackN(resolvedTotalArgdNum + 1); // args + obj + this
				ctx.PushStackByType(&klass->byval_arg);
				CreateAddIR(ir, NewClassVar);
				ir->type = IS_CLASS_VALUE_TYPE(shareMethod->klass) ? HiOpcodeEnum::NewValueTypeVar : HiOpcodeEnum::NewClassVar;
				ir->managed2NativeMethod = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, (void*)managed2NativeMethod);
				ir->method = methodDataIndex;
				ir->argIdxs = argIdxDataIndex;
				ir->obj = objIdx;

				continue;
			}
			case OpcodeValue::CASTCLASS:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (il2cpp::vm::Class::IsNullable(objKlass))
				{
					objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				}
				uint32_t klassDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);

				CreateAddIR(ir, CastclassVar);
				ir->obj = ctx.GetEvalStackTopOffset();
				ir->klass = klassDataIdx;
				ip += 5;
				continue;
			}
			case OpcodeValue::ISINST:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (il2cpp::vm::Class::IsNullable(objKlass))
				{
					objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				}
				uint32_t klassDataIdx = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);

				CreateAddIR(ir, IsInstVar);
				ir->obj = ctx.GetEvalStackTopOffset();
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
					ir->dst = ir->src = ctx.GetEvalStackTopOffset();
					break;
				}
				case EvalStackReduceDataType::I8:
				{
					CreateAddIR(ir, ConvertVarVar_u8_f8);
					ir->dst = ir->src = ctx.GetEvalStackTopOffset();
					break;
				}
				default:
				{
					RaiseHuatuoExecutionEngineException("");
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
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				//if (il2cpp::vm::Class::IsNullable(objKlass))
				//{
				//    objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				//}
				CreateAddIR(ir, UnBoxVarVar);
				ir->addr = ir->obj = ctx.GetEvalStackTopOffset();
				ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);

				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::THROW:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				CreateAddIR(ir, ThrowEx);
				ir->exceptionObj = ctx.GetEvalStackTopOffset();
				ir->firstHandlerIndex = ctx.FindFirstThrowHandlerIndex(body.exceptionClauses, ipOffset);
				ctx.PopAllStack();
				PopBranch();
				continue;
			}
			case OpcodeValue::LDFLD:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);
				// ldfld obj may be obj or or valuetype or ref valuetype....
				EvalStackVarInfo& obj = evalStack[evalStackTop - 1];
				uint16_t topIdx = ctx.GetEvalStackTopOffset();
				IRCommon* ir = obj.reduceType != NATIVE_INT_REDUCE_TYPE && IS_CLASS_VALUE_TYPE(fieldInfo->parent) ? CreateValueTypeLdfld(pool, topIdx, topIdx, fieldInfo) : CreateClassLdfld(pool, topIdx, topIdx, fieldInfo);
				ctx.AddInst(ir);
				ctx.PopStack();
				ctx.PushStackByType(fieldInfo->type);

				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();

				ip += 5;
				continue;
			}
			case OpcodeValue::LDFLDA:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint16_t topIdx = ctx.GetEvalStackTopOffset();
				CreateAddIR(ir, LdfldaVarVar);
				ir->dst = topIdx;
				ir->obj = topIdx;
				ir->offset = GetFieldOffset(fieldInfo);

				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ip += 5;
				continue;
			}
			case OpcodeValue::STFLD:
			{
				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();

				IL2CPP_ASSERT(evalStackTop >= 2);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				IRCommon* ir = CreateStfld(pool, ctx.GetEvalStackOffset_2(), fieldInfo, ctx.GetEvalStackOffset_1());
				ctx.AddInst(ir);
				ctx.PopStackN(2);
				ip += 5;
				continue;
			}
			case OpcodeValue::LDSFLD:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);
				uint32_t parentIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, fieldInfo->parent);
				uint16_t dstIdx = ctx.GetEvalStackNewTopOffset();
				IRCommon* ir = fieldInfo->offset != THREAD_STATIC_FIELD_OFFSET ?
					CreateLdsfld(pool, dstIdx, fieldInfo, parentIndex)
					: CreateLdthreadlocal(pool, dstIdx, fieldInfo, parentIndex);
				ctx.AddInst(ir);
				ctx.PushStackByType(fieldInfo->type);

				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();

				ip += 5;
				continue;
			}
			case OpcodeValue::LDSFLDA:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint16_t dstIdx = ctx.GetEvalStackNewTopOffset();
				if (fieldInfo->offset != THREAD_STATIC_FIELD_OFFSET)
				{
					bool ldfldFromFieldData = false;
					if (huatuo::metadata::IsInterpreterType(fieldInfo->parent))
					{
						const FieldDetail& fieldDet = huatuo::metadata::MetadataModule::GetImage(fieldInfo->parent)
							->GetFieldDetailFromRawIndex(huatuo::metadata::DecodeTokenRowIndex(fieldInfo->token - 1));
						if (fieldDet.defaultValueIndex != kDefaultValueIndexNull)
						{
							ldfldFromFieldData = true;
							CreateAddIR(ir, LdsfldaFromFieldDataVarVar);
							ir->dst = dstIdx;
							ir->src = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, (void*)il2cpp_codegen_get_field_data(fieldInfo));
						}
					}
					if (!ldfldFromFieldData)
					{
						CreateAddIR(ir, LdsfldaVarVar);
						ir->dst = dstIdx;
						ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, fieldInfo->parent);
						ir->offset = fieldInfo->offset;
					}
				}
				else
				{
					CreateAddIR(ir, LdthreadlocalaVarVar);
					ir->dst = dstIdx;
					ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, fieldInfo->parent);
					ir->offset = GetThreadStaticFieldOffset(fieldInfo);
				}
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::STSFLD:
			{
				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();
				IL2CPP_ASSERT(evalStackTop >= 1);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint32_t klassIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, fieldInfo->parent);
				uint16_t dataIdx = ctx.GetEvalStackTopOffset();
				IRCommon* ir = fieldInfo->offset != THREAD_STATIC_FIELD_OFFSET ?
					CreateStsfld(pool, fieldInfo, klassIndex, dataIdx)
					: CreateStthreadlocal(pool, fieldInfo, klassIndex, dataIdx);
				ctx.AddInst(ir);

				ctx.PopStack();
				ip += 5;
				continue;
			}
			case OpcodeValue::STOBJ:
			{
				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& dst = evalStack[evalStackTop - 2];
				EvalStackVarInfo& src = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);

				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);

				IL2CPP_ASSERT(objKlass);

				uint32_t size = GetTypeValueSize(objKlass);
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
				ctx.PopStackN(2);
				IL2CPP_ASSERT(size == GetTypeValueSize(&objKlass->byval_arg));
				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();
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
#if HUATUO_ARCH_64
				CI_conv_un_ovf(i8, I8, 8);
#else
				CI_conv_un_ovf(i4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::CONV_OVF_U_UN:
			{
#if HUATUO_ARCH_64
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
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				/*	if (il2cpp::vm::Class::IsNullable(objKlass))
					{
						objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
					}*/
				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					CreateAddIR(ir, BoxVarVar);
					ir->dst = ir->data = ctx.GetEvalStackTopOffset();
					ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);
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
				Il2CppClass* eleKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(eleKlass);
				Il2CppClass* arrKlass = il2cpp::vm::Class::GetArrayClass(eleKlass, 1);
				uint32_t arrKlassIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, arrKlass);
				switch (varSize.reduceType)
				{
				case EvalStackReduceDataType::I4:
				{
					CreateAddIR(ir, NewArrVarVar_4);
					ir->arr = ir->size = varSize.locOffset;
					ir->klass = arrKlassIndex;
					break;
				}
				case EvalStackReduceDataType::I8:
				{
					CreateAddIR(ir, NewArrVarVar_8);
					ir->arr = ir->size = varSize.locOffset;
					ir->klass = arrKlassIndex;
					break;
				}
				default:
				{
					RaiseHuatuoExecutionEngineException("NEWARR invalid reduceType");
					break;
				}
				}
				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::LDLEN:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				CreateAddIR(ir, GetArrayLengthVarVar_8);
				ir->arr = ir->len = ctx.GetEvalStackTopOffset();
				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip++;
				continue;
			}
			case OpcodeValue::LDELEMA:
			{
				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& arr = evalStack[evalStackTop - 2];
				EvalStackVarInfo& index = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* eleKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				uint32_t eleKlassIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, eleKlass);
				switch (index.reduceType)
				{
				case EvalStackReduceDataType::I4:
				{
					CreateAddIR(ir, GetArrayElementAddressCheckAddrVarVar_i4);
					ir->arr = ir->addr = arr.locOffset;
					ir->index = index.locOffset;
					ir->eleKlass = eleKlassIndex;
					break;
				}
				case EvalStackReduceDataType::I8:
				{
					CreateAddIR(ir, GetArrayElementAddressCheckAddrVarVar_i8);
					ir->arr = ir->addr = arr.locOffset;
					ir->index = index.locOffset;
					ir->eleKlass = eleKlassIndex;
					break;
				}
				default:
				{
					RaiseHuatuoExecutionEngineException("ldelema");
					break;
				}
				}

				ctx.PopStackN(2);
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
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
#if HUATUO_ARCH_64
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
#if HUATUO_ARCH_64
				CI_ldele(i8, I8);
#else
				CI_ldele(i4, I4);
#endif
				continue;
			}
			case OpcodeValue::STELEM_I:
			{
#if HUATUO_ARCH_64
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

#define CI_ldele0(eleType, reduceType2) \
CreateAddIR(ir,  GetArrayElementVarVar_##eleType##_4); \
ir->type = isIndexInt32Type ? HiOpcodeEnum::GetArrayElementVarVar_##eleType##_4 : HiOpcodeEnum::GetArrayElementVarVar_##eleType##_8; \
ir->arr = arr.locOffset; \
ir->index = index.locOffset; \
ir->dst = arr.locOffset;


			case OpcodeValue::LDELEM:
			{
				IL2CPP_ASSERT(evalStackTop >= 2);
				EvalStackVarInfo& arr = evalStack[evalStackTop - 2];
				EvalStackVarInfo& index = evalStack[evalStackTop - 1];

				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				const Il2CppType* eleType = &objKlass->byval_arg;

				IL2CPP_ASSERT(index.reduceType == EvalStackReduceDataType::I4 || index.reduceType == EvalStackReduceDataType::I8);
				bool isIndexInt32Type = index.reduceType == EvalStackReduceDataType::I4;
				LocationDescInfo desc = ComputLocationDescInfo(eleType);
				switch (desc.type)
				{
				case LocationDescType::I1: { CI_ldele0(i1, I4); break; }
				case LocationDescType::U1: { CI_ldele0(u1, I4); break; }
				case LocationDescType::I2: { CI_ldele0(i2, I4); break; }
				case LocationDescType::U2: { CI_ldele0(u2, I4); break; }
				case LocationDescType::I4: { CI_ldele0(i4, I4); break; }
				case LocationDescType::I8: { CI_ldele0(i8, I8); break; }
				case LocationDescType::S:
				{
					uint32_t size = il2cpp::vm::Class::GetValueSize(objKlass, nullptr);
					switch (size)
					{
					case 12:
					{
						CreateAddIR(ir, GetArrayElementVarVar_size_12_8);
						ir->type = isIndexInt32Type ? HiOpcodeEnum::GetArrayElementVarVar_size_12_4 : HiOpcodeEnum::GetArrayElementVarVar_size_12_8;
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->dst = arr.locOffset;
						break;
					}
					case 16:
					{
						CreateAddIR(ir, GetArrayElementVarVar_size_16_8);
						ir->type = isIndexInt32Type ? HiOpcodeEnum::GetArrayElementVarVar_size_16_4 : HiOpcodeEnum::GetArrayElementVarVar_size_16_8;
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->dst = arr.locOffset;
						break;
					}
					default:
					{
						CreateAddIR(ir, GetArrayElementVarVar_n_8);
						ir->type = isIndexInt32Type ? HiOpcodeEnum::GetArrayElementVarVar_n_4 : HiOpcodeEnum::GetArrayElementVarVar_n_8;
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->dst = arr.locOffset;
						break;
					}
					}
					break;
				}
				default:
				{
					RaiseHuatuoExecutionEngineException("ldelem not support type");
				}					 
				}
				ctx.PopStackN(2);
				ctx.PushStackByType(eleType);

				ip += 5;
				continue;
			}


#define CI_stele0(eleType) \
CreateAddIR(ir, SetArrayElementVarVar_##eleType##_8); \
ir->type =  isIndexInt32Type ? HiOpcodeEnum::SetArrayElementVarVar_##eleType##_4 : HiOpcodeEnum::SetArrayElementVarVar_##eleType##_8;\
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
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
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
				case LocationDescType::S:
				{
					uint32_t size = il2cpp::vm::Class::GetValueSize(objKlass, nullptr);
					switch (size)
					{
					case 12:
					{
						CreateAddIR(ir, SetArrayElementVarVar_size_12_8);
						ir->type = isIndexInt32Type ? HiOpcodeEnum::SetArrayElementVarVar_size_12_4 : HiOpcodeEnum::SetArrayElementVarVar_size_12_8;
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->ele = ele.locOffset;
						break;
					}
					case 16:
					{
						CreateAddIR(ir, SetArrayElementVarVar_size_16_8);
						ir->type = isIndexInt32Type ? HiOpcodeEnum::SetArrayElementVarVar_size_16_4 : HiOpcodeEnum::SetArrayElementVarVar_size_16_8;
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->ele = ele.locOffset;
						break;
					}
					default:
					{
						CreateAddIR(ir, SetArrayElementVarVar_n_8);
						ir->type = isIndexInt32Type ? HiOpcodeEnum::SetArrayElementVarVar_n_4 : HiOpcodeEnum::SetArrayElementVarVar_n_8;
						ir->arr = arr.locOffset;
						ir->index = index.locOffset;
						ir->ele = ele.locOffset;
						break;
					}
					}
					break;
				}
				default:
				{
					RaiseHuatuoExecutionEngineException("stelem not support type");
				}
				}
				ctx.PopStackN(3);

				ip += 5;
				continue;
			}
			case OpcodeValue::UNBOX_ANY:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					CreateAddIR(ir, UnBoxAnyVarVar);
					ir->dst = ir->obj = ctx.GetEvalStackTopOffset();
					ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);

					ctx.PopStack();
					ctx.PushStackByType(&objKlass->byval_arg);
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
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				CreateAddIR(ir, RefAnyValueVarVar);
				ir->addr = ir->typedRef = ctx.GetEvalStackTopOffset();
				ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);
				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
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
					ir->src = ctx.GetEvalStackTopOffset();
					break;
				}
				case EvalStackReduceDataType::R8:
				{
					CreateAddIR(ir, CheckFiniteVar_f8);
					ir->src = ctx.GetEvalStackTopOffset();
					break;
				}
				default:
				{
					RaiseHuatuoExecutionEngineException("CKFINITE invalid reduceType");
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
				Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);
				CreateAddIR(ir, MakeRefVarVar);
				ir->dst = ir->data = ctx.GetEvalStackTopOffset();
				ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, objKlass);
				ctx.PopStack();

				Il2CppType typedRef = {};
				typedRef.type = IL2CPP_TYPE_TYPEDBYREF;
				ctx.PushStackByType(&typedRef);

				ip += 5;
				continue;
			}
			case OpcodeValue::LDTOKEN:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				void* runtimeHandle = (void*)image->GetRuntimeHandleFromToken(token, klassContainer, methodContainer, genericContext);

				CreateAddIR(ir, LdtokenVar);
				ir->runtimeHandle = ctx.GetEvalStackNewTopOffset();
				ir->token = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, runtimeHandle);
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
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
#if HUATUO_ARCH_64
				CI_conv(i8, I8, 8);
#else
				CI_conv(i4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::CONV_OVF_I:
			{
#if HUATUO_ARCH_64
				CI_conv_ovf(i8, I8, 8);
#else
				CI_conv_ovf(i4, I4, 4);
#endif
				continue;
			}
			case OpcodeValue::CONV_OVF_U:
			{
#if HUATUO_ARCH_64
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
#if HUATUO_ARCH_64
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i8);
#else
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i4);
#endif
				continue;
			}
			case OpcodeValue::CONV_U:
			{
#if HUATUO_ARCH_64
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
					RaiseHuatuoExecutionEngineException("");
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
				case OpcodeValue::LDARG:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					ctx.AddInst_ldarg(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LDARGA:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					ctx.AddInst_ldarga(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::STARG:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					ctx.AddInst_starg(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LDLOC:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					ctx.CreateAddInst_ldloc(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::LDLOCA:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					ctx.CreateAddInst_ldloca(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::STLOC:
				{
					argIdx = GetU2LittleEndian(ip + 2);
					ctx.CreateAddInst_stloc(argIdx);
					ip += 4;
					continue;
				}
				case OpcodeValue::CONSTRAINED_:
				{
					uint32_t typeToken = (uint32_t)GetI4LittleEndian(ip + 2);
					Il2CppClass* conKlass = image->GetClassFromToken(typeToken, klassContainer, methodContainer, genericContext);
					IL2CPP_ASSERT(conKlass);
					ip += 6;

					IL2CPP_ASSERT(*ip == (uint8_t)OpcodeValue::CALLVIRT);
					uint32_t methodToken = (uint32_t)GetI4LittleEndian(ip + 1);
					ip += 5;

					// TODO token cache optimistic
					shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(methodToken, klassContainer, methodContainer, genericContext));
					IL2CPP_ASSERT(shareMethod);


					int32_t resolvedTotalArgdNum = shareMethod->parameters_count + 1;

					int32_t selfIdx = evalStackTop - resolvedTotalArgdNum;
					EvalStackVarInfo& self = evalStack[selfIdx];
					if (IS_CLASS_VALUE_TYPE(conKlass))
					{
						// impl in self
						const MethodInfo* implMethod = image->FindImplMethod(conKlass, shareMethod);
						if (implMethod)
						{
							shareMethod = implMethod;
							goto LabelCall;
						}
						else
						{
							CreateAddIR(ir, BoxRefVarVar);
							ir->dst = ir->src = self.locOffset;
							ir->klass = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, conKlass);

							self.reduceType = NATIVE_INT_REDUCE_TYPE;
							self.byteSize = GetSizeByReduceType(self.reduceType);
							goto LabelCallVir;
						}
					}
					else
					{
						// deref object. FIXME gc memory barrier
#if HUATUO_ARCH_64
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
				case OpcodeValue::VOLATILE_:
				{
					// Set a flag that causes a memory barrier to be associated with the next load or store.
					//CI_volatileFlag = true;
					prefixFlags |= (int32_t)PrefixFlags::Volatile;
					ip += 2;
					continue;
				}
				case OpcodeValue::LDFTN:
				{
					uint32_t methodToken = (uint32_t)GetI4LittleEndian(ip + 2);
					MethodInfo* methodInfo = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(methodToken, klassContainer, methodContainer, genericContext));
					IL2CPP_ASSERT(methodInfo);
					CreateAddIR(ir, LdcVarConst_8);
					ir->dst = ctx.GetEvalStackNewTopOffset();
					ir->src = (uint64_t)methodInfo;
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					ip += 6;
					continue;
				}

				case OpcodeValue::INITOBJ:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					uint32_t token = (uint32_t)GetI4LittleEndian(ip + 2);
					Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
					CreateAddIR(ir, InitobjVar_n_4);
					ir->obj = ctx.GetEvalStackTopOffset();
					ir->size = GetTypeValueSize(objKlass);
					ctx.PopStack();

					ip += 6;
					break;
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
						ir->dst = ir->size = ctx.GetEvalStackTopOffset();
						break;
					}
					default:
					{
						RaiseHuatuoExecutionEngineException("LOCALLOC invalid reduceType");
						break;
					}
					}
					ctx.PopStack();
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

					ip += 2;
					continue;
				}
				case OpcodeValue::LDVIRTFTN:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					uint32_t methodToken = (uint32_t)GetI4LittleEndian(ip + 2);
					MethodInfo* methodInfo = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(methodToken, klassContainer, methodContainer, genericContext));
					IL2CPP_ASSERT(methodInfo);

					CreateAddIR(ir, LdvirftnVarVar);
					ir->resultMethod = ir->obj = ctx.GetEvalStackTopOffset();
					ir->virtualMethod = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, methodInfo);

					ctx.PopStack();
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
					ip += 6;
					continue;
				}
				case OpcodeValue::SIZEOF:
				{
					uint32_t token = (uint32_t)GetI4LittleEndian(ip + 2);
					Il2CppClass* objKlass = image->GetClassFromToken(token, klassContainer, methodContainer, genericContext);
					IL2CPP_ASSERT(objKlass);
					int32_t typeSize = GetTypeValueSize(&objKlass->byval_arg);
					ctx.CreateAddInst_ldc4(typeSize, EvalStackReduceDataType::I4);
					ip += 6;
					continue;
				}
				case OpcodeValue::RETHROW:
				{
					CreateAddIR(ir, RethrowEx);
					ctx.AddInst(ir);
					ctx.PopAllStack();
					PopBranch();
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
				case OpcodeValue::INITBLK:
				{
					IL2CPP_ASSERT(evalStackTop >= 3);
					CreateAddIR(ir, InitblkVarVarVar);
					ir->addr = ctx.GetEvalStackOffset_3();
					ir->value = ctx.GetEvalStackOffset_2();
					ir->size = ctx.GetEvalStackOffset_1();
					ctx.PopStackN(3);
					ctx.InsertMemoryBarrier();
					ctx.ResetPrefixFlags();
					ip += 2;
					continue;
				}
				case OpcodeValue::CPBLK:
				{
					// we don't sure dst or src is volatile. so insert memory barrier ahead and end.
					ctx.InsertMemoryBarrier();
					ctx.ResetPrefixFlags();
					IL2CPP_ASSERT(evalStackTop >= 3);
					CreateAddIR(ir, CpblkVarVar);
					ir->dst = ctx.GetEvalStackOffset_3();
					ir->src = ctx.GetEvalStackOffset_2();
					ir->size = ctx.GetEvalStackOffset_1();
					ctx.PopStackN(3);
					ctx.InsertMemoryBarrier();
					ctx.ResetPrefixFlags();
					ip += 2;
					continue;
				}
				case OpcodeValue::ENDFILTER:
				{
					CreateAddIR(ir, EndFilterEx);
					ir->value = ctx.GetEvalStackTopOffset();
					ctx.PopAllStack();

					PopBranch();
					continue;
				}
				case OpcodeValue::UNALIGNED_:
				{
					// Nothing to do here.
					prefixFlags |= (int32_t)PrefixFlags::Unaligned;
					ip += 2;
					continue;
				}
				case OpcodeValue::TAIL_:
				{
					prefixFlags |= (int32_t)PrefixFlags::Tail;
					ip += 2;
					continue;
				}
				case OpcodeValue::REFANYTYPE:
				{
					IL2CPP_ASSERT(evalStackTop > 0);
					CreateAddIR(ir, RefAnyTypeVarVar);
					ir->dst = ir->typedRef = ctx.GetEvalStackOffset_1();
					ctx.PopStack();
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

					ip += 2;
					continue;
				}
				default:
				{
					//UNREACHABLE();
					RaiseHuatuoExecutionEngineException("not support instruction");
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
				RaiseHuatuoExecutionEngineException("not support instruction");
				continue;
			}
			}
			ip++;
		}
	finish_transform:


		uint32_t totalSize = 0;
		for (IRBasicBlock* bb : irbbs)
		{
			bb->codeOffset = totalSize;
			for (IRCommon* ir : bb->insts)
			{
				totalSize += g_instructionSizes[(int)ir->type];
			}
		}
		endBb.codeOffset = totalSize;

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


		byte* tranCodes = (byte*)IL2CPP_MALLOC(totalSize);

		uint32_t tranOffset = 0;
		for (IRBasicBlock* bb : irbbs)
		{
			bb->codeOffset = tranOffset;
			for (IRCommon* ir : bb->insts)
			{
				uint32_t irSize = g_instructionSizes[(int)ir->type];
				std::memcpy(tranCodes + tranOffset, &ir->type, irSize);
				tranOffset += irSize;
			}
		}
		IL2CPP_ASSERT(tranOffset == totalSize);

		ArgDesc* argDescs;
		bool isSimpleArgs = true;
		if (actualParamCount > 0)
		{
			argDescs = (ArgDesc*)IL2CPP_CALLOC(actualParamCount, sizeof(ArgDesc));
			for (int32_t i = 0; i < actualParamCount; i++)
			{
				argDescs[i] = GetTypeArgDesc(args[i].type);
				isSimpleArgs = isSimpleArgs && IsSimpleStackObjectCopyArg(argDescs[i].type);
			}
		}
		else
		{
			argDescs = nullptr;
		}

		result.method = methodInfo;
		result.args = argDescs;
		result.argCount = actualParamCount;
		result.argStackObjectSize = totalArgSize;
		result.codes = tranCodes;
		result.codeLength = totalSize;
		result.evalStackBaseOffset = evalStackBaseOffset;
		result.localVarBaseOffset = totalArgSize;
		result.localStackSize = totalArgLocalSize;
		result.maxStackSize = maxStackSize;
		result.isTrivialCopyArgs = isSimpleArgs;
	}
}

}
