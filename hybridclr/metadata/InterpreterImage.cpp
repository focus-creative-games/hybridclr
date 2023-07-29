#include "InterpreterImage.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "il2cpp-class-internals.h"
#include "vm/GlobalMetadata.h"
#include "vm/Type.h"
#include "vm/Field.h"
#include "vm/Object.h"
#include "vm/Runtime.h"
#include "vm/Array.h"
#include "vm/MetadataLock.h"
#include "vm/MetadataCache.h"
#include "vm/String.h"
#include "vm/Reflection.h"
#include "metadata/FieldLayout.h"
#include "metadata/Il2CppTypeCompare.h"
#include "metadata/GenericMetadata.h"
#if HYBRIDCLR_UNITY_2021_OR_NEW
#include "metadata/CustomAttributeCreator.h"
#endif
#include "os/Atomic.h"
#include "icalls/mscorlib/System/MonoCustomAttrs.h"

#include "MetadataModule.h"
#include "MetadataUtil.h"
#include "ClassFieldLayoutCalculator.h"

#include "../interpreter/Engine.h"
#include "../interpreter/InterpreterModule.h"

namespace hybridclr
{
namespace metadata
{

	uint32_t InterpreterImage::s_cliImageCount = 0;
	InterpreterImage* InterpreterImage::s_images[kMaxLoadImageCount + 1] = {};

	void InterpreterImage::Initialize()
	{
		s_cliImageCount = 0;
		std::memset(s_images, 0, sizeof(Assembly*) * (kMaxLoadImageCount + 1));
	}

	uint32_t InterpreterImage::AllocImageIndex()
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
		return ++s_cliImageCount;
	}

	void InterpreterImage::RegisterImage(InterpreterImage* image)
	{
		il2cpp::os::Atomic::FullMemoryBarrier();
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
		IL2CPP_ASSERT(image->GetIndex() > 0);
		s_images[image->GetIndex()] = image;
	}

	void InterpreterImage::InitBasic(Il2CppImage* image)
	{
		SetIl2CppImage(image);
		RegisterImage(this);
	}

	void InterpreterImage::BuildIl2CppAssembly(Il2CppAssembly* ass)
	{
		ass->token = EncodeToken(TableType::ASSEMBLY, 1);
		ass->referencedAssemblyStart = EncodeWithIndex(1);
		ass->referencedAssemblyCount = _rawImage.GetTableRowNum(TableType::ASSEMBLYREF);

		TbAssembly data = _rawImage.ReadAssembly(1);
		auto& aname = ass->aname;
		aname.hash_alg = data.hashAlgId;
		aname.major = data.majorVersion;
		aname.minor = data.minorVersion;
		aname.build = data.buildNumber;
		aname.revision = data.revisionNumber;
		aname.flags = data.flags;
		aname.public_key = _rawImage.GetBlobFromRawIndex(data.publicKey);
		aname.name = _rawImage.GetStringFromRawIndex(data.name);
		aname.culture = _rawImage.GetStringFromRawIndex(data.culture);
	}

	void InterpreterImage::BuildIl2CppImage(Il2CppImage* image2)
	{
		image2->typeCount = _rawImage.GetTableRowNum(TableType::TYPEDEF);
		image2->exportedTypeCount = _rawImage.GetTableRowNum(TableType::EXPORTEDTYPE);
		image2->customAttributeCount = _rawImage.GetTableRowNum(TableType::CUSTOMATTRIBUTE);

		Il2CppImageGlobalMetadata* metadataImage = (Il2CppImageGlobalMetadata*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppImageGlobalMetadata));
		metadataImage->typeStart = EncodeWithIndex(0);
		metadataImage->customAttributeStart = EncodeWithIndex(0);
		metadataImage->entryPointIndex = EncodeWithIndexExcept0(_rawImage.GetEntryPointToken());
		metadataImage->exportedTypeStart = EncodeWithIndex(0);
		metadataImage->image = image2;
		image2->metadataHandle = reinterpret_cast<Il2CppMetadataImageHandle>(metadataImage);

		image2->nameToClassHashTable = nullptr;
		image2->codeGenModule = nullptr;

		image2->token = EncodeWithIndex(0); // TODO
		image2->dynamic = 0;
	}

	void InterpreterImage::InitRuntimeMetadatas()
	{
		IL2CPP_ASSERT(_rawImage.GetTable(TableType::EXPORTEDTYPE).rowNum == 0);

		InitGenericParamDefs0();
		InitTypeDefs_0();
		InitMethodDefs0();
		InitGenericParamDefs();
		InitNestedClass(); // must before typedefs1, because parent may be nested class
		InitTypeDefs_1();

		InitGenericParamConstraintDefs();

		InitParamDefs();
		InitMethodDefs();
		InitFieldDefs();
		InitFieldLayouts();
		InitFieldRVAs();
		InitBlittables();
		InitMethodImpls0();
		InitProperties();
		InitEvents();
		InitMethodSemantics();
		InitConsts();
		InitCustomAttributes();
		InitTypeDefs_2();
		InitClassLayouts();
		InitInterfaces();
		InitClass();
		InitVTables();
	}

	void InterpreterImage::InitTypeDefs_0()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);
		_typesDefines.resize(typeDefTb.rowNum);
		_typeDetails.resize(typeDefTb.rowNum);
		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			Il2CppTypeDefinition& cur = _typesDefines[i];
			TypeDefinitionDetail& typeDetail = _typeDetails[i];
			typeDetail.index = i;
			typeDetail.typeDef = &cur;
			typeDetail.typeSizes = {};

			uint32_t rowIndex = i + 1;
			TbTypeDef data = _rawImage.ReadTypeDef(rowIndex);

			cur = {};

			cur.genericContainerIndex = kGenericContainerIndexInvalid;
			cur.declaringTypeIndex = kTypeDefinitionIndexInvalid;
			cur.elementTypeIndex = kTypeDefinitionIndexInvalid;

			cur.token = EncodeToken(TableType::TYPEDEF, rowIndex);

			bool isValueType = data.extends && IsValueTypeFromToken(DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.extends), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.extends));
			Il2CppType cppType = {};
			cppType.type = isValueType ? IL2CPP_TYPE_VALUETYPE : IL2CPP_TYPE_CLASS;
			SET_IL2CPPTYPE_VALUE_TYPE(cppType, isValueType);
			cppType.data.typeHandle = (Il2CppMetadataTypeHandle)&cur;
			cur.byvalTypeIndex = AddIl2CppTypeCache(cppType);

			if (IsInterface(cur.flags))
			{
				cur.interfaceOffsetsStart = EncodeWithIndex(0);
				cur.interface_offsets_count = 0;
				cur.vtableStart = EncodeWithIndex(0);
				cur.vtable_count = 0;
			}
			else
			{
				cur.interfaceOffsetsStart = 0;
				cur.interface_offsets_count = 0;
				cur.vtableStart = 0;
				cur.vtable_count = 0;
			}
		}
	}

	void InterpreterImage::InitTypeDefs_1()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);
		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			Il2CppTypeDefinition& last = _typesDefines[i > 0 ? i - 1 : 0];
			Il2CppTypeDefinition& cur = _typesDefines[i];
			uint32_t rowIndex = i + 1;
			TbTypeDef data = _rawImage.ReadTypeDef(rowIndex); // token from 1

			cur.flags = data.flags;
			cur.nameIndex = EncodeWithIndex(data.typeName);
			cur.namespaceIndex = EncodeWithIndex(data.typeNamespace);

			cur.fieldStart = EncodeWithIndex(data.fieldList - 1);
			cur.methodStart = EncodeWithIndex(data.methodList - 1);

			if (i > 0)
			{
				last.field_count = (uint16_t)(cur.fieldStart - last.fieldStart);
				last.method_count = (uint16_t)(cur.methodStart - last.methodStart);
			}
			if (i == n - 1)
			{
				cur.field_count = (uint16_t)(_rawImage.GetTableRowNum(TableType::FIELD) - DecodeMetadataIndex(cur.fieldStart));
				cur.method_count = (uint16_t)(_rawImage.GetTableRowNum(TableType::METHOD) - DecodeMetadataIndex(cur.methodStart));
			}

			if (data.extends != 0)
			{
				Il2CppType parentType = {};
				ReadTypeFromToken(GetGenericContainerByTypeDefinition(&cur), nullptr, DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.extends), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.extends), parentType);

				if (parentType.type == IL2CPP_TYPE_CLASS || parentType.type == IL2CPP_TYPE_VALUETYPE)
				{
					Il2CppTypeDefinition* parentDef = (Il2CppTypeDefinition*)parentType.data.typeHandle;
					// FIXE ME . check mscorelib
					const char* parentNs = il2cpp::vm::GlobalMetadata::GetStringFromIndex(parentDef->namespaceIndex);
					if (std::strcmp(parentNs, "System") == 0)
					{
						const char* parentName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(parentDef->nameIndex);
						if (std::strcmp(parentName, "Enum") == 0)
						{
							cur.bitfield |= (1 << (il2cpp::vm::kBitIsValueType - 1));
							cur.bitfield |= (1 << (il2cpp::vm::kBitIsEnum - 1));
						}
						else if (std::strcmp(parentName, "ValueType") == 0)
						{
							cur.bitfield |= (1 << (il2cpp::vm::kBitIsValueType - 1));
						}
					}
				}
				cur.parentIndex = AddIl2CppTypeCache(parentType);
			}
			else
			{
				cur.parentIndex = kInvalidIndex;
			}

			cur.elementTypeIndex = kInvalidIndex;
		}
	}

	void InterpreterImage::InitTypeDefs_2()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			TbTypeDef data = _rawImage.ReadTypeDef(i + 1); // token from 1

			Il2CppTypeDefinition& last = _typesDefines[i > 0 ? i - 1 : 0];
			Il2CppTypeDefinition& cur = _typesDefines[i];
			uint32_t typeIndex = i; // type index start from 0, diff with field index ...

			// enum element_type == 
			if (cur.bitfield & (1 << (il2cpp::vm::kBitIsEnum - 1)))
			{
				cur.elementTypeIndex = _fieldDetails[DecodeMetadataIndex(cur.fieldStart)].fieldDef.typeIndex;
			}

			auto classLayoutRow = _classLayouts.find(typeIndex);
			uint16_t packingSize = 0;
			if (classLayoutRow != _classLayouts.end())
			{
				auto& layoutData = classLayoutRow->second;
				packingSize = layoutData.packingSize;
			}
			else
			{
				cur.bitfield |= (1 << (il2cpp::vm::kClassSizeIsDefault - 1));
			}
			if (packingSize != 0)
			{
				cur.bitfield |= ((uint32_t)il2cpp::vm::GlobalMetadata::ConvertPackingSizeToEnum((uint8_t)packingSize) << (il2cpp::vm::kPackingSize - 1));
			}
			else
			{
				cur.bitfield |= (1 << (il2cpp::vm::kPackingSizeIsDefault - 1));
			}
		}
	}

	void InterpreterImage::InitParamDefs()
	{
		const Table& tb = _rawImage.GetTable(TableType::PARAM);

		// extra 16 for not name params
		_params.reserve(tb.rowNum + 16);
		_paramRawIndex2ActualParamIndex.resize(tb.rowNum);
		//for (uint32_t i = 0; i < tb.rowNum; i++)
		//{
		//	uint32_t rowIndex = i + 1;
		//	Il2CppParameterDefinition& pd = _params[i].paramDef;
		//	TbParam data = _rawImage.ReadParam(rowIndex);

		//	pd.nameIndex = EncodeWithIndex(data.name);
		//	pd.token = EncodeToken(TableType::PARAM, rowIndex);
		//	// pd.typeIndex 在InitMethodDefs中解析signature后填充。
		//}
	}


	void InterpreterImage::InitFieldDefs()
	{
		const Table& fieldTb = _rawImage.GetTable(TableType::FIELD);
		_fieldDetails.resize(fieldTb.rowNum);

		for (size_t i = 0; i < _typesDefines.size(); i++)
		{
			Il2CppTypeDefinition& typeDef = _typesDefines[i];
			uint32_t start = DecodeMetadataIndex(typeDef.fieldStart);
			for (uint32_t k = 0; k < typeDef.field_count; k++)
			{
				FieldDetail& fd = _fieldDetails[start + k];
				fd.typeDefIndex = (uint32_t)i;
			}
		}

		for (uint32_t i = 0, n = fieldTb.rowNum; i < n; i++)
		{
			FieldDetail& fd = _fieldDetails[i];
			Il2CppFieldDefinition& cur = fd.fieldDef;

			fd.offset = 0;
			fd.defaultValueIndex = kDefaultValueIndexNull;

			uint32_t rowIndex = i + 1;
			TbField data = _rawImage.ReadField(rowIndex);

			BlobReader br = _rawImage.GetBlobReaderByRawIndex(data.signature);
			FieldRefSig frs;
			ReadFieldRefSig(br, GetGenericContainerByTypeDefRawIndex(DecodeMetadataIndex(fd.typeDefIndex)), frs);
			frs.type.attrs = data.flags;

			//cur = {};
			cur.nameIndex = EncodeWithIndex(data.name);
			cur.token = EncodeToken(TableType::FIELD, rowIndex);
			cur.typeIndex = AddIl2CppTypeCache(frs.type);
		}
	}

	void InterpreterImage::InitFieldLayouts()
	{
		const Table& tb = _rawImage.GetTable(TableType::FIELDLAYOUT);
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			TbFieldLayout data = _rawImage.ReadFieldLayout(i + 1);
			_fieldDetails[data.field - 1].offset = sizeof(Il2CppObject) + data.offset;
		}
	}

	void InterpreterImage::InitFieldRVAs()
	{
		const Table& tb = _rawImage.GetTable(TableType::FIELDRVA);
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			TbFieldRVA data = _rawImage.ReadFieldRVA(i + 1);
			FieldDetail& fd = _fieldDetails[data.field - 1];
			fd.defaultValueIndex = (uint32_t)_fieldDefaultValues.size();

			Il2CppFieldDefaultValue fdv = {};
			fdv.fieldIndex = data.field - 1;
			fdv.typeIndex = fd.fieldDef.typeIndex;

			uint32_t dataImageOffset = (uint32_t)-1;
			bool ret = _rawImage.TranslateRVAToImageOffset(data.rva, dataImageOffset);
			IL2CPP_ASSERT(ret);
#if HYBRIDCLR_UNITY_2021_OR_NEW
			fdv.dataIndex = (DefaultValueDataIndex)EncodeWithIndex(EncodeWithBlobSource(dataImageOffset, BlobSource::RAW_IMAGE));
#else
			fdv.dataIndex = (DefaultValueDataIndex)EncodeWithIndex(dataImageOffset);
#endif
			_fieldDefaultValues.push_back(fdv);
		}
	}

	void InterpreterImage::InitBlittables()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);

		std::vector<bool> computFlags(typeDefTb.rowNum, false);

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			ComputeBlittable(&_typesDefines[i], computFlags);
		}
	}

	void InterpreterImage::ComputeBlittable(Il2CppTypeDefinition* def, std::vector<bool>& computFlags)
	{
		if (DecodeImageIndex(def->byvalTypeIndex) != GetIndex())
		{
			return;
		}
		uint32_t typeIndex = GetTypeRawIndex(def);
		if (computFlags[typeIndex])
		{
			return;
		}
		computFlags[typeIndex] = true;

		const Il2CppType* type = GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(def->byvalTypeIndex));

		const char* typeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(def->nameIndex);


		bool blittable = false;
		if (type->type == IL2CPP_TYPE_VALUETYPE)
		{
			blittable = true;
			for (int i = 0; i < def->field_count; i++)
			{
				const Il2CppFieldDefinition* field = GetFieldDefinitionFromRawIndex(DecodeMetadataIndex(def->fieldStart + i));
				const Il2CppType* fieldType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(field->typeIndex);
				if (!hybridclr::metadata::IsInstanceField(fieldType))
				{
					continue;
				}

				switch (fieldType->type)
				{
				case IL2CPP_TYPE_BOOLEAN:
				case IL2CPP_TYPE_CHAR:
				case IL2CPP_TYPE_I1:
				case IL2CPP_TYPE_U1:
				case IL2CPP_TYPE_I2:
				case IL2CPP_TYPE_U2:
				case IL2CPP_TYPE_I4:
				case IL2CPP_TYPE_U4:
				case IL2CPP_TYPE_I:
				case IL2CPP_TYPE_U:
				case IL2CPP_TYPE_I8:
				case IL2CPP_TYPE_U8:
				case IL2CPP_TYPE_R4:
				case IL2CPP_TYPE_R8:
				case IL2CPP_TYPE_PTR:
				case IL2CPP_TYPE_FNPTR:
				{
					break;
				}
				case IL2CPP_TYPE_VALUETYPE:
				{
					Il2CppTypeDefinition* fieldDef = (Il2CppTypeDefinition*)fieldType->data.typeHandle;
					ComputeBlittable(fieldDef, computFlags);
					blittable = fieldDef->bitfield & (1 << (il2cpp::vm::kBitIsBlittable - 1));
					break;
				}
				default:
				{
					blittable = false;
				}
				}
				if (!blittable)
				{
					break;
				}
			}
		}
		if (blittable)
		{
			def->bitfield |= (1 << (il2cpp::vm::kBitIsBlittable - 1));
		}
	}

