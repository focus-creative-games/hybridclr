#pragma once
#include <vector>

#include "codegen/il2cpp-codegen-il2cpp.h"
#include "os/ThreadLocalValue.h"

#include "Engine.h"
#include "MethodBridge.h"
#include "../metadata/MetadataDef.h"
#include "../metadata/Image.h"

namespace huatuo
{

namespace interpreter
{

	class Interpreter
	{
	public:
		IL2CPP_FORCE_INLINE static void RuntimeClassCCtorInit(const MethodInfo* method)
		{
			Il2CppClass* klass = method->klass;
			il2cpp::vm::ClassInlines::InitFromCodegen(klass);
			if (klass->has_cctor && !klass->cctor_finished && !huatuo::metadata::IsInstanceMethod(method))
			{
				il2cpp_codegen_runtime_class_init(klass);
			}
		}

		IL2CPP_FORCE_INLINE static void RuntimeClassCCtorInit(Il2CppClass* klass)
		{
			il2cpp::vm::ClassInlines::InitFromCodegen(klass);
			if (klass->has_cctor && !klass->cctor_finished)
			{
				il2cpp_codegen_runtime_class_init(klass);
			}
		}

		static void Execute(const MethodInfo* methodInfo, StackObject* args, StackObject* ret);

	};

}
}

