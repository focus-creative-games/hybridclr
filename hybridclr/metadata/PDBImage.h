#pragma once

#include "RawImageBase.h"

namespace hybridclr
{
namespace metadata
{
	struct ILMapper
	{
		uint32_t irOffset;
		uint32_t ilOffset;
	};

	class PDBImage : public RawImageBase
	{
	public:
		PDBImage() : RawImageBase()
		{
		}

		LoadImageErrorCode LoadCLIHeader(uint32_t& entryPointToken, uint32_t& metadataRva, uint32_t& metadataSize) override;

		Il2CppString* GetUserStringBlogByIndex(uint32_t index) const override
		{
			RaiseExecutionEngineException("PDBImage::GetUserStringBlogByIndex Not implemented");
			return nullptr;
		}

		void SetupStackFrameInfo(const MethodInfo* method, const void* ip, Il2CppStackFrameInfo& stackFrame);
		void SetMethodDebugInfo(const MethodInfo* method, const il2cpp::utils::dynamic_array<ILMapper>& ilMapper);
	private:

		struct SymbolDocumentData
		{
			const char* sourceFiles;
		};

		struct SymbolSequencePoint
		{
			uint32_t document;
			uint32_t ilOffset;
			uint32_t line;
			uint32_t column;
			uint32_t endLine;
			uint32_t endColumn;
		};

		struct SymbolMethodDefData
		{
			uint32_t document;
			il2cpp::utils::dynamic_array<SymbolSequencePoint> sequencePoints;
		};

		struct SymbolMethodInfoData
		{
			SymbolMethodDefData* methodData;
			il2cpp::utils::dynamic_array<ILMapper> ilMapper;
		};

		SymbolMethodDefData* GetMethodDataFromCache(uint32_t methodToken);
		static uint32_t FindILOffsetByIROffset(const il2cpp::utils::dynamic_array<ILMapper>& ilMapper, uint32_t irOffset);
		static const SymbolSequencePoint* FindSequencePoint(const il2cpp::utils::dynamic_array<SymbolSequencePoint>& sequencePoints, uint32_t ilOffset);
		const SymbolDocumentData* GetDocument(uint32_t documentToken);
		const char* GetDocumentName(uint32_t documentToken)
		{
			const SymbolDocumentData* document = GetDocument(documentToken);
			return document ? document->sourceFiles : nullptr;
		}

		typedef Il2CppHashMap<uint32_t, SymbolMethodDefData*, il2cpp::utils::PassThroughHash<uint32_t>> SymbolMethodDataMap;
		SymbolMethodDataMap _methods;

		typedef Il2CppHashMap<uint32_t, SymbolDocumentData*, il2cpp::utils::PassThroughHash<uint32_t>> SymbolDocumentDataMap;
		SymbolDocumentDataMap _documents;

		typedef Il2CppHashMap<const MethodInfo*, SymbolMethodInfoData*, il2cpp::utils::PassThroughHash<const MethodInfo*>> SymbolMethodInfoDataMap;
		SymbolMethodInfoDataMap _methodInfos;
	};
}
}