#if HYBRIDCLR_UNITY_2021_OR_NEW
	DefaultValueDataIndex InterpreterImage::ConvertConstValue(CustomAttributeDataWriter& writer, uint32_t blobIndex, const Il2CppType* type)
	{
		Il2CppTypeEnum ttype = type->type;
		if (ttype == IL2CPP_TYPE_CLASS)
		{
			return kDefaultValueIndexNull;
		}

		DefaultValueIndex retIndex = EncodeWithIndex(EncodeWithBlobSource((DefaultValueIndex)writer.Size(), BlobSource::CONVERTED_IL2CPP_FORMAT));

		BlobReader reader = _rawImage.GetBlobReaderByRawIndex(blobIndex);
		switch (type->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		{
			writer.Write(reader, 1);
			break;
		}
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		{
			writer.Write(reader, 2);
			break;
		}
		case IL2CPP_TYPE_I4:
		{
			writer.WriteCompressedInt32((int32_t)reader.Read32());
			break;
		}
		case IL2CPP_TYPE_U4:
		{
			writer.WriteCompressedUint32(reader.Read32());
			break;
		}
		case IL2CPP_TYPE_R4:
		{
			writer.Write(reader, 4);
			break;
		}
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R8:
		{
			writer.Write(reader, 8);
			break;
		}
		case IL2CPP_TYPE_STRING:
		{
			std::string str = il2cpp::utils::StringUtils::Utf16ToUtf8((const Il2CppChar*)reader.GetData(), reader.GetLength() / 2);
			writer.WriteCompressedInt32((int32_t)str.length());
			writer.WriteBytes((const uint8_t*)str.c_str(), (int32_t)str.length());
			break;
		}
		default:
		{
			RaiseExecutionEngineException("not supported const type");
		}
		}
		
		return retIndex;
	}
#endif

	void InterpreterImage::InitConsts()
	{
		const Table& tb = _rawImage.GetTable(TableType::CONSTANT);
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			TbConstant data = _rawImage.ReadConstant(i + 1);
			TableType parentType = DecodeHasConstantType(data.parent);
			uint32_t rowIndex = DecodeHashConstantIndex(data.parent);

			Il2CppType type = {};
			type.type = (Il2CppTypeEnum)data.type;
			TypeIndex dataTypeIndex = AddIl2CppTypeCache(type);
#if HYBRIDCLR_UNITY_2020
			bool isNullValue = type.type == IL2CPP_TYPE_CLASS;
#endif
			switch (parentType)
			{
			case TableType::FIELD:
			{
				FieldDetail& fd = _fieldDetails[rowIndex - 1];
				fd.defaultValueIndex = (uint32_t)_fieldDefaultValues.size();

				Il2CppFieldDefaultValue fdv = {};
				fdv.fieldIndex = rowIndex - 1;
				fdv.typeIndex = dataTypeIndex;
#if HYBRIDCLR_UNITY_2021_OR_NEW
				fdv.dataIndex = ConvertConstValue(_constValues, data.value, &type);
#else
				uint32_t dataImageOffset = _rawImage.GetImageOffsetOfBlob(type.type, data.value);
				fdv.dataIndex = isNullValue ? kDefaultValueIndexNull : (DefaultValueDataIndex)EncodeWithIndex(dataImageOffset);
#endif
				_fieldDefaultValues.push_back(fdv);
				break;
			}
			case TableType::PARAM:
			{
				int32_t actualIndex = _paramRawIndex2ActualParamIndex[rowIndex - 1];
				ParamDetail& fd = _params[actualIndex];
				fd.defaultValueIndex = (uint32_t)_paramDefaultValues.size();

				Il2CppParameterDefaultValue pdv = {};
				pdv.typeIndex = dataTypeIndex;
				pdv.parameterIndex = fd.parameterIndex;
#if HYBRIDCLR_UNITY_2021_OR_NEW
				pdv.dataIndex = ConvertConstValue(_constValues, data.value, &type);
#else
				uint32_t dataImageOffset = _rawImage.GetImageOffsetOfBlob(type.type, data.value);
				pdv.dataIndex = isNullValue ? kDefaultValueIndexNull : (DefaultValueDataIndex)EncodeWithIndex(dataImageOffset);
#endif
				_paramDefaultValues.push_back(pdv);
				break;
			}
			case TableType::PROPERTY:
			{
				RaiseNotSupportedException("not support property const");
				break;
			}
			default:
			{
				RaiseExecutionEngineException("not support const TableType");
				break;
			}
			}
		}
	}

	void InterpreterImage::InitCustomAttributes()
	{
		const Table& tb = _rawImage.GetTable(TableType::CUSTOMATTRIBUTE);
		_tokenCustomAttributes.reserve(tb.rowNum);


		uint32_t threadStaticMethodToken = 0;
		Il2CppCustomAttributeTypeRange* curTypeRange = nullptr;
		for (uint32_t rowIndex = 1; rowIndex <= tb.rowNum; rowIndex++)
		{
			TbCustomAttribute data = _rawImage.ReadCustomAttribute(rowIndex);
			TableType parentType = DecodeHasCustomAttributeCodedIndexTableType(data.parent);
			uint32_t parentRowIndex = DecodeHasCustomAttributeCodedIndexRowIndex(data.parent);
			uint32_t token = EncodeToken(parentType, parentRowIndex);
			if (curTypeRange == nullptr || curTypeRange->token != token)
			{
				IL2CPP_ASSERT(_tokenCustomAttributes.find(token) == _tokenCustomAttributes.end());
				int32_t attributeStartIndex = EncodeWithIndex((int32_t)_customAttribues.size());
				int32_t handleIndex = (int32_t)_customAttributeHandles.size();
				_tokenCustomAttributes[token] = { (int32_t)EncodeWithIndex(handleIndex), false, nullptr, nullptr };
#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
				_customAttributeHandles.push_back({ token, (uint32_t)attributeStartIndex });
#else
				_customAttributeHandles.push_back({ token, attributeStartIndex, 0 });
#endif
				curTypeRange = &_customAttributeHandles[handleIndex];
			}
#if HYBRIDCLR_UNITY_2020
			++curTypeRange->count;
#endif
			TableType ctorMethodTableType = DecodeCustomAttributeTypeCodedIndexTableType(data.type);
			uint32_t ctorMethodRowIndex = DecodeCustomAttributeTypeCodedIndexRowIndex(data.type);
			uint32_t ctorMethodToken = EncodeToken(ctorMethodTableType, ctorMethodRowIndex);
			//CustomAttribute ca = { ctorMethodToken, data.value };
			//ca.value = data.value;
			//ReadMethodRefInfoFromToken(nullptr, nullptr, , ca.attrCtorMethod);
			_customAttribues.push_back({ ctorMethodToken, data.value });

			if (parentType == TableType::FIELD)
			{
				// try set thread static flags
				if (threadStaticMethodToken == 0)
				{
					if (IsThreadStaticCtorToken(ctorMethodTableType, ctorMethodRowIndex))
					{
						threadStaticMethodToken = ctorMethodToken;
					}
				}
				if (ctorMethodToken == threadStaticMethodToken)
				{
					IL2CPP_ASSERT(threadStaticMethodToken != 0);
					_fieldDetails[parentRowIndex - 1].offset = THREAD_LOCAL_STATIC_MASK;
				}
			}

		}
		IL2CPP_ASSERT(_tokenCustomAttributes.size() == _customAttributeHandles.size());
#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
		// add extra Il2CppCustomAttributeTypeRange for compute count
		_customAttributeHandles.push_back({ 0, EncodeWithIndex((int32_t)_customAttribues.size()) });
#endif
#if !HYBRIDCLR_UNITY_2022_OR_NEW
		_customAttribtesCaches.resize(_tokenCustomAttributes.size());
#endif
	}

