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

#include "ClassFieldLayoutCalculator.h"

#include "metadata/FieldLayout.h"
#include "metadata/GenericMetadata.h"
#include "vm/Field.h"
#include "vm/GlobalMetadata.h"

#include "InterpreterImage.h"
#include "MetadataModule.h"

namespace hybridclr
{
namespace metadata
{
typedef void* voidptr_t;
#define IL2CPP_ALIGN_STRUCT(type) \
    struct type##AlignStruct      \
    {                             \
        uint8_t pad;              \
        type t;                   \
    };

IL2CPP_ALIGN_STRUCT(voidptr_t)
IL2CPP_ALIGN_STRUCT(int8_t)
IL2CPP_ALIGN_STRUCT(int16_t)
IL2CPP_ALIGN_STRUCT(int32_t)
IL2CPP_ALIGN_STRUCT(int64_t)
IL2CPP_ALIGN_STRUCT(intptr_t)
IL2CPP_ALIGN_STRUCT(float)
IL2CPP_ALIGN_STRUCT(double)

#define IL2CPP_ALIGN_OF(type) ((int32_t)offsetof(type##AlignStruct, t))

SizeAndAlignment ClassFieldLayoutCalculator::GetTypeSizeAndAlignment(const Il2CppType* type)
{
    SizeAndAlignment sa = {};
    if (type->byref)
    {
        sa.size = sa.nativeSize = sizeof(voidptr_t);
        sa.alignment = IL2CPP_ALIGN_OF(voidptr_t);
        return sa;
    }

    switch (type->type)
    {
    case IL2CPP_TYPE_I1:
    case IL2CPP_TYPE_U1:
    case IL2CPP_TYPE_BOOLEAN:
        sa.size = sa.nativeSize = sizeof(int8_t);
        sa.alignment = IL2CPP_ALIGN_OF(int8_t);
        return sa;
    case IL2CPP_TYPE_I2:
    case IL2CPP_TYPE_U2:
    case IL2CPP_TYPE_CHAR:
        sa.size = sa.nativeSize = sizeof(int16_t);
        sa.alignment = IL2CPP_ALIGN_OF(int16_t);
        return sa;
    case IL2CPP_TYPE_I4:
    case IL2CPP_TYPE_U4:
        sa.size = sa.nativeSize = sizeof(int32_t);
        sa.alignment = IL2CPP_ALIGN_OF(int32_t);
        return sa;
    case IL2CPP_TYPE_I8:
    case IL2CPP_TYPE_U8:
        sa.size = sa.nativeSize = sizeof(int64_t);
        sa.alignment = IL2CPP_ALIGN_OF(int64_t);
        return sa;
    case IL2CPP_TYPE_I:
    case IL2CPP_TYPE_U:
        // TODO should we use pointer or int32_t here?
        sa.size = sa.nativeSize = sizeof(intptr_t);
        sa.alignment = IL2CPP_ALIGN_OF(intptr_t);
        return sa;
    case IL2CPP_TYPE_R4:
        sa.size = sa.nativeSize = sizeof(float);
        sa.alignment = IL2CPP_ALIGN_OF(float);
        return sa;
    case IL2CPP_TYPE_R8:
        sa.size = sa.nativeSize = sizeof(double);
        sa.alignment = IL2CPP_ALIGN_OF(double);
        return sa;
    case IL2CPP_TYPE_PTR:
    case IL2CPP_TYPE_FNPTR:
    case IL2CPP_TYPE_STRING:
    case IL2CPP_TYPE_SZARRAY:
    case IL2CPP_TYPE_ARRAY:
    case IL2CPP_TYPE_CLASS:
    case IL2CPP_TYPE_OBJECT:
        sa.size = sa.nativeSize = sizeof(voidptr_t);
        sa.alignment = IL2CPP_ALIGN_OF(voidptr_t);
        return sa;
    case IL2CPP_TYPE_VAR:
    case IL2CPP_TYPE_MVAR:
        sa.size = sa.nativeSize = 1;
        sa.alignment = 1;
        return sa;
    case IL2CPP_TYPE_VALUETYPE:
    {
        CalcClassNotStaticFields(type);
        ClassLayoutInfo& classLayout = *_classMap[type];
        sa.size = classLayout.instanceSize - sizeof(Il2CppObject);
        sa.nativeSize = classLayout.nativeSize;
        sa.alignment = classLayout.alignment;
        return sa;
    }
    case IL2CPP_TYPE_GENERICINST:
    {
        Il2CppGenericClass* gclass = type->data.generic_class;
        // Il2CppClass* container_class = GenericClass::GetTypeDefinition(gclass);
        const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
        if (IsValueType(typeDef))
        {
            CalcClassNotStaticFields(type);
            ClassLayoutInfo& classLayout = *_classMap[type];
            sa.size = classLayout.instanceSize - sizeof(Il2CppObject);
            sa.nativeSize = classLayout.nativeSize;
            sa.alignment = classLayout.alignment;
        }
        else
        {
            sa.size = sa.nativeSize = sizeof(voidptr_t);
            sa.alignment = IL2CPP_ALIGN_OF(voidptr_t);
        }
        return sa;
    }
    default:
        IL2CPP_ASSERT(0);
        break;
    }
    return sa;
}

static int32_t AlignTo(int32_t size, int32_t alignment)
{
    if (size & (alignment - 1))
    {
        size += alignment - 1;
        size &= ~(alignment - 1);
    }

    return size;
}

void ClassFieldLayoutCalculator::LayoutFields(int32_t actualParentSize, int32_t parentAlignment, uint8_t packing, std::vector<FieldLayout*>& fields,
                                              FieldLayoutData& data)
{
    // data.classSize = parentSize;
    data.actualClassSize = actualParentSize;
    IL2CPP_ASSERT(parentAlignment <= std::numeric_limits<uint8_t>::max());
    data.minimumAlignment = static_cast<uint8_t>(parentAlignment);
    data.nativeSize = 0;
    for (FieldLayout* field : fields)
    {
        SizeAndAlignment sa = GetTypeSizeAndAlignment(field->type);
        field->size = sa.size; // sa.nativeSize > 0 ? sa.nativeSize : sa.size;

        // For fields, we might not want to take the actual alignment of the type - that might account for
        // packing. When a type is used as a field, we should not care about its alignment with packing,
        // instead let's use its natural alignment, without regard for packing. So if it's alignment
        // is less than the compiler's minimum alignment (4 bytes), lets use the natural alignment if we have it.
        uint8_t alignment = sa.alignment;
        if (packing != 0)
            alignment = std::min(sa.alignment, packing);
        int32_t offset = data.actualClassSize;

        offset += alignment - 1;
        offset &= ~(alignment - 1);
        field->offset = offset;

        data.FieldOffsets.push_back(offset);
        data.actualClassSize = offset + std::max(sa.size, (int32_t)1);
        data.minimumAlignment = std::max(data.minimumAlignment, alignment);
        data.nativeSize += sa.size;
    }

    data.classSize = AlignTo(data.actualClassSize, data.minimumAlignment);

    // C++ ABI difference between MS and Clang
#if IL2CPP_CXX_ABI_MSVC
    data.actualClassSize = data.classSize;
#endif
}

bool ClassFieldLayoutCalculator::IsBlittable(const Il2CppType* type)
{
    if (type->byref)
    {
        return true;
    }

    switch (type->type)
    {
    case IL2CPP_TYPE_I1:
    case IL2CPP_TYPE_U1:
    case IL2CPP_TYPE_BOOLEAN:
    case IL2CPP_TYPE_I2:
    case IL2CPP_TYPE_U2:
    case IL2CPP_TYPE_CHAR:
    case IL2CPP_TYPE_I4:
    case IL2CPP_TYPE_U4:
    case IL2CPP_TYPE_I8:
    case IL2CPP_TYPE_U8:
    case IL2CPP_TYPE_I:
    case IL2CPP_TYPE_U:
    case IL2CPP_TYPE_R4:
    case IL2CPP_TYPE_R8:
    case IL2CPP_TYPE_PTR:
    case IL2CPP_TYPE_FNPTR:
        return true;
    case IL2CPP_TYPE_STRING:
    case IL2CPP_TYPE_SZARRAY:
    case IL2CPP_TYPE_ARRAY:
    case IL2CPP_TYPE_CLASS:
    case IL2CPP_TYPE_OBJECT:
    case IL2CPP_TYPE_VAR:
    case IL2CPP_TYPE_MVAR:
        return false;
    case IL2CPP_TYPE_VALUETYPE:
    {
        CalcClassNotStaticFields(type);
        ClassLayoutInfo& classLayout = *_classMap[type];
        return classLayout.blittable;
    }
    case IL2CPP_TYPE_GENERICINST:
    {
        const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
        if (IsValueType(typeDef))
        {
            CalcClassNotStaticFields(type);
            ClassLayoutInfo& classLayout = *_classMap[type];
            return classLayout.blittable;
        }
        else
        {
            return false;
        }
    }
    default:
        IL2CPP_ASSERT(0);
        return false;
    }
}

inline bool IsRawNormalStaticField(const Il2CppType* type, int32_t offset)
{
    if ((type->attrs & FIELD_ATTRIBUTE_STATIC) == 0)
        return false;

    if (offset == THREAD_LOCAL_STATIC_MASK)
        return false;

    if ((type->attrs & FIELD_ATTRIBUTE_LITERAL) != 0)
        return false;

    return true;
}

inline bool IsRawThreadStaticField(const Il2CppType* type, int32_t offset)
{
    if ((type->attrs & FIELD_ATTRIBUTE_STATIC) == 0)
        return false;

    if (offset != THREAD_LOCAL_STATIC_MASK)
        return false;

    if ((type->attrs & FIELD_ATTRIBUTE_LITERAL) != 0)
        return false;

    return true;
}

void ClassFieldLayoutCalculator::CalcClassNotStaticFields(const Il2CppType* type)
{
    auto it = _classMap.find(type);
    if (it != _classMap.end())
    {
        return;
    }
    ClassLayoutInfo& layout = *(_classMap[type] = new (HYBRIDCLR_MALLOC_ZERO(sizeof(ClassLayoutInfo))) ClassLayoutInfo());
    layout.type = type;
    const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
    const char* typeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
    std::vector<FieldLayout>& fields = layout.fields;
    fields.resize(typeDef->field_count, {});

    bool isCurAssemblyType = DecodeImageIndex(typeDef->byvalTypeIndex) == _image->GetIndex();
    if ((type->type == IL2CPP_TYPE_VALUETYPE || type->type == IL2CPP_TYPE_CLASS) && !isCurAssemblyType)
    {
        Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
        il2cpp::vm::Class::SetupFields(klass);
        layout.instanceSize = klass->instance_size;
        layout.actualSize = klass->actualSize;
        layout.nativeSize = klass->native_size;
        layout.alignment = klass->minimumAlignment;
        layout.blittable = il2cpp::vm::Class::IsBlittable(klass);
        return;
    }

    const Il2CppGenericContext* gc = type->type == IL2CPP_TYPE_GENERICINST ? &type->data.generic_class->context : nullptr;
    for (uint16_t i = 0; i < typeDef->field_count; i++)
    {
        Il2CppFieldDefinition* fieldDef = (Il2CppFieldDefinition*)il2cpp::vm::GlobalMetadata::GetFieldDefinitionFromTypeDefAndFieldIndex(typeDef, i);
        const Il2CppType* fieldType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(fieldDef->typeIndex);
        const Il2CppType* inflatedFieldType = gc ? TryInflateIfNeed(fieldType, gc, true) : fieldType;
        FieldLayout& fieldLayout = fields[i];
        fieldLayout.type = inflatedFieldType;
        if (isCurAssemblyType)
        {
            int32_t offset = _image->GetFieldOffset(typeDef, i);
            fieldLayout.offset = offset;
            fieldLayout.isNormalStatic = IsRawNormalStaticField(inflatedFieldType, offset);
            fieldLayout.isThreadStatic = IsRawThreadStaticField(inflatedFieldType, offset);
        }
        else
        {
            Il2CppClass* klass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)typeDef);
            il2cpp::vm::Class::SetupFields(klass);
            FieldInfo* fieldInfo = klass->fields + i;
            fieldLayout.offset = fieldInfo->offset;
            fieldLayout.isNormalStatic = il2cpp::vm::Field::IsNormalStatic(fieldInfo);
            fieldLayout.isThreadStatic = il2cpp::vm::Field::IsThreadStatic(fieldInfo);
        }
    }

