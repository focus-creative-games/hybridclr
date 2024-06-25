#pragma once

#include "../CommonDef.h"

#include "metadata/GenericMetadata.h"

namespace hybridclr
{
namespace metadata
{
	class MetadataPool
	{
	public:
		static void Initialize();
		static const Il2CppType* GetPooledIl2CppType(const Il2CppType& type);
		static Il2CppType* ShallowCloneIl2CppType(const Il2CppType* type);
	};
}
}