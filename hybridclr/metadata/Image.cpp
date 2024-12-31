#include "Image.h"

#include "vm/ClassInlines.h"
#include "vm/Image.h"
#include "vm/GlobalMetadata.h"
#include "vm/Type.h"
#include "vm/Field.h"
#include "vm/Object.h"
#include "vm/Runtime.h"
#include "vm/Array.h"
#include "vm/Reflection.h"
#include "vm/MetadataLock.h"
#include "vm/String.h"
#include "metadata/GenericMetadata.h"
#include "icalls/mscorlib/System.Reflection/FieldInfo.h"
#ifdef HYBRIDCLR_UNITY_2021_OR_NEW
#include "icalls/mscorlib/System/RuntimeTypeHandle.h"
#else
#include "icalls/mscorlib/System.Reflection/PropertyInfo.h"
#endif
#include "icalls/mscorlib/System/Type.h"
#include "utils/StringUtils.h"

#include "MetadataUtil.h"
#include "BlobReader.h"
#include "MetadataPool.h"

namespace hybridclr
{
namespace metadata
{

    static const char* s_netstandardRefs[]
    {
        "mscorlib",
        "System",
        "System.Core",
        "System.Numerics",
        "System.Collections",
        "System.Collections.Concurrent",
        "System.Numerics.Vectors",
        "System.Data",
        "System.Configuration",
        "System.IO.Compression",
        "System.Net",
        "System.Security",
        "System.Xml",
        "System.Xml.Linq",
        "System.Xml.Serialization",
        "System.Runtime.Serialization",
        "System.Json",
        "System.Diagnostics.Tracing",
        "System.Net.Http",
        nullptr,
    };

    bool Image::IsValueTypeFromToken(TableType tableType, uint32_t rowIndex)
    {
        switch (tableType)
        {
        case TableType::TYPEREF:
        {
            TbTypeRef r = _rawImage->ReadTypeRef(rowIndex);
            const char* typeNamespace = _rawImage->GetStringFromRawIndex(r.typeNamespace);
            if (std::strcmp(typeNamespace, "System"))
            {
                return false;
            }
            const char* typeName = _rawImage->GetStringFromRawIndex(r.typeName);
            return std::strcmp(typeName, "ValueType") == 0 || std::strcmp(typeName, "Enum") == 0;
        }
        default:
        {
            return false;
        }
        }
    }

    bool Image::IsThreadStaticCtorToken(TableType tableType, uint32_t rowIndex)
    {
        if (tableType != TableType::MEMBERREF)
        {
            return false;
        }
        TbMemberRef data = _rawImage->ReadMemberRef(rowIndex);
        TableType parentTableType = DecodeMemberRefParentType(data.classIdx);
        if (parentTableType != TableType::TYPEREF)
        {
            return false;
        }
        const Il2CppType* type = ReadTypeFromTypeRef(DecodeMemberRefParentRowIndex(data.classIdx));
        const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
        const char* strNamespace = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
        if (std::strcmp(strNamespace, "System"))
        {
            return false;
        }
        const char* strName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
        return std::strcmp(strName, "ThreadStaticAttribute") == 0;
    }

    void Image::ReadMemberRefParentFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, ResolveMemberRefParent& ret)
    {
        ret.parentType = tableType;
        switch (tableType)
        {
        case hybridclr::metadata::TableType::TYPEREF:
            ret.type = ReadTypeFromTypeRef(rowIndex);
            break;
        case hybridclr::metadata::TableType::TYPEDEF:
            ret.type = ReadTypeFromTypeDef(rowIndex);
            break;
        case hybridclr::metadata::TableType::METHOD:
            RaiseNotSupportedException("ReadMemberRefParentFromToken. from METHOD");
            break;
        case hybridclr::metadata::TableType::MODULEREF:
            RaiseNotSupportedException("ReadMemberRefParentFromToken. from MODULEREF");
            break;
        case hybridclr::metadata::TableType::TYPESPEC:
            ret.type = ReadTypeFromTypeSpec(klassGenericContainer, methodGenericContainer, rowIndex);
            break;
        default:
        {
            RaiseExecutionEngineException("ReadMemberRefParentFromToken. invalid table type");
            break;
        }
        }
    }

#pragma region type

