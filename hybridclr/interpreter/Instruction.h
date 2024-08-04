#pragma once

#include "../CommonDef.h"

namespace hybridclr
{
namespace interpreter
{

	enum class PrefixFlags
	{
		None = 0,
		Constrained = 0x1,
		No = 0x2,
		ReadOnly = 0x4,
		Tail = 0x8,
		Unaligned = 0x10,
		Volatile = 0x20,
	};

	extern uint16_t g_instructionSizes[];

	enum class HiOpcodeEnum : uint16_t
	{
		None,
		//!!!{{OPCODE
		InitLocals_n_2,
		InitLocals_n_4,
		LdlocVarVar,
		LdlocExpandVarVar_i1,
		LdlocExpandVarVar_u1,
		LdlocExpandVarVar_i2,
		LdlocExpandVarVar_u2,
		LdlocVarVarSize,
		LdlocVarAddress,
		LdcVarConst_1,
		LdcVarConst_2,
		LdcVarConst_4,
		LdcVarConst_8,
		LdnullVar,
		LdindVarVar_i1,
		LdindVarVar_u1,
		LdindVarVar_i2,
		LdindVarVar_u2,
		LdindVarVar_i4,
		LdindVarVar_u4,
		LdindVarVar_i8,
		LdindVarVar_f4,
		LdindVarVar_f8,
		StindVarVar_i1,
		StindVarVar_i2,
		StindVarVar_i4,
		StindVarVar_i8,
		StindVarVar_f4,
		StindVarVar_f8,
		StindVarVar_ref,
		LocalAllocVarVar_n_2,
		LocalAllocVarVar_n_4,
		InitblkVarVarVar,
		CpblkVarVar,
		MemoryBarrier,
		ConvertVarVar_i4_i1,
		ConvertVarVar_i4_u1,
		ConvertVarVar_i4_i2,
		ConvertVarVar_i4_u2,
		ConvertVarVar_i4_i4,
		ConvertVarVar_i4_u4,
		ConvertVarVar_i4_i8,
		ConvertVarVar_i4_u8,
		ConvertVarVar_i4_f4,
		ConvertVarVar_i4_f8,
		ConvertVarVar_u4_i1,
		ConvertVarVar_u4_u1,
		ConvertVarVar_u4_i2,
		ConvertVarVar_u4_u2,
		ConvertVarVar_u4_i4,
		ConvertVarVar_u4_u4,
		ConvertVarVar_u4_i8,
		ConvertVarVar_u4_u8,
		ConvertVarVar_u4_f4,
		ConvertVarVar_u4_f8,
		ConvertVarVar_i8_i1,
		ConvertVarVar_i8_u1,
		ConvertVarVar_i8_i2,
		ConvertVarVar_i8_u2,
		ConvertVarVar_i8_i4,
		ConvertVarVar_i8_u4,
		ConvertVarVar_i8_i8,
		ConvertVarVar_i8_u8,
		ConvertVarVar_i8_f4,
		ConvertVarVar_i8_f8,
		ConvertVarVar_u8_i1,
		ConvertVarVar_u8_u1,
		ConvertVarVar_u8_i2,
		ConvertVarVar_u8_u2,
		ConvertVarVar_u8_i4,
		ConvertVarVar_u8_u4,
		ConvertVarVar_u8_i8,
		ConvertVarVar_u8_u8,
		ConvertVarVar_u8_f4,
		ConvertVarVar_u8_f8,
		ConvertVarVar_f4_i1,
		ConvertVarVar_f4_u1,
		ConvertVarVar_f4_i2,
		ConvertVarVar_f4_u2,
		ConvertVarVar_f4_i4,
		ConvertVarVar_f4_u4,
		ConvertVarVar_f4_i8,
		ConvertVarVar_f4_u8,
		ConvertVarVar_f4_f4,
		ConvertVarVar_f4_f8,
		ConvertVarVar_f8_i1,
		ConvertVarVar_f8_u1,
		ConvertVarVar_f8_i2,
		ConvertVarVar_f8_u2,
		ConvertVarVar_f8_i4,
		ConvertVarVar_f8_u4,
		ConvertVarVar_f8_i8,
		ConvertVarVar_f8_u8,
		ConvertVarVar_f8_f4,
		ConvertVarVar_f8_f8,
		ConvertOverflowVarVar_i4_i1,
		ConvertOverflowVarVar_i4_u1,
		ConvertOverflowVarVar_i4_i2,
		ConvertOverflowVarVar_i4_u2,
		ConvertOverflowVarVar_i4_i4,
		ConvertOverflowVarVar_i4_u4,
		ConvertOverflowVarVar_i4_i8,
		ConvertOverflowVarVar_i4_u8,
		ConvertOverflowVarVar_u4_i1,
		ConvertOverflowVarVar_u4_u1,
		ConvertOverflowVarVar_u4_i2,
		ConvertOverflowVarVar_u4_u2,
		ConvertOverflowVarVar_u4_i4,
		ConvertOverflowVarVar_u4_u4,
		ConvertOverflowVarVar_u4_i8,
		ConvertOverflowVarVar_u4_u8,
		ConvertOverflowVarVar_i8_i1,
		ConvertOverflowVarVar_i8_u1,
		ConvertOverflowVarVar_i8_i2,
		ConvertOverflowVarVar_i8_u2,
		ConvertOverflowVarVar_i8_i4,
		ConvertOverflowVarVar_i8_u4,
		ConvertOverflowVarVar_i8_i8,
		ConvertOverflowVarVar_i8_u8,
		ConvertOverflowVarVar_u8_i1,
		ConvertOverflowVarVar_u8_u1,
		ConvertOverflowVarVar_u8_i2,
		ConvertOverflowVarVar_u8_u2,
		ConvertOverflowVarVar_u8_i4,
		ConvertOverflowVarVar_u8_u4,
		ConvertOverflowVarVar_u8_i8,
		ConvertOverflowVarVar_u8_u8,
		ConvertOverflowVarVar_f4_i1,
		ConvertOverflowVarVar_f4_u1,
		ConvertOverflowVarVar_f4_i2,
		ConvertOverflowVarVar_f4_u2,
		ConvertOverflowVarVar_f4_i4,
		ConvertOverflowVarVar_f4_u4,
		ConvertOverflowVarVar_f4_i8,
		ConvertOverflowVarVar_f4_u8,
		ConvertOverflowVarVar_f8_i1,
		ConvertOverflowVarVar_f8_u1,
		ConvertOverflowVarVar_f8_i2,
		ConvertOverflowVarVar_f8_u2,
		ConvertOverflowVarVar_f8_i4,
		ConvertOverflowVarVar_f8_u4,
		ConvertOverflowVarVar_f8_i8,
		ConvertOverflowVarVar_f8_u8,
		BinOpVarVarVar_Add_i4,
		BinOpVarVarVar_Sub_i4,
		BinOpVarVarVar_Mul_i4,
		BinOpVarVarVar_MulUn_i4,
		BinOpVarVarVar_Div_i4,
		BinOpVarVarVar_DivUn_i4,
		BinOpVarVarVar_Rem_i4,
		BinOpVarVarVar_RemUn_i4,
		BinOpVarVarVar_And_i4,
		BinOpVarVarVar_Or_i4,
		BinOpVarVarVar_Xor_i4,
		BinOpVarVarVar_Add_i8,
		BinOpVarVarVar_Sub_i8,
		BinOpVarVarVar_Mul_i8,
		BinOpVarVarVar_MulUn_i8,
		BinOpVarVarVar_Div_i8,
		BinOpVarVarVar_DivUn_i8,
		BinOpVarVarVar_Rem_i8,
		BinOpVarVarVar_RemUn_i8,
		BinOpVarVarVar_And_i8,
		BinOpVarVarVar_Or_i8,
		BinOpVarVarVar_Xor_i8,
		BinOpVarVarVar_Add_f4,
		BinOpVarVarVar_Sub_f4,
		BinOpVarVarVar_Mul_f4,
		BinOpVarVarVar_Div_f4,
		BinOpVarVarVar_Rem_f4,
		BinOpVarVarVar_Add_f8,
		BinOpVarVarVar_Sub_f8,
		BinOpVarVarVar_Mul_f8,
		BinOpVarVarVar_Div_f8,
		BinOpVarVarVar_Rem_f8,
		BinOpOverflowVarVarVar_Add_i4,
		BinOpOverflowVarVarVar_Sub_i4,
		BinOpOverflowVarVarVar_Mul_i4,
		BinOpOverflowVarVarVar_Add_i8,
		BinOpOverflowVarVarVar_Sub_i8,
		BinOpOverflowVarVarVar_Mul_i8,
		BinOpOverflowVarVarVar_Add_u4,
		BinOpOverflowVarVarVar_Sub_u4,
		BinOpOverflowVarVarVar_Mul_u4,
		BinOpOverflowVarVarVar_Add_u8,
		BinOpOverflowVarVarVar_Sub_u8,
		BinOpOverflowVarVarVar_Mul_u8,
		BitShiftBinOpVarVarVar_Shl_i4_i4,
		BitShiftBinOpVarVarVar_Shr_i4_i4,
		BitShiftBinOpVarVarVar_ShrUn_i4_i4,
		BitShiftBinOpVarVarVar_Shl_i4_i8,
		BitShiftBinOpVarVarVar_Shr_i4_i8,
		BitShiftBinOpVarVarVar_ShrUn_i4_i8,
		BitShiftBinOpVarVarVar_Shl_i8_i4,
		BitShiftBinOpVarVarVar_Shr_i8_i4,
		BitShiftBinOpVarVarVar_ShrUn_i8_i4,
		BitShiftBinOpVarVarVar_Shl_i8_i8,
		BitShiftBinOpVarVarVar_Shr_i8_i8,
		BitShiftBinOpVarVarVar_ShrUn_i8_i8,
		UnaryOpVarVar_Neg_i4,
		UnaryOpVarVar_Not_i4,
		UnaryOpVarVar_Neg_i8,
		UnaryOpVarVar_Not_i8,
		UnaryOpVarVar_Neg_f4,
		UnaryOpVarVar_Neg_f8,
		CheckFiniteVar_f4,
		CheckFiniteVar_f8,
		CompOpVarVarVar_Ceq_i4,
		CompOpVarVarVar_Ceq_i8,
		CompOpVarVarVar_Ceq_f4,
		CompOpVarVarVar_Ceq_f8,
		CompOpVarVarVar_Cgt_i4,
		CompOpVarVarVar_Cgt_i8,
		CompOpVarVarVar_Cgt_f4,
		CompOpVarVarVar_Cgt_f8,
		CompOpVarVarVar_CgtUn_i4,
		CompOpVarVarVar_CgtUn_i8,
		CompOpVarVarVar_CgtUn_f4,
		CompOpVarVarVar_CgtUn_f8,
		CompOpVarVarVar_Clt_i4,
		CompOpVarVarVar_Clt_i8,
		CompOpVarVarVar_Clt_f4,
		CompOpVarVarVar_Clt_f8,
		CompOpVarVarVar_CltUn_i4,
		CompOpVarVarVar_CltUn_i8,
		CompOpVarVarVar_CltUn_f4,
		CompOpVarVarVar_CltUn_f8,
		BranchUncondition_4,
		BranchTrueVar_i4,
		BranchTrueVar_i8,
		BranchFalseVar_i4,
		BranchFalseVar_i8,
		BranchVarVar_Ceq_i4,
		BranchVarVar_Ceq_i8,
		BranchVarVar_Ceq_f4,
		BranchVarVar_Ceq_f8,
		BranchVarVar_CneUn_i4,
		BranchVarVar_CneUn_i8,
		BranchVarVar_CneUn_f4,
		BranchVarVar_CneUn_f8,
		BranchVarVar_Cgt_i4,
		BranchVarVar_Cgt_i8,
		BranchVarVar_Cgt_f4,
		BranchVarVar_Cgt_f8,
		BranchVarVar_CgtUn_i4,
		BranchVarVar_CgtUn_i8,
		BranchVarVar_CgtUn_f4,
		BranchVarVar_CgtUn_f8,
		BranchVarVar_Cge_i4,
		BranchVarVar_Cge_i8,
		BranchVarVar_Cge_f4,
		BranchVarVar_Cge_f8,
		BranchVarVar_CgeUn_i4,
		BranchVarVar_CgeUn_i8,
		BranchVarVar_CgeUn_f4,
		BranchVarVar_CgeUn_f8,
		BranchVarVar_Clt_i4,
		BranchVarVar_Clt_i8,
		BranchVarVar_Clt_f4,
		BranchVarVar_Clt_f8,
		BranchVarVar_CltUn_i4,
		BranchVarVar_CltUn_i8,
		BranchVarVar_CltUn_f4,
		BranchVarVar_CltUn_f8,
		BranchVarVar_Cle_i4,
		BranchVarVar_Cle_i8,
		BranchVarVar_Cle_f4,
		BranchVarVar_Cle_f8,
		BranchVarVar_CleUn_i4,
		BranchVarVar_CleUn_i8,
		BranchVarVar_CleUn_f4,
		BranchVarVar_CleUn_f8,
		BranchJump,
		BranchSwitch,
		NewClassVar,
		NewClassVar_Ctor_0,
		NewClassVar_NotCtor,
		NewValueTypeVar,
		NewClassInterpVar,
		NewClassInterpVar_Ctor_0,
		NewValueTypeInterpVar,
		AdjustValueTypeRefVar,
		BoxRefVarVar,
		LdvirftnVarVar,
		RetVar_ret_1,
		RetVar_ret_2,
		RetVar_ret_4,
		RetVar_ret_8,
		RetVar_ret_12,
		RetVar_ret_16,
		RetVar_ret_20,
		RetVar_ret_24,
		RetVar_ret_28,
		RetVar_ret_32,
		RetVar_ret_n,
		RetVar_void,
		CallNativeInstance_void,
		CallNativeInstance_ret,
		CallNativeInstance_ret_expand,
		CallNativeStatic_void,
		CallNativeStatic_ret,
		CallNativeStatic_ret_expand,
		CallInterp_void,
		CallInterp_ret,
		CallVirtual_void,
		CallVirtual_ret,
		CallVirtual_ret_expand,
		CallInterpVirtual_void,
		CallInterpVirtual_ret,
		CallInd_void,
		CallInd_ret,
		CallInd_ret_expand,
		CallDelegateInvoke_void,
		CallDelegateInvoke_ret,
		CallDelegateInvoke_ret_expand,
		CallDelegateBeginInvoke,
		CallDelegateEndInvoke_void,
		CallDelegateEndInvoke_ret,
		NewDelegate,
		CtorDelegate,
		CallCommonNativeInstance_v_0,
		CallCommonNativeInstance_i1_0,
		CallCommonNativeInstance_u1_0,
		CallCommonNativeInstance_i2_0,
		CallCommonNativeInstance_u2_0,
		CallCommonNativeInstance_i4_0,
		CallCommonNativeInstance_i8_0,
		CallCommonNativeInstance_f4_0,
		CallCommonNativeInstance_f8_0,
		CallCommonNativeInstance_v_i4_1,
		CallCommonNativeInstance_v_i4_2,
		CallCommonNativeInstance_v_i4_3,
		CallCommonNativeInstance_v_i4_4,
		CallCommonNativeInstance_v_i8_1,
		CallCommonNativeInstance_v_i8_2,
		CallCommonNativeInstance_v_i8_3,
		CallCommonNativeInstance_v_i8_4,
		CallCommonNativeInstance_v_f4_1,
		CallCommonNativeInstance_v_f4_2,
		CallCommonNativeInstance_v_f4_3,
		CallCommonNativeInstance_v_f4_4,
		CallCommonNativeInstance_v_f8_1,
		CallCommonNativeInstance_v_f8_2,
		CallCommonNativeInstance_v_f8_3,
		CallCommonNativeInstance_v_f8_4,
		CallCommonNativeInstance_u1_i4_1,
		CallCommonNativeInstance_u1_i4_2,
		CallCommonNativeInstance_u1_i4_3,
		CallCommonNativeInstance_u1_i4_4,
		CallCommonNativeInstance_u1_i8_1,
		CallCommonNativeInstance_u1_i8_2,
		CallCommonNativeInstance_u1_i8_3,
		CallCommonNativeInstance_u1_i8_4,
		CallCommonNativeInstance_u1_f4_1,
		CallCommonNativeInstance_u1_f4_2,
		CallCommonNativeInstance_u1_f4_3,
		CallCommonNativeInstance_u1_f4_4,
		CallCommonNativeInstance_u1_f8_1,
		CallCommonNativeInstance_u1_f8_2,
		CallCommonNativeInstance_u1_f8_3,
		CallCommonNativeInstance_u1_f8_4,
		CallCommonNativeInstance_i4_i4_1,
		CallCommonNativeInstance_i4_i4_2,
		CallCommonNativeInstance_i4_i4_3,
		CallCommonNativeInstance_i4_i4_4,
		CallCommonNativeInstance_i4_i8_1,
		CallCommonNativeInstance_i4_i8_2,
		CallCommonNativeInstance_i4_i8_3,
		CallCommonNativeInstance_i4_i8_4,
		CallCommonNativeInstance_i4_f4_1,
		CallCommonNativeInstance_i4_f4_2,
		CallCommonNativeInstance_i4_f4_3,
		CallCommonNativeInstance_i4_f4_4,
		CallCommonNativeInstance_i4_f8_1,
		CallCommonNativeInstance_i4_f8_2,
		CallCommonNativeInstance_i4_f8_3,
		CallCommonNativeInstance_i4_f8_4,
		CallCommonNativeInstance_i8_i4_1,
		CallCommonNativeInstance_i8_i4_2,
		CallCommonNativeInstance_i8_i4_3,
		CallCommonNativeInstance_i8_i4_4,
		CallCommonNativeInstance_i8_i8_1,
		CallCommonNativeInstance_i8_i8_2,
		CallCommonNativeInstance_i8_i8_3,
		CallCommonNativeInstance_i8_i8_4,
		CallCommonNativeInstance_i8_f4_1,
		CallCommonNativeInstance_i8_f4_2,
		CallCommonNativeInstance_i8_f4_3,
		CallCommonNativeInstance_i8_f4_4,
		CallCommonNativeInstance_i8_f8_1,
		CallCommonNativeInstance_i8_f8_2,
		CallCommonNativeInstance_i8_f8_3,
		CallCommonNativeInstance_i8_f8_4,
		CallCommonNativeInstance_f4_i4_1,
		CallCommonNativeInstance_f4_i4_2,
		CallCommonNativeInstance_f4_i4_3,
		CallCommonNativeInstance_f4_i4_4,
		CallCommonNativeInstance_f4_i8_1,
		CallCommonNativeInstance_f4_i8_2,
		CallCommonNativeInstance_f4_i8_3,
		CallCommonNativeInstance_f4_i8_4,
		CallCommonNativeInstance_f4_f4_1,
		CallCommonNativeInstance_f4_f4_2,
		CallCommonNativeInstance_f4_f4_3,
		CallCommonNativeInstance_f4_f4_4,
		CallCommonNativeInstance_f4_f8_1,
		CallCommonNativeInstance_f4_f8_2,
		CallCommonNativeInstance_f4_f8_3,
		CallCommonNativeInstance_f4_f8_4,
		CallCommonNativeInstance_f8_i4_1,
		CallCommonNativeInstance_f8_i4_2,
		CallCommonNativeInstance_f8_i4_3,
		CallCommonNativeInstance_f8_i4_4,
		CallCommonNativeInstance_f8_i8_1,
		CallCommonNativeInstance_f8_i8_2,
		CallCommonNativeInstance_f8_i8_3,
		CallCommonNativeInstance_f8_i8_4,
		CallCommonNativeInstance_f8_f4_1,
		CallCommonNativeInstance_f8_f4_2,
		CallCommonNativeInstance_f8_f4_3,
		CallCommonNativeInstance_f8_f4_4,
		CallCommonNativeInstance_f8_f8_1,
		CallCommonNativeInstance_f8_f8_2,
		CallCommonNativeInstance_f8_f8_3,
		CallCommonNativeInstance_f8_f8_4,
		CallCommonNativeStatic_v_0,
		CallCommonNativeStatic_i1_0,
		CallCommonNativeStatic_u1_0,
		CallCommonNativeStatic_i2_0,
		CallCommonNativeStatic_u2_0,
		CallCommonNativeStatic_i4_0,
		CallCommonNativeStatic_i8_0,
		CallCommonNativeStatic_f4_0,
		CallCommonNativeStatic_f8_0,
		CallCommonNativeStatic_v_i4_1,
		CallCommonNativeStatic_v_i4_2,
		CallCommonNativeStatic_v_i4_3,
		CallCommonNativeStatic_v_i4_4,
		CallCommonNativeStatic_v_i8_1,
		CallCommonNativeStatic_v_i8_2,
		CallCommonNativeStatic_v_i8_3,
		CallCommonNativeStatic_v_i8_4,
		CallCommonNativeStatic_v_f4_1,
		CallCommonNativeStatic_v_f4_2,
		CallCommonNativeStatic_v_f4_3,
		CallCommonNativeStatic_v_f4_4,
		CallCommonNativeStatic_v_f8_1,
		CallCommonNativeStatic_v_f8_2,
		CallCommonNativeStatic_v_f8_3,
		CallCommonNativeStatic_v_f8_4,
		CallCommonNativeStatic_u1_i4_1,
		CallCommonNativeStatic_u1_i4_2,
		CallCommonNativeStatic_u1_i4_3,
		CallCommonNativeStatic_u1_i4_4,
		CallCommonNativeStatic_u1_i8_1,
		CallCommonNativeStatic_u1_i8_2,
		CallCommonNativeStatic_u1_i8_3,
		CallCommonNativeStatic_u1_i8_4,
		CallCommonNativeStatic_u1_f4_1,
		CallCommonNativeStatic_u1_f4_2,
		CallCommonNativeStatic_u1_f4_3,
		CallCommonNativeStatic_u1_f4_4,
		CallCommonNativeStatic_u1_f8_1,
		CallCommonNativeStatic_u1_f8_2,
		CallCommonNativeStatic_u1_f8_3,
		CallCommonNativeStatic_u1_f8_4,
		CallCommonNativeStatic_i4_i4_1,
		CallCommonNativeStatic_i4_i4_2,
		CallCommonNativeStatic_i4_i4_3,
		CallCommonNativeStatic_i4_i4_4,
		CallCommonNativeStatic_i4_i8_1,
		CallCommonNativeStatic_i4_i8_2,
		CallCommonNativeStatic_i4_i8_3,
		CallCommonNativeStatic_i4_i8_4,
		CallCommonNativeStatic_i4_f4_1,
		CallCommonNativeStatic_i4_f4_2,
		CallCommonNativeStatic_i4_f4_3,
		CallCommonNativeStatic_i4_f4_4,
		CallCommonNativeStatic_i4_f8_1,
		CallCommonNativeStatic_i4_f8_2,
		CallCommonNativeStatic_i4_f8_3,
		CallCommonNativeStatic_i4_f8_4,
		CallCommonNativeStatic_i8_i4_1,
		CallCommonNativeStatic_i8_i4_2,
		CallCommonNativeStatic_i8_i4_3,
		CallCommonNativeStatic_i8_i4_4,
		CallCommonNativeStatic_i8_i8_1,
		CallCommonNativeStatic_i8_i8_2,
		CallCommonNativeStatic_i8_i8_3,
		CallCommonNativeStatic_i8_i8_4,
		CallCommonNativeStatic_i8_f4_1,
		CallCommonNativeStatic_i8_f4_2,
		CallCommonNativeStatic_i8_f4_3,
		CallCommonNativeStatic_i8_f4_4,
		CallCommonNativeStatic_i8_f8_1,
		CallCommonNativeStatic_i8_f8_2,
		CallCommonNativeStatic_i8_f8_3,
		CallCommonNativeStatic_i8_f8_4,
		CallCommonNativeStatic_f4_i4_1,
		CallCommonNativeStatic_f4_i4_2,
		CallCommonNativeStatic_f4_i4_3,
		CallCommonNativeStatic_f4_i4_4,
		CallCommonNativeStatic_f4_i8_1,
		CallCommonNativeStatic_f4_i8_2,
		CallCommonNativeStatic_f4_i8_3,
		CallCommonNativeStatic_f4_i8_4,
		CallCommonNativeStatic_f4_f4_1,
		CallCommonNativeStatic_f4_f4_2,
		CallCommonNativeStatic_f4_f4_3,
		CallCommonNativeStatic_f4_f4_4,
		CallCommonNativeStatic_f4_f8_1,
		CallCommonNativeStatic_f4_f8_2,
		CallCommonNativeStatic_f4_f8_3,
		CallCommonNativeStatic_f4_f8_4,
		CallCommonNativeStatic_f8_i4_1,
		CallCommonNativeStatic_f8_i4_2,
		CallCommonNativeStatic_f8_i4_3,
		CallCommonNativeStatic_f8_i4_4,
		CallCommonNativeStatic_f8_i8_1,
		CallCommonNativeStatic_f8_i8_2,
		CallCommonNativeStatic_f8_i8_3,
		CallCommonNativeStatic_f8_i8_4,
		CallCommonNativeStatic_f8_f4_1,
		CallCommonNativeStatic_f8_f4_2,
		CallCommonNativeStatic_f8_f4_3,
		CallCommonNativeStatic_f8_f4_4,
		CallCommonNativeStatic_f8_f8_1,
		CallCommonNativeStatic_f8_f8_2,
		CallCommonNativeStatic_f8_f8_3,
		CallCommonNativeStatic_f8_f8_4,
		BoxVarVar,
		UnBoxVarVar,
		UnBoxAnyVarVar,
		CastclassVar,
		IsInstVar,
		LdtokenVar,
		MakeRefVarVar,
		RefAnyTypeVarVar,
		RefAnyValueVarVar,
		CpobjVarVar_ref,
		CpobjVarVar_1,
		CpobjVarVar_2,
		CpobjVarVar_4,
		CpobjVarVar_8,
		CpobjVarVar_12,
		CpobjVarVar_16,
		CpobjVarVar_20,
		CpobjVarVar_24,
		CpobjVarVar_28,
		CpobjVarVar_32,
		CpobjVarVar_n_2,
		CpobjVarVar_n_4,
		CpobjVarVar_WriteBarrier_n_2,
		CpobjVarVar_WriteBarrier_n_4,
		LdobjVarVar_ref,
		LdobjVarVar_1,
		LdobjVarVar_2,
		LdobjVarVar_4,
		LdobjVarVar_8,
		LdobjVarVar_12,
		LdobjVarVar_16,
		LdobjVarVar_20,
		LdobjVarVar_24,
		LdobjVarVar_28,
		LdobjVarVar_32,
		LdobjVarVar_n_4,
		StobjVarVar_ref,
		StobjVarVar_1,
		StobjVarVar_2,
		StobjVarVar_4,
		StobjVarVar_8,
		StobjVarVar_12,
		StobjVarVar_16,
		StobjVarVar_20,
		StobjVarVar_24,
		StobjVarVar_28,
		StobjVarVar_32,
		StobjVarVar_n_4,
		StobjVarVar_WriteBarrier_n_4,
		InitobjVar_ref,
		InitobjVar_1,
		InitobjVar_2,
		InitobjVar_4,
		InitobjVar_8,
		InitobjVar_12,
		InitobjVar_16,
		InitobjVar_20,
		InitobjVar_24,
		InitobjVar_28,
		InitobjVar_32,
		InitobjVar_n_2,
		InitobjVar_n_4,
		InitobjVar_WriteBarrier_n_2,
		InitobjVar_WriteBarrier_n_4,
		LdstrVar,
		LdfldVarVar_i1,
		LdfldVarVar_u1,
		LdfldVarVar_i2,
		LdfldVarVar_u2,
		LdfldVarVar_i4,
		LdfldVarVar_u4,
		LdfldVarVar_i8,
		LdfldVarVar_u8,
		LdfldVarVar_size_8,
		LdfldVarVar_size_12,
		LdfldVarVar_size_16,
		LdfldVarVar_size_20,
		LdfldVarVar_size_24,
		LdfldVarVar_size_28,
		LdfldVarVar_size_32,
		LdfldVarVar_n_2,
		LdfldVarVar_n_4,
		LdfldValueTypeVarVar_i1,
		LdfldValueTypeVarVar_u1,
		LdfldValueTypeVarVar_i2,
		LdfldValueTypeVarVar_u2,
		LdfldValueTypeVarVar_i4,
		LdfldValueTypeVarVar_u4,
		LdfldValueTypeVarVar_i8,
		LdfldValueTypeVarVar_u8,
		LdfldValueTypeVarVar_size_8,
		LdfldValueTypeVarVar_size_12,
		LdfldValueTypeVarVar_size_16,
		LdfldValueTypeVarVar_size_20,
		LdfldValueTypeVarVar_size_24,
		LdfldValueTypeVarVar_size_28,
		LdfldValueTypeVarVar_size_32,
		LdfldValueTypeVarVar_n_2,
		LdfldValueTypeVarVar_n_4,
		LdfldaVarVar,
		StfldVarVar_i1,
		StfldVarVar_u1,
		StfldVarVar_i2,
		StfldVarVar_u2,
		StfldVarVar_i4,
		StfldVarVar_u4,
		StfldVarVar_i8,
		StfldVarVar_u8,
		StfldVarVar_ref,
		StfldVarVar_size_8,
		StfldVarVar_size_12,
		StfldVarVar_size_16,
		StfldVarVar_size_20,
		StfldVarVar_size_24,
		StfldVarVar_size_28,
		StfldVarVar_size_32,
		StfldVarVar_n_2,
		StfldVarVar_n_4,
		StfldVarVar_WriteBarrier_n_2,
		StfldVarVar_WriteBarrier_n_4,
		LdsfldVarVar_i1,
		LdsfldVarVar_u1,
		LdsfldVarVar_i2,
		LdsfldVarVar_u2,
		LdsfldVarVar_i4,
		LdsfldVarVar_u4,
		LdsfldVarVar_i8,
		LdsfldVarVar_u8,
		LdsfldVarVar_size_8,
		LdsfldVarVar_size_12,
		LdsfldVarVar_size_16,
		LdsfldVarVar_size_20,
		LdsfldVarVar_size_24,
		LdsfldVarVar_size_28,
		LdsfldVarVar_size_32,
		LdsfldVarVar_n_2,
		LdsfldVarVar_n_4,
		StsfldVarVar_i1,
		StsfldVarVar_u1,
		StsfldVarVar_i2,
		StsfldVarVar_u2,
		StsfldVarVar_i4,
		StsfldVarVar_u4,
		StsfldVarVar_i8,
		StsfldVarVar_u8,
		StsfldVarVar_ref,
		StsfldVarVar_size_8,
		StsfldVarVar_size_12,
		StsfldVarVar_size_16,
		StsfldVarVar_size_20,
		StsfldVarVar_size_24,
		StsfldVarVar_size_28,
		StsfldVarVar_size_32,
		StsfldVarVar_n_2,
		StsfldVarVar_n_4,
		StsfldVarVar_WriteBarrier_n_2,
		StsfldVarVar_WriteBarrier_n_4,
		LdsfldaVarVar,
		LdsfldaFromFieldDataVarVar,
		LdthreadlocalaVarVar,
		LdthreadlocalVarVar_i1,
		LdthreadlocalVarVar_u1,
		LdthreadlocalVarVar_i2,
		LdthreadlocalVarVar_u2,
		LdthreadlocalVarVar_i4,
		LdthreadlocalVarVar_u4,
		LdthreadlocalVarVar_i8,
		LdthreadlocalVarVar_u8,
		LdthreadlocalVarVar_size_8,
		LdthreadlocalVarVar_size_12,
		LdthreadlocalVarVar_size_16,
		LdthreadlocalVarVar_size_20,
		LdthreadlocalVarVar_size_24,
		LdthreadlocalVarVar_size_28,
		LdthreadlocalVarVar_size_32,
		LdthreadlocalVarVar_n_2,
		LdthreadlocalVarVar_n_4,
		StthreadlocalVarVar_i1,
		StthreadlocalVarVar_u1,
		StthreadlocalVarVar_i2,
		StthreadlocalVarVar_u2,
		StthreadlocalVarVar_i4,
		StthreadlocalVarVar_u4,
		StthreadlocalVarVar_i8,
		StthreadlocalVarVar_u8,
		StthreadlocalVarVar_ref,
		StthreadlocalVarVar_size_8,
		StthreadlocalVarVar_size_12,
		StthreadlocalVarVar_size_16,
		StthreadlocalVarVar_size_20,
		StthreadlocalVarVar_size_24,
		StthreadlocalVarVar_size_28,
		StthreadlocalVarVar_size_32,
		StthreadlocalVarVar_n_2,
		StthreadlocalVarVar_n_4,
		StthreadlocalVarVar_WriteBarrier_n_2,
		StthreadlocalVarVar_WriteBarrier_n_4,
		NewArrVarVar,
		GetArrayLengthVarVar,
		GetArrayElementAddressAddrVarVar,
		GetArrayElementAddressCheckAddrVarVar,
		GetArrayElementVarVar_i1,
		GetArrayElementVarVar_u1,
		GetArrayElementVarVar_i2,
		GetArrayElementVarVar_u2,
		GetArrayElementVarVar_i4,
		GetArrayElementVarVar_u4,
		GetArrayElementVarVar_i8,
		GetArrayElementVarVar_u8,
		GetArrayElementVarVar_size_1,
		GetArrayElementVarVar_size_2,
		GetArrayElementVarVar_size_4,
		GetArrayElementVarVar_size_8,
		GetArrayElementVarVar_size_12,
		GetArrayElementVarVar_size_16,
		GetArrayElementVarVar_size_20,
		GetArrayElementVarVar_size_24,
		GetArrayElementVarVar_size_28,
		GetArrayElementVarVar_size_32,
		GetArrayElementVarVar_n,
		SetArrayElementVarVar_i1,
		SetArrayElementVarVar_u1,
		SetArrayElementVarVar_i2,
		SetArrayElementVarVar_u2,
		SetArrayElementVarVar_i4,
		SetArrayElementVarVar_u4,
		SetArrayElementVarVar_i8,
		SetArrayElementVarVar_u8,
		SetArrayElementVarVar_ref,
		SetArrayElementVarVar_size_12,
		SetArrayElementVarVar_size_16,
		SetArrayElementVarVar_n,
		SetArrayElementVarVar_WriteBarrier_n,
		NewMdArrVarVar_length,
		NewMdArrVarVar_length_bound,
		GetMdArrElementVarVar_i1,
		GetMdArrElementVarVar_u1,
		GetMdArrElementVarVar_i2,
		GetMdArrElementVarVar_u2,
		GetMdArrElementVarVar_i4,
		GetMdArrElementVarVar_u4,
		GetMdArrElementVarVar_i8,
		GetMdArrElementVarVar_u8,
		GetMdArrElementVarVar_n,
		GetMdArrElementAddressVarVar,
		SetMdArrElementVarVar_i1,
		SetMdArrElementVarVar_u1,
		SetMdArrElementVarVar_i2,
		SetMdArrElementVarVar_u2,
		SetMdArrElementVarVar_i4,
		SetMdArrElementVarVar_u4,
		SetMdArrElementVarVar_i8,
		SetMdArrElementVarVar_u8,
		SetMdArrElementVarVar_ref,
		SetMdArrElementVarVar_n,
		SetMdArrElementVarVar_WriteBarrier_n,
		ThrowEx,
		RethrowEx,
		LeaveEx,
		LeaveEx_Directly,
		EndFilterEx,
		EndFinallyEx,
		NullableNewVarVar,
		NullableCtorVarVar,
		NullableHasValueVar,
		NullableGetValueOrDefaultVarVar,
		NullableGetValueOrDefaultVarVar_1,
		NullableGetValueVarVar,
		InterlockedCompareExchangeVarVarVarVar_i4,
		InterlockedCompareExchangeVarVarVarVar_i8,
		InterlockedCompareExchangeVarVarVarVar_pointer,
		InterlockedExchangeVarVarVar_i4,
		InterlockedExchangeVarVarVar_i8,
		InterlockedExchangeVarVarVar_pointer,
		NewSystemObjectVar,
		NewVector2,
		NewVector3_2,
		NewVector3_3,
		NewVector4_2,
		NewVector4_3,
		NewVector4_4,
		CtorVector2,
		CtorVector3_2,
		CtorVector3_3,
		CtorVector4_2,
		CtorVector4_3,
		CtorVector4_4,
		ArrayGetGenericValueImpl,
		ArraySetGenericValueImpl,
		NewString,
		NewString_2,
		NewString_3,
		UnsafeEnumCast,
		GetEnumHashCode,
		AssemblyGetExecutingAssembly,
		MethodBaseGetCurrentMethod,

