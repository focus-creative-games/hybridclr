#include <codegen/il2cpp-codegen-metadata.h>
#if HYBRIDCLR_UNITY_2023_OR_NEW
#include <codegen/il2cpp-codegen.h>
#elif HYBRIDCLR_UNITY_2022
#include <codegen/il2cpp-codegen-il2cpp.h>
#elif HYBRIDCLR_UNITY_2020 || HYBRIDCLR_UNITY_2021
#include <codegen/il2cpp-codegen-common-big.h>
#else
#include <codegen/il2cpp-codegen-common.h>
#endif

#include "vm/ClassInlines.h"
#include "vm/Object.h"
#include "vm/Class.h"
#include "vm/ScopedThreadAttacher.h"

#include "../metadata/MetadataUtil.h"


#include "../interpreter/InterpreterModule.h"
#include "../interpreter/MethodBridge.h"
#include "../interpreter/Interpreter.h"
#include "../interpreter/MemoryUtil.h"
#include "../interpreter/InstrinctDef.h"

using namespace hybridclr::interpreter;
using namespace hybridclr::metadata;

//!!!{{CODE

const FullName2Signature hybridclr::interpreter::g_fullName2SignatureStub[] = {
	{ nullptr, nullptr},
};


const Managed2NativeMethodInfo hybridclr::interpreter::g_managed2nativeStub[] = 
{

	{nullptr, nullptr},
};


const Native2ManagedMethodInfo hybridclr::interpreter::g_native2managedStub[] = 
{
	{nullptr, nullptr},
};

const NativeAdjustThunkMethodInfo hybridclr::interpreter::g_adjustThunkStub[] = 
{
	{nullptr, nullptr},
};

const ReversePInvokeMethodData hybridclr::interpreter::g_reversePInvokeMethodStub[]
{
    {nullptr, nullptr},
};

//!!!}}CODE