#ifdef HYBRIDCLR_UNITY_2021_OR_NEW

	void InterpreterImage::InitCustomAttributeData(CustomAttributesInfo& cai, const Il2CppCustomAttributeTypeRange& dataRange)
	{
		il2cpp::os::FastAutoLock metaLock(&il2cpp::vm::g_MetadataLock);
		if (cai.inited)
		{
			return;
		}
		BuildCustomAttributesData(cai, dataRange);
		il2cpp::os::Atomic::FullMemoryBarrier();
		cai.inited = true;
	}

	void InterpreterImage::BuildCustomAttributesData(CustomAttributesInfo& cai, const Il2CppCustomAttributeTypeRange& curTypeRange)
	{
		hybridclr::interpreter::ExecutingInterpImageScope scope(hybridclr::interpreter::InterpreterModule::GetCurrentThreadMachineState(), this->_il2cppImage);
		_il2cppFormatCustomDataBlob.Reset();
		const Il2CppCustomAttributeDataRange& nextTypeRange = *(&curTypeRange + 1);
		uint32_t attrCount = nextTypeRange.startOffset - curTypeRange.startOffset;
		IL2CPP_ASSERT(attrCount > 0 && attrCount < 1024);
		_il2cppFormatCustomDataBlob.WriteAttributeCount(attrCount);
		int32_t attrStartOffset = DecodeMetadataIndex(curTypeRange.startOffset);
		int32_t methodIndexDataOffset = _il2cppFormatCustomDataBlob.Size();
		_il2cppFormatCustomDataBlob.Skip(attrCount * sizeof(int32_t));
		for (uint32_t i = 0; i < attrCount; i++)
		{
			const CustomAttribute& ca = _customAttribues[attrStartOffset + (int32_t)i];
			MethodRefInfo mri = {};
			ReadMethodRefInfoFromToken(nullptr, nullptr, DecodeTokenTableType(ca.ctorMethodToken), DecodeTokenRowIndex(ca.ctorMethodToken), mri);
			const MethodInfo* ctorMethod = GetMethodInfoFromMethodDef(&mri.containerType, mri.methodDef);
			MethodIndex ctorIndex = il2cpp::vm::GlobalMetadata::GetMethodIndexFromDefinition(mri.methodDef);
			_il2cppFormatCustomDataBlob.WriteMethodIndex(methodIndexDataOffset, ctorIndex);
			methodIndexDataOffset += sizeof(int32_t);
			if (ca.value != 0)
			{
				BlobReader reader = _rawImage.GetBlobReaderByRawIndex(ca.value);
				ConvertILCustomAttributeData2Il2CppFormat(ctorMethod, reader);
			}
			else
			{
				IL2CPP_ASSERT(mri.methodDef->parameterCount == 0);
				_il2cppFormatCustomDataBlob.WriteCompressedUint32(0);
				_il2cppFormatCustomDataBlob.WriteCompressedUint32(0);
				_il2cppFormatCustomDataBlob.WriteCompressedUint32(0);
			}
		}
		void* resultData = IL2CPP_MALLOC(_il2cppFormatCustomDataBlob.Size());
		std::memcpy(resultData, _il2cppFormatCustomDataBlob.Data(), _il2cppFormatCustomDataBlob.Size());
		cai.dataStartPtr = resultData;
		cai.dataEndPtr = (uint8_t*)resultData + _il2cppFormatCustomDataBlob.Size();
	}

	void InterpreterImage::WriteEncodeTypeEnum(CustomAttributeDataWriter& writer, const Il2CppType* type)
	{
		Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
		if (type->type == IL2CPP_TYPE_ENUM || klass->enumtype)
		{
			writer.WriteByte((byte)IL2CPP_TYPE_ENUM);
			int32_t typeIndex = type->type == IL2CPP_TYPE_CLASS || type->type == IL2CPP_TYPE_VALUETYPE ? ((Il2CppTypeDefinition*)type->data.typeHandle)->byvalTypeIndex : AddIl2CppTypeCache(*type);
			writer.WriteCompressedInt32(typeIndex);
		}
		else if (klass == il2cpp_defaults.systemtype_class)
		{
			writer.WriteByte((byte)IL2CPP_TYPE_IL2CPP_TYPE_INDEX);
		}
		else
		{
			writer.WriteByte((uint8_t)type->type);
		}
	}

	void InterpreterImage::ConvertBoxedValue(CustomAttributeDataWriter& writer, BlobReader& reader, bool writeType)
	{
		uint64_t obj = 0;
		Il2CppType kind = {};
		ReadCustomAttributeFieldOrPropType(reader, kind);
		ConvertFixedArg(writer, reader, &kind, true);
	}

	void InterpreterImage::ConvertSystemType(CustomAttributeDataWriter& writer, BlobReader& reader, bool writeType)
	{
		if (writeType)
		{
			writer.WriteByte((byte)IL2CPP_TYPE_IL2CPP_TYPE_INDEX);
		}
		Il2CppString* fullName = ReadSerString(reader);
		if (!fullName)
		{
			writer.WriteCompressedInt32(-1);
			return;
		}
		Il2CppReflectionType* type = GetReflectionTypeFromName(fullName);
		if (!type)
		{
			std::string stdTypeName = il2cpp::utils::StringUtils::Utf16ToUtf8(fullName->chars);
			TEMP_FORMAT(errMsg, "CustomAttribute fixed arg type:System.Type fullName:'%s' not find", stdTypeName.c_str());
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
		}
		Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type->type);
		if (!klass->generic_class)
		{
			writer.WriteCompressedInt32(((Il2CppTypeDefinition*)klass->typeMetadataHandle)->byvalTypeIndex);
		}
		else
		{
			writer.WriteCompressedInt32(AddIl2CppTypeCache(*(type->type)));
		}
	}

	void InterpreterImage::ConvertFixedArg(CustomAttributeDataWriter& writer, BlobReader& reader, const Il2CppType* type, bool writeType)
	{
		switch (type->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			writer.Write(reader, 1);
			break;
		}
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			writer.Write(reader, 2);
			break;
		}
		case IL2CPP_TYPE_I4:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			writer.WriteCompressedInt32((int32_t)reader.Read32());
			break;
		}
		case IL2CPP_TYPE_U4:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			writer.WriteCompressedUint32(reader.Read32());
			break;
		}
		case IL2CPP_TYPE_R4:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			writer.Write(reader, 4);
			break;
		}
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R8:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			writer.Write(reader, 8);
			break;
		}
		case IL2CPP_TYPE_SZARRAY:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			int32_t numElem = (int32_t)reader.Read32();
			writer.WriteCompressedInt32(numElem);
			if (numElem != -1)
			{
				//Il2CppType kind = {};
				//ReadCustomAttributeFieldOrPropType(reader, kind);
				const Il2CppType* eleType = type->data.type;
				WriteEncodeTypeEnum(writer, eleType);
				if (eleType->type == IL2CPP_TYPE_OBJECT)
				{
					// kArrayTypeWithDifferentElements
					writer.WriteByte(1);
					for (uint16_t i = 0; i < numElem; i++)
					{
						ConvertBoxedValue(writer, reader, false);
					}
				}
				else
				{
					// all element type is same.
					writer.WriteByte(0);
					for (uint16_t i = 0; i < numElem; i++)
					{
						ConvertFixedArg(writer, reader, eleType, false);
					}
				}

			}
			break;
		}
		case IL2CPP_TYPE_STRING:
		{
			if (writeType)
			{
				writer.WriteByte((uint8_t)type->type);
			}
			byte b = reader.PeekByte();
			if (b == 0xFF)
			{
				reader.SkipByte();
				writer.WriteCompressedInt32(-1);
			}
			else if (b == 0)
			{
				reader.SkipByte();
				writer.WriteCompressedInt32(0);
			}
			else
			{
				const byte* beginDataPtr = reader.GetDataOfReadPosition();
				uint32_t len = reader.ReadCompressedUint32();
				writer.WriteCompressedInt32((int32_t)len);
				writer.WriteBytes(reader.GetDataOfReadPosition(), len);
				reader.SkipBytes(len);
			}
			break;
		}
		case IL2CPP_TYPE_OBJECT:
		{
			ConvertBoxedValue(writer, reader, writeType);
			//*(Il2CppObject**)data = ReadBoxedValue(reader);
			// FIXME memory barrier
			break;
		}
		case IL2CPP_TYPE_CLASS:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			if (!klass)
			{
				RaiseExecutionEngineException("type not find");
			}
			if (klass == il2cpp_defaults.object_class)
			{
				ConvertBoxedValue(writer, reader, writeType);
			}
			else if (klass == il2cpp_defaults.systemtype_class)
			{
				ConvertSystemType(writer, reader, writeType);
			}
			else
			{
				TEMP_FORMAT(errMsg, "fixed arg type:%s.%s not support", klass->namespaze, klass->name);
				RaiseNotSupportedException(errMsg);
			}
			break;
		}
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			if (writeType)
			{
				writer.WriteByte((byte)IL2CPP_TYPE_ENUM);
				IL2CPP_ASSERT(klass->enumtype);
				int32_t typeIndex = klass->generic_class ? AddIl2CppTypeCache(*type) : ((Il2CppTypeDefinition*)type->data.typeHandle)->byvalTypeIndex;
				writer.WriteCompressedInt32(typeIndex);
			}
			ConvertFixedArg(writer, reader, &klass->element_class->byval_arg, false);
			break;
		}
		case IL2CPP_TYPE_SYSTEM_TYPE:
		{
			ConvertSystemType(writer, reader, true);
			break;
		}
		case IL2CPP_TYPE_BOXED_OBJECT:
		{
			uint8_t fieldOrPropType = reader.ReadByte();
			IL2CPP_ASSERT(fieldOrPropType == 0x51);
			ConvertBoxedValue(writer, reader, writeType);
			break;
		}
		case IL2CPP_TYPE_ENUM:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
			IL2CPP_ASSERT(klass->enumtype);
			if (writeType)
			{
				int32_t typeIndex = klass->generic_class ? AddIl2CppTypeCache(*type) : ((Il2CppTypeDefinition*)type->data.typeHandle)->byvalTypeIndex;
				writer.WriteCompressedInt32(typeIndex);
			}
			ConvertFixedArg(writer, reader, &klass->element_class->byval_arg, false);
			break;
		}
		default:
		{
			RaiseExecutionEngineException("not support fixed argument type");
		}
		}
	}

	void InterpreterImage::GetFieldDeclaringTypeIndexAndFieldIndexByName(const Il2CppTypeDefinition* declaringType, const char* name, int32_t& typeIndex, int32_t& fieldIndex)
	{
		Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)declaringType);
		FieldInfo* field = il2cpp::vm::Class::GetFieldFromName(klass, name);
		if (!field)
		{
			RaiseExecutionEngineException("GetFieldDeclaringTypeIndexAndFieldIndexByName can't find field");
		}
		if (field->parent == klass)
		{
			typeIndex = kTypeDefinitionIndexInvalid;
		}
		else
		{
			klass = field->parent;
			if (klass->generic_class)
			{
				RaiseExecutionEngineException("GetFieldDeclaringTypeIndexAndFieldIndexByName doesn't support field of generic CustomAttribute");
			}
			typeIndex = il2cpp::vm::GlobalMetadata::GetIndexForTypeDefinition(klass);
		}
		fieldIndex = (int32_t)(field - klass->fields);
	}

	void InterpreterImage::GetPropertyDeclaringTypeIndexAndPropertyIndexByName(const Il2CppTypeDefinition* declaringType, const char* name, int32_t& typeIndex, int32_t& fieldIndex)
	{
		Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)declaringType);
		const PropertyInfo* propertyInfo = il2cpp::vm::Class::GetPropertyFromName(klass, name);
		if (!propertyInfo)
		{
			RaiseExecutionEngineException("GetFieldDeclaringTypeIndexAndFieldIndexByName can't find field");
		}
		if (propertyInfo->parent == klass)
		{
			typeIndex = kTypeDefinitionIndexInvalid;
		}
		else
		{
			klass = propertyInfo->parent;
			if (klass->generic_class)
			{
				RaiseExecutionEngineException("GetPropertyDeclaringTypeIndexAndPropertyIndexByName doesn't support field of generic CustomAttribute");
			}
			typeIndex = il2cpp::vm::GlobalMetadata::GetIndexForTypeDefinition(klass);
		}
		fieldIndex = (int32_t)(propertyInfo - klass->properties);
	}

	void InterpreterImage::ConvertILCustomAttributeData2Il2CppFormat(const MethodInfo* ctorMethod, BlobReader& reader)
	{
		uint16_t prolog = reader.Read16();
		IL2CPP_ASSERT(prolog == 0x0001);
		IL2CPP_ASSERT(!ctorMethod->is_generic);

		_tempCtorArgBlob.Reset();
		for (uint16_t i = 0; i < ctorMethod->parameters_count; i++)
		{
			const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(ctorMethod->parameters[i]);
			ConvertFixedArg(_tempCtorArgBlob, reader, paramType, true);
		}

		uint16_t numNamed = reader.Read16();

		uint32_t fieldCount = 0;
		uint32_t propertyCount = 0;
		_tempFieldBlob.Reset();
		_tempPropertyBlob.Reset();
		const Il2CppTypeDefinition* declaringType = GetUnderlyingTypeDefinition(&ctorMethod->klass->byval_arg);
		for (uint16_t idx = 0; idx < numNamed; idx++)
		{
			byte fieldOrPropTypeTag = reader.ReadByte();
			IL2CPP_ASSERT(fieldOrPropTypeTag == 0x53 || fieldOrPropTypeTag == 0x54);
			Il2CppType fieldOrPropType = {};
			ReadCustomAttributeFieldOrPropType(reader, fieldOrPropType);
			Il2CppString* fieldOrPropName = ReadSerString(reader);
			std::string stdStrName = il2cpp::utils::StringUtils::Utf16ToUtf8(fieldOrPropName->chars);
			const char* cstrName = stdStrName.c_str();
			int32_t fieldOrPropertyDeclaringTypeIndex = kTypeIndexInvalid;
			int32_t fieldOrPropertyIndex = 0;
			if (fieldOrPropTypeTag == 0x53)
			{
				++fieldCount;
				ConvertFixedArg(_tempFieldBlob, reader, &fieldOrPropType, true);
				GetFieldDeclaringTypeIndexAndFieldIndexByName(declaringType, cstrName, fieldOrPropertyDeclaringTypeIndex, fieldOrPropertyIndex);
				if (fieldOrPropertyDeclaringTypeIndex == kTypeDefinitionIndexInvalid)
				{
					_tempFieldBlob.WriteCompressedInt32(fieldOrPropertyIndex);
				}
				else
				{
					_tempFieldBlob.WriteCompressedInt32(-fieldOrPropertyIndex - 1);
					_tempFieldBlob.WriteCompressedUint32(fieldOrPropertyDeclaringTypeIndex);
				}
			}
			else
			{
				++propertyCount;
				ConvertFixedArg(_tempPropertyBlob, reader, &fieldOrPropType, true);
				GetPropertyDeclaringTypeIndexAndPropertyIndexByName(declaringType, cstrName, fieldOrPropertyDeclaringTypeIndex, fieldOrPropertyIndex);
				if (fieldOrPropertyDeclaringTypeIndex == kTypeDefinitionIndexInvalid)
				{
					_tempPropertyBlob.WriteCompressedInt32(fieldOrPropertyIndex);
				}
				else
				{
					_tempPropertyBlob.WriteCompressedInt32(-fieldOrPropertyIndex - 1);
					_tempPropertyBlob.WriteCompressedUint32(fieldOrPropertyDeclaringTypeIndex);
				}
			}
		}
		_il2cppFormatCustomDataBlob.WriteCompressedUint32(ctorMethod->parameters_count);
		_il2cppFormatCustomDataBlob.WriteCompressedUint32(fieldCount);
		_il2cppFormatCustomDataBlob.WriteCompressedUint32(propertyCount);
		_il2cppFormatCustomDataBlob.Write(_tempCtorArgBlob);
		_il2cppFormatCustomDataBlob.Write(_tempFieldBlob);
		_il2cppFormatCustomDataBlob.Write(_tempPropertyBlob);
	}
