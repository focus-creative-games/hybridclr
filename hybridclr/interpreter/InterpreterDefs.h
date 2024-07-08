#pragma once
#include "../CommonDef.h"
#include "../metadata/MetadataDef.h"

namespace hybridclr
{
	namespace interpreter
	{

		// from obj or arg
		enum class LocationDataType : uint8_t
		{
			I1,
			U1,
			I2,
			U2,
			U8,
			S_N,  // struct size = 3，5，6，7， > 8, size is described by stackObjectSize
		};

		union StackObject
		{
			uint64_t __u64;
			void* ptr; // can't adjust position. will raise native_invoke init args bugs.
			bool b;
			int8_t i8;
			uint8_t u8;
			int16_t i16;
			uint16_t u16;
			int32_t i32;
			uint32_t u32;
			int64_t i64;
			uint64_t u64;
			float f4;
			double f8;
			Il2CppObject* obj;
			Il2CppString* str;
			Il2CppObject** ptrObj;
		};

		static_assert(sizeof(StackObject) == 8, "requrie 8 bytes");


		enum class ExceptionFlowType
		{
			Exception,
			Catch,
			Leave,
		};

		struct InterpMethodInfo;

		struct ExceptionFlowInfo
		{
			ExceptionFlowType exFlowType;
			int32_t throwOffset;
			Il2CppException* ex;
			int32_t nextExClauseIndex;
			int32_t leaveTarget;
		};

		struct InterpFrame
		{
			const MethodInfo* method;
			StackObject* stackBasePtr;
			int32_t oldStackTop;
			void* ret;
			byte* ip;

			ExceptionFlowInfo* exFlowBase;
			int32_t exFlowCount;
			int32_t exFlowCapaticy;

			int32_t oldLocalPoolBottomIdx;

			ExceptionFlowInfo* GetCurExFlow() const
			{
				return exFlowCount > 0 ? exFlowBase + exFlowCount - 1 : nullptr;
			}

			ExceptionFlowInfo* GetPrevExFlow() const
			{
				return exFlowCount > 1 ? exFlowBase + exFlowCount - 2 : nullptr;
			}
		};

		struct InterpExceptionClause
		{
			metadata::CorILExceptionClauseType flags;
			int32_t tryBeginOffset;
			int32_t tryEndOffset;
			int32_t handlerBeginOffset;
			int32_t handlerEndOffset;
			int32_t filterBeginOffset;
			Il2CppClass* exKlass;
		};

		struct MethodArgDesc
		{
			bool passbyValWhenInvoke;
			LocationDataType type;
			uint16_t stackObjectSize;
		};

		struct InterpMethodInfo
		{
			byte* codes;
			MethodArgDesc* args;
			uint64_t* resolveDatas;
			const InterpExceptionClause* exClauses;
			uint32_t argStackObjectSize;
			uint32_t retStackObjectSize : 24;
			uint32_t initLocals : 8;
			uint32_t localStackSize; // args + locals StackObject size
			uint32_t maxStackSize; // args + locals + evalstack size
			uint32_t argCount : 8;
			uint32_t codeLength : 24;
			uint32_t localVarBaseOffset;
			uint32_t evalStackBaseOffset;
			uint32_t exClauseCount;
		};
	}
}