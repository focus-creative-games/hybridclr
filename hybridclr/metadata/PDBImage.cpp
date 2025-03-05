#include "PDBImage.h"

#include <algorithm>

#include "../interpreter/InterpreterDefs.h"

#include "BlobReader.h"

namespace hybridclr
{
namespace metadata
{
	constexpr uint32_t kHiddenLine = 0xfeefee;

	LoadImageErrorCode PDBImage::LoadCLIHeader(uint32_t& entryPointToken, uint32_t& metadataRva, uint32_t& metadataSize)
	{
		entryPointToken = 0;
		metadataRva = 0;
		metadataSize = _imageLength;

		_sections.push_back({ 0, _imageLength, 0 });
		return LoadImageErrorCode::OK;
	}

	uint32_t PDBImage::FindILOffsetByIROffset(const il2cpp::utils::dynamic_array<ILMapper>& ilMapper, uint32_t irOffset)
	{
		auto it = std::upper_bound(ilMapper.begin(), ilMapper.end(), irOffset, [](uint32_t irOffset, const ILMapper& mapper) { return irOffset < mapper.irOffset; });
		if (it != ilMapper.begin())
		{
			auto next = it;
			if (next != ilMapper.end())
			{
				IL2CPP_ASSERT(next->irOffset > irOffset);
			}
			--it;
			IL2CPP_ASSERT(it->irOffset <= irOffset);
			return it->ilOffset;
		}
		return 0;
	}

	const PDBImage::SymbolSequencePoint* PDBImage::FindSequencePoint(const il2cpp::utils::dynamic_array<SymbolSequencePoint>& sequencePoints, uint32_t ilOffset)
	{
		auto it = std::upper_bound(sequencePoints.begin(), sequencePoints.end(), ilOffset, [](uint32_t ilOffset, const SymbolSequencePoint& ssp) { return ilOffset < ssp.ilOffset; });
		if (it != sequencePoints.begin())
		{
			auto next = it;
			if (next != sequencePoints.end())
			{
				IL2CPP_ASSERT(next->ilOffset > ilOffset);
			}
			--it;
			IL2CPP_ASSERT(it->ilOffset <= ilOffset);
			return &(*it);
		}
		return nullptr;
	}

	const PDBImage::SymbolDocumentData* PDBImage::GetDocument(uint32_t documentToken)
	{
		const Table& tableMeta = GetTable(TableType::DOCUMENT);
		uint32_t rowIndex = DecodeTokenRowIndex(documentToken);
		if (rowIndex == 0 || rowIndex > tableMeta.rowNum)
		{
			return nullptr;
		}

		auto it = _documents.find(documentToken);
		if (it != _documents.end())
		{
			return it->second;
		}

		TbSymbolDocument document = ReadSymbolDocument(rowIndex);
		SymbolDocumentData* documentData = new (HYBRIDCLR_MALLOC_ZERO(sizeof(SymbolDocumentData))) SymbolDocumentData();
		BlobReader reader = GetBlobReaderByRawIndex(document.name);
		
		// FIXME. this is a utf-8 char.
		char sep = (char)reader.ReadByte();
		std::string sourceFileNames;
		bool first = true;
		while (reader.NonEmpty())
		{
			if (sep && !first)
			{
				sourceFileNames.push_back(sep);
			}
			uint32_t sourceFileNameIndex = reader.ReadCompressedUint32();
			if (sourceFileNameIndex > 0)
			{
				BlobReader sourceFileNameReader = GetBlobReaderByRawIndex(sourceFileNameIndex);
				sourceFileNames.append((const char*)sourceFileNameReader.GetData(), sourceFileNameReader.GetLength());
			}
			first = false;
		}
		documentData->sourceFiles = CopyString(sourceFileNames.c_str());

		_documents.add(documentToken, documentData);
		return documentData;
	}

