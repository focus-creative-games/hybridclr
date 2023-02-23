#include "TransformContext.h"

namespace hybridclr
{
namespace transform
{

	bool TransformContext::TryAddInstinctInstrumentsByName(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;
		const char* namespaceName = klass->namespaze;
		const char* klassName = klass->name;
		const char* methodName = method->name;
		uint32_t paramCount = method->parameters_count;

		if (std::strcmp(namespaceName, "System") == 0)
		{
			if (std::strcmp(klassName, "Object") == 0)
			{
				// special handle
				if (std::strcmp(methodName, ".ctor") == 0)
				{
					PopStack();
					return true;
				}
				// get_HasValue
				// do nothing
			}
			else if (std::strcmp(klassName, "Nullable`1") == 0)
			{
				il2cpp::vm::Class::SetupFields(klass);
				il2cpp::vm::Class::SetupFields(klass->castClass);
				uint16_t topOffset = GetEvalStackTopOffset();
				uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
				if (strcmp(methodName, ".ctor") == 0)
				{
					if (paramCount == 1)
					{
						IL2CPP_ASSERT(evalStackTop >= 2);
						CreateAddIR(ir, NullableCtorVarVar);
						ir->dst = GetEvalStackOffset_2();
						ir->data = GetEvalStackOffset_1();
						ir->klass = classIndirectIndex;

						PopStackN(2);
						return true;
					}
				}
				else if (strcmp(methodName, "GetValueOrDefault") == 0)
				{
					uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
					if (paramCount == 0)
					{
						IL2CPP_ASSERT(evalStackTop >= 1);
						CreateAddIR(ir, NullableGetValueOrDefaultVarVar);
						ir->dst = topOffset;
						ir->obj = topOffset;
						ir->klass = classIndirectIndex;

						// pop this, push value
						PopStack();
						PushStackByType(&klass->castClass->byval_arg);
						return true;
					}
					else if (paramCount == 1)
					{
						IL2CPP_ASSERT(evalStackTop >= 2);
						CreateAddIR(ir, NullableGetValueOrDefaultVarVar_1);
						ir->dst = ir->obj = GetEvalStackOffset_2();
						ir->defaultValue = topOffset;
						ir->klass = classIndirectIndex;

						// pop this, default value then push value
						PopStackN(2);
						PushStackByType(&klass->castClass->byval_arg);
						return true;
					}
				}
				else if (strcmp(methodName, "get_HasValue") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 1);
					uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
					CreateAddIR(ir, NullableHasValueVar);
					ir->result = topOffset;
					ir->obj = topOffset;
					ir->klass = classIndirectIndex;

					// pop this, push value
					PopStack();
					PushStackByReduceType(EvalStackReduceDataType::I4);
					return true;
				}
				else if (strcmp(methodName, "get_Value") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 1);
					uint32_t classIndirectIndex = GetOrAddResolveDataIndex(ptr2DataIdxs, resolveDatas, klass);
					CreateAddIR(ir, NullableGetValueVarVar);
					ir->dst = topOffset;
					ir->obj = topOffset;
					ir->klass = classIndirectIndex;

					// pop this, push value
					PopStack();
					PushStackByType(&klass->castClass->byval_arg);
					return true;
				}
			}
			else if (std::strcmp(klassName, "Array") == 0)
			{
				if (strcmp(methodName, "GetGenericValueImpl") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 3);
					uint16_t topOffset = GetEvalStackTopOffset();
					CreateAddIR(ir, ArrayGetGenericValueImpl);
					ir->arr = GetEvalStackOffset_3();
					ir->index = GetEvalStackOffset_2();
					ir->value = GetEvalStackOffset_1();
					PopStackN(3);
					return true;
				}
				if (strcmp(methodName, "SetGenericValueImpl") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 3);
					uint16_t topOffset = GetEvalStackTopOffset();
					CreateAddIR(ir, ArraySetGenericValueImpl);
					ir->arr = GetEvalStackOffset_3();
					ir->index = GetEvalStackOffset_2();
					ir->value = GetEvalStackOffset_1();
					PopStackN(3);
					return true;
				}
			}
		}
		else if (strcmp(namespaceName, "System.Threading") == 0)
		{
			if (strcmp(klassName, "Interlocked") == 0)
			{
				if (strcmp(methodName, "CompareExchange") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 3);
					uint16_t retIdx = GetEvalStackOffset_3();
					uint16_t locationIdx = retIdx;
					uint16_t valueIdx = GetEvalStackOffset_2();
					uint16_t comparandIdx = GetEvalStackOffset_1();

					CreateAddIR(ir, InterlockedCompareExchangeVarVarVarVar_pointer);
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
					PopStackN(3);
					PushStackByType(paramType);

					return true;
				}
				else if (strcmp(methodName, "Exchange") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 2);
					uint16_t retIdx = GetEvalStackOffset_2();
					uint16_t locationIdx = retIdx;
					uint16_t valueIdx = GetEvalStackOffset_1();

					CreateAddIR(ir, InterlockedExchangeVarVarVar_pointer);
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
					PopStackN(2);
					PushStackByType(paramType);
					return true;
				}
			}
		}
		else if (strcmp(namespaceName, "System.Runtime.CompilerServices") == 0)
		{
			if (strcmp(klass->name, "JitHelpers") == 0)
			{
				if (strcmp(methodName, "UnsafeEnumCast") == 0)
				{
					IL2CPP_ASSERT(evalStackTop >= 1);
					CreateAddIR(ir, UnsafeEnumCast);
					ir->dst = GetEvalStackTopOffset();
					ir->src = GetEvalStackTopOffset();
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
					PopStack();
					PushStackByReduceType(EvalStackReduceDataType::I4);
					return true;
				}
				else if (strcmp(methodName, "UnsafeCast") == 0 || strcmp(methodName, "UnsafeEnumCastLong") == 0)
				{
					return true;
				}
			}
		}
		else if (strcmp(klassName, "Assembly") == 0 && strcmp(namespaceName, "System.Reflection") == 0)
		{
			if (strcmp(methodName, "GetExecutingAssembly") == 0)
			{
				IL2CPP_ASSERT(evalStackTop >= 0);
				CreateAddIR(ir, AssemblyGetExecutingAssembly);
				ir->ret = GetEvalStackNewTopOffset();
				PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				return true;
			}
		}
		else if (strcmp(namespaceName, "UnityEngine") == 0)
		{
			if (strcmp(methodName, ".ctor") == 0)
			{
				if (strcmp(klassName, "Vector2") == 0)
				{
					if (paramCount == 3)
					{
						IL2CPP_ASSERT(evalStackTop >= 3);
						CreateAddIR(ir, NewVector2);
						ir->obj = GetEvalStackOffset_3();
						ir->x = GetEvalStackOffset_2();
						ir->y = GetEvalStackOffset_1();
						PopStackN(3);
						return true;
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
						ir->obj = GetEvalStackOffset_3();
						ir->x = GetEvalStackOffset_2();
						ir->y = GetEvalStackOffset_1();
						PopStackN(3);
						return true;
					}
					case 3:
					{
						IL2CPP_ASSERT(evalStackTop >= 4);
						CreateAddIR(ir, NewVector3_3);
						ir->obj = GetEvalStackOffset_4();
						ir->x = GetEvalStackOffset_3();
						ir->y = GetEvalStackOffset_2();
						ir->z = GetEvalStackOffset_1();
						PopStackN(4);
						return true;
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
						ir->obj = GetEvalStackOffset_3();
						ir->x = GetEvalStackOffset_2();
						ir->y = GetEvalStackOffset_1();
						PopStackN(3);
						return true;
					}
					case 3:
					{
						IL2CPP_ASSERT(evalStackTop >= 4);
						CreateAddIR(ir, NewVector4_3);
						ir->obj = GetEvalStackOffset_4();
						ir->x = GetEvalStackOffset_3();
						ir->y = GetEvalStackOffset_2();
						ir->z = GetEvalStackOffset_1();
						PopStackN(4);
						return true;
					}
					case 4:
					{
						IL2CPP_ASSERT(evalStackTop >= 5);
						CreateAddIR(ir, NewVector4_4);
						ir->obj = GetEvalStackOffset_5();
						ir->x = GetEvalStackOffset_4();
						ir->y = GetEvalStackOffset_3();
						ir->z = GetEvalStackOffset_2();
						ir->w = GetEvalStackOffset_1();
						PopStackN(5);
						return true;
					}
					default:
						break;
					}
				}
			}
		}
		return false;
	}

	bool TransformContext::TryAddArrayInstinctInstruments(const MethodInfo* method)
	{
		Il2CppClass* klass = method->klass;

		// warn! can't change to else if. because namespace == system
		if (klass->byval_arg.type == IL2CPP_TYPE_ARRAY)
		{
			const char* methodName = method->name;
			uint8_t paramCount = method->parameters_count + 1;
			if (strcmp(methodName, "Get") == 0)
			{
				CreateAddIR(ir, GetMdArrElementVarVar_size);
				ir->type = CalcGetMdArrElementVarVarOpcode(&klass->element_class->byval_arg);
				ir->arr = GetEvalStackOffset(evalStackTop - paramCount);
				ir->lengthIdxs = ir->arr + 1;
				PopStackN(paramCount);
				PushStackByType(&klass->element_class->byval_arg);
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
				CreateAddIR(ir, SetMdArrElementVarVar);
				ir->arr = GetEvalStackOffset(evalStackTop - paramCount);
				ir->lengthIdxs = ir->arr + 1;
				ir->value = GetEvalStackTopOffset();
				PopStackN(paramCount);
				return true;
			}
		}
		return false;
	}

}
}