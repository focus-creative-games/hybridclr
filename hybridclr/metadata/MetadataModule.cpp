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

#include "Assembly.h"
#include "InterpreterImage.h"
#include "ConsistentAOTHomologousImage.h"
#include "SuperSetAOTHomologousImage.h"
#include "ReversePInvokeMethodStub.h"

using namespace il2cpp;

namespace hybridclr
{

namespace metadata
{

    std::unordered_map<const MethodInfo*, const ReversePInvokeInfo*> MetadataModule::s_methodInfo2ReverseInfos;
    std::unordered_map<Il2CppMethodPointer, const ReversePInvokeInfo*> MetadataModule::s_methodPointer2ReverseInfos;
    std::unordered_map<const char*, int32_t, CStringHash, CStringEqualTo> MetadataModule::s_methodSig2Indexs;
    std::vector<ReversePInvokeInfo> MetadataModule::s_reverseInfos;

    static baselib::ReentrantLock g_reversePInvokeMethodLock;

    void MetadataModule::InitReversePInvokeInfo()
    {
        for (int32_t i = 0; ; i++)
        {
            ReversePInvokeMethodData& data = g_reversePInvokeMethodStub[i];
            if (data.methodPointer == nullptr)
            {
                break;
            }
            s_reverseInfos.push_back({ i, data.methodPointer, nullptr });
            auto it = s_methodSig2Indexs.find(data.methodSig);
            if (it == s_methodSig2Indexs.end())
            {
                s_methodSig2Indexs.insert({ data.methodSig, i });
            }
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
        Assembly::InitializePlaceHolderAssemblies();
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


        char sigName[1000];
        interpreter::ComputeSignature(method, false, sigName, sizeof(sigName) - 1);
        auto it2 = s_methodSig2Indexs.find(sigName);
        if (it2 == s_methodSig2Indexs.end())
        {
            TEMP_FORMAT(methodSigBuf, "GetReversePInvokeWrapper fail. not find wrapper of method:%s", GetMethodNameWithSignature(method).c_str());
            RaiseExecutionEngineException(methodSigBuf);
        }
        int32_t wrapperIndex = it2->second;
        ReversePInvokeMethodData& data = g_reversePInvokeMethodStub[wrapperIndex];
        if (data.methodPointer == nullptr || std::strcmp(data.methodSig, sigName))
        {
            TEMP_FORMAT(methodSigBuf, "GetReversePInvokeWrapper fail. exceed max wrapper num of method:%s", GetMethodNameWithSignature(method).c_str());
            RaiseExecutionEngineException(methodSigBuf);
        }

        s_methodSig2Indexs[sigName] = wrapperIndex + 1;

        ReversePInvokeInfo& rpi = s_reverseInfos[wrapperIndex];
        rpi.methodInfo = method;
        s_methodInfo2ReverseInfos.insert({ method, &rpi });
        return rpi.methodPointer;
    }


    LoadImageErrorCode MetadataModule::LoadMetadataForAOTAssembly(const void* dllBytes, uint32_t dllSize, HomologousImageMode mode)
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

        AOTHomologousImage* image = nullptr;
        switch (mode)
        {
        case HomologousImageMode::CONSISTENT: image = new ConsistentAOTHomologousImage(); break;
        case HomologousImageMode::SUPERSET: image = new SuperSetAOTHomologousImage(); break;
        default: return LoadImageErrorCode::INVALID_HOMOLOGOUS_MODE;
        }

        LoadImageErrorCode err = image->Load((byte*)CopyBytes(dllBytes, dllSize), dllSize);
        if (err != LoadImageErrorCode::OK)
        {
            return err;
        }
        if (AOTHomologousImage::FindImageByAssemblyLocked(image->GetAOTAssembly(), lock))
        {
            return LoadImageErrorCode::HOMOLOGOUS_ASSEMBLY_HAS_BEEN_LOADED;
        }
        image->InitRuntimeMetadatas();
        AOTHomologousImage::RegisterLocked(image, lock);
        return LoadImageErrorCode::OK;
    }
}
}
