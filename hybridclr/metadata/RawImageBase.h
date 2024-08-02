#pragma once

#include "../CommonDef.h"

#include "vm/String.h"

#include "MetadataDef.h"
#include "BlobReader.h"
#include "MetadataUtil.h"

namespace hybridclr
{
namespace metadata
{
	enum class LoadImageErrorCode
	{
		OK = 0,
		BAD_IMAGE,
		NOT_IMPLEMENT,
		AOT_ASSEMBLY_NOT_FIND,
		HOMOLOGOUS_ONLY_SUPPORT_AOT_ASSEMBLY,
		HOMOLOGOUS_ASSEMBLY_HAS_BEEN_LOADED,
		INVALID_HOMOLOGOUS_MODE,
		PDB_BAD_FILE,
	};



	struct SectionHeader
	{
		uint32_t virtualAddressBegin;
		uint32_t virtualAddressEnd;
		uint32_t ptrRawDataRelatedToVirtualAddress;
	};

	class RawImageBase
	{
	public:
		RawImageBase() : _imageData(nullptr), _imageLength(0), _ptrRawDataEnd(nullptr),
			_streamStringHeap{}, _streamUS{}, _streamBlobHeap{}, _streamGuidHeap{}, _streamTables{},
			_4byteStringIndex(false), _4byteGUIDIndex(false), _4byteBlobIndex(false)
		{

		}

		virtual ~RawImageBase()
		{
			if (_imageData)
			{
				HYBRIDCLR_FREE((void*)_imageData);
				_imageData = nullptr;
			}
		}
		virtual LoadImageErrorCode Load(const void* imageData, size_t length);
		virtual LoadImageErrorCode PostLoadStreams() { return LoadImageErrorCode::OK; }
		virtual LoadImageErrorCode PostLoadTables() { return LoadImageErrorCode::OK; }

		virtual Il2CppString* GetUserStringBlogByIndex(uint32_t index) const = 0;
		virtual void DecryptMethodBodyIfNeed(const byte* methodBody, uint32_t methodBodySize) {}

		const char* GetStringFromRawIndex(StringIndex index) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(index) == 0);
			IL2CPP_ASSERT(index >= 0 && (uint32_t)index < _streamStringHeap.size);
			return (const char*)(_streamStringHeap.data + index);
		}

