#include "Runtime.h"

#include "vm/Exception.h"
#include "vm/String.h"
#include "vm/Assembly.h"
#include "vm/Class.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "icalls/mscorlib/System.Reflection/Assembly.h"

#include "RuntimeApi.h"
#include "interpreter/InterpreterModule.h"
#include "metadata/MetadataModule.h"
#include "transform/TransformModule.h"


namespace hybridclr
{

	void Runtime::Initialize()
	{
		RuntimeApi::RegisterInternalCalls();
		metadata::MetadataModule::Initialize();
		interpreter::InterpreterModule::Initialize();
		transform::TransformModule::Initialize();
	}
}