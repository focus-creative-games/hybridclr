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
#include "Image.h"

namespace hybridclr
{
namespace metadata
{
struct AOTFieldData
{
    uint32_t typeDefIndex; // rowIndex - 1
    FieldIndex fieldIndex;
};

enum class HomologousImageMode
{
    CONSISTENT,
    SUPERSET,
};

class AOTHomologousImage : public Image
{
  public:
    static AOTHomologousImage* FindImageByAssembly(const Il2CppAssembly* ass);
    static AOTHomologousImage* FindImageByAssemblyLocked(const Il2CppAssembly* ass, il2cpp::os::FastAutoLock& lock);
    static void RegisterLocked(AOTHomologousImage* image, il2cpp::os::FastAutoLock& lock);

    AOTHomologousImage() : _targetAssembly(nullptr)
    {
    }

    const Il2CppAssembly* GetTargetAssembly() const
    {
        return _targetAssembly;
    }

    void SetTargetAssembly(const Il2CppAssembly* targetAssembly)
    {
        _targetAssembly = targetAssembly;
    }

    LoadImageErrorCode Load(const byte* imageData, size_t length);

    const Il2CppType* GetModuleIl2CppType(uint32_t moduleRowIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound) override;

  protected:
    const Il2CppAssembly* _targetAssembly;
};
} // namespace metadata
} // namespace hybridclr