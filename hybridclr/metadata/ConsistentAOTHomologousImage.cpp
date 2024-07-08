#include "ConsistentAOTHomologousImage.h"

#include "vm/MetadataLock.h"
#include "vm/GlobalMetadata.h"
#include "vm/Class.h"
#include "vm/Image.h"
#include "vm/Exception.h"
#include "vm/MetadataCache.h"
#include "metadata/GenericMetadata.h"

namespace hybridclr
{
namespace metadata
{

	void ConsistentAOTHomologousImage::InitRuntimeMetadatas()
	{
		InitTypes();
		InitMethods();
		InitFields();
	}

	void ConsistentAOTHomologousImage::InitTypes()
	{
		const Table& typeDefTb = _rawImage->GetTable(TableType::TYPEDEF);
		uint32_t typeCount = typeDefTb.rowNum;
		_il2cppTypeForTypeDefs.resize(typeCount);
		_typeDefs.resize(typeCount);

		Il2CppImage* image = _aotAssembly->image;
		//if (image->typeCount != typeCount)
		//{
		//	RaiseExecutionEngineException("image metadata not match");
		//}
		for (uint32_t index = 0; index < image->typeCount; index++)
		{
			Il2CppTypeDefinition* typeDef = (Il2CppTypeDefinition*)il2cpp::vm::MetadataCache::GetAssemblyTypeHandle(image, index);
			uint32_t rowIndex = DecodeTokenRowIndex(typeDef->token);
			IL2CPP_ASSERT(rowIndex > 0);
			if (rowIndex > typeCount)
			{
				continue;
			}
			TbTypeDef data = _rawImage->ReadTypeDef(rowIndex);
			uint32_t typeIndex = rowIndex - 1;
			_typeDefs[typeIndex] = typeDef;
			const Il2CppType* il2cppType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->byvalTypeIndex);
			_il2cppTypeForTypeDefs[typeIndex] = il2cppType;

			const char* name1 = _rawImage->GetStringFromRawIndex(data.typeName);
			const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
			if (std::strcmp(name1, name2))
			{
				RaiseExecutionEngineException("metadata type not match");
			}
			const char* namespaze1 = _rawImage->GetStringFromRawIndex(data.typeNamespace);
			const char* namespaze2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
			if (std::strcmp(namespaze1, namespaze2))
			{
				RaiseExecutionEngineException("metadata type not match");
			}
		}
	}

	void ConsistentAOTHomologousImage::InitMethods()
	{
		const Table& methodTb = _rawImage->GetTable(TableType::METHOD);
		_methodDefs.resize(methodTb.rowNum);

		for (Il2CppTypeDefinition* type : _typeDefs)
		{
			for (uint16_t i = 0; i < type->method_count; i++)
			{
				const Il2CppMethodDefinition* methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(type->methodStart + i);
				uint32_t rowIndex = DecodeTokenRowIndex(methodDef->token);
				IL2CPP_ASSERT(rowIndex > 0 && rowIndex <= methodTb.rowNum);
				uint32_t methodIndex = rowIndex - 1;
				IL2CPP_ASSERT(_methodDefs[methodIndex] == nullptr);
				_methodDefs[methodIndex] = methodDef;

				TbMethod methodData = _rawImage->ReadMethod(rowIndex);
				const char* name1 = _rawImage->GetStringFromRawIndex(methodData.name);
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex);
				if (std::strcmp(name1, name2))
				{
					RaiseExecutionEngineException("metadata method not match");
				}
			}
		}
	}

	void ConsistentAOTHomologousImage::InitFields()
	{
		const Table& fieldTb = _rawImage->GetTable(TableType::FIELD);
		_fields.resize(fieldTb.rowNum);

		for (size_t i = 0; i < _typeDefs.size(); i++)
		{
			Il2CppTypeDefinition* type = _typeDefs[i];
			for (uint16_t j = 0; j < type->field_count; j++)
			{
				const Il2CppFieldDefinition* fieldDef = il2cpp::vm::GlobalMetadata::GetFieldDefinitionFromTypeDefAndFieldIndex(type, j);
				uint32_t rowIndex = DecodeTokenRowIndex(fieldDef->token);
				IL2CPP_ASSERT(rowIndex > 0);
				uint32_t fieldIndex = rowIndex - 1;
				IL2CPP_ASSERT(_fields[fieldIndex].fieldDef == nullptr);
				if (rowIndex >= fieldTb.rowNum)
				{
					continue;
				}
				_fields[fieldIndex] = { (uint32_t)i, fieldDef };

				TbField fieldData = _rawImage->ReadField(rowIndex);
				const char* name1 = _rawImage->GetStringFromRawIndex(fieldData.name);
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(fieldDef->nameIndex);
				if (std::strcmp(name1, name2))
				{
					RaiseExecutionEngineException("metadata field not match");
				}
			}
		}
	}

	MethodBody* ConsistentAOTHomologousImage::GetMethodBody(uint32_t token, MethodBody& tempMethodBody)
	{
		auto it = _token2MethodBodies.find(token);
		if (it != _token2MethodBodies.end())
		{
			return it->second;
		}
		uint32_t rowIndex = DecodeTokenRowIndex(token);
		IL2CPP_ASSERT(rowIndex > 0);
		TbMethod methodData = _rawImage->ReadMethod(rowIndex);
		MethodBody* body = new (HYBRIDCLR_METADATA_MALLOC(sizeof(MethodBody))) MethodBody();
		ReadMethodBody(*_methodDefs[rowIndex - 1], methodData, *body);
		_token2MethodBodies.insert({ token, body });
		return body;
	}

	const Il2CppType* ConsistentAOTHomologousImage::GetIl2CppTypeFromRawTypeDefIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _il2cppTypeForTypeDefs.size());
		return _il2cppTypeForTypeDefs[index];
	}

	Il2CppGenericContainer* ConsistentAOTHomologousImage::GetGenericContainerByRawIndex(uint32_t index)
	{
		return (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(index);
	}

	Il2CppGenericContainer* ConsistentAOTHomologousImage::GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex)
	{
		Il2CppTypeDefinition* type = (Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(typeDefIndex);
		return (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(type->genericContainerIndex);
	}

	const Il2CppMethodDefinition* ConsistentAOTHomologousImage::GetMethodDefinitionFromRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _methodDefs.size());
		return _methodDefs[index];
	}

	void ConsistentAOTHomologousImage::ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret)
	{
		IL2CPP_ASSERT(rowIndex > 0);
		AOTFieldData& fd = _fields[rowIndex - 1];
		ret.containerType = _il2cppTypeForTypeDefs[fd.typeDefIndex];
		ret.field = fd.fieldDef;
	}
}
}

