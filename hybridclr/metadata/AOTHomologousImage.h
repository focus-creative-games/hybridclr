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

		AOTHomologousImage() : _aotAssembly(nullptr) { }

		const Il2CppAssembly* GetAOTAssembly() const
		{
			return _aotAssembly;
		}

		LoadImageErrorCode Load(const byte* imageData, size_t length);

		bool GetModuleIl2CppType(Il2CppType& type, uint32_t moduleRowIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound) override;
	protected:
		const Il2CppAssembly* _aotAssembly;
	};
}
}