    if (IsNotFullyInstantiatedType(type))
    {
        layout.instanceSize = 0;
        layout.actualSize = 0;
        layout.nativeSize = -1;
        layout.alignment = 1;
        layout.blittable = false;
        return;
    }

    uint8_t packingSize = 0;
    int32_t layoutClassSize = 0;
    if (IsInterpreterType(typeDef))
    {
        auto classLayoutData = MetadataModule::GetImage(typeDef)->GetClassLayout(typeDef);
        packingSize = (uint8_t)classLayoutData.packingSize;
        layoutClassSize = (int32_t)classLayoutData.classSize;
    }
    else
    {
        packingSize = (uint8_t)il2cpp::vm::GlobalMetadata::StructLayoutPack((Il2CppMetadataTypeHandle)typeDef);
    }
    int32_t classSizeWithHeader = layoutClassSize + sizeof(Il2CppObject);

    std::vector<FieldLayout*> instanceFields;
    bool blittable = true;
    for (FieldLayout& field : fields)
    {
        if (IsInstanceField(field.type))
        {
            instanceFields.push_back(&field);
            blittable &= IsBlittable(field.type);
        }
    }
    layout.blittable = blittable;

    // If the type is not blittable, ignore packingSize
    if (!blittable)
    {
        packingSize = 0;
    }
    // packingSize is ignored for auto layout types
    if (!(typeDef->flags & (TYPE_ATTRIBUTE_SEQUENTIAL_LAYOUT | TYPE_ATTRIBUTE_EXPLICIT_LAYOUT)))
    {
        packingSize = 0;
    }

