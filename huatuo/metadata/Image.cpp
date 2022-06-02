#include "Image.h"

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
#ifdef HUATUO_UNITY_2021_OR_NEW
#include "icalls/mscorlib/System/RuntimeTypeHandle.h"
#else
#include "icalls/mscorlib/System.Reflection/PropertyInfo.h"
#endif
#include "icalls/mscorlib/System/Type.h"
#include "utils/StringUtils.h"

#include "MetadataUtil.h"
#include "BlobReader.h"

namespace huatuo
{
    namespace metadata
    {
        bool Image::IsValueTypeFromToken(TableType tableType, uint32_t rowIndex)
        {
            switch (tableType)
            {
            case TableType::TYPEREF:
            {
                TbTypeRef r = _rawImage.ReadTypeRef(rowIndex);
                const char* typeNamespace = _rawImage.GetStringFromRawIndex(r.typeNamespace);
                if (std::strcmp(typeNamespace, "System"))
                {
                    return false;
                }
                const char* typeName = _rawImage.GetStringFromRawIndex(r.typeName);
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
            TbMemberRef data = _rawImage.ReadMemberRef(rowIndex);
            TableType parentTableType = DecodeMemberRefParentType(data.classIdx);
            if (parentTableType != TableType::TYPEREF)
            {
                return false;
            }
            Il2CppType type = {};
            ReadTypeFromTypeRef(DecodeMemberRefParentRowIndex(data.classIdx), type);
            const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(&type);
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
            case huatuo::metadata::TableType::TYPEREF:
                ReadTypeFromTypeRef(rowIndex, ret.type);
                break;
            case huatuo::metadata::TableType::TYPEDEF:
                ReadTypeFromTypeDef(rowIndex, ret.type);
                break;
            case huatuo::metadata::TableType::METHOD:
                RaiseHuatuoNotSupportedException("ReadMemberRefParentFromToken. from METHOD");
                break;
            case huatuo::metadata::TableType::MODULEREF:
                RaiseHuatuoNotSupportedException("ReadMemberRefParentFromToken. from MODULEREF");
                break;
            case huatuo::metadata::TableType::TYPESPEC:
                ReadTypeFromTypeSpec(klassGenericContainer, methodGenericContainer, rowIndex, ret.type);
                break;
            default:
            {
                RaiseHuatuoExecutionEngineException("ReadMemberRefParentFromToken. invalid table type");
                break;
            }
            }
        }

#pragma region type

        void Image::ReadArrayType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppArrayType& type)
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

        void Image::ReadGenericClass(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericClass& type)
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

