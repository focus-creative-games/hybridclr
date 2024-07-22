#pragma once

#include "RawImageBase.h"

namespace hybridclr
{
namespace metadata
{

	class RawImage : public RawImageBase
	{
	public:
		RawImage(): RawImageBase()
		{

		}

		LoadImageErrorCode LoadCLIHeader(uint32_t& entryPointToken, uint32_t& metadataRva, uint32_t& metadataSize) override;

		Il2CppString* GetUserStringBlogByIndex(uint32_t index) const override
		{
			IL2CPP_ASSERT(index >= 0 && (uint32_t)index < _streamUS.size);
			const byte* str = _streamUS.data + index;
			uint32_t lengthSize;
			uint32_t stringLength = BlobReader::ReadCompressedUint32(str, lengthSize);
			return CreateUserString((const char*)(str + lengthSize), stringLength);
		}


	private:


	};
}
}