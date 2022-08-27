#include "MetadataModule.h"

#include "Baselib.h"
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

namespace hybridclr
{
    Il2CppMethodPointer InitAndGetInterpreterDirectlyCallMethodPointerSlow(MethodInfo* method)
    {
        IL2CPP_ASSERT(!method->initInterpCallMethodPointer);
        method->initInterpCallMethodPointer = true;
#if HYBRIDCLR_UNITY_2021_OR_NEW
        if (hybridclr::metadata::MetadataModule::IsImplementedByInterpreter(method))
        {
            method->interpCallMethodPointer = hybridclr::interpreter::InterpreterModule::GetMethodPointer(method);
            method->isInterpterImpl = true;
        }
        return method->interpCallMethodPointer;
#else
        if (hybridclr::metadata::MetadataModule::IsImplementedByInterpreter(method))
        {
            method->methodPointer = method->klass->valuetype && hybridclr::metadata::IsInstanceMethod(method) ?
                hybridclr::interpreter::InterpreterModule::GetAdjustThunkMethodPointer(method)
                : hybridclr::interpreter::InterpreterModule::GetMethodPointer(method);
            method->invoker_method = hybridclr::interpreter::InterpreterModule::GetMethodInvoker(method);
            method->isInterpterImpl = true;
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
        if (!hybridclr::metadata::IsStaticMethod(method))
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
        RaiseExecutionEngineException("GetReversePInvokeWrapper fail. exceed max wrapper num");
        return nullptr;
    }
}
}
