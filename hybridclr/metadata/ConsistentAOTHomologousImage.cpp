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

		Il2CppImage* image = _targetAssembly->image;
		//if (image->typeCount != typeCount)
		//{
		//	RaiseExecutionEngineException("image metadata not match");
		//}
		for (uint32_t index = 0; index < image->typeCount; index++)
		{
			Il2CppMetadataTypeHandle typeHandle = il2cpp::vm::MetadataCache::GetAssemblyTypeHandle(image, index);
            const Il2CppTypeDefinition typeDef = il2cpp::vm::GlobalMetadata::GetTypeDefinitionFromTypeHandle(typeHandle);
			uint32_t rowIndex = DecodeTokenRowIndex(typeDef.token);
			IL2CPP_ASSERT(rowIndex > 0);
			if (rowIndex > typeCount)
			{
				continue;
			}
			TbTypeDef data = _rawImage->ReadTypeDef(rowIndex);
			uint32_t typeIndex = rowIndex - 1;
			_typeDefs[typeIndex] = typeHandle;
			const Il2CppType* il2cppType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef.byvalTypeIndex);
			_il2cppTypeForTypeDefs[typeIndex] = il2cppType;

			const char* name1 = _rawImage->GetStringFromRawIndex(data.typeName);
			const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef.nameIndex);
			if (std::strcmp(name1, name2))
			{
				RaiseExecutionEngineException("metadata type not match");
			}
			const char* namespaze1 = _rawImage->GetStringFromRawIndex(data.typeNamespace);
			const char* namespaze2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef.namespaceIndex);
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

		for (Il2CppMetadataTypeHandle typeHandle : _typeDefs)
		{
            const Il2CppTypeDefinition typeDef = il2cpp::vm::GlobalMetadata::GetTypeDefinitionFromTypeHandle(typeHandle);
			for (uint16_t i = 0; i < typeDef.method_count; i++)
			{
                MethodIndex encodeMethodIndex = typeDef.methodStart + i;
				const Il2CppMethodDefinition methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionDataFromIndex(encodeMethodIndex);
				uint32_t rowIndex = DecodeTokenRowIndex(methodDef.token);
				IL2CPP_ASSERT(rowIndex > 0 && rowIndex <= methodTb.rowNum);
				uint32_t methodRidZeroBase = rowIndex - 1;
				IL2CPP_ASSERT(_methodDefs[methodRidZeroBase] == nullptr);
				_methodDefs[methodRidZeroBase] = il2cpp::vm::GlobalMetadata::GetMethodHandleFromIndex(encodeMethodIndex);

				TbMethod methodData = _rawImage->ReadMethod(rowIndex);
				const char* name1 = _rawImage->GetStringFromRawIndex(methodData.name);
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef.nameIndex);
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
		_fields.resize(fieldTb.rowNum, {0, kFieldIndexInvalid});

		Il2CppImage* image = _targetAssembly->image;
		for (size_t i = 0; i < _typeDefs.size(); i++)
		{
			Il2CppMetadataTypeHandle typeHandle = _typeDefs[i];
            const Il2CppTypeDefinition typeDef = il2cpp::vm::GlobalMetadata::GetTypeDefinitionFromTypeHandle(typeHandle);
			for (uint16_t j = 0; j < typeDef.field_count; j++)
			{
                FieldIndex fieldIndex = typeDef.fieldStart + j;
				const Il2CppFieldDefinition fieldDef = il2cpp::vm::GlobalMetadata::GetFieldDefinitionFromIndex(image, fieldIndex);
				uint32_t rowIndex = DecodeTokenRowIndex(fieldDef.token);
				IL2CPP_ASSERT(rowIndex > 0);
				uint32_t fieldRidZeroBased = rowIndex - 1;
				IL2CPP_ASSERT(_fields[fieldRidZeroBased].fieldIndex == kFieldIndexInvalid);
				if (rowIndex >= fieldTb.rowNum)
				{
					continue;
				}
				_fields[fieldRidZeroBased] = { (uint32_t)i, fieldIndex };

				TbField fieldData = _rawImage->ReadField(rowIndex);
				const char* name1 = _rawImage->GetStringFromRawIndex(fieldData.name);
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(fieldDef.nameIndex);
				if (std::strcmp(name1, name2))
				{
					RaiseExecutionEngineException("metadata field not match");
				}
			}
		}
	}

	MethodBody* ConsistentAOTHomologousImage::GetMethodBody(uint32_t token)
	{
		uint32_t rowIndex = DecodeTokenRowIndex(token);
		IL2CPP_ASSERT(rowIndex > 0);
		TbMethod methodData = _rawImage->ReadMethod(rowIndex);
		MethodBody* body = new (HYBRIDCLR_MALLOC_ZERO(sizeof(MethodBody))) MethodBody();
        const Il2CppMethodDefinition methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromHandle(_methodDefs[rowIndex - 1]);
		ReadMethodBody(methodDef, methodData, *body);
		return body;
	}

	const Il2CppType* ConsistentAOTHomologousImage::GetIl2CppTypeFromRawTypeDefIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _il2cppTypeForTypeDefs.size());
		return _il2cppTypeForTypeDefs[index];
	}

	Il2CppGenericContainer* ConsistentAOTHomologousImage::GetGenericContainerByRawIndex(uint32_t index)
	{
		return const_cast<Il2CppGenericContainer*>(il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(index));
	}

	Il2CppGenericContainer* ConsistentAOTHomologousImage::GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex)
	{
		Il2CppMetadataTypeHandle typeHandle = il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(typeDefIndex);
		const Il2CppTypeDefinition typeDef = il2cpp::vm::GlobalMetadata::GetTypeDefinitionFromTypeHandle(typeHandle);
		return const_cast<Il2CppGenericContainer*>(il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(typeDef.genericContainerIndex));
	}

	const Il2CppMetadataMethodDefinitionHandle ConsistentAOTHomologousImage::GetMethodHandleFromRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _methodDefs.size());
		return _methodDefs[index];
	}

	void ConsistentAOTHomologousImage::ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret)
	{
		IL2CPP_ASSERT(rowIndex > 0);
		AOTFieldData& fd = _fields[rowIndex - 1];
		ret.containerType = _il2cppTypeForTypeDefs[fd.typeDefIndex];
		ret.fieldIndex = fd.fieldIndex;
	}
}
}

