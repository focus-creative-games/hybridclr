#include "MetadataParser.h"

#include "vm/Image.h"
#include "vm/GlobalMetadata.h"
#include "vm/Type.h"
#include "vm/Field.h"
#include "vm/Object.h"
#include "vm/Runtime.h"
#include "vm/Array.h"
#include "vm/Reflection.h"
#include "vm/String.h"
#include "metadata/GenericMetadata.h"
#include "icalls/mscorlib/System.Reflection/FieldInfo.h"
#include "icalls/mscorlib/System.Reflection/PropertyInfo.h"
#include "icalls/mscorlib/System/Type.h"
#include "utils/StringUtils.h"


#include "MetadataParser.h"
#include "Tables.h"
#include "Image.h"
#include "TableReader.h"
#include "MetadataUtil.h"

namespace huatuo
{
namespace metadata
{
    BlobReader MetadataParser::DecodeBlob(Image& image, const byte* buf)
    {
        uint32_t sizeLength;
        uint32_t length = BlobReader::ReadCompressedUint32(buf, sizeLength);
        return BlobReader(image, buf + sizeLength, length);
    }

    bool MetadataParser::IsValueTypeFromToken(Image& image, TableType tableType, uint32_t rowIndex)
    {
        switch (tableType)
        {
        case TableType::TYPEREF:
        {
            TbTypeRef r = TableReader::ReadTypeRef(image, rowIndex);
            const char* typeNamespace = image.GetStringFromRawIndex(r.typeNamespace);
            if (std::strcmp(typeNamespace, "System"))
            {
                return false;
            }
            const char* typeName = image.GetStringFromRawIndex(r.typeName);
            return std::strcmp(typeName, "ValueType") == 0 || std::strcmp(typeName, "Enum") == 0;
        }
        default:
        {
            return false;
        }
        }
    }

    bool MetadataParser::IsThreadStaticCtorToken(Image& image, TableType tableType, uint32_t rowIndex)
    {
        if (tableType != TableType::MEMBERREF)
        {
            return false;
        }
        TbMemberRef data = TableReader::ReadMemberRef(image, rowIndex);
        TableType parentTableType = DecodeMemberRefParentType(data.classIdx);
        if (parentTableType != TableType::TYPEREF)
        {
            return false;
        }
        Il2CppType type = {};
        ReadTypeFromTypeRef(image, DecodeMemberRefParentRowIndex(data.classIdx), type);
        const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(&type);
        const char* strNamespace = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
        if (std::strcmp(strNamespace, "System"))
        {
            return false;
        }
        const char* strName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
        return std::strcmp(strName, "ThreadStaticAttribute") == 0;
    }

    void MetadataParser::ReadMemberRefParentFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, ResolveMemberRefParent& ret)
    {
        ret.parentType = tableType;
        switch (tableType)
        {
        case huatuo::metadata::TableType::TYPEREF:
            ReadTypeFromTypeRef(image, rowIndex, ret.type);
            break;
        case huatuo::metadata::TableType::TYPEDEF:
            ReadTypeFromTypeDef(image, rowIndex, ret.type);
            break;
        case huatuo::metadata::TableType::METHOD:
            RaiseHuatuoNotSupportedException("ReadMemberRefParentFromToken. from METHOD");
            break;
        case huatuo::metadata::TableType::MODULEREF:
            RaiseHuatuoNotSupportedException("ReadMemberRefParentFromToken. from MODULEREF");
            break;
        case huatuo::metadata::TableType::TYPESPEC:
            ReadTypeFromTypeSpec(image, klassGenericContainer, methodGenericContainer, rowIndex, ret.type);
            break;
        default:
        {
            RaiseHuatuoExecutionEngineException("ReadMemberRefParentFromToken. invalid table type");
            break;
        }
        }
    }

#pragma region type

