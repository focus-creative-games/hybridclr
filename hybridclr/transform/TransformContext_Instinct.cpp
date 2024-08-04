#include "TransformContext.h"

#include "utils/Il2CppHashMap.h"
#include "utils/HashUtils.h"
#include "utils/StringUtils.h"

namespace hybridclr
{
namespace transform
{
	struct NamespaceAndName
	{
		const char* namespaze;
		const char* name;
	};

	struct NamespaceAndNameHash
	{
		size_t operator()(const NamespaceAndName& pair) const
		{
			size_t h = il2cpp::utils::StringUtils::Hash(pair.namespaze);
			h = il2cpp::utils::HashUtils::Combine(h, il2cpp::utils::StringUtils::Hash(pair.name));
			return h;
		}
	};

	struct NamespaceAndNameEquals
	{
		bool operator()(const NamespaceAndName& p1, const NamespaceAndName& p2) const
		{
			return !strcmp(p1.namespaze, p2.namespaze)
				&& !strcmp(p1.name, p2.name);
		}
	};

	struct NamespaceAndNameAndMethod
	{
		const char* namespaze;
		const char* name;
		const char* method;
	};

	struct NamespaceAndNameAndMethodHash
	{
		size_t operator()(const NamespaceAndNameAndMethod& pair) const
		{
			size_t h = il2cpp::utils::StringUtils::Hash(pair.namespaze);
			h = il2cpp::utils::HashUtils::Combine(h, il2cpp::utils::StringUtils::Hash(pair.name));
			h = il2cpp::utils::HashUtils::Combine(h, il2cpp::utils::StringUtils::Hash(pair.method));
			return h;
		}
	};

	struct NamespaceAndNameAndMethodEquals
	{
		bool operator()(const NamespaceAndNameAndMethod& p1, const NamespaceAndNameAndMethod& p2) const
		{
			return !strcmp(p1.namespaze, p2.namespaze)
				&& !strcmp(p1.name, p2.name)
				&& !strcmp(p1.method, p2.method);
		}
	};

	typedef bool (*InstinctHandler)(TransformContext& ctx, const MethodInfo* method);

	typedef Il2CppHashMap<NamespaceAndNameAndMethod, InstinctHandler, NamespaceAndNameAndMethodHash, NamespaceAndNameAndMethodEquals> InstinctHandlerMap;

	static InstinctHandlerMap s_instinctHandlerMap;

	typedef Il2CppHashMap<NamespaceAndName, InstinctHandler, NamespaceAndNameHash, NamespaceAndNameEquals> CtorInstinctHandlerMap;
	static CtorInstinctHandlerMap s_ctorInstinctHandlerMap;

#define IHCreateAddIR(varName, typeName) IR##typeName* varName = ctx.pool.AllocIR<IR##typeName>(); varName->type = HiOpcodeEnum::typeName; ctx.AddInst(varName);


	static bool IH_object_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		ctx.PopStack();
		return true;
	}

	static bool IH_Nullable_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		if (method->parameters_count != 1)
		{
			return false;
		}
		Il2CppClass* klass = method->klass;
		il2cpp::vm::Class::SetupFields(klass);
		il2cpp::vm::Class::SetupFields(klass->castClass);

		IL2CPP_ASSERT(ctx.evalStackTop >= 2);
		IHCreateAddIR(ir, NullableCtorVarVar);
		ir->dst = ctx.GetEvalStackOffset_2();
		ir->data = ctx.GetEvalStackOffset_1();
		ir->klass = ctx.GetOrAddResolveDataIndex(klass);