    const Il2CppType* Image::ReadArrayType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer)
    {
        Il2CppType* arrType = MetadataMallocT<Il2CppType>();;
        arrType->type = IL2CPP_TYPE_ARRAY;
        Il2CppArrayType& type = *MetadataMallocT<Il2CppArrayType>();
        arrType->data.array = &type;

        const Il2CppType* eleType = ReadType(reader, klassGenericContainer, methodGenericContainer);
        type.etype = eleType;
        type.rank = reader.ReadCompressedUint32();
        type.numsizes = reader.ReadCompressedUint32();
        if (type.numsizes > 0)
        {
            type.sizes = (int*)HYBRIDCLR_CALLOC(type.numsizes, sizeof(int));
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
            type.lobounds = (int*)HYBRIDCLR_CALLOC(type.numlobounds, sizeof(int));
            for (uint8_t i = 0; i < type.numlobounds; i++)
            {
                type.lobounds[i] = reader.ReadCompressedInt32();
            }
        }
        else
        {
            type.lobounds = nullptr;
        }
        return arrType;
    }

    const Il2CppGenericClass* Image::ReadGenericClass(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer)
    {
        const Il2CppType* genericBase = ReadType(reader, klassGenericContainer, methodGenericContainer);
        IL2CPP_ASSERT(genericBase->type == IL2CPP_TYPE_CLASS || genericBase->type == IL2CPP_TYPE_VALUETYPE);

        uint32_t argc = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(argc > 0 && argc <= 32);
        const Il2CppType* types[32];
        //const Il2CppType** types = (const Il2CppType**)alloca(argc * sizeof(const Il2CppType*));
        for (uint32_t i = 0; i < argc; i++)
        {
            types[i] = ReadType(reader, klassGenericContainer, methodGenericContainer);
        }
        const Il2CppGenericInst* genericInst = il2cpp::vm::MetadataCache::GetGenericInst(types, argc);

        return il2cpp::metadata::GenericMetadata::GetGenericClass(genericBase, genericInst);
    }

    const Il2CppType* Image::ReadType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer)
    {
        Il2CppType type = {};
        const Il2CppType* underlyingType = nullptr;
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
        case IL2CPP_TYPE_TYPEDBYREF:
        case IL2CPP_TYPE_I:
        case IL2CPP_TYPE_U:
        {
            SET_IL2CPPTYPE_VALUE_TYPE(type, 1);
            break;
        }
        case IL2CPP_TYPE_STRING:
        {
            break;
        }
        case IL2CPP_TYPE_PTR:
        {
            //SET_IL2CPPTYPE_VALUE_TYPE(type, 1);
            type.data.type = ReadType(reader, klassGenericContainer, methodGenericContainer);
            //SET_IL2CPPTYPE_VALUE_TYPE(type, 1);
            break;
        }
        case IL2CPP_TYPE_BYREF:
        {
            //const Il2CppType* underlyingType = ReadType(reader, klassGenericContainer, methodGenericContainer);
            //type = *underlyingType;
            type.byref = 1;
            goto readAgain;
        }
        case IL2CPP_TYPE_VALUETYPE:
        case IL2CPP_TYPE_CLASS:
        {
            uint32_t codedIndex = reader.ReadCompressedUint32(); // 低2位为type, 高位为index
            underlyingType = ReadTypeFromToken(klassGenericContainer, methodGenericContainer, DecodeTypeDefOrRefOrSpecCodedIndexTableType(codedIndex), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(codedIndex));
            break;
        }
        case IL2CPP_TYPE_ARRAY:
        {
            underlyingType = ReadArrayType(reader, klassGenericContainer, methodGenericContainer);
            break;
        }
        case IL2CPP_TYPE_GENERICINST:
        {
            const Il2CppGenericClass* genericClass = ReadGenericClass(reader, klassGenericContainer, methodGenericContainer);
            type.data.generic_class = const_cast<Il2CppGenericClass*>(genericClass);
            COPY_IL2CPPTYPE_VALUE_TYPE_FLAG(type, *genericClass->type);
            break;
        }
        case IL2CPP_TYPE_FNPTR:
        {
            // il2cpp doesn't support FNPTR. il2cpp treats IL2CPP_TYPE_FNPTR as IL2CPP_TYPE_I.
            // so we handle it as IL2CPP_TYPE_I.
            // 
            //MethodRefSig* method = new (HYBRIDCLR_MALLOC(sizeof(MethodRefSig))) MethodRefSig();
            //ReadMethodRefSig(reader, *method);
            //type.data.method = method;
            type.type = IL2CPP_TYPE_I;
            MethodRefSig method = {};
            ReadMethodRefSig(reader, method);
            break;
        }
        case IL2CPP_TYPE_OBJECT:
        {
            break;
        }
        case IL2CPP_TYPE_SZARRAY:
        {
            type.data.type = ReadType(reader, klassGenericContainer, methodGenericContainer);
            break;
        }
        case IL2CPP_TYPE_VAR:
        {
            IL2CPP_ASSERT(!klassGenericContainer || !klassGenericContainer->is_method);
            uint32_t number = reader.ReadCompressedUint32();
            if (klassGenericContainer)
            {
                //IL2CPP_ASSERT(hybridclr::metadata::IsInterpreterIndex(klassGenericContainer->ownerIndex));
                type.data.genericParameterHandle = il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex((Il2CppMetadataGenericContainerHandle)klassGenericContainer, number);
            }
            else
            {
                type.data.__genericParameterIndex = number;
            }
            /*Il2CppGenericParameter* gp = (Il2CppGenericParameter*)type.data.genericParameterHandle;
            IL2CPP_ASSERT(hybridclr::metadata::IsInterpreterIndex(gp->ownerIndex));*/
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
            const Il2CppType* modType = ReadTypeFromToken(nullptr, nullptr, DecodeTypeDefOrRefOrSpecCodedIndexTableType(encodeToken), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(encodeToken));
            if (modType->type != IL2CPP_TYPE_CLASS && modType->type != IL2CPP_TYPE_VALUETYPE)
            {
                goto readAgain;
            }
            IL2CPP_ASSERT(modType->data.typeHandle);
            const Il2CppTypeDefinition* modTypeDef = (const Il2CppTypeDefinition*)modType->data.typeHandle;
            const char* modTypeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(modTypeDef->nameIndex);
            const char* modTypeNamespace = il2cpp::vm::GlobalMetadata::GetStringFromIndex(modTypeDef->namespaceIndex);
            if (std::strcmp(modTypeNamespace, "System.Runtime.InteropServices") == 0)
            {
                if (std::strcmp(modTypeName, "InAttribute") == 0)
                {
                    type.attrs |= PARAM_ATTRIBUTE_IN;
                }
                else if (std::strcmp(modTypeName, "OutAttribute") == 0)
                {
                    type.attrs |= PARAM_ATTRIBUTE_OUT;
                }
                else if (std::strcmp(modTypeName, "OptionalAttribute") == 0)
                {
                    type.attrs |= PARAM_ATTRIBUTE_OPTIONAL;
                }
            }
            goto readAgain;
        }
        case IL2CPP_TYPE_CMOD_OPT:
        {
            ++type.num_mods;
            uint32_t encodeToken = reader.ReadCompressedUint32();
            goto readAgain;
        }
        case IL2CPP_TYPE_INTERNAL:
        {
            RaiseNotSupportedException("Image::ReadType IL2CPP_TYPE_INTERNAL");
            break;
        }
        case IL2CPP_TYPE_MODIFIER:
        {
            RaiseNotSupportedException("Image::ReadType IL2CPP_TYPE_MODIFIER");
            break;
        }
        case IL2CPP_TYPE_SENTINEL:
        {
            break;
        }
        case IL2CPP_TYPE_PINNED:
        {
            type.pinned = true;
            goto readAgain;
        }
        default:
        {
            RaiseBadImageException("Image::ReadType invalid type");
            break;
        }
        }
        if (underlyingType)
        {
            type.type = underlyingType->type;
            type.data = underlyingType->data;
            COPY_IL2CPPTYPE_VALUE_TYPE_FLAG(type, *underlyingType);
        }
        if (type.byref)
        {
            SET_IL2CPPTYPE_VALUE_TYPE(type, 0);
        }
        return MetadataPool::GetPooledIl2CppType(type);
    }

    const Il2CppType* Image::ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName)
    {
        TableType tokenType;
        uint32_t rawIndex;
        DecodeResolutionScopeCodedIndex(scope, tokenType, rawIndex);
        switch (tokenType)
        {
        case TableType::MODULE:
        {
            return GetModuleIl2CppType(rawIndex, typeNamespace, typeName, true);
        }
        case TableType::MODULEREF:
        {
            RaiseNotSupportedException("Image::ReadTypeFromResolutionScope not support ResolutionScore.MODULEREF");
            break;
        }
        case TableType::ASSEMBLYREF:
        {
            TbAssemblyRef assRef = _rawImage->ReadAssemblyRef(rawIndex);
            return GetIl2CppType(rawIndex, typeNamespace, typeName, true);
        }
        case TableType::TYPEREF:
        {
            const Il2CppType* enClosingType = ReadTypeFromTypeRef(rawIndex);
            IL2CPP_ASSERT(typeNamespace == 0);
            const char* name = _rawImage->GetStringFromRawIndex(typeName);

            void* iter = nullptr;
            Il2CppMetadataTypeHandle enclosingTypeDef = enClosingType->data.typeHandle;
            if (!enclosingTypeDef)
            {
                TEMP_FORMAT(errMsg, "Image::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF enclosingType:%s", name);
                RaiseExecutionEngineException(errMsg);
            }
            for (const Il2CppTypeDefinition* nextTypeDef; (nextTypeDef = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetNestedTypes(enclosingTypeDef, &iter));)
            {
                const char* nestedTypeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(nextTypeDef->nameIndex);
                IL2CPP_ASSERT(nestedTypeName);
                if (!std::strcmp(name, nestedTypeName))
                {
                    return GetIl2CppTypeFromTypeDefinition(nextTypeDef);
                }
            }

            std::string enclosingTypeName = GetKlassCStringFullName(enClosingType);
            TEMP_FORMAT(errMsg, "Image::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF fail. type:%s.%s", enclosingTypeName.c_str(), name);
            RaiseExecutionEngineException(errMsg);
            break;
        }
        default:
        {
            RaiseBadImageException("Image::ReadTypeFromResolutionScope invaild TableType");
            break;
        }
        }
        return nullptr;
    }

    const Il2CppType* Image::ReadTypeFromTypeDef(uint32_t rowIndex)
    {
        return GetIl2CppTypeFromRawTypeDefIndex(rowIndex - 1);
    }

    const Il2CppType* Image::ReadTypeFromTypeRef(uint32_t rowIndex)
    {
        TbTypeRef r = _rawImage->ReadTypeRef(rowIndex);
        return ReadTypeFromResolutionScope(r.resolutionScope, r.typeNamespace, r.typeName);
    }

    const Il2CppType* Image::ReadTypeFromTypeSpec(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex)
    {
        TbTypeSpec r = _rawImage->ReadTypeSpec(rowIndex);
        BlobReader reader = _rawImage->GetBlobReaderByRawIndex(r.signature);
        return ReadType(reader, klassGenericContainer, methodGenericContainer);
    }

    const Il2CppType* Image::ReadTypeFromMemberRefParent(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex)
    {
        ResolveMemberRefParent mrp = {};
        ReadMemberRefParentFromToken(klassGenericContainer, methodGenericContainer, tableType, rowIndex, mrp);
        IL2CPP_ASSERT(mrp.parentType == TableType::TYPEDEF || mrp.parentType == TableType::TYPEREF || mrp.parentType == TableType::TYPESPEC);
        return mrp.type;
    }

    const Il2CppType* Image::ReadTypeFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex)
    {
        switch (tableType)
        {
        case TableType::TYPEDEF:
        {
            return ReadTypeFromTypeDef(rowIndex);
        }
        case TableType::TYPEREF:
        {
            return ReadTypeFromTypeRef(rowIndex);
        }
        case TableType::TYPESPEC:
        {
            return ReadTypeFromTypeSpec(klassGenericContainer, methodGenericContainer, rowIndex);
        }
        default:
        {
            RaiseBadImageException("Image::ReadTypeFromToken invalid TableType");
            return nullptr;
        }
        }
    }

