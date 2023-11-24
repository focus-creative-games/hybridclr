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

		BasicBlockSpliter(const metadata::MethodBody& body) : _body(body) { }

		void SplitBasicBlocks();

		const std::set<uint32_t>& GetSplitOffsets() const { return _splitOffsets; }
	private:
		const metadata::MethodBody& _body;
		std::set<uint32_t> _splitOffsets;

		void SplitNormal(const byte* ilcodeStart, uint32_t codeSize, Uin32Set& ilOffsets);
		void SplitExceptionHandles(const byte* ilcodeStart, uint32_t codeSize, const std::vector<metadata::ExceptionClause>& exceptionClauses);
	};
}
}
