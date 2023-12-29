#include "TemporaryMemoryArena.h"

namespace hybridclr
{
namespace transform
{

	TemporaryMemoryArena::Block TemporaryMemoryArena::AllocBlock(size_t size)
	{
		void* data = HYBRIDCLR_MALLOC(size);
		return { data, size };
	}

	void TemporaryMemoryArena::Begin()
	{
		IL2CPP_ASSERT(_buf == nullptr);
		IL2CPP_ASSERT(_size == 0);
		IL2CPP_ASSERT(_pos == 0);
		RequireSize(kMinBlockSize);
	}

	void TemporaryMemoryArena::End()
	{
		if (_buf)
		{
			HYBRIDCLR_FREE(_buf);
			//_buf = nullptr;
			//_size = _pos = 0;
		}
		for (auto& block : _useOuts)
		{
			HYBRIDCLR_FREE(block.data);
		}
	}
}
}