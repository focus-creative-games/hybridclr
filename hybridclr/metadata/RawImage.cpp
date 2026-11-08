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

#include "RawImage.h"

#include <algorithm>
#include <cstring>
#include <iostream>

#include "MetadataUtil.h"
#include "Opcodes.h"

namespace hybridclr
{
namespace metadata
{

const int kOptionalHeaderSize32 = 224;
const int kOptionalHeaderSize64 = 240;
const int kCliHeaderOffset32 = 208;
const int kCliHeaderOffset64 = 224;

LoadImageErrorCode RawImage::LoadCLIHeader(uint32_t& entryPointToken, uint32_t& metadataRva, uint32_t& metadataSize)
{
    const byte* imageData = _imageData;
    if (!imageData || !IsRangeWithin(_imageLength, 0x3c, sizeof(uint32_t)))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    const byte* ptr_lfanew = imageData + 0x3c;
    uint32_t lfanew = GetU4LittleEndian(ptr_lfanew);
    if (!IsRangeWithin(_imageLength, lfanew, 4 + sizeof(PEHeader)))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }

    const byte* ptrSig = imageData + lfanew;
    if (std::memcmp(ptrSig, "PE\0\0", 4))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }

    const PEHeader* peHeader = (const PEHeader*)(ptrSig + 4);

    // optional size may be 224(32bit matchine) or 240 (64bit)
    if (peHeader->optionalHeadersize != kOptionalHeaderSize32 && peHeader->optionalHeadersize != kOptionalHeaderSize64)
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    bool is32BitFormat = peHeader->optionalHeadersize == kOptionalHeaderSize32;
    size_t optionalHeaderOffset = (size_t)lfanew + 4 + sizeof(PEHeader);
    if (!IsRangeWithin(_imageLength, optionalHeaderOffset, peHeader->optionalHeadersize))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    const byte* optionalHeader = imageData + optionalHeaderOffset;
    if (GetU2LittleEndian(optionalHeader) != (is32BitFormat ? 0x10b : 0x20b))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    size_t sectionHeadersOffset = optionalHeaderOffset + peHeader->optionalHeadersize;
    if (!IsRangeWithin(_imageLength, sectionHeadersOffset, (size_t)peHeader->sections * sizeof(PESectionHeader)))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    const PESectionHeader* peSectionHeaders = (const PESectionHeader*)(imageData + sectionHeadersOffset);

    for (uint16_t secIdx = 0; secIdx < peHeader->sections; secIdx++)
    {
        const PESectionHeader* ph = peSectionHeaders + secIdx;
        if (!IsRangeWithin(_imageLength, ph->ptrRawData, ph->sizeOfRawData))
        {
            return LoadImageErrorCode::BAD_IMAGE;
        }
        // An RVA must refer to bytes present in the file, not the zero-filled virtual tail.
        uint32_t mappedSize = ph->virtualSize ? std::min(ph->virtualSize, ph->sizeOfRawData) : ph->sizeOfRawData;
        if (mappedSize > UINT32_MAX - ph->virtualAddress)
        {
            return LoadImageErrorCode::BAD_IMAGE;
        }
        _sections.push_back({ph->virtualAddress, ph->virtualAddress + mappedSize, ph->ptrRawData - ph->virtualAddress});
    }

    const PEDirEntry* ptrCLIHeaderEntry =
        (const PEDirEntry*)(optionalHeader + (is32BitFormat ? kCliHeaderOffset32 : kCliHeaderOffset64));
    uint32_t cLIHeaderOffset;
    if (ptrCLIHeaderEntry->size < sizeof(CLIHeader) ||
        !TranslateRVAToImageOffset(ptrCLIHeaderEntry->rva, cLIHeaderOffset, ptrCLIHeaderEntry->size))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }

    const CLIHeader* ptrCLIHeader = (const CLIHeader*)(imageData + cLIHeaderOffset);
    if (ptrCLIHeader->cb < sizeof(CLIHeader) || ptrCLIHeader->cb > ptrCLIHeaderEntry->size)
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    entryPointToken = ptrCLIHeader->entryPointToken;
    metadataRva = ptrCLIHeader->metaData.rva;
    metadataSize = ptrCLIHeader->metaData.size;

    return LoadImageErrorCode::OK;
}

} // namespace metadata
} // namespace hybridclr
