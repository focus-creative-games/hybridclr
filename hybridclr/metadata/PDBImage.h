// Copyright 2026 Code Philosophy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
} // namespace metadata
} // namespace hybridclr