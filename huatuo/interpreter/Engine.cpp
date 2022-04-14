#include "Engine.h"

#include "Interpreter.h"
#include "MemoryUtil.h"

namespace huatuo
{
namespace interpreter
{

	static void CopyArgs(StackObject* dstBase, StackObject* argBase, ArgDesc* args, uint32_t paramCount, uint32_t totalParamStackObjectSize)
	{
		uint32_t argOffset = 0;
		for (uint32_t i = 0, n = paramCount; i < n; i++)
		{
			ArgDesc& arg = args[i];
			StackObject* dst = dstBase + argOffset;
			StackObject* src = argBase + i;
			switch (arg.type)
			{
			case LocationDataType::I1:
			{
				dst->i64 = *(int8_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::U1:
			{
				dst->i64 = *(uint8_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::I2:
			{
				dst->i64 = *(int16_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::U2:
			{
				dst->i64 = *(uint16_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::U8:
			{
				dst->i64 = *(int64_t*)src;
				++argOffset;
				break;
			}
			case LocationDataType::S_16:
			{
				// when size > 8, arg is ref to struct
				Copy16(dst, src->ptr);
				argOffset += 2;
				break;
			}
			case LocationDataType::S_24:
			{
				Copy24(dst, src->ptr);
				argOffset += 3;
				break;
			}
			case LocationDataType::S_32:
			{
				Copy32(dst, src->ptr);
				argOffset += 4;
				break;
			}
			default:
			{
				std::memcpy(dst, src->ptr, arg.stackObjectSize * sizeof(StackObject));
				argOffset += arg.stackObjectSize;
				break;
			}
			}
		}
		IL2CPP_ASSERT(argOffset == totalParamStackObjectSize);
	}


	InterpFrame* InterpFrameGroup::EnterFrame(const InterpMethodInfo* imi, StackObject* argBase, bool withArgStack)
	{
		ptrdiff_t oldStackTop = _machineState.GetStackTop();
		InterpFrame* newFrame;
		if (withArgStack)
		{
			StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize - imi->argStackObjectSize);

			newFrame = _machineState.PushFrame();
			*newFrame = { imi, argBase, oldStackTop, nullptr, nullptr, nullptr, {}, {} };
			_frames.push(newFrame);
		}
		else
		{
			StackObject* stackBasePtr = _machineState.AllocStackSlot(imi->maxStackSize);

			newFrame = _machineState.PushFrame();
			*newFrame = { imi, stackBasePtr, oldStackTop, nullptr, nullptr, nullptr, {}, {} };
			_frames.push(newFrame);

			// if not prepare arg stack. copy from args
			if (!withArgStack && imi->args)
			{
				IL2CPP_ASSERT(imi->argCount == metadata::GetActualArgumentNum(imi->method));
				if (imi->isTrivialCopyArgs)
				{
					std::memcpy(stackBasePtr, argBase, imi->argStackObjectSize * sizeof(StackObject));
				}
				else
				{
					CopyArgs(stackBasePtr, argBase, imi->args, imi->argCount, imi->argStackObjectSize);
				}
			}
		}
		PUSH_STACK_FRAME(imi->method);
		return newFrame;
	}

}
}