#endif

#if HYBRIDCLR_UNITY_2020

	void InterpreterImage::ConstructCustomAttribute(BlobReader& reader, Il2CppObject* obj, const MethodInfo* ctorMethod)
	{
		uint16_t prolog = reader.Read16();
		IL2CPP_ASSERT(prolog == 0x0001);
		if (ctorMethod->parameters_count == 0)
		{
			il2cpp::vm::Runtime::Invoke(ctorMethod, obj, nullptr, nullptr);
		}
		else
		{
			int32_t argSize = sizeof(uint64_t) * ctorMethod->parameters_count;
			uint64_t* argDatas = (uint64_t*)alloca(argSize);
			std::memset(argDatas, 0, argSize);
			void** argPtrs = (void**)alloca(sizeof(void*) * ctorMethod->parameters_count); // same with argDatas
			for (uint8_t i = 0; i < ctorMethod->parameters_count; i++)
			{
				argPtrs[i] = argDatas + i;
				const Il2CppType* paramType = GET_METHOD_PARAMETER_TYPE(ctorMethod->parameters[i]);
				ReadFixedArg(reader, paramType, argDatas + i);
				Il2CppClass* paramKlass = il2cpp::vm::Class::FromIl2CppType(paramType);
				if (!IS_CLASS_VALUE_TYPE(paramKlass))
				{
					argPtrs[i] = (void*)argDatas[i];
				}
			}
			il2cpp::vm::Runtime::Invoke(ctorMethod, obj, argPtrs, nullptr);
			// clear ref. may not need. gc memory barrier
			std::memset(argDatas, 0, argSize);
		}
		uint16_t numNamed = reader.Read16();
		Il2CppClass* klass = obj->klass;
		for (uint16_t idx = 0; idx < numNamed; idx++)
		{
			byte fieldOrPropTypeTag = reader.ReadByte();
			IL2CPP_ASSERT(fieldOrPropTypeTag == 0x53 || fieldOrPropTypeTag == 0x54);
			Il2CppType fieldOrPropType = {};
			ReadCustomAttributeFieldOrPropType(reader, fieldOrPropType);
			Il2CppString* fieldOrPropName = ReadSerString(reader);
			std::string stdStrName = il2cpp::utils::StringUtils::Utf16ToUtf8(fieldOrPropName->chars);
			const char* cstrName = stdStrName.c_str();
			uint64_t value = 0;
			ReadFixedArg(reader, &fieldOrPropType, &value);
			if (fieldOrPropTypeTag == 0x53)
			{
				FieldInfo* field = il2cpp::vm::Class::GetFieldFromName(klass, cstrName);
				if (!field)
				{
					TEMP_FORMAT(errMsg, "CustomAttribute field missing. klass:%s.%s field:%s", klass->namespaze, klass->name, cstrName);
					il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeInitializationException(errMsg, nullptr));
				}
				Il2CppReflectionField* refField = il2cpp::vm::Reflection::GetFieldObject(klass, field);
				IL2CPP_ASSERT(IsTypeEqual(&fieldOrPropType, field->type));
				uint32_t fieldSize = GetTypeValueSize(&fieldOrPropType);
				std::memcpy((byte*)obj + field->offset, &value, fieldSize);
				//fixme MEMORY BARRIER
				IL2CPP_ASSERT(refField);
			}
			else
			{
				const PropertyInfo* prop = il2cpp::vm::Class::GetPropertyFromName(klass, cstrName);
				if (!prop)
				{
					TEMP_FORMAT(errMsg, "CustomAttribute property missing. klass:%s property:%s", klass->name, cstrName);
					il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeInitializationException(errMsg, nullptr));
				}
				IL2CPP_ASSERT(IsTypeEqual(&fieldOrPropType, GET_METHOD_PARAMETER_TYPE(prop->set->parameters[0])));
				Il2CppException* ex = nullptr;
				Il2CppClass* propKlass = il2cpp::vm::Class::FromIl2CppType(&fieldOrPropType);
				IL2CPP_ASSERT(propKlass);
				void* args[] = { (IS_CLASS_VALUE_TYPE(propKlass) ? &value : (void*)value) };
				il2cpp::vm::Runtime::Invoke(prop->set, obj, args, &ex);
				if (ex)
				{
					il2cpp::vm::Exception::Raise(ex);
				}
			}
		}
	}

	CustomAttributesCache* InterpreterImage::GenerateCustomAttributesCacheInternal(CustomAttributeIndex index)
	{
		IL2CPP_ASSERT(index != kCustomAttributeIndexInvalid);
		CustomAttributesCache* cache = _customAttribtesCaches[index];
		if (cache)
		{
			return cache;
		}
		IL2CPP_ASSERT(index < (CustomAttributeIndex)_customAttributeHandles.size());

		Il2CppCustomAttributeTypeRange& typeRange = _customAttributeHandles[index];

		il2cpp::os::FastAutoLock metaLock(&il2cpp::vm::g_MetadataLock);
		cache = _customAttribtesCaches[index];
		if (cache)
		{
			return cache;
		}

		hybridclr::interpreter::ExecutingInterpImageScope scope(hybridclr::interpreter::InterpreterModule::GetCurrentThreadMachineState(), this->_il2cppImage);

		cache = (CustomAttributesCache*)IL2CPP_CALLOC(1, sizeof(CustomAttributesCache));
		int32_t count;
#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
		count = (int32_t)(_customAttributeHandles[index + 1].startOffset - typeRange.startOffset);
#else
		count = (int32_t)typeRange.count;
#endif
		cache->count = count;
		cache->attributes = (Il2CppObject**)il2cpp::gc::GarbageCollector::AllocateFixed(sizeof(Il2CppObject*) * count, 0);

		int32_t start = DecodeMetadataIndex(GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(typeRange));
		for (int32_t i = 0; i < count; i++)
		{
			int32_t attrIndex = start + i;
			IL2CPP_ASSERT(attrIndex >= 0 && attrIndex < (int32_t)_customAttribues.size());
			CustomAttribute& ca = _customAttribues[attrIndex];
			MethodRefInfo mri = {};
			ReadMethodRefInfoFromToken(nullptr, nullptr, DecodeTokenTableType(ca.ctorMethodToken), DecodeTokenRowIndex(ca.ctorMethodToken), mri);
			const MethodInfo* ctorMethod = GetMethodInfoFromMethodDef(&mri.containerType, mri.methodDef);
			IL2CPP_ASSERT(ctorMethod);
			Il2CppClass* klass = ctorMethod->klass;
			Il2CppObject* attr = il2cpp::vm::Object::New(klass);
			Il2CppArray* paramArr = nullptr;
			if (ca.value != 0)
			{
				BlobReader reader = _rawImage.GetBlobReaderByRawIndex(ca.value);
				ConstructCustomAttribute(reader, attr, ctorMethod);
			}
			else
			{
				IL2CPP_ASSERT(ctorMethod->parameters_count == 0);
				il2cpp::vm::Runtime::Invoke(ctorMethod, attr, nullptr, nullptr);
			}

			cache->attributes[i] = attr;
			il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)cache->attributes + i);
		}

		il2cpp::os::Atomic::FullMemoryBarrier();
		_customAttribtesCaches[index] = cache;
		return cache;
	}
