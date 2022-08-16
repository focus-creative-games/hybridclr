#include "MethodBridge.h"

#include <codegen/il2cpp-codegen-metadata.h>
#include "vm/ClassInlines.h"
#include "vm/Object.h"
#include "vm/Class.h"

#include "../metadata/MetadataModule.h"
#include "../metadata/MetadataUtil.h"

#include "Interpreter.h"
#include "MemoryUtil.h"
#include "InstrinctDef.h"

using namespace hybridclr::interpreter;
using hybridclr::GetInterpreterDirectlyCallMethodPointer;

#if HYBRIDCLR_ABI_ARM_64
//!!!{{INVOKE_STUB

static void __M2N_i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i16i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i16i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i16i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i16i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16i4i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int32_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i8i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8i4i4i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i16i8i4i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i16i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i16i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i16i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8i8i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i16i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i16i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, double __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i16sri4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(uint64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i16vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize16 (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    *(ValueTypeSize16*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int16_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int16_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int16_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i16i4i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i1i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i2i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i8i2i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i2i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i2i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i2i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i4i4i4vf3i4r4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, HtVector3f __arg4, int32_t __arg5, float __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(HtVector3f*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i1i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i4i4r4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i1i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i8i4i8i4i4i4i4i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize16 __arg7, ValueTypeSize16 __arg8, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i1i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i8i16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i8i8i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i1i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i4i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int8_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i8i4i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i1i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i8i8r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8i8sri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, double __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8r8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, double __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8sri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8vd2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector2d __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2d*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8vf3i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8vf3i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i8vf4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i8vf4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(float __arg0, float __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(double __arg0, double __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1sri2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1sri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1sri8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1sri8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1vd2vd2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector2d __arg0, HtVector2d __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2d*)(localVarBase+argVarIndexs[0]), *(HtVector2d*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1vf4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1vf4i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, int8_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1vf4i4i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1vf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, float __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(HtVector4f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int16_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int16_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int16_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i1i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i4i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i4i8i4i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i8i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i4i8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, uint64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i4i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i8i8i4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i8i8i4i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i4i8i4i4i1i1sri4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int8_t __arg7, uint64_t __arg8, int32_t __arg9, int64_t __arg10, int64_t __arg11, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), (uint64_t)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_i4i8i8i4i8i4i4i1i1sri4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int8_t __arg7, uint64_t __arg8, int32_t __arg9, int64_t __arg10, int64_t __arg11, int64_t __arg12, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), (uint64_t)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), *(int64_t*)(localVarBase+argVarIndexs[12]), method);
}


static void __M2N_i4i8i8i4i8i4i4i1i1sri4i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int8_t __arg7, uint64_t __arg8, int32_t __arg9, int64_t __arg10, int64_t __arg11, int64_t __arg12, int32_t __arg13, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), (uint64_t)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), *(int64_t*)(localVarBase+argVarIndexs[12]), *(int32_t*)(localVarBase+argVarIndexs[13]), method);
}


