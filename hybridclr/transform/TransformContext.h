#pragma once

#include "TemporaryMemoryArena.h"

#include "../metadata/Image.h"
#include "../interpreter/Instruction.h"
#include "../interpreter/Engine.h"
#include "../metadata/MetadataUtil.h"
#include "../metadata/Opcodes.h"
#include "../metadata/MetadataModule.h"
#include "../interpreter/Instruction.h"
#include "../interpreter/Interpreter.h"
#include "../interpreter/InterpreterModule.h"

#include "Transform.h"

namespace hybridclr
{
namespace transform
{
	using namespace hybridclr::metadata;
	using namespace hybridclr::interpreter;

	struct IRBasicBlock
	{
		bool visited;
		bool inPending;
		uint32_t ilOffset;
		uint32_t codeOffset;
		std::vector<interpreter::IRCommon*> insts;
	};

	struct ArgVarInfo
	{
		const Il2CppType* type;
		Il2CppClass* klass;
		int32_t argOffset; // StackObject index
		int32_t argLocOffset;
	};

	struct LocVarInfo
	{
		const Il2CppType* type;
		Il2CppClass* klass;
		int32_t locOffset;
	};

	enum class EvalStackReduceDataType
	{
		I4,
		I8,
		R4,
		R8,
		Other,
	};

	struct EvalStackVarInfo
	{
		EvalStackReduceDataType reduceType;
		int32_t byteSize;
		int32_t locOffset;
	};

#if HYBRIDCLR_ARCH_64
#define NATIVE_INT_OP opI8
	constexpr EvalStackReduceDataType NATIVE_INT_REDUCE_TYPE = EvalStackReduceDataType::I8;
#else
#define NATIVE_INT_OP opI4
	constexpr EvalStackReduceDataType NATIVE_INT_REDUCE_TYPE = EvalStackReduceDataType::I4;
#endif

#define CreateIR(varName, typeName) IR##typeName* varName = pool.AllocIR<IR##typeName>(); varName->type = HiOpcodeEnum::typeName;
#define CreateAddIR(varName, typeName) IR##typeName* varName = pool.AllocIR<IR##typeName>(); varName->type = HiOpcodeEnum::typeName; curbb->insts.push_back(varName);

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

#if HYBRIDCLR_ARCH_64
#define NATIVE_INT_DESC_TYPE LocationDescType::I8
#else
#define NATIVE_INT_DESC_TYPE LocationDescType::I4
#endif

	struct LocationDescInfo
	{
		LocationDescType type;
		int32_t size;
	};



	struct FlowInfo
	{
		uint32_t curStackSize;
		uint32_t offset;
		std::vector<EvalStackVarInfo> evalStack;
	};

	const int32_t MAX_STACK_SIZE = (2 << 16) - 1;
	const int32_t MAX_VALUE_TYPE_SIZE = (2 << 16) - 1;

	EvalStackReduceDataType GetEvalStackReduceDataType(const Il2CppType* type);
	int32_t GetSizeByReduceType(EvalStackReduceDataType type);

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

	IRCommon* CreateLoadExpandDataToStackVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, const Il2CppType* type, int32_t size);
	IRCommon* CreateAssignVarVar(TemporaryMemoryArena& pool, int32_t dstOffset, int32_t srcOffset, int32_t size);
	LocationDescInfo ComputValueTypeDescInfo(int32_t size);

	LocationDescInfo ComputLocationDescInfo(const Il2CppType* type);
	interpreter::IRCommon* CreateClassLdfld(TemporaryMemoryArena& pool, int32_t dstIdx, int32_t objIdx, const FieldInfo* fieldInfo);

	interpreter::IRCommon* CreateValueTypeLdfld(TemporaryMemoryArena& pool, int32_t dstIdx, int32_t objIdx, const FieldInfo* fieldInfo);
	interpreter::IRCommon* CreateStfld(TemporaryMemoryArena& pool, int32_t objIdx, const FieldInfo* fieldInfo, int32_t dataIdx);