		const byte* GetBlobFromRawIndex(StringIndex index) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(index) == 0);
			IL2CPP_ASSERT(index == 0 || (index > 0 && (size_t)index < _streamBlobHeap.size));
			return _streamBlobHeap.data + index;
		}

		const uint8_t* GetFieldOrParameterDefalutValueByRawIndex(uint32_t index) const
		{
			return _imageData + index;
		}

		static BlobReader DecodeBlob(const byte* buf)
		{
			uint32_t sizeLength;
			uint32_t length = BlobReader::ReadCompressedUint32(buf, sizeLength);
			return BlobReader(buf + sizeLength, length);
		}

		BlobReader GetBlobReaderByRawIndex(uint32_t rawIndex) const
		{
			IL2CPP_ASSERT(DecodeImageIndex(rawIndex) == 0);
			const byte* buf = _streamBlobHeap.data + rawIndex;
			return DecodeBlob(buf);
		}

		uint32_t GetImageOffsetOfBlob(Il2CppTypeEnum type, uint32_t index) const
		{
			if (type != IL2CPP_TYPE_STRING)
			{
				return (uint32_t)(GetBlobReaderByRawIndex(index).GetData() - _imageData);
			}
			else
			{
				return (uint32_t)(_streamBlobHeap.data + index - _imageData);
			}
		}

		const byte* GetDataPtrByImageOffset(uint32_t imageOffset) const
		{
			IL2CPP_ASSERT(imageOffset < _imageLength);
			return _imageData + imageOffset;
		}


		uint32_t GetEntryPointToken() const
		{
			return _entryPointToken;
		}


		const Table& GetTable(TableType type) const
		{
			return _tables[(int)type];
		}

		uint32_t GetTableRowNum(TableType tableIndex) const
		{
			return _tables[(int)tableIndex].rowNum;
		}

		bool TranslateRVAToImageOffset(uint32_t rvaOffset, uint32_t& imageOffset) const
		{
			for (const SectionHeader& sh : _sections)
			{
				if (sh.virtualAddressBegin <= rvaOffset && rvaOffset < sh.virtualAddressEnd)
				{
					imageOffset = sh.ptrRawDataRelatedToVirtualAddress + rvaOffset;
					return true;
				}
			}
			return false;
		}

		LoadImageErrorCode LoadStreamHeaders(uint32_t metadataRva, uint32_t metadataSize);
		LoadImageErrorCode ValidateStreams();
		LoadImageErrorCode LoadTables();

		void BuildTableRowMetas();

		uint32_t ComputTableRowMetaDataSize(TableType tableIndex) const;

		uint32_t ComputStringIndexByte() const
		{
			return _4byteStringIndex ? 4 : 2;
		}

		uint32_t ComputGUIDIndexByte() const
		{
			return _4byteGUIDIndex ? 4 : 2;
		}

		uint32_t ComputBlobIndexByte() const
		{
			return _4byteBlobIndex ? 4 : 2;
		}

		uint32_t ComputTableIndexByte(TableType tableIndex) const
		{
			return _tables[(int)tableIndex].rowNum < 65536 ? 2 : 4;
		}

		uint32_t ComputIndexByte(uint32_t maxRowNum, uint32_t tagBitNum) const
		{
			return (maxRowNum << tagBitNum) < 65536 ? 2 : 4;
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, uint32_t tagBitNum) const
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, TableType t3, uint32_t tagBitNum) const
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			n = std::max(n, GetTableRowNum(t3));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, TableType t3, TableType t4, uint32_t tagBitNum) const
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			n = std::max(n, GetTableRowNum(t3));
			n = std::max(n, GetTableRowNum(t4));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(TableType t1, TableType t2, TableType t3, TableType t4, TableType t5, uint32_t tagBitNum) const
		{
			uint32_t n = GetTableRowNum(t1);
			n = std::max(n, GetTableRowNum(t2));
			n = std::max(n, GetTableRowNum(t3));
			n = std::max(n, GetTableRowNum(t4));
			n = std::max(n, GetTableRowNum(t5));
			return ComputIndexByte(n, tagBitNum);
		}

		uint32_t ComputTableIndexByte(const TableType* ts, int num, uint32_t tagBitNum) const
		{
			uint32_t n = 0;
			for (int i = 0; i < num; i++)
			{
				n = std::max(n, GetTableRowNum(ts[i]));
			}
			return ComputIndexByte(n, tagBitNum);
		}

	protected:
		virtual LoadImageErrorCode LoadCLIHeader(uint32_t& entryPointToken, uint32_t& metadataRva, uint32_t& metadataSize) = 0;

		const byte* GetTableRowPtr(TableType type, uint32_t rawIndex) const
		{
			auto& tb = _tables[(int)type];
			IL2CPP_ASSERT(rawIndex > 0 && rawIndex <= tb.rowNum);
			return tb.data + tb.rowMetaDataSize * (rawIndex - 1);
		}

		const std::vector<ColumnOffsetSize>& GetRowSchema(TableType type) const
		{
			return _tableRowMetas[(int)type];
		}

		uint32_t ReadColumn(const byte* rowPtr, const ColumnOffsetSize& columnMt) const
		{
			return ReadColumn(rowPtr, columnMt.offset, columnMt.size);
		}

		uint32_t ReadColumn(const byte* data, uint32_t offset, uint32_t size) const
		{
			IL2CPP_ASSERT(size == 2 || size == 4);
			return (size == 2 ? *(uint16_t*)(data + offset) : *(uint32_t*)(data + offset));
		}

		static Il2CppString* CreateUserString(const char* str, uint32_t length)
		{
			if (length == 0)
			{
				return il2cpp::vm::String::Empty();
			}
			else
			{
				IL2CPP_ASSERT(length % 2 == 1);
				UserStringEncoding charEncoding = (UserStringEncoding)str[length - 1];
				return il2cpp::vm::String::NewUtf16((const Il2CppChar*)str, (length - 1) / 2);
			}
		}

	public:

#define TABLE_BEGIN(name, tableType) Tb##name Read##name(uint32_t rawIndex) \
        { \
        IL2CPP_ASSERT(rawIndex > 0 && rawIndex <= GetTable(tableType).rowNum); \
        const byte* rowPtr = GetTableRowPtr(tableType, rawIndex); \
        auto& rowSchema = GetRowSchema(tableType); \
        uint32_t __fieldIndex = 0; \
        Tb##name __r = {};

#define __F(fieldName) const ColumnOffsetSize& col_##fieldName = rowSchema[__fieldIndex++]; \
        __r.fieldName = ReadColumn(rowPtr, col_##fieldName);

#define TABLE_END return __r; \
        }

#define TABLE1(name, tableType, f1) TABLE_BEGIN(name, tableType) \
__F(f1) \
TABLE_END

#define TABLE2(name, tableType, f1, f2) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
TABLE_END

#define TABLE3(name, tableType, f1, f2, f3) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
TABLE_END

#define TABLE4(name, tableType, f1, f2, f3, f4) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
__F(f4) \
TABLE_END

#define TABLE5(name, tableType, f1, f2, f3, f4, f5) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
__F(f4) \
__F(f5) \
TABLE_END

#define TABLE6(name, tableType, f1, f2, f3, f4, f5, f6) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
__F(f4) \
__F(f5) \
__F(f6) \
TABLE_END

		TABLE5(Module, TableType::MODULE, generation, name, mvid, encid, encBaseId);
		TABLE3(TypeRef, TableType::TYPEREF, resolutionScope, typeName, typeNamespace)
		virtual TABLE6(TypeDef, TableType::TYPEDEF, flags, typeName, typeNamespace, extends, fieldList, methodList)
			TABLE1(TypeSpec, TableType::TYPESPEC, signature);
		TABLE3(Field, TableType::FIELD, flags, name, signature)
			TABLE4(GenericParam, TableType::GENERICPARAM, number, flags, owner, name)
			TABLE2(GenericParamConstraint, TableType::GENERICPARAMCONSTRAINT, owner, constraint)
			TABLE3(MemberRef, TableType::MEMBERREF, classIdx, name, signature)
			TABLE1(StandAloneSig, TableType::STANDALONESIG, signature)
			TABLE3(MethodImpl, TableType::METHODIMPL, classIdx, methodBody, methodDeclaration)
			TABLE2(FieldRVA, TableType::FIELDRVA, rva, field)
			TABLE2(FieldLayout, TableType::FIELDLAYOUT, offset, field)
			TABLE3(Constant, TableType::CONSTANT, type, parent, value)
			TABLE2(MethodSpec, TableType::METHODSPEC, method, instantiation)
			TABLE3(CustomAttribute, TableType::CUSTOMATTRIBUTE, parent, type, value)
			TABLE2(PropertyMap, TableType::PROPERTYMAP, parent, propertyList)
			TABLE3(Property, TableType::PROPERTY, flags, name, type)
			TABLE2(EventMap, TableType::EVENTMAP, parent, eventList)
			TABLE3(Event, TableType::EVENT, eventFlags, name, eventType)
			TABLE3(MethodSemantics, TableType::METHODSEMANTICS, semantics, method, association)

			TABLE2(NestedClass, TableType::NESTEDCLASS, nestedClass, enclosingClass)
			TABLE6(Method, TableType::METHOD, rva, implFlags, flags, name, signature, paramList)
			TABLE3(Param, TableType::PARAM, flags, sequence, name)

			TABLE3(ClassLayout, TableType::CLASSLAYOUT, packingSize, classSize, parent)
			TABLE2(InterfaceImpl, TableType::INTERFACEIMPL, classIdx, interfaceIdx)

			TABLE_BEGIN(Assembly, TableType::ASSEMBLY)
			__F(hashAlgId)
			__F(majorVersion)
			__F(minorVersion)
			__F(buildNumber)
			__F(revisionNumber)
			__F(flags)
			__F(publicKey)
			__F(name)
			__F(culture)
			TABLE_END


			TABLE_BEGIN(AssemblyRef, TableType::ASSEMBLYREF)
			__F(majorVersion)
			__F(minorVersion)
			__F(buildNumber)
			__F(revisionNumber)
			__F(flags)
			__F(publicKeyOrToken)
			__F(name)
			__F(culture)
			__F(hashValue)
			TABLE_END

			TABLE4(SymbolDocument, TableType::DOCUMENT, name, hashAlgorithm, hash, language)
			TABLE2(SymbolMethodBody, TableType::METHODBODY, document, sequencePoints)
			TABLE6(SymbolLocalScope, TableType::LOCALSCOPE, method, importScope, variables, constants, startOffset, length)
			TABLE3(SymbolLocalVariable, TableType::LOCALVARIABLE, attributes, index, name)
			TABLE2(SymbolConstant, TableType::LOCALCONSTANT, name, signature)
			TABLE2(SymbolImportScope, TableType::IMPORTSCOPE, parent, imports)
			TABLE2(SymbolStateMachineMethod, TableType::STATEMACHINEMETHOD, moveNextMethod, kickoffMethod)
			TABLE3(SymbolCustomDebugInformation, TableType::CUSTOMDEBUGINFORMATION, parent, kind, value)

		protected:
			const byte* _imageData;
			uint32_t _imageLength;
			const byte* _ptrRawDataEnd;

			std::vector<SectionHeader> _sections;


			uint32_t _entryPointToken;

			CliStream _streamStringHeap;
			CliStream _streamUS;
			CliStream _streamBlobHeap;
			CliStream _streamGuidHeap;
			CliStream _streamTables;

			bool _4byteStringIndex;
			bool _4byteGUIDIndex;
			bool _4byteBlobIndex;

			Table _tables[TABLE_NUM];
			std::vector<ColumnOffsetSize> _tableRowMetas[TABLE_NUM];
	};
}
}