static void __M2N_i4i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i8i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, double __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8vf4i8vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, HtVector2f __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4sri1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(uint64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4sri1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(uint64_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4sri1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(uint64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4vf4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(HtVector4f __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4vf4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(HtVector4f __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4vf4i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(HtVector4f __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4vf4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(HtVector4f __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4vf4i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(HtVector4f __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, int8_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i16i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int8_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int8_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int8_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int16_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int16_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i4i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i4i4i4i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i4i4i4i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i4i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i4i8i8i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i16i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, ValueTypeSize16 __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i16i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i1i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i1i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i2i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i2i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i2i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i4i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i4i1i1i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i4i1i1i1i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i4i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i4i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, double __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8i16i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, ValueTypeSize16 __arg3, ValueTypeSize16 __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i1i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i1i4i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i1i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i1i4i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i1i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i2i2i1i1i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, int16_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int16_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int16_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i4i1i4i4i4i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize16 __arg7, ValueTypeSize16 __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i4i2i2i1i1i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int16_t __arg3, int16_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, int16_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int16_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i4i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i4i8i1i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int8_t __arg5, ValueTypeSize16 __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i4i4i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, ValueTypeSize16 __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int8_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i4i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i4i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i4i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i4i8i8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int8_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i4i8i8i8i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int8_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i8i8i8i4i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i1i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i8i1i4i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i8i8i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i4i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i4i4i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i4i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int8_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i8i4i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i8i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i8i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i8i8i1i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int64_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i8i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i8i8i4i4i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int64_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i8i8i8i8i8i4i4i8i8i8i8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, int64_t __arg10, int64_t __arg11, int32_t __arg12, int32_t __arg13, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), *(int32_t*)(localVarBase+argVarIndexs[12]), *(int32_t*)(localVarBase+argVarIndexs[13]), method);
}


static void __M2N_i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8i8i8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i8i8i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8i8i8i8i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int32_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i8i8i8i8r8i8i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, double __arg3, int64_t __arg4, int64_t __arg5, double __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(double*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(double*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, uint64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8i8i8srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, uint64_t __arg3, uint64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, double __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8i8sri8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, double __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8r8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, double __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, double __arg1, double __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8sri8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8vf3vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8vf3vf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8vf4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8i8vf4vf2r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, float __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8i8vf4vf2r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8i8vf4vf2r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, float __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i8i8vf4vf2r4i4i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, float __arg3, int32_t __arg4, int32_t __arg5, HtVector4f __arg6, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(HtVector4f*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i8i8vf4vf2r4i4i4vf4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, float __arg3, int32_t __arg4, int32_t __arg5, HtVector4f __arg6, int8_t __arg7, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(HtVector4f*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8r4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(float __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(float __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8r8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(double __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8r8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(double __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8srvf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(uint64_t __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8srvf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(uint64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8vf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8vf4i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8vf4i8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8vf4i8i2i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i8vf4i8i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int16_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8vf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8vf4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i8vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i8i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4r4r4i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, int64_t __arg2, float __arg3, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r4r4r4i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, int64_t __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r4r4r4i8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, int64_t __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4r4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, int64_t __arg3, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r4r4r4r4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4r4r4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r4r4r4r4r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4vf4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r4vf4r4r4r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4vf4r4r4r4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_r4vf4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r4vf4r4r4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, float __arg1, float __arg2, float __arg3, float __arg4, int64_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4vf4r4r4r4r4i8i8i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, float __arg1, float __arg2, float __arg3, float __arg4, int64_t __arg5, int64_t __arg6, int8_t __arg7, int32_t __arg8, int64_t __arg9, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_r4vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(HtVector4f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_r8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8i16r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSize16 __arg0, double __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r8i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, double __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i8r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, double __arg1, double __arg2, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8r8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(double __arg0, int32_t __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8r8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(double __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r8r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(double __arg0, double __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8vd2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(HtVector2d __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2d*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8vd3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(HtVector3d __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3d*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S108r4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(float __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S108srr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(uint64_t __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S108srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S120i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<120> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<120>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S120i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<120> (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<120>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i8S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int64_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i8S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int64_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S188i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<188> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<188>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S20i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S20i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S20sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S224i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<224> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<224>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S24i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S24i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S24i8i4i4i4sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S24i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S24i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S24i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24i8sri1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24i8sri1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S24i8srsri1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S24i8srsri1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S24i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24i8vf3i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(float __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24r4r4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(float __arg0, float __arg1, HtVector2f __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24r4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(float __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24srr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(uint64_t __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24srsrr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S28i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S28i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S28i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S32i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S32i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S32i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S32i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S32i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S32i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S36i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<36> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<36>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S40(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<40> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<40>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S40i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<40> (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(ValueTypeSize<40>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S40i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<40> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<40>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S40i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<40> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<40>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S48i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<48> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<48>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S48i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<48> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<48>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S48i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<48> (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<48>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S52i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<52> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<52>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S56i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<56> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<56>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S56i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<56> (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<56>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S56i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<56> (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<56>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S56i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<56> (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<56>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S64i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S64r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S64r4r4r4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, float __arg1, float __arg2, HtVector3f __arg3, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(HtVector3f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S64r4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64sri1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(uint64_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64srr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(uint64_t __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64srsrr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(uint64_t __arg0, uint64_t __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64srvf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(uint64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64vf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64vf3vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector3f __arg2, HtVector3f __arg3, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), *(HtVector3f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S64vf3vf3vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector3f __arg2, HtVector3f __arg3, HtVector3f __arg4, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), *(HtVector3f*)(localVarBase+argVarIndexs[3]), *(HtVector3f*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S64vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64vf3vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector3f __arg0, HtVector4f __arg1, HtVector3f __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S68(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<68> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<68>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S68i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<68> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<68>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S68i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<68> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<68>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S96(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<96> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<96>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S96i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<96> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<96>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S992i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<992> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<992>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_v(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vd2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(double __arg0, double __arg1, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vd2vd2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(HtVector2d __arg0, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2d*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd2vd2r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(HtVector2d __arg0, double __arg1, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2d*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vd2vd2vd2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2d (*NativeMethod)(HtVector2d __arg0, HtVector2d __arg1, const MethodInfo* method);
    *(HtVector2d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2d*)(localVarBase+argVarIndexs[0]), *(HtVector2d*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vd3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3d (*NativeMethod)(const MethodInfo* method);
    *(HtVector3d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vd3i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3d (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(HtVector3d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd3i8vd3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3d (*NativeMethod)(int64_t __arg0, HtVector3d __arg1, const MethodInfo* method);
    *(HtVector3d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3d*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vd3vd3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3d (*NativeMethod)(HtVector3d __arg0, const MethodInfo* method);
    *(HtVector3d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3d*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4d (*NativeMethod)(const MethodInfo* method);
    *(HtVector4d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vd4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4d (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(HtVector4d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vd4i8vd4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4d (*NativeMethod)(int64_t __arg0, HtVector4d __arg1, const MethodInfo* method);
    *(HtVector4d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4d*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vd4vd4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4d (*NativeMethod)(HtVector4d __arg0, const MethodInfo* method);
    *(HtVector4d*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4d*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vf2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf2i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2i8vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2i8vf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf2r4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(float __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf2vf2i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, int8_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf2vf2i1i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, int8_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vf2vf2i1i1i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, int8_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vf2vf2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, int64_t __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf2vf2i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf2vf2r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, float __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf2sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, uint64_t __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf2vf2i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, int64_t __arg2, float __arg3, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf2vf2vf2i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, int64_t __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf2vf2vf2i8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, int64_t __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vf2vf2vf2r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, float __arg2, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf2vf2vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, HtVector2f __arg2, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf2vf2vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector2f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf2vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf2vf4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf2vf4vf2vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, HtVector4f __arg2, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf2vf4vf2vf4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, HtVector4f __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf2vf4vf2vf4i1i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, HtVector4f __arg2, int8_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vf2vf4vf2vf4i1i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, HtVector4f __arg2, int8_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vf2vf4vf2vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector2f (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, HtVector4f __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(HtVector2f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vf3i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf3i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf3i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3i8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf3i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3i8vf3i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int32_t __arg2, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf3r4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(float __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf3vf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, float __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3vf3sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, uint64_t __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3vf3vf3i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, int8_t __arg2, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf3vf3vf3i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, int64_t __arg2, float __arg3, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf3vf3vf3i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, int64_t __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf3vf3vf3i8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, int64_t __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vf3vf3vf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, float __arg2, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf3vf3vf3r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf3vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf3vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector3f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf3vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector3f (*NativeMethod)(HtVector4f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector3f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4i4vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int32_t __arg0, HtVector4f __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4i4vf4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int32_t __arg0, HtVector4f __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf4i4vf4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int32_t __arg0, HtVector4f __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4i8r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4i8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4i8r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf4i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, int64_t __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, int64_t __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4r4r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4r4r4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, int8_t __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vf4r4r4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vf4r4r4r4r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vf4r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vf4r4r4r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, float __arg7, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vf4r4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4r4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(float __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4srvf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(uint64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4vf2sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector2f __arg0, uint64_t __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf2vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector2f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4vf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector3f __arg0, float __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf3sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector3f __arg0, uint64_t __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector3f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vf4vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, float __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, uint64_t __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, HtVector3f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, HtVector4f __arg1, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vf4vf4vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, HtVector4f __arg1, float __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vf4vf4vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef HtVector4f (*NativeMethod)(HtVector4f __arg0, HtVector4f __arg1, HtVector4f __arg2, const MethodInfo* method);
    *(HtVector4f*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi16i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi16i16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi16i16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize16 __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize16*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i1vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i1vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, HtVector4f __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int16_t __arg0, int16_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi2i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int16_t __arg0, int16_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i4i4i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int16_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int16_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, HtVector3f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, uint64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i16i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i16i16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i16i16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i16i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i16sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, uint64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i16sri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, ValueTypeSize16 __arg1, uint64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i1i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i1i1i1i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i1i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i1i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i1r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, float __arg3, float __arg4, float __arg5, float __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i1i1vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i1vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int8_t __arg2, HtVector4f __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i4i4i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int8_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i1i4i4i8i4i16i16i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, ValueTypeSize16 __arg6, ValueTypeSize16 __arg7, int8_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i4i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i1i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i1i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int8_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int16_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i2i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int16_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int16_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, ValueTypeSize16 __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i1i1i1i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i4i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i1i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4i2i2i1i1i1i1i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int8_t __arg7, int8_t __arg8, int8_t __arg9, int8_t __arg10, int8_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), *(int8_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i4i2i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i4i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize16 __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i4i4i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, int8_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int8_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i4i4i4i4i4i4i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i4sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, HtVector4f __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(HtVector4f*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i4vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, HtVector4f __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(HtVector4f*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i4vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, HtVector4f __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i8i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i8i4i2i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int16_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i8i4i4i4i4i16i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize16 __arg7, ValueTypeSize16 __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i8i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i8i8i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int8_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i4i8i8i4i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i8i8i4i8i4i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i8i8i4i8i4i1i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int64_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i4i8i8i4i8i4i1i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int64_t __arg9, int32_t __arg10, int64_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i8i8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i8i8i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i4i8i8i8i4i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i4i8i8i8i4i1i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, int64_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i4i8i8i8i4i1i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, int64_t __arg8, int32_t __arg9, int64_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i4i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i4i8sri4i8i4i1i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, uint64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int64_t __arg9, int32_t __arg10, int64_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i4i8sri8i4i8i4i1i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, uint64_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int64_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8i4i8sri8i4i8i4i1i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, uint64_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int64_t __arg10, int32_t __arg11, int64_t __arg12, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int64_t*)(localVarBase+argVarIndexs[12]), method);
}


static void __M2N_vi8i4i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, int64_t __arg2, HtVector3f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(HtVector3f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, float __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, float __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, uint64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4sri1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, uint64_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i4sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, uint64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, uint64_t __arg2, uint64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, HtVector2f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, HtVector3f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i4vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, HtVector3f __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i4vf3vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, HtVector3f __arg2, HtVector4f __arg3, HtVector3f __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(HtVector3f*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int32_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i16i4i4i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i1i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i1i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int16_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i4i1i1i1i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int64_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i1i4i4i16i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, ValueTypeSize16 __arg6, ValueTypeSize16 __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i1i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i2i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int16_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i2i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int16_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int16_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i4i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int16_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int64_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, int32_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i8i4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i4i8i4i4i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int64_t __arg8, int64_t __arg9, int64_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int8_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i4sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i4sri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i4i8i1i1i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i8i4i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int8_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i8i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i4i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i8i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, uint64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i4i8sri1i1i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, uint64_t __arg4, int8_t __arg5, int8_t __arg6, int8_t __arg7, int32_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i4i8sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, uint64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i4i8sri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i4sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, uint64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i4srsri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, uint64_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8i16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i1i2i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int16_t __arg4, int16_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int16_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int16_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i4i8i16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, ValueTypeSize16 __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize16*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i4i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i1i8i4i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int8_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8i8i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i8i8i8i8i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int32_t __arg9, int64_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8i8i8i8i8i8i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8i8i8i8sri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, uint64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8r4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8r4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, double __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8r8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, double __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8sri4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8sri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8sri8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8sri8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8sri8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8sri8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8sri8i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8sri8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8i8sri8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8i8sri8i4i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8i8srvf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, uint64_t __arg2, HtVector2f __arg3, HtVector2f __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), *(HtVector2f*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8i8vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, HtVector2f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, HtVector2f __arg2, HtVector2f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8i8vf2vf2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, HtVector2f __arg2, HtVector2f __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8i8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, HtVector3f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8r4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, float __arg7, float __arg8, float __arg9, float __arg10, float __arg11, float __arg12, float __arg13, float __arg14, float __arg15, float __arg16, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), *(float*)(localVarBase+argVarIndexs[8]), *(float*)(localVarBase+argVarIndexs[9]), *(float*)(localVarBase+argVarIndexs[10]), *(float*)(localVarBase+argVarIndexs[11]), *(float*)(localVarBase+argVarIndexs[12]), *(float*)(localVarBase+argVarIndexs[13]), *(float*)(localVarBase+argVarIndexs[14]), *(float*)(localVarBase+argVarIndexs[15]), *(float*)(localVarBase+argVarIndexs[16]), method);
}


static void __M2N_vi8r4vf2vf2r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, float __arg1, HtVector2f __arg2, HtVector2f __arg3, float __arg4, float __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, double __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8r8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, double __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, double __arg1, double __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8sr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8sri1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8sri1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8sri4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8sri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8sri4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8sri4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8sri4i4i4i4i4i4sri4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, uint64_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, int32_t __arg12, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), (uint64_t)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int32_t*)(localVarBase+argVarIndexs[12]), method);
}


static void __M2N_vi8sri4i4i4i8i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8sri4i4sri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8sri4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8sri4i8i4i4i8i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int64_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8sri4i8i4i8i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8sri4i8i8i4i8i8i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int64_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8sri4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, float __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8sri4sri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int32_t __arg2, uint64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8sri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8sri8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8sri8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8sri8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8sri8i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8sri8i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8sri8i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8sri8i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8sri8i4i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8sri8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8sri8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8sri8i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8sri8i4i8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int8_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8sri8i4i8i4i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int8_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8sri8i4i8i4i8i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int8_t __arg7, int8_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8sri8i4i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8sri8i4i8i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8sri8i4i8i4i8i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int64_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8sri8i4i8i4i8i4i1i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int64_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8sri8i4i8i4i8i4i1i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int64_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8sri8i4i8i4i8i4i1i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, int8_t __arg8, int64_t __arg9, int32_t __arg10, int64_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int64_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int64_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8sri8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8sri8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8sri8i8i8i1srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, uint64_t __arg6, uint64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), (uint64_t)(localVarBase+argVarIndexs[6]), (uint64_t)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8sri8i8srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, uint64_t __arg4, uint64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), (uint64_t)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8srsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8srsri1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8srsri1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8srsri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8srsri4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8srsri4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8srsri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8srsri8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8srsri8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8srsrsrsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, uint64_t __arg3, uint64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8srsrsrsrsrr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, uint64_t __arg3, uint64_t __arg4, uint64_t __arg5, float __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), (uint64_t)(localVarBase+argVarIndexs[3]), (uint64_t)(localVarBase+argVarIndexs[4]), (uint64_t)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8srsrvf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, HtVector2f __arg3, HtVector2f __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), *(HtVector2f*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8srsrvf2vf2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, HtVector2f __arg3, HtVector2f __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), (uint64_t)(localVarBase+argVarIndexs[2]), *(HtVector2f*)(localVarBase+argVarIndexs[3]), *(HtVector2f*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8srvf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, uint64_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), (uint64_t)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vd3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3d __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3d*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8vf2i1i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int8_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf2i1i1i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int8_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8vf2i1i1i8i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int8_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8vf2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf2i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf2i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf2r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf2r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector2f __arg1, HtVector2f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8vf3i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf3i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf3i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf3r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf3vf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf3vf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, HtVector3f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector3f*)(localVarBase+argVarIndexs[2]), *(HtVector3f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf3vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf3vf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf3vf4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int8_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int8_t __arg8, int8_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int32_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int32_t __arg8, int8_t __arg9, int64_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi8vf3vf4i8i4i8i4i8i4i1i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, int64_t __arg7, int32_t __arg8, int8_t __arg9, int64_t __arg10, int8_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int64_t*)(localVarBase+argVarIndexs[10]), *(int8_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi8vf3vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf3vf4vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, HtVector3f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(HtVector3f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8vf4i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8vf4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf4i8i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi8vf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf4i8i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8vf4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf4r4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, float __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi8vf4vf2vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi8vf4vf2vf4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, HtVector4f __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8vf4vf2vf4i1i1i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, HtVector4f __arg3, int8_t __arg4, int8_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi8vf4vf2vf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector2f __arg2, HtVector4f __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi8vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi8vf4vf4vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, HtVector4f __arg1, HtVector4f __arg2, HtVector4f __arg3, HtVector4f __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(HtVector4f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), *(HtVector4f*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vr4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vr4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vr4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vr4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vr4r4r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, float __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vr4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vr4vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, HtVector2f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vr8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(double __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vr8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(double __arg0, double __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vr8r8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(double __arg0, double __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vsr(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(uint64_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vsri2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(uint64_t __arg0, int16_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vsri4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(uint64_t __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vsri8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(uint64_t __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vsri8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(uint64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))((uint64_t)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector2f __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vvf2vf2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector2f __arg0, HtVector2f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector2f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vvf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vvf3i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vvf3i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf3i8i1vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, int64_t __arg1, int8_t __arg2, HtVector4f __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(HtVector4f*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vvf3i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf3r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, float __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vvf3r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vvf3vf3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vvf3vf3vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf3vf3vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector4f __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vvf3vf3vf4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector3f __arg0, HtVector3f __arg1, HtVector4f __arg2, float __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector3f*)(localVarBase+argVarIndexs[0]), *(HtVector3f*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vvf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vvf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vvf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf4i8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vvf4i8i4i1r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vvf4i8i4i1r4vf4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, HtVector4f __arg5, float __arg6, float __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(HtVector4f*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vvf4i8i4i1r4vf4vf4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, HtVector4f __arg5, HtVector4f __arg6, float __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(HtVector4f*)(localVarBase+argVarIndexs[5]), *(HtVector4f*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vvf4i8i4i1r4vf4vf4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, HtVector4f __arg5, HtVector4f __arg6, HtVector4f __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(HtVector4f*)(localVarBase+argVarIndexs[5]), *(HtVector4f*)(localVarBase+argVarIndexs[6]), *(HtVector4f*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vvf4i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vvf4i8i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vvf4i8i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vvf4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vvf4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vvf4i8vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vvf4i8vf4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vvf4i8vf4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vvf4i8vf4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vvf4i8vf4i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vvf4i8vf4i4i4i4i4vf4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, HtVector4f __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(HtVector4f*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vvf4i8vf4i4i4i4i4vf4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, HtVector4f __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(HtVector4f*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vvf4i8vf4i4i4i4i4vf4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, int64_t __arg1, HtVector4f __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, HtVector4f __arg7, int64_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(HtVector4f*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(HtVector4f*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vvf4vf2vf2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(HtVector4f __arg0, HtVector2f __arg1, HtVector2f __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(HtVector4f*)(localVarBase+argVarIndexs[0]), *(HtVector2f*)(localVarBase+argVarIndexs[1]), *(HtVector2f*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


Managed2NativeMethodInfo hybridclr::interpreter::g_managed2nativeStub[] = 
{

	{"i1", __M2N_i1},
	{"i16", __M2N_i16},
	{"i16i1", __M2N_i16i1},
	{"i16i16", __M2N_i16i16},
	{"i16i16i16", __M2N_i16i16i16},
	{"i16i16i16i16", __M2N_i16i16i16i16},
	{"i16i16i16i8", __M2N_i16i16i16i8},
	{"i16i16i4", __M2N_i16i16i4},
	{"i16i16i4i4", __M2N_i16i16i4i4},
	{"i16i16i8", __M2N_i16i16i8},
	{"i16i16i8i4", __M2N_i16i16i8i4},
	{"i16i16i8i8", __M2N_i16i16i8i8},
	{"i16i2", __M2N_i16i2},
	{"i16i4", __M2N_i16i4},
	{"i16i4i16", __M2N_i16i4i16},
	{"i16i4i4", __M2N_i16i4i4},
	{"i16i8", __M2N_i16i8},
	{"i16i8i1", __M2N_i16i8i1},
	{"i16i8i16", __M2N_i16i8i16},
	{"i16i8i16i16", __M2N_i16i8i16i16},
	{"i16i8i16i8", __M2N_i16i8i16i8},
	{"i16i8i4", __M2N_i16i8i4},
	{"i16i8i4i4", __M2N_i16i8i4i4},
	{"i16i8i4i4i4i4i4i4i4i4i8", __M2N_i16i8i4i4i4i4i4i4i4i4i8},
	{"i16i8i4i4i4i4i4i4i4i8", __M2N_i16i8i4i4i4i4i4i4i4i8},
	{"i16i8i4i4i8", __M2N_i16i8i4i4i8},
	{"i16i8i4i8", __M2N_i16i8i4i8},
	{"i16i8i4i8i8", __M2N_i16i8i4i8i8},
	{"i16i8i8", __M2N_i16i8i8},
	{"i16i8i8i4", __M2N_i16i8i8i4},
	{"i16i8i8i4i8i8i4", __M2N_i16i8i8i4i8i8i4},
	{"i16i8i8i8", __M2N_i16i8i8i8},
	{"i16i8i8i8i4", __M2N_i16i8i8i8i4},
	{"i16i8i8sr", __M2N_i16i8i8sr},
	{"i16i8r8", __M2N_i16i8r8},
	{"i16i8sr", __M2N_i16i8sr},
	{"i16r4", __M2N_i16r4},
	{"i16r8", __M2N_i16r8},
	{"i16sr", __M2N_i16sr},
	{"i16sri4i8", __M2N_i16sri4i8},
	{"i16vf3", __M2N_i16vf3},
	{"i1i1", __M2N_i1i1},
	{"i1i16", __M2N_i1i16},
	{"i1i16i16", __M2N_i1i16i16},
	{"i1i16i8", __M2N_i1i16i8},
	{"i1i1i1", __M2N_i1i1i1},
	{"i1i1i8i8", __M2N_i1i1i8i8},
	{"i1i1i8i8i8", __M2N_i1i1i8i8i8},
	{"i1i2", __M2N_i1i2},
	{"i1i2i2", __M2N_i1i2i2},
	{"i1i2i8", __M2N_i1i2i8},
	{"i1i2i8i8", __M2N_i1i2i8i8},
	{"i1i4", __M2N_i1i4},
	{"i1i4i4", __M2N_i1i4i4},
	{"i1i4i4i8", __M2N_i1i4i4i8},
	{"i1i8", __M2N_i1i8},
	{"i1i8i1", __M2N_i1i8i1},
	{"i1i8i16", __M2N_i1i8i16},
	{"i1i8i16i16", __M2N_i1i8i16i16},
	{"i1i8i16i4", __M2N_i1i8i16i4},
	{"i1i8i16i4i4i4i8i8", __M2N_i1i8i16i4i4i4i8i8},
	{"i1i8i16i8", __M2N_i1i8i16i8},
	{"i1i8i1i8", __M2N_i1i8i1i8},
	{"i1i8i2", __M2N_i1i8i2},
	{"i1i8i2i2i4", __M2N_i1i8i2i2i4},
	{"i1i8i2i4", __M2N_i1i8i2i4},
	{"i1i8i2i4i4i8i8", __M2N_i1i8i2i4i4i8i8},
	{"i1i8i2i4i8", __M2N_i1i8i2i4i8},
	{"i1i8i2i4i8i8", __M2N_i1i8i2i4i8i8},
	{"i1i8i2i8", __M2N_i1i8i2i8},
	{"i1i8i2i8i4", __M2N_i1i8i2i8i4},
	{"i1i8i2i8i4i4", __M2N_i1i8i2i8i4i4},
	{"i1i8i2i8i8", __M2N_i1i8i2i8i8},
	{"i1i8i4", __M2N_i1i8i4},
	{"i1i8i4i1", __M2N_i1i8i4i1},
	{"i1i8i4i4", __M2N_i1i8i4i4},
	{"i1i8i4i4i4", __M2N_i1i8i4i4i4},
	{"i1i8i4i4i4i1", __M2N_i1i8i4i4i4i1},
	{"i1i8i4i4i4i4", __M2N_i1i8i4i4i4i4},
	{"i1i8i4i4i4vf3i4r4i8i8i8", __M2N_i1i8i4i4i4vf3i4r4i8i8i8},
	{"i1i8i4i4i8", __M2N_i1i8i4i4i8},
	{"i1i8i4i4i8i8", __M2N_i1i8i4i4i8i8},
	{"i1i8i4i4r4i8i8i8", __M2N_i1i8i4i4r4i8i8i8},
	{"i1i8i4i8", __M2N_i1i8i4i8},
	{"i1i8i4i8i1", __M2N_i1i8i4i8i1},
	{"i1i8i4i8i4", __M2N_i1i8i4i8i4},
	{"i1i8i4i8i4i4i4", __M2N_i1i8i4i8i4i4i4},
	{"i1i8i4i8i4i4i4i4i16i16", __M2N_i1i8i4i8i4i4i4i4i16i16},
	{"i1i8i4i8i8", __M2N_i1i8i4i8i8},
	{"i1i8i4i8i8i8", __M2N_i1i8i4i8i8i8},
	{"i1i8i8", __M2N_i1i8i8},
	{"i1i8i8i1", __M2N_i1i8i8i1},
	{"i1i8i8i16i4i8", __M2N_i1i8i8i16i4i8},
	{"i1i8i8i16i8", __M2N_i1i8i8i16i8},
	{"i1i8i8i1i8", __M2N_i1i8i8i1i8},
	{"i1i8i8i4", __M2N_i1i8i8i4},
	{"i1i8i8i4i1", __M2N_i1i8i8i4i1},
	{"i1i8i8i4i4", __M2N_i1i8i8i4i4},
	{"i1i8i8i4i4i8", __M2N_i1i8i8i4i4i8},
	{"i1i8i8i4i4i8i8", __M2N_i1i8i8i4i4i8i8},
	{"i1i8i8i4i4i8i8i8", __M2N_i1i8i8i4i4i8i8i8},
	{"i1i8i8i4i8", __M2N_i1i8i8i4i8},
	{"i1i8i8i4i8i1", __M2N_i1i8i8i4i8i1},
	{"i1i8i8i4i8i1i8", __M2N_i1i8i8i4i8i1i8},
	{"i1i8i8i4i8i8", __M2N_i1i8i8i4i8i8},
	{"i1i8i8i8", __M2N_i1i8i8i8},
	{"i1i8i8i8i1", __M2N_i1i8i8i8i1},
	{"i1i8i8i8i4", __M2N_i1i8i8i8i4},
	{"i1i8i8i8i4i4i8i8i8i8", __M2N_i1i8i8i8i4i4i8i8i8i8},
	{"i1i8i8i8i4i8", __M2N_i1i8i8i8i4i8},
	{"i1i8i8i8i8", __M2N_i1i8i8i8i8},
	{"i1i8i8i8i8i1", __M2N_i1i8i8i8i8i1},
	{"i1i8i8i8i8i4", __M2N_i1i8i8i8i8i4},
	{"i1i8i8i8i8i8", __M2N_i1i8i8i8i8i8},
	{"i1i8i8i8i8i8i8", __M2N_i1i8i8i8i8i8i8},
	{"i1i8i8r4i8", __M2N_i1i8i8r4i8},
	{"i1i8i8sr", __M2N_i1i8i8sr},
	{"i1i8i8sri8", __M2N_i1i8i8sri8},
	{"i1i8r4", __M2N_i1i8r4},
	{"i1i8r4r4", __M2N_i1i8r4r4},
	{"i1i8r4r4i8", __M2N_i1i8r4r4i8},
	{"i1i8r8", __M2N_i1i8r8},
	{"i1i8r8i8i8", __M2N_i1i8r8i8i8},
	{"i1i8sr", __M2N_i1i8sr},
	{"i1i8sri8", __M2N_i1i8sri8},
	{"i1i8vd2", __M2N_i1i8vd2},
	{"i1i8vf2", __M2N_i1i8vf2},
	{"i1i8vf3", __M2N_i1i8vf3},
	{"i1i8vf3i1", __M2N_i1i8vf3i1},
	{"i1i8vf3i8", __M2N_i1i8vf3i8},
	{"i1i8vf3vf3", __M2N_i1i8vf3vf3},
	{"i1i8vf4", __M2N_i1i8vf4},
	{"i1i8vf4i1", __M2N_i1i8vf4i1},
	{"i1i8vf4i4", __M2N_i1i8vf4i4},
	{"i1i8vf4i4i4", __M2N_i1i8vf4i4i4},
	{"i1r4", __M2N_i1r4},
	{"i1r4r4", __M2N_i1r4r4},
	{"i1r4r4r4", __M2N_i1r4r4r4},
	{"i1r4r4r4r4", __M2N_i1r4r4r4r4},
	{"i1r8", __M2N_i1r8},
	{"i1r8r8", __M2N_i1r8r8},
	{"i1sr", __M2N_i1sr},
	{"i1sri2", __M2N_i1sri2},
	{"i1sri4", __M2N_i1sri4},
	{"i1sri8", __M2N_i1sri8},
	{"i1sri8i4i8", __M2N_i1sri8i4i8},
	{"i1sri8i8i8", __M2N_i1sri8i8i8},
	{"i1srsr", __M2N_i1srsr},
	{"i1vd2vd2", __M2N_i1vd2vd2},
	{"i1vf2vf2", __M2N_i1vf2vf2},
	{"i1vf3vf3", __M2N_i1vf3vf3},
	{"i1vf4i1i8", __M2N_i1vf4i1i8},
	{"i1vf4i1i8i8", __M2N_i1vf4i1i8i8},
	{"i1vf4i4i1i8i8", __M2N_i1vf4i4i1i8i8},
	{"i1vf4i8", __M2N_i1vf4i8},
	{"i1vf4i8i8", __M2N_i1vf4i8i8},
	{"i1vf4r4", __M2N_i1vf4r4},
	{"i1vf4vf4", __M2N_i1vf4vf4},
	{"i2", __M2N_i2},
	{"i2i1", __M2N_i2i1},
	{"i2i16", __M2N_i2i16},
	{"i2i2", __M2N_i2i2},
	{"i2i2i2", __M2N_i2i2i2},
	{"i2i2i8", __M2N_i2i2i8},
	{"i2i4", __M2N_i2i4},
	{"i2i8", __M2N_i2i8},
	{"i2i8i2", __M2N_i2i8i2},
	{"i2i8i4", __M2N_i2i8i4},
	{"i2i8i4i8", __M2N_i2i8i4i8},
	{"i2i8i8", __M2N_i2i8i8},
	{"i2r4", __M2N_i2r4},
	{"i2r8", __M2N_i2r8},
	{"i2sr", __M2N_i2sr},
	{"i4", __M2N_i4},
	{"i4i1", __M2N_i4i1},
	{"i4i16", __M2N_i4i16},
	{"i4i16i16", __M2N_i4i16i16},
	{"i4i16i4i8", __M2N_i4i16i4i8},
	{"i4i2", __M2N_i4i2},
	{"i4i2i2", __M2N_i4i2i2},
	{"i4i4", __M2N_i4i4},
	{"i4i4i1", __M2N_i4i4i1},
	{"i4i4i4", __M2N_i4i4i4},
	{"i4i4i4i1", __M2N_i4i4i4i1},
	{"i4i4i4i4", __M2N_i4i4i4i4},
	{"i4i4i4i4i4", __M2N_i4i4i4i4i4},
	{"i4i4i4i8", __M2N_i4i4i4i8},
	{"i4i4i4vf4", __M2N_i4i4i4vf4},
	{"i4i4i8", __M2N_i4i4i8},
	{"i4i4i8i4i8", __M2N_i4i4i8i4i8},
	{"i4i4i8i4i8i8", __M2N_i4i4i8i4i8i8},
	{"i4i4i8i8", __M2N_i4i4i8i8},
	{"i4i4i8i8i4i8", __M2N_i4i4i8i8i4i8},
	{"i4i4i8i8i8", __M2N_i4i4i8i8i8},
	{"i4i4i8i8i8i4i8", __M2N_i4i4i8i8i8i4i8},
	{"i4i4i8i8i8i8", __M2N_i4i4i8i8i8i8},
	{"i4i4vf4", __M2N_i4i4vf4},
	{"i4i8", __M2N_i4i8},
	{"i4i8i1", __M2N_i4i8i1},
	{"i4i8i16", __M2N_i4i8i16},
	{"i4i8i1i4", __M2N_i4i8i1i4},
	{"i4i8i1i4i8i4", __M2N_i4i8i1i4i8i4},
	{"i4i8i1i8i4", __M2N_i4i8i1i8i4},
	{"i4i8i2", __M2N_i4i8i2},
	{"i4i8i2i4", __M2N_i4i8i2i4},
	{"i4i8i2i4i4", __M2N_i4i8i2i4i4},
	{"i4i8i4", __M2N_i4i8i4},
	{"i4i8i4i1", __M2N_i4i8i4i1},
	{"i4i8i4i4", __M2N_i4i8i4i4},
	{"i4i8i4i4i1", __M2N_i4i8i4i4i1},
	{"i4i8i4i4i4", __M2N_i4i8i4i4i4},
	{"i4i8i4i4i8", __M2N_i4i8i4i4i8},
	{"i4i8i4i4i8i4", __M2N_i4i8i4i4i8i4},
	{"i4i8i4i4i8i4i4", __M2N_i4i8i4i4i8i4i4},
	{"i4i8i4i4i8i8", __M2N_i4i8i4i4i8i8},
	{"i4i8i4i8", __M2N_i4i8i4i8},
	{"i4i8i4i8i4", __M2N_i4i8i4i8i4},
	{"i4i8i4i8i4i4", __M2N_i4i8i4i8i4i4},
	{"i4i8i4i8i4i4i1", __M2N_i4i8i4i8i4i4i1},
	{"i4i8i4i8i4i4i1i8", __M2N_i4i8i4i8i4i4i1i8},
	{"i4i8i4i8i4i4i4", __M2N_i4i8i4i8i4i4i4},
	{"i4i8i4i8i4i4i8i4", __M2N_i4i8i4i8i4i4i8i4},
	{"i4i8i4i8i8", __M2N_i4i8i4i8i8},
	{"i4i8i4sr", __M2N_i4i8i4sr},
	{"i4i8i4vf4", __M2N_i4i8i4vf4},
	{"i4i8i8", __M2N_i4i8i8},
	{"i4i8i8i1", __M2N_i4i8i8i1},
	{"i4i8i8i1i4", __M2N_i4i8i8i1i4},
	{"i4i8i8i1i8", __M2N_i4i8i8i1i8},
	{"i4i8i8i2", __M2N_i4i8i8i2},
	{"i4i8i8i2i4", __M2N_i4i8i8i2i4},
	{"i4i8i8i2i4i4", __M2N_i4i8i8i2i4i4},
	{"i4i8i8i2i4i4i4", __M2N_i4i8i8i2i4i4i4},
	{"i4i8i8i4", __M2N_i4i8i8i4},
	{"i4i8i8i4i1", __M2N_i4i8i8i4i1},
	{"i4i8i8i4i4", __M2N_i4i8i8i4i4},
	{"i4i8i8i4i4i1", __M2N_i4i8i8i4i4i1},
	{"i4i8i8i4i4i4", __M2N_i4i8i8i4i4i4},
	{"i4i8i8i4i4i4i8", __M2N_i4i8i8i4i4i4i8},
	{"i4i8i8i4i4i8", __M2N_i4i8i8i4i4i8},
	{"i4i8i8i4i4i8i4", __M2N_i4i8i8i4i4i8i4},
	{"i4i8i8i4i4i8i4i1", __M2N_i4i8i8i4i4i8i4i1},
	{"i4i8i8i4i4i8i4i4", __M2N_i4i8i8i4i4i8i4i4},
	{"i4i8i8i4i4i8i4i4i4", __M2N_i4i8i8i4i4i8i4i4i4},
	{"i4i8i8i4i4i8i8", __M2N_i4i8i8i4i4i8i8},
	{"i4i8i8i4i4i8i8i8", __M2N_i4i8i8i4i4i8i8i8},
	{"i4i8i8i4i8", __M2N_i4i8i8i4i8},
	{"i4i8i8i4i8i4", __M2N_i4i8i8i4i8i4},
	{"i4i8i8i4i8i4i1", __M2N_i4i8i8i4i8i4i1},
	{"i4i8i8i4i8i4i4", __M2N_i4i8i8i4i8i4i4},
	{"i4i8i8i4i8i4i4i1i1sri4i8i8", __M2N_i4i8i8i4i8i4i4i1i1sri4i8i8},
	{"i4i8i8i4i8i4i4i1i1sri4i8i8i8", __M2N_i4i8i8i4i8i4i4i1i1sri4i8i8i8},
	{"i4i8i8i4i8i4i4i1i1sri4i8i8i8i4", __M2N_i4i8i8i4i8i4i4i1i1sri4i8i8i8i4},
	{"i4i8i8i4i8i8", __M2N_i4i8i8i4i8i8},
	{"i4i8i8i8", __M2N_i4i8i8i8},
	{"i4i8i8i8i4", __M2N_i4i8i8i8i4},
	{"i4i8i8i8i4i4", __M2N_i4i8i8i8i4i4},
	{"i4i8i8i8i4i4i4", __M2N_i4i8i8i8i4i4i4},
	{"i4i8i8i8i4i8", __M2N_i4i8i8i8i4i8},
	{"i4i8i8i8i8", __M2N_i4i8i8i8i8},
	{"i4i8i8i8i8i4", __M2N_i4i8i8i8i8i4},
	{"i4i8i8i8i8i8", __M2N_i4i8i8i8i8i8},
	{"i4i8i8i8i8i8i4", __M2N_i4i8i8i8i8i8i4},
	{"i4i8i8i8i8i8i8", __M2N_i4i8i8i8i8i8i8},
	{"i4i8i8i8i8i8i8i8", __M2N_i4i8i8i8i8i8i8i8},
	{"i4i8i8i8i8i8i8i8i8", __M2N_i4i8i8i8i8i8i8i8i8},
	{"i4i8r4", __M2N_i4i8r4},
	{"i4i8r4r4", __M2N_i4i8r4r4},
	{"i4i8r8", __M2N_i4i8r8},
	{"i4i8sr", __M2N_i4i8sr},
	{"i4i8vf4i8vf2", __M2N_i4i8vf4i8vf2},
	{"i4r4", __M2N_i4r4},
	{"i4r8", __M2N_i4r8},
	{"i4sr", __M2N_i4sr},
	{"i4sri1", __M2N_i4sri1},
	{"i4sri1i1", __M2N_i4sri1i1},
	{"i4sri1i1i1", __M2N_i4sri1i1i1},
	{"i4srsr", __M2N_i4srsr},
	{"i4vf4i4i8", __M2N_i4vf4i4i8},
	{"i4vf4i4i8i4", __M2N_i4vf4i4i8i4},
	{"i4vf4i4i8i4i8", __M2N_i4vf4i4i8i4i8},
	{"i4vf4i4i8i8", __M2N_i4vf4i4i8i8},
	{"i4vf4i4i8i8i4", __M2N_i4vf4i4i8i8i4},
	{"i8", __M2N_i8},
	{"i8i1", __M2N_i8i1},
	{"i8i16", __M2N_i8i16},
	{"i8i16i1", __M2N_i8i16i1},
	{"i8i16i16", __M2N_i8i16i16},
	{"i8i16i4", __M2N_i8i16i4},
	{"i8i16i4i8", __M2N_i8i16i4i8},
	{"i8i16i8", __M2N_i8i16i8},
	{"i8i16i8i1", __M2N_i8i16i8i1},
	{"i8i1i4", __M2N_i8i1i4},
	{"i8i1i4i8", __M2N_i8i1i4i8},
	{"i8i1i8", __M2N_i8i1i8},
	{"i8i2", __M2N_i8i2},
	{"i8i2i4", __M2N_i8i2i4},
	{"i8i2i8", __M2N_i8i2i8},
	{"i8i4", __M2N_i8i4},
	{"i8i4i4", __M2N_i8i4i4},
	{"i8i4i4i1i8", __M2N_i8i4i4i1i8},
	{"i8i4i4i4", __M2N_i8i4i4i4},
	{"i8i4i4i4i1i1i8", __M2N_i8i4i4i4i1i1i8},
	{"i8i4i4i4i4", __M2N_i8i4i4i4i4},
	{"i8i4i4i4i4i1i8", __M2N_i8i4i4i4i4i1i8},
	{"i8i4i4i4i4i4", __M2N_i8i4i4i4i4i4},
	{"i8i4i4i4i4i4i4", __M2N_i8i4i4i4i4i4i4},
	{"i8i4i4i4i4i4i4i4", __M2N_i8i4i4i4i4i4i4i4},
	{"i8i4i4i4i4i4i4i4i1", __M2N_i8i4i4i4i4i4i4i4i1},
	{"i8i4i4i4i4i4i4i4i4", __M2N_i8i4i4i4i4i4i4i4i4},
	{"i8i4i4i4i4i4i4i4i4i1", __M2N_i8i4i4i4i4i4i4i4i4i1},
	{"i8i4i4i8", __M2N_i8i4i4i8},
	{"i8i4i8", __M2N_i8i4i8},
	{"i8i4i8i4", __M2N_i8i4i8i4},
	{"i8i4i8i8", __M2N_i8i4i8i8},
	{"i8i4i8i8i1i8", __M2N_i8i4i8i8i1i8},
	{"i8i4i8i8i1i8i8", __M2N_i8i4i8i8i1i8i8},
	{"i8i4i8i8i8", __M2N_i8i4i8i8i8},
	{"i8i4i8i8i8i8", __M2N_i8i4i8i8i8i8},
	{"i8i8", __M2N_i8i8},
	{"i8i8i1", __M2N_i8i8i1},
	{"i8i8i16", __M2N_i8i8i16},
	{"i8i8i16i16", __M2N_i8i8i16i16},
	{"i8i8i16i16i16", __M2N_i8i8i16i16i16},
	{"i8i8i16i4", __M2N_i8i8i16i4},
	{"i8i8i16i4i1i8", __M2N_i8i8i16i4i1i8},
	{"i8i8i16i4i8", __M2N_i8i8i16i4i8},
	{"i8i8i16i8", __M2N_i8i8i16i8},
	{"i8i8i1i1", __M2N_i8i8i1i1},
	{"i8i8i1i1i1i4i4", __M2N_i8i8i1i1i1i4i4},
	{"i8i8i1i1i4i4", __M2N_i8i8i1i1i4i4},
	{"i8i8i1i1i8", __M2N_i8i8i1i1i8},
	{"i8i8i1i4i4", __M2N_i8i8i1i4i4},
	{"i8i8i1i8", __M2N_i8i8i1i8},
	{"i8i8i1i8i1", __M2N_i8i8i1i8i1},
	{"i8i8i1i8i8", __M2N_i8i8i1i8i8},
	{"i8i8i2", __M2N_i8i8i2},
	{"i8i8i2i2", __M2N_i8i8i2i2},
	{"i8i8i2i2i4", __M2N_i8i8i2i2i4},
	{"i8i8i2i2i4i4", __M2N_i8i8i2i2i4i4},
	{"i8i8i2i4", __M2N_i8i8i2i4},
	{"i8i8i2i4i8", __M2N_i8i8i2i4i8},
	{"i8i8i2i4i8i8", __M2N_i8i8i2i4i8i8},
	{"i8i8i2i8", __M2N_i8i8i2i8},
	{"i8i8i2i8i8", __M2N_i8i8i2i8i8},
	{"i8i8i4", __M2N_i8i8i4},
	{"i8i8i4i1", __M2N_i8i8i4i1},
	{"i8i8i4i16", __M2N_i8i8i4i16},
	{"i8i8i4i1i1", __M2N_i8i8i4i1i1},
	{"i8i8i4i1i1i1", __M2N_i8i8i4i1i1i1},
	{"i8i8i4i1i1i1i1", __M2N_i8i8i4i1i1i1i1},
	{"i8i8i4i1i1i1i1i8", __M2N_i8i8i4i1i1i1i1i8},
	{"i8i8i4i1i1i1i1i8i4", __M2N_i8i8i4i1i1i1i1i8i4},
	{"i8i8i4i2", __M2N_i8i8i4i2},
	{"i8i8i4i2i2i4", __M2N_i8i8i4i2i2i4},
	{"i8i8i4i4", __M2N_i8i8i4i4},
	{"i8i8i4i4i4", __M2N_i8i8i4i4i4},
	{"i8i8i4i4i4i4", __M2N_i8i8i4i4i4i4},
	{"i8i8i4i4i4i4i4", __M2N_i8i8i4i4i4i4i4},
	{"i8i8i4i4i4i4i4i4i4", __M2N_i8i8i4i4i4i4i4i4i4},
	{"i8i8i4i4i4i4i4i4i4i4", __M2N_i8i8i4i4i4i4i4i4i4i4},
	{"i8i8i4i4i8", __M2N_i8i8i4i4i8},
	{"i8i8i4i4i8i8", __M2N_i8i8i4i4i8i8},
	{"i8i8i4i4i8i8i8", __M2N_i8i8i4i4i8i8i8},
	{"i8i8i4i8", __M2N_i8i8i4i8},
	{"i8i8i4i8i1", __M2N_i8i8i4i8i1},
	{"i8i8i4i8i4", __M2N_i8i8i4i8i4},
	{"i8i8i4i8i4i4", __M2N_i8i8i4i8i4i4},
	{"i8i8i4i8i4i8i8", __M2N_i8i8i4i8i4i8i8},
	{"i8i8i4i8i8", __M2N_i8i8i4i8i8},
	{"i8i8i4i8i8i4", __M2N_i8i8i4i8i8i4},
	{"i8i8i4i8i8i8", __M2N_i8i8i4i8i8i8},
	{"i8i8i4i8i8i8i8", __M2N_i8i8i4i8i8i8i8},
	{"i8i8i4i8i8i8i8i8i8", __M2N_i8i8i4i8i8i8i8i8i8},
	{"i8i8i4r4", __M2N_i8i8i4r4},
	{"i8i8i4r8", __M2N_i8i8i4r8},
	{"i8i8i8", __M2N_i8i8i8},
	{"i8i8i8i1", __M2N_i8i8i8i1},
	{"i8i8i8i16i16i16", __M2N_i8i8i8i16i16i16},
	{"i8i8i8i16i8", __M2N_i8i8i8i16i8},
	{"i8i8i8i1i1", __M2N_i8i8i8i1i1},
	{"i8i8i8i1i1i8i8", __M2N_i8i8i8i1i1i8i8},
	{"i8i8i8i1i4", __M2N_i8i8i8i1i4},
	{"i8i8i8i1i4i1", __M2N_i8i8i8i1i4i1},
	{"i8i8i8i1i4i1i8i8", __M2N_i8i8i8i1i4i1i8i8},
	{"i8i8i8i1i4i8i8i8i8", __M2N_i8i8i8i1i4i8i8i8i8},
	{"i8i8i8i1i4i8i8i8i8i8", __M2N_i8i8i8i1i4i8i8i8i8i8},
	{"i8i8i8i1i8", __M2N_i8i8i8i1i8},
	{"i8i8i8i1i8i8i8i8i4i8", __M2N_i8i8i8i1i8i8i8i8i4i8},
	{"i8i8i8i2i2i1i1i4i2", __M2N_i8i8i8i2i2i1i1i4i2},
	{"i8i8i8i4", __M2N_i8i8i8i4},
	{"i8i8i8i4i1i4i4i4", __M2N_i8i8i8i4i1i4i4i4},
	{"i8i8i8i4i1i4i4i4i16i16", __M2N_i8i8i8i4i1i4i4i4i16i16},
	{"i8i8i8i4i2i2i1i1i4i2", __M2N_i8i8i8i4i2i2i1i1i4i2},
	{"i8i8i8i4i4", __M2N_i8i8i8i4i4},
	{"i8i8i8i4i4i1", __M2N_i8i8i8i4i4i1},
	{"i8i8i8i4i4i4", __M2N_i8i8i8i4i4i4},
	{"i8i8i8i4i4i4i8i8", __M2N_i8i8i8i4i4i4i8i8},
	{"i8i8i8i4i4i4i8i8i8", __M2N_i8i8i8i4i4i4i8i8i8},
	{"i8i8i8i4i4i8", __M2N_i8i8i8i4i4i8},
	{"i8i8i8i4i4i8i1i16", __M2N_i8i8i8i4i4i8i1i16},
	{"i8i8i8i4i4i8i4", __M2N_i8i8i8i4i4i8i4},
	{"i8i8i8i4i4i8i8", __M2N_i8i8i8i4i4i8i8},
	{"i8i8i8i4i4i8i8i8i8i8i8", __M2N_i8i8i8i4i4i8i8i8i8i8i8},
	{"i8i8i8i4i8", __M2N_i8i8i8i4i8},
	{"i8i8i8i4i8i1", __M2N_i8i8i8i4i8i1},
	{"i8i8i8i4i8i16", __M2N_i8i8i8i4i8i16},
	{"i8i8i8i4i8i1i8", __M2N_i8i8i8i4i8i1i8},
	{"i8i8i8i4i8i4", __M2N_i8i8i8i4i8i4},
	{"i8i8i8i4i8i4i4", __M2N_i8i8i8i4i8i4i4},
	{"i8i8i8i4i8i4i8i8", __M2N_i8i8i8i4i8i4i8i8},
	{"i8i8i8i4i8i8", __M2N_i8i8i8i4i8i8},
	{"i8i8i8i4i8i8i1", __M2N_i8i8i8i4i8i8i1},
	{"i8i8i8i4i8i8i8", __M2N_i8i8i8i4i8i8i8},
	{"i8i8i8i4i8i8i8i8", __M2N_i8i8i8i4i8i8i8i8},
	{"i8i8i8i4i8i8i8i8i8", __M2N_i8i8i8i4i8i8i8i8i8},
	{"i8i8i8i4i8i8i8i8i8i1", __M2N_i8i8i8i4i8i8i8i8i8i1},
	{"i8i8i8i4i8i8i8i8i8i1i8", __M2N_i8i8i8i4i8i8i8i8i8i1i8},
	{"i8i8i8i4i8i8i8i8i8i8", __M2N_i8i8i8i4i8i8i8i8i8i8},
	{"i8i8i8i8", __M2N_i8i8i8i8},
	{"i8i8i8i8i1", __M2N_i8i8i8i8i1},
	{"i8i8i8i8i16i8", __M2N_i8i8i8i8i16i8},
	{"i8i8i8i8i1i1", __M2N_i8i8i8i8i1i1},
	{"i8i8i8i8i1i4i8i8i8i8", __M2N_i8i8i8i8i1i4i8i8i8i8},
	{"i8i8i8i8i1i4i8i8i8i8i8", __M2N_i8i8i8i8i1i4i8i8i8i8i8},
	{"i8i8i8i8i1i8", __M2N_i8i8i8i8i1i8},
	{"i8i8i8i8i1i8i8", __M2N_i8i8i8i8i1i8i8},
	{"i8i8i8i8i4", __M2N_i8i8i8i8i4},
	{"i8i8i8i8i4i1", __M2N_i8i8i8i8i4i1},
	{"i8i8i8i8i4i1i8i8", __M2N_i8i8i8i8i4i1i8i8},
	{"i8i8i8i8i4i4", __M2N_i8i8i8i8i4i4},
	{"i8i8i8i8i4i4i1", __M2N_i8i8i8i8i4i4i1},
	{"i8i8i8i8i4i4i8i8", __M2N_i8i8i8i8i4i4i8i8},
	{"i8i8i8i8i4i4i8i8i4i4", __M2N_i8i8i8i8i4i4i8i8i4i4},
	{"i8i8i8i8i4i8", __M2N_i8i8i8i8i4i8},
	{"i8i8i8i8i4i8i4i1", __M2N_i8i8i8i8i4i8i4i1},
	{"i8i8i8i8i4i8i8", __M2N_i8i8i8i8i4i8i8},
	{"i8i8i8i8i4i8i8i8i1", __M2N_i8i8i8i8i4i8i8i8i1},
	{"i8i8i8i8i4i8i8i8i8i8", __M2N_i8i8i8i8i4i8i8i8i8i8},
	{"i8i8i8i8i8", __M2N_i8i8i8i8i8},
	{"i8i8i8i8i8i1", __M2N_i8i8i8i8i8i1},
	{"i8i8i8i8i8i1i1", __M2N_i8i8i8i8i8i1i1},
	{"i8i8i8i8i8i1i1i1", __M2N_i8i8i8i8i8i1i1i1},
	{"i8i8i8i8i8i1i1i1i4", __M2N_i8i8i8i8i8i1i1i1i4},
	{"i8i8i8i8i8i1i8i1", __M2N_i8i8i8i8i8i1i8i1},
	{"i8i8i8i8i8i1i8i8", __M2N_i8i8i8i8i8i1i8i8},
	{"i8i8i8i8i8i4", __M2N_i8i8i8i8i8i4},
	{"i8i8i8i8i8i4i4", __M2N_i8i8i8i8i8i4i4},
	{"i8i8i8i8i8i4i4i8i8", __M2N_i8i8i8i8i8i4i4i8i8},
	{"i8i8i8i8i8i4i4i8i8i4i4", __M2N_i8i8i8i8i8i4i4i8i8i4i4},
	{"i8i8i8i8i8i4i4i8i8i8i8i8i8i4i4", __M2N_i8i8i8i8i8i4i4i8i8i8i8i8i8i4i4},
	{"i8i8i8i8i8i4i8", __M2N_i8i8i8i8i8i4i8},
	{"i8i8i8i8i8i4i8i8", __M2N_i8i8i8i8i8i4i8i8},
	{"i8i8i8i8i8i8", __M2N_i8i8i8i8i8i8},
	{"i8i8i8i8i8i8i4", __M2N_i8i8i8i8i8i8i4},
	{"i8i8i8i8i8i8i8", __M2N_i8i8i8i8i8i8i8},
	{"i8i8i8i8i8i8i8i1", __M2N_i8i8i8i8i8i8i8i1},
	{"i8i8i8i8i8i8i8i8", __M2N_i8i8i8i8i8i8i8i8},
	{"i8i8i8i8i8i8i8i8i4i8", __M2N_i8i8i8i8i8i8i8i8i4i8},
	{"i8i8i8i8i8i8i8i8i8", __M2N_i8i8i8i8i8i8i8i8i8},
	{"i8i8i8i8i8i8i8i8i8i4i8", __M2N_i8i8i8i8i8i8i8i8i8i4i8},
	{"i8i8i8i8r8i8i8r8", __M2N_i8i8i8i8r8i8i8r8},
	{"i8i8i8i8sr", __M2N_i8i8i8i8sr},
	{"i8i8i8i8srsr", __M2N_i8i8i8i8srsr},
	{"i8i8i8r4", __M2N_i8i8i8r4},
	{"i8i8i8r8", __M2N_i8i8i8r8},
	{"i8i8i8sr", __M2N_i8i8i8sr},
	{"i8i8i8sri8i8i8", __M2N_i8i8i8sri8i8i8},
	{"i8i8r4", __M2N_i8i8r4},
	{"i8i8r8", __M2N_i8i8r8},
	{"i8i8r8i8i8i8", __M2N_i8i8r8i8i8i8},
	{"i8i8r8r8", __M2N_i8i8r8r8},
	{"i8i8S12", __M2N_i8i8S12},
	{"i8i8sr", __M2N_i8i8sr},
	{"i8i8sri4", __M2N_i8i8sri4},
	{"i8i8sri8i8i8", __M2N_i8i8sri8i8i8},
	{"i8i8vf3", __M2N_i8i8vf3},
	{"i8i8vf3vf4", __M2N_i8i8vf3vf4},
	{"i8i8vf3vf4i4", __M2N_i8i8vf3vf4i4},
	{"i8i8vf3vf4i8", __M2N_i8i8vf3vf4i8},
	{"i8i8vf4vf2", __M2N_i8i8vf4vf2},
	{"i8i8vf4vf2r4", __M2N_i8i8vf4vf2r4},
	{"i8i8vf4vf2r4i4", __M2N_i8i8vf4vf2r4i4},
	{"i8i8vf4vf2r4i4i4", __M2N_i8i8vf4vf2r4i4i4},
	{"i8i8vf4vf2r4i4i4vf4", __M2N_i8i8vf4vf2r4i4i4vf4},
	{"i8i8vf4vf2r4i4i4vf4i1", __M2N_i8i8vf4vf2r4i4i4vf4i1},
	{"i8r4", __M2N_i8r4},
	{"i8r4i4i8", __M2N_i8r4i4i8},
	{"i8r4i8", __M2N_i8r4i8},
	{"i8r4r4r4", __M2N_i8r4r4r4},
	{"i8r4r4r4r4", __M2N_i8r4r4r4r4},
	{"i8r8", __M2N_i8r8},
	{"i8r8i4i8", __M2N_i8r8i4i8},
	{"i8r8i8", __M2N_i8r8i8},
	{"i8sr", __M2N_i8sr},
	{"i8srvf2", __M2N_i8srvf2},
	{"i8srvf4", __M2N_i8srvf4},
	{"i8vf2", __M2N_i8vf2},
	{"i8vf4", __M2N_i8vf4},
	{"i8vf4i8", __M2N_i8vf4i8},
	{"i8vf4i8i2", __M2N_i8vf4i8i2},
	{"i8vf4i8i2i4", __M2N_i8vf4i8i2i4},
	{"i8vf4i8i2i4i8", __M2N_i8vf4i8i2i4i8},
	{"i8vf4i8i2i8", __M2N_i8vf4i8i2i8},
	{"i8vf4i8i4", __M2N_i8vf4i8i4},
	{"i8vf4i8i4i8", __M2N_i8vf4i8i4i8},
	{"i8vf4i8i8", __M2N_i8vf4i8i8},
	{"r4", __M2N_r4},
	{"r4i1", __M2N_r4i1},
	{"r4i16", __M2N_r4i16},
	{"r4i16i16", __M2N_r4i16i16},
	{"r4i2", __M2N_r4i2},
	{"r4i4", __M2N_r4i4},
	{"r4i8", __M2N_r4i8},
	{"r4i8i4", __M2N_r4i8i4},
	{"r4i8i4i4", __M2N_r4i8i4i4},
	{"r4i8i4i8", __M2N_r4i8i4i8},
	{"r4i8i8", __M2N_r4i8i8},
	{"r4i8i8i8", __M2N_r4i8i8i8},
	{"r4i8i8r4", __M2N_r4i8i8r4},
	{"r4i8i8sr", __M2N_r4i8i8sr},
	{"r4i8r4", __M2N_r4i8r4},
	{"r4i8r4r4", __M2N_r4i8r4r4},
	{"r4i8vf3", __M2N_r4i8vf3},
	{"r4r4", __M2N_r4r4},
	{"r4r4r4", __M2N_r4r4r4},
	{"r4r4r4i8r4", __M2N_r4r4r4i8r4},
	{"r4r4r4i8r4r4", __M2N_r4r4r4i8r4r4},
	{"r4r4r4i8r4r4r4", __M2N_r4r4r4i8r4r4r4},
	{"r4r4r4r4", __M2N_r4r4r4r4},
	{"r4r4r4r4i8", __M2N_r4r4r4r4i8},
	{"r4r4r4r4i8i8i8", __M2N_r4r4r4r4i8i8i8},
	{"r4r4r4r4r4i8", __M2N_r4r4r4r4r4i8},
	{"r4r4r4r4r4i8i8", __M2N_r4r4r4r4r4i8i8},
	{"r4r8", __M2N_r4r8},
	{"r4sr", __M2N_r4sr},
	{"r4srsr", __M2N_r4srsr},
	{"r4vf2", __M2N_r4vf2},
	{"r4vf2vf2", __M2N_r4vf2vf2},
	{"r4vf3", __M2N_r4vf3},
	{"r4vf3vf3", __M2N_r4vf3vf3},
	{"r4vf3vf3vf3", __M2N_r4vf3vf3vf3},
	{"r4vf4", __M2N_r4vf4},
	{"r4vf4r4r4r4", __M2N_r4vf4r4r4r4},
	{"r4vf4r4r4r4i8i8", __M2N_r4vf4r4r4r4i8i8},
	{"r4vf4r4r4r4i8i8i8", __M2N_r4vf4r4r4r4i8i8i8},
	{"r4vf4r4r4r4r4", __M2N_r4vf4r4r4r4r4},
	{"r4vf4r4r4r4r4i8", __M2N_r4vf4r4r4r4r4i8},
	{"r4vf4r4r4r4r4i8i8i1i4i8", __M2N_r4vf4r4r4r4r4i8i8i1i4i8},
	{"r4vf4vf3", __M2N_r4vf4vf3},
	{"r4vf4vf4", __M2N_r4vf4vf4},
	{"r8", __M2N_r8},
	{"r8i1", __M2N_r8i1},
	{"r8i16", __M2N_r8i16},
	{"r8i16r8", __M2N_r8i16r8},
	{"r8i2", __M2N_r8i2},
	{"r8i4", __M2N_r8i4},
	{"r8i8", __M2N_r8i8},
	{"r8i8i4", __M2N_r8i8i4},
	{"r8i8i4i8", __M2N_r8i8i4i8},
	{"r8i8i8", __M2N_r8i8i8},
	{"r8i8i8i8", __M2N_r8i8i8i8},
	{"r8i8i8i8i8", __M2N_r8i8i8i8i8},
	{"r8i8i8i8i8i8", __M2N_r8i8i8i8i8i8},
	{"r8i8r8", __M2N_r8i8r8},
	{"r8i8r8r8", __M2N_r8i8r8r8},
	{"r8r4", __M2N_r8r4},
	{"r8r8", __M2N_r8r8},
	{"r8r8i4", __M2N_r8r8i4},
	{"r8r8i4i4", __M2N_r8r8i4i4},
	{"r8r8r8", __M2N_r8r8r8},
	{"r8vd2", __M2N_r8vd2},
	{"r8vd3", __M2N_r8vd3},
	{"S108", __M2N_S108},
	{"S108r4sr", __M2N_S108r4sr},
	{"S108srr4", __M2N_S108srr4},
	{"S108srsr", __M2N_S108srsr},
	{"S120i8", __M2N_S120i8},
	{"S120i8i1", __M2N_S120i8i1},
	{"S12i8S12", __M2N_S12i8S12},
	{"S12i8S12S12", __M2N_S12i8S12S12},
	{"S188i8", __M2N_S188i8},
	{"S20", __M2N_S20},
	{"S20i8", __M2N_S20i8},
	{"S20i8sr", __M2N_S20i8sr},
	{"S20sr", __M2N_S20sr},
	{"S224i8", __M2N_S224i8},
	{"S24", __M2N_S24},
	{"S24i2", __M2N_S24i2},
	{"S24i4i4i8", __M2N_S24i4i4i8},
	{"S24i4i4i8i8", __M2N_S24i4i4i8i8},
	{"S24i8", __M2N_S24i8},
	{"S24i8i1", __M2N_S24i8i1},
	{"S24i8i4", __M2N_S24i8i4},
	{"S24i8i4i4", __M2N_S24i8i4i4},
	{"S24i8i4i4i4", __M2N_S24i8i4i4i4},
	{"S24i8i4i4i4sri4", __M2N_S24i8i4i4i4sri4},
	{"S24i8i8", __M2N_S24i8i8},
	{"S24i8i8i1", __M2N_S24i8i8i1},
	{"S24i8i8i8", __M2N_S24i8i8i8},
	{"S24i8i8i8i1", __M2N_S24i8i8i8i1},
	{"S24i8i8i8i8", __M2N_S24i8i8i8i8},
	{"S24i8sr", __M2N_S24i8sr},
	{"S24i8sri1", __M2N_S24i8sri1},
	{"S24i8sri1i1", __M2N_S24i8sri1i1},
	{"S24i8srsri1", __M2N_S24i8srsri1},
	{"S24i8srsri1i1", __M2N_S24i8srsri1i1},
	{"S24i8vf3", __M2N_S24i8vf3},
	{"S24i8vf3i4", __M2N_S24i8vf3i4},
	{"S24r4", __M2N_S24r4},
	{"S24r4r4", __M2N_S24r4r4},
	{"S24r4r4vf2", __M2N_S24r4r4vf2},
	{"S24r4vf2", __M2N_S24r4vf2},
	{"S24sr", __M2N_S24sr},
	{"S24srr4", __M2N_S24srr4},
	{"S24srsr", __M2N_S24srsr},
	{"S24srsrr4", __M2N_S24srsrr4},
	{"S24vf2", __M2N_S24vf2},
	{"S24vf2vf2", __M2N_S24vf2vf2},
	{"S28", __M2N_S28},
	{"S28i8", __M2N_S28i8},
	{"S28i8i8", __M2N_S28i8i8},
	{"S28i8sr", __M2N_S28i8sr},
	{"S32", __M2N_S32},
	{"S32i8", __M2N_S32i8},
	{"S32i8i4", __M2N_S32i8i4},
	{"S32i8i4i4", __M2N_S32i8i4i4},
	{"S32i8i8", __M2N_S32i8i8},
	{"S32i8i8i4", __M2N_S32i8i8i4},
	{"S32i8i8i8", __M2N_S32i8i8i8},
	{"S36i8", __M2N_S36i8},
	{"S40", __M2N_S40},
	{"S40i16", __M2N_S40i16},
	{"S40i4", __M2N_S40i4},
	{"S40i8", __M2N_S40i8},
	{"S48i4", __M2N_S48i4},
	{"S48i8", __M2N_S48i8},
	{"S48i8i4", __M2N_S48i8i4},
	{"S52i8", __M2N_S52i8},
	{"S56i8", __M2N_S56i8},
	{"S56i8i4", __M2N_S56i8i4},
	{"S56i8i4i4", __M2N_S56i8i4i4},
	{"S56i8i4i8", __M2N_S56i8i4i8},
	{"S64", __M2N_S64},
	{"S64i4", __M2N_S64i4},
	{"S64i8", __M2N_S64i8},
	{"S64i8i1", __M2N_S64i8i1},
	{"S64i8i4", __M2N_S64i8i4},
	{"S64i8i8", __M2N_S64i8i8},
	{"S64i8vf4", __M2N_S64i8vf4},
	{"S64r4", __M2N_S64r4},
	{"S64r4r4r4", __M2N_S64r4r4r4},
	{"S64r4r4r4r4", __M2N_S64r4r4r4r4},
	{"S64r4r4r4r4r4r4", __M2N_S64r4r4r4r4r4r4},
	{"S64r4r4r4vf3", __M2N_S64r4r4r4vf3},
	{"S64r4vf3", __M2N_S64r4vf3},
	{"S64sr", __M2N_S64sr},
	{"S64sri1", __M2N_S64sri1},
	{"S64srr4", __M2N_S64srr4},
	{"S64srsr", __M2N_S64srsr},
	{"S64srsrr4", __M2N_S64srsrr4},
	{"S64srvf4", __M2N_S64srvf4},
	{"S64vf3", __M2N_S64vf3},
	{"S64vf3r4", __M2N_S64vf3r4},
	{"S64vf3vf3", __M2N_S64vf3vf3},
	{"S64vf3vf3vf3", __M2N_S64vf3vf3vf3},
	{"S64vf3vf3vf3vf3", __M2N_S64vf3vf3vf3vf3},
	{"S64vf3vf3vf3vf3vf3", __M2N_S64vf3vf3vf3vf3vf3},
	{"S64vf3vf4", __M2N_S64vf3vf4},
	{"S64vf3vf4vf3", __M2N_S64vf3vf4vf3},
	{"S64vf4", __M2N_S64vf4},
	{"S68", __M2N_S68},
	{"S68i4", __M2N_S68i4},
	{"S68i8", __M2N_S68i8},
	{"S96", __M2N_S96},
	{"S96i8", __M2N_S96i8},
	{"S992i8", __M2N_S992i8},
	{"v", __M2N_v},
	{"vd2i1", __M2N_vd2i1},
	{"vd2i16", __M2N_vd2i16},
	{"vd2i2", __M2N_vd2i2},
	{"vd2i4", __M2N_vd2i4},
	{"vd2i8", __M2N_vd2i8},
	{"vd2r4", __M2N_vd2r4},
	{"vd2r8", __M2N_vd2r8},
	{"vd2r8r8", __M2N_vd2r8r8},
	{"vd2vd2", __M2N_vd2vd2},
	{"vd2vd2r8", __M2N_vd2vd2r8},
	{"vd2vd2vd2", __M2N_vd2vd2vd2},
	{"vd3", __M2N_vd3},
	{"vd3i8", __M2N_vd3i8},
	{"vd3i8vd3", __M2N_vd3i8vd3},
	{"vd3vd3", __M2N_vd3vd3},
	{"vd4", __M2N_vd4},
	{"vd4i8", __M2N_vd4i8},
	{"vd4i8vd4", __M2N_vd4i8vd4},
	{"vd4vd4", __M2N_vd4vd4},
	{"vf2", __M2N_vf2},
	{"vf2i8", __M2N_vf2i8},
	{"vf2i8i4", __M2N_vf2i8i4},
	{"vf2i8i8", __M2N_vf2i8i8},
	{"vf2i8r4", __M2N_vf2i8r4},
	{"vf2i8vf2", __M2N_vf2i8vf2},
	{"vf2i8vf4i8i4", __M2N_vf2i8vf4i8i4},
	{"vf2r4vf2", __M2N_vf2r4vf2},
	{"vf2vf2", __M2N_vf2vf2},
	{"vf2vf2i1i1i8", __M2N_vf2vf2i1i1i8},
	{"vf2vf2i1i1i8i8i8", __M2N_vf2vf2i1i1i8i8i8},
	{"vf2vf2i1i1i8i8i8i8", __M2N_vf2vf2i1i1i8i8i8i8},
	{"vf2vf2i8", __M2N_vf2vf2i8},
	{"vf2vf2i8i8", __M2N_vf2vf2i8i8},
	{"vf2vf2i8i8i8", __M2N_vf2vf2i8i8i8},
	{"vf2vf2r4", __M2N_vf2vf2r4},
	{"vf2vf2sr", __M2N_vf2vf2sr},
	{"vf2vf2vf2", __M2N_vf2vf2vf2},
	{"vf2vf2vf2i8r4", __M2N_vf2vf2vf2i8r4},
	{"vf2vf2vf2i8r4r4", __M2N_vf2vf2vf2i8r4r4},
	{"vf2vf2vf2i8r4r4r4", __M2N_vf2vf2vf2i8r4r4r4},
	{"vf2vf2vf2r4", __M2N_vf2vf2vf2r4},
	{"vf2vf2vf2vf2", __M2N_vf2vf2vf2vf2},
	{"vf2vf2vf4", __M2N_vf2vf2vf4},
	{"vf2vf3", __M2N_vf2vf3},
	{"vf2vf4", __M2N_vf2vf4},
	{"vf2vf4vf2", __M2N_vf2vf4vf2},
	{"vf2vf4vf2vf4", __M2N_vf2vf4vf2vf4},
	{"vf2vf4vf2vf4i1i1", __M2N_vf2vf4vf2vf4i1i1},
	{"vf2vf4vf2vf4i1i1i8i8", __M2N_vf2vf4vf2vf4i1i1i8i8},
	{"vf2vf4vf2vf4i1i1i8i8i8", __M2N_vf2vf4vf2vf4i1i1i8i8i8},
	{"vf2vf4vf2vf4i8i8", __M2N_vf2vf4vf2vf4i8i8},
	{"vf3", __M2N_vf3},
	{"vf3i16", __M2N_vf3i16},
	{"vf3i8", __M2N_vf3i8},
	{"vf3i8i4", __M2N_vf3i8i4},
	{"vf3i8r4", __M2N_vf3i8r4},
	{"vf3i8r4r4r4", __M2N_vf3i8r4r4r4},
	{"vf3i8vf3", __M2N_vf3i8vf3},
	{"vf3i8vf3i4", __M2N_vf3i8vf3i4},
	{"vf3r4vf3", __M2N_vf3r4vf3},
	{"vf3vf2", __M2N_vf3vf2},
	{"vf3vf3", __M2N_vf3vf3},
	{"vf3vf3r4", __M2N_vf3vf3r4},
	{"vf3vf3sr", __M2N_vf3vf3sr},
	{"vf3vf3vf3", __M2N_vf3vf3vf3},
	{"vf3vf3vf3i1", __M2N_vf3vf3vf3i1},
	{"vf3vf3vf3i8r4", __M2N_vf3vf3vf3i8r4},
	{"vf3vf3vf3i8r4r4", __M2N_vf3vf3vf3i8r4r4},
	{"vf3vf3vf3i8r4r4r4", __M2N_vf3vf3vf3i8r4r4r4},
	{"vf3vf3vf3r4", __M2N_vf3vf3vf3r4},
	{"vf3vf3vf3r4r4", __M2N_vf3vf3vf3r4r4},
	{"vf3vf3vf3vf3", __M2N_vf3vf3vf3vf3},
	{"vf3vf3vf4", __M2N_vf3vf3vf4},
	{"vf3vf4", __M2N_vf3vf4},
	{"vf3vf4vf3", __M2N_vf3vf4vf3},
	{"vf4", __M2N_vf4},
	{"vf4i4", __M2N_vf4i4},
	{"vf4i4vf4i8i8", __M2N_vf4i4vf4i8i8},
	{"vf4i4vf4i8i8i8", __M2N_vf4i4vf4i8i8i8},
	{"vf4i4vf4i8i8i8i8", __M2N_vf4i4vf4i8i8i8i8},
	{"vf4i8", __M2N_vf4i8},
	{"vf4i8i4", __M2N_vf4i8i4},
	{"vf4i8i4i4", __M2N_vf4i8i4i4},
	{"vf4i8i4i4i4", __M2N_vf4i8i4i4i4},
	{"vf4i8i4i4i4i4", __M2N_vf4i8i4i4i4i4},
	{"vf4i8i8", __M2N_vf4i8i8},
	{"vf4i8i8i8", __M2N_vf4i8i8i8},
	{"vf4i8r4", __M2N_vf4i8r4},
	{"vf4i8r4r4", __M2N_vf4i8r4r4},
	{"vf4i8r4r4i4", __M2N_vf4i8r4r4i4},
	{"vf4i8r4r4r4", __M2N_vf4i8r4r4r4},
	{"vf4i8r4r4r4i4", __M2N_vf4i8r4r4r4i4},
	{"vf4i8vf4", __M2N_vf4i8vf4},
	{"vf4r4", __M2N_vf4r4},
	{"vf4r4i8", __M2N_vf4r4i8},
	{"vf4r4i8i8", __M2N_vf4r4i8i8},
	{"vf4r4r4", __M2N_vf4r4r4},
	{"vf4r4r4i8", __M2N_vf4r4r4i8},
	{"vf4r4r4i8i8", __M2N_vf4r4r4i8i8},
	{"vf4r4r4r4", __M2N_vf4r4r4r4},
	{"vf4r4r4r4i1", __M2N_vf4r4r4r4i1},
	{"vf4r4r4r4r4", __M2N_vf4r4r4r4r4},
	{"vf4r4r4r4r4i8", __M2N_vf4r4r4r4r4i8},
	{"vf4r4r4r4r4i8i8", __M2N_vf4r4r4r4r4i8i8},
	{"vf4r4r4r4r4r4r4", __M2N_vf4r4r4r4r4r4r4},
	{"vf4r4r4r4r4r4r4r4r4", __M2N_vf4r4r4r4r4r4r4r4r4},
	{"vf4r4vf3", __M2N_vf4r4vf3},
	{"vf4r4vf4", __M2N_vf4r4vf4},
	{"vf4sr", __M2N_vf4sr},
	{"vf4srvf4", __M2N_vf4srvf4},
	{"vf4vf2", __M2N_vf4vf2},
	{"vf4vf2sr", __M2N_vf4vf2sr},
	{"vf4vf2vf4", __M2N_vf4vf2vf4},
	{"vf4vf3", __M2N_vf4vf3},
	{"vf4vf3r4", __M2N_vf4vf3r4},
	{"vf4vf3sr", __M2N_vf4vf3sr},
	{"vf4vf3vf3", __M2N_vf4vf3vf3},
	{"vf4vf3vf3vf3", __M2N_vf4vf3vf3vf3},
	{"vf4vf3vf4", __M2N_vf4vf3vf4},
	{"vf4vf4", __M2N_vf4vf4},
	{"vf4vf4i8i8", __M2N_vf4vf4i8i8},
	{"vf4vf4r4", __M2N_vf4vf4r4},
	{"vf4vf4sr", __M2N_vf4vf4sr},
	{"vf4vf4vf3", __M2N_vf4vf4vf3},
	{"vf4vf4vf4", __M2N_vf4vf4vf4},
	{"vf4vf4vf4r4", __M2N_vf4vf4vf4r4},
	{"vf4vf4vf4vf4", __M2N_vf4vf4vf4vf4},
	{"vi1", __M2N_vi1},
	{"vi16", __M2N_vi16},
	{"vi16i1", __M2N_vi16i1},
	{"vi16i16", __M2N_vi16i16},
	{"vi16i16i4", __M2N_vi16i16i4},
	{"vi16i16i4i4", __M2N_vi16i16i4i4},
	{"vi16i16i4i4i4", __M2N_vi16i16i4i4i4},
	{"vi16i4", __M2N_vi16i4},
	{"vi16i4i8", __M2N_vi16i4i8},
	{"vi16i8", __M2N_vi16i8},
	{"vi1i1", __M2N_vi1i1},
	{"vi1i1i8", __M2N_vi1i1i8},
	{"vi1i1vf4", __M2N_vi1i1vf4},
	{"vi1i1vf4r4", __M2N_vi1i1vf4r4},
	{"vi1i4i4", __M2N_vi1i4i4},
	{"vi1i8", __M2N_vi1i8},
	{"vi1i8i8", __M2N_vi1i8i8},
	{"vi1i8i8i8", __M2N_vi1i8i8i8},
	{"vi2", __M2N_vi2},
	{"vi2i2", __M2N_vi2i2},
	{"vi2i2i8", __M2N_vi2i2i8},
	{"vi4", __M2N_vi4},
	{"vi4i1", __M2N_vi4i1},
	{"vi4i4", __M2N_vi4i4},
	{"vi4i4i1", __M2N_vi4i4i1},
	{"vi4i4i1i1", __M2N_vi4i4i1i1},
	{"vi4i4i1i4", __M2N_vi4i4i1i4},
	{"vi4i4i4", __M2N_vi4i4i4},
	{"vi4i4i4i4", __M2N_vi4i4i4i4},
	{"vi4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i2i4i4", __M2N_vi4i4i4i4i4i4i2i4i4},
	{"vi4i4i8", __M2N_vi4i4i8},
	{"vi4i4i8i4", __M2N_vi4i4i8i4},
	{"vi4i4i8i8i8", __M2N_vi4i4i8i8i8},
	{"vi4i8", __M2N_vi4i8},
	{"vi4i8i1", __M2N_vi4i8i1},
	{"vi4i8i4", __M2N_vi4i8i4},
	{"vi4i8i4i4", __M2N_vi4i8i4i4},
	{"vi4i8i8", __M2N_vi4i8i8},
	{"vi4i8i8i4", __M2N_vi4i8i8i4},
	{"vi4i8i8i8i8", __M2N_vi4i8i8i8i8},
	{"vi4i8vf3", __M2N_vi4i8vf3},
	{"vi4r4", __M2N_vi4r4},
	{"vi4r4r4", __M2N_vi4r4r4},
	{"vi4r4r4r4", __M2N_vi4r4r4r4},
	{"vi4sr", __M2N_vi4sr},
	{"vi4vf3", __M2N_vi4vf3},
	{"vi4vf4", __M2N_vi4vf4},
	{"vi8", __M2N_vi8},
	{"vi8i1", __M2N_vi8i1},
	{"vi8i16", __M2N_vi8i16},
	{"vi8i16i16", __M2N_vi8i16i16},
	{"vi8i16i16i4", __M2N_vi8i16i16i4},
	{"vi8i16i16i4i4", __M2N_vi8i16i16i4i4},
	{"vi8i16i16i4i4i4", __M2N_vi8i16i16i4i4i4},
	{"vi8i16i4", __M2N_vi8i16i4},
	{"vi8i16i4i4i4", __M2N_vi8i16i4i4i4},
	{"vi8i16i4i8", __M2N_vi8i16i4i8},
	{"vi8i16i8", __M2N_vi8i16i8},
	{"vi8i16i8i8", __M2N_vi8i16i8i8},
	{"vi8i16sr", __M2N_vi8i16sr},
	{"vi8i16sri8", __M2N_vi8i16sri8},
	{"vi8i1i1", __M2N_vi8i1i1},
	{"vi8i1i1i1", __M2N_vi8i1i1i1},
	{"vi8i1i1i1i1", __M2N_vi8i1i1i1i1},
	{"vi8i1i1i1i4", __M2N_vi8i1i1i1i4},
	{"vi8i1i1i1i4i4i4i4", __M2N_vi8i1i1i1i4i4i4i4},
	{"vi8i1i1i1i4i4i4i4i4i4i4i4", __M2N_vi8i1i1i1i4i4i4i4i4i4i4i4},
	{"vi8i1i1i4", __M2N_vi8i1i1i4},
	{"vi8i1i1i4i1", __M2N_vi8i1i1i4i1},
	{"vi8i1i1i4i4i4", __M2N_vi8i1i1i4i4i4},
	{"vi8i1i1i4i8", __M2N_vi8i1i1i4i8},
	{"vi8i1i1i4i8i8i8i8", __M2N_vi8i1i1i4i8i8i8i8},
	{"vi8i1i1i8", __M2N_vi8i1i1i8},
	{"vi8i1i1i8i4", __M2N_vi8i1i1i8i4},
	{"vi8i1i1r4r4r4r4", __M2N_vi8i1i1r4r4r4r4},
	{"vi8i1i1vf4", __M2N_vi8i1i1vf4},
	{"vi8i1i1vf4r4", __M2N_vi8i1i1vf4r4},
	{"vi8i1i4", __M2N_vi8i1i4},
	{"vi8i1i4i4", __M2N_vi8i1i4i4},
	{"vi8i1i4i4i8", __M2N_vi8i1i4i4i8},
	{"vi8i1i4i4i8i1i8", __M2N_vi8i1i4i4i8i1i8},
	{"vi8i1i4i4i8i4i16i16i1i8", __M2N_vi8i1i4i4i8i4i16i16i1i8},
	{"vi8i1i4i8", __M2N_vi8i1i4i8},
	{"vi8i1i4i8i4", __M2N_vi8i1i4i8i4},
	{"vi8i1i4i8i4i8i8", __M2N_vi8i1i4i8i4i8i8},
	{"vi8i1i4i8i8", __M2N_vi8i1i4i8i8},
	{"vi8i1i4i8i8i8", __M2N_vi8i1i4i8i8i8},
	{"vi8i1i8", __M2N_vi8i1i8},
	{"vi8i1i8i4", __M2N_vi8i1i8i4},
	{"vi8i1i8i8", __M2N_vi8i1i8i8},
	{"vi8i1i8i8i8", __M2N_vi8i1i8i8i8},
	{"vi8i2", __M2N_vi8i2},
	{"vi8i2i2", __M2N_vi8i2i2},
	{"vi8i2i4", __M2N_vi8i2i4},
	{"vi8i2i4i1i1i1", __M2N_vi8i2i4i1i1i1},
	{"vi8i2i8", __M2N_vi8i2i8},
	{"vi8i4", __M2N_vi8i4},
	{"vi8i4i1", __M2N_vi8i4i1},
	{"vi8i4i16", __M2N_vi8i4i16},
	{"vi8i4i16i8", __M2N_vi8i4i16i8},
	{"vi8i4i1i1", __M2N_vi8i4i1i1},
	{"vi8i4i1i1i1i1i4i8", __M2N_vi8i4i1i1i1i1i4i8},
	{"vi8i4i1i1i8", __M2N_vi8i4i1i1i8},
	{"vi8i4i1i8i8i8i8", __M2N_vi8i4i1i8i8i8i8},
	{"vi8i4i2", __M2N_vi8i4i2},
	{"vi8i4i2i2i1i1i1i1i1i1i1i1", __M2N_vi8i4i2i2i1i1i1i1i1i1i1i1},
	{"vi8i4i2i2i8", __M2N_vi8i4i2i2i8},
	{"vi8i4i4", __M2N_vi8i4i4},
	{"vi8i4i4i1", __M2N_vi8i4i4i1},
	{"vi8i4i4i16", __M2N_vi8i4i4i16},
	{"vi8i4i4i1i4", __M2N_vi8i4i4i1i4},
	{"vi8i4i4i1i8i8", __M2N_vi8i4i4i1i8i8},
	{"vi8i4i4i4", __M2N_vi8i4i4i4},
	{"vi8i4i4i4i1", __M2N_vi8i4i4i4i1},
	{"vi8i4i4i4i1i1", __M2N_vi8i4i4i4i1i1},
	{"vi8i4i4i4i4", __M2N_vi8i4i4i4i4},
	{"vi8i4i4i4i4i1", __M2N_vi8i4i4i4i4i1},
	{"vi8i4i4i4i4i1i1", __M2N_vi8i4i4i4i4i1i1},
	{"vi8i4i4i4i4i1i8", __M2N_vi8i4i4i4i4i1i8},
	{"vi8i4i4i4i4i4", __M2N_vi8i4i4i4i4i4},
	{"vi8i4i4i4i4i4i1", __M2N_vi8i4i4i4i4i4i1},
	{"vi8i4i4i4i4i4i4", __M2N_vi8i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4", __M2N_vi8i4i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4i1", __M2N_vi8i4i4i4i4i4i4i4i1},
	{"vi8i4i4i4i4i4i4i4i1i4", __M2N_vi8i4i4i4i4i4i4i4i1i4},
	{"vi8i4i4i4i4i4i4i4i1i4i1", __M2N_vi8i4i4i4i4i4i4i4i1i4i1},
	{"vi8i4i4i4i4i4i4i4i4", __M2N_vi8i4i4i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4i4i1", __M2N_vi8i4i4i4i4i4i4i4i4i1},
	{"vi8i4i4i4i4i4i4i4i4i1i1", __M2N_vi8i4i4i4i4i4i4i4i4i1i1},
	{"vi8i4i4i4i4i4i4i4i4i1i4", __M2N_vi8i4i4i4i4i4i4i4i4i1i4},
	{"vi8i4i4i4i4i4i4i4i4i1i4i1", __M2N_vi8i4i4i4i4i4i4i4i4i1i4i1},
	{"vi8i4i4i4i4i4i4i4i4i4", __M2N_vi8i4i4i4i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4i4i4i1", __M2N_vi8i4i4i4i4i4i4i4i4i4i1},
	{"vi8i4i4i4i4i4i4i4i8", __M2N_vi8i4i4i4i4i4i4i4i8},
	{"vi8i4i4i4i4i4i4i4i8i4", __M2N_vi8i4i4i4i4i4i4i4i8i4},
	{"vi8i4i4i4i4i4i4i4i8i8", __M2N_vi8i4i4i4i4i4i4i4i8i8},
	{"vi8i4i4i4i4i4i4i8", __M2N_vi8i4i4i4i4i4i4i8},
	{"vi8i4i4i4i4i4i4i8i4i4i4i4", __M2N_vi8i4i4i4i4i4i4i8i4i4i4i4},
	{"vi8i4i4i4i4i4i8", __M2N_vi8i4i4i4i4i4i8},
	{"vi8i4i4i4i4i8", __M2N_vi8i4i4i4i4i8},
	{"vi8i4i4i4i4i8i4", __M2N_vi8i4i4i4i4i8i4},
	{"vi8i4i4i4i8", __M2N_vi8i4i4i4i8},
	{"vi8i4i4i4sri4", __M2N_vi8i4i4i4sri4},
	{"vi8i4i4i4vf4", __M2N_vi8i4i4i4vf4},
	{"vi8i4i4i4vf4i4", __M2N_vi8i4i4i4vf4i4},
	{"vi8i4i4i8", __M2N_vi8i4i4i8},
	{"vi8i4i4i8i4", __M2N_vi8i4i4i8i4},
	{"vi8i4i4i8i4i4", __M2N_vi8i4i4i8i4i4},
	{"vi8i4i4i8i8", __M2N_vi8i4i4i8i8},
	{"vi8i4i4i8i8i8", __M2N_vi8i4i4i8i8i8},
	{"vi8i4i4r4", __M2N_vi8i4i4r4},
	{"vi8i4i4r4i1", __M2N_vi8i4i4r4i1},
	{"vi8i4i4vf4", __M2N_vi8i4i4vf4},
	{"vi8i4i4vf4i4", __M2N_vi8i4i4vf4i4},
	{"vi8i4i8", __M2N_vi8i4i8},
	{"vi8i4i8i1", __M2N_vi8i4i8i1},
	{"vi8i4i8i16", __M2N_vi8i4i8i16},
	{"vi8i4i8i1i1", __M2N_vi8i4i8i1i1},
	{"vi8i4i8i4", __M2N_vi8i4i8i4},
	{"vi8i4i8i4i1i1", __M2N_vi8i4i8i4i1i1},
	{"vi8i4i8i4i2i8i8i8i8", __M2N_vi8i4i8i4i2i8i8i8i8},
	{"vi8i4i8i4i4", __M2N_vi8i4i8i4i4},
	{"vi8i4i8i4i4i4", __M2N_vi8i4i8i4i4i4},
	{"vi8i4i8i4i4i4i4i16i16", __M2N_vi8i4i8i4i4i4i4i16i16},
	{"vi8i4i8i4i8", __M2N_vi8i4i8i4i8},
	{"vi8i4i8i8", __M2N_vi8i4i8i8},
	{"vi8i4i8i8i4", __M2N_vi8i4i8i8i4},
	{"vi8i4i8i8i4i4", __M2N_vi8i4i8i8i4i4},
	{"vi8i4i8i8i4i8", __M2N_vi8i4i8i8i4i8},
	{"vi8i4i8i8i4i8i4", __M2N_vi8i4i8i8i4i8i4},
	{"vi8i4i8i8i4i8i4i1", __M2N_vi8i4i8i8i4i8i4i1},
	{"vi8i4i8i8i4i8i4i1i4", __M2N_vi8i4i8i8i4i8i4i1i4},
	{"vi8i4i8i8i4i8i4i1i4i8", __M2N_vi8i4i8i8i4i8i4i1i4i8},
	{"vi8i4i8i8i4i8i4i1i4i8i4", __M2N_vi8i4i8i8i4i8i4i1i4i8i4},
	{"vi8i4i8i8i4i8i4i1i4i8i4i8", __M2N_vi8i4i8i8i4i8i4i1i4i8i4i8},
	{"vi8i4i8i8i8", __M2N_vi8i4i8i8i8},
	{"vi8i4i8i8i8i4", __M2N_vi8i4i8i8i8i4},
	{"vi8i4i8i8i8i4i1", __M2N_vi8i4i8i8i8i4i1},
	{"vi8i4i8i8i8i4i1i4", __M2N_vi8i4i8i8i8i4i1i4},
	{"vi8i4i8i8i8i4i1i4i8", __M2N_vi8i4i8i8i8i4i1i4i8},
	{"vi8i4i8i8i8i4i1i4i8i4", __M2N_vi8i4i8i8i8i4i1i4i8i4},
	{"vi8i4i8i8i8i4i1i4i8i4i8", __M2N_vi8i4i8i8i8i4i1i4i8i4i8},
	{"vi8i4i8i8i8i8", __M2N_vi8i4i8i8i8i8},
	{"vi8i4i8i8i8i8i8", __M2N_vi8i4i8i8i8i8i8},
	{"vi8i4i8sri4i8i4i1i4i8i4i8", __M2N_vi8i4i8sri4i8i4i1i4i8i4i8},
	{"vi8i4i8sri8i4i8i4i1i4i8i4", __M2N_vi8i4i8sri8i4i8i4i1i4i8i4},
	{"vi8i4i8sri8i4i8i4i1i4i8i4i8", __M2N_vi8i4i8sri8i4i8i4i1i4i8i4i8},
	{"vi8i4i8vf3", __M2N_vi8i4i8vf3},
	{"vi8i4r4", __M2N_vi8i4r4},
	{"vi8i4r4i8", __M2N_vi8i4r4i8},
	{"vi8i4r4i8i8", __M2N_vi8i4r4i8i8},
	{"vi8i4r4r4", __M2N_vi8i4r4r4},
	{"vi8i4sr", __M2N_vi8i4sr},
	{"vi8i4sri1i1i1", __M2N_vi8i4sri1i1i1},
	{"vi8i4sri4", __M2N_vi8i4sri4},
	{"vi8i4srsr", __M2N_vi8i4srsr},
	{"vi8i4vf2", __M2N_vi8i4vf2},
	{"vi8i4vf3", __M2N_vi8i4vf3},
	{"vi8i4vf3vf4", __M2N_vi8i4vf3vf4},
	{"vi8i4vf3vf4vf3", __M2N_vi8i4vf3vf4vf3},
	{"vi8i4vf4", __M2N_vi8i4vf4},
	{"vi8i8", __M2N_vi8i8},
	{"vi8i8i1", __M2N_vi8i8i1},
	{"vi8i8i16", __M2N_vi8i8i16},
	{"vi8i8i16i4", __M2N_vi8i8i16i4},
	{"vi8i8i16i4i4", __M2N_vi8i8i16i4i4},
	{"vi8i8i16i4i4i8i8i4i4", __M2N_vi8i8i16i4i4i8i8i4i4},
	{"vi8i8i16i8", __M2N_vi8i8i16i8},
	{"vi8i8i1i1", __M2N_vi8i8i1i1},
	{"vi8i8i1i1i1", __M2N_vi8i8i1i1i1},
	{"vi8i8i1i1i1i1", __M2N_vi8i8i1i1i1i1},
	{"vi8i8i1i4", __M2N_vi8i8i1i4},
	{"vi8i8i1i4i1", __M2N_vi8i8i1i4i1},
	{"vi8i8i1i8", __M2N_vi8i8i1i8},
	{"vi8i8i1i8i1", __M2N_vi8i8i1i8i1},
	{"vi8i8i1i8i4", __M2N_vi8i8i1i8i4},
	{"vi8i8i1i8i8", __M2N_vi8i8i1i8i8},
	{"vi8i8i1i8i8i4", __M2N_vi8i8i1i8i8i4},
	{"vi8i8i2", __M2N_vi8i8i2},
	{"vi8i8i2i1", __M2N_vi8i8i2i1},
	{"vi8i8i4", __M2N_vi8i8i4},
	{"vi8i8i4i1", __M2N_vi8i8i4i1},
	{"vi8i8i4i1i1i1i1i8i4", __M2N_vi8i8i4i1i1i1i1i8i4},
	{"vi8i8i4i1i4", __M2N_vi8i8i4i1i4},
	{"vi8i8i4i1i4i1", __M2N_vi8i8i4i1i4i1},
	{"vi8i8i4i1i4i4i16i16i4", __M2N_vi8i8i4i1i4i4i16i16i4},
	{"vi8i8i4i1i4i4i4", __M2N_vi8i8i4i1i4i4i4},
	{"vi8i8i4i1i8i8i8i8", __M2N_vi8i8i4i1i8i8i8i8},
	{"vi8i8i4i2i8i8i8", __M2N_vi8i8i4i2i8i8i8},
	{"vi8i8i4i2i8i8i8i8", __M2N_vi8i8i4i2i8i8i8i8},
	{"vi8i8i4i4", __M2N_vi8i8i4i4},
	{"vi8i8i4i4i1", __M2N_vi8i8i4i4i1},
	{"vi8i8i4i4i1i1", __M2N_vi8i8i4i4i1i1},
	{"vi8i8i4i4i1i4", __M2N_vi8i8i4i4i1i4},
	{"vi8i8i4i4i2", __M2N_vi8i8i4i4i2},
	{"vi8i8i4i4i2i8", __M2N_vi8i8i4i4i2i8},
	{"vi8i8i4i4i4", __M2N_vi8i8i4i4i4},
	{"vi8i8i4i4i4i1i4", __M2N_vi8i8i4i4i4i1i4},
	{"vi8i8i4i4i4i4", __M2N_vi8i8i4i4i4i4},
	{"vi8i8i4i4i4i4i1", __M2N_vi8i8i4i4i4i4i1},
	{"vi8i8i4i4i4i4i1i4", __M2N_vi8i8i4i4i4i4i1i4},
	{"vi8i8i4i4i4i4i4", __M2N_vi8i8i4i4i4i4i4},
	{"vi8i8i4i4i4i4i4i4", __M2N_vi8i8i4i4i4i4i4i4},
	{"vi8i8i4i4i4i4i4i4i4i4i8", __M2N_vi8i8i4i4i4i4i4i4i4i4i8},
	{"vi8i8i4i4i4i4i4i4i4i8", __M2N_vi8i8i4i4i4i4i4i4i4i8},
	{"vi8i8i4i4i4i4i4i4i8", __M2N_vi8i8i4i4i4i4i4i4i8},
	{"vi8i8i4i4i4i4i4i4i8i4", __M2N_vi8i8i4i4i4i4i4i4i8i4},
	{"vi8i8i4i4i4i4i4i4i8i4i4", __M2N_vi8i8i4i4i4i4i4i4i8i4i4},
	{"vi8i8i4i4i4i4i4i8", __M2N_vi8i8i4i4i4i4i4i8},
	{"vi8i8i4i4i4i4i8", __M2N_vi8i8i4i4i4i4i8},
	{"vi8i8i4i4i4i8", __M2N_vi8i8i4i4i4i8},
	{"vi8i8i4i4i8", __M2N_vi8i8i4i4i8},
	{"vi8i8i4i4i8i4", __M2N_vi8i8i4i4i8i4},
	{"vi8i8i4i4i8i4i4", __M2N_vi8i8i4i4i8i4i4},
	{"vi8i8i4i4i8i4i4i1i8i8i8", __M2N_vi8i8i4i4i8i4i4i1i8i8i8},
	{"vi8i8i4i4i8i8", __M2N_vi8i8i4i4i8i8},
	{"vi8i8i4i4i8i8i8i1", __M2N_vi8i8i4i4i8i8i8i1},
	{"vi8i8i4i4sr", __M2N_vi8i8i4i4sr},
	{"vi8i8i4i4sri4", __M2N_vi8i8i4i4sri4},
	{"vi8i8i4i4sri4i4", __M2N_vi8i8i4i4sri4i4},
	{"vi8i8i4i8", __M2N_vi8i8i4i8},
	{"vi8i8i4i8i1i1i1i4i1", __M2N_vi8i8i4i8i1i1i1i4i1},
	{"vi8i8i4i8i4", __M2N_vi8i8i4i8i4},
	{"vi8i8i4i8i4i1i8i8i8", __M2N_vi8i8i4i8i4i1i8i8i8},
	{"vi8i8i4i8i4i4", __M2N_vi8i8i4i8i4i4},
	{"vi8i8i4i8i4i4i4i4", __M2N_vi8i8i4i8i4i4i4i4},
	{"vi8i8i4i8i4i4i4i4i4i4", __M2N_vi8i8i4i8i4i4i4i4i4i4},
	{"vi8i8i4i8i4i4i8", __M2N_vi8i8i4i8i4i4i8},
	{"vi8i8i4i8i4i8", __M2N_vi8i8i4i8i4i8},
	{"vi8i8i4i8i4i8i4", __M2N_vi8i8i4i8i4i8i4},
	{"vi8i8i4i8i4i8i4i8", __M2N_vi8i8i4i8i4i8i4i8},
	{"vi8i8i4i8i8", __M2N_vi8i8i4i8i8},
	{"vi8i8i4i8i8i1", __M2N_vi8i8i4i8i8i1},
	{"vi8i8i4i8i8i1i8", __M2N_vi8i8i4i8i8i1i8},
	{"vi8i8i4i8i8i8", __M2N_vi8i8i4i8i8i8},
	{"vi8i8i4i8sr", __M2N_vi8i8i4i8sr},
	{"vi8i8i4i8sri1i1i1i4i1", __M2N_vi8i8i4i8sri1i1i1i4i1},
	{"vi8i8i4i8sri4", __M2N_vi8i8i4i8sri4},
	{"vi8i8i4i8sri4i4", __M2N_vi8i8i4i8sri4i4},
	{"vi8i8i4r4", __M2N_vi8i8i4r4},
	{"vi8i8i4sr", __M2N_vi8i8i4sr},
	{"vi8i8i4srsri4i4", __M2N_vi8i8i4srsri4i4},
	{"vi8i8i4vf4", __M2N_vi8i8i4vf4},
	{"vi8i8i8", __M2N_vi8i8i8},
	{"vi8i8i8i1", __M2N_vi8i8i8i1},
	{"vi8i8i8i16", __M2N_vi8i8i8i16},
	{"vi8i8i8i16i4", __M2N_vi8i8i8i16i4},
	{"vi8i8i8i1i1", __M2N_vi8i8i8i1i1},
	{"vi8i8i8i1i1i1", __M2N_vi8i8i8i1i1i1},
	{"vi8i8i8i1i1i1i4", __M2N_vi8i8i8i1i1i1i4},
	{"vi8i8i8i1i1i4", __M2N_vi8i8i8i1i1i4},
	{"vi8i8i8i1i2i2i1", __M2N_vi8i8i8i1i2i2i1},
	{"vi8i8i8i1i4", __M2N_vi8i8i8i1i4},
	{"vi8i8i8i1i4i1", __M2N_vi8i8i8i1i4i1},
	{"vi8i8i8i1i4i8", __M2N_vi8i8i8i1i4i8},
	{"vi8i8i8i1i8", __M2N_vi8i8i8i1i8},
	{"vi8i8i8i2i1", __M2N_vi8i8i8i2i1},
	{"vi8i8i8i4", __M2N_vi8i8i8i4},
	{"vi8i8i8i4i1", __M2N_vi8i8i8i4i1},
	{"vi8i8i8i4i4", __M2N_vi8i8i8i4i4},
	{"vi8i8i8i4i4i4", __M2N_vi8i8i8i4i4i4},
	{"vi8i8i8i4i4i4i4", __M2N_vi8i8i8i4i4i4i4},
	{"vi8i8i8i4i4i4i8", __M2N_vi8i8i8i4i4i4i8},
	{"vi8i8i8i4i4i8", __M2N_vi8i8i8i4i4i8},
	{"vi8i8i8i4i4i8i4", __M2N_vi8i8i8i4i4i8i4},
	{"vi8i8i8i4i4i8i8", __M2N_vi8i8i8i4i4i8i8},
	{"vi8i8i8i4i8", __M2N_vi8i8i8i4i8},
	{"vi8i8i8i4i8i16", __M2N_vi8i8i8i4i8i16},
	{"vi8i8i8i4i8i4i4", __M2N_vi8i8i8i4i8i4i4},
	{"vi8i8i8i4i8i4i4i4i4", __M2N_vi8i8i8i4i8i4i4i4i4},
	{"vi8i8i8i4i8i8", __M2N_vi8i8i8i4i8i8},
	{"vi8i8i8i4i8i8i8", __M2N_vi8i8i8i4i8i8i8},
	{"vi8i8i8i8", __M2N_vi8i8i8i8},
	{"vi8i8i8i8i1", __M2N_vi8i8i8i8i1},
	{"vi8i8i8i8i1i1", __M2N_vi8i8i8i8i1i1},
	{"vi8i8i8i8i1i1i4", __M2N_vi8i8i8i8i1i1i4},
	{"vi8i8i8i8i1i8", __M2N_vi8i8i8i8i1i8},
	{"vi8i8i8i8i1i8i4i8i1i1", __M2N_vi8i8i8i8i1i8i4i8i1i1},
	{"vi8i8i8i8i4", __M2N_vi8i8i8i8i4},
	{"vi8i8i8i8i4i4", __M2N_vi8i8i8i8i4i4},
	{"vi8i8i8i8i4i8", __M2N_vi8i8i8i8i4i8},
	{"vi8i8i8i8i8", __M2N_vi8i8i8i8i8},
	{"vi8i8i8i8i8i1", __M2N_vi8i8i8i8i8i1},
	{"vi8i8i8i8i8i1i1", __M2N_vi8i8i8i8i8i1i1},
	{"vi8i8i8i8i8i4", __M2N_vi8i8i8i8i8i4},
	{"vi8i8i8i8i8i8", __M2N_vi8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i4", __M2N_vi8i8i8i8i8i8i4},
	{"vi8i8i8i8i8i8i4i8", __M2N_vi8i8i8i8i8i8i4i8},
	{"vi8i8i8i8i8i8i4i8i8i8", __M2N_vi8i8i8i8i8i8i4i8i8i8},
	{"vi8i8i8i8i8i8i8", __M2N_vi8i8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i8i4", __M2N_vi8i8i8i8i8i8i8i4},
	{"vi8i8i8i8i8i8i8i4i8", __M2N_vi8i8i8i8i8i8i8i4i8},
	{"vi8i8i8i8i8i8i8i8", __M2N_vi8i8i8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i8i8i8", __M2N_vi8i8i8i8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i8i8i8i4", __M2N_vi8i8i8i8i8i8i8i8i8i4},
	{"vi8i8i8i8i8i8i8i8i8i4i8", __M2N_vi8i8i8i8i8i8i8i8i8i4i8},
	{"vi8i8i8i8i8i8i8i8i8i8", __M2N_vi8i8i8i8i8i8i8i8i8i8},
	{"vi8i8i8i8sri4i4", __M2N_vi8i8i8i8sri4i4},
	{"vi8i8i8r4", __M2N_vi8i8i8r4},
	{"vi8i8i8sr", __M2N_vi8i8i8sr},
	{"vi8i8i8vf4", __M2N_vi8i8i8vf4},
	{"vi8i8r4", __M2N_vi8i8r4},
	{"vi8i8r4i8", __M2N_vi8i8r4i8},
	{"vi8i8r4i8i8", __M2N_vi8i8r4i8i8},
	{"vi8i8r4i8i8i8", __M2N_vi8i8r4i8i8i8},
	{"vi8i8r4r4", __M2N_vi8i8r4r4},
	{"vi8i8r8", __M2N_vi8i8r8},
	{"vi8i8r8i8", __M2N_vi8i8r8i8},
	{"vi8i8sr", __M2N_vi8i8sr},
	{"vi8i8sri4", __M2N_vi8i8sri4},
	{"vi8i8sri4i4i4", __M2N_vi8i8sri4i4i4},
	{"vi8i8sri8", __M2N_vi8i8sri8},
	{"vi8i8sri8i4", __M2N_vi8i8sri8i4},
	{"vi8i8sri8i4i4", __M2N_vi8i8sri8i4i4},
	{"vi8i8sri8i4i4i4", __M2N_vi8i8sri8i4i4i4},
	{"vi8i8sri8i4i4i4i4", __M2N_vi8i8sri8i4i4i4i4},
	{"vi8i8sri8i4i4i4i4i8", __M2N_vi8i8sri8i4i4i4i4i8},
	{"vi8i8sri8i4i4i8", __M2N_vi8i8sri8i4i4i8},
	{"vi8i8sri8i4i4i8i4", __M2N_vi8i8sri8i4i4i8i4},
	{"vi8i8sri8i4i4i8i4i8", __M2N_vi8i8sri8i4i4i8i4i8},
	{"vi8i8srvf2vf2", __M2N_vi8i8srvf2vf2},
	{"vi8i8vf2", __M2N_vi8i8vf2},
	{"vi8i8vf2vf2", __M2N_vi8i8vf2vf2},
	{"vi8i8vf2vf2i4i4", __M2N_vi8i8vf2vf2i4i4},
	{"vi8i8vf3", __M2N_vi8i8vf3},
	{"vi8i8vf4", __M2N_vi8i8vf4},
	{"vi8r4", __M2N_vi8r4},
	{"vi8r4i1", __M2N_vi8r4i1},
	{"vi8r4i8", __M2N_vi8r4i8},
	{"vi8r4r4", __M2N_vi8r4r4},
	{"vi8r4r4r4", __M2N_vi8r4r4r4},
	{"vi8r4r4r4i4", __M2N_vi8r4r4r4i4},
	{"vi8r4r4r4i8", __M2N_vi8r4r4r4i8},
	{"vi8r4r4r4r4", __M2N_vi8r4r4r4r4},
	{"vi8r4r4r4r4r4r4", __M2N_vi8r4r4r4r4r4r4},
	{"vi8r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4", __M2N_vi8r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4},
	{"vi8r4vf2vf2r4r4i8", __M2N_vi8r4vf2vf2r4r4i8},
	{"vi8r8", __M2N_vi8r8},
	{"vi8r8i8", __M2N_vi8r8i8},
	{"vi8r8r8", __M2N_vi8r8r8},
	{"vi8sr", __M2N_vi8sr},
	{"vi8sri1", __M2N_vi8sri1},
	{"vi8sri1i1", __M2N_vi8sri1i1},
	{"vi8sri4", __M2N_vi8sri4},
	{"vi8sri4i1", __M2N_vi8sri4i1},
	{"vi8sri4i4", __M2N_vi8sri4i4},
	{"vi8sri4i4i4", __M2N_vi8sri4i4i4},
	{"vi8sri4i4i4i4", __M2N_vi8sri4i4i4i4},
	{"vi8sri4i4i4i4i4i4sri4i4i4i4", __M2N_vi8sri4i4i4i4i4i4sri4i4i4i4},
	{"vi8sri4i4i4i8i8i4i1i4", __M2N_vi8sri4i4i4i8i8i4i1i4},
	{"vi8sri4i4sri4i4", __M2N_vi8sri4i4sri4i4},
	{"vi8sri4i8", __M2N_vi8sri4i8},
	{"vi8sri4i8i4i4i8i8i4i1i4", __M2N_vi8sri4i8i4i4i8i8i4i1i4},
	{"vi8sri4i8i4i8i8i4i1i4", __M2N_vi8sri4i8i4i8i8i4i1i4},
	{"vi8sri4i8i8i4i8i8i4i1i4", __M2N_vi8sri4i8i8i4i8i8i4i1i4},
	{"vi8sri4r4i1", __M2N_vi8sri4r4i1},
	{"vi8sri4sri4", __M2N_vi8sri4sri4},
	{"vi8sri8", __M2N_vi8sri8},
	{"vi8sri8i4", __M2N_vi8sri8i4},
	{"vi8sri8i4i4i4", __M2N_vi8sri8i4i4i4},
	{"vi8sri8i4i4i4i4", __M2N_vi8sri8i4i4i4i4},
	{"vi8sri8i4i4i4i4i4i4", __M2N_vi8sri8i4i4i4i4i4i4},
	{"vi8sri8i4i4i4i4i8", __M2N_vi8sri8i4i4i4i4i8},
	{"vi8sri8i4i4i8", __M2N_vi8sri8i4i4i8},
	{"vi8sri8i4i4i8i4", __M2N_vi8sri8i4i4i8i4},
	{"vi8sri8i4i4i8i4i8", __M2N_vi8sri8i4i4i8i4i8},
	{"vi8sri8i4i8", __M2N_vi8sri8i4i8},
	{"vi8sri8i4i8i4", __M2N_vi8sri8i4i8i4},
	{"vi8sri8i4i8i4i8", __M2N_vi8sri8i4i8i4i8},
	{"vi8sri8i4i8i4i8i1", __M2N_vi8sri8i4i8i4i8i1},
	{"vi8sri8i4i8i4i8i1i1", __M2N_vi8sri8i4i8i4i8i1i1},
	{"vi8sri8i4i8i4i8i1i1i1", __M2N_vi8sri8i4i8i4i8i1i1i1},
	{"vi8sri8i4i8i4i8i4", __M2N_vi8sri8i4i8i4i8i4},
	{"vi8sri8i4i8i4i8i4i1", __M2N_vi8sri8i4i8i4i8i4i1},
	{"vi8sri8i4i8i4i8i4i1i8", __M2N_vi8sri8i4i8i4i8i4i1i8},
	{"vi8sri8i4i8i4i8i4i1i8i1", __M2N_vi8sri8i4i8i4i8i4i1i8i1},
	{"vi8sri8i4i8i4i8i4i1i8i4", __M2N_vi8sri8i4i8i4i8i4i1i8i4},
	{"vi8sri8i4i8i4i8i4i1i8i4i8", __M2N_vi8sri8i4i8i4i8i4i1i8i4i8},
	{"vi8sri8i8", __M2N_vi8sri8i8},
	{"vi8sri8i8i8", __M2N_vi8sri8i8i8},
	{"vi8sri8i8i8i1srsr", __M2N_vi8sri8i8i8i1srsr},
	{"vi8sri8i8srsr", __M2N_vi8sri8i8srsr},
	{"vi8srsr", __M2N_vi8srsr},
	{"vi8srsri1", __M2N_vi8srsri1},
	{"vi8srsri1i1", __M2N_vi8srsri1i1},
	{"vi8srsri4", __M2N_vi8srsri4},
	{"vi8srsri4i4", __M2N_vi8srsri4i4},
	{"vi8srsri4i4i4", __M2N_vi8srsri4i4i4},
	{"vi8srsri8", __M2N_vi8srsri8},
	{"vi8srsri8i4", __M2N_vi8srsri8i4},
	{"vi8srsri8i4i4", __M2N_vi8srsri8i4i4},
	{"vi8srsrsrsr", __M2N_vi8srsrsrsr},
	{"vi8srsrsrsrsrr4", __M2N_vi8srsrsrsrsrr4},
	{"vi8srsrvf2vf2", __M2N_vi8srsrvf2vf2},
	{"vi8srsrvf2vf2i4i4", __M2N_vi8srsrvf2vf2i4i4},
	{"vi8srvf4", __M2N_vi8srvf4},
	{"vi8vd3", __M2N_vi8vd3},
	{"vi8vf2", __M2N_vi8vf2},
	{"vi8vf2i1i1i8", __M2N_vi8vf2i1i1i8},
	{"vi8vf2i1i1i8i8i8", __M2N_vi8vf2i1i1i8i8i8},
	{"vi8vf2i1i1i8i8i8i8", __M2N_vi8vf2i1i1i8i8i8i8},
	{"vi8vf2i4", __M2N_vi8vf2i4},
	{"vi8vf2i8", __M2N_vi8vf2i8},
	{"vi8vf2i8i8", __M2N_vi8vf2i8i8},
	{"vi8vf2i8i8i8", __M2N_vi8vf2i8i8i8},
	{"vi8vf2r4", __M2N_vi8vf2r4},
	{"vi8vf2r4r4", __M2N_vi8vf2r4r4},
	{"vi8vf2vf2", __M2N_vi8vf2vf2},
	{"vi8vf3", __M2N_vi8vf3},
	{"vi8vf3i4", __M2N_vi8vf3i4},
	{"vi8vf3i8", __M2N_vi8vf3i8},
	{"vi8vf3i8i8", __M2N_vi8vf3i8i8},
	{"vi8vf3r4", __M2N_vi8vf3r4},
	{"vi8vf3r4i4", __M2N_vi8vf3r4i4},
	{"vi8vf3vf3", __M2N_vi8vf3vf3},
	{"vi8vf3vf3r4", __M2N_vi8vf3vf3r4},
	{"vi8vf3vf3vf3", __M2N_vi8vf3vf3vf3},
	{"vi8vf3vf4", __M2N_vi8vf3vf4},
	{"vi8vf3vf4i4", __M2N_vi8vf3vf4i4},
	{"vi8vf3vf4i8i4", __M2N_vi8vf3vf4i8i4},
	{"vi8vf3vf4i8i4i8", __M2N_vi8vf3vf4i8i4i8},
	{"vi8vf3vf4i8i4i8i4", __M2N_vi8vf3vf4i8i4i8i4},
	{"vi8vf3vf4i8i4i8i4i8", __M2N_vi8vf3vf4i8i4i8i4i8},
	{"vi8vf3vf4i8i4i8i4i8i1", __M2N_vi8vf3vf4i8i4i8i4i8i1},
	{"vi8vf3vf4i8i4i8i4i8i1i1", __M2N_vi8vf3vf4i8i4i8i4i8i1i1},
	{"vi8vf3vf4i8i4i8i4i8i1i1i1", __M2N_vi8vf3vf4i8i4i8i4i8i1i1i1},
	{"vi8vf3vf4i8i4i8i4i8i4", __M2N_vi8vf3vf4i8i4i8i4i8i4},
	{"vi8vf3vf4i8i4i8i4i8i4i1", __M2N_vi8vf3vf4i8i4i8i4i8i4i1},
	{"vi8vf3vf4i8i4i8i4i8i4i1i8", __M2N_vi8vf3vf4i8i4i8i4i8i4i1i8},
	{"vi8vf3vf4i8i4i8i4i8i4i1i8i1", __M2N_vi8vf3vf4i8i4i8i4i8i4i1i8i1},
	{"vi8vf3vf4r4", __M2N_vi8vf3vf4r4},
	{"vi8vf3vf4vf3", __M2N_vi8vf3vf4vf3},
	{"vi8vf4", __M2N_vi8vf4},
	{"vi8vf4i1i1i1i1", __M2N_vi8vf4i1i1i1i1},
	{"vi8vf4i4", __M2N_vi8vf4i4},
	{"vi8vf4i4i4", __M2N_vi8vf4i4i4},
	{"vi8vf4i4i4i1", __M2N_vi8vf4i4i4i1},
	{"vi8vf4i8", __M2N_vi8vf4i8},
	{"vi8vf4i8i1i1i1i1", __M2N_vi8vf4i8i1i1i1i1},
	{"vi8vf4i8i4", __M2N_vi8vf4i8i4},
	{"vi8vf4i8i4i1", __M2N_vi8vf4i8i4i1},
	{"vi8vf4i8i4i1i1", __M2N_vi8vf4i8i4i1i1},
	{"vi8vf4i8i4i4", __M2N_vi8vf4i8i4i4},
	{"vi8vf4i8i4i4i4", __M2N_vi8vf4i8i4i4i4},
	{"vi8vf4i8i8", __M2N_vi8vf4i8i8},
	{"vi8vf4r4", __M2N_vi8vf4r4},
	{"vi8vf4r4i4", __M2N_vi8vf4r4i4},
	{"vi8vf4r4i4i8", __M2N_vi8vf4r4i4i8},
	{"vi8vf4vf2vf4", __M2N_vi8vf4vf2vf4},
	{"vi8vf4vf2vf4i1i1", __M2N_vi8vf4vf2vf4i1i1},
	{"vi8vf4vf2vf4i1i1i8i8", __M2N_vi8vf4vf2vf4i1i1i8i8},
	{"vi8vf4vf2vf4i8i8", __M2N_vi8vf4vf2vf4i8i8},
	{"vi8vf4vf4", __M2N_vi8vf4vf4},
	{"vi8vf4vf4vf4vf4", __M2N_vi8vf4vf4vf4vf4},
	{"vr4", __M2N_vr4},
	{"vr4r4", __M2N_vr4r4},
	{"vr4r4i8", __M2N_vr4r4i8},
	{"vr4r4r4", __M2N_vr4r4r4},
	{"vr4r4r4i8", __M2N_vr4r4r4i8},
	{"vr4r4r4r4", __M2N_vr4r4r4r4},
	{"vr4vf2", __M2N_vr4vf2},
	{"vr8", __M2N_vr8},
	{"vr8r8", __M2N_vr8r8},
	{"vr8r8i8", __M2N_vr8r8i8},
	{"vsr", __M2N_vsr},
	{"vsri2", __M2N_vsri2},
	{"vsri4", __M2N_vsri4},
	{"vsri8", __M2N_vsri8},
	{"vsri8i4", __M2N_vsri8i4},
	{"vvf2", __M2N_vvf2},
	{"vvf2vf2", __M2N_vvf2vf2},
	{"vvf3", __M2N_vvf3},
	{"vvf3i8", __M2N_vvf3i8},
	{"vvf3i8i1", __M2N_vvf3i8i1},
	{"vvf3i8i1vf4", __M2N_vvf3i8i1vf4},
	{"vvf3i8i8", __M2N_vvf3i8i8},
	{"vvf3r4", __M2N_vvf3r4},
	{"vvf3r4r4r4r4", __M2N_vvf3r4r4r4r4},
	{"vvf3vf3", __M2N_vvf3vf3},
	{"vvf3vf3vf4", __M2N_vvf3vf3vf4},
	{"vvf3vf3vf4r4", __M2N_vvf3vf3vf4r4},
	{"vvf3vf3vf4r4i1", __M2N_vvf3vf3vf4r4i1},
	{"vvf4", __M2N_vvf4},
	{"vvf4i8", __M2N_vvf4i8},
	{"vvf4i8i4", __M2N_vvf4i8i4},
	{"vvf4i8i4i1", __M2N_vvf4i8i4i1},
	{"vvf4i8i4i1r4", __M2N_vvf4i8i4i1r4},
	{"vvf4i8i4i1r4vf4r4r4", __M2N_vvf4i8i4i1r4vf4r4r4},
	{"vvf4i8i4i1r4vf4vf4r4", __M2N_vvf4i8i4i1r4vf4vf4r4},
	{"vvf4i8i4i1r4vf4vf4vf4", __M2N_vvf4i8i4i1r4vf4vf4vf4},
	{"vvf4i8i4i4i4i4", __M2N_vvf4i8i4i4i4i4},
	{"vvf4i8i4i4i4i4i8", __M2N_vvf4i8i4i4i4i4i8},
	{"vvf4i8i4i4i4i4i8i4", __M2N_vvf4i8i4i4i4i4i8i4},
	{"vvf4i8i8", __M2N_vvf4i8i8},
	{"vvf4i8i8i4", __M2N_vvf4i8i8i4},
	{"vvf4i8i8i8", __M2N_vvf4i8i8i8},
	{"vvf4i8vf4", __M2N_vvf4i8vf4},
	{"vvf4i8vf4i1", __M2N_vvf4i8vf4i1},
	{"vvf4i8vf4i4i4i4i4", __M2N_vvf4i8vf4i4i4i4i4},
	{"vvf4i8vf4i4i4i4i4i8", __M2N_vvf4i8vf4i4i4i4i4i8},
	{"vvf4i8vf4i4i4i4i4i8i4", __M2N_vvf4i8vf4i4i4i4i4i8i4},
	{"vvf4i8vf4i4i4i4i4vf4", __M2N_vvf4i8vf4i4i4i4i4vf4},
	{"vvf4i8vf4i4i4i4i4vf4i8", __M2N_vvf4i8vf4i4i4i4i4vf4i8},
	{"vvf4i8vf4i4i4i4i4vf4i8i4", __M2N_vvf4i8vf4i4i4i4i4vf4i8i4},
	{"vvf4vf2vf2i1", __M2N_vvf4vf2vf2i1},
	{nullptr, nullptr},
};

static int8_t __N2M_i1(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static ValueTypeSize16 __N2M_i16(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i16(ValueTypeSize16 __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i16i8(ValueTypeSize16 __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8i16i8(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8i8sr(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_i16i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static int8_t __N2M_i1i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i16i16(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i16i4i4i4i8i8(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i16i8(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i2i2i4(int64_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i2i4(int64_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4i1(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i4i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i4i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i4i4i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8i4i4i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8r4r4(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8vd2(int64_t __arg0, HtVector2d __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8vf2(int64_t __arg0, HtVector2f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8vf3(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i8vf4(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int16_t __N2M_i2(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int16_t __N2M_i2i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int16_t __N2M_i2i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int16_t __N2M_i2i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int32_t __N2M_i4(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i1(int8_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i2(int16_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i4i4i1(int64_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i4i4i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i4i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i1i4(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i2(int64_t __arg0, int64_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i2i4(int64_t __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i2i4i4(int64_t __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i2i4i4i4(int64_t __arg0, int64_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i4i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i4i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i4i8i4i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i4i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i4i8i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i8i4i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i4i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8i8i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int64_t __N2M_i8(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i4i8i8i8(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i16i4i1i8(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i16i8(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i2i2(int64_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i1(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i4i4i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i4i4i4i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i4i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i8i4i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i8i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i4i8i8i8i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i16i16i16(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, ValueTypeSize16 __arg3, ValueTypeSize16 __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3, (uint64_t)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i16i8(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i1i8i8(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i4i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i4i1i8i8(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i4i8i8i8i8(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i8(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i1i8i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i1i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i1i4i4i4i16i16(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize16 __arg7, ValueTypeSize16 __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, (uint64_t)&__arg7, (uint64_t)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i8i8i8i8i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int8_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i4i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i16i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, (uint64_t)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i1i4i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method)
{
    StackObject args[11] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = args + 10;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i1i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i1i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i4i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i8i8i8i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int8_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i4i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i4i4i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8i8i8i8i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int32_t __arg8, int64_t __arg9, const MethodInfo* method)
{
    StackObject args[11] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = args + 10;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8r8(int64_t __arg0, int64_t __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8i8sri8i8i8(int64_t __arg0, int64_t __arg1, uint64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i8sri8i8i8(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static float __N2M_r4(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4r4(float __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static double __N2M_r8(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8r8(double __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static ValueTypeSize<120> __N2M_S120i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[16] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<120>*)ret;
}


static ValueTypeSize<120> __N2M_S120i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[17] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<120>*)ret;
}


static ValueTypeSize<20> __N2M_S20(const MethodInfo* method)
{
    StackObject args[3] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20sr(uint64_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<24> __N2M_S24i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<32> __N2M_S32i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<32>*)ret;
}


static ValueTypeSize<32> __N2M_S32i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<32>*)ret;
}


static ValueTypeSize<64> __N2M_S64i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<64>*)ret;
}


static void __N2M_v(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static HtVector3d __N2M_vd3(const MethodInfo* method)
{
    StackObject args[3] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3d*)ret;
}


static HtVector3d __N2M_vd3i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3d*)ret;
}


static HtVector3d __N2M_vd3i8vd3(int64_t __arg0, HtVector3d __arg1, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3d*)ret;
}


static HtVector3d __N2M_vd3vd3(HtVector3d __arg0, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3d*)ret;
}


static HtVector4d __N2M_vd4(const MethodInfo* method)
{
    StackObject args[4] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4d*)ret;
}


static HtVector4d __N2M_vd4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4d*)ret;
}


static HtVector4d __N2M_vd4i8vd4(int64_t __arg0, HtVector4d __arg1, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4d*)ret;
}


static HtVector4d __N2M_vd4vd4(HtVector4d __arg0, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4d*)ret;
}


static HtVector2f __N2M_vf2i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector2f*)ret;
}


static HtVector3f __N2M_vf3(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector3f __N2M_vf3i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector3f __N2M_vf3i8vf3(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector3f __N2M_vf3vf3(HtVector3f __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector4f __N2M_vf4(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static HtVector4f __N2M_vf4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static HtVector4f __N2M_vf4i8vf4(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static HtVector4f __N2M_vf4vf4(HtVector4f __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static void __N2M_vi16(ValueTypeSize16 __arg0, const MethodInfo* method)
{
    StackObject args[1] = {(uint64_t)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi16i8(ValueTypeSize16 __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi1i8(int8_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[1] = {*(uint64_t*)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i8(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8vf3(int32_t __arg0, int64_t __arg1, HtVector3f __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[1] = {*(uint64_t*)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i16i16(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i16i8(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i16i8i8(int64_t __arg0, ValueTypeSize16 __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i16sr(int64_t __arg0, ValueTypeSize16 __arg1, uint64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i16sri8(int64_t __arg0, ValueTypeSize16 __arg1, uint64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i1i8(int64_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i1i8i4(int64_t __arg0, int8_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i2i2(int64_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i2i8(int64_t __arg0, int16_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i16(int64_t __arg0, int32_t __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i1i1(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i1i8i8i8i8(int64_t __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i4i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i4i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i4i8i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i4i2i8i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int16_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i4i4(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4i8vf3(int64_t __arg0, int32_t __arg1, int64_t __arg2, HtVector3f __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i4sr(int64_t __arg0, int32_t __arg1, uint64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i16(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i16i8(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i1i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i1i4i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i1i8(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i1i8i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i2(int64_t __arg0, int64_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i1i8i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i2i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int16_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i2i8i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int16_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4i4i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i4i8i4i4i1i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int64_t __arg8, int64_t __arg9, int64_t __arg10, const MethodInfo* method)
{
    StackObject args[11] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i8i4i1i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int8_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i8i4i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i8i4i4i4i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i4i8i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i16(int64_t __arg0, int64_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i1i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i4i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i4i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i8i16(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, ValueTypeSize16 __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, (uint64_t)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i8i4i4i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i4i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8i8i8i8i8i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8r4(int64_t __arg0, int64_t __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8r8(int64_t __arg0, int64_t __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8i8sr(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8r4i8(int64_t __arg0, float __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8r8i8(int64_t __arg0, double __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8sri8(int64_t __arg0, uint64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi8sri8i8(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vsr(uint64_t __arg0, const MethodInfo* method)
{
    StackObject args[1] = {*(uint64_t*)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


Native2ManagedMethodInfo hybridclr::interpreter::g_native2managedStub[] = 
{

	{"i1", (Il2CppMethodPointer)__N2M_i1},
	{"i16", (Il2CppMethodPointer)__N2M_i16},
	{"i16i16", (Il2CppMethodPointer)__N2M_i16i16},
	{"i16i16i8", (Il2CppMethodPointer)__N2M_i16i16i8},
	{"i16i8", (Il2CppMethodPointer)__N2M_i16i8},
	{"i16i8i16", (Il2CppMethodPointer)__N2M_i16i8i16},
	{"i16i8i16i8", (Il2CppMethodPointer)__N2M_i16i8i16i8},
	{"i16i8i8", (Il2CppMethodPointer)__N2M_i16i8i8},
	{"i16i8i8i8", (Il2CppMethodPointer)__N2M_i16i8i8i8},
	{"i16i8i8sr", (Il2CppMethodPointer)__N2M_i16i8i8sr},
	{"i16i8sr", (Il2CppMethodPointer)__N2M_i16i8sr},
	{"i1i8", (Il2CppMethodPointer)__N2M_i1i8},
	{"i1i8i1", (Il2CppMethodPointer)__N2M_i1i8i1},
	{"i1i8i16", (Il2CppMethodPointer)__N2M_i1i8i16},
	{"i1i8i16i16", (Il2CppMethodPointer)__N2M_i1i8i16i16},
	{"i1i8i16i4i4i4i8i8", (Il2CppMethodPointer)__N2M_i1i8i16i4i4i4i8i8},
	{"i1i8i16i8", (Il2CppMethodPointer)__N2M_i1i8i16i8},
	{"i1i8i2", (Il2CppMethodPointer)__N2M_i1i8i2},
	{"i1i8i2i2i4", (Il2CppMethodPointer)__N2M_i1i8i2i2i4},
	{"i1i8i2i4", (Il2CppMethodPointer)__N2M_i1i8i2i4},
	{"i1i8i4", (Il2CppMethodPointer)__N2M_i1i8i4},
	{"i1i8i4i1", (Il2CppMethodPointer)__N2M_i1i8i4i1},
	{"i1i8i4i4", (Il2CppMethodPointer)__N2M_i1i8i4i4},
	{"i1i8i4i4i4", (Il2CppMethodPointer)__N2M_i1i8i4i4i4},
	{"i1i8i4i4i4i4", (Il2CppMethodPointer)__N2M_i1i8i4i4i4i4},
	{"i1i8i4i8", (Il2CppMethodPointer)__N2M_i1i8i4i8},
	{"i1i8i4i8i8", (Il2CppMethodPointer)__N2M_i1i8i4i8i8},
	{"i1i8i8", (Il2CppMethodPointer)__N2M_i1i8i8},
	{"i1i8i8i1", (Il2CppMethodPointer)__N2M_i1i8i8i1},
	{"i1i8i8i4", (Il2CppMethodPointer)__N2M_i1i8i8i4},
	{"i1i8i8i4i4", (Il2CppMethodPointer)__N2M_i1i8i8i4i4},
	{"i1i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i4i4i8i8},
	{"i1i8i8i4i4i8i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i4i4i8i8i8},
	{"i1i8i8i4i8", (Il2CppMethodPointer)__N2M_i1i8i8i4i8},
	{"i1i8i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i8},
	{"i1i8i8i8i4", (Il2CppMethodPointer)__N2M_i1i8i8i8i4},
	{"i1i8i8i8i4i4i8i8i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i8i4i4i8i8i8i8},
	{"i1i8i8i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i8i8},
	{"i1i8i8i8i8i4", (Il2CppMethodPointer)__N2M_i1i8i8i8i8i4},
	{"i1i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i8i8i8},
	{"i1i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i1i8i8i8i8i8i8},
	{"i1i8r4", (Il2CppMethodPointer)__N2M_i1i8r4},
	{"i1i8r4r4", (Il2CppMethodPointer)__N2M_i1i8r4r4},
	{"i1i8r8", (Il2CppMethodPointer)__N2M_i1i8r8},
	{"i1i8sr", (Il2CppMethodPointer)__N2M_i1i8sr},
	{"i1i8vd2", (Il2CppMethodPointer)__N2M_i1i8vd2},
	{"i1i8vf2", (Il2CppMethodPointer)__N2M_i1i8vf2},
	{"i1i8vf3", (Il2CppMethodPointer)__N2M_i1i8vf3},
	{"i1i8vf4", (Il2CppMethodPointer)__N2M_i1i8vf4},
	{"i2", (Il2CppMethodPointer)__N2M_i2},
	{"i2i8", (Il2CppMethodPointer)__N2M_i2i8},
	{"i2i8i2", (Il2CppMethodPointer)__N2M_i2i8i2},
	{"i2i8i8", (Il2CppMethodPointer)__N2M_i2i8i8},
	{"i4", (Il2CppMethodPointer)__N2M_i4},
	{"i4i1", (Il2CppMethodPointer)__N2M_i4i1},
	{"i4i2", (Il2CppMethodPointer)__N2M_i4i2},
	{"i4i4", (Il2CppMethodPointer)__N2M_i4i4},
	{"i4i8", (Il2CppMethodPointer)__N2M_i4i8},
	{"i4i8i1", (Il2CppMethodPointer)__N2M_i4i8i1},
	{"i4i8i16", (Il2CppMethodPointer)__N2M_i4i8i16},
	{"i4i8i2", (Il2CppMethodPointer)__N2M_i4i8i2},
	{"i4i8i4", (Il2CppMethodPointer)__N2M_i4i8i4},
	{"i4i8i4i4", (Il2CppMethodPointer)__N2M_i4i8i4i4},
	{"i4i8i4i4i1", (Il2CppMethodPointer)__N2M_i4i8i4i4i1},
	{"i4i8i4i4i4", (Il2CppMethodPointer)__N2M_i4i8i4i4i4},
	{"i4i8i4i4i8i8", (Il2CppMethodPointer)__N2M_i4i8i4i4i8i8},
	{"i4i8i4i8i8", (Il2CppMethodPointer)__N2M_i4i8i4i8i8},
	{"i4i8i8", (Il2CppMethodPointer)__N2M_i4i8i8},
	{"i4i8i8i1i4", (Il2CppMethodPointer)__N2M_i4i8i8i1i4},
	{"i4i8i8i2", (Il2CppMethodPointer)__N2M_i4i8i8i2},
	{"i4i8i8i2i4", (Il2CppMethodPointer)__N2M_i4i8i8i2i4},
	{"i4i8i8i2i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i2i4i4},
	{"i4i8i8i2i4i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i2i4i4i4},
	{"i4i8i8i4", (Il2CppMethodPointer)__N2M_i4i8i8i4},
	{"i4i8i8i4i1", (Il2CppMethodPointer)__N2M_i4i8i8i4i1},
	{"i4i8i8i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i4i4},
	{"i4i8i8i4i4i1", (Il2CppMethodPointer)__N2M_i4i8i8i4i4i1},
	{"i4i8i8i4i4i8i4", (Il2CppMethodPointer)__N2M_i4i8i8i4i4i8i4},
	{"i4i8i8i4i4i8i4i1", (Il2CppMethodPointer)__N2M_i4i8i8i4i4i8i4i1},
	{"i4i8i8i4i4i8i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i4i4i8i4i4},
	{"i4i8i8i4i4i8i4i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i4i4i8i4i4i4},
	{"i4i8i8i4i8", (Il2CppMethodPointer)__N2M_i4i8i8i4i8},
	{"i4i8i8i4i8i4", (Il2CppMethodPointer)__N2M_i4i8i8i4i8i4},
	{"i4i8i8i4i8i4i1", (Il2CppMethodPointer)__N2M_i4i8i8i4i8i4i1},
	{"i4i8i8i4i8i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i4i8i4i4},
	{"i4i8i8i4i8i8", (Il2CppMethodPointer)__N2M_i4i8i8i4i8i8},
	{"i4i8i8i8", (Il2CppMethodPointer)__N2M_i4i8i8i8},
	{"i4i8i8i8i4", (Il2CppMethodPointer)__N2M_i4i8i8i8i4},
	{"i4i8i8i8i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i8i4i4},
	{"i4i8i8i8i4i4i4", (Il2CppMethodPointer)__N2M_i4i8i8i8i4i4i4},
	{"i4i8i8i8i4i8", (Il2CppMethodPointer)__N2M_i4i8i8i8i4i8},
	{"i4i8i8i8i8", (Il2CppMethodPointer)__N2M_i4i8i8i8i8},
	{"i4i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i4i8i8i8i8i8i8},
	{"i4i8i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i4i8i8i8i8i8i8i8},
	{"i4i8i8i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i4i8i8i8i8i8i8i8i8},
	{"i4i8r4", (Il2CppMethodPointer)__N2M_i4i8r4},
	{"i4i8r8", (Il2CppMethodPointer)__N2M_i4i8r8},
	{"i4i8sr", (Il2CppMethodPointer)__N2M_i4i8sr},
	{"i8", (Il2CppMethodPointer)__N2M_i8},
	{"i8i4i8i8i8", (Il2CppMethodPointer)__N2M_i8i4i8i8i8},
	{"i8i8", (Il2CppMethodPointer)__N2M_i8i8},
	{"i8i8i1", (Il2CppMethodPointer)__N2M_i8i8i1},
	{"i8i8i16", (Il2CppMethodPointer)__N2M_i8i8i16},
	{"i8i8i16i4i1i8", (Il2CppMethodPointer)__N2M_i8i8i16i4i1i8},
	{"i8i8i16i8", (Il2CppMethodPointer)__N2M_i8i8i16i8},
	{"i8i8i2", (Il2CppMethodPointer)__N2M_i8i8i2},
	{"i8i8i2i2", (Il2CppMethodPointer)__N2M_i8i8i2i2},
	{"i8i8i4", (Il2CppMethodPointer)__N2M_i8i8i4},
	{"i8i8i4i1", (Il2CppMethodPointer)__N2M_i8i8i4i1},
	{"i8i8i4i4", (Il2CppMethodPointer)__N2M_i8i8i4i4},
	{"i8i8i4i4i4i4", (Il2CppMethodPointer)__N2M_i8i8i4i4i4i4},
	{"i8i8i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i8i8i4i4i4i4i4i4i4},
	{"i8i8i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i8i8i4i4i4i4i4i4i4i4},
	{"i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i4i4i8i8},
	{"i8i8i4i8", (Il2CppMethodPointer)__N2M_i8i8i4i8},
	{"i8i8i4i8i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i4i8i4i8i8},
	{"i8i8i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i4i8i8},
	{"i8i8i4i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i4i8i8i8},
	{"i8i8i4i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i4i8i8i8i8},
	{"i8i8i4i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i4i8i8i8i8i8i8},
	{"i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8},
	{"i8i8i8i1", (Il2CppMethodPointer)__N2M_i8i8i8i1},
	{"i8i8i8i16i16i16", (Il2CppMethodPointer)__N2M_i8i8i8i16i16i16},
	{"i8i8i8i16i8", (Il2CppMethodPointer)__N2M_i8i8i8i16i8},
	{"i8i8i8i1i1", (Il2CppMethodPointer)__N2M_i8i8i8i1i1},
	{"i8i8i8i1i1i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i1i1i8i8},
	{"i8i8i8i1i4i1", (Il2CppMethodPointer)__N2M_i8i8i8i1i4i1},
	{"i8i8i8i1i4i1i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i1i4i1i8i8},
	{"i8i8i8i1i4i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i1i4i8i8i8i8},
	{"i8i8i8i1i8", (Il2CppMethodPointer)__N2M_i8i8i8i1i8},
	{"i8i8i8i1i8i8i8i8i4i8", (Il2CppMethodPointer)__N2M_i8i8i8i1i8i8i8i8i4i8},
	{"i8i8i8i4", (Il2CppMethodPointer)__N2M_i8i8i8i4},
	{"i8i8i8i4i1i4i4i4", (Il2CppMethodPointer)__N2M_i8i8i8i4i1i4i4i4},
	{"i8i8i8i4i1i4i4i4i16i16", (Il2CppMethodPointer)__N2M_i8i8i8i4i1i4i4i4i16i16},
	{"i8i8i8i4i4", (Il2CppMethodPointer)__N2M_i8i8i8i4i4},
	{"i8i8i8i4i4i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i4i8},
	{"i8i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i4i8i8},
	{"i8i8i8i4i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8},
	{"i8i8i8i4i8i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i4i8i8},
	{"i8i8i8i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i8},
	{"i8i8i8i4i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i8i8},
	{"i8i8i8i4i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i8i8i8},
	{"i8i8i8i4i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i8i8i8i8},
	{"i8i8i8i4i8i8i8i8i8i1", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i8i8i8i8i1},
	{"i8i8i8i4i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i4i8i8i8i8i8i8},
	{"i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8},
	{"i8i8i8i8i1", (Il2CppMethodPointer)__N2M_i8i8i8i8i1},
	{"i8i8i8i8i16i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i16i8},
	{"i8i8i8i8i1i4i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i1i4i8i8i8i8i8},
	{"i8i8i8i8i1i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i1i8i8},
	{"i8i8i8i8i4", (Il2CppMethodPointer)__N2M_i8i8i8i8i4},
	{"i8i8i8i8i4i1", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i1},
	{"i8i8i8i8i4i1i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i1i8i8},
	{"i8i8i8i8i4i4", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i4},
	{"i8i8i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i4i8i8},
	{"i8i8i8i8i4i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i8},
	{"i8i8i8i8i4i8i8i8i1", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i8i8i8i1},
	{"i8i8i8i8i4i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i4i8i8i8i8i8},
	{"i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i8},
	{"i8i8i8i8i8i1", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i1},
	{"i8i8i8i8i8i4i4", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i4i4},
	{"i8i8i8i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i4i4i8i8},
	{"i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i8},
	{"i8i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i8i8},
	{"i8i8i8i8i8i8i8i8i4i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i8i8i8i4i8},
	{"i8i8i8i8i8i8i8i8i8i4i8", (Il2CppMethodPointer)__N2M_i8i8i8i8i8i8i8i8i8i4i8},
	{"i8i8i8r8", (Il2CppMethodPointer)__N2M_i8i8i8r8},
	{"i8i8i8sri8i8i8", (Il2CppMethodPointer)__N2M_i8i8i8sri8i8i8},
	{"i8i8sr", (Il2CppMethodPointer)__N2M_i8i8sr},
	{"i8i8sri8i8i8", (Il2CppMethodPointer)__N2M_i8i8sri8i8i8},
	{"r4", (Il2CppMethodPointer)__N2M_r4},
	{"r4i8", (Il2CppMethodPointer)__N2M_r4i8},
	{"r4i8i8", (Il2CppMethodPointer)__N2M_r4i8i8},
	{"r4i8i8i8", (Il2CppMethodPointer)__N2M_r4i8i8i8},
	{"r4i8r4", (Il2CppMethodPointer)__N2M_r4i8r4},
	{"r4r4", (Il2CppMethodPointer)__N2M_r4r4},
	{"r8", (Il2CppMethodPointer)__N2M_r8},
	{"r8i8", (Il2CppMethodPointer)__N2M_r8i8},
	{"r8i8i8", (Il2CppMethodPointer)__N2M_r8i8i8},
	{"r8i8i8i8", (Il2CppMethodPointer)__N2M_r8i8i8i8},
	{"r8i8r8", (Il2CppMethodPointer)__N2M_r8i8r8},
	{"r8r8", (Il2CppMethodPointer)__N2M_r8r8},
	{"S120i8", (Il2CppMethodPointer)__N2M_S120i8},
	{"S120i8i1", (Il2CppMethodPointer)__N2M_S120i8i1},
	{"S20", (Il2CppMethodPointer)__N2M_S20},
	{"S20i8", (Il2CppMethodPointer)__N2M_S20i8},
	{"S20i8sr", (Il2CppMethodPointer)__N2M_S20i8sr},
	{"S20sr", (Il2CppMethodPointer)__N2M_S20sr},
	{"S24i8i1", (Il2CppMethodPointer)__N2M_S24i8i1},
	{"S32i8i4", (Il2CppMethodPointer)__N2M_S32i8i4},
	{"S32i8i8", (Il2CppMethodPointer)__N2M_S32i8i8},
	{"S64i8i1", (Il2CppMethodPointer)__N2M_S64i8i1},
	{"v", (Il2CppMethodPointer)__N2M_v},
	{"vd3", (Il2CppMethodPointer)__N2M_vd3},
	{"vd3i8", (Il2CppMethodPointer)__N2M_vd3i8},
	{"vd3i8vd3", (Il2CppMethodPointer)__N2M_vd3i8vd3},
	{"vd3vd3", (Il2CppMethodPointer)__N2M_vd3vd3},
	{"vd4", (Il2CppMethodPointer)__N2M_vd4},
	{"vd4i8", (Il2CppMethodPointer)__N2M_vd4i8},
	{"vd4i8vd4", (Il2CppMethodPointer)__N2M_vd4i8vd4},
	{"vd4vd4", (Il2CppMethodPointer)__N2M_vd4vd4},
	{"vf2i8", (Il2CppMethodPointer)__N2M_vf2i8},
	{"vf3", (Il2CppMethodPointer)__N2M_vf3},
	{"vf3i8", (Il2CppMethodPointer)__N2M_vf3i8},
	{"vf3i8vf3", (Il2CppMethodPointer)__N2M_vf3i8vf3},
	{"vf3vf3", (Il2CppMethodPointer)__N2M_vf3vf3},
	{"vf4", (Il2CppMethodPointer)__N2M_vf4},
	{"vf4i8", (Il2CppMethodPointer)__N2M_vf4i8},
	{"vf4i8vf4", (Il2CppMethodPointer)__N2M_vf4i8vf4},
	{"vf4vf4", (Il2CppMethodPointer)__N2M_vf4vf4},
	{"vi16", (Il2CppMethodPointer)__N2M_vi16},
	{"vi16i8", (Il2CppMethodPointer)__N2M_vi16i8},
	{"vi1i8", (Il2CppMethodPointer)__N2M_vi1i8},
	{"vi4", (Il2CppMethodPointer)__N2M_vi4},
	{"vi4i4", (Il2CppMethodPointer)__N2M_vi4i4},
	{"vi4i4i8", (Il2CppMethodPointer)__N2M_vi4i4i8},
	{"vi4i8", (Il2CppMethodPointer)__N2M_vi4i8},
	{"vi4i8vf3", (Il2CppMethodPointer)__N2M_vi4i8vf3},
	{"vi8", (Il2CppMethodPointer)__N2M_vi8},
	{"vi8i1", (Il2CppMethodPointer)__N2M_vi8i1},
	{"vi8i16", (Il2CppMethodPointer)__N2M_vi8i16},
	{"vi8i16i16", (Il2CppMethodPointer)__N2M_vi8i16i16},
	{"vi8i16i8", (Il2CppMethodPointer)__N2M_vi8i16i8},
	{"vi8i16i8i8", (Il2CppMethodPointer)__N2M_vi8i16i8i8},
	{"vi8i16sr", (Il2CppMethodPointer)__N2M_vi8i16sr},
	{"vi8i16sri8", (Il2CppMethodPointer)__N2M_vi8i16sri8},
	{"vi8i1i8", (Il2CppMethodPointer)__N2M_vi8i1i8},
	{"vi8i1i8i4", (Il2CppMethodPointer)__N2M_vi8i1i8i4},
	{"vi8i2", (Il2CppMethodPointer)__N2M_vi8i2},
	{"vi8i2i2", (Il2CppMethodPointer)__N2M_vi8i2i2},
	{"vi8i2i8", (Il2CppMethodPointer)__N2M_vi8i2i8},
	{"vi8i4", (Il2CppMethodPointer)__N2M_vi8i4},
	{"vi8i4i16", (Il2CppMethodPointer)__N2M_vi8i4i16},
	{"vi8i4i1i1", (Il2CppMethodPointer)__N2M_vi8i4i1i1},
	{"vi8i4i1i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i4i1i8i8i8i8},
	{"vi8i4i4", (Il2CppMethodPointer)__N2M_vi8i4i4},
	{"vi8i4i4i4", (Il2CppMethodPointer)__N2M_vi8i4i4i4},
	{"vi8i4i4i8", (Il2CppMethodPointer)__N2M_vi8i4i4i8},
	{"vi8i4i4i8i8", (Il2CppMethodPointer)__N2M_vi8i4i4i8i8},
	{"vi8i4i4i8i8i8", (Il2CppMethodPointer)__N2M_vi8i4i4i8i8i8},
	{"vi8i4i8", (Il2CppMethodPointer)__N2M_vi8i4i8},
	{"vi8i4i8i4i2i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i4i8i4i2i8i8i8i8},
	{"vi8i4i8i4i4", (Il2CppMethodPointer)__N2M_vi8i4i8i4i4},
	{"vi8i4i8i4i8", (Il2CppMethodPointer)__N2M_vi8i4i8i4i8},
	{"vi8i4i8i8", (Il2CppMethodPointer)__N2M_vi8i4i8i8},
	{"vi8i4i8i8i4i8", (Il2CppMethodPointer)__N2M_vi8i4i8i8i4i8},
	{"vi8i4i8i8i8", (Il2CppMethodPointer)__N2M_vi8i4i8i8i8},
	{"vi8i4i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i4i8i8i8i8},
	{"vi8i4i8vf3", (Il2CppMethodPointer)__N2M_vi8i4i8vf3},
	{"vi8i4sr", (Il2CppMethodPointer)__N2M_vi8i4sr},
	{"vi8i8", (Il2CppMethodPointer)__N2M_vi8i8},
	{"vi8i8i1", (Il2CppMethodPointer)__N2M_vi8i8i1},
	{"vi8i8i16", (Il2CppMethodPointer)__N2M_vi8i8i16},
	{"vi8i8i16i8", (Il2CppMethodPointer)__N2M_vi8i8i16i8},
	{"vi8i8i1i1", (Il2CppMethodPointer)__N2M_vi8i8i1i1},
	{"vi8i8i1i4i1", (Il2CppMethodPointer)__N2M_vi8i8i1i4i1},
	{"vi8i8i1i8", (Il2CppMethodPointer)__N2M_vi8i8i1i8},
	{"vi8i8i1i8i1", (Il2CppMethodPointer)__N2M_vi8i8i1i8i1},
	{"vi8i8i2", (Il2CppMethodPointer)__N2M_vi8i8i2},
	{"vi8i8i4", (Il2CppMethodPointer)__N2M_vi8i8i4},
	{"vi8i8i4i1i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i1i8i8i8i8},
	{"vi8i8i4i2i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i2i8i8i8},
	{"vi8i8i4i2i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i2i8i8i8i8},
	{"vi8i8i4i4", (Il2CppMethodPointer)__N2M_vi8i8i4i4},
	{"vi8i8i4i4i4i4", (Il2CppMethodPointer)__N2M_vi8i8i4i4i4i4},
	{"vi8i8i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi8i8i4i4i4i4i4i4},
	{"vi8i8i4i4i8", (Il2CppMethodPointer)__N2M_vi8i8i4i4i8},
	{"vi8i8i4i4i8i4", (Il2CppMethodPointer)__N2M_vi8i8i4i4i8i4},
	{"vi8i8i4i4i8i4i4", (Il2CppMethodPointer)__N2M_vi8i8i4i4i8i4i4},
	{"vi8i8i4i4i8i4i4i1i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i4i8i4i4i1i8i8i8},
	{"vi8i8i4i8", (Il2CppMethodPointer)__N2M_vi8i8i4i8},
	{"vi8i8i4i8i4i1i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i8i4i1i8i8i8},
	{"vi8i8i4i8i4i4i4i4", (Il2CppMethodPointer)__N2M_vi8i8i4i8i4i4i4i4},
	{"vi8i8i4i8i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi8i8i4i8i4i4i4i4i4i4},
	{"vi8i8i4i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i8i8},
	{"vi8i8i4i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i4i8i8i8},
	{"vi8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8},
	{"vi8i8i8i1", (Il2CppMethodPointer)__N2M_vi8i8i8i1},
	{"vi8i8i8i16", (Il2CppMethodPointer)__N2M_vi8i8i8i16},
	{"vi8i8i8i1i1", (Il2CppMethodPointer)__N2M_vi8i8i8i1i1},
	{"vi8i8i8i4", (Il2CppMethodPointer)__N2M_vi8i8i8i4},
	{"vi8i8i8i4i1", (Il2CppMethodPointer)__N2M_vi8i8i8i4i1},
	{"vi8i8i8i4i4", (Il2CppMethodPointer)__N2M_vi8i8i8i4i4},
	{"vi8i8i8i4i4i8", (Il2CppMethodPointer)__N2M_vi8i8i8i4i4i8},
	{"vi8i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i4i4i8i8},
	{"vi8i8i8i4i8i16", (Il2CppMethodPointer)__N2M_vi8i8i8i4i8i16},
	{"vi8i8i8i4i8i4i4i4i4", (Il2CppMethodPointer)__N2M_vi8i8i8i4i8i4i4i4i4},
	{"vi8i8i8i4i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i4i8i8},
	{"vi8i8i8i4i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i4i8i8i8},
	{"vi8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i8},
	{"vi8i8i8i8i4i4", (Il2CppMethodPointer)__N2M_vi8i8i8i8i4i4},
	{"vi8i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i8i8},
	{"vi8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i8i8i8i8i8i8},
	{"vi8i8i8i8i8i8i8i8i8i8", (Il2CppMethodPointer)__N2M_vi8i8i8i8i8i8i8i8i8i8},
	{"vi8i8r4", (Il2CppMethodPointer)__N2M_vi8i8r4},
	{"vi8i8r8", (Il2CppMethodPointer)__N2M_vi8i8r8},
	{"vi8i8sr", (Il2CppMethodPointer)__N2M_vi8i8sr},
	{"vi8r4", (Il2CppMethodPointer)__N2M_vi8r4},
	{"vi8r4i8", (Il2CppMethodPointer)__N2M_vi8r4i8},
	{"vi8r8", (Il2CppMethodPointer)__N2M_vi8r8},
	{"vi8r8i8", (Il2CppMethodPointer)__N2M_vi8r8i8},
	{"vi8sr", (Il2CppMethodPointer)__N2M_vi8sr},
	{"vi8sri8", (Il2CppMethodPointer)__N2M_vi8sri8},
	{"vi8sri8i8", (Il2CppMethodPointer)__N2M_vi8sri8i8},
	{"vsr", (Il2CppMethodPointer)__N2M_vsr},
	{nullptr, nullptr},
};

static ValueTypeSize16 __N2M_AdjustorThunk_i16i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_AdjustorThunk_i16i8i16i16(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_AdjustorThunk_i16i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_AdjustorThunk_i16i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static ValueTypeSize16 __N2M_AdjustorThunk_i16i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize16*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i4i4i4vf3i4r4i8i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, HtVector3f __arg4, int32_t __arg5, float __arg6, int64_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method)
{
    StackObject args[11] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = args + 10;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i4i4r4i8i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i4i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8sri8(int64_t __arg0, uint64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vd2(int64_t __arg0, HtVector2d __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vf2(int64_t __arg0, HtVector2f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vf3(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vf3i1(int64_t __arg0, HtVector3f __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vf3vf3(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vf4(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i8vf4i1(int64_t __arg0, HtVector4f __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int16_t __N2M_AdjustorThunk_i2i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i8i4i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8i8i4i4i8i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int64_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i2i8(int64_t __arg0, int16_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i4i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i8S12(int64_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static float __N2M_AdjustorThunk_r4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_AdjustorThunk_r4i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_AdjustorThunk_r4i8i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_AdjustorThunk_r4i8vf3(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static double __N2M_AdjustorThunk_r8i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i8S12(int64_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i8S12S12(int64_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<188> __N2M_AdjustorThunk_S188i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[25] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<188>*)ret;
}


static ValueTypeSize<224> __N2M_AdjustorThunk_S224i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[29] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<224>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8i4i4i4sri4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8i8i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8i8i8i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8sri1(int64_t __arg0, uint64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8sri1i1(int64_t __arg0, uint64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8srsri1(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i8srsri1i1(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<28> __N2M_AdjustorThunk_S28i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<28>*)ret;
}


static ValueTypeSize<28> __N2M_AdjustorThunk_S28i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<28>*)ret;
}


static ValueTypeSize<28> __N2M_AdjustorThunk_S28i8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<28>*)ret;
}


static ValueTypeSize<32> __N2M_AdjustorThunk_S32i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<32>*)ret;
}


static ValueTypeSize<32> __N2M_AdjustorThunk_S32i8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<32>*)ret;
}


static ValueTypeSize<36> __N2M_AdjustorThunk_S36i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<36>*)ret;
}


static ValueTypeSize<40> __N2M_AdjustorThunk_S40i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<40>*)ret;
}


static ValueTypeSize<48> __N2M_AdjustorThunk_S48i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<48>*)ret;
}


static ValueTypeSize<56> __N2M_AdjustorThunk_S56i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<56>*)ret;
}


static ValueTypeSize<56> __N2M_AdjustorThunk_S56i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<56>*)ret;
}


static ValueTypeSize<64> __N2M_AdjustorThunk_S64i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<64>*)ret;
}


static ValueTypeSize<68> __N2M_AdjustorThunk_S68i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[10] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<68>*)ret;
}


static ValueTypeSize<992> __N2M_AdjustorThunk_S992i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[125] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<992>*)ret;
}


static HtVector2f __N2M_AdjustorThunk_vf2i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector2f*)ret;
}


static HtVector2f __N2M_AdjustorThunk_vf2i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector2f*)ret;
}


static HtVector3f __N2M_AdjustorThunk_vf3i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector3f __N2M_AdjustorThunk_vf3i8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector3f __N2M_AdjustorThunk_vf3i8vf3(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector3f*)ret;
}


static HtVector4f __N2M_AdjustorThunk_vf4i8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static HtVector4f __N2M_AdjustorThunk_vf4i8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static HtVector4f __N2M_AdjustorThunk_vf4i8vf4(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(HtVector4f*)ret;
}


static void __N2M_AdjustorThunk_vi8(int64_t __arg0, const MethodInfo* method)
{
    StackObject args[1] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i1(int64_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i16(int64_t __arg0, ValueTypeSize16 __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i16i16(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i16i16i4(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i16i16i4i4(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i16i16i4i4i4(int64_t __arg0, ValueTypeSize16 __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i16i4i4i4(int64_t __arg0, ValueTypeSize16 __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i1i1(int64_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i1i1i1i1(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i1i1i1i4i4i4i4(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i1i1i1i4i4i4i4i4i4i4i4(int64_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method)
{
    StackObject args[12] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10, *(uint64_t*)&__arg11 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i1i4(int64_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i2(int64_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i2i2(int64_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i2i4i1i1i1(int64_t __arg0, int16_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4(int64_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i1(int64_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i1i1i1i1i4i8(int64_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i2i2i1i1i1i1i1i1i1i1(int64_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int8_t __arg7, int8_t __arg8, int8_t __arg9, int8_t __arg10, int8_t __arg11, const MethodInfo* method)
{
    StackObject args[12] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10, *(uint64_t*)&__arg11 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i2i2i8(int64_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i1i1(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i8i4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[10] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i8i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int64_t __arg8, int64_t __arg9, const MethodInfo* method)
{
    StackObject args[10] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i4i4i4i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i4sri4(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4i8(int64_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4r4(int64_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i4r4i1(int64_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4i8i8i8i8i8(int64_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4r4(int64_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4sr(int64_t __arg0, int32_t __arg1, uint64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4sri1i1i1(int64_t __arg0, int32_t __arg1, uint64_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4sri4(int64_t __arg0, int32_t __arg1, uint64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i4vf4(int64_t __arg0, int32_t __arg1, HtVector4f __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8(int64_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i1(int64_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i16(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i16i4(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i16i4i4(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i16i4i4i8i8i4i4(int64_t __arg0, int64_t __arg1, ValueTypeSize16 __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i1i4(int64_t __arg0, int64_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i4i1(int64_t __arg0, int64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i4i4i4(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i4i8(int64_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i1(int64_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i16i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, ValueTypeSize16 __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, (uint64_t)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i4i4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i8i8i8i8i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i8i8i8i8i4i8(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8i8i8sri4i4(int64_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8r8(int64_t __arg0, int64_t __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8i8sr(int64_t __arg0, int64_t __arg1, uint64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4(int64_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4i8(int64_t __arg0, float __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4r4(int64_t __arg0, float __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4r4r4(int64_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4r4r4r4(int64_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4r4r4r4r4r4(int64_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4(int64_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, float __arg7, float __arg8, float __arg9, float __arg10, float __arg11, float __arg12, float __arg13, float __arg14, float __arg15, float __arg16, const MethodInfo* method)
{
    StackObject args[17] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10, *(uint64_t*)&__arg11, *(uint64_t*)&__arg12, *(uint64_t*)&__arg13, *(uint64_t*)&__arg14, *(uint64_t*)&__arg15, *(uint64_t*)&__arg16 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r8(int64_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8r8r8(int64_t __arg0, double __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sr(int64_t __arg0, uint64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri1(int64_t __arg0, uint64_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri1i1(int64_t __arg0, uint64_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri4(int64_t __arg0, uint64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri4i1(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri4i4i4(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri4i4sri4i4(int64_t __arg0, uint64_t __arg1, int32_t __arg2, int32_t __arg3, uint64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri8i8(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri8i8i8(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri8i8i8i1srsr(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int8_t __arg5, uint64_t __arg6, uint64_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8sri8i8srsr(int64_t __arg0, uint64_t __arg1, int64_t __arg2, int64_t __arg3, uint64_t __arg4, uint64_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8srsri1(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8srsri1i1(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8srsrsrsr(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, uint64_t __arg3, uint64_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8srsrsrsrsrr4(int64_t __arg0, uint64_t __arg1, uint64_t __arg2, uint64_t __arg3, uint64_t __arg4, uint64_t __arg5, float __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8srvf4(int64_t __arg0, uint64_t __arg1, HtVector4f __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf2(int64_t __arg0, HtVector2f __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf2r4(int64_t __arg0, HtVector2f __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf2r4r4(int64_t __arg0, HtVector2f __arg1, float __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf2vf2(int64_t __arg0, HtVector2f __arg1, HtVector2f __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3(int64_t __arg0, HtVector3f __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3r4(int64_t __arg0, HtVector3f __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3vf3(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3vf3vf3(int64_t __arg0, HtVector3f __arg1, HtVector3f __arg2, HtVector3f __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3vf4(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3vf4r4(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf3vf4vf3(int64_t __arg0, HtVector3f __arg1, HtVector4f __arg2, HtVector3f __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf4(int64_t __arg0, HtVector4f __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf4r4(int64_t __arg0, HtVector4f __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf4r4i4(int64_t __arg0, HtVector4f __arg1, float __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi8vf4vf4vf4vf4(int64_t __arg0, HtVector4f __arg1, HtVector4f __arg2, HtVector4f __arg3, HtVector4f __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3, (uint64_t)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


NativeAdjustThunkMethodInfo hybridclr::interpreter::g_adjustThunkStub[] = 
{

	{"i16i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i16i8},
	{"i16i8i16i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i16i8i16i16},
	{"i16i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i16i8i4},
	{"i16i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i16i8i8},
	{"i16i8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i16i8r8},
	{"i1i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8},
	{"i1i8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i1},
	{"i1i8i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i16},
	{"i1i8i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i2},
	{"i1i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i4},
	{"i1i8i4i4i4vf3i4r4i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i4i4i4vf3i4r4i8i8i8},
	{"i1i8i4i4r4i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i4i4r4i8i8i8},
	{"i1i8i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i4i8},
	{"i1i8i4i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i4i8i8i8},
	{"i1i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i8},
	{"i1i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8i8i8},
	{"i1i8r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8r4},
	{"i1i8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8r8},
	{"i1i8sr", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8sr},
	{"i1i8sri8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8sri8},
	{"i1i8vd2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vd2},
	{"i1i8vf2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vf2},
	{"i1i8vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vf3},
	{"i1i8vf3i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vf3i1},
	{"i1i8vf3vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vf3vf3},
	{"i1i8vf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vf4},
	{"i1i8vf4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i8vf4i1},
	{"i2i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i2i8},
	{"i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8},
	{"i4i8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i1},
	{"i4i8i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i16},
	{"i4i8i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i2},
	{"i4i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i4},
	{"i4i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i8},
	{"i4i8i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i8i4},
	{"i4i8i8i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i8i4i1},
	{"i4i8i8i4i4i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8i8i4i4i8i8},
	{"i4i8r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8r4},
	{"i4i8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i8r8},
	{"i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8},
	{"i8i8i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i16},
	{"i8i8i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i2},
	{"i8i8i2i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i2i8},
	{"i8i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i4},
	{"i8i8i4i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i4i8i8},
	{"i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i8},
	{"i8i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8i8i8},
	{"i8i8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8r8},
	{"i8i8S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i8S12},
	{"r4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i8},
	{"r4i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i8i4},
	{"r4i8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i8i4i4},
	{"r4i8vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i8vf3},
	{"r8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_r8i8},
	{"S12i8S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i8S12},
	{"S12i8S12S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i8S12S12},
	{"S188i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S188i8},
	{"S224i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S224i8},
	{"S24i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8},
	{"S24i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8i4},
	{"S24i8i4i4i4sri4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8i4i4i4sri4},
	{"S24i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8i8},
	{"S24i8i8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8i8i1},
	{"S24i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8i8i8},
	{"S24i8i8i8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8i8i8i1},
	{"S24i8sri1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8sri1},
	{"S24i8sri1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8sri1i1},
	{"S24i8srsri1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8srsri1},
	{"S24i8srsri1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i8srsri1i1},
	{"S28i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S28i8},
	{"S28i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S28i8i8},
	{"S28i8sr", (Il2CppMethodPointer)__N2M_AdjustorThunk_S28i8sr},
	{"S32i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S32i8},
	{"S32i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S32i8i8},
	{"S36i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S36i8},
	{"S40i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S40i8},
	{"S48i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S48i8i4},
	{"S56i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S56i8},
	{"S56i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S56i8i4},
	{"S64i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S64i8},
	{"S68i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S68i8},
	{"S992i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_S992i8},
	{"vf2i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf2i8},
	{"vf2i8r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf2i8r4},
	{"vf3i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf3i8},
	{"vf3i8r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf3i8r4},
	{"vf3i8vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf3i8vf3},
	{"vf4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf4i8},
	{"vf4i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf4i8i4},
	{"vf4i8vf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vf4i8vf4},
	{"vi8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8},
	{"vi8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i1},
	{"vi8i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i16},
	{"vi8i16i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i16i16},
	{"vi8i16i16i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i16i16i4},
	{"vi8i16i16i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i16i16i4i4},
	{"vi8i16i16i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i16i16i4i4i4},
	{"vi8i16i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i16i4i4i4},
	{"vi8i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i1i1},
	{"vi8i1i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i1i1i1i1},
	{"vi8i1i1i1i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i1i1i1i4i4i4i4},
	{"vi8i1i1i1i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i1i1i1i4i4i4i4i4i4i4i4},
	{"vi8i1i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i1i4},
	{"vi8i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i2},
	{"vi8i2i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i2i2},
	{"vi8i2i4i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i2i4i1i1i1},
	{"vi8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4},
	{"vi8i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i1},
	{"vi8i4i1i1i1i1i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i1i1i1i1i4i8},
	{"vi8i4i2i2i1i1i1i1i1i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i2i2i1i1i1i1i1i1i1i1},
	{"vi8i4i2i2i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i2i2i8},
	{"vi8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4},
	{"vi8i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4},
	{"vi8i4i4i4i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i1i1},
	{"vi8i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4},
	{"vi8i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i4},
	{"vi8i4i4i4i4i4i4i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i8},
	{"vi8i4i4i4i4i4i4i4i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i8i4},
	{"vi8i4i4i4i4i4i4i4i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4i4i8i8},
	{"vi8i4i4i4i4i4i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i4i4i4i8},
	{"vi8i4i4i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4i8},
	{"vi8i4i4i4sri4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i4sri4},
	{"vi8i4i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4i8},
	{"vi8i4i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4r4},
	{"vi8i4i4r4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i4r4i1},
	{"vi8i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i8},
	{"vi8i4i8i8i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4i8i8i8i8i8},
	{"vi8i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4r4},
	{"vi8i4sr", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4sr},
	{"vi8i4sri1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4sri1i1i1},
	{"vi8i4sri4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4sri4},
	{"vi8i4vf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i4vf4},
	{"vi8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8},
	{"vi8i8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i1},
	{"vi8i8i16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i16},
	{"vi8i8i16i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i16i4},
	{"vi8i8i16i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i16i4i4},
	{"vi8i8i16i4i4i8i8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i16i4i4i8i8i4i4},
	{"vi8i8i1i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i1i4},
	{"vi8i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i4},
	{"vi8i8i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i4i1},
	{"vi8i8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i4i4},
	{"vi8i8i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i4i4i4},
	{"vi8i8i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i4i8},
	{"vi8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8},
	{"vi8i8i8i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i1},
	{"vi8i8i8i16i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i16i4},
	{"vi8i8i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i4},
	{"vi8i8i8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i4i4},
	{"vi8i8i8i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i4i4i4},
	{"vi8i8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i8},
	{"vi8i8i8i8i8i8i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i8i8i8i8i4},
	{"vi8i8i8i8i8i8i8i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i8i8i8i8i4i8},
	{"vi8i8i8i8sri4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8i8i8sri4i4},
	{"vi8i8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8r8},
	{"vi8i8sr", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8i8sr},
	{"vi8r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4},
	{"vi8r4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4i8},
	{"vi8r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4r4},
	{"vi8r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4r4r4},
	{"vi8r4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4r4r4r4},
	{"vi8r4r4r4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4r4r4r4r4r4},
	{"vi8r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4},
	{"vi8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r8},
	{"vi8r8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8r8r8},
	{"vi8sr", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sr},
	{"vi8sri1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri1},
	{"vi8sri1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri1i1},
	{"vi8sri4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri4},
	{"vi8sri4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri4i1},
	{"vi8sri4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri4i4i4},
	{"vi8sri4i4sri4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri4i4sri4i4},
	{"vi8sri8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri8i8},
	{"vi8sri8i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri8i8i8},
	{"vi8sri8i8i8i1srsr", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri8i8i8i1srsr},
	{"vi8sri8i8srsr", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8sri8i8srsr},
	{"vi8srsri1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8srsri1},
	{"vi8srsri1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8srsri1i1},
	{"vi8srsrsrsr", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8srsrsrsr},
	{"vi8srsrsrsrsrr4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8srsrsrsrsrr4},
	{"vi8srvf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8srvf4},
	{"vi8vf2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf2},
	{"vi8vf2r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf2r4},
	{"vi8vf2r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf2r4r4},
	{"vi8vf2vf2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf2vf2},
	{"vi8vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3},
	{"vi8vf3r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3r4},
	{"vi8vf3vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3vf3},
	{"vi8vf3vf3vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3vf3vf3},
	{"vi8vf3vf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3vf4},
	{"vi8vf3vf4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3vf4r4},
	{"vi8vf3vf4vf3", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf3vf4vf3},
	{"vi8vf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf4},
	{"vi8vf4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf4r4},
	{"vi8vf4r4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf4r4i4},
	{"vi8vf4vf4vf4vf4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi8vf4vf4vf4vf4},
	{nullptr, nullptr},
};

//!!!}}INVOKE_STUB
#endif
