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
        ByteSpan() : data(nullptr), length(0) {}
        ByteSpan(const byte* data, uint32_t length) : data(data), length(length) {}
    };

    class MetadataReader
    {
    private:
        const byte* _data;
    public:
        MetadataReader(const byte* data) : _data(data) {}
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
}
}