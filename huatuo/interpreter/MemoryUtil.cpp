#include "MemoryUtil.h"

namespace huatuo
{
namespace interpreter
{
	void FixValueByTypeSlow(void* retValue, const Il2CppType* type)
	{
		switch (type->type)
		{
		case IL2CPP_TYPE_BOOLEAN:
		case IL2CPP_TYPE_U1:
			*(int32_t*)retValue = *(uint8_t*)retValue;
			break;
		case IL2CPP_TYPE_I1:
			*(int32_t*)retValue = *(int8_t*)retValue;
			break;
		case IL2CPP_TYPE_I2:
			*(int32_t*)retValue = *(int16_t*)retValue;
			break;
		case IL2CPP_TYPE_U2:
		case IL2CPP_TYPE_CHAR:
			*(int32_t*)retValue = *(uint16_t*)retValue;
			break;
		default: break;
		}
	}
}
}