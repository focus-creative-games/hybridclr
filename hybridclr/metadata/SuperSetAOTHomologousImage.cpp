#include "SuperSetAOTHomologousImage.h"

#include "vm/MetadataLock.h"
#include "vm/GlobalMetadata.h"
#include "vm/Class.h"
#include "vm/Image.h"
#include "vm/Exception.h"
#include "vm/MetadataCache.h"
#include "metadata/GenericMetadata.h"
#include "MetadataPool.h"

namespace hybridclr
{
namespace metadata
{



	const Il2CppMethodDefinition* FindMatchMethod(const Il2CppTypeDefinition* aotTypeDef, const SuperSetMethodDefDetail& method2, const char* methodName, const MethodRefSig& methodSignature)
	{
		const Il2CppGenericContainer* klassGenContainer = aotTypeDef->genericContainerIndex != kGenericContainerIndexInvalid ?
			(const Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(aotTypeDef->genericContainerIndex) : nullptr;
		for (uint16_t i = 0; i < aotTypeDef->method_count; i++)
		{
			//const MethodInfo* method1 = klass1->methods[i];
			const Il2CppMethodDefinition* aotMethodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(aotTypeDef->methodStart + i);
			const char* aotMethodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(aotMethodDef->nameIndex);
			if (std::strcmp(aotMethodName, methodName))
			{
				continue;
			}
			if (IsMatchMethodSig(aotMethodDef, methodSignature, klassGenContainer))
			{
				return aotMethodDef;
			}
		}
		return nullptr;
	}


	const Il2CppFieldDefinition* FindMatchField(const Il2CppTypeDefinition* aotTypeDef, const SuperSetFieldDefDetail& field2, const char* fieldName, const Il2CppType* fieldType)
	{
		const Il2CppGenericContainer* klassGenContainer = aotTypeDef->genericContainerIndex != kGenericContainerIndexInvalid ?
			(const Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(aotTypeDef->genericContainerIndex) : nullptr;
		for (uint16_t i = 0; i < aotTypeDef->field_count; i++)
		{
			//const FieldInfo* field1 = klass1->fields + i;
			const Il2CppFieldDefinition* aotField = il2cpp::vm::GlobalMetadata::GetFieldDefinitionFromTypeDefAndFieldIndex(aotTypeDef, i);
			const char* aotFieldName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(aotField->nameIndex);
			if (std::strcmp(aotFieldName, fieldName))
			{
				continue;
			}
			const Il2CppType* aotFieldType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(aotField->typeIndex);
			if (IsMatchSigType(aotFieldType, fieldType, klassGenContainer, nullptr))
			{
				return aotField;
			}
		}
		return nullptr;
	}

	void SuperSetAOTHomologousImage::InitRuntimeMetadatas()
	{
		_defaultIl2CppType = &il2cpp_defaults.missing_class->byval_arg;

		std::vector< SuperSetTypeIntermediateInfo> typeIntermediateInfos;
		InitTypes0(typeIntermediateInfos);
		InitNestedClass(typeIntermediateInfos);
		InitTypes1(typeIntermediateInfos);

		InitMethods(typeIntermediateInfos);
		InitFields(typeIntermediateInfos);
	}

	void SuperSetAOTHomologousImage::InitTypes0(std::vector< SuperSetTypeIntermediateInfo>& typeIntermediateInfos)
	{
		const Table& typeDefTb = _rawImage->GetTable(TableType::TYPEDEF);
		uint32_t typeCount = typeDefTb.rowNum;
		typeIntermediateInfos.resize(typeCount);
		_typeDefs.resize(typeCount);
		_aotTypeIndex2TypeDefs.resize(typeCount);
	}

	void SuperSetAOTHomologousImage::InitNestedClass(std::vector<SuperSetTypeIntermediateInfo>& typeIntermediateInfos)
	{
		const Table& nestedClassTb = _rawImage->GetTable(TableType::NESTEDCLASS);
		for (uint32_t i = 0; i < nestedClassTb.rowNum; i++)
		{
			TbNestedClass data = _rawImage->ReadNestedClass(i + 1);
			SuperSetTypeIntermediateInfo& nestedType = typeIntermediateInfos[data.nestedClass - 1];
			nestedType.homoParentRowIndex = data.enclosingClass;
		}
	}

	void SuperSetAOTHomologousImage::InitType(std::vector<SuperSetTypeIntermediateInfo>& typeIntermediateInfos, SuperSetTypeIntermediateInfo& type)
	{
		if (type.inited)
		{
			return;
		}
		type.inited = true;
		uint32_t rowIndex = (uint32_t)(&type - &typeIntermediateInfos[0] + 1);
		TbTypeDef data = _rawImage->ReadTypeDef(rowIndex);

		type.homoMethodStartIndex = data.methodList;
		type.homoFieldStartIndex = data.fieldList;

		const char* name = _rawImage->GetStringFromRawIndex(data.typeName);
		const char* namespaze = _rawImage->GetStringFromRawIndex(data.typeNamespace);
		if (type.homoParentRowIndex)
		{
			SuperSetTypeIntermediateInfo& parent = typeIntermediateInfos[type.homoParentRowIndex - 1];
			InitType(typeIntermediateInfos, parent);
			const Il2CppTypeDefinition* parentTypeDef = parent.aotTypeDef;
			if (parentTypeDef == nullptr)
			{
				goto labelInitDefault;
			}

			void* iter = nullptr;
			for (const Il2CppTypeDefinition* nextTypeDef; (nextTypeDef = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetNestedTypes((Il2CppMetadataTypeHandle)parentTypeDef, &iter));)
			{
				const char* nestedTypeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(nextTypeDef->nameIndex);
				IL2CPP_ASSERT(nestedTypeName);
				if (!std::strcmp(name, nestedTypeName))
				{
					type.aotTypeDef = nextTypeDef;
					//type.aotTypeIndex = nextTypeDef->byvalTypeIndex;
					type.aotIl2CppType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(nextTypeDef->byvalTypeIndex);
					//type.aotKlass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)nextTypeDef);
					return;
				}
			}
		}
		else
		{
			const Il2CppTypeDefinition* aotTypeDef = (const Il2CppTypeDefinition*)il2cpp::vm::Image::TypeHandleFromName(_aotAssembly->image, namespaze, name);
			if (aotTypeDef)
			{
				type.aotTypeDef = aotTypeDef;
				type.aotIl2CppType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(aotTypeDef->byvalTypeIndex);
				//type.aotTypeIndex = type.aotTypeDef->byvalTypeIndex;
				return;
			}
		}
		labelInitDefault:
		type.aotIl2CppType = _defaultIl2CppType;
		//TEMP_FORMAT(msg, "type: %s::%s can't find homologous type in assembly:%s", type.namespaze, type.name, _aotAssembly->aname.name);
		//RaiseExecutionEngineException(msg);
	}

	void SuperSetAOTHomologousImage::InitTypes1(std::vector<SuperSetTypeIntermediateInfo>& typeIntermediateInfos)
	{
		for (SuperSetTypeIntermediateInfo& td : typeIntermediateInfos)
		{
			//uint32_t rowIndex = ++index;
			//TbTypeDef data = _rawImage->ReadTypeDef(rowIndex);

			//td.inited = false;
			//td.homoParentRowIndex = 0;
			//td.homoRowIndex = rowIndex;
			//td.homoMethodStartIndex = data.methodList;
			//td.homoFieldStartIndex = data.fieldList;

			//td.name = _rawImage->GetStringFromRawIndex(data.typeName);
			//td.namespaze = _rawImage->GetStringFromRawIndex(data.typeNamespace);
			InitType(typeIntermediateInfos, td);
		}

		uint32_t index = 0;
		for (SuperSetTypeIntermediateInfo& td : typeIntermediateInfos)
		{
			SuperSetTypeDefDetail& type = _typeDefs[index++];
			type.aotIl2CppType = td.aotIl2CppType;
			if (td.aotTypeDef)
			{
				_aotTypeIndex2TypeDefs[il2cpp::vm::GlobalMetadata::GetIndexForTypeDefinition(td.aotTypeDef)] = &type;
			}
		}
	}

	void SuperSetAOTHomologousImage::InitMethods(std::vector<SuperSetTypeIntermediateInfo>& typeIntermediateInfos)
	{
		const Table& methodTb = _rawImage->GetTable(TableType::METHOD);
		uint32_t methodCount = methodTb.rowNum;
		_methodDefs.resize(methodCount);
		//_token2MethodDefs.resize(methodCount * 2);
		uint32_t typeCount = (uint32_t)typeIntermediateInfos.size();
		for (SuperSetTypeIntermediateInfo& type : typeIntermediateInfos)
		{
			uint32_t nextTypeIndex = (uint32_t)(&type - &typeIntermediateInfos[0] + 1);
			uint32_t nextTypeMethodStartIndex = nextTypeIndex < typeCount ? typeIntermediateInfos[nextTypeIndex].homoMethodStartIndex : methodCount + 1;


			for (uint32_t i = type.homoMethodStartIndex; i < nextTypeMethodStartIndex ; i++)
			{
				SuperSetMethodDefDetail& method = _methodDefs[i - 1];
				TbMethod data = _rawImage->ReadMethod(i);
				//method.declaringTypeDef = type.aotTypeDef;
				//method.name = _rawImage->GetStringFromRawIndex(data.name);
				if (type.aotTypeDef == nullptr)
				{
					continue;
				}
				MethodRefSig signature = {};
				signature.flags = data.flags;
				BlobReader methodSigReader = _rawImage->GetBlobReaderByRawIndex(data.signature);
				ReadMethodDefSig(methodSigReader, signature);
				const char* methodName = _rawImage->GetStringFromRawIndex(data.name);
				method.aotMethodDef = FindMatchMethod(type.aotTypeDef, method, methodName, signature);
				if (method.aotMethodDef &&
					(type.aotTypeDef->genericContainerIndex != kGenericContainerIndexInvalid
						|| method.aotMethodDef->genericContainerIndex != kGenericContainerIndexInvalid))
				{
					_token2MethodDefs[method.aotMethodDef->token] = &method;
				}
			}
		}
	}

	void SuperSetAOTHomologousImage::ReadMethodDefSig(BlobReader& reader, MethodRefSig& method)
	{
		uint8_t rawSigFlags = reader.ReadByte();

		if (rawSigFlags & (uint8_t)MethodSigFlags::GENERIC)
		{
			//IL2CPP_ASSERT(false);
			method.genericParamCount = reader.ReadCompressedUint32();
			IL2CPP_ASSERT(method.genericParamCount > 0);
		}
		uint32_t paramCount = reader.ReadCompressedUint32();
		//IL2CPP_ASSERT(paramCount >= methodDef.parameterCount);

		method.returnType = ReadType(reader, nullptr, nullptr);

		int readParamNum = 0;
		for (; reader.NonEmpty(); )
		{
			const Il2CppType* paramType = ReadType(reader, nullptr, nullptr);
			method.params.push_back(paramType);
			++readParamNum;
		}
		IL2CPP_ASSERT(readParamNum == (int)paramCount);
	}

	void SuperSetAOTHomologousImage::InitFields(std::vector<SuperSetTypeIntermediateInfo>& typeIntermediateInfos)
	{
		const Table& fieldTb = _rawImage->GetTable(TableType::FIELD);
		uint32_t fieldCount = fieldTb.rowNum;
		_fields.resize(fieldTb.rowNum);

		uint32_t typeCount = (uint32_t)typeIntermediateInfos.size();
		for (SuperSetTypeIntermediateInfo& type : typeIntermediateInfos)
		{
			uint32_t nextTypeIndex = (uint32_t)(&type - &typeIntermediateInfos[0] + 1);
			uint32_t nextTypeFieldStartIndex = nextTypeIndex < typeCount ? typeIntermediateInfos[nextTypeIndex].homoFieldStartIndex : fieldCount + 1;
			for (uint32_t i = type.homoFieldStartIndex; i < nextTypeFieldStartIndex; i++)
			{
				SuperSetFieldDefDetail& field = _fields[i - 1];
				//field.homoRowIndex = i;
				TbField data = _rawImage->ReadField(i);
				//field.name = _rawImage->GetStringFromRawIndex(data.name);

				//field.declaringTypeDef = type.aotTypeDef;
				field.declaringIl2CppType = type.aotIl2CppType;
				if (type.aotTypeDef == nullptr)
				{
					continue;
				}

				BlobReader br = _rawImage->GetBlobReaderByRawIndex(data.signature);
				FieldRefSig frs;
				ReadFieldRefSig(br, nullptr, frs);
				if (data.flags)
				{
					Il2CppType* newType = MetadataPool::ShallowCloneIl2CppType(frs.type);
					newType->attrs = data.flags;
					frs.type = newType;
				}

				const char* fieldName = _rawImage->GetStringFromRawIndex(data.name);
				field.aotFieldDef = FindMatchField(type.aotTypeDef, field, fieldName, frs.type);
			}
		}
	}

	MethodBody* SuperSetAOTHomologousImage::GetMethodBody(uint32_t token)
	{
		auto it = _token2MethodDefs.find(token);
		if (it == _token2MethodDefs.end())
		{
			return nullptr;
		}
		SuperSetMethodDefDetail* method = it->second;
		uint32_t rowIndex = (uint32_t)(method - &_methodDefs[0] + 1);
		TbMethod methodData = _rawImage->ReadMethod(rowIndex);
		MethodBody* body = new (HYBRIDCLR_MALLOC_ZERO(sizeof(MethodBody))) MethodBody();
		ReadMethodBody(*method->aotMethodDef, methodData, *body);
		return body;
	}

	const Il2CppType* SuperSetAOTHomologousImage::GetIl2CppTypeFromRawTypeDefIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _typeDefs.size());
		return _typeDefs[index].aotIl2CppType;
	}

