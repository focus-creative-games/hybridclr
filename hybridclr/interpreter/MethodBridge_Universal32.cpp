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

#if HYBRIDCLR_ABI_UNIVERSAL_32
//!!!{{INVOKE_STUB

static void __M2N_C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_C16C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16C16C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16C16C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16C16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16C16r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, double __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16i4C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int32_t __arg0, double __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(double __arg0, double __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C16S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<16> (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_C24C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(ValueTypeSizeAlign8<24> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C24C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C24C8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C24i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C24i4C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C24i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C24i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C24i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C24i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C24i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<24> (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<32> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSizeAlign8<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_C32C32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<32> (*NativeMethod)(ValueTypeSizeAlign8<32> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<32>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C32i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<32> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C32i4C32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<32> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<32> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<32>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C64i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<64> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_C8C16C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8i4C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8i4C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C8i4C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C8i4C8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, double __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_C8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C8i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_C8i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_C8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int32_t __arg0, double __arg1, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_C8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_C8S2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSize<2> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<2>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_C8S4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSizeAlign8<8> (*NativeMethod)(ValueTypeSize<4> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSizeAlign8<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i1C1568C1568(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<1568> __arg0, ValueTypeSizeAlign8<1568> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<1568>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<1568>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1C16C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1C24C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<24> __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1C64C64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<64> __arg0, ValueTypeSizeAlign8<64> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int8_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
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


static void __M2N_i1i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int16_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int16_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1i4C1568(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<1568> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<1568>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4C64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<64> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4C8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4C8S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i4i2i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4i4C8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int8_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSizeAlign8<8> __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i1i4i4i4i4i4i4i4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, ValueTypeSize<16> __arg8, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i1i4i4i4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, ValueTypeSize<4> __arg5, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i1i4i4i4i4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, ValueTypeSize<4> __arg5, int32_t __arg6, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i1i4i4i4i4S12i4r4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<12> __arg4, int32_t __arg5, float __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i1i4i4i4r4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i1i4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i4S88(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<88> __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<88>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4i4S88i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<88> __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<88>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, double __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4r8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, double __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<1>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<108> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<108>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S116(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<116> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<116>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S12i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S136(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<136> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<136>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int8_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1i4S16i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i1i4S188(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<188> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<188>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S216(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<216> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<216>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S224(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<224> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<224>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S24i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<24> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S312(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<312> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<312>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<32>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S68(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<68> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<68>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S88(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<88> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<88>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1i4S92(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<92> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<92>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1i4S992(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<992> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<992>*)(localVarBase+argVarIndexs[1]), method);
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


static void __M2N_i1i8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(int64_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
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


static void __M2N_i1S108S108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<108> __arg0, ValueTypeSize<108> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<108>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<108>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S116S116(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<116> __arg0, ValueTypeSize<116> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<116>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<116>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1S12i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<12> __arg0, int16_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S12i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1S12i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<12> __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S136S136(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<136> __arg0, ValueTypeSize<136> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<136>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<136>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1S16i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1S16i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S16i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i1S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i1S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S188S188(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<188> __arg0, ValueTypeSize<188> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<188>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<188>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<20> __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<20>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1S20S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<20> __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<20>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S216S216(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<216> __arg0, ValueTypeSize<216> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<216>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<216>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S224S224(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<224> __arg0, ValueTypeSize<224> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<224>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<224>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S24i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<24> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S24S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<24> __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S28S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<28> __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<28>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S2S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<2> __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<2>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S312S312(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<312> __arg0, ValueTypeSize<312> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<312>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<312>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S32S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<32> __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<32>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<32>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<4> __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<4> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<4> __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S64i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<64> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S64i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<64> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i1S64S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<64> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S68S68(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<68> __arg0, ValueTypeSize<68> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<68>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<68>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i1S8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<8> __arg0, int64_t __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S92S92(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<92> __arg0, ValueTypeSize<92> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<92>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<92>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i1S992S992(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int8_t (*NativeMethod)(ValueTypeSize<992> __arg0, ValueTypeSize<992> __arg1, const MethodInfo* method);
    *(int8_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<992>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<992>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i2C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int16_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i2i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i2i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_i2S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(ValueTypeSize<2> __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<2>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i2S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int16_t (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(int16_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i4C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4C16C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4C16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4C8C8C8C24C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, ValueTypeSizeAlign8<24> __arg3, ValueTypeSizeAlign8<24> __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4C8C8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4C8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4C8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4C8S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int8_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int8_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
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


static void __M2N_i4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int16_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i4C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4C8C8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4C8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4C8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4C8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4C8i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4C8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4C8S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i1i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i2i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i1i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i1i1i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4i4i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i1i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i1i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4i4i1i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i4i4i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4i2i2i1i1i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int16_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int16_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4i4i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSizeAlign8<8> __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i4C8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSizeAlign8<8> __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4C8S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSizeAlign8<8> __arg3, ValueTypeSize<12> __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i1i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i4i4i4i4i1i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i4i4i4i4i1i4i4i4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, ValueTypeSize<16> __arg8, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i4i4i4i4i2i2i1i1i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int16_t __arg3, int16_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, int16_t __arg8, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int16_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSizeAlign8<8> __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i4C8i1S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSizeAlign8<8> __arg4, int8_t __arg5, ValueTypeSize<12> __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i4i4i1i1S24i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int8_t __arg7, ValueTypeSize<24> __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_i4i4i4i4i4i4i4i1i1S24i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int8_t __arg7, ValueTypeSize<24> __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, int64_t __arg12, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int64_t*)(localVarBase+argVarIndexs[12]), method);
}


static void __M2N_i4i4i4i4i4i4i4i1i1S24i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int8_t __arg7, ValueTypeSize<24> __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, int64_t __arg12, int32_t __arg13, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int64_t*)(localVarBase+argVarIndexs[12]), *(int32_t*)(localVarBase+argVarIndexs[13]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_i4i4i4i4i4i4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, int32_t __arg12, int32_t __arg13, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int32_t*)(localVarBase+argVarIndexs[12]), *(int32_t*)(localVarBase+argVarIndexs[13]), method);
}


static void __M2N_i4i4i4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<4> __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<4> __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i4r8i4i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, double __arg3, int32_t __arg4, int32_t __arg5, double __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(double*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(double*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4i4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<20> __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4i4S4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4i8i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4i8i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, double __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4S16S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<16> __arg3, ValueTypeSize<16> __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<20> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<32> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<32>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i4S4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i4S4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4i8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, double __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4r8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, double __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, double __arg1, double __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<1>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S12i4i1S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int8_t __arg3, ValueTypeSize<4> __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4S12i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S12S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4S12S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4S16i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S16S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<16> __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4S16S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S16S8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, float __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i4S16S8r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4i4S16S8r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, float __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4S16S8r4i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, float __arg3, int32_t __arg4, int32_t __arg5, ValueTypeSize<16> __arg6, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_i4i4S16S8r4i4i4S16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, float __arg3, int32_t __arg4, int32_t __arg5, ValueTypeSize<16> __arg6, int8_t __arg7, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_i4i4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S20i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<32>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i4S8S12i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<12> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i4S8S12i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<12> __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(float __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(float __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4r8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(double __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4r8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(double __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<1> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S12i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, int8_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S12i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4S12i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S12i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int8_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S16i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4S16i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int16_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4S16i4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4S16i4i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i4S16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_i4S16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<4> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S48(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<48> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<48>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<4> __arg0, int32_t __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<4> __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S52(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<52> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<52>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S60(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<60> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<60>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S60S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<60> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<60>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S60S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<60> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<60>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<64> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i4S8S12i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4S8S12i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<12> __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_i4S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int32_t (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(int32_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_i8C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_i8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
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


static void __M2N_i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<1> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<20> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<20>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<36> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<36>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<4> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S5(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<5> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<5>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_i8S9(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef int64_t (*NativeMethod)(ValueTypeSize<9> __arg0, const MethodInfo* method);
    *(int64_t*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<9>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_r4C64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSizeAlign8<64> __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4C64C64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSizeAlign8<64> __arg0, ValueTypeSizeAlign8<64> __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i4i4S88(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<88> __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<88>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_r4r4r4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, int32_t __arg2, float __arg3, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r4r4r4i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, int32_t __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r4r4r4i4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, int32_t __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r4r4r4r4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4r4r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r4r4r4r4r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4S16r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r4S16r4r4r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4S16r4r4r4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_r4S16r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r4S16r4r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, float __arg2, float __arg3, float __arg4, int32_t __arg5, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_r4S16r4r4r4r4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, float __arg2, float __arg3, float __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_r4S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<64> __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r4S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef float (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(float*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_r8C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSizeAlign8<24> __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_r8i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_r8i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_r8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, double __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_r8i4r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int32_t __arg0, double __arg1, double __arg2, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_r8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
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


static void __M2N_r8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_r8S8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef double (*NativeMethod)(ValueTypeSize<8> __arg0, double __arg1, const MethodInfo* method);
    *(double*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<1> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<1>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S108r4S108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(float __arg0, ValueTypeSize<108> __arg1, const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<108>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S108S108r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(ValueTypeSize<108> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<108>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S108S108S108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<108> (*NativeMethod)(ValueTypeSize<108> __arg0, ValueTypeSize<108> __arg1, const MethodInfo* method);
    *(ValueTypeSize<108>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<108>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<108>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S12i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S12i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S12i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S12i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12i4S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12i4S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12r4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(float __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S12S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S12S12i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, int8_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12S12S12i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S12S12S12i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S12S12S12i4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S12S12S12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12S12S12r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S12S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S12S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S12S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S12S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S12S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<12> (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<12>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S16C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S16i4i4i4i4S36i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<36> __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S16i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16i4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16i4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16i4r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S16i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16i4S16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S16i4S16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S16i4S36i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16i4S36i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16i4S36S36i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16i4S36S36i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S16i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16r4r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16r4r4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, int8_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S16r4r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S16r4r4r4r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S16r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S16r4r4r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, float __arg7, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_S16r4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16r4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(float __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16S12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<12> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S12S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S16S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<16> __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16S16S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S16S16S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<4> __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<64> __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16S64S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<64> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S16S8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S16S8S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<16> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<16>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S188i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<188> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<188>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<1> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<1>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<1> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<1>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S1i4S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<1> (*NativeMethod)(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method);
    *(ValueTypeSize<1>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<1>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S1S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<1> (*NativeMethod)(ValueTypeSize<1> __arg0, const MethodInfo* method);
    *(ValueTypeSize<1>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<2> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<2>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S20i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S20i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S20i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S20i4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S20S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<20> (*NativeMethod)(ValueTypeSize<20> __arg0, const MethodInfo* method);
    *(ValueTypeSize<20>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<20>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S224i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<224> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<224>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S24C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24i4S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24i4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
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


static void __M2N_S24r4r4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(float __arg0, float __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24r4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(float __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSize<24> __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24S24r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSize<24> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24S24S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSize<24> __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S24S24S24r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSize<24> __arg0, ValueTypeSize<24> __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S24S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S24S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<24> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<24>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S28i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S28i4S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S28S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<28> (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<28>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<2> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<2>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<2> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<2>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S2i4S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<2> (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method);
    *(ValueTypeSize<2>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S2S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<2> (*NativeMethod)(ValueTypeSize<2> __arg0, const MethodInfo* method);
    *(ValueTypeSize<2>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<2>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<3> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<3>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S32i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S32i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S32i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<32> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<32>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S36i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<36> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<36>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S36i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<36> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<36>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S36i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<36> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<36>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S3i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<3> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<3>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S3i4S3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<3> (*NativeMethod)(int32_t __arg0, ValueTypeSize<3> __arg1, const MethodInfo* method);
    *(ValueTypeSize<3>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<3>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S3S3(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<3> (*NativeMethod)(ValueTypeSize<3> __arg0, const MethodInfo* method);
    *(ValueTypeSize<3>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<3>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S48(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<48> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<48>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S48i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<48> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<48>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S48i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<48> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<48>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S4i2S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int16_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S4i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(ValueTypeSize<4> __arg0, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S4S4S4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<4> (*NativeMethod)(ValueTypeSize<4> __arg0, ValueTypeSize<4> __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<4>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S5(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<5> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<5>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S52i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<52> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<52>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S5i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<5> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<5>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S5i4S5(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<5> (*NativeMethod)(int32_t __arg0, ValueTypeSize<5> __arg1, const MethodInfo* method);
    *(ValueTypeSize<5>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<5>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S5S5(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<5> (*NativeMethod)(ValueTypeSize<5> __arg0, const MethodInfo* method);
    *(ValueTypeSize<5>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<5>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S60i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<60> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<60>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S60i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<60> (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<60>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
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


static void __M2N_S64i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
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


static void __M2N_S64r4r4r4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, float __arg1, float __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S64r4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(float __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64S12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64S12S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S64S12S12S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, ValueTypeSize<12> __arg3, ValueTypeSize<12> __arg4, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S64S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S12S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S64S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<24> __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<64> __arg0, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S64S64i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<64> __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S64r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<64> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S64S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<64> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S64S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<64> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S64S64S64r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<64> (*NativeMethod)(ValueTypeSize<64> __arg0, ValueTypeSize<64> __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<64>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
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


static void __M2N_S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int16_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S8i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_S8i4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_S8i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S8i4i4S240(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<240> __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<240>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8i4S12S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S8i4S240(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, ValueTypeSize<240> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<240>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8i4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(float __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8r4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(float __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(double __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8S12i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8S16S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S16S8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8S16S8S16i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<16> __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S8S16S8S16i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<16> __arg2, int8_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_S8S16S8S16i1i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<16> __arg2, int8_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_S8S16S8S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S8S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<32> __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<32>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<36> __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<36>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S8S8i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S8S8i1i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S8S8i1i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_S8S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, int32_t __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8S8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S8S8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, float __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S8S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S8S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S8S8S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8S8S8i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, float __arg3, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_S8S8S8i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, float __arg3, float __arg4, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_S8S8S8i4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, float __arg3, float __arg4, float __arg5, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_S8S8S8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, float __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S8S8S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<8> (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method);
    *(ValueTypeSize<8>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_S9(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<9> (*NativeMethod)(const MethodInfo* method);
    *(ValueTypeSize<9>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_S992i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<992> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<992>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S9i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<9> (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    *(ValueTypeSize<9>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_S9i4S9(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<9> (*NativeMethod)(int32_t __arg0, ValueTypeSize<9> __arg1, const MethodInfo* method);
    *(ValueTypeSize<9>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<9>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_S9S9(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef ValueTypeSize<9> (*NativeMethod)(ValueTypeSize<9> __arg0, const MethodInfo* method);
    *(ValueTypeSize<9>*)ret = ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<9>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_v(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(method);
}


static void __M2N_vC16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vC16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSizeAlign8<16> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vC32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSizeAlign8<32> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<32>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vC8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i1S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i1S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int8_t __arg1, ValueTypeSize<16> __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int8_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int8_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
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


static void __M2N_vi2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int16_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int16_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi4C16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4C16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4C32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<32> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<32>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4C8C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, ValueTypeSizeAlign8<8> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4C8C8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4C8C8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4C8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i1i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i1i1i1i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i1i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i1i1i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i1i1i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, int32_t __arg3, ValueTypeSize<8> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i1r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, float __arg3, float __arg4, float __arg5, float __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i1i1S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, ValueTypeSize<16> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i1i1S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int8_t __arg2, ValueTypeSize<16> __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i1i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i1i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i1i4i4i4i4S16S16i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, ValueTypeSize<16> __arg6, ValueTypeSize<16> __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int8_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int16_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i2i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i2i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int16_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i4C24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<24> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<24>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4C64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<64> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<64>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, ValueTypeSizeAlign8<8> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4C8C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, ValueTypeSizeAlign8<8> __arg3, ValueTypeSizeAlign8<8> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4C8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
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


static void __M2N_vi4i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i1i1i1i1i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int64_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i1i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i2i2i1i1i1i1i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int8_t __arg7, int8_t __arg8, int8_t __arg9, int8_t __arg10, int8_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), *(int8_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i4i2i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSizeAlign8<8> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4C8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSizeAlign8<8> __arg3, ValueTypeSizeAlign8<8> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i1i1i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i1i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i1i2i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int16_t __arg4, int16_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int16_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i1i4i4S16S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, ValueTypeSize<16> __arg6, ValueTypeSize<16> __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i1i8i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i4i1S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, ValueTypeSize<8> __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i2i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int16_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int16_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i2i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int16_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int16_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i1i1i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i1i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int16_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i4i2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int16_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i2i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int16_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int16_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i4i1C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, ValueTypeSizeAlign8<8> __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i4i4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i4i4i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int16_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int16_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSizeAlign8<8> __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, ValueTypeSizeAlign8<8> __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, ValueTypeSizeAlign8<8> __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, int8_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int8_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4i4i4i4i4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i4i4i4i4i4i4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, ValueTypeSize<16> __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4i4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int64_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, ValueTypeSize<16> __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<16> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<16> __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<28> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i4S28i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<28> __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<28> __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4i4S36i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<36> __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i4i4S64i1i1i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<64> __arg4, int8_t __arg5, int8_t __arg6, int8_t __arg7, int32_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4i4i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<16> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<16> __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4S24i4i4i4i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<24> __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i4i4S24i4i4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<24> __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4i4i4S24i4i4i4i4i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<24> __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, int32_t __arg12, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int32_t*)(localVarBase+argVarIndexs[12]), method);
}


static void __M2N_vi4i4i4S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<28> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4S28S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<28> __arg3, ValueTypeSize<28> __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<64> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
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


static void __M2N_vi4i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i8i4i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4i8i4i8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4i8i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4r4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, double __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4r8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, double __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<12> __arg2, ValueTypeSize<16> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S12S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<12> __arg2, ValueTypeSize<16> __arg3, ValueTypeSize<12> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<1> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<1>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<20> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<24> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S28i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4S28i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4S28i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4S28S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, ValueTypeSize<8> __arg3, ValueTypeSize<8> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<36> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S36S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<36> __arg2, ValueTypeSize<36> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S48i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<48> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<48>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S52(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<52> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<52>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S52i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<52> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<52>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S64i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S64i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4S64i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i4S64i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4i4S64i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i4S64i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<64> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i4S8i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i4S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<8> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i4S8S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<8> __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4i8C8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
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


static void __M2N_vi4i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i8i4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8i8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i8i8i1i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int8_t __arg3, int64_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4i8i8i8i8i8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4i8i8i8i8i8i8i4i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), *(int64_t*)(localVarBase+argVarIndexs[3]), *(int64_t*)(localVarBase+argVarIndexs[4]), *(int64_t*)(localVarBase+argVarIndexs[5]), *(int64_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int64_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4i8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, double __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4i8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, int64_t __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
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


static void __M2N_vi4r4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, float __arg7, float __arg8, float __arg9, float __arg10, float __arg11, float __arg12, float __arg13, float __arg14, float __arg15, float __arg16, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), *(float*)(localVarBase+argVarIndexs[8]), *(float*)(localVarBase+argVarIndexs[9]), *(float*)(localVarBase+argVarIndexs[10]), *(float*)(localVarBase+argVarIndexs[11]), *(float*)(localVarBase+argVarIndexs[12]), *(float*)(localVarBase+argVarIndexs[13]), *(float*)(localVarBase+argVarIndexs[14]), *(float*)(localVarBase+argVarIndexs[15]), *(float*)(localVarBase+argVarIndexs[16]), method);
}


static void __M2N_vi4r4S8S8r4r4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, float __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<8> __arg3, float __arg4, float __arg5, ValueTypeSize<8> __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(float*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, double __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4r8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, double __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4r8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, double __arg1, double __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<1>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S12i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S12i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S12r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S12S12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S12S12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S12S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S12S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S12S16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S12S16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int8_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4S12S16i4i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, int8_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int8_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4S12S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S12S16S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S16i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S16i4i1i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int8_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S16i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S16i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S16r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S16r4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, float __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S16S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S16S16S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<16> __arg3, ValueTypeSize<16> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S16S8S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<16> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S16S8S16i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<16> __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S16S8S16i1i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<16> __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4S16S8S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<8> __arg2, ValueTypeSize<16> __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S188(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<188> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<188>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<1> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<1>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S20i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S20i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S20i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S20i4i4S36S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<36> __arg4, ValueTypeSize<36> __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S20i4i4S4i1S36S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<4> __arg4, int8_t __arg5, ValueTypeSize<36> __arg6, ValueTypeSize<36> __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<20>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[4]), *(int8_t*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4S224(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<224> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<224>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S24i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<24> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4S24i4i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<24> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int8_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<24>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S28i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S28i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S28i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S28i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S28i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S28i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4S28i4i4i4i4i4i4S28i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, ValueTypeSize<28> __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, int32_t __arg12, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), *(int32_t*)(localVarBase+argVarIndexs[12]), method);
}


static void __M2N_vi4S28i4i4S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<28> __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S28i4r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, float __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S28i4S28i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, ValueTypeSize<28> __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S28S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, ValueTypeSize<28> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S28S28i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, ValueTypeSize<28> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S28S28i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, ValueTypeSize<28> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S28S28i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, ValueTypeSize<28> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S28S28S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, ValueTypeSize<28> __arg2, ValueTypeSize<8> __arg3, ValueTypeSize<8> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S28S28S8S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<28> __arg1, ValueTypeSize<28> __arg2, ValueTypeSize<8> __arg3, ValueTypeSize<8> __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S2i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S2i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S2i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S2i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<2>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S32(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<32>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S36i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S36i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S36i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S36S36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S36S36i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S36S36i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S36S36S36S28(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, ValueTypeSize<36> __arg3, ValueTypeSize<28> __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S36S36S36S28S64r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, ValueTypeSize<36> __arg3, ValueTypeSize<28> __arg4, ValueTypeSize<64> __arg5, float __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<36>*)(localVarBase+argVarIndexs[3]), *(ValueTypeSize<28>*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S40(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<40> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<40>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S48(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<48> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<48>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S4i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4S4S224(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<4> __arg1, ValueTypeSize<224> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<224>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S5(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<5> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<5>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S52(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<52> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<52>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S52i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<52> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<52>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S60(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<60> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<60>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S64i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S64i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S64i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S64i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S64i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i1i1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int8_t __arg8, int8_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int8_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int8_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i4i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i4i1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int8_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int8_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i4i1i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int32_t __arg10, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), method);
}


static void __M2N_vi4S64i4i4i4i4i4i4i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int8_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), *(int32_t*)(localVarBase+argVarIndexs[10]), *(int32_t*)(localVarBase+argVarIndexs[11]), method);
}


static void __M2N_vi4S64S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S64S64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<64> __arg1, ValueTypeSize<64> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<64>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S68(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<68> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<68>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S8C56(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSizeAlign8<56> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<56>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8C56i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSizeAlign8<56> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSizeAlign8<56>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8i1i1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S8i1i1i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vi4S8i1i1i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vi4S8i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int16_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int16_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S8i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, int64_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int64_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S8r8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, double __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(double*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vi4S8S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vi4S8S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vi4S8S8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vi4S9(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<9> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<9>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi4S992(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int32_t __arg0, ValueTypeSize<992> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int32_t*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<992>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vi8i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vi8i8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(int64_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(int64_t*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
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


static void __M2N_vr4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vr4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, float __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vr4r4r4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, float __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vr4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vr4S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(float __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(float*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
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


static void __M2N_vr8r8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(double __arg0, double __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(double*)(localVarBase+argVarIndexs[0]), *(double*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<1> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS108(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<108> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<108>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS12i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS12i2(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int16_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int16_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS12i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS12i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS12i4i1S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, int8_t __arg2, ValueTypeSize<16> __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS12i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS12i8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, int64_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(int64_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS12r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, float __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS12r4r4r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(float*)(localVarBase+argVarIndexs[1]), *(float*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vS12S12(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS12S12S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS12S12S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, float __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS12S12S16r4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<12> __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, float __arg3, int8_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<12>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<12>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(float*)(localVarBase+argVarIndexs[3]), *(int8_t*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vS16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS16i4i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS16i4i4i1r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), method);
}


static void __M2N_vS16i4i4i1r4S16r4r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, ValueTypeSize<16> __arg5, float __arg6, float __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[5]), *(float*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vS16i4i4i1r4S16S16r4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, ValueTypeSize<16> __arg5, ValueTypeSize<16> __arg6, float __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[6]), *(float*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vS16i4i4i1r4S16S16S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, float __arg4, ValueTypeSize<16> __arg5, ValueTypeSize<16> __arg6, ValueTypeSize<16> __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), *(float*)(localVarBase+argVarIndexs[4]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[5]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vS16i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS16i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), method);
}


static void __M2N_vS16i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vS16i4i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vS16i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS16i4S16i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS16i4S16i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), method);
}


static void __M2N_vS16i4S16i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vS16i4S16i4i4i4i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(int32_t*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vS16i4S16i4i4i4i4S16(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), method);
}


static void __M2N_vS16i4S16i4i4i4i4S16i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, int32_t __arg8, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), method);
}


static void __M2N_vS16i4S16i4i4i4i4S16i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), *(int32_t*)(localVarBase+argVarIndexs[5]), *(int32_t*)(localVarBase+argVarIndexs[6]), *(ValueTypeSize<16>*)(localVarBase+argVarIndexs[7]), *(int32_t*)(localVarBase+argVarIndexs[8]), *(int32_t*)(localVarBase+argVarIndexs[9]), method);
}


static void __M2N_vS16S8S8i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<16> __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int8_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<16>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[2]), *(int8_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS1i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<1> __arg0, int8_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), *(int8_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS1i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<1> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS1i4i1(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<1> __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<1>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int8_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS20(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<20> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<20>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS24(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<24> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<24>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS32i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<32> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<32>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS36(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<36> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<36>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS36i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<36> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<36>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<4> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS40(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<40> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<40>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<4> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS4S4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<4> __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<4>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<4>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS64(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<64> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS64i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<64> __arg0, int32_t __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<64>*)(localVarBase+argVarIndexs[0]), *(int32_t*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<8> __arg0, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), method);
}


static void __M2N_vS8S8(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), method);
}


static void __M2N_vS8S8i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), method);
}


static void __M2N_vS8S8i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), method);
}


static void __M2N_vS8S8i4i4i4(const MethodInfo* method, uint16_t* argVarIndexs, StackObject* localVarBase, void* ret)
{
    typedef void (*NativeMethod)(ValueTypeSize<8> __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method);
    ((NativeMethod)(GetInterpreterDirectlyCallMethodPointer(method)))(*(ValueTypeSize<8>*)(localVarBase+argVarIndexs[0]), *(ValueTypeSize<8>*)(localVarBase+argVarIndexs[1]), *(int32_t*)(localVarBase+argVarIndexs[2]), *(int32_t*)(localVarBase+argVarIndexs[3]), *(int32_t*)(localVarBase+argVarIndexs[4]), method);
}


Managed2NativeMethodInfo hybridclr::interpreter::g_managed2nativeStub[] = 
{

	{"C16", __M2N_C16},
	{"C16C16", __M2N_C16C16},
	{"C16C16C16", __M2N_C16C16C16},
	{"C16C16C8", __M2N_C16C16C8},
	{"C16C16i4", __M2N_C16C16i4},
	{"C16C16r8", __M2N_C16C16r8},
	{"C16C8", __M2N_C16C8},
	{"C16i1", __M2N_C16i1},
	{"C16i2", __M2N_C16i2},
	{"C16i4", __M2N_C16i4},
	{"C16i4C16", __M2N_C16i4C16},
	{"C16i4C8", __M2N_C16i4C8},
	{"C16i4i4", __M2N_C16i4i4},
	{"C16i4i4i4", __M2N_C16i4i4i4},
	{"C16i4i4i4i4", __M2N_C16i4i4i4i4},
	{"C16i4i8", __M2N_C16i4i8},
	{"C16i4r8", __M2N_C16i4r8},
	{"C16i8", __M2N_C16i8},
	{"C16r4", __M2N_C16r4},
	{"C16r8", __M2N_C16r8},
	{"C16r8r8", __M2N_C16r8r8},
	{"C16S16", __M2N_C16S16},
	{"C16S8", __M2N_C16S8},
	{"C24", __M2N_C24},
	{"C24C24", __M2N_C24C24},
	{"C24C8i4i4", __M2N_C24C8i4i4},
	{"C24C8i4i4i4", __M2N_C24C8i4i4i4},
	{"C24i4", __M2N_C24i4},
	{"C24i4C24", __M2N_C24i4C24},
	{"C24i4i4", __M2N_C24i4i4},
	{"C24i4i4i4", __M2N_C24i4i4i4},
	{"C24i4i4i4i4", __M2N_C24i4i4i4i4},
	{"C24i8i8i4", __M2N_C24i8i8i4},
	{"C24i8i8i4i4", __M2N_C24i8i8i4i4},
	{"C32", __M2N_C32},
	{"C32C32", __M2N_C32C32},
	{"C32i4", __M2N_C32i4},
	{"C32i4C32", __M2N_C32i4C32},
	{"C64i4", __M2N_C64i4},
	{"C8", __M2N_C8},
	{"C8C16C16", __M2N_C8C16C16},
	{"C8C8", __M2N_C8C8},
	{"C8C8C8", __M2N_C8C8C8},
	{"C8C8i4", __M2N_C8C8i4},
	{"C8C8i4i4", __M2N_C8C8i4i4},
	{"C8i1", __M2N_C8i1},
	{"C8i2", __M2N_C8i2},
	{"C8i4", __M2N_C8i4},
	{"C8i4C16", __M2N_C8i4C16},
	{"C8i4C8", __M2N_C8i4C8},
	{"C8i4C8i4", __M2N_C8i4C8i4},
	{"C8i4C8i4i4", __M2N_C8i4C8i4i4},
	{"C8i4C8r8", __M2N_C8i4C8r8},
	{"C8i4i4", __M2N_C8i4i4},
	{"C8i4i4i4", __M2N_C8i4i4i4},
	{"C8i4i4i4i4", __M2N_C8i4i4i4i4},
	{"C8i4i4i4i4i4i4i4i4", __M2N_C8i4i4i4i4i4i4i4i4},
	{"C8i4i4i4i4i4i4i4i4i4", __M2N_C8i4i4i4i4i4i4i4i4i4},
	{"C8i4i8", __M2N_C8i4i8},
	{"C8i4r8", __M2N_C8i4r8},
	{"C8i8", __M2N_C8i8},
	{"C8r4", __M2N_C8r4},
	{"C8r8", __M2N_C8r8},
	{"C8S16", __M2N_C8S16},
	{"C8S2i4i4i4", __M2N_C8S2i4i4i4},
	{"C8S4i4i4", __M2N_C8S4i4i4},
	{"i1", __M2N_i1},
	{"i1C1568C1568", __M2N_i1C1568C1568},
	{"i1C16C16", __M2N_i1C16C16},
	{"i1C24C24", __M2N_i1C24C24},
	{"i1C64C64", __M2N_i1C64C64},
	{"i1C8", __M2N_i1C8},
	{"i1C8C8", __M2N_i1C8C8},
	{"i1C8i4", __M2N_i1C8i4},
	{"i1i1", __M2N_i1i1},
	{"i1i1i1", __M2N_i1i1i1},
	{"i1i1i4i4", __M2N_i1i1i4i4},
	{"i1i1i4i4i4", __M2N_i1i1i4i4i4},
	{"i1i2", __M2N_i1i2},
	{"i1i2i2", __M2N_i1i2i2},
	{"i1i2i4", __M2N_i1i2i4},
	{"i1i2i4i4", __M2N_i1i2i4i4},
	{"i1i4", __M2N_i1i4},
	{"i1i4C1568", __M2N_i1i4C1568},
	{"i1i4C16", __M2N_i1i4C16},
	{"i1i4C24", __M2N_i1i4C24},
	{"i1i4C64", __M2N_i1i4C64},
	{"i1i4C8", __M2N_i1i4C8},
	{"i1i4C8C8", __M2N_i1i4C8C8},
	{"i1i4C8i1", __M2N_i1i4C8i1},
	{"i1i4C8S4", __M2N_i1i4C8S4},
	{"i1i4i1", __M2N_i1i4i1},
	{"i1i4i1i4", __M2N_i1i4i1i4},
	{"i1i4i1i8", __M2N_i1i4i1i8},
	{"i1i4i2", __M2N_i1i4i2},
	{"i1i4i2i2i4", __M2N_i1i4i2i2i4},
	{"i1i4i2i4", __M2N_i1i4i2i4},
	{"i1i4i2i4i4", __M2N_i1i4i2i4i4},
	{"i1i4i2i4i4i4", __M2N_i1i4i2i4i4i4},
	{"i1i4i2i4i4i4i4", __M2N_i1i4i2i4i4i4i4},
	{"i1i4i4", __M2N_i1i4i4},
	{"i1i4i4C8i1", __M2N_i1i4i4C8i1},
	{"i1i4i4i1", __M2N_i1i4i4i1},
	{"i1i4i4i1i4", __M2N_i1i4i4i1i4},
	{"i1i4i4i1i8", __M2N_i1i4i4i1i8},
	{"i1i4i4i4", __M2N_i1i4i4i4},
	{"i1i4i4i4C8", __M2N_i1i4i4i4C8},
	{"i1i4i4i4i1", __M2N_i1i4i4i4i1},
	{"i1i4i4i4i4", __M2N_i1i4i4i4i4},
	{"i1i4i4i4i4i1", __M2N_i1i4i4i4i4i1},
	{"i1i4i4i4i4i1i4", __M2N_i1i4i4i4i4i1i4},
	{"i1i4i4i4i4i4", __M2N_i1i4i4i4i4i4},
	{"i1i4i4i4i4i4i4", __M2N_i1i4i4i4i4i4i4},
	{"i1i4i4i4i4i4i4i4i4i4", __M2N_i1i4i4i4i4i4i4i4i4i4},
	{"i1i4i4i4i4i4i4i4S16S16", __M2N_i1i4i4i4i4i4i4i4S16S16},
	{"i1i4i4i4i4i4S4", __M2N_i1i4i4i4i4i4S4},
	{"i1i4i4i4i4i4S4i4", __M2N_i1i4i4i4i4i4S4i4},
	{"i1i4i4i4i4S12i4r4i4i4i4", __M2N_i1i4i4i4i4S12i4r4i4i4i4},
	{"i1i4i4i4r4i4i4i4", __M2N_i1i4i4i4r4i4i4i4},
	{"i1i4i4i4S4", __M2N_i1i4i4i4S4},
	{"i1i4i4i4S4i4", __M2N_i1i4i4i4S4i4},
	{"i1i4i4i8", __M2N_i1i4i4i8},
	{"i1i4i4i8i1", __M2N_i1i4i4i8i1},
	{"i1i4i4r4i4", __M2N_i1i4i4r4i4},
	{"i1i4i4S16i4", __M2N_i1i4i4S16i4},
	{"i1i4i4S16i4i4", __M2N_i1i4i4S16i4i4},
	{"i1i4i4S4", __M2N_i1i4i4S4},
	{"i1i4i4S88", __M2N_i1i4i4S88},
	{"i1i4i4S88i4", __M2N_i1i4i4S88i4},
	{"i1i4i8", __M2N_i1i4i8},
	{"i1i4i8i8", __M2N_i1i4i8i8},
	{"i1i4r4", __M2N_i1i4r4},
	{"i1i4r4r4", __M2N_i1i4r4r4},
	{"i1i4r4r4i4", __M2N_i1i4r4r4i4},
	{"i1i4r8", __M2N_i1i4r8},
	{"i1i4r8i4i4", __M2N_i1i4r8i4i4},
	{"i1i4S1", __M2N_i1i4S1},
	{"i1i4S108", __M2N_i1i4S108},
	{"i1i4S116", __M2N_i1i4S116},
	{"i1i4S12", __M2N_i1i4S12},
	{"i1i4S12i1", __M2N_i1i4S12i1},
	{"i1i4S12i4", __M2N_i1i4S12i4},
	{"i1i4S12S12", __M2N_i1i4S12S12},
	{"i1i4S136", __M2N_i1i4S136},
	{"i1i4S16", __M2N_i1i4S16},
	{"i1i4S16i1", __M2N_i1i4S16i1},
	{"i1i4S16i4", __M2N_i1i4S16i4},
	{"i1i4S16i4i4", __M2N_i1i4S16i4i4},
	{"i1i4S16i4i4i4i4i4", __M2N_i1i4S16i4i4i4i4i4},
	{"i1i4S188", __M2N_i1i4S188},
	{"i1i4S2", __M2N_i1i4S2},
	{"i1i4S20", __M2N_i1i4S20},
	{"i1i4S216", __M2N_i1i4S216},
	{"i1i4S224", __M2N_i1i4S224},
	{"i1i4S24", __M2N_i1i4S24},
	{"i1i4S24i4", __M2N_i1i4S24i4},
	{"i1i4S28", __M2N_i1i4S28},
	{"i1i4S312", __M2N_i1i4S312},
	{"i1i4S32", __M2N_i1i4S32},
	{"i1i4S4", __M2N_i1i4S4},
	{"i1i4S64", __M2N_i1i4S64},
	{"i1i4S68", __M2N_i1i4S68},
	{"i1i4S8", __M2N_i1i4S8},
	{"i1i4S88", __M2N_i1i4S88},
	{"i1i4S8S8", __M2N_i1i4S8S8},
	{"i1i4S92", __M2N_i1i4S92},
	{"i1i4S992", __M2N_i1i4S992},
	{"i1i8", __M2N_i1i8},
	{"i1i8i1", __M2N_i1i8i1},
	{"i1i8i8", __M2N_i1i8i8},
	{"i1i8i8i1", __M2N_i1i8i8i1},
	{"i1i8S8", __M2N_i1i8S8},
	{"i1r4", __M2N_i1r4},
	{"i1r4r4", __M2N_i1r4r4},
	{"i1r4r4r4", __M2N_i1r4r4r4},
	{"i1r4r4r4r4", __M2N_i1r4r4r4r4},
	{"i1r8", __M2N_i1r8},
	{"i1r8r8", __M2N_i1r8r8},
	{"i1S108S108", __M2N_i1S108S108},
	{"i1S116S116", __M2N_i1S116S116},
	{"i1S12", __M2N_i1S12},
	{"i1S12i2", __M2N_i1S12i2},
	{"i1S12i4", __M2N_i1S12i4},
	{"i1S12i4i4i4", __M2N_i1S12i4i4i4},
	{"i1S12i8", __M2N_i1S12i8},
	{"i1S12S12", __M2N_i1S12S12},
	{"i1S136S136", __M2N_i1S136S136},
	{"i1S16", __M2N_i1S16},
	{"i1S16i1i4", __M2N_i1S16i1i4},
	{"i1S16i1i4i4", __M2N_i1S16i1i4i4},
	{"i1S16i4", __M2N_i1S16i4},
	{"i1S16i4i1i4i4", __M2N_i1S16i4i1i4i4},
	{"i1S16i4i4", __M2N_i1S16i4i4},
	{"i1S16r4", __M2N_i1S16r4},
	{"i1S16S16", __M2N_i1S16S16},
	{"i1S188S188", __M2N_i1S188S188},
	{"i1S20", __M2N_i1S20},
	{"i1S20S20", __M2N_i1S20S20},
	{"i1S216S216", __M2N_i1S216S216},
	{"i1S224S224", __M2N_i1S224S224},
	{"i1S24i4", __M2N_i1S24i4},
	{"i1S24S24", __M2N_i1S24S24},
	{"i1S28S28", __M2N_i1S28S28},
	{"i1S2S2", __M2N_i1S2S2},
	{"i1S312S312", __M2N_i1S312S312},
	{"i1S32S32", __M2N_i1S32S32},
	{"i1S4", __M2N_i1S4},
	{"i1S4i4", __M2N_i1S4i4},
	{"i1S4S4", __M2N_i1S4S4},
	{"i1S64i4", __M2N_i1S64i4},
	{"i1S64i4i4i4", __M2N_i1S64i4i4i4},
	{"i1S64S64", __M2N_i1S64S64},
	{"i1S68S68", __M2N_i1S68S68},
	{"i1S8", __M2N_i1S8},
	{"i1S8i8", __M2N_i1S8i8},
	{"i1S8S8", __M2N_i1S8S8},
	{"i1S92S92", __M2N_i1S92S92},
	{"i1S992S992", __M2N_i1S992S992},
	{"i2", __M2N_i2},
	{"i2C8", __M2N_i2C8},
	{"i2i1", __M2N_i2i1},
	{"i2i2", __M2N_i2i2},
	{"i2i2i2", __M2N_i2i2i2},
	{"i2i2i4", __M2N_i2i2i4},
	{"i2i4", __M2N_i2i4},
	{"i2i4i2", __M2N_i2i4i2},
	{"i2i4i4", __M2N_i2i4i4},
	{"i2i4i4i4", __M2N_i2i4i4i4},
	{"i2i4i8", __M2N_i2i4i8},
	{"i2i8", __M2N_i2i8},
	{"i2r4", __M2N_i2r4},
	{"i2r8", __M2N_i2r8},
	{"i2S12", __M2N_i2S12},
	{"i2S16", __M2N_i2S16},
	{"i2S2", __M2N_i2S2},
	{"i2S8", __M2N_i2S8},
	{"i4", __M2N_i4},
	{"i4C16", __M2N_i4C16},
	{"i4C16C16", __M2N_i4C16C16},
	{"i4C16i4", __M2N_i4C16i4},
	{"i4C8", __M2N_i4C8},
	{"i4C8C8", __M2N_i4C8C8},
	{"i4C8C8C8C24C24", __M2N_i4C8C8C8C24C24},
	{"i4C8C8i4i4i4i4i4", __M2N_i4C8C8i4i4i4i4i4},
	{"i4C8i4", __M2N_i4C8i4},
	{"i4C8i4i4", __M2N_i4C8i4i4},
	{"i4C8i4i4i4", __M2N_i4C8i4i4i4},
	{"i4C8i4i4i4i4i4", __M2N_i4C8i4i4i4i4i4},
	{"i4C8S4", __M2N_i4C8S4},
	{"i4i1", __M2N_i4i1},
	{"i4i1i4", __M2N_i4i1i4},
	{"i4i1i4i4", __M2N_i4i1i4i4},
	{"i4i2", __M2N_i4i2},
	{"i4i2i2", __M2N_i4i2i2},
	{"i4i2i4", __M2N_i4i2i4},
	{"i4i4", __M2N_i4i4},
	{"i4i4C16", __M2N_i4i4C16},
	{"i4i4C8", __M2N_i4i4C8},
	{"i4i4C8C8i4i4i4i4i4", __M2N_i4i4C8C8i4i4i4i4i4},
	{"i4i4C8i1", __M2N_i4i4C8i1},
	{"i4i4C8i4", __M2N_i4i4C8i4},
	{"i4i4C8i4i4", __M2N_i4i4C8i4i4},
	{"i4i4C8i4i4i4", __M2N_i4i4C8i4i4i4},
	{"i4i4C8i4i4i4i4", __M2N_i4i4C8i4i4i4i4},
	{"i4i4C8i4i4i4i4i1", __M2N_i4i4C8i4i4i4i4i1},
	{"i4i4C8i4i4i4i4i4", __M2N_i4i4C8i4i4i4i4i4},
	{"i4i4C8S4", __M2N_i4i4C8S4},
	{"i4i4i1", __M2N_i4i4i1},
	{"i4i4i1i1", __M2N_i4i4i1i1},
	{"i4i4i1i1i1i4i4", __M2N_i4i4i1i1i1i4i4},
	{"i4i4i1i1i4", __M2N_i4i4i1i1i4},
	{"i4i4i1i1i4i4", __M2N_i4i4i1i1i4i4},
	{"i4i4i1i4", __M2N_i4i4i1i4},
	{"i4i4i1i4i1", __M2N_i4i4i1i4i1},
	{"i4i4i1i4i4", __M2N_i4i4i1i4i4},
	{"i4i4i1i4i4i4", __M2N_i4i4i1i4i4i4},
	{"i4i4i2", __M2N_i4i4i2},
	{"i4i4i2i2", __M2N_i4i4i2i2},
	{"i4i4i2i2i4", __M2N_i4i4i2i2i4},
	{"i4i4i2i2i4i4", __M2N_i4i4i2i2i4i4},
	{"i4i4i2i4", __M2N_i4i4i2i4},
	{"i4i4i2i4i4", __M2N_i4i4i2i4i4},
	{"i4i4i2i4i4i4", __M2N_i4i4i2i4i4i4},
	{"i4i4i4", __M2N_i4i4i4},
	{"i4i4i4C8", __M2N_i4i4i4C8},
	{"i4i4i4C8i4", __M2N_i4i4i4C8i4},
	{"i4i4i4C8i4i4", __M2N_i4i4i4C8i4i4},
	{"i4i4i4i1", __M2N_i4i4i4i1},
	{"i4i4i4i1i1", __M2N_i4i4i4i1i1},
	{"i4i4i4i1i1i1", __M2N_i4i4i4i1i1i1},
	{"i4i4i4i1i1i1i1", __M2N_i4i4i4i1i1i1i1},
	{"i4i4i4i1i1i1i1i4", __M2N_i4i4i4i1i1i1i1i4},
	{"i4i4i4i1i1i1i1i4i4", __M2N_i4i4i4i1i1i1i1i4i4},
	{"i4i4i4i1i1i4i4", __M2N_i4i4i4i1i1i4i4},
	{"i4i4i4i1i4", __M2N_i4i4i4i1i4},
	{"i4i4i4i1i4i1", __M2N_i4i4i4i1i4i1},
	{"i4i4i4i1i4i1i4i4", __M2N_i4i4i4i1i4i1i4i4},
	{"i4i4i4i1i4i4i4i4i4", __M2N_i4i4i4i1i4i4i4i4i4},
	{"i4i4i4i1i4i4i4i4i4i4", __M2N_i4i4i4i1i4i4i4i4i4i4},
	{"i4i4i4i2", __M2N_i4i4i4i2},
	{"i4i4i4i2i2i1i1i4i2", __M2N_i4i4i4i2i2i1i1i4i2},
	{"i4i4i4i2i2i4", __M2N_i4i4i4i2i2i4},
	{"i4i4i4i2i4", __M2N_i4i4i4i2i4},
	{"i4i4i4i2i4i4", __M2N_i4i4i4i2i4i4},
	{"i4i4i4i2i4i4i4", __M2N_i4i4i4i2i4i4i4},
	{"i4i4i4i4", __M2N_i4i4i4i4},
	{"i4i4i4i4C8", __M2N_i4i4i4i4C8},
	{"i4i4i4i4C8i1", __M2N_i4i4i4i4C8i1},
	{"i4i4i4i4C8S12", __M2N_i4i4i4i4C8S12},
	{"i4i4i4i4i1", __M2N_i4i4i4i4i1},
	{"i4i4i4i4i1i1", __M2N_i4i4i4i4i1i1},
	{"i4i4i4i4i1i1i4", __M2N_i4i4i4i4i1i1i4},
	{"i4i4i4i4i1i4", __M2N_i4i4i4i4i1i4},
	{"i4i4i4i4i1i4i4", __M2N_i4i4i4i4i1i4i4},
	{"i4i4i4i4i1i4i4i4", __M2N_i4i4i4i4i1i4i4i4},
	{"i4i4i4i4i1i4i4i4i4i4", __M2N_i4i4i4i4i1i4i4i4i4i4},
	{"i4i4i4i4i1i4i4i4i4i4i4", __M2N_i4i4i4i4i1i4i4i4i4i4i4},
	{"i4i4i4i4i1i4i4i4S16S16", __M2N_i4i4i4i4i1i4i4i4S16S16},
	{"i4i4i4i4i2i2i1i1i4i2", __M2N_i4i4i4i4i2i2i1i1i4i2},
	{"i4i4i4i4i4", __M2N_i4i4i4i4i4},
	{"i4i4i4i4i4C8", __M2N_i4i4i4i4i4C8},
	{"i4i4i4i4i4C8i1S12", __M2N_i4i4i4i4i4C8i1S12},
	{"i4i4i4i4i4i1", __M2N_i4i4i4i4i4i1},
	{"i4i4i4i4i4i1i1", __M2N_i4i4i4i4i4i1i1},
	{"i4i4i4i4i4i1i1i1", __M2N_i4i4i4i4i4i1i1i1},
	{"i4i4i4i4i4i1i1i1i4", __M2N_i4i4i4i4i4i1i1i1i4},
	{"i4i4i4i4i4i1i4", __M2N_i4i4i4i4i4i1i4},
	{"i4i4i4i4i4i1i4i1", __M2N_i4i4i4i4i4i1i4i1},
	{"i4i4i4i4i4i1i4i4", __M2N_i4i4i4i4i4i1i4i4},
	{"i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i1", __M2N_i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i1i4", __M2N_i4i4i4i4i4i4i1i4},
	{"i4i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i1", __M2N_i4i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4i1i1S24i4i4i4", __M2N_i4i4i4i4i4i4i4i1i1S24i4i4i4},
	{"i4i4i4i4i4i4i4i1i1S24i4i4i4i8", __M2N_i4i4i4i4i4i4i4i1i1S24i4i4i4i8},
	{"i4i4i4i4i4i4i4i1i1S24i4i4i4i8i4", __M2N_i4i4i4i4i4i4i4i1i1S24i4i4i4i8i4},
	{"i4i4i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i1", __M2N_i4i4i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i4i1", __M2N_i4i4i4i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4i4i4i1i4", __M2N_i4i4i4i4i4i4i4i4i4i1i4},
	{"i4i4i4i4i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i4i4i4i4i4i4i4", __M2N_i4i4i4i4i4i4i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4S4", __M2N_i4i4i4i4i4S4},
	{"i4i4i4i4i4S4i4", __M2N_i4i4i4i4i4S4i4},
	{"i4i4i4i4i8", __M2N_i4i4i4i4i8},
	{"i4i4i4i4i8i1", __M2N_i4i4i4i4i8i1},
	{"i4i4i4i4i8i4", __M2N_i4i4i4i4i8i4},
	{"i4i4i4i4r8i4i4r8", __M2N_i4i4i4i4r8i4i4r8},
	{"i4i4i4i4S20", __M2N_i4i4i4i4S20},
	{"i4i4i4i4S4", __M2N_i4i4i4i4S4},
	{"i4i4i4i4S4i4i4", __M2N_i4i4i4i4S4i4i4},
	{"i4i4i4i4S8i4", __M2N_i4i4i4i4S8i4},
	{"i4i4i4i8", __M2N_i4i4i4i8},
	{"i4i4i4i8i4i4i1", __M2N_i4i4i4i8i4i4i1},
	{"i4i4i4i8i4i4i4i1", __M2N_i4i4i4i8i4i4i4i1},
	{"i4i4i4r4", __M2N_i4i4i4r4},
	{"i4i4i4r8", __M2N_i4i4i4r8},
	{"i4i4i4S16", __M2N_i4i4i4S16},
	{"i4i4i4S16S16S16", __M2N_i4i4i4S16S16S16},
	{"i4i4i4S20", __M2N_i4i4i4S20},
	{"i4i4i4S32", __M2N_i4i4i4S32},
	{"i4i4i4S4", __M2N_i4i4i4S4},
	{"i4i4i4S4i4", __M2N_i4i4i4S4i4},
	{"i4i4i4S4i4i4", __M2N_i4i4i4S4i4i4},
	{"i4i4i4S4i4i4i4", __M2N_i4i4i4S4i4i4i4},
	{"i4i4i4S8i4", __M2N_i4i4i4S8i4},
	{"i4i4i8", __M2N_i4i4i8},
	{"i4i4i8i4", __M2N_i4i4i8i4},
	{"i4i4i8i4i4", __M2N_i4i4i8i4i4},
	{"i4i4i8i4i4i4", __M2N_i4i4i8i4i4i4},
	{"i4i4i8i4i4i4i4", __M2N_i4i4i8i4i4i4i4},
	{"i4i4i8i8", __M2N_i4i4i8i8},
	{"i4i4i8i8i4", __M2N_i4i4i8i8i4},
	{"i4i4i8i8i8", __M2N_i4i4i8i8i8},
	{"i4i4r4", __M2N_i4i4r4},
	{"i4i4r4r4", __M2N_i4i4r4r4},
	{"i4i4r8", __M2N_i4i4r8},
	{"i4i4r8i4i4i4", __M2N_i4i4r8i4i4i4},
	{"i4i4r8r8", __M2N_i4i4r8r8},
	{"i4i4S1", __M2N_i4i4S1},
	{"i4i4S12", __M2N_i4i4S12},
	{"i4i4S12i4", __M2N_i4i4S12i4},
	{"i4i4S12i4i1S4", __M2N_i4i4S12i4i1S4},
	{"i4i4S12i4i4", __M2N_i4i4S12i4i4},
	{"i4i4S12S16", __M2N_i4i4S12S16},
	{"i4i4S12S16i4", __M2N_i4i4S12S16i4},
	{"i4i4S12S4", __M2N_i4i4S12S4},
	{"i4i4S16", __M2N_i4i4S16},
	{"i4i4S16i4", __M2N_i4i4S16i4},
	{"i4i4S16i4i4", __M2N_i4i4S16i4i4},
	{"i4i4S16i4S8", __M2N_i4i4S16i4S8},
	{"i4i4S16S16", __M2N_i4i4S16S16},
	{"i4i4S16S16S16", __M2N_i4i4S16S16S16},
	{"i4i4S16S8", __M2N_i4i4S16S8},
	{"i4i4S16S8r4", __M2N_i4i4S16S8r4},
	{"i4i4S16S8r4i4", __M2N_i4i4S16S8r4i4},
	{"i4i4S16S8r4i4i4", __M2N_i4i4S16S8r4i4i4},
	{"i4i4S16S8r4i4i4S16", __M2N_i4i4S16S8r4i4i4S16},
	{"i4i4S16S8r4i4i4S16i1", __M2N_i4i4S16S8r4i4i4S16i1},
	{"i4i4S20", __M2N_i4i4S20},
	{"i4i4S20i4", __M2N_i4i4S20i4},
	{"i4i4S32", __M2N_i4i4S32},
	{"i4i4S36", __M2N_i4i4S36},
	{"i4i4S4", __M2N_i4i4S4},
	{"i4i4S4i4", __M2N_i4i4S4i4},
	{"i4i4S4S4", __M2N_i4i4S4S4},
	{"i4i4S8", __M2N_i4i4S8},
	{"i4i4S8i4", __M2N_i4i4S8i4},
	{"i4i4S8S12i4i4i4", __M2N_i4i4S8S12i4i4i4},
	{"i4i4S8S12i8i8i4", __M2N_i4i4S8S12i8i8i4},
	{"i4i8", __M2N_i4i8},
	{"i4i8i4", __M2N_i4i8i4},
	{"i4i8i4i4", __M2N_i4i8i4i4},
	{"i4i8i4i4i4", __M2N_i4i8i4i4i4},
	{"i4i8i8", __M2N_i4i8i8},
	{"i4i8i8i8", __M2N_i4i8i8i8},
	{"i4r4", __M2N_i4r4},
	{"i4r4i4", __M2N_i4r4i4},
	{"i4r4i4i4", __M2N_i4r4i4i4},
	{"i4r4r4r4", __M2N_i4r4r4r4},
	{"i4r4r4r4r4", __M2N_i4r4r4r4r4},
	{"i4r8", __M2N_i4r8},
	{"i4r8i4", __M2N_i4r8i4},
	{"i4r8i4i4", __M2N_i4r8i4i4},
	{"i4S1", __M2N_i4S1},
	{"i4S12", __M2N_i4S12},
	{"i4S12i1", __M2N_i4S12i1},
	{"i4S12i1i1", __M2N_i4S12i1i1},
	{"i4S12i1i1i1", __M2N_i4S12i1i1i1},
	{"i4S12i4", __M2N_i4S12i4},
	{"i4S12i4i4", __M2N_i4S12i4i4},
	{"i4S12S12", __M2N_i4S12S12},
	{"i4S16", __M2N_i4S16},
	{"i4S16i1", __M2N_i4S16i1},
	{"i4S16i4", __M2N_i4S16i4},
	{"i4S16i4i1", __M2N_i4S16i4i1},
	{"i4S16i4i2", __M2N_i4S16i4i2},
	{"i4S16i4i2i4", __M2N_i4S16i4i2i4},
	{"i4S16i4i2i4i4", __M2N_i4S16i4i2i4i4},
	{"i4S16i4i4", __M2N_i4S16i4i4},
	{"i4S16i4i4i4", __M2N_i4S16i4i4i4},
	{"i4S16i4i4i4i4", __M2N_i4S16i4i4i4i4},
	{"i4S16S16", __M2N_i4S16S16},
	{"i4S4", __M2N_i4S4},
	{"i4S48", __M2N_i4S48},
	{"i4S4i4", __M2N_i4S4i4},
	{"i4S4S4", __M2N_i4S4S4},
	{"i4S52", __M2N_i4S52},
	{"i4S60", __M2N_i4S60},
	{"i4S60S16", __M2N_i4S60S16},
	{"i4S60S8", __M2N_i4S60S8},
	{"i4S64", __M2N_i4S64},
	{"i4S8", __M2N_i4S8},
	{"i4S8S12i4i4i4", __M2N_i4S8S12i4i4i4},
	{"i4S8S12i8i8i4", __M2N_i4S8S12i8i8i4},
	{"i4S8S8", __M2N_i4S8S8},
	{"i8", __M2N_i8},
	{"i8C16", __M2N_i8C16},
	{"i8C8", __M2N_i8C8},
	{"i8i1", __M2N_i8i1},
	{"i8i2", __M2N_i8i2},
	{"i8i4", __M2N_i8i4},
	{"i8i4i4", __M2N_i8i4i4},
	{"i8i4i4i4", __M2N_i8i4i4i4},
	{"i8i4i8", __M2N_i8i4i8},
	{"i8i4i8i4", __M2N_i8i4i8i4},
	{"i8i4i8i8", __M2N_i8i4i8i8},
	{"i8i8", __M2N_i8i8},
	{"i8i8i8", __M2N_i8i8i8},
	{"i8i8i8i4", __M2N_i8i8i8i4},
	{"i8r4", __M2N_i8r4},
	{"i8r8", __M2N_i8r8},
	{"i8S1", __M2N_i8S1},
	{"i8S12", __M2N_i8S12},
	{"i8S16", __M2N_i8S16},
	{"i8S20", __M2N_i8S20},
	{"i8S36", __M2N_i8S36},
	{"i8S4", __M2N_i8S4},
	{"i8S5", __M2N_i8S5},
	{"i8S8", __M2N_i8S8},
	{"i8S9", __M2N_i8S9},
	{"r4", __M2N_r4},
	{"r4C64", __M2N_r4C64},
	{"r4C64C64", __M2N_r4C64C64},
	{"r4C8", __M2N_r4C8},
	{"r4i1", __M2N_r4i1},
	{"r4i2", __M2N_r4i2},
	{"r4i4", __M2N_r4i4},
	{"r4i4i4", __M2N_r4i4i4},
	{"r4i4i4i4", __M2N_r4i4i4i4},
	{"r4i4i4r4", __M2N_r4i4i4r4},
	{"r4i4i4S88", __M2N_r4i4i4S88},
	{"r4i4i8", __M2N_r4i4i8},
	{"r4i4r4", __M2N_r4i4r4},
	{"r4i4r4r4", __M2N_r4i4r4r4},
	{"r4i4S12", __M2N_r4i4S12},
	{"r4i8", __M2N_r4i8},
	{"r4r4", __M2N_r4r4},
	{"r4r4r4", __M2N_r4r4r4},
	{"r4r4r4i4r4", __M2N_r4r4r4i4r4},
	{"r4r4r4i4r4r4", __M2N_r4r4r4i4r4r4},
	{"r4r4r4i4r4r4r4", __M2N_r4r4r4i4r4r4r4},
	{"r4r4r4r4", __M2N_r4r4r4r4},
	{"r4r4r4r4i4", __M2N_r4r4r4r4i4},
	{"r4r4r4r4i4i4i4", __M2N_r4r4r4r4i4i4i4},
	{"r4r4r4r4r4i4", __M2N_r4r4r4r4r4i4},
	{"r4r4r4r4r4i4i4", __M2N_r4r4r4r4r4i4i4},
	{"r4r8", __M2N_r4r8},
	{"r4S12", __M2N_r4S12},
	{"r4S12S12", __M2N_r4S12S12},
	{"r4S12S12S12", __M2N_r4S12S12S12},
	{"r4S16", __M2N_r4S16},
	{"r4S16r4r4r4", __M2N_r4S16r4r4r4},
	{"r4S16r4r4r4i4i4", __M2N_r4S16r4r4r4i4i4},
	{"r4S16r4r4r4i4i4i4", __M2N_r4S16r4r4r4i4i4i4},
	{"r4S16r4r4r4r4", __M2N_r4S16r4r4r4r4},
	{"r4S16r4r4r4r4i4", __M2N_r4S16r4r4r4r4i4},
	{"r4S16r4r4r4r4i4i4i1i4i4", __M2N_r4S16r4r4r4r4i4i4i1i4i4},
	{"r4S16S12", __M2N_r4S16S12},
	{"r4S16S16", __M2N_r4S16S16},
	{"r4S64", __M2N_r4S64},
	{"r4S8", __M2N_r4S8},
	{"r4S8S8", __M2N_r4S8S8},
	{"r8", __M2N_r8},
	{"r8C16", __M2N_r8C16},
	{"r8C24", __M2N_r8C24},
	{"r8C8", __M2N_r8C8},
	{"r8i1", __M2N_r8i1},
	{"r8i2", __M2N_r8i2},
	{"r8i4", __M2N_r8i4},
	{"r8i4C8", __M2N_r8i4C8},
	{"r8i4i4", __M2N_r8i4i4},
	{"r8i4i4i4", __M2N_r8i4i4i4},
	{"r8i4i4i4i4", __M2N_r8i4i4i4i4},
	{"r8i4i4i4i4i4", __M2N_r8i4i4i4i4i4},
	{"r8i4i8", __M2N_r8i4i8},
	{"r8i4r8", __M2N_r8i4r8},
	{"r8i4r8r8", __M2N_r8i4r8r8},
	{"r8i8", __M2N_r8i8},
	{"r8r4", __M2N_r8r4},
	{"r8r8", __M2N_r8r8},
	{"r8r8i4", __M2N_r8r8i4},
	{"r8r8i4i4", __M2N_r8r8i4i4},
	{"r8r8r8", __M2N_r8r8r8},
	{"r8S16", __M2N_r8S16},
	{"r8S8", __M2N_r8S8},
	{"r8S8r8", __M2N_r8S8r8},
	{"S1", __M2N_S1},
	{"S108", __M2N_S108},
	{"S108r4S108", __M2N_S108r4S108},
	{"S108S108r4", __M2N_S108S108r4},
	{"S108S108S108", __M2N_S108S108S108},
	{"S12", __M2N_S12},
	{"S12i1", __M2N_S12i1},
	{"S12i4", __M2N_S12i4},
	{"S12i4C8", __M2N_S12i4C8},
	{"S12i4i1", __M2N_S12i4i1},
	{"S12i4i4", __M2N_S12i4i4},
	{"S12i4i4i1", __M2N_S12i4i4i1},
	{"S12i4i4i4", __M2N_S12i4i4i4},
	{"S12i4i4i4i1", __M2N_S12i4i4i4i1},
	{"S12i4r4", __M2N_S12i4r4},
	{"S12i4r4r4r4", __M2N_S12i4r4r4r4},
	{"S12i4S12", __M2N_S12i4S12},
	{"S12i4S12i4", __M2N_S12i4S12i4},
	{"S12i4S12S12", __M2N_S12i4S12S12},
	{"S12i4S4", __M2N_S12i4S4},
	{"S12r4S12", __M2N_S12r4S12},
	{"S12S12", __M2N_S12S12},
	{"S12S12i4", __M2N_S12S12i4},
	{"S12S12r4", __M2N_S12S12r4},
	{"S12S12S12", __M2N_S12S12S12},
	{"S12S12S12i1", __M2N_S12S12S12i1},
	{"S12S12S12i4r4", __M2N_S12S12S12i4r4},
	{"S12S12S12i4r4r4", __M2N_S12S12S12i4r4r4},
	{"S12S12S12i4r4r4r4", __M2N_S12S12S12i4r4r4r4},
	{"S12S12S12r4", __M2N_S12S12S12r4},
	{"S12S12S12r4r4", __M2N_S12S12S12r4r4},
	{"S12S12S12S12", __M2N_S12S12S12S12},
	{"S12S12S16", __M2N_S12S12S16},
	{"S12S12S64", __M2N_S12S12S64},
	{"S12S16", __M2N_S12S16},
	{"S12S16S12", __M2N_S12S16S12},
	{"S12S8", __M2N_S12S8},
	{"S16", __M2N_S16},
	{"S16C8", __M2N_S16C8},
	{"S16i1", __M2N_S16i1},
	{"S16i2", __M2N_S16i2},
	{"S16i4", __M2N_S16i4},
	{"S16i4i4", __M2N_S16i4i4},
	{"S16i4i4i4", __M2N_S16i4i4i4},
	{"S16i4i4i4i4", __M2N_S16i4i4i4i4},
	{"S16i4i4i4i4i4", __M2N_S16i4i4i4i4i4},
	{"S16i4i4i4i4S36i4", __M2N_S16i4i4i4i4S36i4},
	{"S16i4i8", __M2N_S16i4i8},
	{"S16i4r4", __M2N_S16i4r4},
	{"S16i4r4r4", __M2N_S16i4r4r4},
	{"S16i4r4r4i4", __M2N_S16i4r4r4i4},
	{"S16i4r4r4r4", __M2N_S16i4r4r4r4},
	{"S16i4r4r4r4i4", __M2N_S16i4r4r4r4i4},
	{"S16i4S16", __M2N_S16i4S16},
	{"S16i4S16i4i4", __M2N_S16i4S16i4i4},
	{"S16i4S16i4i4i4", __M2N_S16i4S16i4i4i4},
	{"S16i4S16i4i4i4i4", __M2N_S16i4S16i4i4i4i4},
	{"S16i4S36i1", __M2N_S16i4S36i1},
	{"S16i4S36i1i1", __M2N_S16i4S36i1i1},
	{"S16i4S36S36i1", __M2N_S16i4S36S36i1},
	{"S16i4S36S36i1i1", __M2N_S16i4S36S36i1i1},
	{"S16i8", __M2N_S16i8},
	{"S16r4", __M2N_S16r4},
	{"S16r4i4", __M2N_S16r4i4},
	{"S16r4i4i4", __M2N_S16r4i4i4},
	{"S16r4r4", __M2N_S16r4r4},
	{"S16r4r4i4", __M2N_S16r4r4i4},
	{"S16r4r4i4i4", __M2N_S16r4r4i4i4},
	{"S16r4r4r4", __M2N_S16r4r4r4},
	{"S16r4r4r4i1", __M2N_S16r4r4r4i1},
	{"S16r4r4r4r4", __M2N_S16r4r4r4r4},
	{"S16r4r4r4r4i4", __M2N_S16r4r4r4r4i4},
	{"S16r4r4r4r4i4i4", __M2N_S16r4r4r4r4i4i4},
	{"S16r4r4r4r4r4r4", __M2N_S16r4r4r4r4r4r4},
	{"S16r4r4r4r4r4r4r4r4", __M2N_S16r4r4r4r4r4r4r4r4},
	{"S16r4S12", __M2N_S16r4S12},
	{"S16r4S16", __M2N_S16r4S16},
	{"S16r8", __M2N_S16r8},
	{"S16S12", __M2N_S16S12},
	{"S16S12r4", __M2N_S16S12r4},
	{"S16S12S12", __M2N_S16S12S12},
	{"S16S12S12S12", __M2N_S16S12S12S12},
	{"S16S12S16", __M2N_S16S12S16},
	{"S16S12S64", __M2N_S16S12S64},
	{"S16S16", __M2N_S16S16},
	{"S16S16i4", __M2N_S16S16i4},
	{"S16S16i4i4", __M2N_S16S16i4i4},
	{"S16S16r4", __M2N_S16S16r4},
	{"S16S16S12", __M2N_S16S16S12},
	{"S16S16S16", __M2N_S16S16S16},
	{"S16S16S16r4", __M2N_S16S16S16r4},
	{"S16S16S16S16", __M2N_S16S16S16S16},
	{"S16S16S64", __M2N_S16S16S64},
	{"S16S4", __M2N_S16S4},
	{"S16S64", __M2N_S16S64},
	{"S16S64S16", __M2N_S16S64S16},
	{"S16S8", __M2N_S16S8},
	{"S16S8S16", __M2N_S16S8S16},
	{"S16S8S64", __M2N_S16S8S64},
	{"S188i4", __M2N_S188i4},
	{"S1i4", __M2N_S1i4},
	{"S1i4i4", __M2N_S1i4i4},
	{"S1i4S1", __M2N_S1i4S1},
	{"S1S1", __M2N_S1S1},
	{"S2", __M2N_S2},
	{"S20", __M2N_S20},
	{"S20i4", __M2N_S20i4},
	{"S20i4i4", __M2N_S20i4i4},
	{"S20i4i4i4", __M2N_S20i4i4i4},
	{"S20i4S20", __M2N_S20i4S20},
	{"S20S20", __M2N_S20S20},
	{"S224i4", __M2N_S224i4},
	{"S24", __M2N_S24},
	{"S24C8", __M2N_S24C8},
	{"S24i2", __M2N_S24i2},
	{"S24i4", __M2N_S24i4},
	{"S24i4S12", __M2N_S24i4S12},
	{"S24i4S12i4", __M2N_S24i4S12i4},
	{"S24i4S64", __M2N_S24i4S64},
	{"S24r4", __M2N_S24r4},
	{"S24r4r4", __M2N_S24r4r4},
	{"S24r4r4S8", __M2N_S24r4r4S8},
	{"S24r4S8", __M2N_S24r4S8},
	{"S24S24", __M2N_S24S24},
	{"S24S24r4", __M2N_S24S24r4},
	{"S24S24S24", __M2N_S24S24S24},
	{"S24S24S24r4", __M2N_S24S24S24r4},
	{"S24S8", __M2N_S24S8},
	{"S24S8S8", __M2N_S24S8S8},
	{"S28", __M2N_S28},
	{"S28i4", __M2N_S28i4},
	{"S28i4i4", __M2N_S28i4i4},
	{"S28i4S28", __M2N_S28i4S28},
	{"S28S8", __M2N_S28S8},
	{"S2i4", __M2N_S2i4},
	{"S2i4i4", __M2N_S2i4i4},
	{"S2i4S2", __M2N_S2i4S2},
	{"S2S2", __M2N_S2S2},
	{"S3", __M2N_S3},
	{"S32i4", __M2N_S32i4},
	{"S32i4i1", __M2N_S32i4i1},
	{"S32i4i4", __M2N_S32i4i4},
	{"S36i4", __M2N_S36i4},
	{"S36i4i4", __M2N_S36i4i4},
	{"S36i4i4i4", __M2N_S36i4i4i4},
	{"S3i4", __M2N_S3i4},
	{"S3i4S3", __M2N_S3i4S3},
	{"S3S3", __M2N_S3S3},
	{"S4", __M2N_S4},
	{"S48", __M2N_S48},
	{"S48i4", __M2N_S48i4},
	{"S48i4i4", __M2N_S48i4i4},
	{"S4i2", __M2N_S4i2},
	{"S4i2S4", __M2N_S4i2S4},
	{"S4i4", __M2N_S4i4},
	{"S4i4i4", __M2N_S4i4i4},
	{"S4i4i4i4", __M2N_S4i4i4i4},
	{"S4i4i4i4i4", __M2N_S4i4i4i4i4},
	{"S4i4i4i4i4i4i4", __M2N_S4i4i4i4i4i4i4},
	{"S4i4i4S4", __M2N_S4i4i4S4},
	{"S4i4S4", __M2N_S4i4S4},
	{"S4i4S8", __M2N_S4i4S8},
	{"S4S12", __M2N_S4S12},
	{"S4S16", __M2N_S4S16},
	{"S4S4", __M2N_S4S4},
	{"S4S4S4r4", __M2N_S4S4S4r4},
	{"S5", __M2N_S5},
	{"S52i4", __M2N_S52i4},
	{"S5i4", __M2N_S5i4},
	{"S5i4S5", __M2N_S5i4S5},
	{"S5S5", __M2N_S5S5},
	{"S60i4", __M2N_S60i4},
	{"S60i4i1", __M2N_S60i4i1},
	{"S64", __M2N_S64},
	{"S64i4", __M2N_S64i4},
	{"S64i4i4", __M2N_S64i4i4},
	{"S64i4S16", __M2N_S64i4S16},
	{"S64r4", __M2N_S64r4},
	{"S64r4r4r4", __M2N_S64r4r4r4},
	{"S64r4r4r4r4", __M2N_S64r4r4r4r4},
	{"S64r4r4r4r4r4r4", __M2N_S64r4r4r4r4r4r4},
	{"S64r4r4r4S12", __M2N_S64r4r4r4S12},
	{"S64r4S12", __M2N_S64r4S12},
	{"S64S12", __M2N_S64S12},
	{"S64S12r4", __M2N_S64S12r4},
	{"S64S12S12", __M2N_S64S12S12},
	{"S64S12S12S12", __M2N_S64S12S12S12},
	{"S64S12S12S12S12", __M2N_S64S12S12S12S12},
	{"S64S12S12S12S12S12", __M2N_S64S12S12S12S12S12},
	{"S64S12S16", __M2N_S64S12S16},
	{"S64S12S16S12", __M2N_S64S12S16S12},
	{"S64S16", __M2N_S64S16},
	{"S64S24", __M2N_S64S24},
	{"S64S64", __M2N_S64S64},
	{"S64S64i1", __M2N_S64S64i1},
	{"S64S64r4", __M2N_S64S64r4},
	{"S64S64S16", __M2N_S64S64S16},
	{"S64S64S64", __M2N_S64S64S64},
	{"S64S64S64r4", __M2N_S64S64S64r4},
	{"S68", __M2N_S68},
	{"S68i4", __M2N_S68i4},
	{"S8", __M2N_S8},
	{"S8i1", __M2N_S8i1},
	{"S8i2", __M2N_S8i2},
	{"S8i4", __M2N_S8i4},
	{"S8i4i1", __M2N_S8i4i1},
	{"S8i4i4", __M2N_S8i4i4},
	{"S8i4i4i4", __M2N_S8i4i4i4},
	{"S8i4i4i4i4", __M2N_S8i4i4i4i4},
	{"S8i4i4i4i4i4i4i4i4i4", __M2N_S8i4i4i4i4i4i4i4i4i4},
	{"S8i4i4i4i4i4i4i4i4i4i4", __M2N_S8i4i4i4i4i4i4i4i4i4i4},
	{"S8i4i4i4i4i8i4", __M2N_S8i4i4i4i4i8i4},
	{"S8i4i4S240", __M2N_S8i4i4S240},
	{"S8i4r4", __M2N_S8i4r4},
	{"S8i4S12S4", __M2N_S8i4S12S4},
	{"S8i4S16i4i4", __M2N_S8i4S16i4i4},
	{"S8i4S240", __M2N_S8i4S240},
	{"S8i4S8", __M2N_S8i4S8},
	{"S8i4S8i4", __M2N_S8i4S8i4},
	{"S8i8", __M2N_S8i8},
	{"S8r4", __M2N_S8r4},
	{"S8r4S8", __M2N_S8r4S8},
	{"S8r8", __M2N_S8r8},
	{"S8S12", __M2N_S8S12},
	{"S8S12i4i4", __M2N_S8S12i4i4},
	{"S8S16", __M2N_S8S16},
	{"S8S16S8", __M2N_S8S16S8},
	{"S8S16S8S16", __M2N_S8S16S8S16},
	{"S8S16S8S16i1i1", __M2N_S8S16S8S16i1i1},
	{"S8S16S8S16i1i1i4i4", __M2N_S8S16S8S16i1i1i4i4},
	{"S8S16S8S16i1i1i4i4i4", __M2N_S8S16S8S16i1i1i4i4i4},
	{"S8S16S8S16i4i4", __M2N_S8S16S8S16i4i4},
	{"S8S32", __M2N_S8S32},
	{"S8S36", __M2N_S8S36},
	{"S8S8", __M2N_S8S8},
	{"S8S8i1i1i4", __M2N_S8S8i1i1i4},
	{"S8S8i1i1i4i4i4", __M2N_S8S8i1i1i4i4i4},
	{"S8S8i1i1i4i4i4i4", __M2N_S8S8i1i1i4i4i4i4},
	{"S8S8i4", __M2N_S8S8i4},
	{"S8S8i4i4", __M2N_S8S8i4i4},
	{"S8S8i4i4i4", __M2N_S8S8i4i4i4},
	{"S8S8r4", __M2N_S8S8r4},
	{"S8S8S16", __M2N_S8S8S16},
	{"S8S8S24", __M2N_S8S8S24},
	{"S8S8S64", __M2N_S8S8S64},
	{"S8S8S8", __M2N_S8S8S8},
	{"S8S8S8i4", __M2N_S8S8S8i4},
	{"S8S8S8i4r4", __M2N_S8S8S8i4r4},
	{"S8S8S8i4r4r4", __M2N_S8S8S8i4r4r4},
	{"S8S8S8i4r4r4r4", __M2N_S8S8S8i4r4r4r4},
	{"S8S8S8r4", __M2N_S8S8S8r4},
	{"S8S8S8S8", __M2N_S8S8S8S8},
	{"S9", __M2N_S9},
	{"S992i4", __M2N_S992i4},
	{"S9i4", __M2N_S9i4},
	{"S9i4S9", __M2N_S9i4S9},
	{"S9S9", __M2N_S9S9},
	{"v", __M2N_v},
	{"vC16", __M2N_vC16},
	{"vC16i4", __M2N_vC16i4},
	{"vC32", __M2N_vC32},
	{"vC8", __M2N_vC8},
	{"vi1", __M2N_vi1},
	{"vi1i1", __M2N_vi1i1},
	{"vi1i1i4", __M2N_vi1i1i4},
	{"vi1i1S16", __M2N_vi1i1S16},
	{"vi1i1S16r4", __M2N_vi1i1S16r4},
	{"vi1i4", __M2N_vi1i4},
	{"vi1i4i4", __M2N_vi1i4i4},
	{"vi1i4i4i4", __M2N_vi1i4i4i4},
	{"vi2", __M2N_vi2},
	{"vi2i2", __M2N_vi2i2},
	{"vi2i2i4", __M2N_vi2i2i4},
	{"vi4", __M2N_vi4},
	{"vi4C16", __M2N_vi4C16},
	{"vi4C16i4", __M2N_vi4C16i4},
	{"vi4C24", __M2N_vi4C24},
	{"vi4C32", __M2N_vi4C32},
	{"vi4C8", __M2N_vi4C8},
	{"vi4C8C8", __M2N_vi4C8C8},
	{"vi4C8C8C8", __M2N_vi4C8C8C8},
	{"vi4C8C8i1", __M2N_vi4C8C8i1},
	{"vi4C8C8i1i8", __M2N_vi4C8C8i1i8},
	{"vi4C8i4", __M2N_vi4C8i4},
	{"vi4C8i4i4", __M2N_vi4C8i4i4},
	{"vi4i1", __M2N_vi4i1},
	{"vi4i1i1", __M2N_vi4i1i1},
	{"vi4i1i1i1", __M2N_vi4i1i1i1},
	{"vi4i1i1i1i1", __M2N_vi4i1i1i1i1},
	{"vi4i1i1i1i4", __M2N_vi4i1i1i1i4},
	{"vi4i1i1i1i4i4i4i4", __M2N_vi4i1i1i1i4i4i4i4},
	{"vi4i1i1i1i4i4i4i4i4i4i4i4", __M2N_vi4i1i1i1i4i4i4i4i4i4i4i4},
	{"vi4i1i1i4", __M2N_vi4i1i1i4},
	{"vi4i1i1i4i1", __M2N_vi4i1i1i4i1},
	{"vi4i1i1i4i4", __M2N_vi4i1i1i4i4},
	{"vi4i1i1i4i4i4", __M2N_vi4i1i1i4i4i4},
	{"vi4i1i1i4i4i4i4i4", __M2N_vi4i1i1i4i4i4i4i4},
	{"vi4i1i1i4S8", __M2N_vi4i1i1i4S8},
	{"vi4i1i1r4r4r4r4", __M2N_vi4i1i1r4r4r4r4},
	{"vi4i1i1S16", __M2N_vi4i1i1S16},
	{"vi4i1i1S16r4", __M2N_vi4i1i1S16r4},
	{"vi4i1i4", __M2N_vi4i1i4},
	{"vi4i1i4i4", __M2N_vi4i1i4i4},
	{"vi4i1i4i4i4", __M2N_vi4i1i4i4i4},
	{"vi4i1i4i4i4i1i4", __M2N_vi4i1i4i4i4i1i4},
	{"vi4i1i4i4i4i4", __M2N_vi4i1i4i4i4i4},
	{"vi4i1i4i4i4i4i4", __M2N_vi4i1i4i4i4i4i4},
	{"vi4i1i4i4i4i4S16S16i1i4", __M2N_vi4i1i4i4i4i4S16S16i1i4},
	{"vi4i1i8", __M2N_vi4i1i8},
	{"vi4i2", __M2N_vi4i2},
	{"vi4i2i2", __M2N_vi4i2i2},
	{"vi4i2i4", __M2N_vi4i2i4},
	{"vi4i2i4i1i1i1", __M2N_vi4i2i4i1i1i1},
	{"vi4i4", __M2N_vi4i4},
	{"vi4i4C24", __M2N_vi4i4C24},
	{"vi4i4C64", __M2N_vi4i4C64},
	{"vi4i4C8", __M2N_vi4i4C8},
	{"vi4i4C8C8", __M2N_vi4i4C8C8},
	{"vi4i4C8C8C8", __M2N_vi4i4C8C8C8},
	{"vi4i4C8i4", __M2N_vi4i4C8i4},
	{"vi4i4i1", __M2N_vi4i4i1},
	{"vi4i4i1i1", __M2N_vi4i4i1i1},
	{"vi4i4i1i1i1", __M2N_vi4i4i1i1i1},
	{"vi4i4i1i1i1i1", __M2N_vi4i4i1i1i1i1},
	{"vi4i4i1i1i1i1i4i8", __M2N_vi4i4i1i1i1i1i4i8},
	{"vi4i4i1i1i4", __M2N_vi4i4i1i1i4},
	{"vi4i4i1i4", __M2N_vi4i4i1i4},
	{"vi4i4i1i4i1", __M2N_vi4i4i1i4i1},
	{"vi4i4i1i4i4", __M2N_vi4i4i1i4i4},
	{"vi4i4i1i4i4i4", __M2N_vi4i4i1i4i4i4},
	{"vi4i4i1i8i8i4i4", __M2N_vi4i4i1i8i8i4i4},
	{"vi4i4i2", __M2N_vi4i4i2},
	{"vi4i4i2i1", __M2N_vi4i4i2i1},
	{"vi4i4i2i2i1i1i1i1i1i1i1i1", __M2N_vi4i4i2i2i1i1i1i1i1i1i1i1},
	{"vi4i4i2i2i4", __M2N_vi4i4i2i2i4},
	{"vi4i4i4", __M2N_vi4i4i4},
	{"vi4i4i4C8", __M2N_vi4i4i4C8},
	{"vi4i4i4C8C8", __M2N_vi4i4i4C8C8},
	{"vi4i4i4i1", __M2N_vi4i4i4i1},
	{"vi4i4i4i1i1", __M2N_vi4i4i4i1i1},
	{"vi4i4i4i1i1i1", __M2N_vi4i4i4i1i1i1},
	{"vi4i4i4i1i1i1i1i4i4", __M2N_vi4i4i4i1i1i1i1i4i4},
	{"vi4i4i4i1i1i1i4", __M2N_vi4i4i4i1i1i1i4},
	{"vi4i4i4i1i1i4", __M2N_vi4i4i4i1i1i4},
	{"vi4i4i4i1i2i2i1", __M2N_vi4i4i4i1i2i2i1},
	{"vi4i4i4i1i4", __M2N_vi4i4i4i1i4},
	{"vi4i4i4i1i4i1", __M2N_vi4i4i4i1i4i1},
	{"vi4i4i4i1i4i4", __M2N_vi4i4i4i1i4i4},
	{"vi4i4i4i1i4i4i4", __M2N_vi4i4i4i1i4i4i4},
	{"vi4i4i4i1i4i4S16S16i4", __M2N_vi4i4i4i1i4i4S16S16i4},
	{"vi4i4i4i1i8i8i4i4", __M2N_vi4i4i4i1i8i8i4i4},
	{"vi4i4i4i1S8i4", __M2N_vi4i4i4i1S8i4},
	{"vi4i4i4i2i1", __M2N_vi4i4i4i2i1},
	{"vi4i4i4i2i4i4i4", __M2N_vi4i4i4i2i4i4i4},
	{"vi4i4i4i2i4i4i4i4", __M2N_vi4i4i4i2i4i4i4i4},
	{"vi4i4i4i4", __M2N_vi4i4i4i4},
	{"vi4i4i4i4i1", __M2N_vi4i4i4i4i1},
	{"vi4i4i4i4i1i1", __M2N_vi4i4i4i4i1i1},
	{"vi4i4i4i4i1i1i1i4i1", __M2N_vi4i4i4i4i1i1i1i4i1},
	{"vi4i4i4i4i1i1i4", __M2N_vi4i4i4i4i1i1i4},
	{"vi4i4i4i4i1i4", __M2N_vi4i4i4i4i1i4},
	{"vi4i4i4i4i1i4i4i4i1i1", __M2N_vi4i4i4i4i1i4i4i4i1i1},
	{"vi4i4i4i4i2", __M2N_vi4i4i4i4i2},
	{"vi4i4i4i4i2i4", __M2N_vi4i4i4i4i2i4},
	{"vi4i4i4i4i2i4i4i4i4", __M2N_vi4i4i4i4i2i4i4i4i4},
	{"vi4i4i4i4i4", __M2N_vi4i4i4i4i4},
	{"vi4i4i4i4i4i1", __M2N_vi4i4i4i4i4i1},
	{"vi4i4i4i4i4i1C8", __M2N_vi4i4i4i4i4i1C8},
	{"vi4i4i4i4i4i1i1", __M2N_vi4i4i4i4i4i1i1},
	{"vi4i4i4i4i4i1i4", __M2N_vi4i4i4i4i4i1i4},
	{"vi4i4i4i4i4i1i4i4i4", __M2N_vi4i4i4i4i4i1i4i4i4},
	{"vi4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i1", __M2N_vi4i4i4i4i4i4i1},
	{"vi4i4i4i4i4i4i1i4", __M2N_vi4i4i4i4i4i4i1i4},
	{"vi4i4i4i4i4i4i1i4i4", __M2N_vi4i4i4i4i4i4i1i4i4},
	{"vi4i4i4i4i4i4i1i4i4i4", __M2N_vi4i4i4i4i4i4i1i4i4i4},
	{"vi4i4i4i4i4i4i1i4i4i4i4", __M2N_vi4i4i4i4i4i4i1i4i4i4i4},
	{"vi4i4i4i4i4i4i2i4i4", __M2N_vi4i4i4i4i4i4i2i4i4},
	{"vi4i4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4C8", __M2N_vi4i4i4i4i4i4i4C8},
	{"vi4i4i4i4i4i4i4i1", __M2N_vi4i4i4i4i4i4i4i1},
	{"vi4i4i4i4i4i4i4i1i4", __M2N_vi4i4i4i4i4i4i4i1i4},
	{"vi4i4i4i4i4i4i4i1i4i4", __M2N_vi4i4i4i4i4i4i4i1i4i4},
	{"vi4i4i4i4i4i4i4i1i4i4i4", __M2N_vi4i4i4i4i4i4i4i1i4i4i4},
	{"vi4i4i4i4i4i4i4i1i4i4i4i4", __M2N_vi4i4i4i4i4i4i4i1i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4C8", __M2N_vi4i4i4i4i4i4i4i4C8},
	{"vi4i4i4i4i4i4i4i4i1", __M2N_vi4i4i4i4i4i4i4i4i1},
	{"vi4i4i4i4i4i4i4i4i1i4", __M2N_vi4i4i4i4i4i4i4i4i1i4},
	{"vi4i4i4i4i4i4i4i4i1i4i1", __M2N_vi4i4i4i4i4i4i4i4i1i4i1},
	{"vi4i4i4i4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4i4C8", __M2N_vi4i4i4i4i4i4i4i4i4C8},
	{"vi4i4i4i4i4i4i4i4i4i1", __M2N_vi4i4i4i4i4i4i4i4i4i1},
	{"vi4i4i4i4i4i4i4i4i4i1i1", __M2N_vi4i4i4i4i4i4i4i4i4i1i1},
	{"vi4i4i4i4i4i4i4i4i4i1i4", __M2N_vi4i4i4i4i4i4i4i4i4i1i4},
	{"vi4i4i4i4i4i4i4i4i4i1i4i1", __M2N_vi4i4i4i4i4i4i4i4i4i1i4i1},
	{"vi4i4i4i4i4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4i4i4i1", __M2N_vi4i4i4i4i4i4i4i4i4i4i1},
	{"vi4i4i4i4i4i4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4i4i4i4i4", __M2N_vi4i4i4i4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4S16S16", __M2N_vi4i4i4i4i4i4i4S16S16},
	{"vi4i4i4i4i4i8", __M2N_vi4i4i4i4i4i8},
	{"vi4i4i4i4i4i8i4", __M2N_vi4i4i4i4i4i8i4},
	{"vi4i4i4i4i4S16", __M2N_vi4i4i4i4i4S16},
	{"vi4i4i4i4S16", __M2N_vi4i4i4i4S16},
	{"vi4i4i4i4S16i4", __M2N_vi4i4i4i4S16i4},
	{"vi4i4i4i4S28", __M2N_vi4i4i4i4S28},
	{"vi4i4i4i4S28i4", __M2N_vi4i4i4i4S28i4},
	{"vi4i4i4i4S28i4i4", __M2N_vi4i4i4i4S28i4i4},
	{"vi4i4i4i4S36i4", __M2N_vi4i4i4i4S36i4},
	{"vi4i4i4i4S64i1i1i1i4i1", __M2N_vi4i4i4i4S64i1i1i1i4i1},
	{"vi4i4i4i8", __M2N_vi4i4i4i8},
	{"vi4i4i4i8i4", __M2N_vi4i4i4i8i4},
	{"vi4i4i4i8i8", __M2N_vi4i4i4i8i8},
	{"vi4i4i4r4", __M2N_vi4i4i4r4},
	{"vi4i4i4r4i1", __M2N_vi4i4i4r4i1},
	{"vi4i4i4S12", __M2N_vi4i4i4S12},
	{"vi4i4i4S16", __M2N_vi4i4i4S16},
	{"vi4i4i4S16i4", __M2N_vi4i4i4S16i4},
	{"vi4i4i4S24i4i4i4i1i4i4i4i4", __M2N_vi4i4i4S24i4i4i4i1i4i4i4i4},
	{"vi4i4i4S24i4i4i4i4i1i4i4i4", __M2N_vi4i4i4S24i4i4i4i4i1i4i4i4},
	{"vi4i4i4S24i4i4i4i4i1i4i4i4i4", __M2N_vi4i4i4S24i4i4i4i4i1i4i4i4i4},
	{"vi4i4i4S28", __M2N_vi4i4i4S28},
	{"vi4i4i4S28S28i4i4", __M2N_vi4i4i4S28S28i4i4},
	{"vi4i4i4S4", __M2N_vi4i4i4S4},
	{"vi4i4i4S4i4", __M2N_vi4i4i4S4i4},
	{"vi4i4i4S64", __M2N_vi4i4i4S64},
	{"vi4i4i4S8", __M2N_vi4i4i4S8},
	{"vi4i4i4S8i4", __M2N_vi4i4i4S8i4},
	{"vi4i4i8", __M2N_vi4i4i8},
	{"vi4i4i8i4", __M2N_vi4i4i8i4},
	{"vi4i4i8i4i4", __M2N_vi4i4i8i4i4},
	{"vi4i4i8i4i8i4", __M2N_vi4i4i8i4i8i4},
	{"vi4i4i8i4i8i4i4", __M2N_vi4i4i8i4i8i4i4},
	{"vi4i4i8i8", __M2N_vi4i4i8i8},
	{"vi4i4i8i8i4", __M2N_vi4i4i8i8i4},
	{"vi4i4i8i8i8", __M2N_vi4i4i8i8i8},
	{"vi4i4r4", __M2N_vi4i4r4},
	{"vi4i4r4i4", __M2N_vi4i4r4i4},
	{"vi4i4r4i4i4", __M2N_vi4i4r4i4i4},
	{"vi4i4r4i4i4i4", __M2N_vi4i4r4i4i4i4},
	{"vi4i4r4r4", __M2N_vi4i4r4r4},
	{"vi4i4r8", __M2N_vi4i4r8},
	{"vi4i4r8i4", __M2N_vi4i4r8i4},
	{"vi4i4S12", __M2N_vi4i4S12},
	{"vi4i4S12S16", __M2N_vi4i4S12S16},
	{"vi4i4S12S16S12", __M2N_vi4i4S12S16S12},
	{"vi4i4S16", __M2N_vi4i4S16},
	{"vi4i4S16i4", __M2N_vi4i4S16i4},
	{"vi4i4S1i4", __M2N_vi4i4S1i4},
	{"vi4i4S20", __M2N_vi4i4S20},
	{"vi4i4S24", __M2N_vi4i4S24},
	{"vi4i4S28", __M2N_vi4i4S28},
	{"vi4i4S28i1i1i1", __M2N_vi4i4S28i1i1i1},
	{"vi4i4S28i4", __M2N_vi4i4S28i4},
	{"vi4i4S28i4i4", __M2N_vi4i4S28i4i4},
	{"vi4i4S28i4i4i4", __M2N_vi4i4S28i4i4i4},
	{"vi4i4S28S8S8", __M2N_vi4i4S28S8S8},
	{"vi4i4S36", __M2N_vi4i4S36},
	{"vi4i4S36S36", __M2N_vi4i4S36S36},
	{"vi4i4S4", __M2N_vi4i4S4},
	{"vi4i4S48i4", __M2N_vi4i4S48i4},
	{"vi4i4S4i4", __M2N_vi4i4S4i4},
	{"vi4i4S52", __M2N_vi4i4S52},
	{"vi4i4S52i4", __M2N_vi4i4S52i4},
	{"vi4i4S64", __M2N_vi4i4S64},
	{"vi4i4S64i4", __M2N_vi4i4S64i4},
	{"vi4i4S64i4i4", __M2N_vi4i4S64i4i4},
	{"vi4i4S64i4i4i4", __M2N_vi4i4S64i4i4i4},
	{"vi4i4S64i4i4i4i4", __M2N_vi4i4S64i4i4i4i4},
	{"vi4i4S64i4i4i4i4i4", __M2N_vi4i4S64i4i4i4i4i4},
	{"vi4i4S64i4i4i4i4i4i4", __M2N_vi4i4S64i4i4i4i4i4i4},
	{"vi4i4S8", __M2N_vi4i4S8},
	{"vi4i4S8i4", __M2N_vi4i4S8i4},
	{"vi4i4S8i4i4", __M2N_vi4i4S8i4i4},
	{"vi4i4S8i4i4i4i4i4i4", __M2N_vi4i4S8i4i4i4i4i4i4},
	{"vi4i4S8S8", __M2N_vi4i4S8S8},
	{"vi4i4S8S8i4i4", __M2N_vi4i4S8S8i4i4},
	{"vi4i8", __M2N_vi4i8},
	{"vi4i8C8", __M2N_vi4i8C8},
	{"vi4i8i1", __M2N_vi4i8i1},
	{"vi4i8i2", __M2N_vi4i8i2},
	{"vi4i8i4", __M2N_vi4i8i4},
	{"vi4i8i4i4", __M2N_vi4i8i4i4},
	{"vi4i8i4i8", __M2N_vi4i8i4i8},
	{"vi4i8i4i8i8", __M2N_vi4i8i4i8i8},
	{"vi4i8i8", __M2N_vi4i8i8},
	{"vi4i8i8i1", __M2N_vi4i8i8i1},
	{"vi4i8i8i1i8", __M2N_vi4i8i8i1i8},
	{"vi4i8i8i4", __M2N_vi4i8i8i4},
	{"vi4i8i8i8i8i8i8i4", __M2N_vi4i8i8i8i8i8i8i4},
	{"vi4i8i8i8i8i8i8i4i8", __M2N_vi4i8i8i8i8i8i8i4i8},
	{"vi4i8r4", __M2N_vi4i8r4},
	{"vi4i8r8", __M2N_vi4i8r8},
	{"vi4i8S16", __M2N_vi4i8S16},
	{"vi4r4", __M2N_vi4r4},
	{"vi4r4i1", __M2N_vi4r4i1},
	{"vi4r4i4", __M2N_vi4r4i4},
	{"vi4r4r4", __M2N_vi4r4r4},
	{"vi4r4r4r4", __M2N_vi4r4r4r4},
	{"vi4r4r4r4i4", __M2N_vi4r4r4r4i4},
	{"vi4r4r4r4r4", __M2N_vi4r4r4r4r4},
	{"vi4r4r4r4r4r4r4", __M2N_vi4r4r4r4r4r4r4},
	{"vi4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4", __M2N_vi4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4},
	{"vi4r4S8S8r4r4S8", __M2N_vi4r4S8S8r4r4S8},
	{"vi4r8", __M2N_vi4r8},
	{"vi4r8i4", __M2N_vi4r8i4},
	{"vi4r8r8", __M2N_vi4r8r8},
	{"vi4S1", __M2N_vi4S1},
	{"vi4S12", __M2N_vi4S12},
	{"vi4S12i4", __M2N_vi4S12i4},
	{"vi4S12i4i4", __M2N_vi4S12i4i4},
	{"vi4S12i4i4i4", __M2N_vi4S12i4i4i4},
	{"vi4S12r4", __M2N_vi4S12r4},
	{"vi4S12r4i4", __M2N_vi4S12r4i4},
	{"vi4S12S12", __M2N_vi4S12S12},
	{"vi4S12S12r4", __M2N_vi4S12S12r4},
	{"vi4S12S12S12", __M2N_vi4S12S12S12},
	{"vi4S12S16", __M2N_vi4S12S16},
	{"vi4S12S16i4", __M2N_vi4S12S16i4},
	{"vi4S12S16i4i4", __M2N_vi4S12S16i4i4},
	{"vi4S12S16i4i4i4", __M2N_vi4S12S16i4i4i4},
	{"vi4S12S16i4i4i4i4", __M2N_vi4S12S16i4i4i4i4},
	{"vi4S12S16i4i4i4i4i4", __M2N_vi4S12S16i4i4i4i4i4},
	{"vi4S12S16i4i4i4i4i4i1", __M2N_vi4S12S16i4i4i4i4i4i1},
	{"vi4S12S16i4i4i4i4i4i1i1", __M2N_vi4S12S16i4i4i4i4i4i1i1},
	{"vi4S12S16i4i4i4i4i4i1i1i1", __M2N_vi4S12S16i4i4i4i4i4i1i1i1},
	{"vi4S12S16i4i4i4i4i4i4", __M2N_vi4S12S16i4i4i4i4i4i4},
	{"vi4S12S16i4i4i4i4i4i4i1", __M2N_vi4S12S16i4i4i4i4i4i4i1},
	{"vi4S12S16i4i4i4i4i4i4i1i4", __M2N_vi4S12S16i4i4i4i4i4i4i1i4},
	{"vi4S12S16i4i4i4i4i4i4i1i4i1", __M2N_vi4S12S16i4i4i4i4i4i4i1i4i1},
	{"vi4S12S16r4", __M2N_vi4S12S16r4},
	{"vi4S12S16S12", __M2N_vi4S12S16S12},
	{"vi4S16", __M2N_vi4S16},
	{"vi4S16i1i1i1i1", __M2N_vi4S16i1i1i1i1},
	{"vi4S16i4", __M2N_vi4S16i4},
	{"vi4S16i4i1i1i1i1", __M2N_vi4S16i4i1i1i1i1},
	{"vi4S16i4i4", __M2N_vi4S16i4i4},
	{"vi4S16i4i4i1", __M2N_vi4S16i4i4i1},
	{"vi4S16i4i4i1i1", __M2N_vi4S16i4i4i1i1},
	{"vi4S16i4i4i4", __M2N_vi4S16i4i4i4},
	{"vi4S16i4i4i4i4", __M2N_vi4S16i4i4i4i4},
	{"vi4S16r4", __M2N_vi4S16r4},
	{"vi4S16r4i4", __M2N_vi4S16r4i4},
	{"vi4S16r4i4i4", __M2N_vi4S16r4i4i4},
	{"vi4S16S16", __M2N_vi4S16S16},
	{"vi4S16S16i4", __M2N_vi4S16S16i4},
	{"vi4S16S16S16S16", __M2N_vi4S16S16S16S16},
	{"vi4S16S8S16", __M2N_vi4S16S8S16},
	{"vi4S16S8S16i1i1", __M2N_vi4S16S8S16i1i1},
	{"vi4S16S8S16i1i1i4i4", __M2N_vi4S16S8S16i1i1i4i4},
	{"vi4S16S8S16i4i4", __M2N_vi4S16S8S16i4i4},
	{"vi4S188", __M2N_vi4S188},
	{"vi4S1i4", __M2N_vi4S1i4},
	{"vi4S2", __M2N_vi4S2},
	{"vi4S20", __M2N_vi4S20},
	{"vi4S20i4", __M2N_vi4S20i4},
	{"vi4S20i4i4", __M2N_vi4S20i4i4},
	{"vi4S20i4i4i4", __M2N_vi4S20i4i4i4},
	{"vi4S20i4i4S36S36", __M2N_vi4S20i4i4S36S36},
	{"vi4S20i4i4S4i1S36S36", __M2N_vi4S20i4i4S4i1S36S36},
	{"vi4S224", __M2N_vi4S224},
	{"vi4S24", __M2N_vi4S24},
	{"vi4S24i4i4i4i4i4i4i1i4", __M2N_vi4S24i4i4i4i4i4i4i1i4},
	{"vi4S24i4i4i4i4i4i4i4i1i4", __M2N_vi4S24i4i4i4i4i4i4i4i1i4},
	{"vi4S28", __M2N_vi4S28},
	{"vi4S28i1", __M2N_vi4S28i1},
	{"vi4S28i1i1", __M2N_vi4S28i1i1},
	{"vi4S28i4", __M2N_vi4S28i4},
	{"vi4S28i4i4", __M2N_vi4S28i4i4},
	{"vi4S28i4i4i4", __M2N_vi4S28i4i4i4},
	{"vi4S28i4i4i4i4", __M2N_vi4S28i4i4i4i4},
	{"vi4S28i4i4i4i4i4i4i4", __M2N_vi4S28i4i4i4i4i4i4i4},
	{"vi4S28i4i4i4i4i4i4S28i4i4i4i4", __M2N_vi4S28i4i4i4i4i4i4S28i4i4i4i4},
	{"vi4S28i4i4S28i4i4", __M2N_vi4S28i4i4S28i4i4},
	{"vi4S28i4r4i1", __M2N_vi4S28i4r4i1},
	{"vi4S28i4S28i4", __M2N_vi4S28i4S28i4},
	{"vi4S28S28", __M2N_vi4S28S28},
	{"vi4S28S28i4", __M2N_vi4S28S28i4},
	{"vi4S28S28i4i4", __M2N_vi4S28S28i4i4},
	{"vi4S28S28i4i4i4", __M2N_vi4S28S28i4i4i4},
	{"vi4S28S28S8S8", __M2N_vi4S28S28S8S8},
	{"vi4S28S28S8S8i4i4", __M2N_vi4S28S28S8S8i4i4},
	{"vi4S2i4", __M2N_vi4S2i4},
	{"vi4S2i4i4", __M2N_vi4S2i4i4},
	{"vi4S2i4i4i4", __M2N_vi4S2i4i4i4},
	{"vi4S2i4i4i4i4", __M2N_vi4S2i4i4i4i4},
	{"vi4S32", __M2N_vi4S32},
	{"vi4S36", __M2N_vi4S36},
	{"vi4S36i1", __M2N_vi4S36i1},
	{"vi4S36i1i1", __M2N_vi4S36i1i1},
	{"vi4S36i4i1", __M2N_vi4S36i4i1},
	{"vi4S36S36", __M2N_vi4S36S36},
	{"vi4S36S36i1", __M2N_vi4S36S36i1},
	{"vi4S36S36i1i1", __M2N_vi4S36S36i1i1},
	{"vi4S36S36S36S28", __M2N_vi4S36S36S36S28},
	{"vi4S36S36S36S28S64r4", __M2N_vi4S36S36S36S28S64r4},
	{"vi4S4", __M2N_vi4S4},
	{"vi4S40", __M2N_vi4S40},
	{"vi4S48", __M2N_vi4S48},
	{"vi4S4i4", __M2N_vi4S4i4},
	{"vi4S4i4i4", __M2N_vi4S4i4i4},
	{"vi4S4i4i4i4", __M2N_vi4S4i4i4i4},
	{"vi4S4i4i4i4i4i4i4i4", __M2N_vi4S4i4i4i4i4i4i4i4},
	{"vi4S4S224", __M2N_vi4S4S224},
	{"vi4S5", __M2N_vi4S5},
	{"vi4S52", __M2N_vi4S52},
	{"vi4S52i4i4i4", __M2N_vi4S52i4i4i4},
	{"vi4S60", __M2N_vi4S60},
	{"vi4S64", __M2N_vi4S64},
	{"vi4S64i4", __M2N_vi4S64i4},
	{"vi4S64i4i4", __M2N_vi4S64i4i4},
	{"vi4S64i4i4i4", __M2N_vi4S64i4i4i4},
	{"vi4S64i4i4i4i4", __M2N_vi4S64i4i4i4i4},
	{"vi4S64i4i4i4i4i4", __M2N_vi4S64i4i4i4i4i4},
	{"vi4S64i4i4i4i4i4i1", __M2N_vi4S64i4i4i4i4i4i1},
	{"vi4S64i4i4i4i4i4i1i1", __M2N_vi4S64i4i4i4i4i4i1i1},
	{"vi4S64i4i4i4i4i4i1i1i1", __M2N_vi4S64i4i4i4i4i4i1i1i1},
	{"vi4S64i4i4i4i4i4i4", __M2N_vi4S64i4i4i4i4i4i4},
	{"vi4S64i4i4i4i4i4i4i1", __M2N_vi4S64i4i4i4i4i4i4i1},
	{"vi4S64i4i4i4i4i4i4i1i4", __M2N_vi4S64i4i4i4i4i4i4i1i4},
	{"vi4S64i4i4i4i4i4i4i1i4i1", __M2N_vi4S64i4i4i4i4i4i4i1i4i1},
	{"vi4S64i4i4i4i4i4i4i1i4i4", __M2N_vi4S64i4i4i4i4i4i4i1i4i4},
	{"vi4S64i4i4i4i4i4i4i1i4i4i4", __M2N_vi4S64i4i4i4i4i4i4i1i4i4i4},
	{"vi4S64S16", __M2N_vi4S64S16},
	{"vi4S64S64", __M2N_vi4S64S64},
	{"vi4S68", __M2N_vi4S68},
	{"vi4S8", __M2N_vi4S8},
	{"vi4S8C56", __M2N_vi4S8C56},
	{"vi4S8C56i4", __M2N_vi4S8C56i4},
	{"vi4S8i1", __M2N_vi4S8i1},
	{"vi4S8i1i1i4", __M2N_vi4S8i1i1i4},
	{"vi4S8i1i1i4i4i4", __M2N_vi4S8i1i1i4i4i4},
	{"vi4S8i1i1i4i4i4i4", __M2N_vi4S8i1i1i4i4i4i4},
	{"vi4S8i2", __M2N_vi4S8i2},
	{"vi4S8i4", __M2N_vi4S8i4},
	{"vi4S8i4i4", __M2N_vi4S8i4i4},
	{"vi4S8i4i4i4", __M2N_vi4S8i4i4i4},
	{"vi4S8i4i4i4i4", __M2N_vi4S8i4i4i4i4},
	{"vi4S8i8", __M2N_vi4S8i8},
	{"vi4S8r4", __M2N_vi4S8r4},
	{"vi4S8r4r4", __M2N_vi4S8r4r4},
	{"vi4S8r8", __M2N_vi4S8r8},
	{"vi4S8S4", __M2N_vi4S8S4},
	{"vi4S8S8", __M2N_vi4S8S8},
	{"vi4S8S8i4", __M2N_vi4S8S8i4},
	{"vi4S8S8i4i4", __M2N_vi4S8S8i4i4},
	{"vi4S8S8i4i4i4", __M2N_vi4S8S8i4i4i4},
	{"vi4S9", __M2N_vi4S9},
	{"vi4S992", __M2N_vi4S992},
	{"vi8", __M2N_vi8},
	{"vi8i8", __M2N_vi8i8},
	{"vi8i8i4", __M2N_vi8i8i4},
	{"vr4", __M2N_vr4},
	{"vr4r4", __M2N_vr4r4},
	{"vr4r4i4", __M2N_vr4r4i4},
	{"vr4r4r4", __M2N_vr4r4r4},
	{"vr4r4r4i4", __M2N_vr4r4r4i4},
	{"vr4r4r4r4", __M2N_vr4r4r4r4},
	{"vr4S8", __M2N_vr4S8},
	{"vr8", __M2N_vr8},
	{"vr8r8", __M2N_vr8r8},
	{"vr8r8i4", __M2N_vr8r8i4},
	{"vS1", __M2N_vS1},
	{"vS108", __M2N_vS108},
	{"vS12", __M2N_vS12},
	{"vS12i1", __M2N_vS12i1},
	{"vS12i2", __M2N_vS12i2},
	{"vS12i4", __M2N_vS12i4},
	{"vS12i4i1", __M2N_vS12i4i1},
	{"vS12i4i1S16", __M2N_vS12i4i1S16},
	{"vS12i4i4", __M2N_vS12i4i4},
	{"vS12i8", __M2N_vS12i8},
	{"vS12r4", __M2N_vS12r4},
	{"vS12r4r4r4r4", __M2N_vS12r4r4r4r4},
	{"vS12S12", __M2N_vS12S12},
	{"vS12S12S16", __M2N_vS12S12S16},
	{"vS12S12S16r4", __M2N_vS12S12S16r4},
	{"vS12S12S16r4i1", __M2N_vS12S12S16r4i1},
	{"vS16", __M2N_vS16},
	{"vS16i4", __M2N_vS16i4},
	{"vS16i4i4", __M2N_vS16i4i4},
	{"vS16i4i4i1", __M2N_vS16i4i4i1},
	{"vS16i4i4i1r4", __M2N_vS16i4i4i1r4},
	{"vS16i4i4i1r4S16r4r4", __M2N_vS16i4i4i1r4S16r4r4},
	{"vS16i4i4i1r4S16S16r4", __M2N_vS16i4i4i1r4S16S16r4},
	{"vS16i4i4i1r4S16S16S16", __M2N_vS16i4i4i1r4S16S16S16},
	{"vS16i4i4i4", __M2N_vS16i4i4i4},
	{"vS16i4i4i4i4i4", __M2N_vS16i4i4i4i4i4},
	{"vS16i4i4i4i4i4i4", __M2N_vS16i4i4i4i4i4i4},
	{"vS16i4i4i4i4i4i4i4", __M2N_vS16i4i4i4i4i4i4i4},
	{"vS16i4S16", __M2N_vS16i4S16},
	{"vS16i4S16i1", __M2N_vS16i4S16i1},
	{"vS16i4S16i4i4i4i4", __M2N_vS16i4S16i4i4i4i4},
	{"vS16i4S16i4i4i4i4i4", __M2N_vS16i4S16i4i4i4i4i4},
	{"vS16i4S16i4i4i4i4i4i4", __M2N_vS16i4S16i4i4i4i4i4i4},
	{"vS16i4S16i4i4i4i4S16", __M2N_vS16i4S16i4i4i4i4S16},
	{"vS16i4S16i4i4i4i4S16i4", __M2N_vS16i4S16i4i4i4i4S16i4},
	{"vS16i4S16i4i4i4i4S16i4i4", __M2N_vS16i4S16i4i4i4i4S16i4i4},
	{"vS16S8S8i1", __M2N_vS16S8S8i1},
	{"vS1i1", __M2N_vS1i1},
	{"vS1i4", __M2N_vS1i4},
	{"vS1i4i1", __M2N_vS1i4i1},
	{"vS20", __M2N_vS20},
	{"vS24", __M2N_vS24},
	{"vS32i4i4", __M2N_vS32i4i4},
	{"vS36", __M2N_vS36},
	{"vS36i4", __M2N_vS36i4},
	{"vS4", __M2N_vS4},
	{"vS40", __M2N_vS40},
	{"vS4i4", __M2N_vS4i4},
	{"vS4S4", __M2N_vS4S4},
	{"vS64", __M2N_vS64},
	{"vS64i4", __M2N_vS64i4},
	{"vS8", __M2N_vS8},
	{"vS8S8", __M2N_vS8S8},
	{"vS8S8i4", __M2N_vS8S8i4},
	{"vS8S8i4i4", __M2N_vS8S8i4i4},
	{"vS8S8i4i4i4", __M2N_vS8S8i4i4i4},
	{nullptr, nullptr},
};

static ValueTypeSizeAlign8<16> __N2M_C16(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_C16C16(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_C16i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_C16i4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<24> __N2M_C24(const MethodInfo* method)
{
    StackObject args[3] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<24>*)ret;
}


static ValueTypeSizeAlign8<24> __N2M_C24C24(ValueTypeSizeAlign8<24> __arg0, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<24>*)ret;
}


static ValueTypeSizeAlign8<24> __N2M_C24i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<24>*)ret;
}


static ValueTypeSizeAlign8<24> __N2M_C24i4C24(int32_t __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<24>*)ret;
}


static ValueTypeSizeAlign8<32> __N2M_C32(const MethodInfo* method)
{
    StackObject args[4] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<32>*)ret;
}


static ValueTypeSizeAlign8<32> __N2M_C32C32(ValueTypeSizeAlign8<32> __arg0, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<32>*)ret;
}


static ValueTypeSizeAlign8<32> __N2M_C32i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<32>*)ret;
}


static ValueTypeSizeAlign8<32> __N2M_C32i4C32(int32_t __arg0, ValueTypeSizeAlign8<32> __arg1, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<32>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8C8(ValueTypeSizeAlign8<8> __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8C8i4i4(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4C8i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4C8i4i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4C8r8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_C8i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static int8_t __N2M_i1(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4C1568(int32_t __arg0, ValueTypeSizeAlign8<1568> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4C24(int32_t __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4C8i1(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i2i2i4(int32_t __arg0, int16_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i2i4(int32_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4i4i4S4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, ValueTypeSize<4> __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4i4i4S4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, ValueTypeSize<4> __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4S4(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i4i4S4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4r4r4(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S1(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S108(int32_t __arg0, ValueTypeSize<108> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S116(int32_t __arg0, ValueTypeSize<116> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S136(int32_t __arg0, ValueTypeSize<136> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S16i4(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S16i4i4i4i4i4(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S188(int32_t __arg0, ValueTypeSize<188> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S2(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S20(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S216(int32_t __arg0, ValueTypeSize<216> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S224(int32_t __arg0, ValueTypeSize<224> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S24(int32_t __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S28(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S312(int32_t __arg0, ValueTypeSize<312> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S32(int32_t __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S64(int32_t __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S68(int32_t __arg0, ValueTypeSize<68> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S8S8(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S92(int32_t __arg0, ValueTypeSize<92> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_i1i4S992(int32_t __arg0, ValueTypeSize<992> __arg1, const MethodInfo* method)
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


static int16_t __N2M_i2i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int16_t __N2M_i2i4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int16_t __N2M_i2i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
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


static int32_t __N2M_i4C8C8i4i4i4i4i4(ValueTypeSizeAlign8<8> __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4C8i4i4i4(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4C8i4i4i4i4i4(ValueTypeSizeAlign8<8> __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
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


static int32_t __N2M_i4i4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4C8C8i4i4i4i4i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4C8i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4C8i4i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4C8i4i4i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4C8i4i4i4i4i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i2i2(int32_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4C8i4(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4C8i4i4(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i1i4i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i4i1i4i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i1i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i2(int32_t __arg0, int32_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i2i4(int32_t __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i2i4i4(int32_t __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i2i4i4i4(int32_t __arg0, int32_t __arg1, int16_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i1i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i1i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i1i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[11] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = args + 10;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i1i4i4i4S16S16(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSize<16> __arg7, ValueTypeSize<16> __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, (uint64_t)&__arg7, (uint64_t)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i1i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int8_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = args + 8;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int8_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = args + 9;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[11] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = args + 10;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4S4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<4> __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4i4S4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<4> __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4S4(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4i4S8i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4S16S16S16(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<16> __arg3, ValueTypeSize<16> __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3, (uint64_t)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4S4(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4S4i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4S4i4i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4S4i4i4i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i4S8i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S1(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S12i4i1S4(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int8_t __arg3, ValueTypeSize<4> __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S12S4(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S20(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S4i4(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S8i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S8S12i4i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<12> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4i4S8S12i8i8i4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<12> __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4S8S12i4i4i4(ValueTypeSize<8> __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_i4S8S12i8i8i4(ValueTypeSize<8> __arg0, ValueTypeSize<12> __arg1, int64_t __arg2, int64_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
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


static int64_t __N2M_i8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static int64_t __N2M_i8i4i8i4(int32_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
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


static float __N2M_r4(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_r4i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
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


static double __N2M_r8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static double __N2M_r8i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
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


static ValueTypeSize<1> __N2M_S1(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<1>*)ret;
}


static ValueTypeSize<12> __N2M_S12(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_S12i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_S12i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_S12i4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_S12S12(ValueTypeSize<12> __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<16> __N2M_S16(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_S16i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_S16i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_S16i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_S16i4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_S16S16(ValueTypeSize<16> __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<1> __N2M_S1i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<1>*)ret;
}


static ValueTypeSize<1> __N2M_S1i4S1(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<1>*)ret;
}


static ValueTypeSize<1> __N2M_S1S1(ValueTypeSize<1> __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<1>*)ret;
}


static ValueTypeSize<2> __N2M_S2(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<2>*)ret;
}


static ValueTypeSize<20> __N2M_S20(const MethodInfo* method)
{
    StackObject args[3] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20i4S20(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_S20S20(ValueTypeSize<20> __arg0, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<2> __N2M_S2i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<2>*)ret;
}


static ValueTypeSize<2> __N2M_S2i4S2(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<2>*)ret;
}


static ValueTypeSize<2> __N2M_S2S2(ValueTypeSize<2> __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<2>*)ret;
}


static ValueTypeSize<3> __N2M_S3(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<3>*)ret;
}


static ValueTypeSize<32> __N2M_S32i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<32>*)ret;
}


static ValueTypeSize<3> __N2M_S3i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<3>*)ret;
}


static ValueTypeSize<3> __N2M_S3i4S3(int32_t __arg0, ValueTypeSize<3> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<3>*)ret;
}


static ValueTypeSize<3> __N2M_S3S3(ValueTypeSize<3> __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<3>*)ret;
}


static ValueTypeSize<4> __N2M_S4(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<4> __N2M_S4i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<4> __N2M_S4i4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<4> __N2M_S4S4(ValueTypeSize<4> __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<5> __N2M_S5(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<5>*)ret;
}


static ValueTypeSize<5> __N2M_S5i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<5>*)ret;
}


static ValueTypeSize<5> __N2M_S5i4S5(int32_t __arg0, ValueTypeSize<5> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<5>*)ret;
}


static ValueTypeSize<5> __N2M_S5S5(ValueTypeSize<5> __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<5>*)ret;
}


static ValueTypeSize<60> __N2M_S60i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<60>*)ret;
}


static ValueTypeSize<60> __N2M_S60i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<60>*)ret;
}


static ValueTypeSize<8> __N2M_S8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_S8i4i4S240(int32_t __arg0, int32_t __arg1, ValueTypeSize<240> __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_S8i4S12S4(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_S8i4S240(int32_t __arg0, ValueTypeSize<240> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_S8i4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_S8i4S8i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_S8S8i4(ValueTypeSize<8> __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<9> __N2M_S9(const MethodInfo* method)
{
    StackObject args[2] = { };
    StackObject* ret = args + 0;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<9>*)ret;
}


static ValueTypeSize<9> __N2M_S9i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<9>*)ret;
}


static ValueTypeSize<9> __N2M_S9i4S9(int32_t __arg0, ValueTypeSize<9> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<9>*)ret;
}


static ValueTypeSize<9> __N2M_S9S9(ValueTypeSize<9> __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)&__arg0 };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<9>*)ret;
}


static void __N2M_v(const MethodInfo* method)
{
    StackObject args[1] = { };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vC16(ValueTypeSizeAlign8<16> __arg0, const MethodInfo* method)
{
    StackObject args[1] = {(uint64_t)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vC16i4(ValueTypeSizeAlign8<16> __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vC32(ValueTypeSizeAlign8<32> __arg0, const MethodInfo* method)
{
    StackObject args[1] = {(uint64_t)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi1i4(int8_t __arg0, int32_t __arg1, const MethodInfo* method)
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


static void __N2M_vi4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4C16i4(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4C32(int32_t __arg0, ValueTypeSizeAlign8<32> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4C8i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i1i4(int32_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i1i4i4(int32_t __arg0, int8_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i2i2(int32_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i2i4(int32_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4C8(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4C8i4(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i1i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i1i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i1i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i1i8i8i4i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int64_t __arg3, int64_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i1i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i1i8i8i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, int64_t __arg4, int64_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i2i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int16_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i2i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int16_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i2i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int16_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i1i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int8_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i4i4i1i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int8_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, const MethodInfo* method)
{
    StackObject args[11] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[10] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4i4i4S16(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, ValueTypeSize<16> __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, (uint64_t)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4S12(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i4S8(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i8(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4i8i4i4(int32_t __arg0, int32_t __arg1, int64_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4S12(int32_t __arg0, int32_t __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4S20(int32_t __arg0, int32_t __arg1, ValueTypeSize<20> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4S36(int32_t __arg0, int32_t __arg1, ValueTypeSize<36> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4S8(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i4S8i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8i4(int32_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8i4i4(int32_t __arg0, int64_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8i4i8(int32_t __arg0, int64_t __arg1, int32_t __arg2, int64_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8i8(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4i8i8i4(int32_t __arg0, int64_t __arg1, int64_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4r4i4(int32_t __arg0, float __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4r8i4(int32_t __arg0, double __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S12i4(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S16i4(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S16i4i4(int32_t __arg0, ValueTypeSize<16> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S20(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S32(int32_t __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S36(int32_t __arg0, ValueTypeSize<36> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S48(int32_t __arg0, ValueTypeSize<48> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S4i4i4(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S4i4i4i4i4i4i4i4(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S60(int32_t __arg0, ValueTypeSize<60> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8C56(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSizeAlign8<56> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8C56i4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSizeAlign8<56> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i1(int32_t __arg0, ValueTypeSize<8> __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i2(int32_t __arg0, ValueTypeSize<8> __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i4i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i4i4i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8i8(int32_t __arg0, ValueTypeSize<8> __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8r4(int32_t __arg0, ValueTypeSize<8> __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8r8(int32_t __arg0, ValueTypeSize<8> __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8S4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vi4S8S8(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {*(uint64_t*)&__arg0, *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_vS8(ValueTypeSize<8> __arg0, const MethodInfo* method)
{
    StackObject args[1] = {*(uint64_t*)&__arg0 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


Native2ManagedMethodInfo hybridclr::interpreter::g_native2managedStub[] = 
{

	{"C16", (Il2CppMethodPointer)__N2M_C16},
	{"C16C16", (Il2CppMethodPointer)__N2M_C16C16},
	{"C16i4", (Il2CppMethodPointer)__N2M_C16i4},
	{"C16i4C16", (Il2CppMethodPointer)__N2M_C16i4C16},
	{"C24", (Il2CppMethodPointer)__N2M_C24},
	{"C24C24", (Il2CppMethodPointer)__N2M_C24C24},
	{"C24i4", (Il2CppMethodPointer)__N2M_C24i4},
	{"C24i4C24", (Il2CppMethodPointer)__N2M_C24i4C24},
	{"C32", (Il2CppMethodPointer)__N2M_C32},
	{"C32C32", (Il2CppMethodPointer)__N2M_C32C32},
	{"C32i4", (Il2CppMethodPointer)__N2M_C32i4},
	{"C32i4C32", (Il2CppMethodPointer)__N2M_C32i4C32},
	{"C8", (Il2CppMethodPointer)__N2M_C8},
	{"C8C8", (Il2CppMethodPointer)__N2M_C8C8},
	{"C8C8i4i4", (Il2CppMethodPointer)__N2M_C8C8i4i4},
	{"C8i4", (Il2CppMethodPointer)__N2M_C8i4},
	{"C8i4C8", (Il2CppMethodPointer)__N2M_C8i4C8},
	{"C8i4C8i4", (Il2CppMethodPointer)__N2M_C8i4C8i4},
	{"C8i4C8i4i4", (Il2CppMethodPointer)__N2M_C8i4C8i4i4},
	{"C8i4C8r8", (Il2CppMethodPointer)__N2M_C8i4C8r8},
	{"C8i4i4", (Il2CppMethodPointer)__N2M_C8i4i4},
	{"C8i4i4i4", (Il2CppMethodPointer)__N2M_C8i4i4i4},
	{"C8i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_C8i4i4i4i4i4i4i4i4},
	{"C8i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_C8i4i4i4i4i4i4i4i4i4},
	{"i1", (Il2CppMethodPointer)__N2M_i1},
	{"i1i4", (Il2CppMethodPointer)__N2M_i1i4},
	{"i1i4C1568", (Il2CppMethodPointer)__N2M_i1i4C1568},
	{"i1i4C16", (Il2CppMethodPointer)__N2M_i1i4C16},
	{"i1i4C24", (Il2CppMethodPointer)__N2M_i1i4C24},
	{"i1i4C8", (Il2CppMethodPointer)__N2M_i1i4C8},
	{"i1i4C8i1", (Il2CppMethodPointer)__N2M_i1i4C8i1},
	{"i1i4i1", (Il2CppMethodPointer)__N2M_i1i4i1},
	{"i1i4i2", (Il2CppMethodPointer)__N2M_i1i4i2},
	{"i1i4i2i2i4", (Il2CppMethodPointer)__N2M_i1i4i2i2i4},
	{"i1i4i2i4", (Il2CppMethodPointer)__N2M_i1i4i2i4},
	{"i1i4i4", (Il2CppMethodPointer)__N2M_i1i4i4},
	{"i1i4i4i1", (Il2CppMethodPointer)__N2M_i1i4i4i1},
	{"i1i4i4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4},
	{"i1i4i4i4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4i4},
	{"i1i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4i4i4},
	{"i1i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4i4i4i4},
	{"i1i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4i4i4i4i4i4i4},
	{"i1i4i4i4i4i4S4", (Il2CppMethodPointer)__N2M_i1i4i4i4i4i4S4},
	{"i1i4i4i4i4i4S4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4i4i4S4i4},
	{"i1i4i4i4S4", (Il2CppMethodPointer)__N2M_i1i4i4i4S4},
	{"i1i4i4i4S4i4", (Il2CppMethodPointer)__N2M_i1i4i4i4S4i4},
	{"i1i4i8", (Il2CppMethodPointer)__N2M_i1i4i8},
	{"i1i4r4", (Il2CppMethodPointer)__N2M_i1i4r4},
	{"i1i4r4r4", (Il2CppMethodPointer)__N2M_i1i4r4r4},
	{"i1i4r8", (Il2CppMethodPointer)__N2M_i1i4r8},
	{"i1i4S1", (Il2CppMethodPointer)__N2M_i1i4S1},
	{"i1i4S108", (Il2CppMethodPointer)__N2M_i1i4S108},
	{"i1i4S116", (Il2CppMethodPointer)__N2M_i1i4S116},
	{"i1i4S12", (Il2CppMethodPointer)__N2M_i1i4S12},
	{"i1i4S136", (Il2CppMethodPointer)__N2M_i1i4S136},
	{"i1i4S16", (Il2CppMethodPointer)__N2M_i1i4S16},
	{"i1i4S16i4", (Il2CppMethodPointer)__N2M_i1i4S16i4},
	{"i1i4S16i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i1i4S16i4i4i4i4i4},
	{"i1i4S188", (Il2CppMethodPointer)__N2M_i1i4S188},
	{"i1i4S2", (Il2CppMethodPointer)__N2M_i1i4S2},
	{"i1i4S20", (Il2CppMethodPointer)__N2M_i1i4S20},
	{"i1i4S216", (Il2CppMethodPointer)__N2M_i1i4S216},
	{"i1i4S224", (Il2CppMethodPointer)__N2M_i1i4S224},
	{"i1i4S24", (Il2CppMethodPointer)__N2M_i1i4S24},
	{"i1i4S28", (Il2CppMethodPointer)__N2M_i1i4S28},
	{"i1i4S312", (Il2CppMethodPointer)__N2M_i1i4S312},
	{"i1i4S32", (Il2CppMethodPointer)__N2M_i1i4S32},
	{"i1i4S4", (Il2CppMethodPointer)__N2M_i1i4S4},
	{"i1i4S64", (Il2CppMethodPointer)__N2M_i1i4S64},
	{"i1i4S68", (Il2CppMethodPointer)__N2M_i1i4S68},
	{"i1i4S8", (Il2CppMethodPointer)__N2M_i1i4S8},
	{"i1i4S8S8", (Il2CppMethodPointer)__N2M_i1i4S8S8},
	{"i1i4S92", (Il2CppMethodPointer)__N2M_i1i4S92},
	{"i1i4S992", (Il2CppMethodPointer)__N2M_i1i4S992},
	{"i2", (Il2CppMethodPointer)__N2M_i2},
	{"i2i4", (Il2CppMethodPointer)__N2M_i2i4},
	{"i2i4i2", (Il2CppMethodPointer)__N2M_i2i4i2},
	{"i2i4i4", (Il2CppMethodPointer)__N2M_i2i4i4},
	{"i4", (Il2CppMethodPointer)__N2M_i4},
	{"i4C8C8i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4C8C8i4i4i4i4i4},
	{"i4C8i4i4i4", (Il2CppMethodPointer)__N2M_i4C8i4i4i4},
	{"i4C8i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4C8i4i4i4i4i4},
	{"i4i1", (Il2CppMethodPointer)__N2M_i4i1},
	{"i4i2", (Il2CppMethodPointer)__N2M_i4i2},
	{"i4i4", (Il2CppMethodPointer)__N2M_i4i4},
	{"i4i4C16", (Il2CppMethodPointer)__N2M_i4i4C16},
	{"i4i4C8", (Il2CppMethodPointer)__N2M_i4i4C8},
	{"i4i4C8C8i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4C8C8i4i4i4i4i4},
	{"i4i4C8i4", (Il2CppMethodPointer)__N2M_i4i4C8i4},
	{"i4i4C8i4i4", (Il2CppMethodPointer)__N2M_i4i4C8i4i4},
	{"i4i4C8i4i4i4", (Il2CppMethodPointer)__N2M_i4i4C8i4i4i4},
	{"i4i4C8i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4C8i4i4i4i4i4},
	{"i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i1},
	{"i4i4i2", (Il2CppMethodPointer)__N2M_i4i4i2},
	{"i4i4i2i2", (Il2CppMethodPointer)__N2M_i4i4i2i2},
	{"i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4},
	{"i4i4i4C8i4", (Il2CppMethodPointer)__N2M_i4i4i4C8i4},
	{"i4i4i4C8i4i4", (Il2CppMethodPointer)__N2M_i4i4i4C8i4i4},
	{"i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i1},
	{"i4i4i4i1i1", (Il2CppMethodPointer)__N2M_i4i4i4i1i1},
	{"i4i4i4i1i1i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i1i1i4i4},
	{"i4i4i4i1i4", (Il2CppMethodPointer)__N2M_i4i4i4i1i4},
	{"i4i4i4i1i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i1i4i1},
	{"i4i4i4i1i4i1i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i1i4i1i4i4},
	{"i4i4i4i1i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i1i4i4i4i4i4},
	{"i4i4i4i1i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i1i4i4i4i4i4i4},
	{"i4i4i4i2", (Il2CppMethodPointer)__N2M_i4i4i4i2},
	{"i4i4i4i2i4", (Il2CppMethodPointer)__N2M_i4i4i4i2i4},
	{"i4i4i4i2i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i2i4i4},
	{"i4i4i4i2i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i2i4i4i4},
	{"i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4},
	{"i4i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i4i1},
	{"i4i4i4i4i1i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i1i4i4},
	{"i4i4i4i4i1i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i1i4i4i4},
	{"i4i4i4i4i1i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i1i4i4i4i4i4i4},
	{"i4i4i4i4i1i4i4i4S16S16", (Il2CppMethodPointer)__N2M_i4i4i4i4i1i4i4i4S16S16},
	{"i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4},
	{"i4i4i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i1},
	{"i4i4i4i4i4i1i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i1i4i4},
	{"i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i4i1", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i4i4i1},
	{"i4i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4i4i4i4i4i4i4},
	{"i4i4i4i4i4S4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4S4},
	{"i4i4i4i4i4S4i4", (Il2CppMethodPointer)__N2M_i4i4i4i4i4S4i4},
	{"i4i4i4i4S4", (Il2CppMethodPointer)__N2M_i4i4i4i4S4},
	{"i4i4i4i4S8i4", (Il2CppMethodPointer)__N2M_i4i4i4i4S8i4},
	{"i4i4i4S16S16S16", (Il2CppMethodPointer)__N2M_i4i4i4S16S16S16},
	{"i4i4i4S4", (Il2CppMethodPointer)__N2M_i4i4i4S4},
	{"i4i4i4S4i4", (Il2CppMethodPointer)__N2M_i4i4i4S4i4},
	{"i4i4i4S4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4S4i4i4},
	{"i4i4i4S4i4i4i4", (Il2CppMethodPointer)__N2M_i4i4i4S4i4i4i4},
	{"i4i4i4S8i4", (Il2CppMethodPointer)__N2M_i4i4i4S8i4},
	{"i4i4i8", (Il2CppMethodPointer)__N2M_i4i4i8},
	{"i4i4r4", (Il2CppMethodPointer)__N2M_i4i4r4},
	{"i4i4r8", (Il2CppMethodPointer)__N2M_i4i4r8},
	{"i4i4S1", (Il2CppMethodPointer)__N2M_i4i4S1},
	{"i4i4S12", (Il2CppMethodPointer)__N2M_i4i4S12},
	{"i4i4S12i4i1S4", (Il2CppMethodPointer)__N2M_i4i4S12i4i1S4},
	{"i4i4S12S4", (Il2CppMethodPointer)__N2M_i4i4S12S4},
	{"i4i4S16", (Il2CppMethodPointer)__N2M_i4i4S16},
	{"i4i4S20", (Il2CppMethodPointer)__N2M_i4i4S20},
	{"i4i4S4", (Il2CppMethodPointer)__N2M_i4i4S4},
	{"i4i4S4i4", (Il2CppMethodPointer)__N2M_i4i4S4i4},
	{"i4i4S8", (Il2CppMethodPointer)__N2M_i4i4S8},
	{"i4i4S8i4", (Il2CppMethodPointer)__N2M_i4i4S8i4},
	{"i4i4S8S12i4i4i4", (Il2CppMethodPointer)__N2M_i4i4S8S12i4i4i4},
	{"i4i4S8S12i8i8i4", (Il2CppMethodPointer)__N2M_i4i4S8S12i8i8i4},
	{"i4S8S12i4i4i4", (Il2CppMethodPointer)__N2M_i4S8S12i4i4i4},
	{"i4S8S12i8i8i4", (Il2CppMethodPointer)__N2M_i4S8S12i8i8i4},
	{"i8", (Il2CppMethodPointer)__N2M_i8},
	{"i8i4", (Il2CppMethodPointer)__N2M_i8i4},
	{"i8i4i4", (Il2CppMethodPointer)__N2M_i8i4i4},
	{"i8i4i4i4", (Il2CppMethodPointer)__N2M_i8i4i4i4},
	{"i8i4i8", (Il2CppMethodPointer)__N2M_i8i4i8},
	{"i8i4i8i4", (Il2CppMethodPointer)__N2M_i8i4i8i4},
	{"i8i8", (Il2CppMethodPointer)__N2M_i8i8},
	{"r4", (Il2CppMethodPointer)__N2M_r4},
	{"r4i4", (Il2CppMethodPointer)__N2M_r4i4},
	{"r4i4i4", (Il2CppMethodPointer)__N2M_r4i4i4},
	{"r4i4i4i4", (Il2CppMethodPointer)__N2M_r4i4i4i4},
	{"r4i4r4", (Il2CppMethodPointer)__N2M_r4i4r4},
	{"r4r4", (Il2CppMethodPointer)__N2M_r4r4},
	{"r8", (Il2CppMethodPointer)__N2M_r8},
	{"r8i4", (Il2CppMethodPointer)__N2M_r8i4},
	{"r8i4C8", (Il2CppMethodPointer)__N2M_r8i4C8},
	{"r8i4i4", (Il2CppMethodPointer)__N2M_r8i4i4},
	{"r8i4i4i4", (Il2CppMethodPointer)__N2M_r8i4i4i4},
	{"r8i4r8", (Il2CppMethodPointer)__N2M_r8i4r8},
	{"r8r8", (Il2CppMethodPointer)__N2M_r8r8},
	{"S1", (Il2CppMethodPointer)__N2M_S1},
	{"S12", (Il2CppMethodPointer)__N2M_S12},
	{"S12i4", (Il2CppMethodPointer)__N2M_S12i4},
	{"S12i4i1", (Il2CppMethodPointer)__N2M_S12i4i1},
	{"S12i4S12", (Il2CppMethodPointer)__N2M_S12i4S12},
	{"S12S12", (Il2CppMethodPointer)__N2M_S12S12},
	{"S16", (Il2CppMethodPointer)__N2M_S16},
	{"S16i4", (Il2CppMethodPointer)__N2M_S16i4},
	{"S16i4i4", (Il2CppMethodPointer)__N2M_S16i4i4},
	{"S16i4i4i4", (Il2CppMethodPointer)__N2M_S16i4i4i4},
	{"S16i4S16", (Il2CppMethodPointer)__N2M_S16i4S16},
	{"S16S16", (Il2CppMethodPointer)__N2M_S16S16},
	{"S1i4", (Il2CppMethodPointer)__N2M_S1i4},
	{"S1i4S1", (Il2CppMethodPointer)__N2M_S1i4S1},
	{"S1S1", (Il2CppMethodPointer)__N2M_S1S1},
	{"S2", (Il2CppMethodPointer)__N2M_S2},
	{"S20", (Il2CppMethodPointer)__N2M_S20},
	{"S20i4", (Il2CppMethodPointer)__N2M_S20i4},
	{"S20i4i4", (Il2CppMethodPointer)__N2M_S20i4i4},
	{"S20i4S20", (Il2CppMethodPointer)__N2M_S20i4S20},
	{"S20S20", (Il2CppMethodPointer)__N2M_S20S20},
	{"S2i4", (Il2CppMethodPointer)__N2M_S2i4},
	{"S2i4S2", (Il2CppMethodPointer)__N2M_S2i4S2},
	{"S2S2", (Il2CppMethodPointer)__N2M_S2S2},
	{"S3", (Il2CppMethodPointer)__N2M_S3},
	{"S32i4i1", (Il2CppMethodPointer)__N2M_S32i4i1},
	{"S3i4", (Il2CppMethodPointer)__N2M_S3i4},
	{"S3i4S3", (Il2CppMethodPointer)__N2M_S3i4S3},
	{"S3S3", (Il2CppMethodPointer)__N2M_S3S3},
	{"S4", (Il2CppMethodPointer)__N2M_S4},
	{"S4i4", (Il2CppMethodPointer)__N2M_S4i4},
	{"S4i4S4", (Il2CppMethodPointer)__N2M_S4i4S4},
	{"S4S4", (Il2CppMethodPointer)__N2M_S4S4},
	{"S5", (Il2CppMethodPointer)__N2M_S5},
	{"S5i4", (Il2CppMethodPointer)__N2M_S5i4},
	{"S5i4S5", (Il2CppMethodPointer)__N2M_S5i4S5},
	{"S5S5", (Il2CppMethodPointer)__N2M_S5S5},
	{"S60i4", (Il2CppMethodPointer)__N2M_S60i4},
	{"S60i4i1", (Il2CppMethodPointer)__N2M_S60i4i1},
	{"S8i4", (Il2CppMethodPointer)__N2M_S8i4},
	{"S8i4i4S240", (Il2CppMethodPointer)__N2M_S8i4i4S240},
	{"S8i4S12S4", (Il2CppMethodPointer)__N2M_S8i4S12S4},
	{"S8i4S240", (Il2CppMethodPointer)__N2M_S8i4S240},
	{"S8i4S8", (Il2CppMethodPointer)__N2M_S8i4S8},
	{"S8i4S8i4", (Il2CppMethodPointer)__N2M_S8i4S8i4},
	{"S8S8i4", (Il2CppMethodPointer)__N2M_S8S8i4},
	{"S9", (Il2CppMethodPointer)__N2M_S9},
	{"S9i4", (Il2CppMethodPointer)__N2M_S9i4},
	{"S9i4S9", (Il2CppMethodPointer)__N2M_S9i4S9},
	{"S9S9", (Il2CppMethodPointer)__N2M_S9S9},
	{"v", (Il2CppMethodPointer)__N2M_v},
	{"vC16", (Il2CppMethodPointer)__N2M_vC16},
	{"vC16i4", (Il2CppMethodPointer)__N2M_vC16i4},
	{"vC32", (Il2CppMethodPointer)__N2M_vC32},
	{"vi1i4", (Il2CppMethodPointer)__N2M_vi1i4},
	{"vi4", (Il2CppMethodPointer)__N2M_vi4},
	{"vi4C16", (Il2CppMethodPointer)__N2M_vi4C16},
	{"vi4C16i4", (Il2CppMethodPointer)__N2M_vi4C16i4},
	{"vi4C32", (Il2CppMethodPointer)__N2M_vi4C32},
	{"vi4C8", (Il2CppMethodPointer)__N2M_vi4C8},
	{"vi4C8i4", (Il2CppMethodPointer)__N2M_vi4C8i4},
	{"vi4i1", (Il2CppMethodPointer)__N2M_vi4i1},
	{"vi4i1i4", (Il2CppMethodPointer)__N2M_vi4i1i4},
	{"vi4i1i4i4", (Il2CppMethodPointer)__N2M_vi4i1i4i4},
	{"vi4i2", (Il2CppMethodPointer)__N2M_vi4i2},
	{"vi4i2i2", (Il2CppMethodPointer)__N2M_vi4i2i2},
	{"vi4i2i4", (Il2CppMethodPointer)__N2M_vi4i2i4},
	{"vi4i4", (Il2CppMethodPointer)__N2M_vi4i4},
	{"vi4i4C8", (Il2CppMethodPointer)__N2M_vi4i4C8},
	{"vi4i4C8i4", (Il2CppMethodPointer)__N2M_vi4i4C8i4},
	{"vi4i4i1", (Il2CppMethodPointer)__N2M_vi4i4i1},
	{"vi4i4i1i1", (Il2CppMethodPointer)__N2M_vi4i4i1i1},
	{"vi4i4i1i4", (Il2CppMethodPointer)__N2M_vi4i4i1i4},
	{"vi4i4i1i4i1", (Il2CppMethodPointer)__N2M_vi4i4i1i4i1},
	{"vi4i4i1i8i8i4i4", (Il2CppMethodPointer)__N2M_vi4i4i1i8i8i4i4},
	{"vi4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4},
	{"vi4i4i4i1", (Il2CppMethodPointer)__N2M_vi4i4i4i1},
	{"vi4i4i4i1i1", (Il2CppMethodPointer)__N2M_vi4i4i4i1i1},
	{"vi4i4i4i1i8i8i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i1i8i8i4i4},
	{"vi4i4i4i2i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i2i4i4i4},
	{"vi4i4i4i2i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i2i4i4i4i4},
	{"vi4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4},
	{"vi4i4i4i4i1", (Il2CppMethodPointer)__N2M_vi4i4i4i4i1},
	{"vi4i4i4i4i2i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i2i4i4i4i4},
	{"vi4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4},
	{"vi4i4i4i4i4i1i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i1i4i4i4},
	{"vi4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i1i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i4i4i1i4i4i4},
	{"vi4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4S16", (Il2CppMethodPointer)__N2M_vi4i4i4i4i4S16},
	{"vi4i4i4S12", (Il2CppMethodPointer)__N2M_vi4i4i4S12},
	{"vi4i4i4S8", (Il2CppMethodPointer)__N2M_vi4i4i4S8},
	{"vi4i4i8", (Il2CppMethodPointer)__N2M_vi4i4i8},
	{"vi4i4i8i4i4", (Il2CppMethodPointer)__N2M_vi4i4i8i4i4},
	{"vi4i4S12", (Il2CppMethodPointer)__N2M_vi4i4S12},
	{"vi4i4S20", (Il2CppMethodPointer)__N2M_vi4i4S20},
	{"vi4i4S36", (Il2CppMethodPointer)__N2M_vi4i4S36},
	{"vi4i4S8", (Il2CppMethodPointer)__N2M_vi4i4S8},
	{"vi4i4S8i4", (Il2CppMethodPointer)__N2M_vi4i4S8i4},
	{"vi4i8", (Il2CppMethodPointer)__N2M_vi4i8},
	{"vi4i8i4", (Il2CppMethodPointer)__N2M_vi4i8i4},
	{"vi4i8i4i4", (Il2CppMethodPointer)__N2M_vi4i8i4i4},
	{"vi4i8i4i8", (Il2CppMethodPointer)__N2M_vi4i8i4i8},
	{"vi4i8i8", (Il2CppMethodPointer)__N2M_vi4i8i8},
	{"vi4i8i8i4", (Il2CppMethodPointer)__N2M_vi4i8i8i4},
	{"vi4r4", (Il2CppMethodPointer)__N2M_vi4r4},
	{"vi4r4i4", (Il2CppMethodPointer)__N2M_vi4r4i4},
	{"vi4r8", (Il2CppMethodPointer)__N2M_vi4r8},
	{"vi4r8i4", (Il2CppMethodPointer)__N2M_vi4r8i4},
	{"vi4S12", (Il2CppMethodPointer)__N2M_vi4S12},
	{"vi4S12i4", (Il2CppMethodPointer)__N2M_vi4S12i4},
	{"vi4S16", (Il2CppMethodPointer)__N2M_vi4S16},
	{"vi4S16i4", (Il2CppMethodPointer)__N2M_vi4S16i4},
	{"vi4S16i4i4", (Il2CppMethodPointer)__N2M_vi4S16i4i4},
	{"vi4S20", (Il2CppMethodPointer)__N2M_vi4S20},
	{"vi4S32", (Il2CppMethodPointer)__N2M_vi4S32},
	{"vi4S36", (Il2CppMethodPointer)__N2M_vi4S36},
	{"vi4S4", (Il2CppMethodPointer)__N2M_vi4S4},
	{"vi4S48", (Il2CppMethodPointer)__N2M_vi4S48},
	{"vi4S4i4i4", (Il2CppMethodPointer)__N2M_vi4S4i4i4},
	{"vi4S4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4S4i4i4i4i4i4i4i4},
	{"vi4S60", (Il2CppMethodPointer)__N2M_vi4S60},
	{"vi4S8", (Il2CppMethodPointer)__N2M_vi4S8},
	{"vi4S8C56", (Il2CppMethodPointer)__N2M_vi4S8C56},
	{"vi4S8C56i4", (Il2CppMethodPointer)__N2M_vi4S8C56i4},
	{"vi4S8i1", (Il2CppMethodPointer)__N2M_vi4S8i1},
	{"vi4S8i2", (Il2CppMethodPointer)__N2M_vi4S8i2},
	{"vi4S8i4", (Il2CppMethodPointer)__N2M_vi4S8i4},
	{"vi4S8i4i4", (Il2CppMethodPointer)__N2M_vi4S8i4i4},
	{"vi4S8i4i4i4", (Il2CppMethodPointer)__N2M_vi4S8i4i4i4},
	{"vi4S8i4i4i4i4", (Il2CppMethodPointer)__N2M_vi4S8i4i4i4i4},
	{"vi4S8i8", (Il2CppMethodPointer)__N2M_vi4S8i8},
	{"vi4S8r4", (Il2CppMethodPointer)__N2M_vi4S8r4},
	{"vi4S8r8", (Il2CppMethodPointer)__N2M_vi4S8r8},
	{"vi4S8S4", (Il2CppMethodPointer)__N2M_vi4S8S4},
	{"vi4S8S8", (Il2CppMethodPointer)__N2M_vi4S8S8},
	{"vS8", (Il2CppMethodPointer)__N2M_vS8},
	{nullptr, nullptr},
};

static ValueTypeSizeAlign8<16> __N2M_AdjustorThunk_C16i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_AdjustorThunk_C16i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_AdjustorThunk_C16i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_AdjustorThunk_C16i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<16> __N2M_AdjustorThunk_C16i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<16>*)ret;
}


static ValueTypeSizeAlign8<24> __N2M_AdjustorThunk_C24i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<24>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_AdjustorThunk_C8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_AdjustorThunk_C8i4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_AdjustorThunk_C8i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_AdjustorThunk_C8i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_AdjustorThunk_C8i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static ValueTypeSizeAlign8<8> __N2M_AdjustorThunk_C8i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSizeAlign8<8>*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4C1568(int32_t __arg0, ValueTypeSizeAlign8<1568> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4C24(int32_t __arg0, ValueTypeSizeAlign8<24> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4C64(int32_t __arg0, ValueTypeSizeAlign8<64> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i4i4i4S12i4r4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<12> __arg4, int32_t __arg5, float __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[11] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = args + 10;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i4i4r4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = args + 7;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S1(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S108(int32_t __arg0, ValueTypeSize<108> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S116(int32_t __arg0, ValueTypeSize<116> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S12i1(int32_t __arg0, ValueTypeSize<12> __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S12i4(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S12S12(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S136(int32_t __arg0, ValueTypeSize<136> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S16i1(int32_t __arg0, ValueTypeSize<16> __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S188(int32_t __arg0, ValueTypeSize<188> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S2(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S20(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S216(int32_t __arg0, ValueTypeSize<216> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S224(int32_t __arg0, ValueTypeSize<224> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S24(int32_t __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S24i4(int32_t __arg0, ValueTypeSize<24> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S28(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S312(int32_t __arg0, ValueTypeSize<312> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S32(int32_t __arg0, ValueTypeSize<32> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S64(int32_t __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S68(int32_t __arg0, ValueTypeSize<68> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S88(int32_t __arg0, ValueTypeSize<88> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S92(int32_t __arg0, ValueTypeSize<92> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int8_t __N2M_AdjustorThunk_i1i4S992(int32_t __arg0, ValueTypeSize<992> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int8_t*)ret;
}


static int16_t __N2M_AdjustorThunk_i2i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int16_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4C16(int32_t __arg0, ValueTypeSizeAlign8<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i2i4(int32_t __arg0, int16_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4S1(int32_t __arg0, ValueTypeSize<1> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int32_t __N2M_AdjustorThunk_i4i4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(int32_t*)ret;
}


static int64_t __N2M_AdjustorThunk_i8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(int64_t*)ret;
}


static float __N2M_AdjustorThunk_r4i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_AdjustorThunk_r4i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_AdjustorThunk_r4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static float __N2M_AdjustorThunk_r4i4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(float*)ret;
}


static double __N2M_AdjustorThunk_r8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(double*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4S12S12(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<12> __N2M_AdjustorThunk_S12i4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<12>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4i4i4i4S36i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<36> __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = args + 6;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4S36i1(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = args + 3;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4S36i1i1(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4S36S36i1(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<16> __N2M_AdjustorThunk_S16i4S36S36i1i1(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = args + 5;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<16>*)ret;
}


static ValueTypeSize<188> __N2M_AdjustorThunk_S188i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[25] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<188>*)ret;
}


static ValueTypeSize<1> __N2M_AdjustorThunk_S1i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<1>*)ret;
}


static ValueTypeSize<20> __N2M_AdjustorThunk_S20i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<20> __N2M_AdjustorThunk_S20i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<20>*)ret;
}


static ValueTypeSize<224> __N2M_AdjustorThunk_S224i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[29] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<224>*)ret;
}


static ValueTypeSize<24> __N2M_AdjustorThunk_S24i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<24>*)ret;
}


static ValueTypeSize<28> __N2M_AdjustorThunk_S28i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<28>*)ret;
}


static ValueTypeSize<28> __N2M_AdjustorThunk_S28i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<28>*)ret;
}


static ValueTypeSize<28> __N2M_AdjustorThunk_S28i4S28(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<28>*)ret;
}


static ValueTypeSize<2> __N2M_AdjustorThunk_S2i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<2>*)ret;
}


static ValueTypeSize<36> __N2M_AdjustorThunk_S36i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<36>*)ret;
}


static ValueTypeSize<36> __N2M_AdjustorThunk_S36i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<36>*)ret;
}


static ValueTypeSize<48> __N2M_AdjustorThunk_S48i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<48>*)ret;
}


static ValueTypeSize<4> __N2M_AdjustorThunk_S4i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<4> __N2M_AdjustorThunk_S4i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<4> __N2M_AdjustorThunk_S4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = args + 4;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<4>*)ret;
}


static ValueTypeSize<64> __N2M_AdjustorThunk_S64i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<64>*)ret;
}


static ValueTypeSize<68> __N2M_AdjustorThunk_S68i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[10] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<68>*)ret;
}


static ValueTypeSize<8> __N2M_AdjustorThunk_S8i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_AdjustorThunk_S8i4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<8> __N2M_AdjustorThunk_S8i4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = args + 2;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<8>*)ret;
}


static ValueTypeSize<992> __N2M_AdjustorThunk_S992i4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[125] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = args + 1;
    Interpreter::Execute(method, args, ret);
    return *(ValueTypeSize<992>*)ret;
}


static void __N2M_AdjustorThunk_vi4(int32_t __arg0, const MethodInfo* method)
{
    StackObject args[1] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)) };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4C8C8(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4C8i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4C8i4i4(int32_t __arg0, ValueTypeSizeAlign8<8> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i1(int32_t __arg0, int8_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i1i1(int32_t __arg0, int8_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i1i1i1i1(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i1i1i1i4i4i4i4(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i1i1i1i4i4i4i4i4i4i4i4(int32_t __arg0, int8_t __arg1, int8_t __arg2, int8_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, int32_t __arg10, int32_t __arg11, const MethodInfo* method)
{
    StackObject args[12] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10, *(uint64_t*)&__arg11 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i1i4(int32_t __arg0, int8_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i2(int32_t __arg0, int16_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i2i2(int32_t __arg0, int16_t __arg1, int16_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i2i4i1i1i1(int32_t __arg0, int16_t __arg1, int32_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4(int32_t __arg0, int32_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4C8(int32_t __arg0, int32_t __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i1(int32_t __arg0, int32_t __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i1i1i1i1i4i8(int32_t __arg0, int32_t __arg1, int8_t __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, int32_t __arg6, int64_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i1i4(int32_t __arg0, int32_t __arg1, int8_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i2i2i1i1i1i1i1i1i1i1(int32_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int8_t __arg4, int8_t __arg5, int8_t __arg6, int8_t __arg7, int8_t __arg8, int8_t __arg9, int8_t __arg10, int8_t __arg11, const MethodInfo* method)
{
    StackObject args[12] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10, *(uint64_t*)&__arg11 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i2i2i4(int32_t __arg0, int32_t __arg1, int16_t __arg2, int16_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i1i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4C8(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, ValueTypeSizeAlign8<8> __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4C8(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, ValueTypeSizeAlign8<8> __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4i4C8(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, ValueTypeSizeAlign8<8> __arg9, const MethodInfo* method)
{
    StackObject args[10] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, int32_t __arg9, const MethodInfo* method)
{
    StackObject args[10] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4S28i4i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<28> __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4i4S36i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<36> __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4r4(int32_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4r4i1(int32_t __arg0, int32_t __arg1, int32_t __arg2, float __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4S4(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<4> __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i4S8i4(int32_t __arg0, int32_t __arg1, int32_t __arg2, ValueTypeSize<8> __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4i8(int32_t __arg0, int32_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4r4(int32_t __arg0, int32_t __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4r8(int32_t __arg0, int32_t __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S16(int32_t __arg0, int32_t __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S28i1i1i1(int32_t __arg0, int32_t __arg1, ValueTypeSize<28> __arg2, int8_t __arg3, int8_t __arg4, int8_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S36(int32_t __arg0, int32_t __arg1, ValueTypeSize<36> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S4(int32_t __arg0, int32_t __arg1, ValueTypeSize<4> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S48i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<48> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S8(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S8i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S8i4i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i4S8i4i4i4i4i4i4(int32_t __arg0, int32_t __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, int32_t __arg6, int32_t __arg7, int32_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i8(int32_t __arg0, int64_t __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i8C8(int32_t __arg0, int64_t __arg1, ValueTypeSizeAlign8<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i8i4(int32_t __arg0, int64_t __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i8i8(int32_t __arg0, int64_t __arg1, int64_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i8i8i8i8i8i8i4(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4i8i8i8i8i8i8i4i8(int32_t __arg0, int64_t __arg1, int64_t __arg2, int64_t __arg3, int64_t __arg4, int64_t __arg5, int64_t __arg6, int32_t __arg7, int64_t __arg8, const MethodInfo* method)
{
    StackObject args[9] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4(int32_t __arg0, float __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4i4(int32_t __arg0, float __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4r4(int32_t __arg0, float __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4r4r4(int32_t __arg0, float __arg1, float __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4r4r4r4(int32_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4r4r4r4r4r4(int32_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4(int32_t __arg0, float __arg1, float __arg2, float __arg3, float __arg4, float __arg5, float __arg6, float __arg7, float __arg8, float __arg9, float __arg10, float __arg11, float __arg12, float __arg13, float __arg14, float __arg15, float __arg16, const MethodInfo* method)
{
    StackObject args[17] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6, *(uint64_t*)&__arg7, *(uint64_t*)&__arg8, *(uint64_t*)&__arg9, *(uint64_t*)&__arg10, *(uint64_t*)&__arg11, *(uint64_t*)&__arg12, *(uint64_t*)&__arg13, *(uint64_t*)&__arg14, *(uint64_t*)&__arg15, *(uint64_t*)&__arg16 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r8(int32_t __arg0, double __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4r8r8(int32_t __arg0, double __arg1, double __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12(int32_t __arg0, ValueTypeSize<12> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12i4i4i4(int32_t __arg0, ValueTypeSize<12> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12r4(int32_t __arg0, ValueTypeSize<12> __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12S12(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12S12S12(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<12> __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12S16(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12S16r4(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S12S16S12(int32_t __arg0, ValueTypeSize<12> __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<12> __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S16(int32_t __arg0, ValueTypeSize<16> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S16r4(int32_t __arg0, ValueTypeSize<16> __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S16r4i4(int32_t __arg0, ValueTypeSize<16> __arg1, float __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S16S16S16S16(int32_t __arg0, ValueTypeSize<16> __arg1, ValueTypeSize<16> __arg2, ValueTypeSize<16> __arg3, ValueTypeSize<16> __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3, (uint64_t)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S188(int32_t __arg0, ValueTypeSize<188> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S2(int32_t __arg0, ValueTypeSize<2> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S20(int32_t __arg0, ValueTypeSize<20> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S20i4(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S20i4i4(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S20i4i4i4(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S20i4i4S36S36(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<36> __arg4, ValueTypeSize<36> __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, (uint64_t)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S20i4i4S4i1S36S36(int32_t __arg0, ValueTypeSize<20> __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<4> __arg4, int8_t __arg5, ValueTypeSize<36> __arg6, ValueTypeSize<36> __arg7, const MethodInfo* method)
{
    StackObject args[8] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5, (uint64_t)&__arg6, (uint64_t)&__arg7 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S224(int32_t __arg0, ValueTypeSize<224> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S24(int32_t __arg0, ValueTypeSize<24> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S28(int32_t __arg0, ValueTypeSize<28> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S28i1i1(int32_t __arg0, ValueTypeSize<28> __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S28i4i4i4(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S28i4i4S28i4i4(int32_t __arg0, ValueTypeSize<28> __arg1, int32_t __arg2, int32_t __arg3, ValueTypeSize<28> __arg4, int32_t __arg5, int32_t __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, (uint64_t)&__arg4, *(uint64_t*)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S2i4(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S2i4i4(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S2i4i4i4(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S2i4i4i4i4(int32_t __arg0, ValueTypeSize<2> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36(int32_t __arg0, ValueTypeSize<36> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36i1(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36i1i1(int32_t __arg0, ValueTypeSize<36> __arg1, int8_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36i4i1(int32_t __arg0, ValueTypeSize<36> __arg1, int32_t __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36S36i1(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36S36i1i1(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, int8_t __arg3, int8_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36S36S36S28(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, ValueTypeSize<36> __arg3, ValueTypeSize<28> __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3, (uint64_t)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S36S36S36S28S64r4(int32_t __arg0, ValueTypeSize<36> __arg1, ValueTypeSize<36> __arg2, ValueTypeSize<36> __arg3, ValueTypeSize<28> __arg4, ValueTypeSize<64> __arg5, float __arg6, const MethodInfo* method)
{
    StackObject args[7] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2, (uint64_t)&__arg3, (uint64_t)&__arg4, (uint64_t)&__arg5, *(uint64_t*)&__arg6 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S4(int32_t __arg0, ValueTypeSize<4> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S40(int32_t __arg0, ValueTypeSize<40> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S4i4(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S4i4i4(int32_t __arg0, ValueTypeSize<4> __arg1, int32_t __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S4S224(int32_t __arg0, ValueTypeSize<4> __arg1, ValueTypeSize<224> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S64(int32_t __arg0, ValueTypeSize<64> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S64S16(int32_t __arg0, ValueTypeSize<64> __arg1, ValueTypeSize<16> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1, (uint64_t)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S68(int32_t __arg0, ValueTypeSize<68> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8(int32_t __arg0, ValueTypeSize<8> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8i4i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, int32_t __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8r4(int32_t __arg0, ValueTypeSize<8> __arg1, float __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8r4r4(int32_t __arg0, ValueTypeSize<8> __arg1, float __arg2, float __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8S8(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, const MethodInfo* method)
{
    StackObject args[3] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8S8i4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, const MethodInfo* method)
{
    StackObject args[4] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8S8i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, const MethodInfo* method)
{
    StackObject args[5] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S8S8i4i4i4(int32_t __arg0, ValueTypeSize<8> __arg1, ValueTypeSize<8> __arg2, int32_t __arg3, int32_t __arg4, int32_t __arg5, const MethodInfo* method)
{
    StackObject args[6] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), *(uint64_t*)&__arg1, *(uint64_t*)&__arg2, *(uint64_t*)&__arg3, *(uint64_t*)&__arg4, *(uint64_t*)&__arg5 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


static void __N2M_AdjustorThunk_vi4S992(int32_t __arg0, ValueTypeSize<992> __arg1, const MethodInfo* method)
{
    StackObject args[2] = {(uint64_t)(*(uint8_t**)&__arg0 + sizeof(Il2CppObject)), (uint64_t)&__arg1 };
    StackObject* ret = nullptr;
    Interpreter::Execute(method, args, ret);
    
}


NativeAdjustThunkMethodInfo hybridclr::interpreter::g_adjustThunkStub[] = 
{

	{"C16i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_C16i4},
	{"C16i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_C16i4C8},
	{"C16i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_C16i4i4},
	{"C16i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_C16i4i8},
	{"C16i4r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_C16i4r8},
	{"C24i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_C24i4i4},
	{"C8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_C8i4},
	{"C8i4C16", (Il2CppMethodPointer)__N2M_AdjustorThunk_C8i4C16},
	{"C8i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_C8i4C8},
	{"C8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_C8i4i4},
	{"C8i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_C8i4i8},
	{"C8i4r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_C8i4r8},
	{"i1i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4},
	{"i1i4C1568", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4C1568},
	{"i1i4C16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4C16},
	{"i1i4C24", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4C24},
	{"i1i4C64", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4C64},
	{"i1i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4C8},
	{"i1i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i1},
	{"i1i4i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i2},
	{"i1i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i4},
	{"i1i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i4i4},
	{"i1i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i4i4i4i4},
	{"i1i4i4i4i4S12i4r4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i4i4i4S12i4r4i4i4i4},
	{"i1i4i4i4r4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i4i4r4i4i4i4},
	{"i1i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4i8},
	{"i1i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4r4},
	{"i1i4r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4r8},
	{"i1i4S1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S1},
	{"i1i4S108", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S108},
	{"i1i4S116", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S116},
	{"i1i4S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S12},
	{"i1i4S12i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S12i1},
	{"i1i4S12i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S12i4},
	{"i1i4S12S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S12S12},
	{"i1i4S136", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S136},
	{"i1i4S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S16},
	{"i1i4S16i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S16i1},
	{"i1i4S188", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S188},
	{"i1i4S2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S2},
	{"i1i4S20", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S20},
	{"i1i4S216", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S216},
	{"i1i4S224", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S224},
	{"i1i4S24", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S24},
	{"i1i4S24i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S24i4},
	{"i1i4S28", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S28},
	{"i1i4S312", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S312},
	{"i1i4S32", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S32},
	{"i1i4S4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S4},
	{"i1i4S64", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S64},
	{"i1i4S68", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S68},
	{"i1i4S8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S8},
	{"i1i4S88", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S88},
	{"i1i4S92", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S92},
	{"i1i4S992", (Il2CppMethodPointer)__N2M_AdjustorThunk_i1i4S992},
	{"i2i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i2i4},
	{"i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4},
	{"i4i4C16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4C16},
	{"i4i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4C8},
	{"i4i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i1},
	{"i4i4i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i2},
	{"i4i4i2i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i2i4},
	{"i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i4},
	{"i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i4i4},
	{"i4i4i4i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i4i4i1},
	{"i4i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4i8},
	{"i4i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4r4},
	{"i4i4r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4r8},
	{"i4i4S1", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4S1},
	{"i4i4S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4S16},
	{"i4i4S4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4S4},
	{"i4i4S8", (Il2CppMethodPointer)__N2M_AdjustorThunk_i4i4S8},
	{"i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_i8i4},
	{"r4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i4},
	{"r4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i4i4},
	{"r4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i4i4i4},
	{"r4i4S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_r4i4S12},
	{"r8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_r8i4},
	{"S12i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4},
	{"S12i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4i4},
	{"S12i4i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4i4i1},
	{"S12i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4i4i4},
	{"S12i4i4i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4i4i4i1},
	{"S12i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4r4},
	{"S12i4S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4S12},
	{"S12i4S12S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4S12S12},
	{"S12i4S4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S12i4S4},
	{"S16i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4},
	{"S16i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4i4},
	{"S16i4i4i4i4S36i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4i4i4i4S36i4},
	{"S16i4S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4S16},
	{"S16i4S36i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4S36i1},
	{"S16i4S36i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4S36i1i1},
	{"S16i4S36S36i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4S36S36i1},
	{"S16i4S36S36i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_S16i4S36S36i1i1},
	{"S188i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S188i4},
	{"S1i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S1i4},
	{"S20i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S20i4},
	{"S20i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S20i4i4},
	{"S224i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S224i4},
	{"S24i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S24i4},
	{"S28i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S28i4},
	{"S28i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S28i4i4},
	{"S28i4S28", (Il2CppMethodPointer)__N2M_AdjustorThunk_S28i4S28},
	{"S2i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S2i4},
	{"S36i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S36i4},
	{"S36i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S36i4i4},
	{"S48i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S48i4i4},
	{"S4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S4i4},
	{"S4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S4i4i4},
	{"S4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S4i4i4i4i4},
	{"S64i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S64i4},
	{"S68i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S68i4},
	{"S8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S8i4},
	{"S8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S8i4i4},
	{"S8i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S8i4r4},
	{"S992i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_S992i4},
	{"vi4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4},
	{"vi4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4C8},
	{"vi4C8C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4C8C8},
	{"vi4C8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4C8i4},
	{"vi4C8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4C8i4i4},
	{"vi4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i1},
	{"vi4i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i1i1},
	{"vi4i1i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i1i1i1i1},
	{"vi4i1i1i1i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i1i1i1i4i4i4i4},
	{"vi4i1i1i1i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i1i1i1i4i4i4i4i4i4i4i4},
	{"vi4i1i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i1i4},
	{"vi4i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i2},
	{"vi4i2i2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i2i2},
	{"vi4i2i4i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i2i4i1i1i1},
	{"vi4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4},
	{"vi4i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4C8},
	{"vi4i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i1},
	{"vi4i4i1i1i1i1i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i1i1i1i1i4i8},
	{"vi4i4i1i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i1i4},
	{"vi4i4i2i2i1i1i1i1i1i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i2i2i1i1i1i1i1i1i1i1},
	{"vi4i4i2i2i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i2i2i4},
	{"vi4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4},
	{"vi4i4i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i1},
	{"vi4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4},
	{"vi4i4i4i4i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i1i1},
	{"vi4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4},
	{"vi4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4C8},
	{"vi4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4C8},
	{"vi4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4i4i4i4i4i4C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4i4C8},
	{"vi4i4i4i4i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4i4i4i4i4i4i4},
	{"vi4i4i4i4S28i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4S28i4i4},
	{"vi4i4i4i4S36i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4i4S36i4},
	{"vi4i4i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4r4},
	{"vi4i4i4r4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4r4i1},
	{"vi4i4i4S4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4S4},
	{"vi4i4i4S8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i4S8i4},
	{"vi4i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4i8},
	{"vi4i4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4r4},
	{"vi4i4r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4r8},
	{"vi4i4S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S16},
	{"vi4i4S28i1i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S28i1i1i1},
	{"vi4i4S36", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S36},
	{"vi4i4S4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S4},
	{"vi4i4S48i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S48i4},
	{"vi4i4S8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S8},
	{"vi4i4S8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S8i4},
	{"vi4i4S8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S8i4i4},
	{"vi4i4S8i4i4i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i4S8i4i4i4i4i4i4},
	{"vi4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i8},
	{"vi4i8C8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i8C8},
	{"vi4i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i8i4},
	{"vi4i8i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i8i8},
	{"vi4i8i8i8i8i8i8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i8i8i8i8i8i8i4},
	{"vi4i8i8i8i8i8i8i4i8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4i8i8i8i8i8i8i4i8},
	{"vi4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4},
	{"vi4r4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4i4},
	{"vi4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4r4},
	{"vi4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4r4r4},
	{"vi4r4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4r4r4r4},
	{"vi4r4r4r4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4r4r4r4r4r4},
	{"vi4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4r4},
	{"vi4r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r8},
	{"vi4r8r8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4r8r8},
	{"vi4S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12},
	{"vi4S12i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12i4i4i4},
	{"vi4S12r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12r4},
	{"vi4S12S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12S12},
	{"vi4S12S12S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12S12S12},
	{"vi4S12S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12S16},
	{"vi4S12S16r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12S16r4},
	{"vi4S12S16S12", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S12S16S12},
	{"vi4S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S16},
	{"vi4S16r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S16r4},
	{"vi4S16r4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S16r4i4},
	{"vi4S16S16S16S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S16S16S16S16},
	{"vi4S188", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S188},
	{"vi4S2", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S2},
	{"vi4S20", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S20},
	{"vi4S20i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S20i4},
	{"vi4S20i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S20i4i4},
	{"vi4S20i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S20i4i4i4},
	{"vi4S20i4i4S36S36", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S20i4i4S36S36},
	{"vi4S20i4i4S4i1S36S36", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S20i4i4S4i1S36S36},
	{"vi4S224", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S224},
	{"vi4S24", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S24},
	{"vi4S28", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S28},
	{"vi4S28i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S28i1i1},
	{"vi4S28i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S28i4i4i4},
	{"vi4S28i4i4S28i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S28i4i4S28i4i4},
	{"vi4S2i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S2i4},
	{"vi4S2i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S2i4i4},
	{"vi4S2i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S2i4i4i4},
	{"vi4S2i4i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S2i4i4i4i4},
	{"vi4S36", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36},
	{"vi4S36i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36i1},
	{"vi4S36i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36i1i1},
	{"vi4S36i4i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36i4i1},
	{"vi4S36S36i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36S36i1},
	{"vi4S36S36i1i1", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36S36i1i1},
	{"vi4S36S36S36S28", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36S36S36S28},
	{"vi4S36S36S36S28S64r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S36S36S36S28S64r4},
	{"vi4S4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S4},
	{"vi4S40", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S40},
	{"vi4S4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S4i4},
	{"vi4S4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S4i4i4},
	{"vi4S4S224", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S4S224},
	{"vi4S64", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S64},
	{"vi4S64S16", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S64S16},
	{"vi4S68", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S68},
	{"vi4S8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8},
	{"vi4S8i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8i4i4i4},
	{"vi4S8r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8r4},
	{"vi4S8r4r4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8r4r4},
	{"vi4S8S8", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8S8},
	{"vi4S8S8i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8S8i4},
	{"vi4S8S8i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8S8i4i4},
	{"vi4S8S8i4i4i4", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S8S8i4i4i4},
	{"vi4S992", (Il2CppMethodPointer)__N2M_AdjustorThunk_vi4S992},
	{nullptr, nullptr},
};

//!!!}}INVOKE_STUB
#endif
