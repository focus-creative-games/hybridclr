
#include "Assembly.h"

#include <cstring>
#include <iostream>
#include <vector>

#include "os/File.h"
#include "utils/MemoryMappedFile.h"
#include "vm/Assembly.h"
#include "vm/Image.h"
#include "vm/Class.h"
#include "vm/String.h"
#include "vm/MetadataLock.h"

#include "Image.h"
#include "MetadataModule.h"
#include "MetadataUtil.h"
#include "ConsistentAOTHomologousImage.h"
#include "SuperSetAOTHomologousImage.h"

namespace hybridclr
{
namespace metadata
{

    std::vector<Il2CppAssembly*> s_placeHolderAssembies;

#if ENABLE_PLACEHOLDER_DLL == 1

    static const char* CreateAssemblyNameWithoutExt(const char* assemblyName)
    {
        const char* extStr = std::strstr(assemblyName, ".dll");
        if (extStr)
        {
            size_t nameLen = extStr - assemblyName;
            char* name = (char*)HYBRIDCLR_MALLOC(nameLen + 1);
            std::strncpy(name, assemblyName, nameLen);
            name[nameLen] = '\0';
            return name;
        }
        else
        {
            return CopyString(assemblyName);
        }
    }

    static Il2CppAssembly* CreatePlaceHolderAssembly(const char* assemblyName)
    {
        auto ass = new (HYBRIDCLR_MALLOC_ZERO(sizeof(Il2CppAssembly))) Il2CppAssembly;
        auto image2 = new (HYBRIDCLR_MALLOC_ZERO(sizeof(Il2CppImage))) Il2CppImage;
        ass->image = image2;
        ass->image->name = CopyString(assemblyName);
        ass->image->nameNoExt = ass->aname.name = CreateAssemblyNameWithoutExt(assemblyName);
        image2->assembly = ass;
        s_placeHolderAssembies.push_back(ass);
        return ass;
    }

    static Il2CppAssembly* FindPlaceHolderAssembly(const char* assemblyNameNoExt)
    {
        for (Il2CppAssembly* ass : s_placeHolderAssembies)
        {
            if (std::strcmp(ass->image->nameNoExt, assemblyNameNoExt) == 0)
            {
                return ass;
            }
        }
        return nullptr;
    }
#else
    static Il2CppAssembly* FindPlaceHolderAssembly(const char* assemblyNameNoExt)
    {
        return nullptr;
    }
#endif

    void Assembly::InitializePlaceHolderAssemblies()
    {
        for (const char** ptrPlaceHolderName = g_placeHolderAssemblies; *ptrPlaceHolderName; ++ptrPlaceHolderName)
        {
            const char* nameWithExtension = ConcatNewString(*ptrPlaceHolderName, ".dll");
            Il2CppAssembly* placeHolderAss = CreatePlaceHolderAssembly(nameWithExtension);
            HYBRIDCLR_FREE((void*)nameWithExtension);
            il2cpp::vm::MetadataCache::RegisterInterpreterAssembly(placeHolderAss);
        }
    }

    static void RunModuleInitializer(Il2CppImage* image)
    {
        Il2CppClass* moduleKlass = il2cpp::vm::Image::ClassFromName(image, "", "<Module>");
        if (!moduleKlass)
        {
            return;
        }
        il2cpp::vm::Runtime::ClassInit(moduleKlass);
    }

    Il2CppAssembly* Assembly::LoadFromBytes(const void* assemblyData, uint64_t length, const void* rawSymbolStoreBytes, uint64_t rawSymbolStoreLength)
    {
        Il2CppAssembly* ass = Create((const byte*)assemblyData, length, (const byte*)rawSymbolStoreBytes, rawSymbolStoreLength);
        RunModuleInitializer(ass->image);
        return ass;
    }

    Il2CppAssembly* Assembly::Create(const byte* assemblyData, uint64_t length, const byte* rawSymbolStoreBytes, uint64_t rawSymbolStoreLength)
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

