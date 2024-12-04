#pragma once

#include <unordered_set>
#include <set>

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
#define CreateAddIR(varName, typeName) IR##typeName* varName = pool.AllocIR<IR##typeName>(); varName->type = HiOpcodeEnum::typeName; curbb->insts.push_back(varName); if (ir2offsetMap) { ir2offsetMap->add(varName, ipOffset); }

	enum class LocationDescType
	{
		I1,
		U1,
		I2,
		U2,
		I4,
		I8,
		Ref,
		S,
		StructContainsRef,
	};

#if HYBRIDCLR_ARCH_64
#define NATIVE_INT_DESC_TYPE LocationDescType::I8
#define ARCH_ARGUMENT(x32, x64) x64
#else
#define NATIVE_INT_DESC_TYPE LocationDescType::I4
#define ARCH_ARGUMENT(x32, x64) x32
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
		il2cpp::utils::dynamic_array<EvalStackVarInfo> evalStack;
	};

	typedef Il2CppHashMap<IRCommon*, uint32_t, il2cpp::utils::PointerHash<IRCommon>> IR2OffsetMap;

	LocationDescInfo ComputLocationDescInfo(const Il2CppType* type);

	class TransformContext
	{
	private:
		metadata::Image* image;
		const MethodInfo* methodInfo;
		metadata::MethodBody& body;


		TemporaryMemoryArena& pool;

		int32_t actualParamCount;

		std::set<uint32_t> splitOffsets;
		IRBasicBlock** ip2bb;
		IRBasicBlock* curbb;

		ArgVarInfo* args;
		LocVarInfo* locals;
		EvalStackVarInfo* evalStack;
		int32_t evalStackTop;
		int32_t evalStackBaseOffset;
		int32_t maxStackSize;
		int32_t curStackSize;

		il2cpp::utils::dynamic_array<uint64_t>& resolveDatas;
		Il2CppHashMap<uint32_t, uint32_t, il2cpp::utils::PassThroughHash<uint32_t>> token2DataIdxs;
		Il2CppHashMap<const void*, uint32_t, il2cpp::utils::PassThroughHash<const void*>> ptr2DataIdxs;
		std::vector<int32_t*> relocationOffsets;
		std::vector<std::pair<int32_t, int32_t>> switchOffsetsInResolveData;
		std::vector<FlowInfo*> pendingFlows;
		int32_t nextFlowIdx;

		const byte* ipBase;
		const byte* ip;
		uint32_t ipOffset;
		IR2OffsetMap* ir2offsetMap;

		int32_t prefixFlags;

		const MethodInfo* shareMethod;

		std::vector<IRBasicBlock*> irbbs;
		il2cpp::utils::dynamic_array<InterpExceptionClause> exClauses;

		uint32_t totalIRSize;
		int32_t totalArgSize;
		int32_t totalArgLocalSize;
		bool initLocals;

	public:

		TransformContext(hybridclr::metadata::Image* image, const MethodInfo* methodInfo, metadata::MethodBody& body, TemporaryMemoryArena& pool, il2cpp::utils::dynamic_array<uint64_t>& resolveDatas);
		~TransformContext();

		static void InitializeInstinctHandlers();

		uint32_t GetOrAddResolveDataIndex(const void* ptr);

		TemporaryMemoryArena& GetPool() const
		{
			return pool;
		}

		int32_t GetEvalStackTop() const
		{
			return evalStackTop;
		}

		IRBasicBlock* GetCurbb() const
		{
			return curbb;
		}

		uint32_t GetIpOffset() const
		{
			return ipOffset;
		}

		IR2OffsetMap* GetIr2offsetMap() const
		{
			return ir2offsetMap;
		}

		int32_t GetArgOffset(int32_t idx) const
		{
			return args[idx].argOffset;
		}

		int32_t GetArgLocOffset(int32_t idx) const
		{
			return args[idx].argLocOffset;
		}

		int32_t GetLocOffset(int32_t idx) const
		{
			return locals[idx].locOffset;
		}

		int32_t GetEvalStackOffset(int32_t idx) const
		{
			return idx < evalStackTop ? evalStack[idx].locOffset : curStackSize;
		}

		int32_t GetEvalStackTopOffset() const
		{
			return evalStackTop > 0 ? evalStack[evalStackTop - 1].locOffset : curStackSize;
		}

		int32_t GetEvalStackNewTopOffset() const
		{
			return curStackSize;
		}

		int32_t GetEvalStackOffset_5() const
		{
			return evalStack[evalStackTop - 5].locOffset;
		}

		int32_t GetEvalStackOffset_4() const
		{
			return evalStack[evalStackTop - 4].locOffset;
		}

		int32_t GetEvalStackOffset_3() const
		{
			return evalStack[evalStackTop - 3].locOffset;
		}

		int32_t GetEvalStackOffset_2() const
		{
			return evalStack[evalStackTop - 2].locOffset;
		}

		int32_t GetEvalStackOffset_1() const
		{
			return evalStack[evalStackTop - 1].locOffset;
		}

		void PushStackByType(const Il2CppType* type);

		void PushStackByReduceType(EvalStackReduceDataType t);

		void DuplicateStack();

		void PopStack();

		void PopStackN(int32_t n);

		void PopAllStack();

		void InsertMemoryBarrier();

		void ResetPrefixFlags();

		void Add_ldind(HiOpcodeEnum opCode, EvalStackReduceDataType dataType);

		void Add_stind(HiOpcodeEnum opCode);

		void PushOffset(int32_t* offsetPtr);

		void PushBranch(int32_t targetOffset);

		bool FindNextFlow();

		void AddInst(IRCommon* ir);

		void AddInst_ldarg(int32_t argIdx);

		bool IsCreateNotNullObjectInstrument(IRCommon* ir);

		IRCommon* GetLastInstrument()
		{
			return curbb->insts.empty() ? nullptr : curbb->insts.back();
		}

		void RemoveLastInstrument();

		void AddInst_ldarga(int32_t argIdx);

		void AddInst_starg(int32_t argIdx);

		void CreateAddInst_ldloc(int32_t locIdx);

		void CreateAddInst_stloc(int32_t locIdx);

		void CreateAddInst_ldloca(int32_t locIdx);

		void CreateAddInst_ldc4(int32_t c, EvalStackReduceDataType rtype);

		void CreateAddInst_ldc8(int64_t c, EvalStackReduceDataType rtype);

		void Add_brtruefalse(bool c, int32_t targetOffset);

		void Add_bc(int32_t ipOffset, int32_t brOffset, int32_t opSize, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8);

		void Add_conv(int32_t dstTypeSize, EvalStackReduceDataType dstReduceType, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8);

		void Add_conv_ovf(int32_t dstTypeSize, EvalStackReduceDataType dstReduceType, HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8);

		void Add_binop(HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8);

		void Add_shiftop(HiOpcodeEnum opI4I4, HiOpcodeEnum opI4I8, HiOpcodeEnum opI8I4, HiOpcodeEnum opI8I8);

		void Add_compare(HiOpcodeEnum opI4, HiOpcodeEnum opI8, HiOpcodeEnum opR4, HiOpcodeEnum opR8);

		void Add_ldelem(EvalStackReduceDataType resultType, HiOpcodeEnum opI4);
		void Add_stelem(HiOpcodeEnum opI4);

		bool FindFirstLeaveHandlerIndex(const std::vector<ExceptionClause>& exceptionClauses, uint32_t leaveOffset, uint32_t targetOffset, uint16_t& index);

		bool IsLeaveInTryBlock(const std::vector<ExceptionClause>& exceptionClauses, uint32_t leaveOffset);

		void Add_leave(uint32_t targetOffset);

		uint16_t FindFirstThrowHandlerIndex(const std::vector<ExceptionClause>& exceptionClauses, uint32_t throwOffset);

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


		HiOpcodeEnum CalcGetMdArrElementVarVarOpcode(const Il2CppType* type);

		void TransformBody(int32_t depth, int32_t localVarOffset, interpreter::InterpMethodInfo& result);

	private:
		void TransformBodyImpl(int32_t depth, int32_t localVarOffset);
		void BuildInterpMethodInfo(interpreter::InterpMethodInfo& result);
		static bool TransformSubMethodBody(TransformContext& callingCtx, const MethodInfo* subMethod, int32_t depth, int32_t localVarOffset);
	};
}
}