#elif HYBRIDCLR_UNITY_2021
	CustomAttributesCache* InterpreterImage::GenerateCustomAttributesCacheInternal(CustomAttributeIndex index)
	{
		IL2CPP_ASSERT(index != kCustomAttributeIndexInvalid);
		CustomAttributesCache* cache = _customAttribtesCaches[index];
		if (cache)
		{
			return cache;
		}
		IL2CPP_ASSERT(index < (CustomAttributeIndex)_customAttributeHandles.size());

		Il2CppCustomAttributeTypeRange& typeRange = _customAttributeHandles[index];

		cache = _customAttribtesCaches[index];
		if (cache)
		{
			return cache;
		}

		hybridclr::interpreter::ExecutingInterpImageScope scope(hybridclr::interpreter::InterpreterModule::GetCurrentThreadMachineState(), this->_il2cppImage);

		void* start;
		void* end;
		std::tie(start, end) = CreateCustomAttributeDataTuple(&typeRange);
		IL2CPP_ASSERT(start && end);

		il2cpp::metadata::CustomAttributeDataReader reader(start, end);

		cache = (CustomAttributesCache*)IL2CPP_CALLOC(1, sizeof(CustomAttributesCache));
		cache->count = (int)reader.GetCount();
		cache->attributes = (Il2CppObject**)il2cpp::gc::GarbageCollector::AllocateFixed(sizeof(Il2CppObject*) * cache->count, 0);

		il2cpp::metadata::CustomAttributeDataIterator iter = reader.GetDataIterator();
		for (int i = 0; i < cache->count; i++)
		{
			Il2CppException* exc = NULL;
			il2cpp::metadata::CustomAttributeCreator creator;
			if (reader.VisitCustomAttributeData(_il2cppImage, &iter, &creator, &exc))
			{
				cache->attributes[i] = creator.GetAttribute(&exc);
				il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)&cache->attributes[i]);
			}

			if (exc != NULL)
			{
				il2cpp::gc::GarbageCollector::FreeFixed(cache->attributes);
				IL2CPP_FREE(cache);
				il2cpp::vm::Exception::Raise(exc);
			}
		}


		il2cpp::os::FastAutoLock metaLock(&il2cpp::vm::g_MetadataLock);
		CustomAttributesCache* original = _customAttribtesCaches[index];
		if (original)
		{
			// A non-NULL return value indicates some other thread already generated this cache.
			// We need to cleanup the resources we allocated
			il2cpp::gc::GarbageCollector::FreeFixed(cache->attributes);
			IL2CPP_FREE(cache);
			return original;
		}
		il2cpp::os::Atomic::FullMemoryBarrier();
		_customAttribtesCaches[index] = cache;
		return cache;
	}
