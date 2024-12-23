#pragma once
#include "Image.h"

namespace hybridclr
{
namespace metadata
{
	struct AOTFieldData
	{
		uint32_t typeDefIndex; // rowIndex - 1
		const Il2CppFieldDefinition* fieldDef;
	};

	enum class HomologousImageMode
	{
		CONSISTENT,
		SUPERSET,
	};

	class AOTHomologousImage : public Image
	{
	public:

		static AOTHomologousImage* FindImageByAssembly(const Il2CppAssembly* ass);
		static AOTHomologousImage* FindImageByAssemblyLocked(const Il2CppAssembly* ass, il2cpp::os::FastAutoLock& lock);
		static void RegisterLocked(AOTHomologousImage* image, il2cpp::os::FastAutoLock& lock);

		AOTHomologousImage() : _targetAssembly(nullptr) { }

		const Il2CppAssembly* GetTargetAssembly() const
		{
			return _targetAssembly;
		}

		void SetTargetAssembly(const Il2CppAssembly* targetAssembly)
		{
			_targetAssembly = targetAssembly;
		}

		LoadImageErrorCode Load(const byte* imageData, size_t length);

		const Il2CppType* GetModuleIl2CppType(uint32_t moduleRowIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound) override;
	protected:
		const Il2CppAssembly* _targetAssembly;
	};
}
}