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

#include "MetadataUtil.h"

namespace hybridclr
{
namespace metadata
{
struct ByteSpan
{
    const byte* data;
    uint32_t length;

    ByteSpan() : data(nullptr), length(0)
    {
    }

    ByteSpan(const byte* data, uint32_t length) : data(data), length(length)
    {
    }
};

class MetadataReader
{
  private:
    const byte* _data;

  public:
    MetadataReader(const byte* data) : _data(data)
    {
    }

    int16_t ReadInt16()
    {
        int16_t value = GetI2LittleEndian(_data);
        _data += 2;
        return value;
    }

    bool ReadBool()
    {
        return *(_data++) != 0;
    }

    uint8_t ReadUInt8()
    {
        return *(_data++);
    }

    uint16_t ReadUInt16()
    {
        uint16_t value = GetU2LittleEndian(_data);
        _data += 2;
        return value;
    }

    int32_t ReadInt32()
    {
        int32_t value = GetI4LittleEndian(_data);
        _data += 4;
        return value;
    }

    uint32_t ReadUInt32()
    {
        uint32_t value = GetU4LittleEndian(_data);
        _data += 4;
        return value;
    }

    int64_t ReadInt64()
    {
        int64_t value = GetI8LittleEndian(_data);
        _data += 8;
        return value;
    }

    uint64_t ReadUInt64()
    {
        uint64_t value = GetU8LittleEndian(_data);
        _data += 8;
        return value;
    }

    const byte* ReadFixedBytes(int32_t byteCount)
    {
        const byte* value = _data;
        _data += byteCount;
        return value;
    }

    ByteSpan ReadBytes()
    {
        uint32_t byteCount = ReadUInt32();
        const byte* buffer = _data;
        _data += byteCount;
        return ByteSpan(buffer, byteCount);
    }

    const byte* CurrentDataPtr() const
    {
        return _data;
    }
};
} // namespace metadata
} // namespace hybridclr