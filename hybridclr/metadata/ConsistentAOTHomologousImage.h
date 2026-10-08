// Copyright 2026 Code Philosophy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "AOTHomologousImage.h"

namespace hybridclr
{
namespace metadata
{

class ConsistentAOTHomologousImage : public AOTHomologousImage
{
  public:
    ConsistentAOTHomologousImage() : AOTHomologousImage()
    {
    }

    void InitRuntimeMetadatas() override;

    void InitTypes();
    void InitMethods();
    void InitFields();

    MethodBody* GetMethodBody(uint32_t token) override;
    const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index) override;
    Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index) override;
    Il2CppGenericContainer* GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex) override;
    const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index) override;
    void ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret) override;

  private:
    std::vector<const Il2CppType*> _il2cppTypeForTypeDefs;
    std::vector<Il2CppTypeDefinition*> _typeDefs;

    std::vector<const Il2CppMethodDefinition*> _methodDefs;

    std::vector<AOTFieldData> _fields;
};
} // namespace metadata
} // namespace hybridclr