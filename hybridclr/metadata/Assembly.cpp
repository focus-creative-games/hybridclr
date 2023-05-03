
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
            char* name = (char*)IL2CPP_MALLOC(nameLen + 1);
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
        auto ass = new (IL2CPP_MALLOC_ZERO(sizeof(Il2CppAssembly))) Il2CppAssembly;
        auto image2 = new (IL2CPP_MALLOC_ZERO(sizeof(Il2CppImage))) Il2CppImage;
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
            IL2CPP_FREE((void*)nameWithExtension);
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

    Il2CppAssembly* Assembly::LoadFromBytes(const void* assemblyData, uint64_t length, bool copyData)
    {
        Il2CppAssembly* ass = Create((const byte*)assemblyData, length, copyData);
        if (ass)
        {
            RunModuleInitializer(ass->image);
        }
        return ass;
    }

    Il2CppAssembly* Assembly::Create(const byte* assemblyData, uint64_t length, bool copyData)
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
        if (!assemblyData)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentNullException("rawAssembly is null"));
        }

        uint32_t imageId = InterpreterImage::AllocImageIndex();
        if (imageId > kMaxLoadImageCount)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException("exceed max image index", ""));
        }
        InterpreterImage* image = new InterpreterImage(imageId);
        
        if (copyData)
        {
            assemblyData = (const byte*)CopyBytes(assemblyData, length);
        }
        LoadImageErrorCode err = image->Load(assemblyData, (size_t)length);


        if (err != LoadImageErrorCode::OK)
        {
            if (copyData)
            {
                IL2CPP_FREE((void*)assemblyData);
            }
            TEMP_FORMAT(errMsg, "LoadImageErrorCode:%d", (int)err);
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetBadImageFormatException(errMsg));
            // when load a bad image, mean a fatal error. we don't clean image on purpose.
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
            IL2CPP_FREE((void*)ass->image->name);
            IL2CPP_FREE((void*)ass->image->nameNoExt);
        }
        else
        {
            ass = new (IL2CPP_MALLOC_ZERO(sizeof(Il2CppAssembly))) Il2CppAssembly;
            image2 = new (IL2CPP_MALLOC_ZERO(sizeof(Il2CppImage))) Il2CppImage;
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
}
}

