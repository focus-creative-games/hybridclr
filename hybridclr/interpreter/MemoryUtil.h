#pragma once
#include "InterpreterDefs.h"

namespace hybridclr
{
namespace interpreter
{

	inline void Copy1(void* dst, void* src)
	{
		*(uint8_t*)dst = *(uint8_t*)src;
	}

	inline void Copy2(void* dst, void* src)
	{
		*(uint16_t*)dst = *(uint16_t*)src;
	}

	inline void Copy4(void* dst, void* src)
	{
		*(uint32_t*)dst = *(uint32_t*)src;
	}

	inline void Copy8(void* dst, void* src)
	{
		*(uint64_t*)dst = *(uint64_t*)src;
	}

	inline void Copy12(void* dst, void* src)
	{
		if (dst <= src)
		{
			*(uint64_t*)dst = *(uint64_t*)src;
			*(uint32_t*)((byte*)dst + 8) = *(uint32_t*)((byte*)src + 8);
		}
		else
		{
			*(uint32_t*)((byte*)dst + 8) = *(uint32_t*)((byte*)src + 8);
			*(uint64_t*)dst = *(uint64_t*)src;
		}
	}

	inline void Copy16(void* dst, void* src)
	{
		if (dst <= src)
		{
			*(uint64_t*)dst = *(uint64_t*)src;
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
		}
		else
		{
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)dst = *(uint64_t*)src;
		}
	}

	inline void Copy20(void* dst, void* src)
	{
		if (dst <= src)
		{
			*(uint64_t*)dst = *(uint64_t*)src;
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint32_t*)((byte*)dst + 16) = *(uint32_t*)((byte*)src + 16);
		}
		else
		{
			*(uint32_t*)((byte*)dst + 16) = *(uint32_t*)((byte*)src + 16);
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)dst = *(uint64_t*)src;
		}
	}

	inline void Copy24(void* dst, void* src)
	{
		if (dst <= src)
		{
			*(uint64_t*)dst = *(uint64_t*)src;
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)((byte*)dst + 16) = *(uint64_t*)((byte*)src + 16);
		}
		else
		{
			*(uint64_t*)((byte*)dst + 16) = *(uint64_t*)((byte*)src + 16);
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)dst = *(uint64_t*)src;
		}
	}

	inline void Copy28(void* dst, void* src)
	{
		if (dst <= src)
		{
			*(uint64_t*)dst = *(uint64_t*)src;
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)((byte*)dst + 16) = *(uint64_t*)((byte*)src + 16);
			*(uint32_t*)((byte*)dst + 24) = *(uint32_t*)((byte*)src + 24);
		}
		else
		{
			*(uint32_t*)((byte*)dst + 24) = *(uint32_t*)((byte*)src + 24);
			*(uint64_t*)((byte*)dst + 16) = *(uint64_t*)((byte*)src + 16);
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)dst = *(uint64_t*)src;
		}
	}

	inline void Copy32(void* dst, void* src)
	{
		if (dst <= src)
		{
			*(uint64_t*)dst = *(uint64_t*)src;
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)((byte*)dst + 16) = *(uint64_t*)((byte*)src + 16);
			*(uint64_t*)((byte*)dst + 24) = *(uint64_t*)((byte*)src + 24);
		}
		else
		{
			*(uint64_t*)((byte*)dst + 24) = *(uint64_t*)((byte*)src + 24);
			*(uint64_t*)((byte*)dst + 16) = *(uint64_t*)((byte*)src + 16);
			*(uint64_t*)((byte*)dst + 8) = *(uint64_t*)((byte*)src + 8);
			*(uint64_t*)dst = *(uint64_t*)src;
		}
	}

	inline void CopyStackObject(StackObject* dst, void* vsrc, uint32_t count)
	{
		StackObject* src = (StackObject*)vsrc;
		IL2CPP_ASSERT(dst + count <= src || src + count <= dst);
		switch (count)
		{
		case 8: dst[7] = src[7];
		case 7: dst[6] = src[6];
		case 6: dst[5] = src[5];
		case 5: dst[4] = src[4];
		case 4: dst[3] = src[3];
		case 3: dst[2] = src[2];
		case 2: dst[1] = src[1];
		case 1: *dst = *src; break;
		case 0: break;
		default: std::memcpy(dst, src, count * sizeof(StackObject));
		}
	}

	inline void CopyBySize(void* dst, void* src, uint32_t size)
	{
		switch (size)
		{
		case 1: Copy1(dst, src); break;
		default: std::memmove(dst, src, size); break;
		}
	}

	inline void InitDefault1(void* dst)
	{
		*(uint8_t*)dst = 0;
	}

	inline void InitDefault2(void* dst)
	{
		*(uint16_t*)dst = 0;
	}

	inline void InitDefault4(void* dst)
	{
		*(uint32_t*)dst = 0;
	}

	inline void InitDefault8(void* dst)
	{
		*(uint64_t*)dst = 0;
	}

	inline void InitDefault12(void* dst)
	{
		int32_t* p = (int32_t*)dst;
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
	}

	inline void InitDefault16(void* dst)
	{
		*(uint64_t*)dst = 0;
		*(uint64_t*)((byte*)dst + 8) = 0;
	}

	inline void InitDefault20(void* dst)
	{
		int32_t* p = (int32_t*)dst;
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
		p[3] = 0;
		p[4] = 0;
	}

	inline void InitDefault24(void* dst)
	{
		*(uint64_t*)dst = 0;
		*(uint64_t*)((byte*)dst + 8) = 0;
		*(uint64_t*)((byte*)dst + 16) = 0;
	}

	inline void InitDefault28(void* dst)
	{
		int32_t* p = (int32_t*)dst;
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
		p[3] = 0;
		p[4] = 0;
		p[5] = 0;
		p[6] = 0;
	}

	inline void InitDefault32(void* dst)
	{
		*(uint64_t*)dst = 0;
		*(uint64_t*)((byte*)dst + 8) = 0;
		*(uint64_t*)((byte*)dst + 16) = 0;
		*(uint64_t*)((byte*)dst + 24) = 0;
	}

	inline void InitDefaultN(void* dst, size_t size)
	{
		std::memset(dst, 0, size);
	}
}
}
