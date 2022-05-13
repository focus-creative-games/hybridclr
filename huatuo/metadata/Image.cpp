#include "Image.h"

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
#include "metadata/FieldLayout.h"
#include "metadata/Il2CppTypeCompare.h"
#include "metadata/GenericMetadata.h"
#include "os/Atomic.h"

#include "MetadataModule.h"
#include "Tables.h"
#include "MetadataParser.h"
#include "MetadataUtil.h"
#include "TableReader.h"

#include "../interpreter/Engine.h"
#include "../interpreter/InterpreterModule.h"

namespace huatuo
{
namespace metadata
{

	void Image::InitBasic(Il2CppImage* image)
	{
		SetIl2CppImage(image);
		MetadataModule::RegisterImage(this);
	}

	void Image::BuildIl2CppAssembly(Il2CppAssembly* ass)
	{
		auto& table = _tables[(int)TableType::ASSEMBLYREF];

		ass->token = EncodeWithIndex(GetIndex());
		ass->referencedAssemblyStart = EncodeWithIndex(1);
		ass->referencedAssemblyCount = table.rowNum;

		TbAssembly data = TableReader::ReadAssembly(*this, 1);
		auto& aname = ass->aname;
		aname.hash_alg = data.hashAlgId;
		aname.major = data.majorVersion;
		aname.minor = data.minorVersion;
		aname.build = data.buildNumber;
		aname.revision = data.revisionNumber;
		aname.flags = data.flags;
		aname.public_key = GetBlobFromRawIndex(data.publicKey);
		aname.name = GetStringFromRawIndex(data.name);
		aname.culture = GetStringFromRawIndex(data.culture);
	}

	void Image::BuildIl2CppImage(Il2CppImage* image2)
	{
		image2->typeCount = GetTypeCount();
		image2->exportedTypeCount = GetExportedTypeCount();
		image2->customAttributeCount = _tables[(int)TableType::CUSTOMATTRIBUTE].rowNum;

		Il2CppImageGlobalMetadata* metadataImage = (Il2CppImageGlobalMetadata*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppImageGlobalMetadata));
		metadataImage->typeStart = EncodeWithIndex(0);
		metadataImage->customAttributeStart = EncodeWithIndex(0);
		metadataImage->entryPointIndex = EncodeWithIndexExcept0(_CLIHeader->entryPointToken);
		metadataImage->exportedTypeStart = EncodeWithIndex(0);
		metadataImage->image = image2;

		image2->metadataHandle = reinterpret_cast<Il2CppMetadataImageHandle>(metadataImage);

		image2->nameToClassHashTable = nullptr;
		image2->codeGenModule = nullptr;

		image2->token = EncodeWithIndex(0); // TODO
		image2->dynamic = 0;
	}

	void Image::InitRuntimeMetadatas()
	{
		IL2CPP_ASSERT(_tables[(int)TableType::EXPORTEDTYPE].rowNum == 0);

		il2cpp::os::FastAutoLock metaLock(&il2cpp::vm::g_MetadataLock);

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

		InitClassLayouts();

		InitTypeDefs_2();
		InitInterfaces();

		InitClass();

		InitVTables_1();
		InitVTables_2();
	}