		//!!!}}OPCODE
	};

	struct IRCommon
	{
		HiOpcodeEnum type;
	};

#pragma region instruction
#pragma pack(push, 1)
	//!!!{{INST

	struct IRInitLocals_n_2 : IRCommon
	{
		uint16_t size;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitLocals_n_4 : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t size;
	};


	struct IRLdlocVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdlocExpandVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdlocExpandVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdlocExpandVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdlocExpandVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdlocVarVarSize : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint16_t size;
	};


	struct IRLdlocVarAddress : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdcVarConst_1 : IRCommon
	{
		uint8_t src;
		uint8_t __pad3;
		uint16_t dst;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdcVarConst_2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdcVarConst_4 : IRCommon
	{
		uint16_t dst;
		uint32_t src;
	};


	struct IRLdcVarConst_8 : IRCommon
	{
		uint16_t dst;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
		uint64_t src;
	};


	struct IRLdnullVar : IRCommon
	{
		uint16_t dst;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdindVarVar_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStindVarVar_ref : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLocalAllocVarVar_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t size;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLocalAllocVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t size;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitblkVarVarVar : IRCommon
	{
		uint16_t addr;
		uint16_t value;
		uint16_t size;
	};


	struct IRCpblkVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint16_t size;
	};


	struct IRMemoryBarrier : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i4_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u4_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_i8_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_u8_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f4_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertVarVar_f8_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i4_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u4_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_i8_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_u8_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f4_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRConvertOverflowVarVar_f8_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRBinOpVarVarVar_Add_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Sub_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Mul_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_MulUn_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Div_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_DivUn_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Rem_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_RemUn_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_And_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Or_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Xor_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Add_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Sub_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Mul_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_MulUn_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Div_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_DivUn_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Rem_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_RemUn_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_And_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Or_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Xor_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Add_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Sub_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Mul_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Div_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Rem_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Add_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Sub_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Mul_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Div_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpVarVarVar_Rem_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Add_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Sub_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Mul_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Add_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Sub_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Mul_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Add_u4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Sub_u4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Mul_u4 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Add_u8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Sub_u8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBinOpOverflowVarVarVar_Mul_u8 : IRCommon
	{
		uint16_t ret;
		uint16_t op1;
		uint16_t op2;
	};