        if (!assemblyData)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentNullException("rawAssembly is null"));
        }

        uint32_t imageId = InterpreterImage::AllocImageIndex((uint32_t)length);
        if (imageId == kInvalidImageIndex)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException("InterpreterImage::AllocImageIndex failed"));
        }
        InterpreterImage* image = new InterpreterImage(imageId);
        
        assemblyData = (const byte*)CopyBytes(assemblyData, length);
        LoadImageErrorCode err = image->Load(assemblyData, (size_t)length);

        if (err != LoadImageErrorCode::OK)
        {
            TEMP_FORMAT(errMsg, "LoadImageErrorCode:%d", (int)err);
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetBadImageFormatException(errMsg));
            // when load a bad image, mean a fatal error. we don't clean image on purpose.
        }

        if (rawSymbolStoreBytes)
        {
            rawSymbolStoreBytes = (const byte*)CopyBytes(rawSymbolStoreBytes, rawSymbolStoreLength);
            err = image->LoadPDB(rawSymbolStoreBytes, (size_t)rawSymbolStoreLength);
            if (err != LoadImageErrorCode::OK)
            {
                TEMP_FORMAT(errMsg, "LoadPDB Error:%d", (int)err);
                il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetBadImageFormatException(errMsg));
            }
        }

        TbAssembly data = image->GetRawImage().ReadAssembly(1);
        const char* nameNoExt = image->GetStringFromRawIndex(data.name);

        Il2CppAssembly* ass;
        Il2CppImage* image2;
        if ((ass = FindPlaceHolderAssembly(nameNoExt)) != nullptr)
        {
            if (ass->token)
            {
                RaiseExecutionEngineException("reloading placeholder assembly is not supported!");
            }
            image2 = ass->image;
            HYBRIDCLR_FREE((void*)ass->image->name);
            HYBRIDCLR_FREE((void*)ass->image->nameNoExt);
        }
        else
        {
            ass = new (HYBRIDCLR_MALLOC_ZERO(sizeof(Il2CppAssembly))) Il2CppAssembly;
            image2 = new (HYBRIDCLR_MALLOC_ZERO(sizeof(Il2CppImage))) Il2CppImage;
        }

        image->InitBasic(image2);
        image->BuildIl2CppAssembly(ass);
        ass->image = image2;

        image->BuildIl2CppImage(image2);
        image2->name = ConcatNewString(ass->aname.name, ".dll");
        image2->nameNoExt = ass->aname.name;
        image2->assembly = ass;

        image->InitRuntimeMetadatas();
        return ass;
    }

    LoadImageErrorCode Assembly::LoadMetadataForAOTAssembly(const void* dllBytes, uint32_t dllSize, HomologousImageMode mode)
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
            delete image;
            return err;
        }

        RawImageBase* rawImage = &image->GetRawImage();
        TbAssembly data = rawImage->ReadAssembly(1);
        const char* assName = rawImage->GetStringFromRawIndex(data.name);
        const Il2CppAssembly* aotAss = il2cpp::vm::Assembly::GetLoadedAssembly(assName);
        // FIXME. not free memory.
        if (!aotAss)
        {
            delete image;
            return LoadImageErrorCode::AOT_ASSEMBLY_NOT_FIND;
        }
        if (hybridclr::metadata::IsInterpreterImage(aotAss->image))
        {
            delete image;
            return LoadImageErrorCode::HOMOLOGOUS_ONLY_SUPPORT_AOT_ASSEMBLY;
        }
        image->SetTargetAssembly(aotAss);
        if (AOTHomologousImage::FindImageByAssemblyLocked(image->GetTargetAssembly(), lock))
        {
            return LoadImageErrorCode::HOMOLOGOUS_ASSEMBLY_HAS_BEEN_LOADED;
        }
        image->InitRuntimeMetadatas();
        AOTHomologousImage::RegisterLocked(image, lock);
        return LoadImageErrorCode::OK;
    }


}
}