		ctx.PopStackN(2);
		return true;
	}

	static bool IH_Nullable_GetValueOrDefault(TransformContext& ctx, const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		il2cpp::vm::Class::SetupFields(klass);
		il2cpp::vm::Class::SetupFields(klass->castClass);
		uint32_t classIndirectIndex = ctx.GetOrAddResolveDataIndex(klass);
		uint16_t topOffset = ctx.GetEvalStackTopOffset();
		if (method->parameters_count == 0)
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 1);
			IHCreateAddIR(ir, NullableGetValueOrDefaultVarVar);
			ir->dst = topOffset;
			ir->obj = topOffset;
			ir->klass = classIndirectIndex;

			// pop this, push value
			ctx.PopStack();
			ctx.PushStackByType(&klass->castClass->byval_arg);
			return true;
		}
		else if (method->parameters_count == 1)
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 2);
			IHCreateAddIR(ir, NullableGetValueOrDefaultVarVar_1);
			ir->dst = ir->obj = ctx.GetEvalStackOffset_2();
			ir->defaultValue = topOffset;
			ir->klass = classIndirectIndex;

			// pop this, default value then push value
			ctx.PopStackN(2);
			ctx.PushStackByType(&klass->castClass->byval_arg);
			return true;
		}
		return false;
	}

	static bool IH_Nullable_get_HasValue(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 1);
		Il2CppClass* klass = method->klass;
		il2cpp::vm::Class::SetupFields(klass);
		il2cpp::vm::Class::SetupFields(klass->castClass);
		uint32_t classIndirectIndex = ctx.GetOrAddResolveDataIndex(klass);
		uint16_t topOffset = ctx.GetEvalStackTopOffset();

		IHCreateAddIR(ir, NullableHasValueVar);
		ir->result = topOffset;
		ir->obj = topOffset;
		ir->klass = classIndirectIndex;

		// pop this, push value
		ctx.PopStack();
		ctx.PushStackByReduceType(EvalStackReduceDataType::I4);
		return true;
	}

	static bool IH_Nullable_get_Value(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 1);
		Il2CppClass* klass = method->klass;
		il2cpp::vm::Class::SetupFields(klass);
		il2cpp::vm::Class::SetupFields(klass->castClass);
		uint32_t classIndirectIndex = ctx.GetOrAddResolveDataIndex(klass);
		uint16_t topOffset = ctx.GetEvalStackTopOffset();

		IHCreateAddIR(ir, NullableGetValueVarVar);
		ir->dst = topOffset;
		ir->obj = topOffset;
		ir->klass = classIndirectIndex;

		// pop this, push value
		ctx.PopStack();
		ctx.PushStackByType(&klass->castClass->byval_arg);
		return true;
	}

	static bool IH_Array_GetGenericValueImpl(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 3);
		uint16_t topOffset = ctx.GetEvalStackTopOffset();
		IHCreateAddIR(ir, ArrayGetGenericValueImpl);
		ir->arr = ctx.GetEvalStackOffset_3();
		ir->index = ctx.GetEvalStackOffset_2();
		ir->value = ctx.GetEvalStackOffset_1();
		ctx.PopStackN(3);
		return true;
	}

	static bool IH_Array_SetGenericValueImpl(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 3);
		uint16_t topOffset = ctx.GetEvalStackTopOffset();
		IHCreateAddIR(ir, ArraySetGenericValueImpl);
		ir->arr = ctx.GetEvalStackOffset_3();
		ir->index = ctx.GetEvalStackOffset_2();
		ir->value = ctx.GetEvalStackOffset_1();
		ctx.PopStackN(3);
		return true;
	}

	static bool IH_Interlocked_CompareExchange(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 3);
		uint16_t retIdx = ctx.GetEvalStackOffset_3();
		uint16_t locationIdx = retIdx;
		uint16_t valueIdx = ctx.GetEvalStackOffset_2();
		uint16_t comparandIdx = ctx.GetEvalStackOffset_1();

		IHCreateAddIR(ir, InterlockedCompareExchangeVarVarVarVar_pointer);
		ir->ret = retIdx;
		ir->location = locationIdx;
		ir->value = valueIdx;
		ir->comparand = comparandIdx;

		const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(method->parameters[1]);
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
					RaiseExecutionEngineException("not support System.Threading.Interlocked.CompareExchange");
				}
			}
		}
		ctx.PopStackN(3);
		ctx.PushStackByType(paramType);

		return true;
	}

	static bool IH_Interlocked_Exchange(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 2);
		uint16_t retIdx = ctx.GetEvalStackOffset_2();
		uint16_t locationIdx = retIdx;
		uint16_t valueIdx = ctx.GetEvalStackOffset_1();

		IHCreateAddIR(ir, InterlockedExchangeVarVarVar_pointer);
		ir->ret = retIdx;
		ir->location = locationIdx;
		ir->value = valueIdx;

		const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(method->parameters[1]);
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
					RaiseExecutionEngineException("not support System.Threading.Interlocked.Exchange");
				}
			}
		}
		ctx.PopStackN(2);
		ctx.PushStackByType(paramType);
		return true;
	}

	static bool IH_JitHelpers_UnsafeEnumCast(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 1);
		IHCreateAddIR(ir, UnsafeEnumCast);
		ir->dst = ctx.GetEvalStackTopOffset();
		ir->src = ctx.GetEvalStackTopOffset();
		const Il2CppType* srcType = method->genericMethod->context.method_inst->type_argv[0];
		if (srcType->type == IL2CPP_TYPE_VALUETYPE || srcType->type == IL2CPP_TYPE_GENERICINST)
		{
			Il2CppClass* srcKlass = il2cpp::vm::Class::FromIl2CppType(srcType);
			if (!srcKlass->enumtype)
			{
				RaiseExecutionEngineException("not support UnsafeEnumCast src type");
			}
			ir->srcType = (uint16_t)srcKlass->castClass->byval_arg.type;
		}
		else
		{
			ir->srcType = (uint16_t)srcType->type;
		}
		ctx.PopStack();
		ctx.PushStackByReduceType(EvalStackReduceDataType::I4);
		return true;
	}

	static bool IH_JitHelpers_UnsafeCast(TransformContext& ctx, const MethodInfo* method)
	{
		return true;
	}

	static bool IH_JitHelpers_UnsafeEnumCastLong(TransformContext& ctx, const MethodInfo* method)
	{
		return true;
	}

	static bool IH_Assembly_GetExecutingAssembly(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 0);
		IHCreateAddIR(ir, AssemblyGetExecutingAssembly);
		ir->ret = ctx.GetEvalStackNewTopOffset();
		ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		return true;
	}

	static bool IH_MethodBase_GetCurrentMethod(TransformContext& ctx, const MethodInfo* method)
	{
		IL2CPP_ASSERT(ctx.evalStackTop >= 0);
		IHCreateAddIR(ir, MethodBaseGetCurrentMethod);
		ir->ret = ctx.GetEvalStackNewTopOffset();
		ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		return true;
	}

	static bool IH_UnityEngine_Vector2_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		if (method->parameters_count != 2)
		{
			return false;
		}
		IL2CPP_ASSERT(ctx.evalStackTop >= 3);
		IHCreateAddIR(ir, CtorVector2);
		ir->obj = ctx.GetEvalStackOffset_3();
		ir->x = ctx.GetEvalStackOffset_2();
		ir->y = ctx.GetEvalStackOffset_1();
		ctx.PopStackN(3);
		return true;
	}

	static bool IH_UnityEngine_Vector3_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		switch (method->parameters_count)
		{
		case 2:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 3);
			IHCreateAddIR(ir, CtorVector3_2);
			ir->obj = ctx.GetEvalStackOffset_3();
			ir->x = ctx.GetEvalStackOffset_2();
			ir->y = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(3);
			return true;
		}
		case 3:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 4);
			IHCreateAddIR(ir, CtorVector3_3);
			ir->obj = ctx.GetEvalStackOffset_4();
			ir->x = ctx.GetEvalStackOffset_3();
			ir->y = ctx.GetEvalStackOffset_2();
			ir->z = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(4);
			return true;
		}
		default: return false;
		}
	}

	static bool IH_UnityEngine_Vector4_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		switch (method->parameters_count)
		{
		case 2:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 3);
			IHCreateAddIR(ir, CtorVector4_2);
			ir->obj = ctx.GetEvalStackOffset_3();
			ir->x = ctx.GetEvalStackOffset_2();
			ir->y = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(3);
			return true;
		}
		case 3:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 4);
			IHCreateAddIR(ir, CtorVector4_3);
			ir->obj = ctx.GetEvalStackOffset_4();
			ir->x = ctx.GetEvalStackOffset_3();
			ir->y = ctx.GetEvalStackOffset_2();
			ir->z = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(4);
			return true;
		}
		case 4:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 5);
			IHCreateAddIR(ir, CtorVector4_4);
			ir->obj = ctx.GetEvalStackOffset_5();
			ir->x = ctx.GetEvalStackOffset_4();
			ir->y = ctx.GetEvalStackOffset_3();
			ir->z = ctx.GetEvalStackOffset_2();
			ir->w = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(5);
			return true;
		}
		default: return false;
		}
	}

	static bool IH_ByReference_get_Value(TransformContext& ctx, const MethodInfo* method)
	{
		// ByReference<T>.Value equals to *this
		IL2CPP_ASSERT(ctx.evalStackTop >= 1);
		TemporaryMemoryArena& pool = ctx.pool;
		IRBasicBlock*& curbb = ctx.curbb;
		IR2OffsetMap* ir2offsetMap = ctx.ir2offsetMap;
		uint32_t ipOffset = ctx.ipOffset;

		CreateAddIR(ir, LdindVarVar_i1);
#if HYBRIDCLR_ARCH_64
		ir->type = HiOpcodeEnum::LdindVarVar_i8;
#else
		ir->type = HiOpcodeEnum::LdindVarVar_i4;
#endif
		ir->dst = ir->src = ctx.GetEvalStackTopOffset();
		ctx.PopStack();
		ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		return true;
	}


	struct InstinctHandlerInfo
	{
		const char* namespaze;
		const char* name;
		const char* method;
		InstinctHandler handler;
	};

	static InstinctHandlerInfo s_instinctHandlerInfos[] =
	{
		{"System", "Object", ".ctor", IH_object_ctor},
		{"System", "Nullable`1", ".ctor", IH_Nullable_ctor},
		{"System", "Nullable`1", "GetValueOrDefault", IH_Nullable_GetValueOrDefault},
		{"System", "Nullable`1", "get_HasValue", IH_Nullable_get_HasValue},
		{"System", "Nullable`1", "get_Value", IH_Nullable_get_Value},
		{"System", "Array", "GetGenericValueImpl", IH_Array_GetGenericValueImpl},
		{"System", "Array", "SetGenericValueImpl", IH_Array_SetGenericValueImpl},
		{"System.Threading", "Interlocked", "CompareExchange", IH_Interlocked_CompareExchange},
		{"System.Threading", "Interlocked", "Exchange", IH_Interlocked_Exchange},
		{"System.Runtime.CompilerServices", "JitHelpers", "UnsafeEnumCast", IH_JitHelpers_UnsafeEnumCast},
		{"System.Runtime.CompilerServices", "JitHelpers", "UnsafeCast", IH_JitHelpers_UnsafeCast},
		{"System.Runtime.CompilerServices", "JitHelpers", "UnsafeEnumCastLong", IH_JitHelpers_UnsafeEnumCastLong},
		{"System.Reflection", "Assembly", "GetExecutingAssembly", IH_Assembly_GetExecutingAssembly},
		{"System.Reflection", "MethodBase", "GetCurrentMethod", IH_MethodBase_GetCurrentMethod},
		{"UnityEngine", "Vector2", ".ctor", IH_UnityEngine_Vector2_ctor},
		{"UnityEngine", "Vector3", ".ctor", IH_UnityEngine_Vector3_ctor},
		{"UnityEngine", "Vector4", ".ctor", IH_UnityEngine_Vector4_ctor},
		{"System", "ByReference`1", "get_Value", IH_ByReference_get_Value},
	};

	struct CtorInstinctHandlerInfo
	{
		const char* namespaze;
		const char* name;
		InstinctHandler handler;
	};

	static bool CIH_Object(TransformContext& ctx, const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		IHCreateAddIR(ir, NewSystemObjectVar);
		ir->obj = ctx.GetEvalStackNewTopOffset();
		ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		return true;
	}

	static bool CIH_String(TransformContext& ctx, const MethodInfo* method)
	{
		switch (method->parameters_count)
		{
		case 1:
		{
			const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(method->parameters[0]);
			if (paramType->type == IL2CPP_TYPE_SZARRAY && paramType->data.type->type == IL2CPP_TYPE_CHAR)
			{
				// new string(char[])
				IHCreateAddIR(ir, NewString);
				ir->str = ctx.GetEvalStackTopOffset();
				ir->chars = ctx.GetEvalStackTopOffset();
				return true;
			}
			return false;
		}
		case 2:
		{
			const Il2CppType* paramType1 = GET_METHOD_PARAMETER_TYPE(method->parameters[0]);
			const Il2CppType* paramType2 = GET_METHOD_PARAMETER_TYPE(method->parameters[1]);
			if (paramType1->type == IL2CPP_TYPE_CHAR && paramType2->type == IL2CPP_TYPE_I4)
			{
				IHCreateAddIR(ir, NewString_3);
				ir->str = ctx.GetEvalStackOffset_2();
				ir->c = ctx.GetEvalStackOffset_2();
				ir->count = ctx.GetEvalStackOffset_1();
				ctx.PopStack();
				return true;
			}
			return false;
		}
		case 3:
		{
			// new string(char[] chars, int startIndex, int length)
			const Il2CppType* paramType1 = GET_METHOD_PARAMETER_TYPE(method->parameters[0]);
			const Il2CppType* paramType2 = GET_METHOD_PARAMETER_TYPE(method->parameters[1]);
			const Il2CppType* paramType3 = GET_METHOD_PARAMETER_TYPE(method->parameters[2]);
			if (paramType1->type == IL2CPP_TYPE_SZARRAY && paramType1->data.type->type == IL2CPP_TYPE_CHAR
				&& paramType2->type == IL2CPP_TYPE_I4 && paramType3->type == IL2CPP_TYPE_I4)
			{
				IHCreateAddIR(ir, NewString_2);
				ir->str = ctx.GetEvalStackOffset_3();
				ir->chars = ctx.GetEvalStackOffset_3();
				ir->startIndex = ctx.GetEvalStackOffset_2();
				ir->length = ctx.GetEvalStackOffset_1();
				ctx.PopStackN(2);
				return true;
			}
			return false;
		}
		default: return false;
		}
	}

	static bool CIH_Nullable(TransformContext& ctx, const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		IL2CPP_ASSERT(IS_CLASS_VALUE_TYPE(klass));
		IL2CPP_ASSERT(ctx.evalStackTop > 0);
		il2cpp::vm::Class::SetupFields(klass);
		il2cpp::vm::Class::SetupFields(klass->castClass);
		IHCreateAddIR(ir, NullableNewVarVar);
		ir->dst = ir->data = ctx.GetEvalStackTopOffset();
		ir->klass = ctx.GetOrAddResolveDataIndex(klass);
		ctx.PopStack();
		ctx.PushStackByType(&klass->byval_arg);
		return true;
	}

	static bool CIH_MdArray(TransformContext& ctx, const MethodInfo* method)
	{
		uint8_t paramCount = method->parameters_count;
		Il2CppClass* klass = method->klass;
		if (klass->rank == paramCount)
		{
			IHCreateAddIR(ir, NewMdArrVarVar_length);
			ir->lengthIdxs = ctx.GetEvalStackOffset(ctx.evalStackTop - paramCount);
			ctx.PopStackN(paramCount);
			ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
			ir->arr = ctx.GetEvalStackTopOffset();
			ir->klass = ctx.GetOrAddResolveDataIndex(klass);
		}
		else if (klass->rank * 2 == paramCount)
		{
			IHCreateAddIR(ir, NewMdArrVarVar_length_bound);
			ir->lengthIdxs = ctx.GetEvalStackOffset(ctx.evalStackTop - paramCount);
			ir->lowerBoundIdxs = ctx.GetEvalStackOffset(ctx.evalStackTop - klass->rank);
			ctx.PopStackN(paramCount);
			ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
			ir->arr = ctx.GetEvalStackTopOffset();
			ir->klass = ctx.GetOrAddResolveDataIndex(klass);
		}
		else
		{
			RaiseExecutionEngineException("not support array ctor");
		}
		return true;
	}

	static bool CIH_Delegate(TransformContext& ctx, const MethodInfo* method)
	{
		uint8_t paramCount = method->parameters_count;
		Il2CppClass* klass = method->klass;
		IL2CPP_ASSERT(ctx.evalStackTop >= 2);
#if HYBRIDCLR_UNITY_2021_OR_NEW
		const MethodInfo* ctor = il2cpp::vm::Class::GetMethodFromName(method->klass, ".ctor", 2);
		if (ctor && ctor->methodPointer && !ctor->isInterpterImpl)
		{
			IHCreateAddIR(ir, CtorDelegate);
			ir->dst = ir->obj = ctx.GetEvalStackOffset_2();
			ir->ctor = ctx.GetOrAddResolveDataIndex(ctor);
			ir->method = ctx.GetEvalStackOffset_1();
		}
		else
		{
			IHCreateAddIR(ir, NewDelegate);
			ir->dst = ir->obj = ctx.GetEvalStackOffset_2();
			ir->klass = ctx.GetOrAddResolveDataIndex(klass);
			ir->method = ctx.GetEvalStackOffset_1();
		}
#else
		IHCreateAddIR(ir, NewDelegate);
		ir->dst = ir->obj = ctx.GetEvalStackOffset_2();
		ir->klass = ctx.GetOrAddResolveDataIndex(klass);
		ir->method = ctx.GetEvalStackOffset_1();
#endif
		ctx.PopStackN(2);
		ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		return true;
	}

	static bool CIH_UnityEngine_Vector2_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		if (method->parameters_count != 2)
		{
			return false;
		}
		IL2CPP_ASSERT(ctx.evalStackTop >= 2);
		IHCreateAddIR(ir, NewVector2);
		ir->obj = ir->x = ctx.GetEvalStackOffset_2();
		ir->y = ctx.GetEvalStackOffset_1();
		ctx.PopStackN(2);
		ctx.PushStackByType(&method->klass->byval_arg);
		return true;
	}

	static bool CIH_UnityEngine_Vector3_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		switch (method->parameters_count)
		{
		case 2:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 2);
			IHCreateAddIR(ir, NewVector3_2);
			ir->obj = ir->x = ctx.GetEvalStackOffset_2();
			ir->y = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(2);
			ctx.PushStackByType(&method->klass->byval_arg);
			return true;
		}
		case 3:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 3);
			IHCreateAddIR(ir, NewVector3_3);
			ir->obj = ir->x = ctx.GetEvalStackOffset_3();
			ir->y = ctx.GetEvalStackOffset_2();
			ir->z = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(3);
			ctx.PushStackByType(&method->klass->byval_arg);
			return true;
		}
		default: return false;
		}
	}

	static bool CIH_UnityEngine_Vector4_ctor(TransformContext& ctx, const MethodInfo* method)
	{
		switch (method->parameters_count)
		{
		case 2:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 2);
			IHCreateAddIR(ir, NewVector4_2);
			ir->obj = ir->x = ctx.GetEvalStackOffset_2();
			ir->y = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(2);
			ctx.PushStackByType(&method->klass->byval_arg);
			return true;
		}
		case 3:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 3);
			IHCreateAddIR(ir, NewVector4_3);
			ir->obj = ir->x = ctx.GetEvalStackOffset_3();
			ir->y = ctx.GetEvalStackOffset_2();
			ir->z = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(3);
			ctx.PushStackByType(&method->klass->byval_arg);
			return true;
		}
		case 4:
		{
			IL2CPP_ASSERT(ctx.evalStackTop >= 4);
			IHCreateAddIR(ir, NewVector4_4);
			ir->obj = ir->x = ctx.GetEvalStackOffset_4();
			ir->y = ctx.GetEvalStackOffset_3();
			ir->z = ctx.GetEvalStackOffset_2();
			ir->w = ctx.GetEvalStackOffset_1();
			ctx.PopStackN(4);
			ctx.PushStackByType(&method->klass->byval_arg);
			return true;
		}
		default: return false;
		}
	}

	static bool CIH_ByReference(TransformContext& ctx, const MethodInfo* method)
	{
		// new ByReference<T>(ref T value) don't need to do anything
		Il2CppClass* klass = method->klass;
		IL2CPP_ASSERT(ctx.evalStackTop > 0);
		ctx.PopStack();
		ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
		return true;
	}

	static CtorInstinctHandlerInfo s_ctorInstinctHandlerInfos[] =
	{
		{"System", "Object", CIH_Object},
		{"System", "String", CIH_String},
		{"System", "Nullable`1", CIH_Nullable},

		{"UnityEngine", "Vector2", CIH_UnityEngine_Vector2_ctor},
		{"UnityEngine", "Vector3", CIH_UnityEngine_Vector3_ctor},
		{"UnityEngine", "Vector4", CIH_UnityEngine_Vector4_ctor},

		{"System", "ByReference`1", CIH_ByReference},
	};
	
	void TransformContext::InitializeInstinctHandlers()
	{
		for (InstinctHandlerInfo& handler : s_instinctHandlerInfos)
		{
			NamespaceAndNameAndMethod nnm = { handler.namespaze, handler.name, handler.method };
			s_instinctHandlerMap.add(nnm, handler.handler);
		}
		for (CtorInstinctHandlerInfo& handler : s_ctorInstinctHandlerInfos)
		{
			NamespaceAndName nnm = { handler.namespaze, handler.name };
			s_ctorInstinctHandlerMap.add(nnm, handler.handler);
		}
	}
	
	bool TransformContext::TryAddInstinctCtorInstruments(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;

		if (klass->byval_arg.type == IL2CPP_TYPE_ARRAY)
		{
			return CIH_MdArray(*this, method);
		}

		if (IsChildTypeOfMulticastDelegate(method->klass))
		{
			return CIH_Delegate(*this, method);
		}

		NamespaceAndName key = { klass->namespaze, klass->name };
		auto it = s_ctorInstinctHandlerMap.find(key);
		if (it != s_ctorInstinctHandlerMap.end())
		{
			return (it->second)(*this, method);
		}
		return false;
	}

	bool TransformContext::TryAddInstinctInstrumentsByName(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		const char* namespaceName = klass->namespaze;
		const char* klassName = klass->name;
		const char* methodName = method->name;
		uint32_t paramCount = method->parameters_count;

		NamespaceAndNameAndMethod key = { namespaceName, klassName, methodName };
		auto it = s_instinctHandlerMap.find(key);
		if (it == s_instinctHandlerMap.end())
		{
			return false;
		}
		return (it->second)(*this, method);
	}

	bool TransformContext::TryAddArrayInstinctInstruments(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;

		// warn! can't change to else if. because namespace == system
		if (klass->byval_arg.type == IL2CPP_TYPE_ARRAY)
		{
			const char* methodName = method->name;
			uint8_t paramCount = method->parameters_count + 1;
			const Il2CppType* eleType = &klass->element_class->byval_arg;
			LocationDescInfo desc = ComputLocationDescInfo(eleType);
			if (strcmp(methodName, "Get") == 0)
			{
				CreateAddIR(ir, GetMdArrElementVarVar_n);
				ir->type = CalcGetMdArrElementVarVarOpcode(eleType);
				ir->arr = GetEvalStackOffset(evalStackTop - paramCount);
				ir->lengthIdxs = ir->arr + 1;
				PopStackN(paramCount);
				PushStackByType(eleType);
				ir->value = GetEvalStackTopOffset();
				return true;
			}
			else if (strcmp(methodName, "Address") == 0)
			{
				CreateAddIR(ir, GetMdArrElementAddressVarVar);
				ir->arr = GetEvalStackOffset(evalStackTop - paramCount);
				ir->lengthIdxs = ir->arr + 1;
				PopStackN(paramCount);
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				ir->addr = GetEvalStackTopOffset();
				return true;
			}
			else if (strcmp(methodName, "Set") == 0)
			{
				CreateAddIR(ir, SetMdArrElementVarVar_n);
				switch (desc.type)
				{
				case LocationDescType::I1: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_i1; break;
				case LocationDescType::U1: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_u1; break;
				case LocationDescType::I2: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_i2; break;
				case LocationDescType::U2: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_u2; break;
				case LocationDescType::I4: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_i4; break;
				case LocationDescType::I8: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_i8; break;
				case LocationDescType::Ref: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_ref; break;
				case LocationDescType::S: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_n; break;
				case LocationDescType::StructContainsRef: ir->type = HiOpcodeEnum::SetMdArrElementVarVar_WriteBarrier_n; break;
				default: RaiseExecutionEngineException("not support array element type"); break;
				}
				ir->arr = GetEvalStackOffset(evalStackTop - paramCount);
				ir->lengthIdxs = ir->arr + 1;
				ir->ele = GetEvalStackTopOffset();
				PopStackN(paramCount);
				return true;
			}
		}
		return false;
	}

}
}