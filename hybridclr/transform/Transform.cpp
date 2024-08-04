
#include "Transform.h"

#include "metadata/GenericMetadata.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/String.h"
#include "vm/Field.h"

#include "../interpreter/InterpreterUtil.h"

#include "TransformContext.h"

using namespace hybridclr::metadata;
using namespace hybridclr::interpreter;

namespace hybridclr
{
namespace transform
{

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
if (brOffset != 0) \
{\
	ctx.Add_bc(ipOffset, brOffset, 2, HiOpcodeEnum::BranchVarVar_##opName##_i4, HiOpcodeEnum::BranchVarVar_##opName##_i8, HiOpcodeEnum::BranchVarVar_##opName##_f4, HiOpcodeEnum::BranchVarVar_##opName##_f8); \
}\
else\
{\
	ctx.PopStackN(2);\
}\
ip += 2;

#define CI_branch4(opName) IL2CPP_ASSERT(evalStackTop >= 2); \
brOffset = GetI4LittleEndian(ip + 1); \
if (brOffset != 0) \
{ \
	ctx.Add_bc(ipOffset, brOffset, 5, HiOpcodeEnum::BranchVarVar_##opName##_i4, HiOpcodeEnum::BranchVarVar_##opName##_i8, HiOpcodeEnum::BranchVarVar_##opName##_f4, HiOpcodeEnum::BranchVarVar_##opName##_f8); \
}\
else \
{\
	ctx.PopStackN(2);\
}\
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

#define CI_ldele(eleType, resultType) ctx.Add_ldelem(EvalStackReduceDataType::resultType, HiOpcodeEnum::GetArrayElementVarVar_##eleType);
#define CI_stele(eleType) ctx.Add_stelem(HiOpcodeEnum::SetArrayElementVarVar_##eleType);

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
		LocVarInfo* locals = pool.NewNAny<LocVarInfo>((int)body.localVars.size());
		// FIXME may exceed max size
		// TODO MEMORY OPTIMISTIC
		EvalStackVarInfo* evalStack = pool.NewNAny<EvalStackVarInfo>(body.maxStack + 100);

		il2cpp::utils::dynamic_array<uint64_t> resolveDatas;

		// TODO. alloc use pool
		Il2CppHashMap<uint32_t, uint32_t, il2cpp::utils::PassThroughHash<uint32_t>> token2DataIdxs;
		// TOTO. alloc use pool
		Il2CppHashMap<const void*, uint32_t, il2cpp::utils::PassThroughHash<const void*>> ptr2DataIdxs;

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
		for (size_t i = 0; i < body.localVars.size(); i++)
		{
			LocVarInfo& local = locals[i];
			// FIXME memory leak
			local.type = InflateIfNeeded(body.localVars[i], genericContext, true);
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
		uint32_t ipOffset = 0;

		int32_t evalStackTop = 0;
		int32_t prefixFlags = 0;

		uint32_t argIdx = 0;
		int32_t varKst = 0;
		int64_t varKst8 = 0;
		int32_t brOffset = 0;
		const MethodInfo* shareMethod = nullptr;

		Token2RuntimeHandleMap tokenCache(64);

		hybridclr::metadata::PDBImage* pdbImage = image->GetPDBImage();
		IR2OffsetMap* ir2offsetMap = pdbImage ? new IR2OffsetMap(body.codeSize) : nullptr;

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
			ipOffset,
			ir2offsetMap,
		};

		bool initLocals = (body.flags & (uint32_t)CorILMethodFormat::InitLocals) != 0;
		// init local vars
		if (initLocals && totalLocalSize > 0)
		{
			ctx.AddInst(CreateInitLocals(pool, totalLocalSize * sizeof(StackObject)));
		}

		il2cpp::utils::dynamic_array<InterpExceptionClause> exClauses(body.exceptionClauses.size());
		int clauseIdx = 0;
		for (ExceptionClause& ec : body.exceptionClauses)
		{
			InterpExceptionClause* iec = &exClauses[clauseIdx++];
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
				iec->exKlass = image->GetClassFromToken(tokenCache, ec.classTokenOrFilterOffset, klassContainer, methodContainer, genericContext);
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
				if (ctx.TryAddInstinctInstruments(shareMethod))
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
				uint32_t methodDataIndex = ctx.GetOrAddResolveDataIndex(shareMethod);

				if (hybridclr::metadata::IsInterpreterImplement(shareMethod))
				{
					ctx.PopStackN(resolvedTotalArgNum);

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
#if HYBRIDCLR_UNITY_2021_OR_NEW
				if (!shareMethod->has_full_generic_sharing_signature)
#endif
				{
					if (ctx.TryAddCallCommonInstruments(shareMethod, methodDataIndex))
					{
						continue;
					}
				}



				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = ctx.GetOrAddResolveDataIndex((void*)managed2NativeMethod);

				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);

				if (resolvedIsInstanceMethod)
				{
					__argIdxs[0] = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
				}

				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + resolvedIsInstanceMethod;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				ctx.PopStackN(resolvedTotalArgNum);

				if (!IsReturnVoidMethod(shareMethod))
				{
					ctx.PushStackByType(shareMethod->return_type);
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(shareMethod->return_type);
					if (interpreter::IsNeedExpandLocationType(locDataType))
					{
						CreateAddIR(ir, CallNativeInstance_ret_expand);
						ir->type = resolvedIsInstanceMethod ? HiOpcodeEnum::CallNativeInstance_ret_expand : HiOpcodeEnum::CallNativeStatic_ret_expand;
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = ctx.GetEvalStackTopOffset();
						ir->retLocationType = (uint8_t)locDataType;
					}
					else
					{
						CreateAddIR(ir, CallNativeInstance_ret);
						ir->type = resolvedIsInstanceMethod ? HiOpcodeEnum::CallNativeInstance_ret : HiOpcodeEnum::CallNativeStatic_ret;
						ir->managed2NativeMethod = managed2NativeMethodDataIdx;
						ir->methodInfo = methodDataIndex;
						ir->argIdxs = argIdxDataIndex;
						ir->ret = ctx.GetEvalStackTopOffset();
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
				uint32_t methodDataIndex = ctx.GetOrAddResolveDataIndex(shareMethod);

				bool isMultiDelegate = IsChildTypeOfMulticastDelegate(shareMethod->klass);
				if (!isMultiDelegate && IsInterpreterMethod(shareMethod) && !IsInterface(shareMethod->klass->flags))
				{
					ctx.PopStackN(resolvedTotalArgNum);

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
				uint32_t managed2NativeMethodDataIdx = ctx.GetOrAddResolveDataIndex((void*)managed2NativeMethod);


				int32_t needDataSlotNum = (resolvedTotalArgNum + 3) / 4;
				int32_t argIdxDataIndex;
				uint16_t* __argIdxs;
				AllocResolvedData(resolveDatas, needDataSlotNum, argIdxDataIndex, __argIdxs);

				__argIdxs[0] = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);
				for (uint8_t i = 0; i < shareMethod->parameters_count; i++)
				{
					int32_t curArgIdx = i + 1;
					__argIdxs[curArgIdx] = evalStack[callArgEvalStackIdxBase + curArgIdx].locOffset;
				}

				ctx.PopStackN(resolvedTotalArgNum);

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
				if (isMultiDelegate)
				{
					if (std::strcmp(shareMethod->name, "Invoke") == 0)
					{
						Managed2NativeCallMethod staticManaged2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, true);
						IL2CPP_ASSERT(staticManaged2NativeMethod);
						uint32_t staticManaged2NativeMethodDataIdx = ctx.GetOrAddResolveDataIndex((void*)staticManaged2NativeMethod);
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

				int32_t methodIdx = ctx.GetEvalStackTopOffset();
				//uint32_t methodDataIndex = ctx.GetOrAddResolveDataIndex(shareMethod);
				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(methodSig);
				IL2CPP_ASSERT(managed2NativeMethod);
				uint32_t managed2NativeMethodDataIdx = ctx.GetOrAddResolveDataIndex((void*)managed2NativeMethod);
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

				ctx.PopStackN(resolvedTotalArgNum + 1);

				if (!IsVoidType(methodSig.returnType))
				{
					ctx.PushStackByType(methodSig.returnType);
					interpreter::LocationDataType locDataType = GetLocationDataTypeByType(methodSig.returnType);
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
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 2;
					ctx.Add_brtruefalse(false, targetOffset);
				}
				else
				{
					ctx.PopStack();
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
					ctx.Add_brtruefalse(true, targetOffset);
				}
				else
				{
					ctx.PopStack();
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
				if (brOffset != 0)
				{
					int32_t targetOffset = ipOffset + brOffset + 5;
					ctx.Add_brtruefalse(false, targetOffset);
				}
				else
				{
					ctx.PopStack();
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
					ctx.Add_brtruefalse(true, targetOffset);
				}
				else
				{
					ctx.PopStack();
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

				uint32_t switchValue = ctx.GetEvalStackTopOffset();
				uint32_t n = (uint32_t)GetI4LittleEndian(ip + 1);
				ir->value = ctx.GetEvalStackTopOffset();
				ir->caseNum = n;

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
#if HYBRIDCLR_ARCH_64
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
#if HYBRIDCLR_ARCH_64
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i8, NATIVE_INT_REDUCE_TYPE);
#else
				ctx.Add_ldind(HiOpcodeEnum::LdindVarVar_i4, NATIVE_INT_REDUCE_TYPE);
#endif
				continue;
			}
			case OpcodeValue::STIND_REF:
			{
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_ref);
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

				ctx.PopStackN(2);
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

				ctx.PopStack();
				ctx.PushStackByType(&objKlass->byval_arg);
				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();
				ip += 5;
				continue;
			}
			case OpcodeValue::LDSTR:
			{
				uint32_t token = (uint32_t)GetI4LittleEndian(ip + 1);
				Il2CppString* str = image->GetIl2CppUserStringFromRawIndex(DecodeTokenRowIndex(token));
				uint32_t dataIdx = ctx.GetOrAddResolveDataIndex(str);

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
				shareMethod = const_cast<MethodInfo*>(image->GetMethodInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(shareMethod);
				IL2CPP_ASSERT(!std::strcmp(shareMethod->name, ".ctor"));
				IL2CPP_ASSERT(hybridclr::metadata::IsInstanceMethod(shareMethod));
				if (ctx.TryAddInstinctCtorInstruments(shareMethod))
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
						for (int32_t i = evalStackTop ; i > thisIdx; i--)
						{
							evalStack[i] = evalStack[i - 1];
						}
						// locOffset of this is not important. You only need make sure the value is not equal to nullptr.
						evalStack[thisIdx] = { NATIVE_INT_REDUCE_TYPE, PTR_SIZE, ctx.GetEvalStackOffset(thisIdx) };
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
				uint16_t objIdx = ctx.GetEvalStackOffset(callArgEvalStackIdxBase);

				int32_t resolvedTotalArgNum = shareMethod->parameters_count + 1;

				uint32_t methodDataIndex = ctx.GetOrAddResolveDataIndex(shareMethod);

				if (IsInterpreterImplement(shareMethod))
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

				int32_t needDataSlotNum = (resolvedTotalArgNum + 3) / 4;
				Managed2NativeCallMethod managed2NativeMethod = InterpreterModule::GetManaged2NativeMethodPointer(shareMethod, false);
				IL2CPP_ASSERT((void*)managed2NativeMethod);
				//uint32_t managed2NativeMethodDataIdx = ctx.GetOrAddResolveDataIndex(managed2NativeMethod);



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
				ctx.PopStackN(resolvedTotalArgNum + 1); // args + obj + this
				ctx.PushStackByType(&klass->byval_arg);
				CreateAddIR(ir, NewClassVar);
				ir->type = IS_CLASS_VALUE_TYPE(shareMethod->klass) ? HiOpcodeEnum::NewValueTypeVar : HiOpcodeEnum::NewClassVar;
				ir->managed2NativeMethod = ctx.GetOrAddResolveDataIndex((void*)managed2NativeMethod);
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
				uint32_t klassDataIdx = ctx.GetOrAddResolveDataIndex(objKlass);

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
				Il2CppClass* objKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				IL2CPP_ASSERT(objKlass);

				if (il2cpp::vm::Class::IsNullable(objKlass))
				{
					objKlass = il2cpp::vm::Class::GetNullableArgument(objKlass);
				}
				uint32_t klassDataIdx = ctx.GetOrAddResolveDataIndex(objKlass);

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
				ir->addr = ir->obj = ctx.GetEvalStackTopOffset();
				ir->klass = ctx.GetOrAddResolveDataIndex(objKlass);

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
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
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
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
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
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
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
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);
				uint32_t parentIndex = ctx.GetOrAddResolveDataIndex(fieldInfo->parent);
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
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint16_t dstIdx = ctx.GetEvalStackNewTopOffset();
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
							ir->src = ctx.GetOrAddResolveDataIndex(il2cpp::vm::Field::GetData(fieldInfo));
						}
					}
					if (!ldfldFromFieldData)
					{
						CreateAddIR(ir, LdsfldaVarVar);
						ir->dst = dstIdx;
						ir->klass = ctx.GetOrAddResolveDataIndex(fieldInfo->parent);
						ir->offset = fieldInfo->offset;
					}
				}
				else
				{
					CreateAddIR(ir, LdthreadlocalaVarVar);
					ir->dst = dstIdx;
					ir->klass = ctx.GetOrAddResolveDataIndex(fieldInfo->parent);
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
				FieldInfo* fieldInfo = const_cast<FieldInfo*>(image->GetFieldInfoFromToken(tokenCache, token, klassContainer, methodContainer, genericContext));
				IL2CPP_ASSERT(fieldInfo);

				uint32_t klassIndex = ctx.GetOrAddResolveDataIndex(fieldInfo->parent);
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
				ctx.InsertMemoryBarrier();
				ctx.ResetPrefixFlags();

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
				
				ctx.PopStackN(2);
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
				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
				if (IS_CLASS_VALUE_TYPE(objKlass))
				{
					CreateAddIR(ir, BoxVarVar);
					ir->dst = ir->data = ctx.GetEvalStackTopOffset();
					ir->klass = ctx.GetOrAddResolveDataIndex(objKlass);
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
				uint32_t arrKlassIndex = ctx.GetOrAddResolveDataIndex(arrKlass);

				CreateAddIR(ir, NewArrVarVar);
				ir->arr = ir->size = varSize.locOffset;
				ir->klass = arrKlassIndex;

				ctx.PopStack();
				ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

				ip += 5;
				continue;
			}
			case OpcodeValue::LDLEN:
			{
				IL2CPP_ASSERT(evalStackTop > 0);
				CreateAddIR(ir, GetArrayLengthVarVar);
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
				Il2CppClass* eleKlass = image->GetClassFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);
				uint32_t eleKlassIndex = ctx.GetOrAddResolveDataIndex(eleKlass);

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
				ctx.ResetPrefixFlags();
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
				ctx.PopStackN(2);
				ctx.PushStackByType(eleType);

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
				case LocationDescType::Ref: { CI_stele0(ref); break;}
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
				ctx.PopStackN(3);

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
					ir->dst = ir->obj = ctx.GetEvalStackTopOffset();
					ir->klass = ctx.GetOrAddResolveDataIndex(objKlass);

					ctx.PopStack();
					ctx.PushStackByType(&objKlass->byval_arg);
				}
				else
				{
					CreateAddIR(ir, CastclassVar);
					ir->obj = ctx.GetEvalStackTopOffset();
					ir->klass = ctx.GetOrAddResolveDataIndex(objKlass);
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
				ir->addr = ir->typedRef = ctx.GetEvalStackTopOffset();
				ir->klass = ctx.GetOrAddResolveDataIndex(objKlass);
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
				ir->dst = ir->data = ctx.GetEvalStackTopOffset();
				ir->klass = ctx.GetOrAddResolveDataIndex(objKlass);
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
				void* runtimeHandle = (void*)image->GetRuntimeHandleFromToken(tokenCache, token, klassContainer, methodContainer, genericContext);

				CreateAddIR(ir, LdtokenVar);
				ir->runtimeHandle = ctx.GetEvalStackNewTopOffset();
				ir->token = ctx.GetOrAddResolveDataIndex(runtimeHandle);
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
#if HYBRIDCLR_ARCH_64
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i8);
#else
				ctx.Add_stind(HiOpcodeEnum::StindVarVar_i4);
#endif
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
					ir->dst = ctx.GetEvalStackNewTopOffset();
					ir->src = (uint64_t)methodInfo;
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
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
					ir->resultMethod = ir->obj = ctx.GetEvalStackTopOffset();
					ir->virtualMethod = ctx.GetOrAddResolveDataIndex(methodInfo);

					ctx.PopStack();
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);
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
						RaiseExecutionEngineException("LOCALLOC invalid reduceType");
						break;
					}
					}
					ctx.PopStack();
					ctx.PushStackByReduceType(NATIVE_INT_REDUCE_TYPE);

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
					ir->value = ctx.GetEvalStackTopOffset();
					ctx.PopAllStack();

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
							ir->obj = ctx.GetEvalStackTopOffset();
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
								ir->obj = ctx.GetEvalStackTopOffset();
								convert = true;
								break;
							}
							case 2:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 2)
								{
									CreateAddIR(ir, InitobjVar_2);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 4:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_4);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 8:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_8);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 12:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_12);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 16:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_16);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 20:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_20);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 24:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_24);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 28:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 4)
								{
									CreateAddIR(ir, InitobjVar_28);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							case 32:
							{
								if (SUPPORT_MEMORY_NOT_ALIGMENT_ACCESS || objKlass->minimumAlignment >= 8)
								{
									CreateAddIR(ir, InitobjVar_32);
									ir->obj = ctx.GetEvalStackTopOffset();
									convert = true;
								}
								break;
							}
							}
							if (!convert)
							{
								CreateAddIR(ir, InitobjVar_n_4);
								ir->obj = ctx.GetEvalStackTopOffset();
								ir->size = objSize;
							}
						}
					}
					else
					{
						CreateAddIR(ir, InitobjVar_ref);
						ir->obj = ctx.GetEvalStackTopOffset();
					}
					ctx.PopStack();

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
							ir->klass = ctx.GetOrAddResolveDataIndex(conKlass);

							self.reduceType = NATIVE_INT_REDUCE_TYPE;
							self.byteSize = GetSizeByReduceType(self.reduceType);
							goto LabelCallVir;
						}
					}
					else
					{
						// deref object. FIXME gc memory barrier
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
					ctx.InsertMemoryBarrier();
					ctx.ResetPrefixFlags();
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
				case OpcodeValue::INITBLK:
				{
					IL2CPP_ASSERT(evalStackTop >= 3);
					ctx.InsertMemoryBarrier();
					ctx.ResetPrefixFlags();
					CreateAddIR(ir, InitblkVarVarVar);
					ir->addr = ctx.GetEvalStackOffset_3();
					ir->value = ctx.GetEvalStackOffset_2();
					ir->size = ctx.GetEvalStackOffset_1();
					ctx.PopStackN(3);
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
					ctx.AddInst(ir);
					ctx.PopAllStack();
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
					ctx.CreateAddInst_ldc4(typeSize, EvalStackReduceDataType::I4);
					ip += 6;
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
		byte* tranCodes = (byte*)HYBRIDCLR_METADATA_MALLOC(totalSize);

		uint32_t tranOffset = 0;
		for (IRBasicBlock* bb : irbbs)
		{
			bb->codeOffset = tranOffset;
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
			bb->~IRBasicBlock();
		}
		IL2CPP_ASSERT(tranOffset == totalSize);

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
		result.codeLength = totalSize;
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
			pdbImage->SetMethodDebugInfo(methodInfo, *ilMappers);
		}
	}
}

}
