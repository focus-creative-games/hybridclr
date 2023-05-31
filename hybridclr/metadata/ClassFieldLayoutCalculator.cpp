#include "ClassFieldLayoutCalculator.h"

#include "metadata/FieldLayout.h"
#include "vm/Field.h"

#include "InterpreterImage.h"

namespace hybridclr
{
namespace metadata
{
    typedef void* voidptr_t;
#define IL2CPP_ALIGN_STRUCT(type) struct type ## AlignStruct {uint8_t pad; type t; };

    IL2CPP_ALIGN_STRUCT(voidptr_t)
        IL2CPP_ALIGN_STRUCT(int8_t)
        IL2CPP_ALIGN_STRUCT(int16_t)
        IL2CPP_ALIGN_STRUCT(int32_t)
        IL2CPP_ALIGN_STRUCT(int64_t)
        IL2CPP_ALIGN_STRUCT(intptr_t)
        IL2CPP_ALIGN_STRUCT(float)
        IL2CPP_ALIGN_STRUCT(double)

#define IL2CPP_ALIGN_OF(type) ((int32_t)offsetof(type ## AlignStruct, t))

    SizeAndAlignment ClassFieldLayoutCalculator::GetTypeSizeAndAlignment(const Il2CppType* type)
    {
        SizeAndAlignment sa = { };
        if (type->byref)
        {
            sa.size = sizeof(voidptr_t);
            sa.alignment = IL2CPP_ALIGN_OF(voidptr_t);
            return sa;
        }

        switch (type->type)
        {
        case IL2CPP_TYPE_I1:
        case IL2CPP_TYPE_U1:
        case IL2CPP_TYPE_BOOLEAN:
            sa.size = sizeof(int8_t);
            sa.alignment = IL2CPP_ALIGN_OF(int8_t);
            return sa;
        case IL2CPP_TYPE_I2:
        case IL2CPP_TYPE_U2:
        case IL2CPP_TYPE_CHAR:
            sa.size = sizeof(int16_t);
            sa.alignment = IL2CPP_ALIGN_OF(int16_t);
            return sa;
        case IL2CPP_TYPE_I4:
        case IL2CPP_TYPE_U4:
            sa.size = sizeof(int32_t);
            sa.alignment = IL2CPP_ALIGN_OF(int32_t);
            return sa;
        case IL2CPP_TYPE_I8:
        case IL2CPP_TYPE_U8:
            sa.size = sizeof(int64_t);
            sa.alignment = IL2CPP_ALIGN_OF(int64_t);
            return sa;
        case IL2CPP_TYPE_I:
        case IL2CPP_TYPE_U:
            // TODO should we use pointer or int32_t here?
            sa.size = sizeof(intptr_t);
            sa.alignment = IL2CPP_ALIGN_OF(intptr_t);
            return sa;
        case IL2CPP_TYPE_R4:
            sa.size = sizeof(float);
            sa.alignment = IL2CPP_ALIGN_OF(float);
            return sa;
        case IL2CPP_TYPE_R8:
            sa.size = sizeof(double);
            sa.alignment = IL2CPP_ALIGN_OF(double);
            return sa;
        case IL2CPP_TYPE_PTR:
        case IL2CPP_TYPE_FNPTR:
        case IL2CPP_TYPE_STRING:
        case IL2CPP_TYPE_SZARRAY:
        case IL2CPP_TYPE_ARRAY:
        case IL2CPP_TYPE_CLASS:
        case IL2CPP_TYPE_OBJECT:
        case IL2CPP_TYPE_VAR:
        case IL2CPP_TYPE_MVAR:
            sa.size = sizeof(voidptr_t);
            sa.alignment = IL2CPP_ALIGN_OF(voidptr_t);
            return sa;
        case IL2CPP_TYPE_VALUETYPE:
        {
            CalcClassNotStaticFields(type);
            ClassLayoutInfo& classLayout = _classMap[type];
            sa.size = classLayout.instanceSize - sizeof(Il2CppObject);
            sa.nativeSize = classLayout.nativeSize;
            sa.alignment = classLayout.alignment;
#if !HYBRIDCLR_UNITY_2022_OR_NEW
            sa.naturalAlignment = classLayout.naturalAlignment;
#endif
            return sa;
        }
        case IL2CPP_TYPE_GENERICINST:
        {
            Il2CppGenericClass* gclass = type->data.generic_class;
            //Il2CppClass* container_class = GenericClass::GetTypeDefinition(gclass);
            const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
            if (IsValueType(typeDef))
            {
                CalcClassNotStaticFields(type);
                ClassLayoutInfo& classLayout = _classMap[type];
                sa.size = classLayout.instanceSize - sizeof(Il2CppObject);
                sa.nativeSize = classLayout.nativeSize;
                sa.alignment = classLayout.alignment;
#if !HYBRIDCLR_UNITY_2022_OR_NEW
                sa.naturalAlignment = classLayout.naturalAlignment;
#endif
            }
            else
            {
                sa.size = sizeof(voidptr_t);
                sa.naturalAlignment = sa.alignment = IL2CPP_ALIGN_OF(voidptr_t);
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

    void ClassFieldLayoutCalculator::LayoutFields(int32_t actualParentSize, int32_t parentAlignment, uint8_t packing, std::vector<FieldLayout*>& fields, FieldLayoutData& data)
    {
        //data.classSize = parentSize;
        data.actualClassSize = actualParentSize;
        IL2CPP_ASSERT(parentAlignment <= std::numeric_limits<uint8_t>::max());
        data.minimumAlignment = static_cast<uint8_t>(parentAlignment);
        data.naturalAlignment = 0;
        data.nativeSize = 0;
        for (FieldLayout* field : fields)
        {
            SizeAndAlignment sa = GetTypeSizeAndAlignment(field->type);
            field->size = sa.nativeSize ? sa.nativeSize : sa.size;

            // For fields, we might not want to take the actual alignment of the type - that might account for
            // packing. When a type is used as a field, we should not care about its alignment with packing,
            // instead let's use its natural alignment, without regard for packing. So if it's alignment
            // is less than the compiler's minimum alignment (4 bytes), lets use the natural alignment if we have it.
            uint8_t alignment = sa.alignment;
            if (alignment < 4 && sa.naturalAlignment != 0)
                alignment = sa.naturalAlignment;
            if (packing != 0)
                alignment = std::min(sa.alignment, packing);
            int32_t offset = data.actualClassSize;

            offset += alignment - 1;
            offset &= ~(alignment - 1);
            field->offset = offset;

            data.FieldOffsets.push_back(offset);
            data.actualClassSize = offset + std::max(sa.size, (int32_t)1);
            data.minimumAlignment = std::max(data.minimumAlignment, alignment);
            data.naturalAlignment = std::max({ data.naturalAlignment, sa.alignment, sa.naturalAlignment });
            data.nativeSize += sa.size;
        }

        data.classSize = AlignTo(data.actualClassSize, data.minimumAlignment);

        // C++ ABI difference between MS and Clang
#if IL2CPP_CXX_ABI_MSVC
        data.actualClassSize = data.classSize;
#endif
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
		ClassLayoutInfo& layout = _classMap[type] = {};
		layout.type = type;
		const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
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
#if !HYBRIDCLR_UNITY_2022_OR_NEW
            layout.naturalAlignment = klass->naturalAligment;
#endif
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


        TbClassLayout classLayoutData = _image->GetClassLayout(typeDef);
        uint8_t packingSize = (uint8_t)classLayoutData.packingSize;

        bool isExplictLayout = typeDef->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT;
        if (isExplictLayout)
        {
            IL2CPP_ASSERT(IsValueType(typeDef));
            IL2CPP_ASSERT(isCurAssemblyType);
            int32_t instanceSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS + sizeof(Il2CppObject);
            for (FieldLayout& field : fields)
            {
                if (!IsInstanceField(field.type))
                {
                    continue;
                }
                SizeAndAlignment sa = GetTypeSizeAndAlignment(field.type);
                instanceSize = std::max(instanceSize, field.offset + (int32_t)sa.size);
            }
            // TODO FIXME. not consider packingSize
#if !HYBRIDCLR_UNITY_2022_OR_NEW
            layout.naturalAlignment = layout.alignment = std::max(packingSize, (uint8_t)1);
#endif
            layout.actualSize = layout.instanceSize = AlignTo(instanceSize, layout.alignment);
            layout.nativeSize = -1;
        }
        else
        {
            uint8_t parentMinimumAligment;
            int32_t parentActualSize = 0;
            if (typeDef->parentIndex != kInvalidIndex)
            {
                if (IsValueType(typeDef))
                {
                    parentMinimumAligment = 1;
                    parentActualSize = sizeof(Il2CppObject);
                }
                else
                {
                    const Il2CppType* parentType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->parentIndex);
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

            std::vector<FieldLayout*> instanceFields;
            for (FieldLayout& field : fields)
            {
                if (IsInstanceField(field.type))
                    instanceFields.push_back(&field);
            }

            FieldLayoutData layoutData;
            LayoutFields(parentActualSize, parentMinimumAligment, packingSize, instanceFields, layoutData);
            if (fields.empty() && IsValueType(type))
            {
                layoutData.classSize = layoutData.actualClassSize = layoutData.nativeSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS + sizeof(Il2CppObject);;
            }
            layout.alignment = layoutData.minimumAlignment;
#if !HYBRIDCLR_UNITY_2022_OR_NEW
            layout.naturalAlignment = layoutData.naturalAlignment;
#endif
            layout.actualSize = layoutData.actualClassSize;
            layout.instanceSize = layoutData.classSize;
            layout.nativeSize = layoutData.nativeSize;

            if (!IsValueType(typeDef))
            {
                layout.nativeSize = -1;
            }
            if (classLayoutData.classSize > 0)
            {
                layout.actualSize = layout.instanceSize = layout.instanceSize = classLayoutData.classSize + sizeof(Il2CppObject);
            }
        }
	}

	void ClassFieldLayoutCalculator::CalcClassStaticFields(const Il2CppType* type)
	{
        IL2CPP_ASSERT(_classMap.find(type) != _classMap.end());
        ClassLayoutInfo& layout = _classMap[type];

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
}
}