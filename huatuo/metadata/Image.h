#pragma once

#include <vector>
#include <unordered_map>
#include <tuple>

#include "vm/GlobalMetadataFileInternals.h"
#include "gc/GarbageCollector.h"
#include "gc/Allocator.h"
#include "gc/AppendOnlyGCHashMap.h"

#include "Coff.h"
#include "Tables.h"
#include "MetadataParser.h"
#include "VTableSetup.h"
#include "MetadataUtil.h"


namespace huatuo
{
namespace metadata
{

	enum class LoadImageErrorCode
	{
		OK = 0,
		BAD_IMAGE,
		NOT_IMPLEMENT,
	};

	struct InterfaceOffsetInfo
	{
		const Il2CppType* type;
		uint32_t offset;
	};


	struct TypeDefinitionDetail
	{
		uint32_t index; // from 0
		Il2CppTypeDefinition* typeDef;
		Il2CppTypeDefinitionSizes typeSizes;
		std::vector<VirtualMethodImpl> vtable;
		std::vector<MethodImpl> methodImpls;
	};

	struct FieldDetail
	{
		Il2CppFieldDefinition fieldDef;
		uint32_t typeDefIndex;
		uint32_t offset;
		uint32_t defaultValueIndex; // -1 for invalid
	};

	struct ParamDetail
	{
		Il2CppParameterDefinition paramDef;
		const Il2CppMethodDefinition* methodDef;
		//uint32_t methodIndex;
		uint32_t parameterIndex;
		uint32_t defaultValueIndex; // -1 for invalid
	};

	struct PropertyDetail
	{
		const char* name;
		uint16_t flags;
		uint32_t signatureBlobIndex;
		uint32_t getterMethodIndex; // start from 1;
		uint32_t setterMethodIndex;
	};

	struct EventDetail
	{
		const char* name;
		uint16_t eventFlags;
		uint32_t eventType; // TypeDefOrRef codedIndex
		uint32_t addMethodIndex; // start from 1
		uint32_t removeMethodIndex; // start from 1
		uint32_t fireMethodIndex; // start from 1;
	};

	struct CustomAttribute
	{
		uint32_t ctorMethodToken;
		uint32_t value;
	};

	struct CustomAtttributesInfo
	{
		int32_t typeRangeIndex;
	};

	typedef std::tuple<uint32_t, const Il2CppGenericContext*> TokenGenericContextType;

	struct TokenGenericContextTypeHash {
		size_t operator()(const TokenGenericContextType x) const noexcept {
			return std::get<0>(x) * 0x9e3779b9 + (size_t)std::get<1>(x);
		}
	};

	struct TokenGenericContextTypeEqual
	{
		bool operator()(const TokenGenericContextType a, const TokenGenericContextType b) const {
			return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
		}
	};

	class Image
	{
	public:

		Image(uint32_t imageIndex) : _index(imageIndex), _inited(false), _ptrRawData(nullptr), _imageLength(0), _ptrRawDataEnd(nullptr),
			_isDll(false), _PEHeader(nullptr), _PESectionHeaders(nullptr), _ptrMetaData(nullptr), _ptrMetaRoot(nullptr),
			_streamStringHeap{}, _streamUS{}, _streamBlobHeap{}, _streamGuidHeap{}, _streamTables{},
			_stringHeapStrNum(0), _userStringStrNum(0), _blobNum(0),
			_4byteStringIndex(false), _4byteGUIDIndex(false), _4byteBlobIndex(false)
		{

		}

		LoadImageErrorCode Load(const byte* imageData, size_t length);

		bool IsInitialized() const { return _inited; }

		uint32_t GetIndex() const
		{
			return _index;
		}

		const Il2CppImage* GetIl2CppImage() const
		{
			return _il2cppImage;
		}

		uint32_t EncodeWithIndex(uint32_t rawIndex) const
		{
			return EncodeImageAndMetadataIndex(_index, rawIndex);
		}

