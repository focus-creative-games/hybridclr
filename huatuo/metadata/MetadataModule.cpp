#include "MetadataModule.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"
#include "os/Atomic.h"
#include "os/Mutex.h"
#include "os/File.h"
#include "vm/Exception.h"
#include "vm/String.h"
#include "vm/Assembly.h"
#include "vm/Class.h"
#include "vm/Object.h"
#include "vm/Image.h"
#include "vm/MetadataLock.h"
#include "utils/Logging.h"
#include "utils/MemoryMappedFile.h"
#include "utils/Memory.h"

#include "../interpreter/InterpreterModule.h"

#include "InterpreterImage.h"
#include "AOTHomologousImage.h"
#include "ReversePInvokeMethodStub.h"

using namespace il2cpp;

namespace huatuo
{
    Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointerSlow(MethodInfo* method)
    {
        IL2CPP_ASSERT(!method->initInterpCallMethodPointer);
        method->initInterpCallMethodPointer = true;
#if HUATUO_UNITY_2021
        method->interpCallMethodPointer = huatuo::metadata::MetadataModule::IsImplementedByInterpreter(method) ?
            huatuo::interpreter::InterpreterModule::GetMethodPointer(method) : nullptr;
        return method->interpCallMethodPointer;
#else
        if (huatuo::metadata::MetadataModule::IsImplementedByInterpreter(method))
        {
            method->methodPointer = method->klass->valuetype && huatuo::metadata::IsInstanceMethod(method) ?
                huatuo::interpreter::InterpreterModule::GetAdjustThunkMethodPointer(method)
                : huatuo::interpreter::InterpreterModule::GetMethodPointer(method);
            method->invoker_method = huatuo::interpreter::InterpreterModule::GetMethodInvoker(method);
        }
        return method->methodPointer;
#endif
    }

namespace metadata
{

    std::unordered_map<const MethodInfo*, const ReversePInvokeInfo*> MetadataModule::s_methodInfo2ReverseInfos;
    std::unordered_map<Il2CppMethodPointer, const ReversePInvokeInfo*> MetadataModule::s_methodPointer2ReverseInfos;
    std::vector<ReversePInvokeInfo> MetadataModule::s_reverseInfos;
    size_t MetadataModule::s_nextMethodIndex;

    static baselib::ReentrantLock g_reversePInvokeMethodLock;

    void MetadataModule::InitReversePInvokeInfo()
    {
        s_nextMethodIndex = 0;
        for (int32_t i = 0; s_ReversePInvokeMethodStub[i]; i++)
        {
            s_reverseInfos.push_back({ i, s_ReversePInvokeMethodStub[i], nullptr });
        }
        s_methodInfo2ReverseInfos.reserve(s_reverseInfos.size() * 2);
        s_methodPointer2ReverseInfos.reserve(s_reverseInfos.size() * 2);
        for (ReversePInvokeInfo& rpi : s_reverseInfos)
        {
            s_methodPointer2ReverseInfos.insert({ rpi.methodPointer, &rpi });
        }
    }

    void MetadataModule::Initialize()
    {
        InitReversePInvokeInfo();
        InterpreterImage::Initialize();
    }

    Il2CppMethodPointer MetadataModule::GetReversePInvokeWrapper(const Il2CppImage* image, const MethodInfo* method)
    {
        if (!huatuo::metadata::IsStaticMethod(method))
        {
            return nullptr;
        }
        il2cpp::os::FastAutoLock lock(&g_reversePInvokeMethodLock);
        auto it = s_methodInfo2ReverseInfos.find(method);
        if (it != s_methodInfo2ReverseInfos.end())
        {
            return it->second->methodPointer;
        }
        if (s_nextMethodIndex < s_reverseInfos.size())
        {
            ReversePInvokeInfo& rpi = s_reverseInfos[s_nextMethodIndex++];
            rpi.methodInfo = method;
            s_methodInfo2ReverseInfos.insert({ method, &rpi });
            return rpi.methodPointer;
        }
        RaiseHuatuoExecutionEngineException("GetReversePInvokeWrapper fail. exceed max wrapper num");
        return nullptr;
    }
}
}
