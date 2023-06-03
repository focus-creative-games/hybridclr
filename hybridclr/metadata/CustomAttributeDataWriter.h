#pragma once

#include "BlobReader.h"

#include "../CommonDef.h"

#include "utils/MemoryRead.h"

namespace hybridclr
{
namespace metadata
{
	class CustomAttributeDataWriter
	{
	private:
		uint8_t* _data;
		uint32_t _capacity;
		uint32_t _size;

	public:
		CustomAttributeDataWriter(uint32_t capacity) : _capacity(Round2Exp(capacity)), _size(0)
		{
			_data = (uint8_t*)IL2CPP_MALLOC_ZERO(_capacity);
		}

		~CustomAttributeDataWriter()
		{
			IL2CPP_FREE(_data);
			_data = nullptr;
		}

		uint32_t Size() const { return _size; }

		bool Empty() const { return _size == 0; }

		const uint8_t* Data() const { return _data; }

		const uint8_t* DataAt(uint32_t offset) { return _data + offset; }

		void Reset()
		{
			_size = 0;
		}

		void WriteAttributeCount(uint32_t count)
		{
			WriteCompressedUint32(count);
		}

		void Skip(int32_t skipBytes)
		{
			SureRemainSize(skipBytes);
			_size += skipBytes;
		}

		void WriteMethodIndex(int32_t offset, int32_t methodIndex)
		{
			*(int32_t*)(_data + offset) = methodIndex;
		}

		void WriteByte(uint8_t n)
		{
			SureRemainSize(1);
			_data[_size++] = n;
		}

		void WriteCompressedUint32(uint32_t n)
		{
			SureRemainSize(5);
			uint8_t* buf = _data + _size;
			if (n < 0x80)
			{
				buf[0] = (uint8_t)n;
				++_size;
			}
			else if (n < 0x4000)
			{
				uint32_t v = n | 0x8000;
				buf[0] = uint8_t(v >> 8);
				buf[1] = uint8_t(v);
				_size += 2;
			}
			else if (n < 0x20000000)
			{
				uint32_t v = n | 0xC0000000;
				buf[0] = uint8_t(v >> 24);
				buf[1] = uint8_t(v >> 16);
				buf[2] = uint8_t(v >> 8);
				buf[3] = uint8_t(v);
				_size += 4;
			}
			else if (n < UINT32_MAX - 1)
			{
				buf[0] = 0xF0;
				buf[1] = uint8_t(n);
				buf[2] = uint8_t(n >> 8);
				buf[3] = uint8_t(n >> 16);
				buf[4] = uint8_t(n >> 24);
				_size += 5;
			}
			else if (n == UINT32_MAX - 1)
			{
				buf[0] = 0xFE;
				++_size;
			}
			else
			{
				buf[0] = 0xFF;
				++_size;
			}
		}

		void WriteUint32(uint32_t n)
		{
			WriteData(n);
		}

		void WriteCompressedInt32(int32_t n)
		{
			uint32_t v = n >= 0 ? (n << 1) : (((-(n + 1)) << 1) | 0x1U);
			WriteCompressedUint32(v);
		}

		template<typename T>
		void WriteData(T x)
		{
			int32_t n = sizeof(T);
			SureRemainSize(n);
			std::memcpy(_data + _size, &x, n);
			_size += n;
		}

		void WriteBytes(const uint8_t* data, uint32_t len)
		{
			SureRemainSize(len);
			std::memcpy(_data + _size, data, len);
			_size += len;
		}

		void Write(const CustomAttributeDataWriter& writer)
		{
			SureRemainSize(writer._size);
			std::memcpy(_data + _size, writer._data, writer._size);
			_size += writer._size;
		}

		void Write(BlobReader& reader, int32_t count)
		{
			SureRemainSize(count);
			std::memcpy(_data + _size, reader.GetDataOfReadPosition(), count);
			_size += count;
			reader.SkipBytes(count);
		}

		void Test()
		{
#if HYBRIDCLR_UNITY_2021_OR_NEW
			for (uint64_t i = 0; i < UINT32_MAX; i = (i * 5) / 4 + 1)
			{
				_size = 0;
				WriteCompressedUint32((uint32_t)i);
				const char* p = (char*)_data;
				uint32_t v = il2cpp::utils::ReadCompressedUInt32(&p);
				IL2CPP_ASSERT(v == (uint32_t)i);
				IL2CPP_ASSERT(p == (const char*)_data + _size);
			}
			for (uint64_t i = UINT32_MAX - 1; i <= UINT32_MAX; i++)
			{
				_size = 0;
				WriteCompressedUint32((uint32_t)i);
				const char* p = (char*)_data;
				uint32_t v = il2cpp::utils::ReadCompressedUInt32(&p);
				IL2CPP_ASSERT(v == (uint32_t)i);
				IL2CPP_ASSERT(p == (const char*)_data + _size);
			}

			for (int64_t i = 0; i < INT32_MAX; i = (i * 5) / 4 + 1)
			{
				_size = 0;
				WriteCompressedInt32((int32_t)i);
				const char* p = (char*)_data;
				int32_t v = il2cpp::utils::ReadCompressedInt32(&p);
				IL2CPP_ASSERT(v == (int32_t)i);
				IL2CPP_ASSERT(p == (const char*)_data + _size);

				_size = 0;
				WriteCompressedInt32((int32_t)-i);
				p = (char*)_data;
				v = il2cpp::utils::ReadCompressedInt32(&p);
				IL2CPP_ASSERT(v == (int32_t)-i);
				IL2CPP_ASSERT(p == (const char*)_data + _size);
			}
			for (int64_t i = INT32_MIN; i <= INT32_MIN + 4; i++)
			{
				_size = 0;
				WriteCompressedInt32((int32_t)i);
				const char* p = (char*)_data;
				int32_t v = il2cpp::utils::ReadCompressedInt32(&p);
				IL2CPP_ASSERT(v == (int32_t)i);
				IL2CPP_ASSERT(p == (const char*)_data + _size);
			}
#endif
		}

		void PopByte()
		{
			IL2CPP_ASSERT(_size > 0);
			--_size;
		}

		void ReplaceLastByte(byte x)
		{
			IL2CPP_ASSERT(_size > 0);
			_data[_size - 1] = x;
		}

	private:
		uint32_t Round2Exp(uint32_t n)
		{
			uint32_t s = 64;
			for (uint32_t s = 64; ; s *= 2)
			{
				if (s >= n)
				{
					return s;
				}
			}
			return n;
		}

		void SureRemainSize(uint32_t remainSize)
		{
			uint32_t newSize = _size + remainSize;
			if (newSize > _capacity)
			{
				Resize(newSize);
			}
		}

		void Resize(uint32_t newSize)
		{
			_capacity = newSize = Round2Exp(newSize);
			uint8_t* oldData = _data;
			_data = (uint8_t*)IL2CPP_MALLOC(newSize);
			std::memcpy(_data, oldData, _size);
			IL2CPP_FREE(oldData);
		}
	};
}
}