	struct IRBitShiftBinOpVarVarVar_Shl_i4_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shr_i4_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_ShrUn_i4_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shl_i4_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shr_i4_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_ShrUn_i4_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shl_i8_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shr_i8_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_ShrUn_i8_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shl_i8_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_Shr_i8_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRBitShiftBinOpVarVarVar_ShrUn_i8_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t value;
		uint16_t shiftAmount;
	};


	struct IRUnaryOpVarVar_Neg_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRUnaryOpVarVar_Not_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRUnaryOpVarVar_Neg_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRUnaryOpVarVar_Not_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRUnaryOpVarVar_Neg_f4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRUnaryOpVarVar_Neg_f8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCheckFiniteVar_f4 : IRCommon
	{
		uint16_t src;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCheckFiniteVar_f8 : IRCommon
	{
		uint16_t src;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCompOpVarVarVar_Ceq_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Ceq_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Ceq_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Ceq_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Cgt_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Cgt_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Cgt_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Cgt_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CgtUn_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CgtUn_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CgtUn_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CgtUn_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Clt_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Clt_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Clt_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_Clt_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CltUn_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CltUn_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CltUn_f4 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRCompOpVarVarVar_CltUn_f8 : IRCommon
	{
		uint16_t ret;
		uint16_t c1;
		uint16_t c2;
	};


	struct IRBranchUncondition_4 : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		int32_t offset;
	};


