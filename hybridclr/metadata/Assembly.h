#pragma once

#include "../CommonDef.h"

#include "InterpreterImage.h"
#include "AOTHomologousImage.h"

namespace hybridclr
{
namespace metadata
{

    class Assembly
    {
    public:
        static void InitializePlaceHolderAssemblies();
        static Il2CppAssembly* LoadFromBytes(const void* assemblyData, uint64_t length, const void* rawSymbolStoreBytes, uint64_t rawSymbolStoreLength);
        static LoadImageErrorCode LoadMetadataForAOTAssembly(const void* dllBytes, uint32_t dllSize, HomologousImageMode mode);
    private:
        static Il2CppAssembly* Create(const byte* assemblyData, uint64_t length, const byte* rawSymbolStoreBytes, uint64_t rawSymbolStoreLength);
    };
}
}