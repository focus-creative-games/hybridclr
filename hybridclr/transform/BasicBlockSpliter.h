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

#include <set>

#include "../CommonDef.h"
#include "../metadata/MetadataDef.h"

namespace hybridclr
{
namespace transform
{
class BasicBlockSpliter
{
  public:
    typedef Il2CppHashSet<uint32_t, il2cpp::utils::PassThroughHash<uint32_t>> Uin32Set;

    BasicBlockSpliter(const metadata::MethodBody& body) : _body(body)
    {
    }

    void SplitBasicBlocks();

    const std::set<uint32_t>& GetSplitOffsets() const
    {
        return _splitOffsets;
    }

  private:
    const metadata::MethodBody& _body;
    std::set<uint32_t> _splitOffsets;

    void SplitNormal(const byte* ilcodeStart, uint32_t codeSize, Uin32Set& ilOffsets);
    void SplitExceptionHandles(const byte* ilcodeStart, uint32_t codeSize, const std::vector<metadata::ExceptionClause>& exceptionClauses);
};
} // namespace transform
} // namespace hybridclr
