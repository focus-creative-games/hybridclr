#include "TransformModule.h"
#include "TransformContext.h"

namespace hybridclr
{
namespace transform
{
	void TransformModule::Initialize()
	{
		TransformContext::InitializeInstinctHandlers();
	}
}
}