    void MetadataParser::ReadArrayType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppArrayType& type)
    {
        // FIXME memory leak
        Il2CppType* eleType = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
        ReadType(reader, klassGenericContainer, methodGenericContainer, *eleType);
        type.etype = eleType;
        type.rank = reader.ReadCompressedUint32();
        type.numsizes = reader.ReadCompressedUint32();
        if (type.numsizes > 0)
        {
            type.sizes = (int*)IL2CPP_CALLOC(type.numsizes, sizeof(int));
            for (uint8_t i = 0; i < type.numsizes; i++)
            {
                type.sizes[i] = reader.ReadCompressedUint32();
            }
        }
        else
        {
            type.sizes = nullptr;
        }
        type.numlobounds = reader.ReadCompressedUint32();
        if (type.numlobounds > 0)
        {
            type.lobounds = (int*)IL2CPP_CALLOC(type.numlobounds, sizeof(int));
            for (uint8_t i = 0; i < type.numlobounds; i++)
            {
                type.lobounds[i] = reader.ReadCompressedInt32();
            }
        }
        else
        {
            type.lobounds = nullptr;
        }
    }

    void MetadataParser::ReadGenericClass(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericClass& type)
    {
        Il2CppType* genericBase = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
        ReadType(reader, klassGenericContainer, methodGenericContainer, *genericBase);
        IL2CPP_ASSERT(genericBase->type == IL2CPP_TYPE_CLASS || genericBase->type == IL2CPP_TYPE_VALUETYPE);
        type.type = genericBase;

        Il2CppGenericInst* classInst = (Il2CppGenericInst*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppGenericInst));

        uint32_t argc = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(argc > 0);
        const Il2CppType** argv = (const Il2CppType**)IL2CPP_CALLOC(argc, sizeof(const Il2CppType*));
        for (uint32_t i = 0; i < argc; i++)
        {
            Il2CppType* argType = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
            ReadType(reader, klassGenericContainer, methodGenericContainer, *argType);
            argv[i] = argType;
        }
        classInst->type_argc = argc;
        classInst->type_argv = argv;
        type.context.class_inst = classInst;
        type.context.method_inst = nullptr;
    }

    void MetadataParser::ReadType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType& type)
    {
        readAgain:
        Il2CppTypeEnum etype = (Il2CppTypeEnum)reader.ReadByte();
        type.type = etype;
        switch (etype)
        {
        case IL2CPP_TYPE_VOID:
            break;
        case IL2CPP_TYPE_BOOLEAN:
        case IL2CPP_TYPE_CHAR:
        case IL2CPP_TYPE_I1:
        case IL2CPP_TYPE_U1:
        case IL2CPP_TYPE_I2:
        case IL2CPP_TYPE_U2:
        case IL2CPP_TYPE_I4:
        case IL2CPP_TYPE_U4:
        case IL2CPP_TYPE_I8:
        case IL2CPP_TYPE_U8:
        case IL2CPP_TYPE_R4:
        case IL2CPP_TYPE_R8:
            break;
        case IL2CPP_TYPE_STRING:
            break;
        case IL2CPP_TYPE_PTR:
        {
            Il2CppType* ptrType = (Il2CppType*)IL2CPP_MALLOC(sizeof(Il2CppType));
            *ptrType = {};
            ReadType(reader, klassGenericContainer, methodGenericContainer, *ptrType);
            type.data.type = ptrType;
            break;
        }
        case IL2CPP_TYPE_BYREF:
        {
            type.byref = 1;
            ReadType(reader, klassGenericContainer, methodGenericContainer, type);
            break;
        }
        case IL2CPP_TYPE_VALUETYPE:
        case IL2CPP_TYPE_CLASS:
        {
            uint32_t codedIndex = reader.ReadCompressedUint32(); // 低2位为type, 高位为index
            ReadTypeFromToken(reader.GetImage(), klassGenericContainer, methodGenericContainer, DecodeTypeDefOrRefOrSpecCodedIndexTableType(codedIndex), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(codedIndex), type);
            break;
        }
        case IL2CPP_TYPE_ARRAY:
        {
            Il2CppArrayType* arrType = (Il2CppArrayType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppArrayType));
            ReadArrayType(reader, klassGenericContainer, methodGenericContainer, *arrType);
            type.data.array = arrType;
            break;
        }
        case IL2CPP_TYPE_GENERICINST:
        {
            Il2CppGenericClass* genericClass = (Il2CppGenericClass*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppGenericClass));
            ReadGenericClass(reader, klassGenericContainer, methodGenericContainer, *genericClass);
            type.data.generic_class = genericClass;
            break;
        }
        case IL2CPP_TYPE_TYPEDBYREF:
            break;
        case IL2CPP_TYPE_I:
        case IL2CPP_TYPE_U:
            break;
        case IL2CPP_TYPE_FNPTR:
        {
            RaiseHuatuoNotSupportedException("MetadataParser::ReadType IL2CPP_TYPE_FNPTR");
            break;
        }
        case IL2CPP_TYPE_OBJECT:
            break;
        case IL2CPP_TYPE_SZARRAY:
        {
            Il2CppType* eleType = (Il2CppType*)IL2CPP_MALLOC(sizeof(Il2CppType));
            *eleType = {};
            ReadType(reader, klassGenericContainer, methodGenericContainer, *eleType);
            type.data.type = eleType;
            break;
        }
        case IL2CPP_TYPE_VAR:
        {
            IL2CPP_ASSERT(!klassGenericContainer || !klassGenericContainer->is_method);
            uint32_t number = reader.ReadCompressedUint32();
            if (klassGenericContainer)
            {
                //IL2CPP_ASSERT(huatuo::metadata::IsInterpreterIndex(klassGenericContainer->ownerIndex));
                type.data.genericParameterHandle = il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex((Il2CppMetadataGenericContainerHandle)klassGenericContainer, number);
            }
            else
            {
                type.data.__genericParameterIndex = number;
            }
            /*Il2CppGenericParameter* gp = (Il2CppGenericParameter*)type.data.genericParameterHandle;
            IL2CPP_ASSERT(huatuo::metadata::IsInterpreterIndex(gp->ownerIndex));*/
            break;
        }
        case IL2CPP_TYPE_MVAR:
        {
            IL2CPP_ASSERT(!methodGenericContainer || methodGenericContainer->is_method);
            uint32_t number = reader.ReadCompressedUint32();
            if (methodGenericContainer)
            {
                type.data.genericParameterHandle = il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex((Il2CppMetadataGenericContainerHandle)methodGenericContainer, number);
            }
            else
            {
                // method ref can't resolve at that time
                type.data.__genericParameterIndex = number;
            }
            break;
        }
        case IL2CPP_TYPE_CMOD_REQD:
        {
            ++type.num_mods;
            uint32_t encodeToken = reader.ReadCompressedUint32();
            Il2CppType modType = {};
            ReadTypeFromToken(reader.GetImage(), nullptr, nullptr, DecodeTypeDefOrRefOrSpecCodedIndexTableType(encodeToken), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(encodeToken), modType);
            Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(&modType);
            if (std::strcmp(klass->namespaze, "System.Runtime.InteropServices") == 0)
            {
                if (std::strcmp(klass->name, "InAttribute") == 0)
                {
                    type.attrs |= PARAM_ATTRIBUTE_IN;
                }
                else if (std::strcmp(klass->name, "OutAttribute") == 0)
                {
                    type.attrs |= PARAM_ATTRIBUTE_OUT;
                }
            }
            goto readAgain;
            break;
        }
        case IL2CPP_TYPE_CMOD_OPT:
        {
            ++type.num_mods;
            uint32_t encodeToken = reader.ReadCompressedUint32();
            goto readAgain;
            break;
        }
        case IL2CPP_TYPE_INTERNAL:
        {
            RaiseHuatuoNotSupportedException("MetadataParser::ReadType IL2CPP_TYPE_INTERNAL");
            break;
        }
        case IL2CPP_TYPE_MODIFIER:
        {
            RaiseHuatuoNotSupportedException("MetadataParser::ReadType IL2CPP_TYPE_MODIFIER");
            break;
        }
        case IL2CPP_TYPE_SENTINEL:
        {
            break;
        }
        case IL2CPP_TYPE_PINNED:
        {
            type.pinned = true;
            ReadType(reader, klassGenericContainer, methodGenericContainer, type);
            break;
        }
        default:
        {
            RaiseBadImageException("MetadataParser::ReadType invalid type");
        }
            break;
        }
    }

    void MetadataParser::ReadTypeFromResolutionScope(Image& image, uint32_t scope, uint32_t typeNamespace, uint32_t typeName, Il2CppType& type)
    {
        TableType tokenType;
        uint32_t rawIndex;
        DecodeResolutionScopeCodedIndex(scope, tokenType, rawIndex);
        switch (tokenType)
        {
        case TableType::MODULE:
        {
            RaiseHuatuoNotSupportedException("MetadataParser::ReadTypeFromResolutionScope not support ResolutionScore.MODULE");
            break;
        }
        case TableType::MODULEREF:
        {
            RaiseHuatuoNotSupportedException("MetadataParser::ReadTypeFromResolutionScope not support ResolutionScore.MODULEREF");
            break;
        }
        case TableType::ASSEMBLYREF:
        {
            TbAssemblyRef assRef = TableReader::ReadAssemblyRef(image, rawIndex);
            GetIl2CppTypeFromTypeDefinition(GetTypeDefinition(image, rawIndex, typeNamespace, typeName), type);
            break;
        }
        case TableType::TYPEREF:
        {
            Il2CppType enClosingType = {};
            ReadTypeFromTypeRef(image, rawIndex, enClosingType);
            IL2CPP_ASSERT(typeNamespace == 0);
            const char* name = image.GetStringFromRawIndex(typeName);

            void* iter = nullptr;
            Il2CppMetadataTypeHandle enclosingTypeDef = enClosingType.data.typeHandle;
            if (!enclosingTypeDef)
            {
                TEMP_FORMAT(errMsg, "MetadataParser::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF enclosingType:%s", name);
                RaiseHuatuoExecutionEngineException(errMsg);
            }
            IL2CPP_ASSERT(enclosingTypeDef);
            for (const Il2CppTypeDefinition* nextTypeDef; (nextTypeDef = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetNestedTypes(enclosingTypeDef, &iter));)
            {
                const char* nestedTypeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(nextTypeDef->nameIndex);
                IL2CPP_ASSERT(nestedTypeName);
                if (!std::strcmp(name, nestedTypeName))
                {
                    GetIl2CppTypeFromTypeDefinition(nextTypeDef, type);
                    return;
                }
            }
            
            break;
        }
        default:
        {
            RaiseBadImageException("MetadataParser::ReadTypeFromResolutionScope invaild TableType");
            break;
        }
        }
        IL2CPP_ASSERT(type.data.typeHandle);
    }

    void MetadataParser::ReadTypeFromTypeDef(Image& image, uint32_t rowIndex, Il2CppType& type)
    {
        const Il2CppType* typeDef = image.GetIl2CppTypeFromRawTypeDefIndex(rowIndex - 1);
        type.type = typeDef->type;
        type.data.typeHandle = typeDef->data.typeHandle;
    }

    void MetadataParser::ReadTypeFromTypeRef(Image& image, uint32_t rowIndex, Il2CppType& type)
    {
        TbTypeRef r = TableReader::ReadTypeRef(image, rowIndex);
        ReadTypeFromResolutionScope(image, r.resolutionScope, r.typeNamespace, r.typeName, type);
    }

    void MetadataParser::ReadTypeFromTypeSpec(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, Il2CppType& type)
    {
        TbTypeSpec r = TableReader::ReadTypeSpec(image, rowIndex);
        BlobReader reader = image.GetBlobReaderByRawIndex(r.signature);
        ReadType(reader, klassGenericContainer, methodGenericContainer, type);
    }

    void MetadataParser::ReadTypeFromMemberRefParent(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type)
    {
        ResolveMemberRefParent mrp = {};
        ReadMemberRefParentFromToken(image, klassGenericContainer, methodGenericContainer, tableType, rowIndex, mrp);
        type = mrp.type;
        IL2CPP_ASSERT(mrp.parentType == TableType::TYPEDEF || mrp.parentType == TableType::TYPEREF || mrp.parentType == TableType::TYPESPEC);
    }

    void MetadataParser::ReadTypeFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type)
    {
        switch (tableType)
        {
        case TableType::TYPEDEF:
        {
            ReadTypeFromTypeDef(image, rowIndex, type);
            break;
        }
        case TableType::TYPEREF:
        {
            ReadTypeFromTypeRef(image, rowIndex, type);
            break;
        }
        case TableType::TYPESPEC:
        {
            ReadTypeFromTypeSpec(image, klassGenericContainer, methodGenericContainer, rowIndex, type);
            break;
        }
        default:
        {
            RaiseBadImageException("MetadataParser::ReadTypeFromToken invalid TableType");
            break;
        }
        }
    }

