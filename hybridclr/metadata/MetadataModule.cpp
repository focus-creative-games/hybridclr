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
#include "DifferentialHybridImage.h"
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

    static bool IsDHEAssembly(const char* assemblyName)
    {

        for (const char** ptrAotAss = g_differentialHybridAssemblies; *ptrAotAss; ptrAotAss++)
        {
            if (std::strcmp(*ptrAotAss, assemblyName) == 0)
            {
                return true;
            }
        }
        return false;
    }

    static void PrepareDHEAssembles()
    {
        for (const char** ptrAotAss = g_differentialHybridAssemblies; *ptrAotAss; ptrAotAss++)
        {
            Il2CppAssembly* aotAss = const_cast<Il2CppAssembly*>(il2cpp::vm::Assembly::GetLoadedAssembly(*ptrAotAss));
            if (!aotAss)
            {
                continue;
            }
            Il2CppImage* aotImage = aotAss->image;

            Il2CppImage* tempImage = new Il2CppImage{};
            Il2CppAssembly* tempAss = new Il2CppAssembly{};
            *tempImage = *aotAss->image;
            *tempAss = *aotAss;
            tempAss->image = tempImage;
            tempImage->assembly = tempAss;

            *aotAss = {};
            aotAss->image = aotImage;
            aotAss->aname = tempAss->aname;
            aotAss->originAssembly = tempAss;

            *aotAss->image = {};
            aotAss->image->assembly = aotAss;
            aotAss->image->name = tempImage->name;
            aotAss->image->nameNoExt = tempImage->nameNoExt;
        }
    }

    void MetadataModule::Initialize()
    {
        InitReversePInvokeInfo();
        InterpreterImage::Initialize();
        PrepareDHEAssembles();
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

    LoadImageErrorCode MetadataModule::UseDifferentialHybridAOTAssembly(const char* assemblyName)
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

        Il2CppAssembly* aotAss = const_cast<Il2CppAssembly*>(il2cpp::vm::Assembly::GetLoadedAssembly(assemblyName));
        if (!aotAss)
        {
            return LoadImageErrorCode::AOT_ASSEMBLY_NOT_FIND;
        }
        if (!aotAss->originAssembly)
        {
            return LoadImageErrorCode::DIFFERENTIAL_HYBRID_ASSEMBLY_NOT_DIFFERENTIAL_HYBRID_ASSEMBLY;
        }

        Il2CppImage* aotImage = aotAss->image;
        *aotAss = *aotAss->originAssembly;
        *aotImage = *aotAss->originAssembly->image;
        aotAss->image = aotImage;
        aotImage->assembly = aotAss;
        IL2CPP_ASSERT(aotAss->originAssembly == nullptr);
        return LoadImageErrorCode::OK;
    }

    LoadImageErrorCode MetadataModule::LoadDifferentialHybridAssembly(const void* assemblyData, uint32_t length, const void* optionData, uint32_t optionCount)
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

        if (!assemblyData)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentNullException("rawAssembly is null"));
        }
        if (!optionData)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentNullException("optionData is null"));
        }

        uint32_t imageId = InterpreterImage::AllocImageIndex();
        if (imageId > kMaxLoadImageCount)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException("exceed max image index", ""));
        }
        DifferentialHybridOption options = {};
        BlobReader reader((byte*)optionData, optionCount);
        if (!options.Unmarshal(reader))
        {
            return LoadImageErrorCode::DIFFERENTIAL_HYBRID_ASSEMBLY_BAD_OPTION_DATA;
        }
        DifferentialHybridImage* image = new DifferentialHybridImage(imageId, options);

        assemblyData = (const byte*)CopyBytes(assemblyData, length);
        LoadImageErrorCode err = image->Load(assemblyData, (size_t)length);


        if (err != LoadImageErrorCode::OK)
        {
            IL2CPP_FREE((void*)assemblyData);
            TEMP_FORMAT(errMsg, "LoadImageErrorCode:%d", (int)err);
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetBadImageFormatException(errMsg));
            // when load a bad image, mean a fatal error. we don't clean image on purpose.
        }

        TbAssembly data = image->GetRawImage().ReadAssembly(1);
        const char* nameNoExt = image->GetStringFromRawIndex(data.name);
        Il2CppAssembly* aotAss = const_cast<Il2CppAssembly*>(il2cpp::vm::Assembly::GetLoadedAssembly(nameNoExt));
        // FIXME. not free memory.
        if (!aotAss)
        {
            return LoadImageErrorCode::AOT_ASSEMBLY_NOT_FIND;
        }
        if (IsInterpreterImage(aotAss->image))
        {
            return LoadImageErrorCode::DIFFERENTIAL_HYBRID_ASSEMBLY_ONLY_SUPPORT_AOT_ASSEMBLY;
        }
        if (!aotAss->originAssembly)
        {
            return LoadImageErrorCode::DIFFERENTIAL_HYBRID_ASSEMBLY_HAS_BEEN_LOADED;
        }

        Il2CppAssembly* ass;
        Il2CppImage* image2;
        ass = new (IL2CPP_MALLOC_ZERO(sizeof(Il2CppAssembly))) Il2CppAssembly;
        image2 = new (IL2CPP_MALLOC_ZERO(sizeof(Il2CppImage))) Il2CppImage;


        image2->assembly = ass;
        image->InitBasic(image2);
        image->BuildIl2CppAssembly(ass);
        ass->image = image2;

        image->BuildIl2CppImage(image2, aotAss->originAssembly);
        image2->name = ConcatNewString(ass->aname.name, ".dll");
        image2->nameNoExt = ass->aname.name;

        image->InitRuntimeMetadatas();

        // swap aot assembly

        Il2CppAssembly* originAssembly = aotAss->originAssembly;
        Il2CppImage* aotImage = aotAss->image;
        *aotAss = *ass;
        *aotImage = *image2;

        aotAss->image = aotImage;
        aotImage->assembly = aotAss;

        aotAss->originAssembly = originAssembly;

        return LoadImageErrorCode::OK;
    }
}
}
