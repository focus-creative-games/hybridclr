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

#include <stack>
#include <cmath>
#include <vector>

#include "../CommonDef.h"

namespace hybridclr
{
namespace transform
{
const size_t kMinBlockSize = 8 * 1024;

class TemporaryMemoryArena
{
  public:
    TemporaryMemoryArena() : _buf(nullptr), _size(0), _pos(0)
    {
        Begin();
    }

    ~TemporaryMemoryArena()
    {
        End();
    }

    static size_t AligndSize(size_t size)
    {
        return (size + 7) & ~7;
    }

    template <typename T>
    T* AllocIR()
    {
        const size_t aligndSize = AligndSize(sizeof(T));
        if (_pos + aligndSize <= _size)
        {
            T* ir = (T*)(_buf + _pos);
            *ir = {};
            _pos += aligndSize;
            return ir;
        }

        RequireSize(aligndSize);

        T* ir = (T*)(_buf + _pos);
        *ir = {};
        _pos += aligndSize;
        return ir;
    }

    template <typename T>
    T* NewAny()
    {
        const size_t needSize = AligndSize(sizeof(T));
        if (_pos + needSize <= _size)
        {
            T* ir = new (_buf + _pos) T();
            *ir = {};
            _pos += needSize;
            return ir;
        }

        RequireSize(needSize);

        T* ir = new (_buf + _pos) T();
        *ir = {};
        _pos += needSize;
        return ir;
    }

    template <typename T>
    T* NewNAny(int n)
    {
        if (n > 0)
        {
            size_t bytes = AligndSize(sizeof(T) * n);
            if (_pos + bytes > _size)
            {
                RequireSize(bytes);
            }
            T* ret = new (_buf + _pos) T[n];
            _pos += bytes;
            return ret;
        }
        else
        {
            return nullptr;
        }
    }

    void Begin();

    void End();

  private:
    struct Block
    {
        void* data;
        size_t size;
    };

    void RequireSize(size_t size)
    {
        if (_buf)
        {
            _useOuts.push_back({(void*)_buf, _size});
        }

        Block newBlock = AllocBlock(std::max(size, kMinBlockSize));
        _buf = (byte*)newBlock.data;
        _size = newBlock.size;
        _pos = 0;
    }

    static Block AllocBlock(size_t size);

    std::vector<Block> _useOuts;

    byte* _buf;
    size_t _size;
    size_t _pos;
};
} // namespace transform
} // namespace hybridclr