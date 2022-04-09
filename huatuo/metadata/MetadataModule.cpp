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


using namespace il2cpp;

namespace huatuo
{

namespace metadata
{

    uint32_t MetadataModule::s_cliImageCount = 0;
    Image* MetadataModule::s_images[kMaxLoadImageCount + 1] = {};

    void MetadataModule::Initialize()
    {
        s_cliImageCount = 0;
        std::memset(s_images, 0, sizeof(Assembly*) * (kMaxLoadImageCount + 1));
    }

    uint32_t MetadataModule::AllocImageIndex()
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
        return ++s_cliImageCount;
    }

    void MetadataModule::RegisterImage(Image* image)
    {
        il2cpp::os::Atomic::FullMemoryBarrier();
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
        IL2CPP_ASSERT(image->GetIndex() > 0);
        s_images[image->GetIndex()] = image;
    }

    Il2CppClass* MetadataModule::GetTypeInfoFromTypeDefinitionEncodeIndex(TypeDefinitionIndex index)
    {
        uint32_t imageIndex = DecodeImageIndex(index);
        IL2CPP_ASSERT(imageIndex > 0);

        uint32_t rawIndex = DecodeMetadataIndex(index);
        return s_images[imageIndex]->GetTypeInfoFromTypeDefinitionRawIndex(rawIndex);
    }
}
}
