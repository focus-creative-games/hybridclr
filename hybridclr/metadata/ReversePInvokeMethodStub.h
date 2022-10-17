#pragma once

#include "../CommonDef.h"

namespace hybridclr
{
namespace metadata
{
	struct ReversePInvokeMethodData
	{
		const char* methodSig;
		Il2CppMethodPointer methodPointer;
	};

	extern ReversePInvokeMethodData g_reversePInvokeMethodStub[];
}
}