#pragma endregion

    void Image::ReadFieldRefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, FieldRefSig& field)
    {
        field = {};
        uint8_t rawSigType = reader.ReadByte();
        SigType sigType = DecodeSigType(rawSigType);
        IL2CPP_ASSERT(sigType == SigType::FIELD);
        field.type = ReadType(reader, klassGenericContainer, nullptr);
    }

    void Image::ReadMethodRefSig(BlobReader& reader, MethodRefSig& method)
    {
        method = {};
        uint8_t rawSigFlags = reader.ReadByte();
        method.flags = rawSigFlags;
        if (rawSigFlags & (uint8_t)SigType::GENERIC)
        {
            method.genericParamCount = reader.ReadCompressedUint32();
        }
        uint32_t paramCount = reader.ReadCompressedUint32();

        method.returnType = ReadType(reader, nullptr, nullptr);

        bool sentinel = false;
        for (uint32_t readParamNum = 0; readParamNum < paramCount; ++readParamNum)
        {
            const Il2CppType* paramType = ReadType(reader, nullptr, nullptr);
            if (paramType->type == IL2CPP_TYPE_SENTINEL)
            {
                IL2CPP_ASSERT(rawSigFlags & (uint8_t)SigType::VARARG);
                sentinel = true;
                continue;
            }
            method.params.push_back(paramType);
        }
    }

    void Image::ReadMemberRefSig(const Il2CppGenericContainer* klassGenericContainer, TbMemberRef& data, ResolveMemberRefSig& signature)
    {
        BlobReader reader = _rawImage->GetBlobReaderByRawIndex(data.signature);
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
            ReadMethodRefSig(reader, signature.method);
        }
    }


    void Image::ReadMethodRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, MethodRefInfo& ret)
    {
        IL2CPP_ASSERT(rowIndex > 0);
        switch (tableType)
        {
        case TableType::METHOD:
        {
            const Il2CppMethodDefinition* methodDef = GetMethodDefinitionFromRawIndex(rowIndex - 1);
            const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(methodDef->declaringType);
            const Il2CppType* type = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->byvalTypeIndex);
            ret.containerType = type;
            ret.methodDef = methodDef;
            IL2CPP_ASSERT(type);
            IL2CPP_ASSERT(methodDef);
            break;
        }
        case TableType::MEMBERREF:
        {
            ReadMethodRefInfoFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, ret);
            break;
        }
        case TableType::METHODSPEC:
        {
            TbMethodSpec methodSpec = _rawImage->ReadMethodSpec(rowIndex);

            ret.instantiation = ReadMethodSpecInstantiation(methodSpec.instantiation, klassGenericContainer, methodGenericContainer);
            TableType methodTableType = DecodeMethodDefOrRefCodedIndexTableType(methodSpec.method);
            uint32_t methodRowIndex = DecodeMethodDefOrRefCodedIndexRowIndex(methodSpec.method);
            switch (methodTableType)
            {
            case TableType::METHOD:
            {
                ReadMethodRefInfoFromToken(klassGenericContainer, methodGenericContainer, methodTableType, methodRowIndex, ret);
                break;
            }
            case TableType::MEMBERREF:
            {
                ReadMethodRefInfoFromMemberRef(klassGenericContainer, methodGenericContainer, methodRowIndex, ret);
                break;
            }
            default:
            {
                RaiseBadImageException("Image::ReadMethodRefInfoFromToken METHODSPEC invalid TableType");
                break;
            }
            }
            break;
        }
        default:
        {
            RaiseBadImageException("Image::ReadMethodRefInfoFromToken invalid TableType");
        }
        }
    }

    void Image::ReadResolveMemberRefFromMemberRef(const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, ResolveMemberRef& ret)
    {
        TbMemberRef data = _rawImage->ReadMemberRef(rowIndex);
        ret.name = _rawImage->GetStringFromRawIndex(data.name);
        ReadMemberRefParentFromToken(klassGenericContainer, methodGenericContainer, DecodeMemberRefParentType(data.classIdx), DecodeMemberRefParentRowIndex(data.classIdx), ret.parent);
        IL2CPP_ASSERT(ret.parent.parentType == TableType::TYPEDEF || ret.parent.parentType == TableType::TYPEREF || ret.parent.parentType == TableType::TYPESPEC);
        ReadMemberRefSig(nullptr, data, ret.signature);
    }

    void Image::ReadMethodRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, MethodRefInfo& ret)
    {
        ResolveMemberRef rmr = {};
        ReadResolveMemberRefFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, rmr);
        IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
        IL2CPP_ASSERT(rmr.signature.memberType == TableType::METHOD_POINTER);
        ret.containerType = rmr.parent.type;
        ret.methodDef = ResolveMethodDefinition(rmr.parent.type, rmr.name, rmr.signature.method);
    }

    const Il2CppGenericInst* Image::ReadMethodSpecInstantiation(uint32_t signature, const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer)
    {
        BlobReader reader = _rawImage->GetBlobReaderByRawIndex(signature);
        uint8_t rawSigFlags = reader.ReadByte();
        IL2CPP_ASSERT(rawSigFlags == 0xA);
        uint32_t argCount = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(argCount >= 0 && argCount < 100);
        if (argCount == 0)
        {
            return nullptr;
        }

        IL2CPP_ASSERT(argCount > 0 && argCount <= 32);
        const Il2CppType* types[32];

        //genericInstantiation = (Il2CppGenericInst*)il2cpp::vm::MetadataMalloc(sizeof(Il2CppGenericInst));
        //genericInstantiation->type_argc = argCount;
        //genericInstantiation->type_argv = (const Il2CppType**)il2cpp::vm::MetadataCalloc(argCount, sizeof(Il2CppType*));
        for (uint32_t i = 0; i < argCount; i++)
        {
            const Il2CppType* type = ReadType(reader, klassGenericContainer, methodGenericContainer);
            types[i] = type;
        }
        return il2cpp::vm::MetadataCache::GetGenericInst(types, argCount);
    }

    void Image::ReadFieldRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, FieldRefInfo& ret)
    {
        ResolveMemberRef rmr = {};
        ReadResolveMemberRefFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, rmr);
        IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
        IL2CPP_ASSERT(rmr.signature.memberType == TableType::FIELD_POINTER);
        ret.containerType = rmr.parent.type;
        ResolveFieldThrow(rmr.parent.type, rmr.name, rmr.signature.field.type, ret.field);
    }

    void Image::ReadLocalVarSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, il2cpp::utils::dynamic_array<const Il2CppType*>& vars)
    {
        uint8_t sig = reader.ReadByte();
        IL2CPP_ASSERT(sig == 0x7);
        uint32_t varCount = reader.ReadCompressedUint32();
        IL2CPP_ASSERT(varCount >= 1 && varCount <= 0xFFFE);
        vars.resize_uninitialized(varCount);
        for (uint32_t i = 0; i < varCount; i++)
        {
            vars[i] = ReadType(reader, klassGenericContainer, methodGenericContainer);
        }
    }

    void Image::ReadStandAloneSig(uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, ResolveStandAloneMethodSig& methodSig)
    {
        BlobReader reader = _rawImage->GetBlobReaderByRawIndex(signatureIdx);
        uint8_t sig = reader.ReadByte();
        methodSig.flags = sig;
        uint32_t paramCount = reader.ReadCompressedUint32();
        if (paramCount > 0xFFFE)
        {
            RaiseBadImageException("ReadStandAloneSig exceed max param count");
        }
        methodSig.returnType = ReadType(reader, klassGenericContainer, methodGenericContainer);
        if (paramCount > 0)
        {
            for (uint32_t i = 0; i < paramCount; i++)
            {
                methodSig.params.push_back(ReadType(reader, klassGenericContainer, methodGenericContainer));
            }
        }
        if (reader.NonEmpty())
        {
            RaiseNotSupportedException("ReadStandAloneSig don't support sentinel params");
        }
    }

    Il2CppClass* Image::FindNetStandardExportedType(const char* namespaceStr, const char* nameStr)
    {
        for (const char** ptrAssName = s_netstandardRefs; *ptrAssName; ptrAssName++)
        {
            const Il2CppAssembly* refAss = GetLoadedAssembly(*ptrAssName);
            if (refAss)
            {
                const Il2CppImage* image2 = il2cpp::vm::Assembly::GetImage(refAss);
                Il2CppClass* klass = il2cpp::vm::Class::FromName(image2, namespaceStr, nameStr);
                if (klass)
                {
                    return klass;
                }
            }
        }
        return nullptr;
    }

    const Il2CppType* Image::GetIl2CppType(uint32_t assemblyRefIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound)
    {
        TbAssemblyRef data = _rawImage->ReadAssemblyRef(assemblyRefIndex);
        const char* assName = _rawImage->GetStringFromRawIndex(data.name);
        const char* typeNameStr = _rawImage->GetStringFromRawIndex(typeName);
        const char* typeNamespaceStr = _rawImage->GetStringFromRawIndex(typeNamespace);
        const Il2CppAssembly* refAss = GetLoadedAssembly(assName);
        Il2CppClass* klass = nullptr;
        if (refAss)
        {
            const Il2CppImage* image2 = il2cpp::vm::Assembly::GetImage(refAss);
            klass = il2cpp::vm::Class::FromName(image2, typeNamespaceStr, typeNameStr);
        }
        else if (!refAss && std::strcmp(assName, "netstandard") == 0)
        {
            klass = FindNetStandardExportedType(typeNamespaceStr, typeNameStr);
        }
        if (!klass)
        {
            if (!raiseExceptionIfNotFound)
            {
                return nullptr;
            }
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(
                CStringToStringView(typeNamespaceStr),
                CStringToStringView(typeNameStr),
                CStringToStringView(assName)));
        }
        return &klass->byval_arg;
    }

    void Image::ReadMethodBody(const Il2CppMethodDefinition& methodDef, const TbMethod& methodData, MethodBody& body)
    {
        uint32_t bodyRVA = methodData.rva;
        if (bodyRVA > 0)
        {
            uint32_t methodImageOffset = 0;
            bool ret = _rawImage->TranslateRVAToImageOffset(bodyRVA, methodImageOffset);
            IL2CPP_ASSERT(ret);
            const byte* bodyStart = _rawImage->GetDataPtrByImageOffset(methodImageOffset);
            byte bodyFlags = *bodyStart;
            byte smallFatFlags = bodyFlags & 0x3;

            if (smallFatFlags == (uint8_t)CorILMethodFormat::Tiny)
            {
                body.flags = (uint32_t)(bodyFlags & 0x3);
                body.ilcodes = bodyStart + 1;
                body.codeSize = (uint8_t)bodyFlags >> 2;
                body.maxStack = 8;
            }
            else
            {
                IL2CPP_ASSERT(smallFatFlags == (uint8_t)CorILMethodFormat::Fat);
                const CorILMethodFatHeader* methodHeader = (const CorILMethodFatHeader*)GetAlignBorder<4>(bodyStart);
                IL2CPP_ASSERT(methodHeader->size == 3);
                body.flags = methodHeader->flags;
                body.ilcodes = bodyStart + methodHeader->size * 4;
                body.codeSize = methodHeader->codeSize;
                body.maxStack = methodHeader->maxStack;

                if (methodHeader->localVarSigToken)
                {
                    TbStandAloneSig sigData = _rawImage->ReadStandAloneSig(DecodeTokenRowIndex(methodHeader->localVarSigToken));

                    BlobReader reader = _rawImage->GetBlobReaderByRawIndex(sigData.signature);
                    ReadLocalVarSig(reader,
                        GetGenericContainerByTypeDefRawIndex(DecodeMetadataIndex(methodDef.declaringType)),
                        GetGenericContainerByRawIndex(DecodeMetadataIndex(methodDef.genericContainerIndex)),
                        body.localVars);
                }
            }
            if (body.flags & (uint8_t)CorILMethodFormat::MoreSects)
            {
                const byte* nextSection = (const byte*)GetAlignBorder<4>(body.ilcodes + body.codeSize);
                while (true)
                {
                    byte kind = *nextSection;
                    if (!(kind & (byte)CorILSecion::EHTable))
                    {
                        IL2CPP_ASSERT(false && "not support kind");
                        break;
                    }
                    if (kind & (byte)CorILSecion::FatFormat)
                    {
                        CorILEHSectionHeaderFat* ehSec = (CorILEHSectionHeaderFat*)nextSection;
                        uint32_t dataSize = (uint32_t)ehSec->dataSize0 | ((uint32_t)ehSec->dataSize1 << 8) | ((uint32_t)ehSec->dataSize2 << 16);
                        IL2CPP_ASSERT(dataSize % 24 == 4);
                        uint32_t ehCount = (dataSize - 4) / 24;
                        body.exceptionClauses.reserve(ehCount);
                        for (uint32_t i = 0; i < ehCount; i++)
                        {
                            CorILEHFat& eh = ehSec->clauses[i];
                            IL2CPP_ASSERT(eh.flags >= (uint32_t)CorILExceptionClauseType::Exception && eh.flags <= (uint32_t)CorILExceptionClauseType::Fault);
                            body.exceptionClauses.push_back({
                                (CorILExceptionClauseType)eh.flags,
                                eh.tryOffset,
                                eh.tryLength,
                                eh.handlerOffset,
                                eh.handlerLength,
                                eh.classTokenOrFilterOffset });
                        }
                        nextSection += dataSize;
                    }
                    else
                    {
                        CorILEHSectionHeaderSmall* ehSec = (CorILEHSectionHeaderSmall*)nextSection;
                        IL2CPP_ASSERT(ehSec->dataSize % 12 == 4);
                        uint32_t ehCount = (ehSec->dataSize - 4) / 12;
                        body.exceptionClauses.reserve(ehCount);
                        for (uint32_t i = 0; i < ehCount; i++)
                        {
                            CorILEHSmall& eh = ehSec->clauses[i];
                            IL2CPP_ASSERT(eh.flags >= 0 && eh.flags <= 4);
                            body.exceptionClauses.push_back({
                                (CorILExceptionClauseType)eh.flags,
                                eh.tryOffset,
                                eh.tryLength,
                                ((uint32_t)eh.handlerOffset1 << 8) + eh.handlerOffset0,
                                eh.handlerLength,
                                eh.classTokenOrFilterOffset });
                        }
                        nextSection += ehSec->dataSize;
                    }
                    if (!(kind & (byte)CorILSecion::MoreSects))
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            body.ilcodes = nullptr;
            body.codeSize = 0;
        }
    }

    const MethodInfo* Image::FindImplMethod(Il2CppClass* klass, const MethodInfo* method)
    {
        if (!IsVirtualMethod(method->flags))
        {
            return method;
        }
        il2cpp::vm::Class::Init(klass);
        const MethodInfo* result;
        if (hybridclr::metadata::IsInterface(method->klass->flags))
        {
            result = il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(klass, method->klass, method->slot)->method;
        }
        else
        {
            result = klass->vtable[method->slot].method;
        }
        IL2CPP_ASSERT(!method->genericMethod || method->is_inflated);
        if (method->genericMethod && method->genericMethod->context.method_inst/* && method->genericMethod*/) // means it's genericInstance method 或generic method
        {
            result = GetGenericVirtualMethod(result, method);
        }
        return result;
    }


    Il2CppString* Image::GetIl2CppUserStringFromRawIndex(StringIndex index)
    {
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
        Il2CppString* clrStr;
        if (_il2cppStringCache.TryGetValue(index, &clrStr))
        {
            return clrStr;
        }
        else
        {
            Il2CppString* clrStr = _rawImage->GetUserStringBlogByIndex((uint32_t)index);
#if HYBRIDCLR_UNITY_2022_OR_NEW
            _il2cppStringCache.GetOrAdd(index, clrStr);
#else
            _il2cppStringCache.Add(index, clrStr);
#endif
            return clrStr;
        }
    }

    Il2CppClass* Image::GetClassFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
    {
        TokenGenericContextType key = { token, genericContext };
        auto it = tokenCache.find(key);
        if (it != tokenCache.end())
        {
            return (Il2CppClass*)it->second;
        }

        const Il2CppType* originType = ReadTypeFromToken(klassGenericContainer, methodGenericContainer, DecodeTokenTableType(token), DecodeTokenRowIndex(token));
        const Il2CppType* resultType = genericContext != nullptr ? il2cpp::metadata::GenericMetadata::InflateIfNeeded(originType, genericContext, true) : originType;
        Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(resultType);
        if (!klass)
        {
            TEMP_FORMAT(errMsg, "InterpreterImage::GetClassFromToken token:%u class not exists", token);
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException(errMsg));
        }
        tokenCache.insert({ key, (void*)klass });
        return klass;
    }

    const FieldInfo* Image::GetFieldInfoFromFieldRef(const Il2CppType& type, const Il2CppFieldDefinition* fieldDef)
    {
        Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(&type);
        const char* name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(fieldDef->nameIndex);
        void* iter = nullptr;
        for (const FieldInfo* cur = nullptr; (cur = il2cpp::vm::Class::GetFields(klass, &iter)) != nullptr; )
        {
            if (cur->token == fieldDef->token)
            {
                IL2CPP_ASSERT(std::strcmp(cur->name, name) == 0);
                return cur;
            }
        }
        RaiseMissingFieldException(&type, name);
        return nullptr;
    }

    const MethodInfo* Image::ResolveMethodInfo(const Il2CppType* type, const char* resolveMethodName, const MethodRefSig& resolveSig, const Il2CppGenericInst* genericInstantiation, const Il2CppGenericContext* genericContext)
    {
        if (type->type != IL2CPP_TYPE_ARRAY)
        {
            const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
            const Il2CppGenericContainer* klassGenericContainer = GetGenericContainerFromIl2CppType(type);
            const char* typeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
            for (uint32_t i = 0; i < typeDef->method_count; i++)
            {
                const Il2CppMethodDefinition* methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(typeDef->methodStart + i);
                const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex);
                IL2CPP_ASSERT((genericInstantiation ? genericInstantiation->type_argc : 0) == resolveSig.genericParamCount);
                if (std::strcmp(resolveMethodName, methodName) == 0 && IsMatchMethodSig(methodDef, resolveSig, klassGenericContainer))
                {
                    return GetMethodInfo(type, methodDef, genericInstantiation, genericContext);
                }
            }
        }
        else
        {
            IL2CPP_ASSERT(genericInstantiation == nullptr);
            Il2CppClass* arrayKlass = il2cpp::vm::Class::FromIl2CppType(type);
            il2cpp::vm::Class::SetupMethods(arrayKlass);
            const Il2CppType** genericClassInstArgv = genericContext && genericContext->class_inst ? genericContext->class_inst->type_argv : nullptr;
            const Il2CppType** genericMethodInstArgv = genericContext && genericContext->method_inst ? genericContext->method_inst->type_argv : nullptr;

            for (uint16_t i = 0; i < arrayKlass->method_count; i++)
            {
                const MethodInfo* method = arrayKlass->methods[i];
                if (std::strcmp(resolveMethodName, method->name) == 0 && IsMatchMethodSig(method, resolveSig, genericClassInstArgv, genericMethodInstArgv))
                {
                    return method;
                }
            }
        }
        RaiseMethodNotFindException(type, resolveMethodName);
        return nullptr;
    }

    const void* Image::ReadRuntimeHandleFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, uint32_t rowIndex)
    {
        ResolveMemberRef rmr = {};
        ReadResolveMemberRefFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, rmr);
        if (rmr.signature.memberType == TableType::FIELD_POINTER)
        {
            const Il2CppFieldDefinition* fieldDef = nullptr;
            ResolveFieldThrow(rmr.parent.type, rmr.name, rmr.signature.field.type, fieldDef);
            if (!fieldDef)
            {
                RaiseMissingFieldException(rmr.parent.type, rmr.name);
            }
            const Il2CppType* parentType = genericContext != nullptr ? il2cpp::metadata::GenericMetadata::InflateIfNeeded(rmr.parent.type, genericContext, true) : rmr.parent.type;
            const FieldInfo* fieldInfo = GetFieldInfoFromFieldRef(*parentType, fieldDef);
            return fieldInfo;
        }
        else if (rmr.signature.memberType == TableType::METHOD_POINTER)
        {
            const Il2CppType* parentType = genericContext != nullptr ? il2cpp::metadata::GenericMetadata::InflateIfNeeded(rmr.parent.type, genericContext, true) : rmr.parent.type;
            return ResolveMethodInfo(parentType, rmr.name, rmr.signature.method, nullptr, genericContext);
        }
        else
        {
            RaiseExecutionEngineException("GetRuntimeHandleFromToken invaild ParentType");
            return nullptr;
        }
    }

    const void* Image::GetRuntimeHandleFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
    {
        TableType ttype = DecodeTokenTableType(token);
        uint32_t rowIndex = DecodeTokenRowIndex(token);
        const void* handle = nullptr;
        switch (ttype)
        {
        case hybridclr::metadata::TableType::TYPEREF:
        case hybridclr::metadata::TableType::TYPEDEF:
        case hybridclr::metadata::TableType::TYPESPEC:
        {
            const Il2CppType* type = ReadTypeFromToken(klassGenericContainer, methodGenericContainer, ttype, rowIndex);
            if (genericContext)
            {
                type = TryInflateIfNeed(type, genericContext, true);
            }
            handle = type;
            break;
        }
        case hybridclr::metadata::TableType::FIELD:
        {
            handle = GetFieldInfoFromToken(tokenCache, token, klassGenericContainer, methodGenericContainer, genericContext);
            break;
        }
        case hybridclr::metadata::TableType::METHOD:
        case hybridclr::metadata::TableType::METHODSPEC:
        {
            handle = GetMethodInfoFromToken(tokenCache, token, klassGenericContainer, methodGenericContainer, genericContext);
            break;
        }
        case hybridclr::metadata::TableType::MEMBERREF:
        {
            handle = ReadRuntimeHandleFromMemberRef(klassGenericContainer, methodGenericContainer, genericContext, rowIndex);
            //_token2RuntimeHandleCache.insert({ key, (void*)handle });
            break;
        }
        default:
        {
            RaiseExecutionEngineException("GetRuntimeHandleFromToken invaild TableType");
            return nullptr;
        }
        }
        return handle;
    }

    const FieldInfo* Image::GetFieldInfoFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
    {
        TokenGenericContextType key = { token, genericContext };
        auto it = tokenCache.find(key);
        if (it != tokenCache.end())
        {
            return (const FieldInfo*)it->second;
        }

        FieldRefInfo fri;
        ReadFieldRefInfoFromToken(klassGenericContainer, methodGenericContainer, DecodeTokenTableType(token), DecodeTokenRowIndex(token), fri);
        if (!fri.field)
        {
            TEMP_FORMAT(errMsg, "token:%d", token);
            RaiseMissingFieldException(fri.containerType, errMsg);
        }
        const Il2CppType* resultType = genericContext != nullptr ? il2cpp::metadata::GenericMetadata::InflateIfNeeded(fri.containerType, genericContext, true) : fri.containerType;
        const FieldInfo* fieldInfo = GetFieldInfoFromFieldRef(*resultType, fri.field);
        il2cpp::vm::Class::Init(fieldInfo->parent);
        tokenCache.insert({ key, (void*)fieldInfo });
        return fieldInfo;
    }


    const MethodInfo* Image::ReadMethodInfoFromToken(const Il2CppGenericContainer* klassGenericContainer,
        const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, const Il2CppGenericInst* genericInst, TableType tableType, uint32_t rowIndex)
    {
        IL2CPP_ASSERT(rowIndex > 0);
        switch (tableType)
        {
        case TableType::METHOD:
        {
            const Il2CppMethodDefinition* methodDef = GetMethodDefinitionFromRawIndex(rowIndex - 1);
            const Il2CppTypeDefinition* declareType = (Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(methodDef->declaringType);
            const Il2CppType* type = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(declareType->byvalTypeIndex);
            return GetMethodInfo(type, methodDef, genericInst, genericContext);
        }
        case TableType::MEMBERREF:
        {
            ResolveMemberRef rmr = {};
            ReadResolveMemberRefFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, rmr);
            IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
            IL2CPP_ASSERT(rmr.signature.memberType == TableType::METHOD_POINTER);
            if (genericContext)
            {
                rmr.parent.type = TryInflateIfNeed(rmr.parent.type, genericContext, true);
            }
            return ResolveMethodInfo(rmr.parent.type, rmr.name, rmr.signature.method, genericInst, genericContext);
        }
        case TableType::METHODSPEC:
        {
            TbMethodSpec methodSpec = _rawImage->ReadMethodSpec(rowIndex);
            const Il2CppGenericInst* genericInstantiation = ReadMethodSpecInstantiation(methodSpec.instantiation, klassGenericContainer, methodGenericContainer);
            genericInstantiation = TryInflateGenericInst(genericInstantiation, genericContext);

            TableType methodTableType = DecodeMethodDefOrRefCodedIndexTableType(methodSpec.method);
            uint32_t methodRowIndex = DecodeMethodDefOrRefCodedIndexRowIndex(methodSpec.method);
            switch (methodTableType)
            {
            case TableType::METHOD:
            {
                return ReadMethodInfoFromToken(klassGenericContainer, methodGenericContainer, genericContext, genericInstantiation, methodTableType, methodRowIndex);
            }
            case TableType::MEMBERREF:
            {
                return ReadMethodInfoFromToken(klassGenericContainer, methodGenericContainer, genericContext, genericInstantiation, methodTableType, methodRowIndex);
            }
            default:
            {
                RaiseBadImageException("ReadMethodSpec invaild TableType");
                return nullptr;
            }
            }
            break;
        }
        default:
        {
            RaiseBadImageException("ReadMethodInfoFromToken invaild TableType");
            return nullptr;
        }
        }
    }

    const MethodInfo* Image::GetMethodInfoFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext)
    {
        auto key = std::tuple<uint32_t, const Il2CppGenericContext*>(token, genericContext);
        auto it = tokenCache.find(key);
        if (it != tokenCache.end())
        {
            return (const MethodInfo*)it->second;
        }

        const MethodInfo* method = ReadMethodInfoFromToken(klassGenericContainer, methodGenericContainer, genericContext,
            nullptr, DecodeTokenTableType(token), DecodeTokenRowIndex(token));

        IL2CPP_ASSERT(method);
        il2cpp::vm::Class::Init(method->klass);

        tokenCache.insert({ key, (void*)method });
        return method;
    }

    const MethodInfo* Image::GetMethodInfo(const Il2CppType* containerType, const Il2CppMethodDefinition* methodDef, const Il2CppGenericInst* instantiation, const Il2CppGenericContext* genericContext)
    {
        const Il2CppType* finalContainerType = TryInflateIfNeed(containerType, genericContext, true);
        const MethodInfo* method = GetMethodInfoFromMethodDef(containerType, methodDef);
        IL2CPP_ASSERT(method);
        // final genericContext = finalContainerType.class_inst + mri.instantiation
        if (instantiation)
        {
            const Il2CppGenericInst* finalClassIns = finalContainerType->type == IL2CPP_TYPE_GENERICINST ? finalContainerType->data.generic_class->context.class_inst : nullptr;
            const Il2CppGenericInst* finalMethodIns = instantiation;
            Il2CppGenericContext finalGenericContext = { finalClassIns, finalMethodIns };
            method = method->is_inflated ? method->genericMethod->methodDefinition : method;
            method = il2cpp::metadata::GenericMetadata::Inflate(method, &finalGenericContext);
            IL2CPP_ASSERT(method);
        }
        return method;
    }

    void Image::GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig)
    {
        TbStandAloneSig sas = _rawImage->ReadStandAloneSig(DecodeTokenRowIndex(token));
        ReadStandAloneSig(sas.signature, klassGenericContainer, methodGenericContainer, methodSig);
        if (genericContext)
        {
            methodSig.returnType = TryInflateIfNeed(methodSig.returnType, genericContext, true);
            for (uint32_t i = 0, n = (uint32_t)methodSig.params.size(); i < n; i++)
            {
                methodSig.params[i] = TryInflateIfNeed(methodSig.params[i], genericContext, true);
            }
        }
    }

    void Image::ReadFieldRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, FieldRefInfo& ret)
    {
        IL2CPP_ASSERT(rowIndex > 0);
        if (tableType == TableType::FIELD)
        {
            ReadFieldRefInfoFromFieldDefToken(rowIndex, ret);
        }
        else
        {
            IL2CPP_ASSERT(tableType == TableType::MEMBERREF);
            ReadFieldRefInfoFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, ret);
        }
    }
}
}