#endif

	void InterpreterImage::InitMethodDefs0()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);
		const Table& methodTb = _rawImage.GetTable(TableType::METHOD);

		_methodDefines.resize(methodTb.rowNum);
		for (Il2CppMethodDefinition& md : _methodDefines)
		{
			md.genericContainerIndex = kGenericContainerIndexInvalid;
		}
	}

	void InterpreterImage::InitMethodDefs()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);
		const Table& methodTb = _rawImage.GetTable(TableType::METHOD);

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			Il2CppTypeDefinition& typeDef = _typesDefines[i];
			uint32_t rawMethodStart = DecodeMetadataIndex(typeDef.methodStart);

			for (int m = 0; m < typeDef.method_count; m++)
			{
				Il2CppMethodDefinition& md = _methodDefines[rawMethodStart + m];
				md.declaringType = EncodeWithIndex(i);
			}
		}


		_methodDefine2InfoCaches.resize(methodTb.rowNum);
		_methodBodies.resize(methodTb.rowNum);

		int32_t paramTableRowNum = _rawImage.GetTable(TableType::PARAM).rowNum;
		for (uint32_t index = 0; index < methodTb.rowNum; index++)
		{
			Il2CppMethodDefinition& md = _methodDefines[index];
			uint32_t rowIndex = index + 1;
			TbMethod methodData = _rawImage.ReadMethod(rowIndex);

			md.nameIndex = EncodeWithIndex(methodData.name);
			md.parameterStart = methodData.paramList - 1;
			//md.genericContainerIndex = kGenericContainerIndexInvalid;
			md.token = EncodeToken(TableType::METHOD, rowIndex);
			md.flags = methodData.flags;
			md.iflags = methodData.implFlags;
			md.slot = kInvalidIl2CppMethodSlot;
			if (index > 0)
			{
				auto& last = _methodDefines[index - 1];
				last.parameterCount = md.parameterStart - last.parameterStart;
			}
			if (index == methodTb.rowNum - 1)
			{
				md.parameterCount = (int)paramTableRowNum - (int32_t)md.parameterStart;
			}

			MethodBody& body = _methodBodies[index];
			ReadMethodBody(md, methodData, body);
		}

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			Il2CppTypeDefinition& typeDef = _typesDefines[i];
			uint32_t rawMethodStart = DecodeMetadataIndex(typeDef.methodStart);
			bool isInterface = IsInterface(typeDef.flags);
			for (int m = 0; m < typeDef.method_count; m++)
			{
				Il2CppMethodDefinition& md = _methodDefines[rawMethodStart + m];
				const char* methodName = _rawImage.GetStringFromRawIndex(DecodeMetadataIndex(md.nameIndex));
				if (!std::strcmp(methodName, ".cctor"))
				{
					typeDef.bitfield |= (1 << (il2cpp::vm::kBitHasStaticConstructor - 1));
				}
				if (!std::strcmp(methodName, "Finalize"))
				{
					typeDef.bitfield |= (1 << (il2cpp::vm::kBitHasFinalizer - 1));
				}
				if (isInterface)
				{
					md.slot = m;
				}
				// TODO 可以考虑优化一下,将 signature在前一步存到暂时不用的 returnType里
				TbMethod methodData = _rawImage.ReadMethod(rawMethodStart + m + 1);

				BlobReader methodSigReader = _rawImage.GetBlobReaderByRawIndex(methodData.signature);
				uint32_t namedParamStart = md.parameterStart;
				uint32_t namedParamCount = md.parameterCount;

				uint32_t actualParamStart = (uint32_t)_params.size();
				ReadMethodDefSig(
					methodSigReader,
					GetGenericContainerByTypeDefinition(&typeDef),
					GetGenericContainerByRawIndex(DecodeMetadataIndex(md.genericContainerIndex)),
					md,
					_params);
				uint32_t actualParamCount = (uint32_t)_params.size() - actualParamStart;
				md.parameterStart = actualParamStart;
				md.parameterCount = actualParamCount;
				for (uint32_t paramRowIndex = namedParamStart + 1; paramRowIndex <= namedParamStart + namedParamCount; paramRowIndex++)
				{
					TbParam data = _rawImage.ReadParam(paramRowIndex);
					if (data.sequence > 0)
					{
						int32_t actualParamIndex = actualParamStart + data.sequence - 1;
						ParamDetail& paramDetail = _params[actualParamIndex];
						Il2CppParameterDefinition& pd = paramDetail.paramDef;
						IL2CPP_ASSERT(paramDetail.parameterIndex == data.sequence - 1);
						pd.nameIndex = EncodeWithIndex(data.name);
						pd.token = EncodeToken(TableType::PARAM, paramRowIndex);
						_paramRawIndex2ActualParamIndex[paramRowIndex - 1] = actualParamIndex;
						if (data.flags)
						{
							paramDetail.type.attrs = data.flags;
							pd.typeIndex = AddIl2CppTypeCache(paramDetail.type);
						}
					}
					else
					{
						// data.sequence == 0  is for returnType.
						// used for parent of CustomeAttributes of ReturnType
						// il2cpp not support ReturnType CustomAttributes. so we just ignore it.
					}
				}
			}
		}
	}

	void InterpreterImage::InitMethodImpls0()
	{
		const Table& miTb = _rawImage.GetTable(TableType::METHODIMPL);
		for (uint32_t i = 0; i < miTb.rowNum; i++)
		{
			TbMethodImpl data = _rawImage.ReadMethodImpl(i + 1);
			TypeDefinitionDetail& tdd = _typeDetails[data.classIdx - 1];
			Il2CppGenericContainer* gc = GetGenericContainerByTypeDefinition(tdd.typeDef);
			MethodImpl impl;
			ReadMethodRefInfoFromToken(gc, nullptr, DecodeMethodDefOrRefCodedIndexTableType(data.methodBody), DecodeMethodDefOrRefCodedIndexRowIndex(data.methodBody), impl.body);
			ReadMethodRefInfoFromToken(gc, nullptr, DecodeMethodDefOrRefCodedIndexTableType(data.methodDeclaration), DecodeMethodDefOrRefCodedIndexRowIndex(data.methodDeclaration), impl.declaration);
			tdd.methodImpls.push_back(impl);
		}
	}

	void InterpreterImage::InitProperties()
	{
		const Table& propertyMapTb = _rawImage.GetTable(TableType::PROPERTYMAP);
		const Table& propertyTb = _rawImage.GetTable(TableType::PROPERTY);
		_propeties.reserve(propertyTb.rowNum);

		for (uint32_t rowIndex = 1; rowIndex <= propertyTb.rowNum; rowIndex++)
		{
			TbProperty data = _rawImage.ReadProperty(rowIndex);
			_propeties.push_back({ _rawImage.GetStringFromRawIndex(data.name), data.flags, data.type, 0, 0
				, nullptr
				, { (StringIndex)EncodeWithIndex(data.name), kMethodIndexInvalid, kMethodIndexInvalid, (uint32_t)data.flags, EncodeToken(TableType::PROPERTY, rowIndex)}
				});
		}

		Il2CppTypeDefinition* last = nullptr;
		for (uint32_t rowIndex = 1; rowIndex <= propertyMapTb.rowNum; rowIndex++)
		{
			TbPropertyMap data = _rawImage.ReadPropertyMap(rowIndex);
			TypeDefinitionDetail& cur = _typeDetails[data.parent - 1];
			cur.typeDef->propertyStart = EncodeWithIndex(data.propertyList); // start from 1
			if (last != nullptr)
			{
				last->property_count = data.propertyList - DecodeMetadataIndex(last->propertyStart);
			}
			last = cur.typeDef;
		}
		if (last)
		{
			last->property_count = propertyTb.rowNum - DecodeMetadataIndex(last->propertyStart) + 1;
		}
	}

	void InterpreterImage::InitEvents()
	{
		const Table& eventMapTb = _rawImage.GetTable(TableType::EVENTMAP);
		const Table& eventTb = _rawImage.GetTable(TableType::EVENT);
		_events.reserve(eventTb.rowNum);

		for (uint32_t rowIndex = 1; rowIndex <= eventTb.rowNum; rowIndex++)
		{
			TbEvent data = _rawImage.ReadEvent(rowIndex);
			_events.push_back({ _rawImage.GetStringFromRawIndex(data.name), data.eventFlags, data.eventType, 0, 0, 0});
		}

		Il2CppTypeDefinition* last = nullptr;
		for (uint32_t rowIndex = 1; rowIndex <= eventMapTb.rowNum; rowIndex++)
		{
			TbEventMap data = _rawImage.ReadEventMap(rowIndex);
			TypeDefinitionDetail& cur = _typeDetails[data.parent - 1];
			cur.typeDef->eventStart = EncodeWithIndex(data.eventList); // start from 1
			if (last != nullptr)
			{
				last->event_count = data.eventList - DecodeMetadataIndex(last->eventStart);
			}
			last = cur.typeDef;
		}
		if (last)
		{
			last->event_count = eventTb.rowNum - DecodeMetadataIndex(last->eventStart) + 1;
		}
	}


	void InterpreterImage::InitMethodSemantics()
	{
		const Table& msTb = _rawImage.GetTable(TableType::METHODSEMANTICS);
		for (uint32_t rowIndex = 1; rowIndex <= msTb.rowNum; rowIndex++)
		{
			TbMethodSemantics data = _rawImage.ReadMethodSemantics(rowIndex);
			uint32_t method = data.method;
			uint16_t semantics = data.semantics;
			TableType tableType = DecodeHasSemanticsCodedIndexTableType(data.association);
			uint32_t propertyOrEventIndex = DecodeHasSemanticsCodedIndexRowIndex(data.association) - 1;
			if (semantics & (uint16_t)MethodSemanticsAttributes::Getter)
			{
				IL2CPP_ASSERT(tableType == TableType::PROPERTY);
				PropertyDetail& pd = _propeties[propertyOrEventIndex];
				pd.getterMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::Setter)
			{
				IL2CPP_ASSERT(tableType == TableType::PROPERTY);
				PropertyDetail& pd = _propeties[propertyOrEventIndex];
				pd.setterMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::AddOn)
			{
				IL2CPP_ASSERT(tableType == TableType::EVENT);
				EventDetail& ed = _events[propertyOrEventIndex];
				ed.addMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::RemoveOn)
			{
				IL2CPP_ASSERT(tableType == TableType::EVENT);
				EventDetail& ed = _events[propertyOrEventIndex];
				ed.removeMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::Fire)
			{
				IL2CPP_ASSERT(tableType == TableType::EVENT);
				EventDetail& ed = _events[propertyOrEventIndex];
				ed.fireMethodIndex = method;
			}
		}
	}

	struct EnclosingClassInfo
	{
		uint32_t enclosingTypeIndex; // rowIndex - 1
		std::vector<uint32_t> nestedTypeIndexs;
	};

	void InterpreterImage::InitNestedClass()
	{
		const Table& nestedClassTb = _rawImage.GetTable(TableType::NESTEDCLASS);
		_nestedTypeDefineIndexs.reserve(nestedClassTb.rowNum);
		std::vector<EnclosingClassInfo> enclosingTypes;

		for (uint32_t i = 0; i < nestedClassTb.rowNum; i++)
		{
			TbNestedClass data = _rawImage.ReadNestedClass(i + 1);
			Il2CppTypeDefinition& nestedType = _typesDefines[data.nestedClass - 1];
			Il2CppTypeDefinition& enclosingType = _typesDefines[data.enclosingClass - 1];
			if (enclosingType.nested_type_count == 0)
			{
				// 此行代码不能删，用于标识 enclosingTypes的index
				enclosingType.nestedTypesStart = (uint32_t)enclosingTypes.size();
				enclosingTypes.push_back({ data.enclosingClass - 1 });
			}
			++enclosingType.nested_type_count;
			enclosingTypes[enclosingType.nestedTypesStart].nestedTypeIndexs.push_back(data.nestedClass - 1);
			//_nestedTypeDefineIndexs.push_back(data.nestedClass - 1);
			nestedType.declaringTypeIndex = enclosingType.byvalTypeIndex;
		}

		for (auto& enclosingType : enclosingTypes)
		{
			Il2CppTypeDefinition& enclosingTypeDef = _typesDefines[enclosingType.enclosingTypeIndex];
			IL2CPP_ASSERT(enclosingType.nestedTypeIndexs.size() == (size_t)enclosingTypeDef.nested_type_count);
			enclosingTypeDef.nestedTypesStart = (NestedTypeIndex)_nestedTypeDefineIndexs.size();
			enclosingTypeDef.nested_type_count = (uint16_t)enclosingType.nestedTypeIndexs.size();
			_nestedTypeDefineIndexs.insert(_nestedTypeDefineIndexs.end(), enclosingType.nestedTypeIndexs.begin(), enclosingType.nestedTypeIndexs.end());
		}
	}

	void InterpreterImage::InitClassLayouts()
	{
		const Table& classLayoutTb = _rawImage.GetTable(TableType::CLASSLAYOUT);
		for (uint32_t i = 0; i < classLayoutTb.rowNum; i++)
		{
			TbClassLayout data = _rawImage.ReadClassLayout(i + 1);
			_classLayouts[data.parent - 1] = data;
			if (data.classSize > 0)
			{
				Il2CppTypeDefinitionSizes& typeSizes = _typeDetails[data.parent - 1].typeSizes;
				typeSizes.instance_size = data.classSize + sizeof(Il2CppObject);
			}
		}

		ClassFieldLayoutCalculator calculator(this);
		for (TypeDefinitionDetail& type : _typeDetails)
		{
			const Il2CppType* il2cppType = GetIl2CppTypeFromRawTypeDefIndex(type.index);
			calculator.CalcClassNotStaticFields(il2cppType);
		}

		for (TypeDefinitionDetail& type : _typeDetails)
		{
			const Il2CppType* il2cppType = GetIl2CppTypeFromRawTypeDefIndex(type.index);
			calculator.CalcClassStaticFields(il2cppType);
			ClassLayoutInfo* layout = calculator.GetClassLayoutInfo(il2cppType);
			Il2CppTypeDefinition* typeDef = type.typeDef;

			auto& sizes = type.typeSizes;
			sizes.native_size = layout->nativeSize;
			if (typeDef->genericContainerIndex == kGenericContainerIndexInvalid)
			{
				sizes.static_fields_size = layout->staticFieldsSize;
				sizes.thread_static_fields_size = layout->threadStaticFieldsSize;
			}
			else
			{
				sizes.static_fields_size = 0;
				sizes.thread_static_fields_size = 0;
			}
			if (sizes.instance_size == 0)
			{
				sizes.instance_size = layout->instanceSize;
			}
			int32_t fieldStart = DecodeMetadataIndex(typeDef->fieldStart);
			for (int32_t i = 0, end = typeDef->field_count; i < end ; i++)
			{
				FieldDetail& fd = _fieldDetails[fieldStart + i];
				FieldLayout& fieldLayout = layout->fields[i];
				if (fd.offset == 0)
				{
					fd.offset = fieldLayout.offset;
				}
				else if (fd.offset == THREAD_LOCAL_STATIC_MASK)
				{
					fd.offset = fieldLayout.offset;
				}
				else
				{
					IL2CPP_ASSERT(fd.offset == fieldLayout.offset);
					int a = 0;
				}
			}
		}
	}

	uint32_t InterpreterImage::AddIl2CppTypeCache(const Il2CppType& type)
	{
		auto it = _type2Indexs.find(type);
		if (it != _type2Indexs.end())
		{
			return it->second;
		}
		uint32_t encodeIndex = EncodeWithIndex((uint32_t)_types.size());
		_types.push_back(type);
		_type2Indexs.insert({ type, encodeIndex });
		return encodeIndex;
	}

	uint32_t InterpreterImage::AddIl2CppGenericContainers(Il2CppGenericContainer& geneContainer)
	{
		uint32_t index = (uint32_t)_genericContainers.size();
		_genericContainers.push_back(geneContainer);
		return EncodeWithIndex(index);
	}

	void InterpreterImage::InitClass()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);
		_classList.resize(typeDefTb.rowNum);
	}

	Il2CppClass* InterpreterImage::GetTypeInfoFromTypeDefinitionRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT(index < _classList.size());
		Il2CppClass* klass = _classList[index];
		if (klass)
		{
			return klass;
		}
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
		klass = _classList[index];
		if (klass)
		{
			return klass;
		}
		klass = il2cpp::vm::GlobalMetadata::FromTypeDefinition(EncodeWithIndex(index));
		IL2CPP_ASSERT(klass->interfaces_count <= klass->interface_offsets_count || _typesDefines[index].interfaceOffsetsStart == 0);
		il2cpp::os::Atomic::FullMemoryBarrier();
		_classList[index] = klass;
		return klass;
	}

	const Il2CppType* InterpreterImage::GetInterfaceFromIndex(const Il2CppClass* klass, TypeInterfaceIndex globalOffset)
	{
		IL2CPP_ASSERT((uint32_t)globalOffset < (uint32_t)_interfaceDefines.size());
		return &_types[_interfaceDefines[globalOffset]];
	}

	const Il2CppType* InterpreterImage::GetInterfaceFromOffset(const Il2CppClass* klass, TypeInterfaceIndex offset)
	{
		const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)(klass->typeMetadataHandle);
		IL2CPP_ASSERT(typeDef);
		return GetInterfaceFromOffset(typeDef, offset);
	}

	const Il2CppType* InterpreterImage::GetInterfaceFromOffset(const Il2CppTypeDefinition* typeDef, TypeInterfaceIndex offset)
	{
		uint32_t globalOffset = typeDef->interfacesStart + offset;
		IL2CPP_ASSERT(globalOffset < (uint32_t)_interfaceDefines.size());
		return &_types[_interfaceDefines[globalOffset]];
	}

	Il2CppInterfaceOffsetInfo InterpreterImage::GetInterfaceOffsetInfo(const Il2CppTypeDefinition* typeDefine, TypeInterfaceOffsetIndex index)
	{
		uint32_t globalIndex = DecodeMetadataIndex((uint32_t)(typeDefine->interfaceOffsetsStart + index));
		IL2CPP_ASSERT(globalIndex < (uint32_t)_interfaceOffsets.size());

		InterfaceOffsetInfo& offsetPair = _interfaceOffsets[globalIndex];
		return { offsetPair.type, (int32_t)offsetPair.offset };
	}

	Il2CppClass* InterpreterImage::GetNestedTypeFromOffset(const Il2CppTypeDefinition* typeDefine, TypeNestedTypeIndex offset)
	{
		uint32_t globalIndex = typeDefine->nestedTypesStart + offset;
		IL2CPP_ASSERT(globalIndex < (uint32_t)_nestedTypeDefineIndexs.size());
		uint32_t typeDefIndex = _nestedTypeDefineIndexs[globalIndex];
		IL2CPP_ASSERT(typeDefIndex < (uint32_t)_typesDefines.size());
		return il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)&_typesDefines[typeDefIndex]);
	}

	Il2CppClass* InterpreterImage::GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset)
	{
		return GetNestedTypeFromOffset((Il2CppTypeDefinition*)klass->typeMetadataHandle, offset);
	}

	Il2CppTypeDefinition* InterpreterImage::GetNestedTypes(Il2CppTypeDefinition* typeDefinition, void** iter)
	{
		if (_nestedTypeDefineIndexs.empty())
		{
			return nullptr;
		}
		const TypeDefinitionIndex* nestedTypeIndices = (const TypeDefinitionIndex*)(&_nestedTypeDefineIndexs[typeDefinition->nestedTypesStart]);

		if (!*iter)
		{
			if (typeDefinition->nested_type_count == 0)
				return NULL;

			*iter = (void*)(nestedTypeIndices);
			return &_typesDefines[nestedTypeIndices[0]];
		}

		TypeDefinitionIndex* nestedTypeAddress = (TypeDefinitionIndex*)*iter;
		nestedTypeAddress++;
		ptrdiff_t index = nestedTypeAddress - nestedTypeIndices;

		if (index < typeDefinition->nested_type_count)
		{
			*iter = nestedTypeAddress;
			return &_typesDefines[*nestedTypeAddress];
		}

		return NULL;
	}

	const Il2CppAssembly* InterpreterImage::GetReferencedAssembly(int32_t referencedAssemblyTableIndex, const Il2CppAssembly assembliesTable[], int assembliesCount)
	{
		auto& table = _rawImage.GetTable(TableType::ASSEMBLYREF);
		IL2CPP_ASSERT((uint32_t)referencedAssemblyTableIndex < table.rowNum);

		TbAssemblyRef assRef = _rawImage.ReadAssemblyRef(referencedAssemblyTableIndex + 1);
		const char* refAssName = _rawImage.GetStringFromRawIndex(assRef.name);
		const Il2CppAssembly* il2cppAssRef = il2cpp::vm::Assembly::GetLoadedAssembly(refAssName);
		if (!il2cppAssRef)
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetDllNotFoundException(refAssName));
		}
		return il2cppAssRef;
	}

	void InterpreterImage::ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret)
	{
		IL2CPP_ASSERT(rowIndex > 0);
		const FieldDetail& fd = GetFieldDetailFromRawIndex(rowIndex - 1);
		ret.containerType = *GetIl2CppTypeFromRawTypeDefIndex(DecodeMetadataIndex(fd.typeDefIndex));
		ret.field = &fd.fieldDef;
	}

	void InterpreterImage::GetClassAndMethodGenericContainerFromGenericContainerIndex(GenericContainerIndex idx, const Il2CppGenericContainer*& klassGc, const Il2CppGenericContainer*& methodGc)
	{
		Il2CppGenericContainer* gc = GetGenericContainerByRawIndex(DecodeMetadataIndex(idx));
		IL2CPP_ASSERT(gc);
		if (gc->is_method)
		{
			const Il2CppMethodDefinition* methodDef = GetMethodDefinitionFromRawIndex(DecodeMetadataIndex(gc->ownerIndex));
			klassGc = GetGenericContainerByTypeDefRawIndex(DecodeMetadataIndex(methodDef->declaringType));
			methodGc = GetGenericContainerByRawIndex(DecodeMetadataIndex(methodDef->genericContainerIndex));
		}
		else
		{
			klassGc = gc;
			methodGc = nullptr;
		}
	}

	void InterpreterImage::InitGenericParamConstraintDefs()
	{
		const Table& tb = _rawImage.GetTable(TableType::GENERICPARAMCONSTRAINT);
		_genericConstraints.resize(tb.rowNum);
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			uint32_t rowIndex = i + 1;
			TbGenericParamConstraint data = _rawImage.ReadGenericParamConstraint(rowIndex);
			Il2CppGenericParameter& genericParam = _genericParams[data.owner - 1];

			if (genericParam.constraintsCount == 0)
			{
				genericParam.constraintsStart = EncodeWithIndex(i);
			}
			++genericParam.constraintsCount;

			Il2CppType paramCons = {};

			const Il2CppGenericContainer* klassGc;
			const Il2CppGenericContainer* methodGc;
			GetClassAndMethodGenericContainerFromGenericContainerIndex(genericParam.ownerIndex, klassGc, methodGc);

			ReadTypeFromToken(klassGc, methodGc, DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.constraint), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.constraint), paramCons);
			_genericConstraints[i] = DecodeMetadataIndex(AddIl2CppTypeCache(paramCons));
		}
	}

	void InterpreterImage::InitGenericParamDefs0()
	{
		const Table& tb = _rawImage.GetTable(TableType::GENERICPARAM);
		_genericParams.resize(tb.rowNum);
	}

	void InterpreterImage::InitGenericParamDefs()
	{
		const Table& tb = _rawImage.GetTable(TableType::GENERICPARAM);
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			uint32_t rowIndex = i + 1;
			TbGenericParam data = _rawImage.ReadGenericParam(rowIndex);
			Il2CppGenericParameter& paramDef = _genericParams[i];
			paramDef.num = data.number;
			paramDef.flags = data.flags;
			paramDef.nameIndex = EncodeWithIndex(data.name);
			// constraintsStart 和 constrantsCount init at InitGenericParamConstrains() latter

			TableType ownerType = DecodeTypeOrMethodDefCodedIndexTableType(data.owner);
			uint32_t ownerIndex = DecodeTypeOrMethodDefCodedIndexRowIndex(data.owner);
			IL2CPP_ASSERT(ownerIndex > 0);
			Il2CppGenericContainer* geneContainer;
			int32_t interIndex = ownerIndex - 1;
			if (ownerType == TableType::TYPEDEF)
			{
				Il2CppTypeDefinition& typeDef = _typesDefines[interIndex];
				if (typeDef.genericContainerIndex == kGenericContainerIndexInvalid)
				{
					Il2CppGenericContainer c = {};
					c.ownerIndex = EncodeWithIndex(interIndex);
					c.is_method = false;
					typeDef.genericContainerIndex = AddIl2CppGenericContainers(c);
				}
				geneContainer = &_genericContainers[DecodeMetadataIndex(typeDef.genericContainerIndex)];
				paramDef.ownerIndex = typeDef.genericContainerIndex;
			}
			else
			{
				Il2CppMethodDefinition& methodDef = _methodDefines[interIndex];
				if (methodDef.genericContainerIndex == kGenericContainerIndexInvalid)
				{
					Il2CppGenericContainer c = {};
					c.ownerIndex = EncodeWithIndex(interIndex);
					c.is_method = true;
					methodDef.genericContainerIndex = AddIl2CppGenericContainers(c);
				}
				geneContainer = &_genericContainers[DecodeMetadataIndex(methodDef.genericContainerIndex)];
				paramDef.ownerIndex = methodDef.genericContainerIndex;
			}
			if (geneContainer->type_argc == 0)
			{
				geneContainer->genericParameterStart = EncodeWithIndex(i);
			}
			++geneContainer->type_argc;
		}
	}


	void InterpreterImage::InitInterfaces()
	{
		const Table& table = _rawImage.GetTable(TableType::INTERFACEIMPL);

		// interface中只包含直接继承的interface,不包括来自父类的
		// 此interface只在CastClass及Type.GetInterfaces()反射函数中
		// 发挥作用，不在callvir中发挥作用。
		// interfaceOffsets中包含了水平展开的所有interface(包括父类的)
		_interfaceDefines.resize(table.rowNum);
		uint32_t lastClassIdx = 0;
		for (uint32_t i = 0; i < table.rowNum; i++)
		{
			uint32_t rowIndex = i + 1;
			TbInterfaceImpl data = _rawImage.ReadInterfaceImpl(rowIndex);

			Il2CppTypeDefinition& typeDef = _typesDefines[data.classIdx - 1];
			Il2CppType intType = {};
			ReadTypeFromToken(GetGenericContainerByTypeDefinition(&typeDef), nullptr,
				DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.interfaceIdx), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.interfaceIdx), intType);
			_interfaceDefines[i] = DecodeMetadataIndex(AddIl2CppTypeCache(intType));
			if (typeDef.interfaces_count == 0)
			{
				typeDef.interfacesStart = (InterfacesIndex)i;
			}
			else
			{
				// 必须连续
				IL2CPP_ASSERT(data.classIdx == lastClassIdx);
			}
			++typeDef.interfaces_count;
			lastClassIdx = data.classIdx;
		}
	}

	void InterpreterImage::ComputeVTable(TypeDefinitionDetail* tdd)
	{
		Il2CppTypeDefinition& typeDef = *tdd->typeDef;
		if (IsInterface(typeDef.flags) || typeDef.interfaceOffsetsStart != 0)
		{
			return;
		}

		if (typeDef.parentIndex != kInvalidIndex)
		{
			const Il2CppType* parentType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef.parentIndex);
			const Il2CppTypeDefinition* parentTypeDef = GetUnderlyingTypeDefinition(parentType);
			if (IsInterpreterType(parentTypeDef) && parentTypeDef->interfaceOffsetsStart == 0)
			{
				IL2CPP_ASSERT(DecodeImageIndex(parentTypeDef->byvalTypeIndex) == this->GetIndex());
				int32_t typeDefIndex = GetTypeRawIndexByEncodedIl2CppTypeIndex(parentTypeDef->byvalTypeIndex);
				ComputeVTable(&_typeDetails[typeDefIndex]);
			}
		}

		const Il2CppType* type = GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(typeDef.byvalTypeIndex));
		VTableSetUp* typeTree = VTableSetUp::BuildByType(_cacheTrees, type);

		uint32_t offsetsStart = (uint32_t)_interfaceOffsets.size();

		auto& vms = typeTree->GetVirtualMethodImpls();
		IL2CPP_ASSERT(tdd->vtable.empty());
		tdd->vtable = vms;

		auto& interfaceOffsetInfos = typeTree->GetInterfaceOffsetInfos();
		for (auto ioi : interfaceOffsetInfos)
		{
			_interfaceOffsets.push_back({ ioi.type, ioi.offset });
		}

		typeDef.vtableStart = EncodeWithIndex(0);
		typeDef.vtable_count = (uint16_t)vms.size();
		typeDef.interfaceOffsetsStart = EncodeWithIndex(offsetsStart);
		typeDef.interface_offsets_count = (uint16_t)interfaceOffsetInfos.size();

		Il2CppClass* klass = _classList[tdd->index];
		IL2CPP_ASSERT(!klass);
	}

	void InterpreterImage::InitVTables()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);

		for (TypeDefinitionDetail& td : _typeDetails)
		{
			ComputeVTable(&td);
		}

		for (auto& e : _cacheTrees)
		{
			e.second->~VTableSetUp();
			IL2CPP_FREE(e.second);
		}
		Il2CppType2TypeDeclaringTreeMap temp;
		_cacheTrees.swap(temp);
	}

	// index => MethodDefinition -> DeclaringClass -> index - klass->methodStart -> MethodInfo*
	const MethodInfo* InterpreterImage::GetMethodInfoFromMethodDefinitionRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index <= _methodDefine2InfoCaches.size());
		if (_methodDefine2InfoCaches[index])
		{
			return _methodDefine2InfoCaches[index];
		}
		const Il2CppMethodDefinition* methodDefinition = GetMethodDefinitionFromRawIndex(index);
		const Il2CppTypeDefinition* typeDefinition = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(methodDefinition->declaringType);
		int32_t indexInClass = index - DecodeMetadataIndex(typeDefinition->methodStart);
		IL2CPP_ASSERT(indexInClass >= 0 && indexInClass < typeDefinition->method_count);
		Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)typeDefinition);
		il2cpp::vm::Class::SetupMethods(klass);
		// il2cpp::vm::Class::Init(klass);
		return _methodDefine2InfoCaches[index] = klass->methods[indexInClass];
	}

	const MethodInfo* InterpreterImage::GetMethodInfoFromMethodDefinition(const Il2CppMethodDefinition* methodDef)
	{
		uint32_t rawIndex = (uint32_t)(methodDef - &_methodDefines[0]);
		IL2CPP_ASSERT(rawIndex < (uint32_t)_methodDefines.size());
		return GetMethodInfoFromMethodDefinitionRawIndex(rawIndex);
	}

	// typeDef vTableSlot -> type virtual method index -> MethodDefinition*
	const Il2CppMethodDefinition* InterpreterImage::GetMethodDefinitionFromVTableSlot(const Il2CppTypeDefinition* typeDef, int32_t vTableSlot)
	{
		uint32_t typeDefIndex = GetTypeRawIndex(typeDef);
		IL2CPP_ASSERT(typeDefIndex < (uint32_t)_typeDetails.size());
		TypeDefinitionDetail& td = _typeDetails[typeDefIndex];

		IL2CPP_ASSERT(vTableSlot >= 0 && vTableSlot < (int32_t)td.vtable.size());
		VirtualMethodImpl& vmi = td.vtable[vTableSlot];
		return vmi.method;
	}

	const MethodInfo* InterpreterImage::GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot)
	{
		IL2CPP_ASSERT(!klass->generic_class);
		const Il2CppTypeDefinition* typeDef = (Il2CppTypeDefinition*)klass->typeMetadataHandle;
		//const Il2CppMethodDefinition* methodDef = GetMethodDefinitionFromVTableSlot((Il2CppTypeDefinition*)klass->typeMetadataHandle, vTableSlot);
		// FIX ME. why return null?
		//IL2CPP_ASSERT(methodDef);

		uint32_t typeDefIndex = GetTypeRawIndex(typeDef);
		IL2CPP_ASSERT(typeDefIndex < (uint32_t)_typeDetails.size());
		TypeDefinitionDetail& td = _typeDetails[typeDefIndex];

		IL2CPP_ASSERT(vTableSlot >= 0 && vTableSlot < (int32_t)td.vtable.size());
		VirtualMethodImpl& vmi = td.vtable[vTableSlot];
		if (vmi.method)
		{
			if (vmi.method->declaringType == EncodeWithIndex(typeDefIndex))
			{
				return il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle((Il2CppMetadataMethodDefinitionHandle)vmi.method);
			}
			else
			{
				Il2CppClass* implClass = il2cpp::vm::Class::FromIl2CppType(vmi.type);
				IL2CPP_ASSERT(implClass != klass);
				il2cpp::vm::Class::SetupMethods(implClass);
				for (uint32_t i = 0; i < implClass->method_count; i++)
				{
					const MethodInfo* implMethod = implClass->methods[i];
					if (implMethod->token == vmi.method->token)
					{
						return implMethod;
					}
				}
				RaiseExecutionEngineException("not find vtable method");
			}
		}
		return nullptr;
	}

	Il2CppMethodPointer InterpreterImage::GetAdjustorThunk(uint32_t token)
	{
		uint32_t methodIndex = DecodeTokenRowIndex(token) - 1;
		IL2CPP_ASSERT(methodIndex < (uint32_t)_methodDefines.size());
		const Il2CppMethodDefinition* methodDef = &_methodDefines[methodIndex];
		return IsInstanceMethod(methodDef) ? hybridclr::interpreter::InterpreterModule::GetAdjustThunkMethodPointer(methodDef) : nullptr;
	}

	Il2CppMethodPointer InterpreterImage::GetMethodPointer(uint32_t token)
	{
		uint32_t methodIndex = DecodeTokenRowIndex(token) - 1;
		IL2CPP_ASSERT(methodIndex < (uint32_t)_methodDefines.size());
		const Il2CppMethodDefinition* methodDef = &_methodDefines[methodIndex];
		return hybridclr::interpreter::InterpreterModule::GetMethodPointer(methodDef);
	}

	InvokerMethod InterpreterImage::GetMethodInvoker(uint32_t token)
	{
		uint32_t methodIndex = DecodeTokenRowIndex(token) - 1;
		IL2CPP_ASSERT(methodIndex < (uint32_t)_methodDefines.size());
		const Il2CppMethodDefinition* methodDef = &_methodDefines[methodIndex];
		return hybridclr::interpreter::InterpreterModule::GetMethodInvoker(methodDef);
	}


	Il2CppString* InterpreterImage::ReadSerString(BlobReader& reader)
	{
		byte b = reader.PeekByte();
		if (b == 0xFF)
		{
			reader.SkipByte();
			return nullptr;
		}
		else if (b == 0)
		{
			reader.SkipByte();
			return il2cpp::vm::String::Empty();
		}
		else
		{
			uint32_t len = reader.ReadCompressedUint32();
#if HYBRIDCLR_UNITY_2020
			return il2cpp::vm::String::NewLen((char*)reader.GetAndSkipCurBytes(len), len);
#else
			char* chars = (char*)reader.GetDataOfReadPosition();
			reader.SkipBytes(len);
			return il2cpp::vm::String::NewLen(chars, len);
#endif
		}
	}