    if (typeDef->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT)
    {
        IL2CPP_ASSERT(IsValueType(typeDef));
        IL2CPP_ASSERT(isCurAssemblyType);
        int32_t instanceSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS + sizeof(Il2CppObject);
        if (layoutClassSize > 0)
        {
            instanceSize = std::max(instanceSize, classSizeWithHeader);
        }
        int32_t maxAlignment = 1;
        int32_t nativeSize = 1;
        for (FieldLayout* field : instanceFields)
        {
            SizeAndAlignment sa = GetTypeSizeAndAlignment(field->type);
            bool fieldBlittable = IsBlittable(field->type);
            if (!fieldBlittable && field->offset % PTR_SIZE != 0)
            {
                TEMP_FORMAT(errMsg, "Type %s is not blittable and has an invalid layout", typeName);
                RaiseExecutionEngineException(errMsg);
            }
            instanceSize = std::max(instanceSize, field->offset + (int32_t)sa.size);

            // compute size of alignment field
            uint8_t actualAlignment = packingSize != 0 ? std::min(packingSize, sa.alignment) : sa.alignment;
            instanceSize = std::max(instanceSize, AlignTo(field->offset, actualAlignment) + (int32_t)sa.size);

            maxAlignment = std::max(maxAlignment, (int32_t)sa.alignment);
            if (packingSize != 0)
            {
                maxAlignment = std::min(maxAlignment, (int32_t)packingSize);
            }
            nativeSize = AlignTo(std::max(nativeSize, field->offset + sa.nativeSize - (int32_t)sizeof(Il2CppObject)), maxAlignment);
        }
        layout.alignment = maxAlignment;
        layout.actualSize = layout.instanceSize = AlignTo(instanceSize, layout.alignment);
        layout.nativeSize = nativeSize;
        if (layoutClassSize > 0)
        {
            layout.actualSize = std::max(layout.actualSize, classSizeWithHeader);
            layout.instanceSize = std::max(layout.instanceSize, classSizeWithHeader);
            layout.nativeSize = std::max((int32_t)layoutClassSize, layout.nativeSize);
        }
    }
    else
    {
        uint8_t parentMinimumAligment;
        int32_t parentActualSize = 0;
        bool isValueType = IsValueType(typeDef);
        if (typeDef->parentIndex != kInvalidIndex)
        {
            if (isValueType)
            {
                parentMinimumAligment = 1;
                parentActualSize = sizeof(Il2CppObject);
            }
            else
            {
                const Il2CppType* parentType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->parentIndex);
                parentType = TryInflateIfNeed(parentType, gc, true);
                CalcClassNotStaticFields(parentType);
                ClassLayoutInfo* parentLayout = GetClassLayoutInfo(parentType);
                parentActualSize = parentLayout->actualSize;
                parentMinimumAligment = parentLayout->alignment;
            }
        }
        else
        {
            parentActualSize = sizeof(Il2CppObject);
            parentMinimumAligment = PTR_SIZE;
        }

