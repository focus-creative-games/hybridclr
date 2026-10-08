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
    const byte* ptr_lfanew = imageData + 0x3c;
    uint32_t lfanew = *(uint32_t*)ptr_lfanew;
    if (lfanew >= _imageLength)
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }

    const byte* ptrSig = imageData + lfanew;
    /*if (ptr_sig[0] != 'P' || ptr_sig[1] != 'E' || ptr_sig[2] != 0 || ptr_sig[3] != 0)*/
    if (std::strncmp((const char*)ptrSig, "PE\0\0", 4))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }

    PEHeader* peHeader = (PEHeader*)(ptrSig + 4);

    bool isDll = (peHeader->characteristics & 0x2000);
    // std::cout << "load " << (_isDll ? "dll" : "exe") << std::endl;

    // optional size may be 224(32bit matchine) or 240 (64bit)
    if (peHeader->optionalHeadersize != kOptionalHeaderSize32 && peHeader->optionalHeadersize != kOptionalHeaderSize64)
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    bool is32BitFormat = peHeader->optionalHeadersize == kOptionalHeaderSize32;

    PESectionHeader* _peSectionHeaders = (PESectionHeader*)((byte*)peHeader + 20 + peHeader->optionalHeadersize);

    for (uint16_t secIdx = 0; secIdx < peHeader->sections; secIdx++)
    {
        const PESectionHeader* ph = _peSectionHeaders + secIdx;
        if ((byte*)ph >= _ptrRawDataEnd)
        {
            return LoadImageErrorCode::BAD_IMAGE;
        }
        _sections.push_back({ph->virtualAddress, ph->virtualAddress + ph->virtualSize, ph->ptrRawData - ph->virtualAddress});
    }

    const PEDirEntry* ptrCLIHeaderEntry =
        (PEDirEntry*)(((byte*)peHeader) + 20 /* pe header size */
                      + (is32BitFormat ? kCliHeaderOffset32 : kCliHeaderOffset64) /* pe optional header -> pe header data directories -> cli header */);
    uint32_t cLIHeaderOffset;
    if (!TranslateRVAToImageOffset(ptrCLIHeaderEntry->rva, cLIHeaderOffset))
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }
    if (cLIHeaderOffset >= _imageLength)
    {
        return LoadImageErrorCode::BAD_IMAGE;
    }

    const CLIHeader* ptrCLIHeader = (const CLIHeader*)(imageData + cLIHeaderOffset);
    entryPointToken = ptrCLIHeader->entryPointToken;
    metadataRva = ptrCLIHeader->metaData.rva;
    metadataSize = ptrCLIHeader->metaData.size;

    return LoadImageErrorCode::OK;
}

} // namespace metadata
} // namespace hybridclr