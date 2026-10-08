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

#include <vector>

#include "MetadataUtil.h"

namespace hybridclr
{
namespace metadata
{

struct FieldLayout
{
    const Il2CppType* type;
    int32_t offset;
    int32_t size;
    bool isNormalStatic;
    bool isThreadStatic;
};

struct ClassLayoutInfo
{
    const Il2CppType* type;
    std::vector<FieldLayout> fields;
    int32_t instanceSize;
    int32_t actualSize;
    int32_t nativeSize;
    uint32_t staticFieldsSize;
    uint32_t threadStaticFieldsSize;
    uint8_t alignment;
    bool blittable;
};

struct SizeAndAlignment
{
    int32_t size;
    int32_t nativeSize;
    uint8_t alignment;
};

struct FieldLayoutData
{
    std::vector<size_t> FieldOffsets;
    int32_t classSize;
    int32_t actualClassSize;
    int32_t nativeSize;

    uint8_t minimumAlignment;
};

class InterpreterImage;

typedef Il2CppHashMap<const Il2CppType*, ClassLayoutInfo*, il2cpp::metadata::Il2CppTypeHash, il2cpp::metadata::Il2CppTypeEqualityComparer>
    Il2CppType2ClassLayoutInfoMap;

class ClassFieldLayoutCalculator
{
  private:
    InterpreterImage* _image;
    Il2CppType2ClassLayoutInfoMap _classMap;

  public:
    ClassFieldLayoutCalculator(InterpreterImage* image) : _image(image)
    {
    }

    ~ClassFieldLayoutCalculator()
    {
        for (auto it : _classMap)
        {
            ClassLayoutInfo* info = it.second;
            info->~ClassLayoutInfo();
            HYBRIDCLR_FREE(info);
        }
    }

    ClassLayoutInfo* GetClassLayoutInfo(const Il2CppType* type)
    {
        auto it = _classMap.find(type);
        return it != _classMap.end() ? it->second : nullptr;
    }

    void CalcClassNotStaticFields(const Il2CppType* type);
    void CalcClassStaticFields(const Il2CppType* type);

    void LayoutFields(int32_t actualParentSize, int32_t parentAlignment, uint8_t packing, std::vector<FieldLayout*>& fields, FieldLayoutData& data);
    SizeAndAlignment GetTypeSizeAndAlignment(const Il2CppType* type);
    bool IsBlittable(const Il2CppType* type);
};
} // namespace metadata
} // namespace hybridclr