	interpreter::IRCommon* CreateLdsfld(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent);
	interpreter::IRCommon* CreateStsfld(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx);
	interpreter::IRCommon* CreateLdthreadlocal(TemporaryMemoryArena& pool, int32_t dstIdx, const FieldInfo* fieldInfo, uint32_t parent);
	interpreter::IRCommon* CreateStthreadlocal(TemporaryMemoryArena& pool, const FieldInfo* fieldInfo, uint32_t parent, int32_t dataIdx);

	HiOpcodeEnum CalcGetMdArrElementVarVarOpcode(const Il2CppType* type);

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

		static void InitializeInstinctHandlers();

		uint32_t GetOrAddResolveDataIndex(const void* ptr)
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
			IL2CPP_ASSERT(ir->type != HiOpcodeEnum::None);
			curbb->insts.push_back(ir);
		}

		void AddInst_ldarg(int32_t argIdx)
		{
			ArgVarInfo& __arg = args[argIdx];
			IRCommon* ir = CreateLoadExpandDataToStackVarVar(pool, GetEvalStackNewTopOffset(), __arg.argLocOffset, __arg.type, GetTypeValueSize(__arg.type));
			AddInst(ir);
			PushStackByType(__arg.type);
		}

		bool IsCreateNotNullObjectInstrument(IRCommon* ir)
		{
			switch (ir->type)
			{
				case HiOpcodeEnum::BoxVarVar:
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
				case HiOpcodeEnum::NewArrVarVar_4:
				case HiOpcodeEnum::NewArrVarVar_8:
				case HiOpcodeEnum::LdsfldaFromFieldDataVarVar:
				case HiOpcodeEnum::LdsfldaVarVar:
				case HiOpcodeEnum::LdthreadlocalaVarVar:
				case HiOpcodeEnum::LdlocVarAddress:
					return true;
				default:
					return false;
			}
		}

		IRCommon* GetLastInstrument()
		{
			return curbb->insts.empty() ? nullptr : curbb->insts.back();
		}

		void RemoveLastInstrument()
		{
			IL2CPP_ASSERT(!curbb->insts.empty());
			curbb->insts.pop_back();
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
					RaiseExecutionEngineException("conv");
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
					RaiseExecutionEngineException("conv_ovf");
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
				RaiseExecutionEngineException("ldelem");
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
				RaiseExecutionEngineException("stelem");
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
				if (ec.handlerOffsets <= leaveOffset && leaveOffset < ec.handlerOffsets + ec.handlerLength)
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
				if (ec.flags == CorILExceptionClauseType::Finally || ec.flags == CorILExceptionClauseType::Exception || ec.flags == CorILExceptionClauseType::Filter)
				{
					if (ec.tryOffset <= throwOffset && throwOffset < ec.tryOffset + ec.tryLength)
						return index;
				}
				++index;
			}
			return index;
		}

		bool TryAddInstinctInstruments(const MethodInfo* method)
		{
			return TryAddInstinctInstrumentsByName(method) || TryAddArrayInstinctInstruments(method);
		}

		bool TryAddInstinctInstrumentsByName(const MethodInfo* method);
		bool TryAddArrayInstinctInstruments(const MethodInfo* method);

		bool TryAddInstinctCtorInstruments(const MethodInfo* method);

		bool TryAddCallCommonInstruments(const MethodInfo* method, uint32_t methodDataIndex)
		{
			bool resolvedIsInstanceMethod = IsInstanceMethod(method);
			bool add = resolvedIsInstanceMethod ? TryAddCallCommonInstanceInstruments(method, methodDataIndex)
				: TryAddCallCommonStaticInstruments(method, methodDataIndex);
			if (add)
			{
				int32_t resolvedTotalArgNum = method->parameters_count + resolvedIsInstanceMethod;
				PopStackN(resolvedTotalArgNum);
				if (method->return_type->type != IL2CPP_TYPE_VOID)
				{
					PushStackByType(method->return_type);
				}
				return true;
			}
			return false;
		}

		bool TryAddCallCommonInstanceInstruments(const MethodInfo* method, uint32_t methodDataIndex);
		bool TryAddCallCommonStaticInstruments(const MethodInfo* method, uint32_t methodDataIndex);
	};
}
}