	struct IRBranchTrueVar_i4 : IRCommon
	{
		uint16_t op;
		int32_t offset;
	};


	struct IRBranchTrueVar_i8 : IRCommon
	{
		uint16_t op;
		int32_t offset;
	};


	struct IRBranchFalseVar_i4 : IRCommon
	{
		uint16_t op;
		int32_t offset;
	};


	struct IRBranchFalseVar_i8 : IRCommon
	{
		uint16_t op;
		int32_t offset;
	};


	struct IRBranchVarVar_Ceq_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Ceq_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Ceq_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Ceq_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CneUn_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CneUn_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CneUn_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CneUn_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cgt_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cgt_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cgt_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cgt_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgtUn_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgtUn_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgtUn_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgtUn_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cge_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cge_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cge_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cge_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgeUn_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgeUn_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgeUn_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CgeUn_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Clt_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Clt_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Clt_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Clt_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CltUn_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CltUn_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CltUn_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CltUn_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cle_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cle_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cle_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_Cle_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CleUn_i4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CleUn_i8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CleUn_f4 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchVarVar_CleUn_f8 : IRCommon
	{
		uint16_t op1;
		uint16_t op2;
		uint8_t __pad6;
		uint8_t __pad7;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRBranchJump : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t token;
	};


	struct IRBranchSwitch : IRCommon
	{
		uint16_t value;
		uint32_t caseNum;
		uint32_t caseOffsets;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewClassVar : IRCommon
	{
		uint16_t obj;
		uint32_t managed2NativeMethod;
		uint32_t method;
		uint32_t argIdxs;
	};