	Il2CppGenericContainer* SuperSetAOTHomologousImage::GetGenericContainerByRawIndex(uint32_t index)
	{
		return (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(index);
	}

	Il2CppGenericContainer* SuperSetAOTHomologousImage::GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex)
	{
		auto it = _aotTypeIndex2TypeDefs.find(typeDefIndex);
		if (it == _aotTypeIndex2TypeDefs.end())
		{
			return nullptr;
		}
		const Il2CppType* type = it->second->aotIl2CppType;
		if (type == nullptr)
		{
			return nullptr;
		}
		const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)(type->data.typeHandle);
		return (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(typeDef->genericContainerIndex);
	}

	const Il2CppMethodDefinition* SuperSetAOTHomologousImage::GetMethodDefinitionFromRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _methodDefs.size());
		SuperSetMethodDefDetail& method = _methodDefs[index];
		const Il2CppMethodDefinition* methodDef = method.aotMethodDef;
		if (!methodDef)
		{
			TEMP_FORMAT(errMsg, "method not exist. rowIndex:%d", index);
			RaiseExecutionEngineException(errMsg);
		}
		return methodDef;
	}

	void SuperSetAOTHomologousImage::ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret)
	{
		IL2CPP_ASSERT(rowIndex > 0);
		SuperSetFieldDefDetail& fd = _fields[rowIndex - 1];
		ret.containerType = fd.declaringIl2CppType;
		ret.field = fd.aotFieldDef;
	}

	const Il2CppType* SuperSetAOTHomologousImage::ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName)
	{
		TableType tokenType;
		uint32_t rawIndex;
		DecodeResolutionScopeCodedIndex(scope, tokenType, rawIndex);
		switch (tokenType)
		{
		case TableType::MODULE:
		{
			const Il2CppType* retType = GetModuleIl2CppType(rawIndex, typeNamespace, typeName, false);
			return retType ? retType : _defaultIl2CppType;
		}
		case TableType::MODULEREF:
		{
			RaiseNotSupportedException("Image::ReadTypeFromResolutionScope not support ResolutionScore.MODULEREF");
			return nullptr;
		}
		case TableType::ASSEMBLYREF:
		{
			const Il2CppType* refType = GetIl2CppType(rawIndex, typeNamespace, typeName, false);
			return refType ? refType : _defaultIl2CppType;
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
				//TEMP_FORMAT(errMsg, "Image::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF enclosingType:%s", name);
				//RaiseExecutionEngineException(errMsg);
				return _defaultIl2CppType;
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
			return _defaultIl2CppType;
		}
		default:
		{
			RaiseBadImageException("Image::ReadTypeFromResolutionScope invaild TableType");
			return nullptr;
		}
		}
	}
}
}