		uint32_t EncodeWithIndexExcept0(uint32_t rawIndex) const
		{
			return rawIndex != 0 ? EncodeImageAndMetadataIndex(_index, rawIndex) : 0;
		}

		uint32_t GetTypeCount() const
		{
			return _tables[(int)TableType::TYPEDEF].rowNum;
		}

		uint32_t GetExportedTypeCount() const
		{
			return _tables[(int)TableType::EXPORTEDTYPE].rowNum;
		}

		MethodBody& GetMethodBody(uint32_t token)
		{
			IL2CPP_ASSERT(DecodeTokenTableType(token) == TableType::METHOD);
			uint32_t rowIndex = DecodeTokenRowIndex(token);
			IL2CPP_ASSERT(rowIndex > 0 && rowIndex <= (uint32_t)_methodBodies.size());
			return _methodBodies[rowIndex - 1];
		}

		// type index start from 0, difference with table index...
		Il2CppMetadataTypeHandle GetAssemblyTypeHandleFromRawIndex(AssemblyTypeIndex index) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(index) == 0);
			IL2CPP_ASSERT(index >= 0 && (size_t)index < _typesDefines.size());
			return (Il2CppMetadataTypeHandle)&_typesDefines[index];
		}

		Il2CppMetadataTypeHandle GetAssemblyExportedTypeHandleFromRawIndex(AssemblyTypeIndex index) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(index) == 0);
			IL2CPP_ASSERT(index >= 0 && (size_t)index < _typesDefines.size());
			return (Il2CppMetadataTypeHandle)&_exportedTypeDefines[index];
		}

		const Il2CppTypeDefinitionSizes* GetTypeDefinitionSizesFromRawIndex(TypeDefinitionIndex index)
		{
			IL2CPP_ASSERT(index < _typeDetails.size());
			return &_typeDetails[index].typeSizes;
		}

		const char* GetStringFromRawIndex(StringIndex index) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(index) == 0);
			IL2CPP_ASSERT(index >= 0 && (uint32_t)index < _streamStringHeap.size);
			return (const char*)(_streamStringHeap.data + index);
		}

		Il2CppString* GetIl2CppUserStringFromRawIndex(StringIndex index);

		const byte* GetBlobFromRawIndex(StringIndex index) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(index) == 0);
			IL2CPP_ASSERT(index >= 0 && (size_t)index < _streamBlobHeap.size);
			return _streamBlobHeap.data + index;
		}

		uint32_t GetTypeRawIndex(const Il2CppTypeDefinition* typeDef) const
		{
			return (uint32_t)(typeDef - &_typesDefines[0]);
		}

		const Il2CppTypeDefinition* GetTypeFromRawIndex(uint32_t index) const
		{
			IL2CPP_ASSERT((size_t)index < _typesDefines.size());
			return &_typesDefines[index];
		}

		const Il2CppType* GetIl2CppTypeFromRawIndex(uint32_t index) const
		{
			IL2CPP_ASSERT((size_t)index < _types.size());
			return &_types[index];
		}

		const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index)
		{
			IL2CPP_ASSERT(index < (uint32_t)_typeDetails.size());
			return &_types[DecodeMetadataIndex(_typeDetails[index].typeDef->byvalTypeIndex)];
		}

		const Il2CppFieldDefinition* GetFieldDefinitionFromRawIndex(uint32_t index)
		{
			IL2CPP_ASSERT(index < (uint32_t)_fieldDetails.size());
			return &(_fieldDetails[index].fieldDef);
		}

		const FieldDetail& GetFieldDetailFromRawIndex(uint32_t index)
		{
			IL2CPP_ASSERT(index < (uint32_t)_fieldDetails.size());
			return _fieldDetails[index];
		}

		const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index)
		{
			IL2CPP_ASSERT((size_t)index < _methodDefines.size());
			return &_methodDefines[index];
		}

		const Il2CppGenericParameter* GetGenericParameterByRawIndex(const Il2CppGenericContainer* container, uint32_t index)
		{
			IL2CPP_ASSERT(container->genericParameterStart + index < (uint32_t)_genericParams.size());
			return &_genericParams[container->genericParameterStart + index];
		}

		Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index)
		{
			if (index != kGenericContainerIndexInvalid)
			{
				IL2CPP_ASSERT(index < (uint32_t)_genericContainers.size());
				return &_genericContainers[index];
			}
			return nullptr;
		}

		Il2CppGenericContainer* GetGenericContainerByTypeDefinition(const Il2CppTypeDefinition* typeDef)
		{
			GenericContainerIndex idx = DecodeMetadataIndex(typeDef->genericContainerIndex);
			if (idx != kGenericContainerIndexInvalid)
			{
				IL2CPP_ASSERT(idx < (GenericContainerIndex)_genericContainers.size());
				return &_genericContainers[idx];
			}
			return nullptr;
		}

		Il2CppGenericContainer* GetGenericContainerByTypeDefIndex(int32_t typeDefIndex)
		{
			IL2CPP_ASSERT(typeDefIndex < (int32_t)_typeDetails.size());
			return GetGenericContainerByTypeDefinition(&_typesDefines[typeDefIndex]);
		}

		const std::vector<MethodImpl>& GetTypeMethodImplByTypeDefinition(const Il2CppTypeDefinition* typeDef)
		{
			uint32_t index = (uint32_t)(typeDef - &_typesDefines[0]);
			IL2CPP_ASSERT(index < (uint32_t)_typeDetails.size());
			return _typeDetails[index].methodImpls;
		}

		Il2CppClass* GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset);

		const MethodInfo* GetMethodInfoFromMethodDefinitionRawIndex(uint32_t index);
		const MethodInfo* GetMethodInfoFromMethodDefinition(const Il2CppMethodDefinition* methodDef);
		const Il2CppMethodDefinition* GetMethodDefinitionFromVTableSlot(const Il2CppTypeDefinition* typeDefine, int32_t vTableSlot);
		const MethodInfo* GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot);

		Il2CppTypeDefinition* GetNestedTypes(Il2CppTypeDefinition* handle, void** iter);
		const FieldInfo* GetFieldInfoFromMemberRef(const Il2CppType& type, uint32_t name, const Il2CppType& fieldType);

		Il2CppMethodPointer GetAdjustorThunk(uint32_t token);
		Il2CppMethodPointer GetMethodPointer(uint32_t token);
		InvokerMethod GetMethodInvoker(uint32_t token);

		const Il2CppParameterDefinition* GetParameterDefinitionFromIndex(uint32_t index)
		{
			IL2CPP_ASSERT((size_t)index < _params.size());
			return &_params[index].paramDef;
		}

		uint32_t GetFieldOffset(const Il2CppClass* klass, int32_t fieldIndexInType, FieldInfo* field);

		const Il2CppFieldDefaultValue* GetFieldDefaultValueEntryByRawIndex(uint32_t index)
		{
			IL2CPP_ASSERT(index < (uint32_t)_fieldDetails.size());
			uint32_t fdvIndex = _fieldDetails[index].defaultValueIndex;
			IL2CPP_ASSERT(fdvIndex != kDefaultValueIndexNull);
			return &_fieldDefaultValues[fdvIndex];
		}

		const uint8_t* GetFieldOrParameterDefalutValueByRawIndex(uint32_t index)
		{
			return _ptrRawData + index;
		}

		Il2CppMetadataPropertyInfo GetPropertyInfo(const Il2CppClass* klass, TypePropertyIndex index)
		{
			const Il2CppTypeDefinition* typeDef = (Il2CppTypeDefinition*)klass->typeMetadataHandle;
			IL2CPP_ASSERT(typeDef->propertyStart);
			uint32_t rowIndex = DecodeMetadataIndex(typeDef->propertyStart) + index;
			PropertyDetail& pd = _propeties[rowIndex - 1];
			uint32_t baseMethodIdx = DecodeMetadataIndex(typeDef->methodStart) + 1;
			const MethodInfo* getter = pd.getterMethodIndex ? klass->methods[pd.getterMethodIndex - baseMethodIdx] : nullptr;
			const MethodInfo* setter = pd.setterMethodIndex ? klass->methods[pd.setterMethodIndex - baseMethodIdx] : nullptr;
			return { pd.name, getter, setter, pd.flags, EncodeToken(TableType::PROPERTY, rowIndex) };
		}

		Il2CppMetadataEventInfo GetEventInfo(const Il2CppClass* klass, TypeEventIndex index)
		{
			const Il2CppTypeDefinition* typeDef = (Il2CppTypeDefinition*)klass->typeMetadataHandle;
			IL2CPP_ASSERT(typeDef->eventStart);
			uint32_t rowIndex = DecodeMetadataIndex(typeDef->eventStart) + index;
			EventDetail& pd = _events[rowIndex - 1];
			uint32_t baseMethodIdx = DecodeMetadataIndex(typeDef->methodStart) + 1;
			const MethodInfo* addOn = pd.addMethodIndex ? klass->methods[pd.addMethodIndex - baseMethodIdx] : nullptr;
			const MethodInfo* removeOn = pd.removeMethodIndex ? klass->methods[pd.removeMethodIndex - baseMethodIdx] : nullptr;
			const MethodInfo* raiseOn = pd.fireMethodIndex ? klass->methods[pd.fireMethodIndex - baseMethodIdx] : nullptr;
			return { pd.name, &klass->byval_arg, addOn, removeOn, raiseOn, EncodeToken(TableType::EVENT, rowIndex) };
		}

		Il2CppMetadataCustomAttributeHandle GetCustomAttributeTypeToken(uint32_t token)
		{
			auto it = _tokenCustomAttributes.find(token);
			return it != _tokenCustomAttributes.end() ? (Il2CppMetadataCustomAttributeHandle)&_customAttributeHandles[it->second.typeRangeIndex] : nullptr;
		}

		CustomAttributeIndex GetCustomAttributeIndex(uint32_t token)
		{
			auto it = _tokenCustomAttributes.find(token);
			return it != _tokenCustomAttributes.end() ? it->second.typeRangeIndex : kCustomAttributeIndexInvalid;
		}

		std::tuple<void*, void*> GetCustomAttributeDataRange(uint32_t token)
		{
			const Il2CppCustomAttributeTypeRange* dataRangeCur = (const Il2CppCustomAttributeTypeRange*)GetCustomAttributeTypeToken(token);
			CustomAttributeIndex curIndex = DecodeMetadataIndex(GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(*dataRangeCur));
			CustomAttributeIndex nextIndex = DecodeMetadataIndex(GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(*(dataRangeCur + 1)));
			CustomAttribute& curCa = _customAttribues[curIndex];
			CustomAttribute& nextCa = _customAttribues[nextIndex];
			return std::make_tuple<void*, void*>((void*)GetBlobReaderByRawIndex(curCa.value).GetData(), (void*)GetBlobReaderByRawIndex(nextCa.value).GetData());
		}

		CustomAttributesCache* GenerateCustomAttributesCacheInternal(const Il2CppCustomAttributeTypeRange* typeRange)
		{
			CustomAttributeIndex index = (CustomAttributeIndex)(typeRange - (const Il2CppCustomAttributeTypeRange*)&_customAttributeHandles[0]);
			IL2CPP_ASSERT(index >= 0 && index < (CustomAttributeIndex)_customAttributeHandles.size());
			return GenerateCustomAttributesCacheInternal(index);
		}

		bool HasAttribute(uint32_t token, Il2CppClass* attribute)
		{
			CustomAttributeIndex index = GetCustomAttributeIndex(token);
			if (index == kCustomAttributeIndexInvalid)
			{
				return false;
			}
			CustomAttributesCache* attrCache = GenerateCustomAttributesCacheInternal(index);
			for (int i = 0; i < attrCache->count; i++)
			{
				Il2CppObject* attrObj = attrCache->attributes[i];
				if (il2cpp::vm::Class::IsAssignableFrom(attribute, attrObj->klass))
				{
					return true;
				}
			}
			return false;
		}

		CustomAttributesCache* GenerateCustomAttributesCacheInternal(CustomAttributeIndex index);

		Il2CppClass* GetTypeInfoFromTypeDefinitionRawIndex(uint32_t index);

		const Il2CppType* GetInterfaceFromOffset(const Il2CppClass* klass, TypeInterfaceIndex offset);
		const Il2CppType* GetInterfaceFromOffset(const Il2CppTypeDefinition* typeDefine, TypeInterfaceIndex offset);

		Il2CppInterfaceOffsetInfo GetInterfaceOffsetInfo(const Il2CppTypeDefinition* typeDefine, TypeInterfaceOffsetIndex index);

		Il2CppClass* GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const MethodInfo* GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const FieldInfo* GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const void* GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		void GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig);

		const MethodInfo* FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod);

		uint32_t AddIl2CppTypeCache(Il2CppType& type);

		uint32_t AddIl2CppGenericContainers(Il2CppGenericContainer& geneContainer);

		BlobReader GetBlobReaderByRawIndex(uint32_t rawIndex)
		{
			IL2CPP_ASSERT(DecodeImageIndex(rawIndex) == 0);
			const byte* buf = _streamBlobHeap.data + rawIndex;
			return MetadataParser::DecodeBlob(*this, buf);
		}

		const byte* GetTableRowPtr(TableType type, uint32_t rawIndex)
		{
			auto& tb = _tables[(int)type];
			IL2CPP_ASSERT(rawIndex > 0 && rawIndex <= tb.rowNum);
			return tb.data + tb.rowMetaDataSize * (rawIndex - 1);
		}

		const Table& GetTable(TableType type) const
		{
			return _tables[(int)type];
		}

		const std::vector<ColumnOffsetSize>& GetRowSchema(TableType type) const
		{
			return _tableRowMetas[(int)type];
		}

		void InitBasic(Il2CppImage* image);
		void BuildIl2CppImage(Il2CppImage* image);
		void BuildIl2CppAssembly(Il2CppAssembly* assembly);

		void InitRuntimeMetadatas();
	private:

		void InitTypeDefs_0();
		void InitTypeDefs_1();
		void InitTypeDefs_2();
		void InitConsts();

		void InitClass();

		void InitParamDefs();
		void InitGenericParamConstraintDefs();
		void InitGenericParamDefs0();
		void InitGenericParamDefs();
		void InitFieldDefs();
		void InitFieldLayouts();
		void InitFieldRVAs();
		void InitMethodDefs0();
		void InitMethodDefs();
		void InitMethodImpls0();
		void InitNestedClass();
		void InitClassLayouts();
		void InitCustomAttributes();
		void InitProperties();
		void InitEvents();
		void InitMethodSemantics();
		void InitInterfaces();
		void InitVtables();

		void SetIl2CppImage(Il2CppImage* image)
		{
			_il2cppImage = image;
		}

		bool TranslateRVAToImageOffset(uint32_t rvaOffset, uint32_t& imageOffset);

		LoadImageErrorCode LoadStreams();

		LoadImageErrorCode LoadTables();

		void BuildTableRowMetas();

		uint32_t ComputTableRowMetaDataSize(TableType tableIndex);

		uint32_t ComputStringIndexByte() { return _4byteStringIndex ? 4 : 2; }

		uint32_t ComputGUIDIndexByte()
		{
			return _4byteGUIDIndex ? 4 : 2;
		}

		uint32_t ComputBlobIndexByte()
		{
			return _4byteBlobIndex ? 4 : 2;
		}

		uint32_t ComputTableIndexByte(TableType tableIndex)
		{
			return _tables[(int)tableIndex].rowNum < 65536 ? 2 : 4;
		}

		uint32_t ComputIndexByte(uint32_t maxRowNum, uint32_t tagBitNum)
		{
			return (maxRowNum << tagBitNum) < 65536 ? 2 : 4;
		}

		uint32_t GetTableRowNum(TableType tableIndex)
		{
			return _tables[(int)tableIndex].rowNum;
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, uint32_t tagBitNum)
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, TableType t3, uint32_t tagBitNum)
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			n = std::max(n, GetTableRowNum(t3));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, TableType t3, TableType t4, uint32_t tagBitNum)
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			n = std::max(n, GetTableRowNum(t3));
			n = std::max(n, GetTableRowNum(t4));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, TableType t3, TableType t4, TableType t5, uint32_t tagBitNum)
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			n = std::max(n, GetTableRowNum(t3));
			n = std::max(n, GetTableRowNum(t4));
			n = std::max(n, GetTableRowNum(t5));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(const TableType* ts, int num, uint32_t tagBitNum)
		{
			uint32_t n = 0;
			for (int i = 0; i < num; i++)
			{
				n = std::max(n, GetTableRowNum(ts[i]));
			}
			return ComputIndexByte(n, tagBitNum);
		}

		bool _inited;

		Il2CppImage* _il2cppImage;

		const uint32_t _index;

		const byte* _ptrRawData;
		uint32_t _imageLength;
		const byte* _ptrRawDataEnd;

		bool _isDll;
		const PEHeader* _PEHeader;
		const CLIHeader* _CLIHeader;
		const PESectionHeader* _PESectionHeaders;
		const MetadataRootPartial* _ptrMetaRoot;

		const byte* _ptrMetaData;

		CliStream _streamStringHeap;
		CliStream _streamUS;
		CliStream _streamBlobHeap;
		CliStream _streamGuidHeap;
		CliStream _streamTables;

		uint32_t _stringHeapStrNum;

		uint32_t _userStringStrNum;
		uint32_t _blobNum;


		bool _4byteStringIndex;
		bool _4byteGUIDIndex;
		bool _4byteBlobIndex;

		Table _tables[TABLE_NUM];
		std::vector<ColumnOffsetSize> _tableRowMetas[TABLE_NUM];

		std::vector<TypeDefinitionDetail> _typeDetails;
		std::vector<Il2CppTypeDefinition> _typesDefines;
		std::vector<Il2CppTypeDefinition> _exportedTypeDefines;

		std::vector<Il2CppType> _types;
		std::vector<TypeIndex> _interfaceDefines;
		std::vector<InterfaceOffsetInfo> _interfaceOffsets;

		std::vector<const MethodInfo*> _methodDefine2InfoCaches;
		std::vector<Il2CppMethodDefinition> _methodDefines;
		std::vector<MethodBody> _methodBodies;

		std::vector<ParamDetail> _params;
		std::vector<Il2CppParameterDefaultValue> _paramDefaultValues;

		std::vector<Il2CppGenericParameter> _genericParams;
		std::vector<TypeIndex> _genericConstraints; // raw TypeIndex
		std::vector<Il2CppGenericContainer> _genericContainers;

		std::vector<FieldDetail> _fieldDetails;
		std::vector<Il2CppFieldDefaultValue> _fieldDefaultValues;

		std::unordered_map<uint32_t, TbClassLayout> _classLayouts;
		std::vector<uint32_t> _nestedTypeDefineIndexs;

		// runtime data 
		std::vector<Il2CppClass*> _classList;

		std::unordered_map<std::tuple<uint32_t, const Il2CppGenericContext*>, void*, TokenGenericContextTypeHash, TokenGenericContextTypeEqual> _token2ResolvedDataCache;
		il2cpp::gc::AppendOnlyGCHashMap<uint32_t, Il2CppString*, std::hash<uint32_t>> _il2cppStringCache;

		std::unordered_map<uint32_t, CustomAtttributesInfo> _tokenCustomAttributes;
		std::vector<Il2CppCustomAttributeTypeRange> _customAttributeHandles;
		std::vector<CustomAttributesCache*> _customAttribtesCaches;
		std::vector<CustomAttribute> _customAttribues;

		std::vector<PropertyDetail> _propeties;
		std::vector<EventDetail> _events;
	};
}
}