	void Image::InitTypeDefs_0()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];
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
			TbTypeDef data = TableReader::ReadTypeDef(*this, rowIndex);

			cur = {};

			cur.genericContainerIndex = kGenericContainerIndexInvalid;
			cur.declaringTypeIndex = kTypeDefinitionIndexInvalid;
			cur.elementTypeIndex = kTypeDefinitionIndexInvalid;

			cur.token = EncodeToken(TableType::TYPEDEF, rowIndex);

			bool isValueType = data.extends && MetadataParser::IsValueTypeFromToken(*this, DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.extends), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.extends));
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

	void Image::InitTypeDefs_1()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];
		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			Il2CppTypeDefinition& last = _typesDefines[i > 0 ? i - 1 : 0];
			Il2CppTypeDefinition& cur = _typesDefines[i];
			uint32_t rowIndex = i + 1;
			TbTypeDef data = TableReader::ReadTypeDef(*this, rowIndex); // token from 1

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
				cur.field_count = (uint16_t)(_tables[(int)TableType::FIELD].rowNum - DecodeMetadataIndex(cur.fieldStart));
				cur.method_count = (uint16_t)(_tables[(int)TableType::METHOD].rowNum - DecodeMetadataIndex(cur.methodStart));
			}

			if (data.extends != 0)
			{
				Il2CppType parentType = {};
				MetadataParser::ReadTypeFromToken(*this, GetGenericContainerByTypeDefinition(&cur), nullptr, DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.extends), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.extends), parentType);

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

	void Image::InitTypeDefs_2()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			TbTypeDef data = TableReader::ReadTypeDef(*this, i + 1); // token from 1

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

	void Image::InitParamDefs()
	{
		Table& tb = _tables[(int)TableType::PARAM];

		// extra 16 for not name params
		_params.reserve(tb.rowNum + 16);
		//for (uint32_t i = 0; i < tb.rowNum; i++)
		//{
		//	uint32_t rowIndex = i + 1;
		//	Il2CppParameterDefinition& pd = _params[i].paramDef;
		//	TbParam data = TableReader::ReadParam(*this, rowIndex);

		//	pd.nameIndex = EncodeWithIndex(data.name);
		//	pd.token = EncodeToken(TableType::PARAM, rowIndex);
		//	// pd.typeIndex 在InitMethodDefs中解析signature后填充。
		//}
	}


	void Image::InitFieldDefs()
	{
		Table& fieldTb = _tables[(int)TableType::FIELD];
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
			TbField data = TableReader::ReadField(*this, rowIndex);

			BlobReader br = GetBlobReaderByRawIndex(data.signature);
			FieldRefSig frs;
			MetadataParser::ReadFieldRefSig(br, GetGenericContainerByTypeDefIndex(DecodeMetadataIndex(fd.typeDefIndex)), frs);
			frs.type.attrs = data.flags;

			//cur = {};
			cur.nameIndex = EncodeWithIndex(data.name);
			cur.token = EncodeToken(TableType::FIELD, rowIndex);
			cur.typeIndex = AddIl2CppTypeCache(frs.type);
		}
	}

	void Image::InitFieldLayouts()
	{
		Table& tb = _tables[(int)TableType::FIELDLAYOUT];
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			TbFieldLayout data = TableReader::ReadFieldLayout(*this, i + 1);
			_fieldDetails[data.field - 1].offset = sizeof(Il2CppObject) + data.offset;
		}
	}

	void Image::InitFieldRVAs()
	{
		Table& tb = _tables[(int)TableType::FIELDRVA];
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			TbFieldRVA data = TableReader::ReadFieldRVA(*this, i + 1);
			FieldDetail& fd = _fieldDetails[data.field - 1];
			fd.defaultValueIndex = (uint32_t)_fieldDefaultValues.size();

			Il2CppFieldDefaultValue fdv = {};
			fdv.fieldIndex = data.field - 1;
			fdv.typeIndex = fd.fieldDef.typeIndex;

			uint32_t dataImageOffset = (uint32_t)-1;
			bool ret = TranslateRVAToImageOffset(data.rva, dataImageOffset);
			IL2CPP_ASSERT(ret);
			fdv.dataIndex = (DefaultValueDataIndex)EncodeWithIndex(dataImageOffset);
			_fieldDefaultValues.push_back(fdv);
		}
	}

	void Image::InitBlittables()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];

		std::vector<bool> computFlags(typeDefTb.rowNum, false);

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			ComputeBlittable(&_typesDefines[i], computFlags);
		}
	}

	void Image::ComputeBlittable(Il2CppTypeDefinition* def, std::vector<bool>& computFlags)
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
				if (!huatuo::metadata::IsInstanceField(fieldType))
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

	void Image::InitConsts()
	{
		Table& tb = _tables[(int)TableType::CONSTANT];
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			TbConstant data = TableReader::ReadConstant(*this, i + 1);
			TableType parentType = DecodeHasConstantType(data.parent);
			uint32_t rowIndex = DecodeHashConstantIndex(data.parent);

			Il2CppType type = {};
			type.type = (Il2CppTypeEnum)data.type;
			TypeIndex dataTypeIndex = AddIl2CppTypeCache(type);

			switch (parentType)
			{
			case TableType::FIELD:
			{
				FieldDetail& fd = _fieldDetails[rowIndex - 1];
				fd.defaultValueIndex = (uint32_t)_fieldDefaultValues.size();

				Il2CppFieldDefaultValue fdv = {};
				fdv.fieldIndex = rowIndex - 1;
				fdv.typeIndex = dataTypeIndex;
				uint32_t dataImageOffset = (uint32_t)(GetBlobReaderByRawIndex(data.value).GetData() - _ptrRawData);
				fdv.dataIndex = (DefaultValueDataIndex)EncodeWithIndex(dataImageOffset);
				_fieldDefaultValues.push_back(fdv);
				break;
			}
			case TableType::PARAM:
			{
				ParamDetail& fd = _params[rowIndex - 1];
				fd.defaultValueIndex = (uint32_t)_paramDefaultValues.size();

				Il2CppParameterDefaultValue pdv = {};
				pdv.typeIndex = dataTypeIndex;
				pdv.parameterIndex = fd.parameterIndex;
				uint32_t dataImageOffset = (uint32_t)(GetBlobReaderByRawIndex(data.value).GetData() - _ptrRawData);
				pdv.dataIndex = (DefaultValueDataIndex)EncodeWithIndex(dataImageOffset);
				_paramDefaultValues.push_back(pdv);
				break;
			}
			case TableType::PROPERTY:
			{
				RaiseHuatuoNotSupportedException("not support property const");
				break;
			}
			default:
			{
				RaiseHuatuoExecutionEngineException("not support const TableType");
				break;
			}
			}
		}
	}

	void Image::InitCustomAttributes()
	{
		Table& tb = _tables[(int)TableType::CUSTOMATTRIBUTE];
		_tokenCustomAttributes.reserve(tb.rowNum);


		uint32_t threadStaticMethodToken = 0;
		Il2CppCustomAttributeTypeRange* curTypeRange = nullptr;
		for (uint32_t rowIndex = 1; rowIndex <= tb.rowNum; rowIndex++)
		{
			TbCustomAttribute data = TableReader::ReadCustomAttribute(*this, rowIndex);
			TableType parentType = DecodeHasCustomAttributeCodedIndexTableType(data.parent);
			uint32_t parentRowIndex = DecodeHasCustomAttributeCodedIndexRowIndex(data.parent);
			uint32_t token = EncodeToken(parentType, parentRowIndex);
			if (curTypeRange == nullptr || curTypeRange->token != token)
			{
				IL2CPP_ASSERT(_tokenCustomAttributes.find(token) == _tokenCustomAttributes.end());
				int32_t attributeStartIndex = EncodeWithIndex((int32_t)_customAttribues.size());
				int32_t handleIndex = (int32_t)_customAttributeHandles.size();
				_tokenCustomAttributes[token] = { handleIndex };
#ifdef HUATUO_UNITY_2021_OR_NEW
				_customAttributeHandles.push_back({ token, (uint32_t)attributeStartIndex});
#else
				_customAttributeHandles.push_back({ token, attributeStartIndex, 0 });
#endif
				curTypeRange = &_customAttributeHandles[handleIndex];
			}
#ifndef HUATUO_UNITY_2021_OR_NEW
			++curTypeRange->count;
#endif

			TableType ctorMethodTableType = DecodeCustomAttributeTypeCodedIndexTableType(data.type);
			uint32_t ctorMethodRowIndex = DecodeCustomAttributeTypeCodedIndexRowIndex(data.type);
			uint32_t ctorMethodToken = EncodeToken(ctorMethodTableType, ctorMethodRowIndex);
			//CustomAttribute ca = { ctorMethodToken, data.value };
			//ca.value = data.value;
			//MetadataParser::ReadMethodRefInfoFromToken(*this, nullptr, nullptr, , ca.attrCtorMethod);
			_customAttribues.push_back({ ctorMethodToken, data.value });

			if (parentType == TableType::FIELD)
			{
				// try set thread static flags
				if (threadStaticMethodToken == 0)
				{
					if (MetadataParser::IsThreadStaticCtorToken(*this, ctorMethodTableType, ctorMethodRowIndex))
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
#ifdef HUATUO_UNITY_2021_OR_NEW
		// add extra Il2CppCustomAttributeTypeRange for compute count
		_customAttributeHandles.push_back({ 0, EncodeWithIndex((int32_t)_customAttribues.size())});
#endif
		_customAttribtesCaches.resize(_tokenCustomAttributes.size());
	}

	CustomAttributesCache* Image::GenerateCustomAttributesCacheInternal(CustomAttributeIndex index)
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

		huatuo::interpreter::ExecutingInterpImageScope scope(huatuo::interpreter::InterpreterModule::GetCurrentThreadMachineState(), this->_il2cppImage);

		cache = (CustomAttributesCache*)IL2CPP_CALLOC(1, sizeof(CustomAttributesCache));
		int32_t count;
#ifdef HUATUO_UNITY_2021_OR_NEW
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
			MetadataParser::ReadMethodRefInfoFromToken(*this, nullptr, nullptr, DecodeTokenTableType(ca.ctorMethodToken), DecodeTokenRowIndex(ca.ctorMethodToken), mri);
			const MethodInfo* ctorMethod = GetMethodInfoFromMethodDef(&mri.containerType, mri.methodDef);
			IL2CPP_ASSERT(ctorMethod);
			Il2CppClass* klass = ctorMethod->klass;
			Il2CppObject* attr = il2cpp::vm::Object::New(klass);
			Il2CppArray* paramArr = nullptr;
			if (ca.value != 0)
			{
				BlobReader reader = GetBlobReaderByRawIndex(ca.value);
				MetadataParser::ConstructCustomAttribute(reader, attr, ctorMethod);
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

	void Image::InitMethodDefs0()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];
		Table& methodTb = _tables[(int)TableType::METHOD];

		_methodDefines.resize(methodTb.rowNum);
		for (Il2CppMethodDefinition& md : _methodDefines)
		{
			md.genericContainerIndex = kGenericContainerIndexInvalid;
		}
	}

	void Image::InitMethodDefs()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];
		Table& methodTb = _tables[(int)TableType::METHOD];

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

		int32_t paramTableRowNum = _tables[(int)TableType::PARAM].rowNum;
		for (uint32_t index = 0; index < methodTb.rowNum; index++)
		{
			Il2CppMethodDefinition& md = _methodDefines[index];
			uint32_t rowIndex = index + 1;
			TbMethod methodData = TableReader::ReadMethod(*this, rowIndex);

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
			if (methodData.rva > 0)
			{
				uint32_t methodImageOffset = 0;
				bool ret = TranslateRVAToImageOffset(methodData.rva, methodImageOffset);
				IL2CPP_ASSERT(ret);
				const byte* bodyStart = _ptrRawData + methodImageOffset;
				IL2CPP_ASSERT(bodyStart < _ptrRawDataEnd);
				byte bodyFlags = *bodyStart;
				byte smallFatFlags = bodyFlags & 0x3;

				if (smallFatFlags == (uint8_t)CorILMethodFormat::Tiny)
				{
					body.flags = (uint32_t)(bodyFlags & 0x3);
					body.ilcodes = bodyStart + 1;
					body.codeSize = (uint8_t)bodyFlags >> 2;
					body.maxStack = 8;
					body.localVarCount = 0;
					body.localVars = nullptr;
				}
				else
				{
					IL2CPP_ASSERT(smallFatFlags == (uint8_t)CorILMethodFormat::Fat);
					const CorILMethodFatHeader* methodHeader = (const CorILMethodFatHeader*)GetAlignBorder<4>(bodyStart);
					IL2CPP_ASSERT(methodHeader->size == 3);
					body.flags = methodHeader->flags;
					body.ilcodes = bodyStart + methodHeader->size * 4;
					body.codeSize = methodHeader->codeSize;
					body.maxStack = methodHeader->maxStack;

					if (methodHeader->localVarSigToken)
					{
						TbStandAloneSig sigData = TableReader::ReadStandAloneSig(*this, DecodeTokenRowIndex(methodHeader->localVarSigToken));
                        
                        BlobReader reader = GetBlobReaderByRawIndex(sigData.signature);
						MetadataParser::ReadLocalVarSig(reader,
							GetGenericContainerByTypeDefIndex(DecodeMetadataIndex(md.declaringType)),
							GetGenericContainerByRawIndex(DecodeMetadataIndex(md.genericContainerIndex)),
							body.localVars, body.localVarCount);
					}
				}
				if (body.flags & (uint8_t)CorILMethodFormat::MoreSects)
				{
					const byte* nextSection = (const byte*)GetAlignBorder<4>(body.ilcodes + body.codeSize);
					while (true)
					{
						byte kind = *nextSection;
						if (!(kind & (byte)CorILSecion::EHTable))
						{
							IL2CPP_ASSERT(false && "not support kinkd");
							break;
						}
						if (kind & (byte)CorILSecion::FatFormat)
						{
							CorILEHSectionHeaderFat* ehSec = (CorILEHSectionHeaderFat*)nextSection;
							uint32_t dataSize = (uint32_t)ehSec->dataSize0 | ((uint32_t)ehSec->dataSize1 << 8) | ((uint32_t)ehSec->dataSize2 << 16);
							IL2CPP_ASSERT(dataSize % 24 == 4);
							uint32_t ehCount = (dataSize - 4) / 24;
							body.exceptionClauses.reserve(ehCount);
							for (uint32_t i = 0; i < ehCount; i++)
							{
								CorILEHFat& eh = ehSec->clauses[i];
								IL2CPP_ASSERT(eh.flags >= (uint32_t)CorILExceptionClauseType::Exception && eh.flags <= (uint32_t)CorILExceptionClauseType::Fault);
								body.exceptionClauses.push_back({
									(CorILExceptionClauseType)eh.flags,
									eh.tryOffset,
									eh.tryLength,
									eh.handlerOffset,
									eh.handlerLength,
									eh.classTokenOrFilterOffset });
							}
							nextSection += dataSize;
						}
						else
						{
							CorILEHSectionHeaderSmall* ehSec = (CorILEHSectionHeaderSmall*)nextSection;
							IL2CPP_ASSERT(ehSec->dataSize % 12 == 4);
							uint32_t ehCount = (ehSec->dataSize - 4) / 12;
							body.exceptionClauses.reserve(ehCount);
							for (uint32_t i = 0; i < ehCount; i++)
							{
								CorILEHSmall& eh = ehSec->clauses[i];
								IL2CPP_ASSERT(eh.flags >= 0 && eh.flags <= 4);
								body.exceptionClauses.push_back({
									(CorILExceptionClauseType)eh.flags,
									eh.tryOffset,
									eh.tryLength,
									((uint32_t)eh.handlerOffset1 << 8) + eh.handlerOffset0,
									eh.handlerLength,
									eh.classTokenOrFilterOffset });
							}
							nextSection += ehSec->dataSize;
						}
						if (!(kind & (byte)CorILSecion::MoreSects))
						{
							break;
						}
					}
				}
			}
			else
			{
				body.ilcodes = nullptr;
				body.codeSize = 0;
			}
		}

		for (uint32_t i = 0, n = typeDefTb.rowNum; i < n; i++)
		{
			Il2CppTypeDefinition& typeDef = _typesDefines[i];
			uint32_t rawMethodStart = DecodeMetadataIndex(typeDef.methodStart);

			for (int m = 0; m < typeDef.method_count; m++)
			{
				Il2CppMethodDefinition& md = _methodDefines[rawMethodStart + m];
				const char* methodName = GetStringFromRawIndex(DecodeMetadataIndex(md.nameIndex));
				if (!std::strcmp(methodName, ".cctor"))
				{
					typeDef.bitfield |= (1 << (il2cpp::vm::kBitHasStaticConstructor - 1));
				}
				if (!std::strcmp(methodName, "Finalize"))
				{
					typeDef.bitfield |= (1 << (il2cpp::vm::kBitHasFinalizer - 1));
				}
				// TODO 可以考虑优化一下,将 signature在前一步存到暂时不用的 returnType里
				TbMethod methodData = TableReader::ReadMethod(*this, rawMethodStart + m + 1);

				BlobReader methodSigReader = GetBlobReaderByRawIndex(methodData.signature);
				uint32_t namedParamStart = md.parameterStart;
				uint32_t namedParamCount = md.parameterCount;

				uint32_t actualParamStart = (uint32_t)_params.size();
				MetadataParser::ReadMethodDefSig(
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
					TbParam data = TableReader::ReadParam(*this, paramRowIndex);
					if (data.sequence > 0)
					{
						ParamDetail& paramDetail = _params[actualParamStart + data.sequence - 1];
						Il2CppParameterDefinition& pd = paramDetail.paramDef;
						IL2CPP_ASSERT(paramDetail.parameterIndex == data.sequence - 1);
						pd.nameIndex = EncodeWithIndex(data.name);
						pd.token = EncodeToken(TableType::PARAM, paramRowIndex);
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

	void Image::InitMethodImpls0()
	{
		Table& miTb = _tables[(int)TableType::METHODIMPL];
		for (uint32_t i = 0; i < miTb.rowNum; i++)
		{
			TbMethodImpl data = TableReader::ReadMethodImpl(*this, i + 1);
			TypeDefinitionDetail& tdd = _typeDetails[data.classIdx - 1];
			Il2CppGenericContainer* gc = GetGenericContainerByTypeDefinition(tdd.typeDef);
			MethodImpl impl;
			MetadataParser::ReadMethodRefInfoFromToken(*this, gc, nullptr, DecodeMethodDefOrRefCodedIndexTableType(data.methodBody), DecodeMethodDefOrRefCodedIndexRowIndex(data.methodBody), impl.body);
			MetadataParser::ReadMethodRefInfoFromToken(*this, gc, nullptr, DecodeMethodDefOrRefCodedIndexTableType(data.methodDeclaration), DecodeMethodDefOrRefCodedIndexRowIndex(data.methodDeclaration), impl.declaration);
			tdd.methodImpls.push_back(impl);
		}
	}

	void Image::InitProperties()
	{
		Table& propertyMapTb = _tables[(int)TableType::PROPERTYMAP];
		Table& propertyTb = _tables[(int)TableType::PROPERTY];
		_propeties.reserve(propertyTb.rowNum);

		Il2CppTypeDefinition* last = nullptr;
		for (uint32_t rowIndex = 1; rowIndex <= propertyMapTb.rowNum; rowIndex++)
		{
			TbPropertyMap data = TableReader::ReadPropertyMap(*this, rowIndex);
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

		for (uint32_t rowIndex = 1; rowIndex <= propertyTb.rowNum; rowIndex++)
		{
			TbProperty data = TableReader::ReadProperty(*this, rowIndex);
			_propeties.push_back({ GetStringFromRawIndex(data.name), data.flags, data.type, 0, 0 });
		}
	}

	void Image::InitEvents()
	{
		Table& eventMapTb = _tables[(int)TableType::EVENTMAP];
		Table& eventTb = _tables[(int)TableType::EVENT];
		_events.reserve(eventTb.rowNum);

		Il2CppTypeDefinition* last = nullptr;
		for (uint32_t rowIndex = 1; rowIndex <= eventMapTb.rowNum; rowIndex++)
		{
			TbEventMap data = TableReader::ReadEventMap(*this, rowIndex);
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

		for (uint32_t rowIndex = 1; rowIndex <= eventTb.rowNum; rowIndex++)
		{
			TbEvent data = TableReader::ReadEvent(*this, rowIndex);
			_events.push_back({ GetStringFromRawIndex(data.name), data.eventFlags, data.eventType, 0, 0, 0 });
		}
	}


	void Image::InitMethodSemantics()
	{
		Table& msTb = _tables[(int)TableType::METHODSEMANTICS];
		for (uint32_t rowIndex = 1; rowIndex <= msTb.rowNum; rowIndex++)
		{
			TbMethodSemantics data = TableReader::ReadMethodSemantics(*this, rowIndex);
			uint32_t method = data.method;
			uint16_t semantics = data.semantics;
			TableType tableType = DecodeHasSemanticsCodedIndexTableType(data.association);
			uint32_t propertyOrEventIndex = DecodeHasSemanticsCodedIndexRowIndex(data.association) - 1;
			if (semantics & (uint16_t)MethodSemanticsAttributes::Getter)
			{
				IL2CPP_ASSERT(tableType == TableType::PROPERTY);
				_propeties[propertyOrEventIndex].getterMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::Setter)
			{
				IL2CPP_ASSERT(tableType == TableType::PROPERTY);
				_propeties[propertyOrEventIndex].setterMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::AddOn)
			{
				IL2CPP_ASSERT(tableType == TableType::EVENT);
				_events[propertyOrEventIndex].addMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::RemoveOn)
			{
				IL2CPP_ASSERT(tableType == TableType::EVENT);
				_events[propertyOrEventIndex].removeMethodIndex = method;
			}
			if (semantics & (uint16_t)MethodSemanticsAttributes::Fire)
			{
				IL2CPP_ASSERT(tableType == TableType::EVENT);
				_events[propertyOrEventIndex].fireMethodIndex = method;
			}
		}
	}

	struct EnclosingClassInfo
	{
		uint32_t enclosingTypeIndex; // rowIndex - 1
		std::vector<uint32_t> nestedTypeIndexs;
	};

	void Image::InitNestedClass()
	{
		Table& nestedClassTb = _tables[(int)TableType::NESTEDCLASS];
		_nestedTypeDefineIndexs.reserve(nestedClassTb.rowNum);
		std::vector<EnclosingClassInfo> enclosingTypes;

		for (uint32_t i = 0; i < nestedClassTb.rowNum; i++)
		{
			TbNestedClass data = TableReader::ReadNestedClass(*this, i + 1);
			Il2CppTypeDefinition& nestedType = _typesDefines[data.nestedClass - 1];
			Il2CppTypeDefinition& enclosingType = _typesDefines[data.enclosingClass - 1];
			if (enclosingType.nested_type_count == 0)
			{
				// 此行代码不能删，用于标识 enclosingTypes的index
				enclosingType.nestedTypesStart = (uint32_t)enclosingTypes.size();
				enclosingTypes.push_back({data.enclosingClass - 1});
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

	void Image::InitClassLayouts()
	{
		Table& classLayoutTb = _tables[(int)TableType::CLASSLAYOUT];
		for (uint32_t i = 0; i < classLayoutTb.rowNum; i++)
		{
			TbClassLayout data = TableReader::ReadClassLayout(*this, i + 1);
			Il2CppTypeDefinitionSizes& typeSizes = _typeDetails[data.parent - 1].typeSizes;
			typeSizes.instance_size = typeSizes.native_size = sizeof(Il2CppObject) + data.classSize;
		}
	}

	uint32_t Image::AddIl2CppTypeCache(Il2CppType& type)
	{
		//// TODO 优化
		uint32_t index = (uint32_t)_types.size();
		_types.push_back(type);
		return EncodeWithIndex(index);
	}

	uint32_t Image::AddIl2CppGenericContainers(Il2CppGenericContainer& geneContainer)
	{
		uint32_t index = (uint32_t)_genericContainers.size();
		_genericContainers.push_back(geneContainer);
		return EncodeWithIndex(index);
	}

	void Image::InitClass()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];
		_classList.resize(typeDefTb.rowNum);
	}

	Il2CppClass* Image::GetTypeInfoFromTypeDefinitionRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT(index < _classList.size());
		Il2CppClass* klass = _classList[index];
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

	const Il2CppType* Image::GetInterfaceFromOffset(const Il2CppClass* klass, TypeInterfaceIndex offset)
	{
		const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)(klass->typeMetadataHandle);
		IL2CPP_ASSERT(typeDef);
		return GetInterfaceFromOffset(typeDef, offset);
	}

	const Il2CppType* Image::GetInterfaceFromOffset(const Il2CppTypeDefinition* typeDef, TypeInterfaceIndex offset)
	{
		uint32_t globalOffset = typeDef->interfacesStart + offset;
		IL2CPP_ASSERT(globalOffset < (uint32_t)_interfaceDefines.size());
		return &_types[_interfaceDefines[globalOffset]];
	}

	Il2CppInterfaceOffsetInfo Image::GetInterfaceOffsetInfo(const Il2CppTypeDefinition* typeDefine, TypeInterfaceOffsetIndex index)
	{
		uint32_t globalIndex = DecodeMetadataIndex((uint32_t)(typeDefine->interfaceOffsetsStart + index));
		IL2CPP_ASSERT(globalIndex < (uint32_t)_interfaceOffsets.size());

		InterfaceOffsetInfo& offsetPair = _interfaceOffsets[globalIndex];
		return { offsetPair.type, (int32_t)offsetPair.offset };
	}

	Il2CppClass* Image::GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset)
	{
		uint32_t globalIndex = ((Il2CppTypeDefinition*)klass->typeMetadataHandle)->nestedTypesStart + offset;
		IL2CPP_ASSERT(globalIndex < (uint32_t)_nestedTypeDefineIndexs.size());
		uint32_t typeDefIndex = _nestedTypeDefineIndexs[globalIndex];
		IL2CPP_ASSERT(typeDefIndex < (uint32_t)_typesDefines.size());
		return il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)&_typesDefines[typeDefIndex]);
	}

	Il2CppTypeDefinition* Image::GetNestedTypes(Il2CppTypeDefinition* typeDefinition, void** iter)
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


	const MethodInfo* Image::FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod)
	{
		void* iter = nullptr;
		for (const MethodInfo* cur = nullptr; (cur = il2cpp::vm::Class::GetMethods(klass, &iter)) != nullptr; )
		{
			if (std::strcmp(cur->name, matchMethod->name)
				|| cur->parameters_count != matchMethod->parameters_count
				|| !il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(cur->return_type, matchMethod->return_type))
			{
				continue;
			}
			bool match = true;
			for (uint32_t i = 0; i < cur->parameters_count; i++)
			{
				if (!il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(GET_METHOD_PARAMETER_TYPE(cur->parameters[i]), GET_METHOD_PARAMETER_TYPE(matchMethod->parameters[i])))
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				return cur;
			}
		}
		return nullptr;
	}

	const void* Image::GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		TableType ttype = DecodeTokenTableType(token);
		uint32_t rowIndex = DecodeTokenRowIndex(token);
		switch (ttype)
		{
		case huatuo::metadata::TableType::TYPEREF:
		case huatuo::metadata::TableType::TYPEDEF:
		case huatuo::metadata::TableType::TYPESPEC:
		{
			// TODO cache
			Il2CppType* type = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
			MetadataParser::ReadTypeFromToken(*this, klassGenericContainer, methodGenericContainer, ttype, rowIndex, *type);
			if (genericContext)
			{
				type = const_cast<Il2CppType*>(TryInflateIfNeed(type, genericContext, true));
			}
			return type;
		}
		case huatuo::metadata::TableType::FIELD_POINTER:
		case huatuo::metadata::TableType::FIELD:
		{
			return GetFieldInfoFromToken(token, klassGenericContainer, methodGenericContainer, genericContext);
		}
		case huatuo::metadata::TableType::METHOD_POINTER:
		case huatuo::metadata::TableType::METHOD:
		case huatuo::metadata::TableType::METHODSPEC:
		{
			return GetMethodInfoFromToken(token, klassGenericContainer, methodGenericContainer, genericContext);
		}
		default:
		{
			RaiseHuatuoExecutionEngineException("GetRuntimeHandleFromToken invaild TableType");
			return nullptr;
		}
		}
	}

	Il2CppClass* Image::GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		auto key = std::tuple<uint32_t, const Il2CppGenericContext*>(token, genericContext);
		{
			il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
			auto it = _token2ResolvedDataCache.find(key);
			if (it != _token2ResolvedDataCache.end())
			{
				return (Il2CppClass*)it->second;
			}
		}
		Il2CppType originType = {};
		MetadataParser::ReadTypeFromToken(*this, klassGenericContainer, methodGenericContainer, DecodeTokenTableType(token), DecodeTokenRowIndex(token), originType);
		const Il2CppType* resultType = genericContext != nullptr ? il2cpp::metadata::GenericMetadata::InflateIfNeeded(&originType, genericContext, true) : &originType;
		Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(resultType);
		if (!klass)
		{
			TEMP_FORMAT(errMsg, "Image::GetClassFromToken token:%u class not exists", token);
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException());
		}
		// FIXME free resultType
		{
			il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
			_token2ResolvedDataCache.insert({ key, (void*)klass });
		}
		return klass;
	}


	// FIXME 此处bug较多，仍需要仔细检查

	const MethodInfo* GetMethodInfo(const Il2CppType* containerType, const Il2CppMethodDefinition* methodDef, const Il2CppGenericInst* instantiation, const Il2CppGenericContext* genericContext)
	{
		const Il2CppType* finalContainerType = TryInflateIfNeed(containerType, genericContext, true);
		const MethodInfo* method = GetMethodInfoFromMethodDef(containerType, methodDef);
		IL2CPP_ASSERT(method);
		// final genericContext = finalContainerType.class_inst + mri.instantiation
		if (instantiation)
		{
			const Il2CppGenericInst* finalClassIns = finalContainerType->type == IL2CPP_TYPE_GENERICINST ? finalContainerType->data.generic_class->context.class_inst : nullptr;
			const Il2CppGenericInst* finalMethodIns = instantiation;
			Il2CppGenericContext finalGenericContext = { finalClassIns, finalMethodIns };
			method = method->is_inflated ? method->genericMethod->methodDefinition : method;
			method = il2cpp::metadata::GenericMetadata::Inflate(method, &finalGenericContext);
			IL2CPP_ASSERT(method);
		}
		return method;
	}

	const MethodInfo* ResolveMethodInfo(const Il2CppType* type, const char* resolveMethodName, const MethodRefSig& resolveSig, const Il2CppGenericInst* genericInstantiation, const Il2CppGenericContext* genericContext)
	{
		if (type->type != IL2CPP_TYPE_ARRAY)
		{
			const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
			const Il2CppGenericContainer* klassGenericContainer = GetGenericContainerFromIl2CppType(type);
			const char* typeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
			for (uint32_t i = 0; i < typeDef->method_count; i++)
			{
				const Il2CppMethodDefinition* methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(typeDef->methodStart + i);
				const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex);
				if (std::strcmp(resolveMethodName, methodName) == 0 && IsMatchMethodSig(methodDef, resolveSig, klassGenericContainer, genericInstantiation ? genericInstantiation->type_argc : 0))
				{
					return GetMethodInfo(type, methodDef, genericInstantiation, genericContext);
				}
			}
		}
		else
		{
			IL2CPP_ASSERT(genericInstantiation == nullptr);
			Il2CppClass* arrayKlass = il2cpp::vm::Class::FromIl2CppType(type);
			il2cpp::vm::Class::SetupMethods(arrayKlass);
			//const Il2CppType* genericClassInstArgv[] = { &arrayKlass->element_class->byval_arg };
			const Il2CppType** genericClassInstArgv = genericContext && genericContext->class_inst ? genericContext->class_inst->type_argv : nullptr;
			const Il2CppType** genericMethodInstArgv = genericContext && genericContext->method_inst ? genericContext->method_inst->type_argv : nullptr;

			// FIXME MEMORY LEAK
			for (uint16_t i = 0; i < arrayKlass->method_count; i++)
			{
				const MethodInfo* method = arrayKlass->methods[i];
				if (std::strcmp(resolveMethodName, method->name) == 0 && IsMatchMethodSig(method, resolveSig, genericClassInstArgv, genericMethodInstArgv))
				{
					return method;
				}
			}
		}
		RaiseMethodNotFindException(type, resolveMethodName);
		return nullptr;
	}

	const MethodInfo* ReadMethodInfoFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer,
		const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, Il2CppGenericInst* genericInst, TableType tableType, uint32_t rowIndex)
	{
		IL2CPP_ASSERT(rowIndex > 0);
		switch (tableType)
		{
		case TableType::METHOD:
		{
			const Il2CppMethodDefinition* methodDef = image.GetMethodDefinitionFromRawIndex(rowIndex - 1);
			const Il2CppType* type = image.GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(image.GetTypeFromRawIndex(DecodeMetadataIndex(methodDef->declaringType))->byvalTypeIndex));
			return GetMethodInfo(type, methodDef, genericInst, genericContext);
		}
		case TableType::MEMBERREF:
		{
			ResolveMemberRef rmr = {};
			MetadataParser::ReadResolveMemberRefFromMemberRef(image, klassGenericContainer, methodGenericContainer, rowIndex, rmr);
			IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
			IL2CPP_ASSERT(rmr.signature.memberType == TableType::METHOD_POINTER);
			if (genericContext)
			{
				rmr.parent.type = *TryInflateIfNeed(&rmr.parent.type, genericContext, true);
			}
			return ResolveMethodInfo(&rmr.parent.type, rmr.name, rmr.signature.method, genericInst, genericContext);
		}
		case TableType::METHODSPEC:
		{
			TbMethodSpec methodSpec = TableReader::ReadMethodSpec(image, rowIndex);
			Il2CppGenericInst* genericInstantiation = nullptr;
			// FIXME! genericInstantiation memory leak
			MetadataParser::ReadMethodSpecInstantiation(image, methodSpec.instantiation, klassGenericContainer, methodGenericContainer, genericInstantiation);
			// FIXME memory leak
			genericInstantiation = TryInflateGenericInst(genericInstantiation, genericContext);

			TableType methodTableType = DecodeMethodDefOrRefCodedIndexTableType(methodSpec.method);
			uint32_t methodRowIndex = DecodeMethodDefOrRefCodedIndexRowIndex(methodSpec.method);
			switch (methodTableType)
			{
			case TableType::METHOD:
			{
				return ReadMethodInfoFromToken(image, klassGenericContainer, methodGenericContainer, genericContext, genericInstantiation, methodTableType, methodRowIndex);
			}
			case TableType::MEMBERREF:
			{
				return ReadMethodInfoFromToken(image, klassGenericContainer, methodGenericContainer, genericContext, genericInstantiation, methodTableType, methodRowIndex);
			}
			default:
			{
				RaiseBadImageException("ReadMethodSpec invaild TableType");
				return nullptr;
			}
			}
			break;
		}
		default:
		{
			RaiseBadImageException("ReadMethodInfoFromToken invaild TableType");
			return nullptr;
		}
		}
	}


	const MethodInfo* Image::GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		auto key = std::tuple<uint32_t, const Il2CppGenericContext*>(token, genericContext);
		{
			il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
			auto it = _token2ResolvedDataCache.find(key);
			if (it != _token2ResolvedDataCache.end())
			{
				return (const MethodInfo*)it->second;
			}
		}

		const MethodInfo* method = ReadMethodInfoFromToken(*this, klassGenericContainer, methodGenericContainer, genericContext,
			nullptr, DecodeTokenTableType(token), DecodeTokenRowIndex(token));

		//MethodRefInfo mri = {};
		//MetadataParser::ReadMethodRefInfoFromToken(*this, klassGenericContainer, methodGenericContainer, , , mri);
		//const Il2CppType* finalContainerType = TryInflateIfNeed(&mri.containerType, genericContext, true);
		//const MethodInfo* method = GetMethodInfoFromMethodDef(&mri.containerType, mri.methodDef);
		//// final genericContext = finalContainerType.class_inst + mri.instantiation
		//if (mri.instantiation)

		//{
		//	const Il2CppGenericInst* finalClassIns = finalContainerType->type == IL2CPP_TYPE_GENERICINST ? finalContainerType->data.generic_class->context.class_inst : nullptr;
		//	const Il2CppGenericInst* finalMethodIns = mri.instantiation;
		//	Il2CppGenericContext finalGenericContext = { finalClassIns, finalMethodIns };
		//	method = method->is_inflated ? method->genericMethod->methodDefinition : method;
		//	method = il2cpp::metadata::GenericMetadata::Inflate(method, &finalGenericContext);
		//}

		IL2CPP_ASSERT(method);
		{
			il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
			_token2ResolvedDataCache.insert({ key, (void*)method });
		}
		return method;
	}

	void Image::GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig)
	{
		MetadataParser::ReadStandAloneSig(*this, token, klassGenericContainer, methodGenericContainer, methodSig);
		if (genericContext)
		{
			// FIXME. memory leak
			methodSig.returnType = *TryInflateIfNeed(&methodSig.returnType, genericContext, true);
			for (uint32_t i = 0; i < methodSig.paramCount; i++)
			{
				methodSig.params[i] = *TryInflateIfNeed(methodSig.params + i, genericContext, true);
			}
		}
	}

	const FieldInfo* Image::GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
	{
		auto key = std::tuple<uint32_t, const Il2CppGenericContext*>(token, genericContext);
		{
			il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
			auto it = _token2ResolvedDataCache.find(key);
			if (it != _token2ResolvedDataCache.end())
			{
				return (const FieldInfo*)it->second;
			}
		}

		FieldRefInfo fri;
		MetadataParser::ReadFieldRefInfoFromToken(*this, klassGenericContainer, methodGenericContainer, DecodeTokenTableType(token), DecodeTokenRowIndex(token), fri);
		const Il2CppType* resultType = genericContext != nullptr ? il2cpp::metadata::GenericMetadata::InflateIfNeeded(&fri.containerType, genericContext, true) : &fri.containerType;
		const FieldInfo* fieldInfo = GetFieldInfoFromFieldRef(*this, *resultType, fri.field);
		{
			il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
			_token2ResolvedDataCache.insert({ key, (void*)fieldInfo });
		}
		return fieldInfo;
	}

	Il2CppString* Image::GetIl2CppUserStringFromRawIndex(StringIndex index)
	{
		il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
		Il2CppString* clrStr;
		if (_il2cppStringCache.TryGetValue(index, &clrStr))
		{
			return clrStr;
		}
		else
		{
			IL2CPP_ASSERT(index >= 0 && (uint32_t)index < _streamUS.size);
			const byte* str = _streamUS.data + index;
			uint32_t lengthSize;
			uint32_t stringLength = BlobReader::ReadCompressedUint32(str, lengthSize);

			Il2CppString* clrStr;
			if (stringLength == 0)
			{
				clrStr = il2cpp::vm::String::Empty();
			}
			else
			{
				str += lengthSize;
				IL2CPP_ASSERT(stringLength % 2 == 1);
				UserStringEncoding charEncoding = (UserStringEncoding)str[stringLength - 1];
				clrStr = il2cpp::vm::String::NewUtf16((const Il2CppChar*)str, (stringLength - 1) / 2);
			}
			_il2cppStringCache.Add(index, clrStr);
			return clrStr;
		}
	}

}
}