        void Image::ReadType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType& type)
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
            {
                SET_IL2CPPTYPE_VALUE_TYPE(type, 1);
                break;
            }
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
                ReadTypeFromToken(klassGenericContainer, methodGenericContainer, DecodeTypeDefOrRefOrSpecCodedIndexTableType(codedIndex), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(codedIndex), type);
                SET_IL2CPPTYPE_VALUE_TYPE(type, (etype == IL2CPP_TYPE_VALUETYPE));
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
                SET_IL2CPPTYPE_VALUE_TYPE(type, GET_IL2CPPTYPE_VALUE_TYPE(*genericClass->type));
                break;
            }
            case IL2CPP_TYPE_TYPEDBYREF:
            {
                SET_IL2CPPTYPE_VALUE_TYPE(type, 1);
                break;
            }
            case IL2CPP_TYPE_I:
            case IL2CPP_TYPE_U:
            {
                SET_IL2CPPTYPE_VALUE_TYPE(type, 1);
                break;
            }
            case IL2CPP_TYPE_FNPTR:
            {
                RaiseHuatuoNotSupportedException("Image::ReadType IL2CPP_TYPE_FNPTR");
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
                ReadTypeFromToken(nullptr, nullptr, DecodeTypeDefOrRefOrSpecCodedIndexTableType(encodeToken), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(encodeToken), modType);
                IL2CPP_ASSERT(modType.type == IL2CPP_TYPE_CLASS);
                IL2CPP_ASSERT(modType.data.typeHandle);
                const Il2CppTypeDefinition* modTypeDef = (const Il2CppTypeDefinition*)modType.data.typeHandle;
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
                RaiseHuatuoNotSupportedException("Image::ReadType IL2CPP_TYPE_INTERNAL");
                break;
            }
            case IL2CPP_TYPE_MODIFIER:
            {
                RaiseHuatuoNotSupportedException("Image::ReadType IL2CPP_TYPE_MODIFIER");
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
                RaiseBadImageException("Image::ReadType invalid type");
            }
            break;
            }
        }

        void Image::ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName, Il2CppType& type)
        {
            TableType tokenType;
            uint32_t rawIndex;
            DecodeResolutionScopeCodedIndex(scope, tokenType, rawIndex);
            switch (tokenType)
            {
            case TableType::MODULE:
            {
                RaiseHuatuoNotSupportedException("Image::ReadTypeFromResolutionScope not support ResolutionScore.MODULE");
                break;
            }
            case TableType::MODULEREF:
            {
                RaiseHuatuoNotSupportedException("Image::ReadTypeFromResolutionScope not support ResolutionScore.MODULEREF");
                break;
            }
            case TableType::ASSEMBLYREF:
            {
                TbAssemblyRef assRef = _rawImage.ReadAssemblyRef(rawIndex);
                GetIl2CppTypeFromTypeDefinition(GetTypeDefinition(rawIndex, typeNamespace, typeName), type);
                break;
            }
            case TableType::TYPEREF:
            {
                Il2CppType enClosingType = {};
                ReadTypeFromTypeRef(rawIndex, enClosingType);
                IL2CPP_ASSERT(typeNamespace == 0);
                const char* name = _rawImage.GetStringFromRawIndex(typeName);

                void* iter = nullptr;
                Il2CppMetadataTypeHandle enclosingTypeDef = enClosingType.data.typeHandle;
                if (!enclosingTypeDef)
                {
                    TEMP_FORMAT(errMsg, "Image::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF enclosingType:%s", name);
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
                RaiseBadImageException("Image::ReadTypeFromResolutionScope invaild TableType");
                break;
            }
            }
            IL2CPP_ASSERT(type.data.typeHandle);
        }

        void Image::ReadTypeFromTypeDef(uint32_t rowIndex, Il2CppType& type)
        {
            const Il2CppType* typeDef = GetIl2CppTypeFromRawTypeDefIndex(rowIndex - 1);
            type.type = typeDef->type;
            type.data.typeHandle = typeDef->data.typeHandle;
        }

        void Image::ReadTypeFromTypeRef(uint32_t rowIndex, Il2CppType& type)
        {
            TbTypeRef r = _rawImage.ReadTypeRef(rowIndex);
            ReadTypeFromResolutionScope(r.resolutionScope, r.typeNamespace, r.typeName, type);
        }

        void Image::ReadTypeFromTypeSpec(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, Il2CppType& type)
        {
            TbTypeSpec r = _rawImage.ReadTypeSpec(rowIndex);
            BlobReader reader = _rawImage.GetBlobReaderByRawIndex(r.signature);
            ReadType(reader, klassGenericContainer, methodGenericContainer, type);
        }

        void Image::ReadTypeFromMemberRefParent(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type)
        {
            ResolveMemberRefParent mrp = {};
            ReadMemberRefParentFromToken(klassGenericContainer, methodGenericContainer, tableType, rowIndex, mrp);
            type = mrp.type;
            IL2CPP_ASSERT(mrp.parentType == TableType::TYPEDEF || mrp.parentType == TableType::TYPEREF || mrp.parentType == TableType::TYPESPEC);
        }

        void Image::ReadTypeFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type)
        {
            switch (tableType)
            {
            case TableType::TYPEDEF:
            {
                ReadTypeFromTypeDef(rowIndex, type);
                break;
            }
            case TableType::TYPEREF:
            {
                ReadTypeFromTypeRef(rowIndex, type);
                break;
            }
            case TableType::TYPESPEC:
            {
                ReadTypeFromTypeSpec(klassGenericContainer, methodGenericContainer, rowIndex, type);
                break;
            }
            default:
            {
                RaiseBadImageException("Image::ReadTypeFromToken invalid TableType");
                break;
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
            ReadType(reader, klassGenericContainer, nullptr, field.type);
        }

        void Image::ReadMethodRefSig(TbMemberRef& data, MethodRefSig& method)
        {
            method = {};
            BlobReader reader = _rawImage.GetBlobReaderByRawIndex(data.signature);
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

        void Image::ReadMemberRefSig(const Il2CppGenericContainer* klassGenericContainer, TbMemberRef& data, ResolveMemberRefSig& signature)
        {
            BlobReader reader = _rawImage.GetBlobReaderByRawIndex(data.signature);
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
                ReadMethodRefSig(data, signature.method);
            }
        }

        void Image::ReadMethodDefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppMethodDefinition& methodDef, std::vector<ParamDetail>& paramArr)
        {
            uint8_t rawSigFlags = reader.ReadByte();

            if (rawSigFlags & (uint8_t)MethodSigFlags::GENERIC)
            {
                //IL2CPP_ASSERT(false);
                uint32_t genParamCount = reader.ReadCompressedUint32();
                Il2CppGenericContainer* gc = GetGenericContainerByRawIndex(DecodeMetadataIndex(methodDef.genericContainerIndex));
                IL2CPP_ASSERT(gc->type_argc == genParamCount);
            }
            uint32_t paramCount = reader.ReadCompressedUint32();
            //IL2CPP_ASSERT(paramCount >= methodDef.parameterCount);

            Il2CppType returnType = {};
            ReadType(reader, klassGenericContainer, methodGenericContainer, returnType);
            methodDef.returnType = AddIl2CppTypeCache(returnType);

            int readParamNum = 0;
            for (; reader.NonEmpty(); )
            {
                ParamDetail curParam = {};
                Il2CppType paramType = {};
                ReadType(reader, klassGenericContainer, methodGenericContainer, paramType);
                curParam.parameterIndex = readParamNum++;
                curParam.methodDef = &methodDef;
                curParam.paramDef.typeIndex = AddIl2CppTypeCache(paramType);
                paramArr.push_back(curParam);
            }
            IL2CPP_ASSERT(readParamNum == (int)paramCount);
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
                const Il2CppType* type = GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(GetTypeFromRawIndex(DecodeMetadataIndex(methodDef->declaringType))->byvalTypeIndex));
                ret.containerType = *type;
                ret.methodDef = methodDef;
                IL2CPP_ASSERT(type);
                IL2CPP_ASSERT(methodDef);
                break;
            }
            case TableType::MEMBERREF:
            {
                ReadMethodRefInfoFromMemberRef(klassGenericContainer, methodGenericContainer, nullptr, rowIndex, ret);
                break;
            }
            case TableType::METHODSPEC:
            {
                TbMethodSpec methodSpec = _rawImage.ReadMethodSpec(rowIndex);

                ReadMethodSpecInstantiation(methodSpec.instantiation, klassGenericContainer, methodGenericContainer, ret.instantiation);
                //FIXME instantiation memory leak

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
                    ReadMethodRefInfoFromMemberRef(klassGenericContainer, methodGenericContainer, ret.instantiation, methodRowIndex, ret);
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
            TbMemberRef data = _rawImage.ReadMemberRef(rowIndex);
            ret.name = _rawImage.GetStringFromRawIndex(data.name);
            ReadMemberRefParentFromToken(klassGenericContainer, methodGenericContainer, DecodeMemberRefParentType(data.classIdx), DecodeMemberRefParentRowIndex(data.classIdx), ret.parent);
            IL2CPP_ASSERT(ret.parent.parentType == TableType::TYPEDEF || ret.parent.parentType == TableType::TYPEREF || ret.parent.parentType == TableType::TYPESPEC);
            Il2CppType& parentType = ret.parent.type;
            ReadMemberRefSig(nullptr, data, ret.signature);
        }

        void Image::ReadMethodRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer,
            const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst* genericInstantiation, uint32_t rowIndex, MethodRefInfo& ret)
        {
            ResolveMemberRef rmr = {};
            ReadResolveMemberRefFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, rmr);
            IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
            IL2CPP_ASSERT(rmr.signature.memberType == TableType::METHOD_POINTER);
            ret.containerType = rmr.parent.type;
            ret.methodDef = ResolveMethodDefinition(&rmr.parent.type, rmr.name, rmr.signature.method, genericInstantiation);
        }

        void Image::ReadMethodSpecInstantiation(uint32_t signature, const Il2CppGenericContainer* klassGenericContainer,
            const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst*& genericInstantiation)
        {
            BlobReader reader = _rawImage.GetBlobReaderByRawIndex(signature);
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

        void Image::ReadFieldRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, FieldRefInfo& ret)
        {
            IL2CPP_ASSERT(rowIndex > 0);
            if (tableType == TableType::FIELD)
            {
                const FieldDetail& fd = GetFieldDetailFromRawIndex(rowIndex - 1);
                ret.containerType = *GetIl2CppTypeFromRawTypeDefIndex(DecodeMetadataIndex(fd.typeDefIndex));
                ret.field = &fd.fieldDef;
                //ret.classType = *image.GetIl2CppTypeFromRawTypeDefIndex(DecodeMetadataIndex(ret.field->typeIndex));
            }
            else
            {
                IL2CPP_ASSERT(tableType == TableType::MEMBERREF);
                ReadFieldRefInfoFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, ret);
            }
        }

        void Image::ReadFieldRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, FieldRefInfo& ret)
        {
            ResolveMemberRef rmr = {};
            ReadResolveMemberRefFromMemberRef(klassGenericContainer, methodGenericContainer, rowIndex, rmr);
            IL2CPP_ASSERT(rmr.parent.parentType == TableType::TYPEDEF || rmr.parent.parentType == TableType::TYPEREF || rmr.parent.parentType == TableType::TYPESPEC);
            IL2CPP_ASSERT(rmr.signature.memberType == TableType::FIELD_POINTER);
            ret.containerType = rmr.parent.type;
            ResolveField(&rmr.parent.type, rmr.name, &rmr.signature.field.type, ret.field);
        }

        void Image::ReadLocalVarSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType*& vars, uint32_t& varCount)
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

        void Image::ReadStandAloneSig(uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, ResolveStandAloneMethodSig& methodSig)
        {
            BlobReader reader = _rawImage.GetBlobReaderByRawIndex(signatureIdx);
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

        const Il2CppTypeDefinition* Image::GetTypeDefinition(uint32_t assemblyRefIndex, uint32_t typeNamespace, uint32_t typeName)
        {
            TbAssemblyRef data = _rawImage.ReadAssemblyRef(assemblyRefIndex);
            const char* assName = _rawImage.GetStringFromRawIndex(data.name);
            const char* typeNameStr = _rawImage.GetStringFromRawIndex(typeName);
            const char* typeNamespaceStr = _rawImage.GetStringFromRawIndex(typeNamespace);
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

    }
}