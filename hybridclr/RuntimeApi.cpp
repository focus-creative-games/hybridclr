#include "RuntimeApi.h"

#include "codegen/il2cpp-codegen.h"
#include "vm/InternalCalls.h"
#include "vm/Array.h"
#include "vm/Exception.h"

#include "metadata/MetadataModule.h"
#include "Config.h"

namespace hybridclr
{
	void RuntimeApi::RegisterInternalCalls()
	{
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::LoadMetadataForAOTAssembly(System.Byte[],HybridCLR.HomologousImageMode)", (Il2CppMethodPointer)LoadMetadataForAOTAssembly);
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::GetInterpreterThreadObjectStackSize()", (Il2CppMethodPointer)GetInterpreterThreadObjectStackSize);
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::SetInterpreterThreadObjectStackSize(System.Int32)", (Il2CppMethodPointer)SetInterpreterThreadObjectStackSize);
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::GetInterpreterThreadFrameStackSize()", (Il2CppMethodPointer)GetInterpreterThreadFrameStackSize);
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::SetInterpreterThreadFrameStackSize(System.Int32)", (Il2CppMethodPointer)SetInterpreterThreadFrameStackSize);
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::GetInterpreterThreadExceptionFlowSize()", (Il2CppMethodPointer)GetInterpreterThreadExceptionFlowSize);
		il2cpp::vm::InternalCalls::Add("HybridCLR.RuntimeApi::SetInterpreterThreadExceptionFlowSize(System.Int32)", (Il2CppMethodPointer)SetInterpreterThreadExceptionFlowSize);
	}

	int32_t RuntimeApi::LoadMetadataForAOTAssembly(Il2CppArray* dllBytes, int32_t mode)
	{
		if (!dllBytes)
		{
			il2cpp::vm::Exception::RaiseNullReferenceException();
		}
		return (int32_t)hybridclr::metadata::MetadataModule::LoadMetadataForAOTAssembly(il2cpp::vm::Array::GetFirstElementAddress(dllBytes), il2cpp::vm::Array::GetByteLength(dllBytes), (hybridclr::metadata::HomologousImageMode)mode);
	}

	uint32_t RuntimeApi::GetInterpreterThreadObjectStackSize()
	{
		return hybridclr::Config::GetIns().GetInterpreterThreadObjectStackSize();
	}

	void RuntimeApi::SetInterpreterThreadObjectStackSize(uint32_t size)
	{
		hybridclr::Config::GetIns().SetInterpreterThreadObjectStackSize(size);
	}

	uint32_t RuntimeApi::GetInterpreterThreadFrameStackSize()
	{
		return hybridclr::Config::GetIns().GetInterpreterThreadFrameStackSize();
	}

	void RuntimeApi::SetInterpreterThreadFrameStackSize(uint32_t size)
	{
		hybridclr::Config::GetIns().SetInterpreterThreadFrameStackSize(size);
	}

	uint32_t RuntimeApi::GetInterpreterThreadExceptionFlowSize()
	{
		return hybridclr::Config::GetIns().GetInterpreterThreadExceptionFlowSize();
	}

	void RuntimeApi::SetInterpreterThreadExceptionFlowSize(uint32_t size)
	{
		hybridclr::Config::GetIns().SetInterpreterThreadExceptionFlowSize(size);
	}

}
