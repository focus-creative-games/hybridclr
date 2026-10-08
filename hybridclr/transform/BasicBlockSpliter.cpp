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

#include "BasicBlockSpliter.h"

#include "../metadata/Opcodes.h"
#include "../metadata/MetadataUtil.h"

using namespace hybridclr::metadata;

namespace hybridclr
{
namespace transform
{

void BasicBlockSpliter::SplitNormal(const byte* ilcodeStart, uint32_t codeSize, Uin32Set& ilOffsets)
{
    const byte* codeEnd = ilcodeStart + codeSize;
    const byte* ip = ilcodeStart;

    while (ip < codeEnd)
    {
        ilOffsets.insert((uint32_t)(ip - ilcodeStart));
        const OpCodeInfo* oc = DecodeOpCodeInfo(ip, codeEnd);
        IL2CPP_ASSERT(oc);
        int32_t opCodeSize = GetOpCodeSize(ip, oc);
        const byte* nextIp = ip + opCodeSize;
        int32_t nextOffset = (int32_t)(nextIp - ilcodeStart);
        IL2CPP_ASSERT(nextOffset >= 0 && nextOffset <= (int32_t)codeSize);

        switch (oc->inlineType)
        {
        case ArgType::None:
        case ArgType::Data:
        {
            break;
        }
        case ArgType::StaticBranch:
        {
            _splitOffsets.insert(nextOffset);
            break;
        }
        case ArgType::BranchTarget:
        {
            int32_t offset;
            switch (oc->inlineParam)
            {
            case 1:
            {
                offset = GetI1(ip + 1);
                break;
            }
            case 4:
            {
                offset = GetI4LittleEndian(ip + 1);
                break;
            }
            default:
            {
                RaiseExecutionEngineException("invalid BranchTarget param");
                offset = -1;
            }
            }
            // don't split 0 offset br
            if (offset != 0 || (oc->baseOpValue == OpcodeValue::LEAVE || oc->baseOpValue == OpcodeValue::LEAVE_S))
            {
                _splitOffsets.insert(nextOffset);
                _splitOffsets.insert(nextOffset + offset);
            }
            break;
        }
        case ArgType::Switch:
        {
            uint32_t caseNum = GetI4LittleEndian(ip + 1);
            bool splitAny = false;
            for (uint32_t caseIdx = 0; caseIdx < caseNum; caseIdx++)
            {
                int32_t caseOffset = GetI4LittleEndian(ip + 5 + caseIdx * 4);
                if (caseOffset != 0)
                {
                    _splitOffsets.insert(nextOffset + caseOffset);
                    splitAny = true;
                }
            }
            if (splitAny)
            {
                _splitOffsets.insert(nextOffset);
            }
            break;
        }
        default:
        {
            RaiseExecutionEngineException("unknown inline type");
            nextOffset = -1;
        }
        }
        ip = nextIp;
    }
    IL2CPP_ASSERT(ip == codeEnd);
}

void BasicBlockSpliter::SplitExceptionHandles(const byte* ilcodeStart, uint32_t codeSize, const std::vector<metadata::ExceptionClause>& exceptionClauses)
{
    for (auto& eh : exceptionClauses)
    {
        _splitOffsets.insert(eh.tryOffset);
        _splitOffsets.insert(eh.tryOffset + eh.tryLength);
        _splitOffsets.insert(eh.handlerOffsets);
        _splitOffsets.insert(eh.handlerOffsets + eh.handlerLength);
        if (eh.flags == CorILExceptionClauseType::Filter)
        {
            _splitOffsets.insert(eh.classTokenOrFilterOffset);
        }
    }
}

void BasicBlockSpliter::SplitBasicBlocks()
{
    const byte* ilcodeStart = _body.ilcodes;

    uint32_t codeSize = _body.codeSize;

    Uin32Set ilOffsets(codeSize);
    ilOffsets.insert(codeSize);

    SplitNormal(ilcodeStart, codeSize, ilOffsets);
    SplitExceptionHandles(ilcodeStart, codeSize, _body.exceptionClauses);

    /*if (_splitOffsets.find(0) != _splitOffsets.end())
    {
        _splitOffsets.erase(0);
    }*/
#if DEBUG
    for (uint32_t offset : _splitOffsets)
    {
        IL2CPP_ASSERT(ilOffsets.find(offset) != ilOffsets.end());
    }
    IL2CPP_ASSERT(_splitOffsets.find(codeSize) != _splitOffsets.end());
#endif
}
} // namespace transform
} // namespace hybridclr