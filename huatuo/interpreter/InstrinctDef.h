#pragma once
#include "../CommonDef.h"

namespace huatuo
{
namespace interpreter
{

	struct HtVector2
	{
		float x;
		float y;
	};
	static_assert(sizeof(HtVector2) == 8, "Vector2");

	struct HtVector3
	{
		float x;
		float y;
		float z;
	};
	static_assert(sizeof(HtVector3) == 12, "Vector3");

	struct HtVector4
	{
		float x;
		float y;
		float z;
		float w;
	};
	static_assert(sizeof(HtVector4) == 16, "Vector4");

#pragma endregion

}
}
