#pragma once

#include "BlobReader.h"
#include "MetadataDef.h"

namespace huatuo
{
namespace metadata
{
    class Image;
    struct ParamDetail;

    class MetadataParser
    {
    public:
        static BlobReader DecodeBlob(Image& image, const byte* buf);

        // misc
        static bool IsValueTypeFromToken(Image& image, TableType tableType, uint32_t rowIndex);
        static bool IsThreadStaticCtorToken(Image& image, TableType tableType, uint32_t rowIndex);
        static void ReadMemberRefParentFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, ResolveMemberRefParent& ret);
        static void ReadTypeFromMemberRefParent(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type);

        static const Il2CppTypeDefinition* GetTypeDefinition(Image& image, uint32_t assemblyRefIndex, uint32_t typeNamespace, uint32_t typeName);
        static void ConstructCustomAttribute(BlobReader& reader, Il2CppObject* obj, const MethodInfo* ctorMethod);
        // type
        static void ReadType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType& type);
            
        static void ReadTypeFromTypeDef(Image& image, uint32_t rowIndex, Il2CppType& type);
        static void ReadTypeFromTypeRef(Image& image, uint32_t rowIndex, Il2CppType& type);
        static void ReadTypeFromTypeSpec(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, Il2CppType& type);
        static void ReadTypeFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type);

        static void ReadTypeFromResolutionScope(Image& image, uint32_t scope, uint32_t typeNamespace, uint32_t typeName, Il2CppType& type);

        static void ReadArrayType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppArrayType& type);
        static void ReadGenericClass(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericClass& type);

        // signature
        static void ReadMemberRefSig(Image& image, const Il2CppGenericContainer* klassGenericContainer, TbMemberRef& data, ResolveMemberRefSig& signature);
        static void ReadFieldRefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, FieldRefSig& field);
        static void ReadMethodRefSig(Image& image, TbMemberRef& rowData, MethodRefSig& method);
        static void ReadMethodDefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppMethodDefinition& methodDef, std::vector<ParamDetail>& paramArr);
        static void ReadMethodSpecInstantiation(Image& image, uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst*& genericInstantiation);
        static void ReadLocalVarSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType*& vars, uint32_t& varCount);
        static void ReadStandAloneSig(Image& image, uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, ResolveStandAloneMethodSig& sig);
       
        // resolve from token
        static void ReadResolveMemberRefFromMemberRef(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, ResolveMemberRef& ret);
        static void ReadMethodRefInfoFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, MethodRefInfo& ret);
        static void ReadMethodRefInfoFromMemberRef(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst* genericInstantiation, uint32_t rowIndex, MethodRefInfo& ret);

        static void ReadFieldRefInfoFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, FieldRefInfo& ret);
        static void ReadFieldRefInfoFromMemberRef(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, FieldRefInfo& ret);

    };

}
}