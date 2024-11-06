
#include "Transform.h"

#include <unordered_set>

#include "TransformContext.h"

#include "../metadata/MethodBodyCache.h"

namespace hybridclr
{
namespace transform
{

	InterpMethodInfo* HiTransform::Transform(const MethodInfo* methodInfo)
	{
		TemporaryMemoryArena pool;

		metadata::Image* image = metadata::MetadataModule::GetUnderlyingInterpreterImage(methodInfo);
		IL2CPP_ASSERT(image);

		metadata::MethodBodyCache::EnableShrinkMethodBodyCache(false);
		metadata::MethodBody* methodBody = metadata::MethodBodyCache::GetMethodBody(image, methodInfo->token);
		if (methodBody == nullptr || methodBody->ilcodes == nullptr)
		{
			TEMP_FORMAT(errMsg, "Method body is null. %s.%s::%s", methodInfo->klass->namespaze, methodInfo->klass->name, methodInfo->name);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
		}
		InterpMethodInfo* result = new (HYBRIDCLR_METADATA_MALLOC(sizeof(InterpMethodInfo))) InterpMethodInfo;
		il2cpp::utils::dynamic_array<uint64_t> resolveDatas;
		TransformContext ctx(image, methodInfo, *methodBody, pool, resolveDatas);

		ctx.TransformBody(0, 0, *result);
		metadata::MethodBodyCache::EnableShrinkMethodBodyCache(true);
		return result;
	}
}

}