	void PDBImage::SetupStackFrameInfo(const MethodInfo* method, const void* ip, Il2CppStackFrameInfo& stackFrame)
	{
		auto it = _methodInfos.find(method);
		if (it == _methodInfos.end())
		{
			return;
		}
		const SymbolMethodInfoData* methodInfoData = it->second;
		const SymbolMethodDefData* methodData = methodInfoData->methodData;
		const hybridclr::interpreter::InterpMethodInfo* imi = (const hybridclr::interpreter::InterpMethodInfo*)method->interpData;
		const byte* actualIp;
		if (ip >= imi->codes && ip < imi->codes + imi->codeLength)
		{
			actualIp = (const byte*)ip;
		}
		else
		{
			actualIp = *(byte**)ip;
			IL2CPP_ASSERT(actualIp >= imi->codes && actualIp < imi->codes + imi->codeLength);
		}

		uint32_t irOffset = (uint32_t)((uintptr_t)actualIp - (uintptr_t)imi->codes);
		uint32_t ilOffset = FindILOffsetByIROffset(methodInfoData->ilMapper, irOffset);
		// when call sub interpreter method, ip point to next instruction, so we need to adjust ilOffset.
		if (ilOffset > 0)
		{
			--ilOffset;
		}

		const SymbolSequencePoint* ssp = FindSequencePoint(methodData->sequencePoints, ilOffset);
		if (!ssp)
		{
			return;
		}

		stackFrame.ilOffset = ilOffset;
		stackFrame.sourceCodeLineNumber = ssp->line;

		stackFrame.filePath = GetDocumentName(ssp->document);
	}

	void PDBImage::SetMethodDebugInfo(const MethodInfo* method, const il2cpp::utils::dynamic_array<ILMapper>& ilMapper)
	{
		IL2CPP_ASSERT(_methodInfos.find(method) == _methodInfos.end());
		SymbolMethodDefData* methodData = GetMethodDataFromCache(method->token);
		if (!methodData)
		{
			return;
		}

		SymbolMethodInfoData* methodInfoData = new (HYBRIDCLR_MALLOC_ZERO(sizeof(SymbolMethodInfoData))) SymbolMethodInfoData();
		methodInfoData->methodData = methodData;
		methodInfoData->ilMapper = ilMapper;
		_methodInfos.add(method, methodInfoData);
	}


	PDBImage::SymbolMethodDefData* PDBImage::GetMethodDataFromCache(uint32_t methodToken)
	{
		const Table& tableMeta = GetTable(TableType::METHODBODY);
		uint32_t rowIndex = hybridclr::metadata::DecodeTokenRowIndex(methodToken);
		if (rowIndex == 0 || rowIndex > tableMeta.rowNum)
		{
			return nullptr;
		}

		auto it = _methods.find(methodToken);
		if (it != _methods.end())
		{
			return it->second;
		}

		SymbolMethodDefData* methodData = new (HYBRIDCLR_MALLOC_ZERO(sizeof(SymbolMethodDefData))) SymbolMethodDefData();

		// see https://github.com/dotnet/runtime/blob/main/docs/design/specs/PortablePdb-Metadata.md
		TbSymbolMethodBody smb = ReadSymbolMethodBody(rowIndex);
		methodData->document = smb.document;
		if (smb.sequencePoints > 0)
		{
			auto& sequencePoints = methodData->sequencePoints;
			BlobReader reader = GetBlobReaderByRawIndex(smb.sequencePoints);
			uint32_t localSignature = reader.ReadCompressedUint32();
			uint32_t document = smb.document ? smb.document : reader.ReadCompressedUint32();
			int32_t prevStartLine = -1;
			int32_t prevStartColumn = -1;
			while (reader.NonEmpty())
			{
				uint32_t deltaIlOffset = reader.ReadCompressedUint32();
				// document record
				if (deltaIlOffset == 0 && !sequencePoints.empty())
				{
					document = reader.ReadCompressedUint32();
					continue;
				}
				uint32_t deltaLines = reader.ReadCompressedUint32();
				int32_t deltaColumns = deltaLines == 0 ? reader.ReadCompressedUint32() : reader.ReadCompressedInt32();
				
				uint32_t ilOffset = sequencePoints.empty() ? deltaIlOffset : sequencePoints.back().ilOffset + deltaIlOffset;

				SymbolSequencePoint ssp = {};
				ssp.document = document;
				ssp.ilOffset = ilOffset;
				// hidden-sequence-point record
				if (deltaLines == 0 && deltaColumns == 0)
				{
					ssp.line = ssp.endLine = kHiddenLine;
					ssp.column = ssp.endColumn = 0;
				}
				else
				{
					// sequence-point record
					if (prevStartColumn < 0)
					{
						prevStartLine = reader.ReadCompressedUint32();
						prevStartColumn = reader.ReadCompressedUint32();
					}
					else
					{
						prevStartLine += reader.ReadCompressedInt32();
						prevStartColumn += reader.ReadCompressedInt32();
					}
					ssp.line = prevStartLine;
					ssp.endLine = prevStartLine + deltaLines;
					ssp.column = prevStartColumn;
					ssp.endColumn = prevStartColumn + deltaColumns;
				}
				sequencePoints.push_back(ssp);
			}
		}

		_methods.add(methodToken, methodData);
		return methodData;
	}
}
}


