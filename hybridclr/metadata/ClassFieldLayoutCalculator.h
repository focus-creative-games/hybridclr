#pragma once

#include <vector>

#include "MetadataUtil.h"

namespace hybridclr
{
namespace metadata
{

	struct FieldLayout
	{
		const Il2CppType* type;
		int32_t offset;
		int32_t size;
		bool isNormalStatic;
		bool isThreadStatic;
	};

	struct ClassLayoutInfo
	{
		const Il2CppType* type;
		std::vector<FieldLayout> fields;
		int32_t instanceSize;
		int32_t actualSize;
		int32_t nativeSize;
		uint32_t staticFieldsSize;
		uint32_t threadStaticFieldsSize;
		uint8_t alignment;
#if !HYBRIDCLR_UNITY_2022_OR_NEW
		uint8_t naturalAlignment;
#endif
	};

	struct SizeAndAlignment
	{
		int32_t size;
		int32_t nativeSize;
		uint8_t alignment;
		uint8_t naturalAlignment;
	};

	struct FieldLayoutData
	{
		std::vector<size_t> FieldOffsets;
		int32_t classSize;
		int32_t actualClassSize;
		int32_t nativeSize;
		
		uint8_t minimumAlignment;
		uint8_t naturalAlignment;
	};

	class InterpreterImage;

	typedef std::unordered_map<const Il2CppType*, ClassLayoutInfo, Il2CppTypeHash, Il2CppTypeEqualTo> Il2CppType2ClassLayoutInfoMap;

	class ClassFieldLayoutCalculator
	{
	private:
		InterpreterImage* _image;
		Il2CppType2ClassLayoutInfoMap _classMap;

	public:
		ClassFieldLayoutCalculator(InterpreterImage* image) : _image(image)
		{

		}

		ClassLayoutInfo* GetClassLayoutInfo(const Il2CppType* type)
		{
			auto it = _classMap.find(type);
			return it != _classMap.end() ? &it->second : nullptr;
		}

		void CalcClassNotStaticFields(const Il2CppType* type);
		void CalcClassStaticFields(const Il2CppType* type);

		void LayoutFields(int32_t actualParentSize, int32_t parentAlignment, uint8_t packing, std::vector<FieldLayout*>& fields, FieldLayoutData& data);
		SizeAndAlignment GetTypeSizeAndAlignment(const Il2CppType* type);
	};
}
}