#pragma endregion

    void MetadataParser::ReadFieldRefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, FieldRefSig& field)
    {
        field = {};
        uint8_t rawSigType = reader.ReadByte();
        SigType sigType = DecodeSigType(rawSigType);
        IL2CPP_ASSERT(sigType == SigType::FIELD);
        ReadType(reader, klassGenericContainer, nullptr, field.type);
    }

    void MetadataParser::ReadMethodRefSig(Image& image, TbMemberRef& data, MethodRefSig& method)
    {
        method = {};
        BlobReader reader = image.GetBlobReaderByRawIndex(data.signature);
        uint8_t rawSigFlags = reader.ReadByte();
        method.flags = rawSigFlags;
        if (rawSigFlags & (uint8_t)SigType::GENERIC)
        {
            method.genericParamCount = reader.ReadCompressedUint32();
        }
        uint32_t paramCount = reader.ReadCompressedUint32();

        ReadType(reader, nullptr, nullptr, method.returnType);

        bool sentinel = false;
        for (uint32_t readParamNum = 0; readParamNum < paramCount; ++readParamNum)
        {
            Il2CppType paramType = {};
            ReadType(reader, nullptr, nullptr, paramType);
            if (paramType.type == IL2CPP_TYPE_SENTINEL)
            {
                IL2CPP_ASSERT(rawSigFlags & (uint8_t)SigType::VARARG);
                sentinel = true;
                continue;
            }
            method.params.push_back(paramType);
        }
    }

    void MetadataParser::ReadMemberRefSig(Image& image, const Il2CppGenericContainer* klassGenericContainer, TbMemberRef& data, ResolveMemberRefSig& signature)
    {
        BlobReader reader = image.GetBlobReaderByRawIndex(data.signature);
        uint8_t rawSigFlags = reader.PeekByte();
        SigType sigType = DecodeSigType(rawSigFlags);
        if (sigType == SigType::FIELD)
        {
            signature.memberType = TableType::FIELD_POINTER;
            ReadFieldRefSig(reader, klassGenericContainer, signature.field);
        }
        else
        {
            signature.memberType = TableType::METHOD_POINTER;
            ReadMethodRefSig(image, data, signature.method);
        }
    }

    void MetadataParser::ReadMethodDefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppMethodDefinition& methodDef, std::vector<ParamDetail>& paramArr)
    {
        Image& image = reader.GetImage();

        uint8_t rawSigFlags = reader.ReadByte();

        if (rawSigFlags & (uint8_t)MethodSigFlags::GENERIC)
        {
            //IL2CPP_ASSERT(false);
            uint32_t genParamCount = reader.ReadCompressedUint32();
            Il2CppGenericContainer* gc = image.GetGenericContainerByRawIndex(DecodeMetadataIndex(methodDef.genericContainerIndex));
            IL2CPP_ASSERT(gc->type_argc == genParamCount);
        }
        uint32_t paramCount = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(paramCount >= methodDef.parameterCount);

        Il2CppType returnType = {};
        ReadType(reader, klassGenericContainer, methodGenericContainer, returnType);
        methodDef.returnType = image.AddIl2CppTypeCache(returnType);

        int readParamNum = 0;
        for (; reader.NonEmpty(); )
        {
            ParamDetail curParam = {};
            Il2CppType paramType = {};
            ReadType(reader, klassGenericContainer, methodGenericContainer, paramType);
            curParam.parameterIndex = readParamNum++;
            curParam.methodDef = &methodDef;
            curParam.paramDef.typeIndex = image.AddIl2CppTypeCache(paramType);
            paramArr.push_back(curParam);
        }
        IL2CPP_ASSERT(readParamNum == (int)paramCount);
    }

    void MetadataParser::ReadMethodRefInfoFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, MethodRefInfo& ret)
    {
        IL2CPP_ASSERT(rowIndex > 0);
        switch (tableType)
        {
        case TableType::METHOD:
        {
            const Il2CppMethodDefinition* methodDef = image.GetMethodDefinitionFromRawIndex(rowIndex - 1);
            const Il2CppType* type = image.GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(image.GetTypeFromRawIndex(DecodeMetadataIndex(methodDef->declaringType))->byvalTypeIndex));
            ret.containerType = *type;
            ret.methodDef = methodDef;
            IL2CPP_ASSERT(type);
            IL2CPP_ASSERT(methodDef);
            break;
        }
        case TableType::MEMBERREF:
        {
            ReadMethodRefInfoFromMemberRef(image, klassGenericContainer, methodGenericContainer, nullptr, rowIndex, ret);
            break;
        }
        case TableType::METHODSPEC:
        {
            TbMethodSpec methodSpec = TableReader::ReadMethodSpec(image, rowIndex);

            ReadMethodSpecInstantiation(image, methodSpec.instantiation, klassGenericContainer, methodGenericContainer, ret.instantiation);
            //FIXME instantiation memory leak

            TableType methodTableType = DecodeMethodDefOrRefCodedIndexTableType(methodSpec.method);
            uint32_t methodRowIndex = DecodeMethodDefOrRefCodedIndexRowIndex(methodSpec.method);
            switch (methodTableType)
            {
            case TableType::METHOD:
            {
                ReadMethodRefInfoFromToken(image, klassGenericContainer, methodGenericContainer, methodTableType, methodRowIndex, ret);
                break;
            }
            case TableType::MEMBERREF:
            {
                ReadMethodRefInfoFromMemberRef(image, klassGenericContainer, methodGenericContainer, ret.instantiation, methodRowIndex, ret);
                break;
            }
            default:
            {
                RaiseBadImageException("MetadataParser::ReadMethodRefInfoFromToken METHODSPEC invalid TableType");
                break;
            }
            }
            break;
        }
        default:
        {
            RaiseBadImageException("MetadataParser::ReadMethodRefInfoFromToken invalid TableType");
        }
        }
    }

    void MetadataParser::ReadResolveMemberRefFromMemberRef(Image& image, const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, ResolveMemberRef& ret)
    {
        TbMemberRef data = TableReader::ReadMemberRef(image, rowIndex);
        ret.name = image.GetStringFromRawIndex(data.name);
        ReadMemberRefParentFromToken(image, klassGenericContainer, methodGenericContainer, DecodeMemberRefParentType(data.classIdx), DecodeMemberRefParentRowIndex(data.classIdx), ret.parent);
        IL2CPP_ASSERT(ret.parent.parentType == TableType::TYPEDEF || ret.parent.parentType == TableType::TYPEREF || ret.parent.parentType == TableType::TYPESPEC);
        Il2CppType& parentType = ret.parent.type;
        ReadMemberRefSig(image, nullptr, data, ret.signature);
    }

    void MetadataParser::ReadMethodRefInfoFromMemberRef(Image& image, const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst* genericInstantiation, uint32_t rowIndex, MethodRefInfo& ret)
    {
        ResolveMemberRef rmr = {};
        ReadResolveMemberRefFromMemberRef(image, klassGenericContainer, methodGenericContainer, rowIndex, rmr);
        IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
        IL2CPP_ASSERT(rmr.signature.memberType == TableType::METHOD_POINTER);
        ret.containerType = rmr.parent.type;
        ret.methodDef = ResolveMethodDefinition(&rmr.parent.type, rmr.name, rmr.signature.method, genericInstantiation);
    }

    void MetadataParser::ReadMethodSpecInstantiation(Image& image, uint32_t signature, const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst*& genericInstantiation)
    {
        BlobReader reader = image.GetBlobReaderByRawIndex(signature);
        uint8_t rawSigFlags = reader.ReadByte();
        IL2CPP_ASSERT(rawSigFlags == 0xA);
        uint32_t argCount = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(argCount >= 0 && argCount < 100);
        if (argCount == 0)
        {
            genericInstantiation = nullptr;
            return;
        }
        genericInstantiation = (Il2CppGenericInst*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppGenericInst));
        genericInstantiation->type_argc = argCount;
        genericInstantiation->type_argv = (const Il2CppType**)IL2CPP_CALLOC(argCount, sizeof(Il2CppType*));
        for (uint32_t i = 0; i < argCount; i++)
        {
            Il2CppType* type = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
            ReadType(reader, klassGenericContainer, methodGenericContainer, *type);
            genericInstantiation->type_argv[i] = type;
        }
    }

    void MetadataParser::ReadFieldRefInfoFromToken(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, FieldRefInfo& ret)
    {
        IL2CPP_ASSERT(rowIndex > 0);
        if (tableType == TableType::FIELD)
        {
            const FieldDetail& fd = image.GetFieldDetailFromRawIndex(rowIndex - 1);
            ret.containerType = *image.GetIl2CppTypeFromRawTypeDefIndex(DecodeMetadataIndex(fd.typeDefIndex));
            ret.field = &fd.fieldDef;
            //ret.classType = *image.GetIl2CppTypeFromRawTypeDefIndex(DecodeMetadataIndex(ret.field->typeIndex));
        }
        else
        {
            IL2CPP_ASSERT(tableType == TableType::MEMBERREF);
            ReadFieldRefInfoFromMemberRef(image, klassGenericContainer, methodGenericContainer, rowIndex, ret);
        }
    }

    void MetadataParser::ReadFieldRefInfoFromMemberRef(Image& image, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, FieldRefInfo& ret)
    {
        ResolveMemberRef rmr = {};
        ReadResolveMemberRefFromMemberRef(image, klassGenericContainer, methodGenericContainer, rowIndex, rmr);
        IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
        IL2CPP_ASSERT(rmr.signature.memberType == TableType::FIELD_POINTER);
        ret.containerType = rmr.parent.type;
        ResolveField(&rmr.parent.type, rmr.name, &rmr.signature.field.type, ret.field);
    }

    void MetadataParser::ReadLocalVarSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType*& vars, uint32_t& varCount)
    {
        uint8_t sig = reader.ReadByte();
        IL2CPP_ASSERT(sig == 0x7);
        varCount = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(varCount >= 1 && varCount <= 0xFFFE);
        vars = (Il2CppType*)IL2CPP_MALLOC_ZERO(varCount * sizeof(Il2CppType));
        for (uint32_t i = 0; i < varCount; i++)
        {
            ReadType(reader, klassGenericContainer, methodGenericContainer, vars[i]);
        }
    }

    void MetadataParser::ReadStandAloneSig(Image& image, uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, ResolveStandAloneMethodSig& methodSig)
    {
        BlobReader reader = image.GetBlobReaderByRawIndex(signatureIdx);
        uint8_t sig = reader.ReadByte();
        methodSig.flags = sig;
        uint32_t paramCount = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(paramCount >= 1 && paramCount <= 0xFFFE);
        methodSig.paramCount = paramCount;
        ReadType(reader, klassGenericContainer, methodGenericContainer, methodSig.returnType);
        if (paramCount > 0)
        {
            Il2CppType* params = (Il2CppType*)IL2CPP_MALLOC_ZERO(paramCount * sizeof(Il2CppType));
            for (uint32_t i = 0; i < paramCount; i++)
            {
                ReadType(reader, klassGenericContainer, methodGenericContainer, params[i]);
            }
        }
        else
        {
            methodSig.params = nullptr;
        }
    }

    const Il2CppTypeDefinition* MetadataParser::GetTypeDefinition(Image& image, uint32_t assemblyRefIndex, uint32_t typeNamespace, uint32_t typeName)
    {
        TbAssemblyRef data = TableReader::ReadAssemblyRef(image, assemblyRefIndex);
        const char* assName = image.GetStringFromRawIndex(data.name);
        const char* typeNameStr = image.GetStringFromRawIndex(typeName);
        const char* typeNamespaceStr = image.GetStringFromRawIndex(typeNamespace);
        const Il2CppAssembly* refAss = il2cpp::vm::Assembly::GetLoadedAssembly(assName);
        Il2CppClass* klass = nullptr;
        if (refAss)
        {
            const Il2CppImage* image2 = il2cpp::vm::Assembly::GetImage(refAss);
            klass = il2cpp::vm::Class::FromName(image2, typeNamespaceStr, typeNameStr);
        }
        if (!klass || !klass->typeMetadataHandle)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(
                CStringToStringView(typeNamespaceStr),
                CStringToStringView(typeNameStr),
                CStringToStringView(assName)));
        }
        return (const Il2CppTypeDefinition*)klass->typeMetadataHandle;
    }


    Il2CppString* ReadSerString(BlobReader& reader)
    {
        byte b = reader.PeekByte();
        if (b == 0xFF)
        {
            reader.SkipByte();
            return nullptr;
        }
        else if (b == 0)
        {
            reader.SkipByte();
            return il2cpp::vm::String::Empty();
        }
        else
        {
            uint32_t len = reader.ReadCompressedUint32();
            return il2cpp::vm::String::NewLen((char*)reader.GetAndSkipCurBytes(len), len);
        }
    }

    void ReadFixedArg(BlobReader& reader, const Il2CppType* argType, void* data)
    {
        switch (argType->type)
        {
        case IL2CPP_TYPE_BOOLEAN:
        {
            *(bool*)data = reader.Read<bool>();
            break;
        }
        case IL2CPP_TYPE_CHAR:
        {
            *(uint16_t*)data = reader.ReadUshort();
            break;
        }
        case IL2CPP_TYPE_I1:
        case IL2CPP_TYPE_U1:
        {
            *(byte*)data = reader.ReadByte();
            break;
        }
        case IL2CPP_TYPE_I2:
        case IL2CPP_TYPE_U2:
        {
            *(uint16_t*)data = reader.Read<uint16_t>();
            break;
        }
        case IL2CPP_TYPE_I4:
        case IL2CPP_TYPE_U4:
        {
            *(uint32_t*)data = reader.Read<uint32_t>();
            break;
        }
        case IL2CPP_TYPE_I8:
        case IL2CPP_TYPE_U8:
        {
            *(uint64_t*)data = reader.Read<uint64_t>();
            break;
        }
        case IL2CPP_TYPE_R4:
        {
            *(float*)data = reader.Read<float>();
            break;
        }
        case IL2CPP_TYPE_R8:
        {
            *(double*)data = reader.Read<double>();
            break;
        }
        case IL2CPP_TYPE_SZARRAY:
        {
            uint32_t numElem = reader.Read<uint32_t>();
            if (numElem != (uint32_t)-1)
            {
                Il2CppClass* arrKlass = il2cpp::vm::Class::FromIl2CppType(argType);
                Il2CppArray* arr = il2cpp::vm::Array::New(il2cpp::vm::Class::GetElementClass(arrKlass), numElem);
                for (uint16_t i = 0; i < numElem; i++)
                {
                    ReadFixedArg(reader, argType->data.type, load_array_elema(arr, i, arr->klass->element_size));
                }
                *(void**)data = arr;
            }
            else
            {
                *(void**)data = nullptr;
            }
            break;
        }
        case IL2CPP_TYPE_STRING:
        {
            *(Il2CppString**)data = ReadSerString(reader);
            // FIXME memory barrier
            break;
        }
        case IL2CPP_TYPE_OBJECT:
        {
            uint64_t obj = 0;
            Il2CppType kind = {};
            kind.type = (Il2CppTypeEnum)reader.ReadByte();
            Il2CppClass* valueType = il2cpp::vm::Class::FromIl2CppType(&kind);
            ReadFixedArg(reader, &kind, &obj);
            *(Il2CppObject**)data = il2cpp::vm::Object::Box(valueType, &obj);
            // FIXME memory barrier
            break;
        }
        case IL2CPP_TYPE_CLASS:
        {
            Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(argType);
            if (!klass)
            {
                RaiseHuatuoExecutionEngineException("type not find");
            }
            if (klass == il2cpp_defaults.object_class)
            {
                Il2CppType boxedValueType = {};
                boxedValueType.type = (Il2CppTypeEnum)reader.ReadByte();
                Il2CppClass* valKlass = il2cpp::vm::Class::FromIl2CppType(&boxedValueType);
                IL2CPP_ASSERT(valKlass);
                uint64_t val = 0;
                ReadFixedArg(reader, &boxedValueType, &val);
                *(Il2CppObject**)data = il2cpp::vm::Object::Box(valKlass, &val);
            }
            else if (klass == il2cpp_defaults.systemtype_class)
            {
                Il2CppString* fullName = ReadSerString(reader);
                Il2CppReflectionType* type = il2cpp::icalls::mscorlib::System::Type::internal_from_name(fullName, true, false);
                if (!type)
                {
                    std::string stdTypeName = il2cpp::utils::StringUtils::Utf16ToUtf8(fullName->chars);
                    TEMP_FORMAT(errMsg, "CustomAttribute fixed arg type:System.Type fullName:'%s' not find", stdTypeName.c_str());
                    il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
                }
                *(Il2CppReflectionType**)data = type;
            }
            else
            {
                TEMP_FORMAT(errMsg, "fixed arg type:%s.%s not support", klass->namespaze, klass->name);
                RaiseHuatuoNotSupportedException(errMsg);
            }
            break;
        }
        case IL2CPP_TYPE_VALUETYPE:
        {
            Il2CppClass* valueType = il2cpp::vm::Class::FromIl2CppType(argType);
            IL2CPP_ASSERT(valueType->enumtype);
            ReadFixedArg(reader, &valueType->element_class->byval_arg, data);
            break;
        }
        case IL2CPP_TYPE_SYSTEM_TYPE:
        {
            Il2CppString* fullName = ReadSerString(reader);
            Il2CppReflectionType* type = il2cpp::icalls::mscorlib::System::Type::internal_from_name(fullName, true, false);
            if (!type)
            {
                std::string stdTypeName = il2cpp::utils::StringUtils::Utf16ToUtf8(fullName->chars);
                TEMP_FORMAT(errMsg, "CustomAttribute fixed arg type:System.Type fullName:'%s' not find", stdTypeName.c_str());
                il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
            }
            *(Il2CppReflectionType**)data = type;
            break;
        }
        case IL2CPP_TYPE_BOXED_OBJECT:
        {
            uint8_t fieldOrPropType = reader.ReadByte();
            IL2CPP_ASSERT(fieldOrPropType == 0x51);
            Il2CppType boxedValueType = {};
            boxedValueType.type = (Il2CppTypeEnum)reader.ReadByte();
            Il2CppClass* valKlass = il2cpp::vm::Class::FromIl2CppType(&boxedValueType);
            IL2CPP_ASSERT(valKlass);
            uint64_t val = 0;
            ReadFixedArg(reader, &boxedValueType, &val);
            *(Il2CppObject**)data = il2cpp::vm::Object::Box(valKlass, &val);
            break;
        }
        case IL2CPP_TYPE_ENUM:
        {
            Il2CppClass* valueType = il2cpp::vm::Class::FromIl2CppType(argType);
            IL2CPP_ASSERT(valueType->enumtype);
            ReadFixedArg(reader, &valueType->element_class->byval_arg, data);
            break;
        }
        default:
        {
            RaiseHuatuoExecutionEngineException("not support fixed argument type");
        }
        }
    }

    void ReadCustomAttributeFieldOrPropType(BlobReader& reader, Il2CppType& type)
    {
        type.type = (Il2CppTypeEnum)reader.ReadByte();

        switch (type.type)
        {
        case IL2CPP_TYPE_SZARRAY:
        {
            // FIXME MEMORY LEAK
            Il2CppType* eleType = (Il2CppType*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppType));
            ReadCustomAttributeFieldOrPropType(reader, *eleType);
            type.data.type = eleType;
            break;
        }
        case IL2CPP_TYPE_ENUM:
        {
            Il2CppString* enumTypeName = ReadSerString(reader);

            Il2CppReflectionType* enumType = il2cpp::icalls::mscorlib::System::Type::internal_from_name(enumTypeName, true, false);
            if (!enumType)
            {
                std::string stdStrName = il2cpp::utils::StringUtils::Utf16ToUtf8(enumTypeName->chars);
                TEMP_FORMAT(errMsg, "ReadCustomAttributeFieldOrPropType enum:'%s' not exists", stdStrName.c_str());
                RaiseHuatuoExecutionEngineException(errMsg);
            }
            type = *enumType->type;
            break;
        }
        case IL2CPP_TYPE_SYSTEM_TYPE:
        {
            type = il2cpp_defaults.systemtype_class->byval_arg;
            break;
        }
        case IL2CPP_TYPE_BOXED_OBJECT:
        {
            type = il2cpp_defaults.object_class->byval_arg;
            break;
        }
        
        }
    }

    void MetadataParser::ConstructCustomAttribute(BlobReader& reader, Il2CppObject* obj, const MethodInfo* ctorMethod)
    {
        uint16_t prolog = reader.ReadUshort();
        IL2CPP_ASSERT(prolog == 0x0001);
        if (ctorMethod->parameters_count == 0)
        {
            il2cpp::vm::Runtime::Invoke(ctorMethod, obj, nullptr, nullptr);
        }
        else
        {
            int32_t argSize = sizeof(uint64_t) * ctorMethod->parameters_count;
            uint64_t* argDatas = (uint64_t*)alloca(argSize);
            std::memset(argDatas, 0, argSize);
            void** argPtrs = (void**)alloca(sizeof(void*) * ctorMethod->parameters_count); // same with argDatas
            for (uint8_t i = 0; i < ctorMethod->parameters_count; i++)
            {
                argPtrs[i] = argDatas + i;
                const Il2CppType* paramType = ctorMethod->parameters[i].parameter_type;
                ReadFixedArg(reader, paramType, argDatas + i);
                Il2CppClass* paramKlass = il2cpp::vm::Class::FromIl2CppType(paramType);
                if (!paramKlass->valuetype)
                {
                    argPtrs[i] = (void*)argDatas[i];
                }
            }
            il2cpp::vm::Runtime::Invoke(ctorMethod, obj, argPtrs, nullptr);
            // clear ref. may not need. gc memory barrier
            std::memset(argDatas, 0, argSize);
        }
        uint16_t numNamed = reader.ReadUshort();
        Il2CppClass* klass = obj->klass;
        for (uint16_t idx = 0; idx < numNamed; idx++)
        {
            byte fieldOrPropTypeTag = reader.ReadByte();
            IL2CPP_ASSERT(fieldOrPropTypeTag == 0x53 || fieldOrPropTypeTag == 0x54);
            Il2CppType fieldOrPropType = {};
            ReadCustomAttributeFieldOrPropType(reader, fieldOrPropType);
            Il2CppString* fieldOrPropName = ReadSerString(reader);
            std::string stdStrName = il2cpp::utils::StringUtils::Utf16ToUtf8(fieldOrPropName->chars);
            const char* cstrName = stdStrName.c_str();
            uint64_t value = 0;
            ReadFixedArg(reader, &fieldOrPropType, &value);
            if (fieldOrPropTypeTag == 0x53)
            {
                FieldInfo* field = il2cpp::vm::Class::GetFieldFromName(klass, cstrName);
                if (!field)
                {
                    TEMP_FORMAT(errMsg, "CustomAttribute field missing. klass:%s.%s field:%s", klass->namespaze, klass->name, cstrName);
                    il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeInitializationException(errMsg, nullptr));
                }
                Il2CppReflectionField* refField = il2cpp::vm::Reflection::GetFieldObject(klass, field);
                IL2CPP_ASSERT(IsTypeEqual(&fieldOrPropType, field->type));
                uint32_t fieldSize = GetTypeValueSize(&fieldOrPropType);
                std::memcpy((byte*)obj + field->offset, &value, fieldSize);
                //fixme MEMORY BARRIER
                IL2CPP_ASSERT(refField);
            }
            else
            {
                const PropertyInfo* prop = il2cpp::vm::Class::GetPropertyFromName(klass, cstrName);
                if (!prop)
                {
                    TEMP_FORMAT(errMsg, "CustomAttribute property missing. klass:%s property:%s", klass->name, cstrName);
                    il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeInitializationException(errMsg, nullptr));
                }
                IL2CPP_ASSERT(IsTypeEqual(&fieldOrPropType, prop->set->parameters[0].parameter_type));
                Il2CppException* ex = nullptr;
                Il2CppClass* propKlass = il2cpp::vm::Class::FromIl2CppType(&fieldOrPropType);
                IL2CPP_ASSERT(propKlass);
                void* args[] = { (propKlass->valuetype ? &value : (void*)value) };
                il2cpp::vm::Runtime::Invoke(prop->set, obj, args, &ex);
                if (ex)
                {
                    il2cpp::vm::Exception::Raise(ex);
                }
            }
        }
    }

}
}