#if HYBRIDCLR_UNITY_2021_OR_NEW
	bool InterpreterImage::ReadUTF8SerString(BlobReader& reader, std::string& s)
	{
		byte b = reader.PeekByte();
		if (b == 0xFF)
		{
			reader.SkipByte();
			return false;
		}
		else if (b == 0)
		{
			reader.SkipByte();
			s.clear();
			return true;
		}
		else
		{
			uint32_t len = reader.ReadCompressedUint32();
			char* chars = (char*)reader.GetDataOfReadPosition();
			reader.SkipBytes(len);
			s.assign(chars, len);
			return true;
		}
	}
#endif

	Il2CppReflectionType* InterpreterImage::ReadSystemType(BlobReader& reader)
	{
		Il2CppString* fullName = ReadSerString(reader);
		if (!fullName)
		{
			return nullptr;
		}
		Il2CppReflectionType* type = GetReflectionTypeFromName(fullName);
		if (!type)
		{
			std::string stdTypeName = il2cpp::utils::StringUtils::Utf16ToUtf8(fullName->chars);
			TEMP_FORMAT(errMsg, "CustomAttribute fixed arg type:System.Type fullName:'%s' not find", stdTypeName.c_str());
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
		}
		return type;
	}


	Il2CppObject* InterpreterImage::ReadBoxedValue(BlobReader& reader)
	{
		uint64_t obj = 0;
		Il2CppType kind = {};
		ReadCustomAttributeFieldOrPropType(reader, kind);
		ReadFixedArg(reader, &kind, &obj);
		Il2CppClass* valueType = il2cpp::vm::Class::FromIl2CppType(&kind);
		return il2cpp::vm::Object::Box(valueType, &obj);
	}

	void InterpreterImage::ReadFixedArg(BlobReader& reader, const Il2CppType* argType, void* data)
	{
		switch (argType->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		{
			*(byte*)data = reader.ReadByte();
			break;
		}
		case IL2CPP_TYPE_CHAR:
		{
			*(uint16_t*)data = reader.Read16();
			break;
		}
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		{
			*(byte*)data = reader.ReadByte();
			break;
		}
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		{
			*(uint16_t*)data = reader.Read16();
			break;
		}
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
		{
			*(uint32_t*)data = reader.Read32();
			break;
		}
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		{
			*(uint64_t*)data = reader.Read64();
			break;
		}
		case IL2CPP_TYPE_R4:
		{
			*(float*)data = reader.ReadFloat();
			break;
		}
		case IL2CPP_TYPE_R8:
		{
			*(double*)data = reader.ReadDouble();
			break;
		}
		case IL2CPP_TYPE_SZARRAY:
		{
			uint32_t numElem = reader.Read32();
			if (numElem != (uint32_t)-1)
			{
				Il2CppClass* arrKlass = il2cpp::vm::Class::FromIl2CppType(argType);
				Il2CppArray* arr = il2cpp::vm::Array::New(il2cpp::vm::Class::GetElementClass(arrKlass), numElem);
				for (uint16_t i = 0; i < numElem; i++)
				{
					ReadFixedArg(reader, argType->data.type, GET_ARRAY_ELEMENT_ADDRESS(arr, i, arr->klass->element_size));
				}
				*(void**)data = arr;
			}
			else
			{
				*(void**)data = nullptr;
			}
			break;
		}
		case IL2CPP_TYPE_STRING:
		{
			*(Il2CppString**)data = ReadSerString(reader);
			// FIXME memory barrier
			break;
		}
		case IL2CPP_TYPE_OBJECT:
		{
			*(Il2CppObject**)data = ReadBoxedValue(reader);
			// FIXME memory barrier
			break;
		}
		case IL2CPP_TYPE_CLASS:
		{
			Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(argType);
			if (!klass)
			{
				RaiseExecutionEngineException("type not find");
			}
			if (klass == il2cpp_defaults.object_class)
			{
				*(Il2CppObject**)data = ReadBoxedValue(reader);
			}
			else if (klass == il2cpp_defaults.systemtype_class)
			{
				*(Il2CppReflectionType**)data = ReadSystemType(reader);
			}
			else
			{
				TEMP_FORMAT(errMsg, "fixed arg type:%s.%s not support", klass->namespaze, klass->name);
				RaiseNotSupportedException(errMsg);
			}
			break;
		}
		case IL2CPP_TYPE_VALUETYPE:
		{
			Il2CppClass* valueType = il2cpp::vm::Class::FromIl2CppType(argType);
			IL2CPP_ASSERT(valueType->enumtype);
			ReadFixedArg(reader, &valueType->element_class->byval_arg, data);
			break;
		}
		case IL2CPP_TYPE_SYSTEM_TYPE:
		{
			*(Il2CppReflectionType**)data = ReadSystemType(reader);
			break;
		}
		case IL2CPP_TYPE_BOXED_OBJECT:
		{
			uint8_t fieldOrPropType = reader.ReadByte();
			IL2CPP_ASSERT(fieldOrPropType == 0x51);
			*(Il2CppObject**)data = ReadBoxedValue(reader);
			break;
		}
		case IL2CPP_TYPE_ENUM:
		{
			Il2CppClass* valueType = il2cpp::vm::Class::FromIl2CppType(argType);
			IL2CPP_ASSERT(valueType->enumtype);
			ReadFixedArg(reader, &valueType->element_class->byval_arg, data);
			break;
		}
		default:
		{
			RaiseExecutionEngineException("not support fixed argument type");
		}
		}
	}

	void InterpreterImage::ReadCustomAttributeFieldOrPropType(BlobReader& reader, Il2CppType& type)
	{
		type.type = (Il2CppTypeEnum)reader.ReadByte();

		switch (type.type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_CHAR:
		case IL2CPP_TYPE_I1:
		case IL2CPP_TYPE_U1:
		case IL2CPP_TYPE_I2:
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_I4:
		case IL2CPP_TYPE_U4:
		case IL2CPP_TYPE_I8:
		case IL2CPP_TYPE_U8:
		case IL2CPP_TYPE_R4:
		case IL2CPP_TYPE_R8:
		case IL2CPP_TYPE_STRING:
		{
			break;
		}
		case IL2CPP_TYPE_SZARRAY:
		{
			// FIXME MEMORY LEAK
			Il2CppType* eleType = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
			ReadCustomAttributeFieldOrPropType(reader, *eleType);
			type.data.type = eleType;
			break;
		}
		case IL2CPP_TYPE_ENUM:
		{
			Il2CppString* enumTypeName = ReadSerString(reader);

			Il2CppReflectionType* enumType = GetReflectionTypeFromName(enumTypeName);
			if (!enumType)
			{
				std::string stdStrName = il2cpp::utils::StringUtils::Utf16ToUtf8(enumTypeName->chars);
				TEMP_FORMAT(errMsg, "ReadCustomAttributeFieldOrPropType enum:'%s' not exists", stdStrName.c_str());
				RaiseExecutionEngineException(errMsg);
			}
			type = *enumType->type;
			break;
		}
		case IL2CPP_TYPE_SYSTEM_TYPE:
		{
			type = il2cpp_defaults.systemtype_class->byval_arg;
			break;
		}
		case IL2CPP_TYPE_BOXED_OBJECT:
		{
			type = il2cpp_defaults.object_class->byval_arg;
			break;
		}
		default:
		{
			TEMP_FORMAT(errMsg, "ReadCustomAttributeFieldOrPropType. image:%s unknown type:%d", GetIl2CppImage()->name, (int)type.type);
			RaiseBadImageException(errMsg);
		}
		}
	}

	void InterpreterImage::ReadMethodDefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppMethodDefinition& methodDef, std::vector<ParamDetail>& paramArr)
	{
		uint8_t rawSigFlags = reader.ReadByte();

		if (rawSigFlags & (uint8_t)MethodSigFlags::GENERIC)
		{
			//IL2CPP_ASSERT(false);
			uint32_t genParamCount = reader.ReadCompressedUint32();
			Il2CppGenericContainer* gc = GetGenericContainerByRawIndex(DecodeMetadataIndex(methodDef.genericContainerIndex));
			IL2CPP_ASSERT(gc->type_argc == genParamCount);
		}
		uint32_t paramCount = reader.ReadCompressedUint32();
		//IL2CPP_ASSERT(paramCount >= methodDef.parameterCount);

		Il2CppType returnType = {};
		ReadType(reader, klassGenericContainer, methodGenericContainer, returnType);
		methodDef.returnType = AddIl2CppTypeCache(returnType);

		int readParamNum = 0;
		for (; reader.NonEmpty(); )
		{
			ParamDetail curParam = {};
			curParam.type = {};
			ReadType(reader, klassGenericContainer, methodGenericContainer, curParam.type);
			curParam.parameterIndex = readParamNum++;
			curParam.methodDef = &methodDef;
			curParam.paramDef.typeIndex = AddIl2CppTypeCache(curParam.type);
			paramArr.push_back(curParam);
		}
		IL2CPP_ASSERT(readParamNum == (int)paramCount);
	}

	bool InterpreterImage::GetModuleIl2CppType(Il2CppType& resultType, uint32_t moduleRowIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound)
	{
		IL2CPP_ASSERT(moduleRowIndex == 1);
		uint32_t encodedNamespaceIndex = EncodeWithIndex(typeNamespace);
		uint32_t encodedNameIndex = EncodeWithIndex(typeName);
		for (TypeDefinitionDetail& type : _typeDetails)
		{
			if (type.typeDef->namespaceIndex == encodedNamespaceIndex && type.typeDef->nameIndex == encodedNameIndex)
			{
				GetIl2CppTypeFromTypeDefinition(type.typeDef, resultType);
				return true;
			}
		}
		resultType = {};
		if (!raiseExceptionIfNotFound)
		{
			return false;
		}
		const char* typeNameStr = _rawImage.GetStringFromRawIndex(typeName);
		const char* typeNamespaceStr = _rawImage.GetStringFromRawIndex(typeNamespace);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(
			CStringToStringView(typeNamespaceStr),
			CStringToStringView(typeNameStr),
			CStringToStringView(_il2cppImage->nameNoExt)));
		return false;
	}
}
}