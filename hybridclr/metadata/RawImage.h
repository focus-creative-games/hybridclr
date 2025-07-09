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


	private:


	};
}
}