	struct IRNewClassVar_Ctor_0 : IRCommon
	{
		uint16_t obj;
		uint32_t method;
	};


	struct IRNewClassVar_NotCtor : IRCommon
	{
		uint16_t obj;
		uint32_t klass;
	};


	struct IRNewValueTypeVar : IRCommon
	{
		uint16_t obj;
		uint32_t managed2NativeMethod;
		uint32_t method;
		uint32_t argIdxs;
	};


	struct IRNewClassInterpVar : IRCommon
	{
		uint16_t obj;
		uint16_t argBase;
		uint16_t argStackObjectNum;
		uint16_t ctorFrameBase;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRNewClassInterpVar_Ctor_0 : IRCommon
	{
		uint16_t obj;
		uint16_t ctorFrameBase;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewValueTypeInterpVar : IRCommon
	{
		uint16_t obj;
		uint16_t argBase;
		uint16_t argStackObjectNum;
		uint16_t ctorFrameBase;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRAdjustValueTypeRefVar : IRCommon
	{
		uint16_t data;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRBoxRefVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdvirftnVarVar : IRCommon
	{
		uint16_t resultMethod;
		uint16_t obj;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t virtualMethod;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRRetVar_ret_1 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_2 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_4 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_8 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_12 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_16 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_20 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_24 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_28 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_32 : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRetVar_ret_n : IRCommon
	{
		uint16_t ret;
		uint32_t size;
	};


	struct IRRetVar_void : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCallNativeInstance_void : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallNativeInstance_ret : IRCommon
	{
		uint16_t ret;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallNativeInstance_ret_expand : IRCommon
	{
		uint8_t retLocationType;
		uint8_t __pad3;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallNativeStatic_void : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallNativeStatic_ret : IRCommon
	{
		uint16_t ret;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallNativeStatic_ret_expand : IRCommon
	{
		uint8_t retLocationType;
		uint8_t __pad3;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallInterp_void : IRCommon
	{
		uint16_t argBase;
		uint32_t methodInfo;
	};


	struct IRCallInterp_ret : IRCommon
	{
		uint16_t argBase;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t methodInfo;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallVirtual_void : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallVirtual_ret : IRCommon
	{
		uint16_t ret;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallVirtual_ret_expand : IRCommon
	{
		uint8_t retLocationType;
		uint8_t __pad3;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallInterpVirtual_void : IRCommon
	{
		uint16_t argBase;
		uint32_t method;
	};


	struct IRCallInterpVirtual_ret : IRCommon
	{
		uint16_t argBase;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallInd_void : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallInd_ret : IRCommon
	{
		uint16_t ret;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
	};


	struct IRCallInd_ret_expand : IRCommon
	{
		uint8_t retLocationType;
		uint8_t __pad3;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t managed2NativeMethod;
		uint32_t methodInfo;
		uint32_t argIdxs;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallDelegateInvoke_void : IRCommon
	{
		uint16_t invokeParamCount;
		uint32_t managed2NativeStaticMethod;
		uint32_t managed2NativeInstanceMethod;
		uint32_t argIdxs;
	};


	struct IRCallDelegateInvoke_ret : IRCommon
	{
		uint16_t ret;
		uint16_t invokeParamCount;
		uint16_t retTypeStackObjectSize;
		uint32_t managed2NativeStaticMethod;
		uint32_t managed2NativeInstanceMethod;
		uint32_t argIdxs;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallDelegateInvoke_ret_expand : IRCommon
	{
		uint8_t retLocationType;
		uint8_t __pad3;
		uint16_t ret;
		uint16_t invokeParamCount;
		uint32_t managed2NativeStaticMethod;
		uint32_t managed2NativeInstanceMethod;
		uint32_t argIdxs;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallDelegateBeginInvoke : IRCommon
	{
		uint16_t result;
		uint32_t methodInfo;
		uint32_t argIdxs;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallDelegateEndInvoke_void : IRCommon
	{
		uint16_t asyncResult;
		uint32_t methodInfo;
	};


	struct IRCallDelegateEndInvoke_ret : IRCommon
	{
		uint16_t asyncResult;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t methodInfo;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewDelegate : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t method;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCtorDelegate : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t method;
		uint32_t ctor;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_0 : IRCommon
	{
		uint16_t self;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i1_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_u1_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i2_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_u2_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i4_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i8_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f4_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f8_0 : IRCommon
	{
		uint16_t self;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_i4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_i4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_i4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_i4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_i8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_i8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_i8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_i8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_f4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_f4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_f4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_f4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_f8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_f8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_v_f8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_v_f8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_i4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_u1_i4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_i4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_i4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_u1_i8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_u1_i8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_i8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_i8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_u1_f4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_u1_f4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_f4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_f4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_u1_f8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_u1_f8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_f8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_u1_f8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i4_i4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i4_i4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_i4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_i4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i4_i8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i4_i8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_i8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_i8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i4_f4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i4_f4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_f4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_f4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i4_f8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i4_f8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_f8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i4_f8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i8_i4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i8_i4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_i4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_i4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i8_i8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i8_i8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_i8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_i8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i8_f4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i8_f4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_f4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_f4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_i8_f8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_i8_f8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_f8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_i8_f8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f4_i4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f4_i4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_i4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_i4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f4_i8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f4_i8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_i8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_i8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f4_f4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f4_f4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_f4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_f4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f4_f8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f4_f8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_f8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f4_f8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f8_i4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f8_i4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_i4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_i4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f8_i8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f8_i8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_i8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_i8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f8_f4_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f8_f4_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_f4_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_f4_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeInstance_f8_f8_1 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeInstance_f8_f8_2 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_f8_3 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeInstance_f8_f8_4 : IRCommon
	{
		uint16_t self;
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint8_t __pad14;
		uint8_t __pad15;
		uint32_t method;
		uint8_t __pad20;
		uint8_t __pad21;
		uint8_t __pad22;
		uint8_t __pad23;
	};


	struct IRCallCommonNativeStatic_v_0 : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i1_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i2_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u2_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_0 : IRCommon
	{
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_i4_1 : IRCommon
	{
		uint16_t param0;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_i4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_i4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_i4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_i8_1 : IRCommon
	{
		uint16_t param0;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_i8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_i8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_i8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_f4_1 : IRCommon
	{
		uint16_t param0;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_f4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_f4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_f4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_f8_1 : IRCommon
	{
		uint16_t param0;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_v_f8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_f8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_v_f8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_i4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_i4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_i4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_i4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_i8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_i8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_i8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_i8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_f4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_f4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_f4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_f4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_f8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_f8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_u1_f8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_u1_f8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_i4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_i4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_i4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_i4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_i8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_i8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_i8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_i8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_f4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_f4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_f4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_f4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_f8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_f8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i4_f8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i4_f8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_i4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_i4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_i4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_i4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_i8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_i8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_i8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_i8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_f4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_f4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_f4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_f4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_f8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_f8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_i8_f8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_i8_f8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_i4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_i4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_i4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_i4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_i8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_i8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_i8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_i8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_f4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_f4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_f4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_f4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_f8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_f8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f4_f8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f4_f8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_i4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_i4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_i4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_i4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_i8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_i8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_i8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_i8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_f4_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_f4_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_f4_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_f4_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_f8_1 : IRCommon
	{
		uint16_t param0;
		uint16_t ret;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_f8_2 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t ret;
		uint32_t method;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCallCommonNativeStatic_f8_f8_3 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t ret;
		uint8_t __pad10;
		uint8_t __pad11;
		uint32_t method;
	};


	struct IRCallCommonNativeStatic_f8_f8_4 : IRCommon
	{
		uint16_t param0;
		uint16_t param1;
		uint16_t param2;
		uint16_t param3;
		uint16_t ret;
		uint32_t method;
	};


	struct IRBoxVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRUnBoxVarVar : IRCommon
	{
		uint16_t addr;
		uint16_t obj;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRUnBoxAnyVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCastclassVar : IRCommon
	{
		uint16_t obj;
		uint32_t klass;
	};


	struct IRIsInstVar : IRCommon
	{
		uint16_t obj;
		uint32_t klass;
	};


	struct IRLdtokenVar : IRCommon
	{
		uint16_t runtimeHandle;
		uint32_t token;
	};


	struct IRMakeRefVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRRefAnyTypeVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t typedRef;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRefAnyValueVarVar : IRCommon
	{
		uint16_t addr;
		uint16_t typedRef;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCpobjVarVar_ref : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_12 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_16 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_20 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_24 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_28 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_32 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRCpobjVarVar_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint16_t size;
	};


	struct IRCpobjVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCpobjVarVar_WriteBarrier_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint16_t size;
	};


	struct IRCpobjVarVar_WriteBarrier_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdobjVarVar_ref : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_12 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_16 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_20 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_24 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_28 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_32 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLdobjVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStobjVarVar_ref : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_1 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_2 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_8 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_12 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_16 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_20 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_24 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_28 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_32 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRStobjVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStobjVarVar_WriteBarrier_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRInitobjVar_ref : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_1 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_2 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_4 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_8 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_12 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_16 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_20 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_24 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_28 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_32 : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_n_2 : IRCommon
	{
		uint16_t obj;
		uint16_t size;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_n_4 : IRCommon
	{
		uint16_t obj;
		uint32_t size;
	};


	struct IRInitobjVar_WriteBarrier_n_2 : IRCommon
	{
		uint16_t obj;
		uint16_t size;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRInitobjVar_WriteBarrier_n_4 : IRCommon
	{
		uint16_t obj;
		uint32_t size;
	};


	struct IRLdstrVar : IRCommon
	{
		uint16_t dst;
		uint32_t str;
	};


	struct IRLdfldVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_8 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_12 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_16 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_20 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_24 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_28 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_size_32 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldVarVar_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
		uint16_t size;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdfldVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdfldValueTypeVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_8 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_12 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_16 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_20 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_24 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_28 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_size_32 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRLdfldValueTypeVarVar_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
		uint16_t size;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdfldValueTypeVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdfldaVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t offset;
	};


	struct IRStfldVarVar_i1 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_u1 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_i2 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_u2 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_i4 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_u4 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_i8 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_u8 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_ref : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_8 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_12 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_16 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_20 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_24 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_28 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_size_32 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
	};


	struct IRStfldVarVar_n_2 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
		uint16_t size;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStfldVarVar_n_4 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStfldVarVar_WriteBarrier_n_2 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
		uint16_t size;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStfldVarVar_WriteBarrier_n_4 : IRCommon
	{
		uint16_t obj;
		uint16_t offset;
		uint16_t data;
		uint32_t size;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_8 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_12 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_16 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_20 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_24 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_28 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_size_32 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint16_t size;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint32_t size;
	};


	struct IRStsfldVarVar_i1 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_u1 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_i2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_u2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_i4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_u4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_i8 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_u8 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_ref : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_8 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_12 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_16 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_20 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_24 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_28 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_size_32 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_n_2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint16_t size;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_n_4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint32_t size;
	};


	struct IRStsfldVarVar_WriteBarrier_n_2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint16_t size;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStsfldVarVar_WriteBarrier_n_4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint32_t size;
	};


	struct IRLdsfldaVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t offset;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdsfldaFromFieldDataVarVar : IRCommon
	{
		uint16_t dst;
		uint32_t src;
	};


	struct IRLdthreadlocalaVarVar : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_u4 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_u8 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_8 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_12 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_16 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_20 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_24 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_28 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_size_32 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRLdthreadlocalVarVar_n_2 : IRCommon
	{
		uint16_t dst;
		uint16_t size;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		int32_t offset;
	};


	struct IRLdthreadlocalVarVar_n_4 : IRCommon
	{
		uint16_t dst;
		uint32_t klass;
		int32_t offset;
		uint32_t size;
	};


	struct IRStthreadlocalVarVar_i1 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_u1 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_i2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_u2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_i4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_u4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_i8 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_u8 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_ref : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_8 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_12 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_16 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_20 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_24 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_28 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_size_32 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_n_2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint16_t size;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_n_4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint32_t size;
	};


	struct IRStthreadlocalVarVar_WriteBarrier_n_2 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint16_t size;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRStthreadlocalVarVar_WriteBarrier_n_4 : IRCommon
	{
		uint16_t offset;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint32_t size;
	};


	struct IRNewArrVarVar : IRCommon
	{
		uint16_t arr;
		uint16_t size;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRGetArrayLengthVarVar : IRCommon
	{
		uint16_t len;
		uint16_t arr;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRGetArrayElementAddressAddrVarVar : IRCommon
	{
		uint16_t addr;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementAddressCheckAddrVarVar : IRCommon
	{
		uint16_t addr;
		uint16_t arr;
		uint16_t index;
		uint32_t eleKlass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRGetArrayElementVarVar_i1 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_u1 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_i2 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_u2 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_i4 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_u4 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_i8 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_u8 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_1 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_2 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_4 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_8 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_12 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_16 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_20 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_24 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_28 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_size_32 : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRGetArrayElementVarVar_n : IRCommon
	{
		uint16_t dst;
		uint16_t arr;
		uint16_t index;
	};


	struct IRSetArrayElementVarVar_i1 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_u1 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_i2 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_u2 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_i4 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_u4 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_i8 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_u8 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_ref : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_size_12 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_size_16 : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_n : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRSetArrayElementVarVar_WriteBarrier_n : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t ele;
	};


	struct IRNewMdArrVarVar_length : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewMdArrVarVar_length_bound : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t lowerBoundIdxs;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRGetMdArrElementVarVar_i1 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_u1 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_i2 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_u2 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_i4 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_u4 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_i8 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_u8 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementVarVar_n : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t value;
	};


	struct IRGetMdArrElementAddressVarVar : IRCommon
	{
		uint16_t addr;
		uint16_t arr;
		uint16_t lengthIdxs;
	};


	struct IRSetMdArrElementVarVar_i1 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_u1 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_i2 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_u2 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_i4 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_u4 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_i8 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_u8 : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_ref : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_n : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRSetMdArrElementVarVar_WriteBarrier_n : IRCommon
	{
		uint16_t arr;
		uint16_t lengthIdxs;
		uint16_t ele;
	};


	struct IRThrowEx : IRCommon
	{
		uint16_t exceptionObj;
		uint16_t firstHandlerIndex;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRRethrowEx : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRLeaveEx : IRCommon
	{
		uint16_t firstHandlerIndex;
		int32_t target;
	};


	struct IRLeaveEx_Directly : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		int32_t target;
	};


	struct IREndFilterEx : IRCommon
	{
		uint16_t value;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IREndFinallyEx : IRCommon
	{
		uint8_t __pad2;
		uint8_t __pad3;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRNullableNewVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNullableCtorVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t data;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNullableHasValueVar : IRCommon
	{
		uint16_t result;
		uint16_t obj;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNullableGetValueOrDefaultVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNullableGetValueOrDefaultVarVar_1 : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint16_t defaultValue;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNullableGetValueVarVar : IRCommon
	{
		uint16_t dst;
		uint16_t obj;
		uint8_t __pad6;
		uint8_t __pad7;
		uint32_t klass;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRInterlockedCompareExchangeVarVarVarVar_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t location;
		uint16_t value;
		uint16_t comparand;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRInterlockedCompareExchangeVarVarVarVar_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t location;
		uint16_t value;
		uint16_t comparand;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRInterlockedCompareExchangeVarVarVarVar_pointer : IRCommon
	{
		uint16_t ret;
		uint16_t location;
		uint16_t value;
		uint16_t comparand;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRInterlockedExchangeVarVarVar_i4 : IRCommon
	{
		uint16_t ret;
		uint16_t location;
		uint16_t value;
	};


	struct IRInterlockedExchangeVarVarVar_i8 : IRCommon
	{
		uint16_t ret;
		uint16_t location;
		uint16_t value;
	};


	struct IRInterlockedExchangeVarVarVar_pointer : IRCommon
	{
		uint16_t ret;
		uint16_t location;
		uint16_t value;
	};


	struct IRNewSystemObjectVar : IRCommon
	{
		uint16_t obj;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRNewVector2 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
	};


	struct IRNewVector3_2 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
	};


	struct IRNewVector3_3 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewVector4_2 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
	};


	struct IRNewVector4_3 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewVector4_4 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint16_t w;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCtorVector2 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
	};


	struct IRCtorVector3_2 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
	};


	struct IRCtorVector3_3 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCtorVector4_2 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
	};


	struct IRCtorVector4_3 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRCtorVector4_4 : IRCommon
	{
		uint16_t obj;
		uint16_t x;
		uint16_t y;
		uint16_t z;
		uint16_t w;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRArrayGetGenericValueImpl : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t value;
	};


	struct IRArraySetGenericValueImpl : IRCommon
	{
		uint16_t arr;
		uint16_t index;
		uint16_t value;
	};


	struct IRNewString : IRCommon
	{
		uint16_t str;
		uint16_t chars;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRNewString_2 : IRCommon
	{
		uint16_t str;
		uint16_t chars;
		uint16_t startIndex;
		uint16_t length;
		uint8_t __pad10;
		uint8_t __pad11;
		uint8_t __pad12;
		uint8_t __pad13;
		uint8_t __pad14;
		uint8_t __pad15;
	};


	struct IRNewString_3 : IRCommon
	{
		uint16_t str;
		uint16_t c;
		uint16_t count;
	};


	struct IRUnsafeEnumCast : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint16_t srcType;
	};


	struct IRGetEnumHashCode : IRCommon
	{
		uint16_t dst;
		uint16_t src;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRAssemblyGetExecutingAssembly : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	struct IRMethodBaseGetCurrentMethod : IRCommon
	{
		uint16_t ret;
		uint8_t __pad4;
		uint8_t __pad5;
		uint8_t __pad6;
		uint8_t __pad7;
	};


	//!!!}}INST
#pragma pack(pop)

#pragma endregion

}
}