        FieldLayoutData layoutData;
        LayoutFields(parentActualSize, parentMinimumAligment, packingSize, instanceFields, layoutData);
        if (instanceFields.empty() && isValueType)
        {
            layoutData.classSize = layoutData.actualClassSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS + sizeof(Il2CppObject);
            layoutData.nativeSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS;
        }
        layout.alignment = layoutData.minimumAlignment;
        layout.actualSize = layoutData.actualClassSize;
        layout.instanceSize = layoutData.classSize;
        layout.nativeSize = AlignTo(layoutData.nativeSize, layout.alignment);

        if (!isValueType)
        {
            layout.nativeSize = -1;
        }
        if (layoutClassSize > 0)
        {
            layout.actualSize = std::max(layout.actualSize, classSizeWithHeader);
            layout.instanceSize = std::max(layout.instanceSize, classSizeWithHeader);
            layout.nativeSize = isValueType ? std::max((int32_t)layoutClassSize, layout.nativeSize) : -1;
        }
    }
}

void ClassFieldLayoutCalculator::CalcClassStaticFields(const Il2CppType* type)
{
    IL2CPP_ASSERT(_classMap.find(type) != _classMap.end());
    ClassLayoutInfo& layout = *_classMap[type];

    std::vector<FieldLayout*> staticFields;
    std::vector<FieldLayout*> threadStaticFields;

    for (FieldLayout& field : layout.fields)
    {
        if (field.isNormalStatic)
        {
            staticFields.push_back(&field);
        }
        else if (field.isThreadStatic)
        {
            threadStaticFields.push_back(&field);
        }
    }
    if (!staticFields.empty())
    {
        FieldLayoutData staticLayoutData;
        LayoutFields(0, 1, 0, staticFields, staticLayoutData);
        layout.staticFieldsSize = staticLayoutData.classSize;
    }
    if (!threadStaticFields.empty())
    {
        FieldLayoutData threadStaticLayoutData;
        LayoutFields(0, 1, 0, threadStaticFields, threadStaticLayoutData);
        layout.threadStaticFieldsSize = threadStaticLayoutData.classSize;
        for (FieldLayout* field : threadStaticFields)
        {
            field->offset = field->offset | THREAD_LOCAL_STATIC_MASK;
        }
    }
}
} // namespace metadata
} // namespace hybridclr