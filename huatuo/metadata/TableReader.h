#pragma once

#include "Image.h"

namespace huatuo
{
namespace metadata
{


	class TableReader
	{

    private:
        static uint32_t ReadColumn(Image& image, const byte* rowPtr, const ColumnOffsetSize& columnMt)
        {
            return ReadColumn(rowPtr, columnMt.offset, columnMt.size);
        }

        static uint32_t ReadColumn(const byte* data, uint32_t offset, uint32_t size)
        {
            IL2CPP_ASSERT(size == 2 || size == 4);
            return (size == 2 ? *(uint16_t*)(data + offset) : *(uint32_t*)(data + offset));
        }

    public:


#define TABLE_BEGIN(name, tableType) static Tb##name Read##name(Image& image, uint32_t rawIndex) \
        { \
        IL2CPP_ASSERT(rawIndex > 0 && rawIndex <= image.GetTable(tableType).rowNum); \
        const byte* rowPtr = image.GetTableRowPtr(tableType, rawIndex); \
        auto& rowSchema = image.GetRowSchema(tableType); \
        uint32_t __fieldIndex = 0; \
        Tb##name __r = {};

#define __F(fieldName) const ColumnOffsetSize& col_##fieldName = rowSchema[__fieldIndex++]; \
        __r.fieldName = ReadColumn(image, rowPtr, col_##fieldName);

#define TABLE_END return __r; \
        }

#define TABLE1(name, tableType, f1) TABLE_BEGIN(name, tableType) \
__F(f1) \
TABLE_END

#define TABLE2(name, tableType, f1, f2) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
TABLE_END

#define TABLE3(name, tableType, f1, f2, f3) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
TABLE_END

#define TABLE4(name, tableType, f1, f2, f3, f4) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
__F(f4) \
TABLE_END

#define TABLE5(name, tableType, f1, f2, f3, f4, f5) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
__F(f4) \
__F(f5) \
TABLE_END

#define TABLE6(name, tableType, f1, f2, f3, f4, f5, f6) TABLE_BEGIN(name, tableType) \
__F(f1) \
__F(f2) \
__F(f3) \
__F(f4) \
__F(f5) \
__F(f6) \
TABLE_END

        TABLE5(Module, TableType::MODULE, generation, name, mvid, encid, encBaseId);
        TABLE3(TypeRef, TableType::TYPEREF, resolutionScope, typeName, typeNamespace)
        TABLE6(TypeDef, TableType::TYPEDEF, flags, typeName, typeNamespace, extends, fieldList, methodList)
        TABLE1(TypeSpec, TableType::TYPESPEC, signature);
        TABLE3(Field, TableType::FIELD, flags, name, signature)
        TABLE4(GenericParam, TableType::GENERICPARAM, number, flags, owner, name)
        TABLE2(GenericParamConstraint, TableType::GENERICPARAMCONSTRAINT, owner, constraint)
        TABLE3(MemberRef, TableType::MEMBERREF, classIdx, name, signature)
        TABLE1(StandAloneSig, TableType::STANDALONESIG, signature)
        TABLE3(MethodImpl, TableType::METHODIMPL, classIdx, methodBody, methodDeclaration)
        TABLE2(FieldRVA, TableType::FIELDRVA, rva, field)
        TABLE2(FieldLayout, TableType::FIELDLAYOUT, offset, field)
        TABLE3(Constant, TableType::CONSTANT, type, parent, value)
        TABLE2(MethodSpec, TableType::METHODSPEC, method, instantiation)
        TABLE3(CustomAttribute, TableType::CUSTOMATTRIBUTE, parent, type, value)
        TABLE2(PropertyMap, TableType::PROPERTYMAP, parent, propertyList)
        TABLE3(Property, TableType::PROPERTY, flags, name, type)
        TABLE2(EventMap, TableType::EVENTMAP, parent, eventList)
        TABLE3(Event, TableType::EVENT, eventFlags, name, eventType)
        TABLE3(MethodSemantics, TableType::METHODSEMANTICS, semantics, method, association)

        TABLE2(NestedClass, TableType::NESTEDCLASS, nestedClass, enclosingClass)
        TABLE6(Method, TableType::METHOD, rva, implFlags, flags, name, signature, paramList)
        TABLE3(Param, TableType::PARAM, flags, sequence, name)

        TABLE3(ClassLayout, TableType::CLASSLAYOUT, packingSize, classSize, parent)
        TABLE2(InterfaceImpl, TableType::INTERFACEIMPL, classIdx, interfaceIdx)

        TABLE_BEGIN(Assembly, TableType::ASSEMBLY)
        __F(hashAlgId)
        __F(majorVersion)
        __F(minorVersion)
        __F(buildNumber)
        __F(revisionNumber)
        __F(flags)
        __F(publicKey)
        __F(name)
        __F(culture)
        TABLE_END


        TABLE_BEGIN(AssemblyRef, TableType::ASSEMBLYREF)
        __F(majorVersion)
        __F(minorVersion)
        __F(buildNumber)
        __F(revisionNumber)
        __F(flags)
        __F(publicKeyOrToken)
        __F(name)
        __F(culture)
        __F(hashValue)
        TABLE_END

	};

}
}