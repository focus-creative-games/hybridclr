#include "SuperSetAOTHomologousImage.h"

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

	void SuperSetAOTHomologousImage::InitRuntimeMetadatas()
	{
		_defaultIl2CppType = il2cpp_defaults.missing_class->byval_arg;

		InitTypes0();
		InitNestedClass();
		InitTypes1();
		InitMethods();
		InitFields();
	}

	void SuperSetAOTHomologousImage::InitTypes0()
	{
		const Table& typeDefTb = _rawImage.GetTable(TableType::TYPEDEF);
		uint32_t typeCount = typeDefTb.rowNum;
		_typeDefs.resize(typeCount);
		_aotTypeIndex2TypeDefs.reserve(typeCount);

		Il2CppImage* image = _aotAssembly->image;
		for (uint32_t index = 0; index < typeCount; index++)
		{
			SuperSetTypeDefDetail& td = _typeDefs[index];
			uint32_t rowIndex = index + 1;
			TbTypeDef data = _rawImage.ReadTypeDef(rowIndex);
			
			td.inited = false;
			td.homoParentRowIndex = 0;
			td.homoRowIndex = rowIndex;
			td.homoMethodStartIndex = data.methodList;
			td.homoFieldStartIndex = data.fieldList;
			
			td.name = _rawImage.GetStringFromRawIndex(data.typeName);
			td.namespaze = _rawImage.GetStringFromRawIndex(data.typeNamespace);
			td.aotTypeIndex = kInvalidIndex;
			td.aotIl2CppType = nullptr;
			td.aotTypeDef = nullptr;
		}
	}

	void SuperSetAOTHomologousImage::InitNestedClass()
	{
		const Table& nestedClassTb = _rawImage.GetTable(TableType::NESTEDCLASS);
		for (uint32_t i = 0; i < nestedClassTb.rowNum; i++)
		{
			TbNestedClass data = _rawImage.ReadNestedClass(i + 1);
			SuperSetTypeDefDetail& nestedType = _typeDefs[data.nestedClass - 1];
			nestedType.homoParentRowIndex = data.enclosingClass;
		}
	}

	void SuperSetAOTHomologousImage::InitType(SuperSetTypeDefDetail& type)
	{
		if (type.inited)
		{
			return;
		}
		type.inited = true;
		if (type.homoParentRowIndex)
		{
			SuperSetTypeDefDetail& parent = _typeDefs[type.homoParentRowIndex - 1];
			InitType(parent);
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
				if (!std::strcmp(type.name, nestedTypeName))
				{
					type.aotTypeDef = nextTypeDef;
					type.aotTypeIndex = nextTypeDef->byvalTypeIndex;
					type.aotIl2CppType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(nextTypeDef->byvalTypeIndex);
					type.aotKlass = il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle((Il2CppMetadataTypeHandle)nextTypeDef);
					_aotTypeIndex2TypeDefs[il2cpp::vm::GlobalMetadata::GetIndexForTypeDefinition(type.aotKlass)] = &type;
					return;
				}
			}
		}
		else
		{
			Il2CppClass* klass = il2cpp::vm::Image::ClassFromName(_aotAssembly->image, type.namespaze, type.name);
			if (klass)
			{
				type.aotTypeDef = (const Il2CppTypeDefinition*)klass->typeMetadataHandle;
				type.aotIl2CppType = &klass->byval_arg;
				type.aotTypeIndex = type.aotTypeDef->byvalTypeIndex;
				type.aotKlass = klass;
				_aotTypeIndex2TypeDefs[il2cpp::vm::GlobalMetadata::GetIndexForTypeDefinition(type.aotKlass)] = &type;
				return;
			}
		}
		labelInitDefault:
		type.aotIl2CppType = &_defaultIl2CppType;
		//TEMP_FORMAT(msg, "type: %s::%s can't find homologous type in assembly:%s", type.namespaze, type.name, _aotAssembly->aname.name);
		//RaiseExecutionEngineException(msg);
	}

	void SuperSetAOTHomologousImage::InitTypes1()
	{
		for (SuperSetTypeDefDetail& td : _typeDefs)
		{
			InitType(td);
		}
	}

	static const Il2CppMethodDefinition* FindMatchMethod(const Il2CppClass* klass1, const SuperSetMethodDefDetail& method2)
	{
		il2cpp::vm::Class::SetupMethods(const_cast<Il2CppClass*>(klass1));
		const Il2CppGenericContainer* klassGenContainer = klass1->is_generic ? GetGenericContainerFromIl2CppType(&klass1->byval_arg) : nullptr;
		for (uint16_t i = 0; i < klass1->method_count; i++)
		{
			const MethodInfo* method1 = klass1->methods[i];
			if (std::strcmp(method1->name, method2.name))
			{
				continue;
			}
			if (IsMatchMethodSig(method1, method2.signature, klassGenContainer))
			{
				return (const Il2CppMethodDefinition*)method1->methodMetadataHandle;
			}
		}
		return nullptr;
	}

	void SuperSetAOTHomologousImage::InitMethods()
	{
		const Table& methodTb = _rawImage.GetTable(TableType::METHOD);
		uint32_t methodCount = methodTb.rowNum;
		_methodDefs.resize(methodCount);
		_token2MethodDefs.reserve(methodCount * 2);
		uint32_t typeCount = (uint32_t)_typeDefs.size();
		for (SuperSetTypeDefDetail& type : _typeDefs)
		{
			uint32_t nextTypeMethodStartIndex = type.homoRowIndex < typeCount ? _typeDefs[type.homoRowIndex].homoMethodStartIndex : methodCount + 1;


			for (uint32_t i = type.homoMethodStartIndex; i < nextTypeMethodStartIndex ; i++)
			{
				SuperSetMethodDefDetail& method = _methodDefs[i - 1];
				method.homoRowIndex = i;
				TbMethod data = _rawImage.ReadMethod(i);
				method.declaringTypeDef = type.aotTypeDef;
				method.name = _rawImage.GetStringFromRawIndex(data.name);
				if (type.aotTypeDef == nullptr)
				{
					continue;
				}
				method.signature.flags = data.flags;
				BlobReader methodSigReader = _rawImage.GetBlobReaderByRawIndex(data.signature);
				ReadMethodDefSig(methodSigReader, method.signature);
				method.aotMethodDef = FindMatchMethod(type.aotKlass, method);
				if (method.aotMethodDef)
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

		method.returnType = {};
		ReadType(reader, nullptr, nullptr, method.returnType);

		int readParamNum = 0;
		for (; reader.NonEmpty(); )
		{
			Il2CppType paramType = {};
			ReadType(reader, nullptr, nullptr, paramType);
			method.params.push_back(paramType);
			++readParamNum;
		}
		IL2CPP_ASSERT(readParamNum == (int)paramCount);
	}


	const Il2CppFieldDefinition* FindMatchField(const Il2CppClass* klass1, const SuperSetFieldDefDetail& field2)
	{
		il2cpp::vm::Class::SetupFields(const_cast<Il2CppClass*>(klass1));
		const Il2CppGenericContainer* klassGenContainer = klass1->is_generic ? GetGenericContainerFromIl2CppType(&klass1->byval_arg) : nullptr;
		for (uint16_t i = 0; i < klass1->field_count; i++)
		{
			const FieldInfo* field1 = klass1->fields + i;
			if (std::strcmp(field1->name, field2.name))
			{
				continue;
			}
			if (IsMatchSigType(field1->type, &field2.type, klassGenContainer, nullptr))
			{
				return il2cpp::vm::GlobalMetadata::GetFieldDefinitionFromTypeDefAndFieldIndex((const Il2CppTypeDefinition*)klass1->typeMetadataHandle, i);
			}
		}
		return nullptr;
	}

	void SuperSetAOTHomologousImage::InitFields()
	{
		const Table& fieldTb = _rawImage.GetTable(TableType::FIELD);
		uint32_t fieldCount = fieldTb.rowNum;
		_fields.resize(fieldTb.rowNum);

		uint32_t typeCount = (uint32_t)_typeDefs.size();
		for (SuperSetTypeDefDetail& type : _typeDefs)
		{
			uint32_t nextTypeFieldStartIndex = type.homoRowIndex < typeCount ? _typeDefs[type.homoRowIndex].homoFieldStartIndex : fieldCount + 1;
			for (uint32_t i = type.homoFieldStartIndex; i < nextTypeFieldStartIndex; i++)
			{
				SuperSetFieldDefDetail& field = _fields[i - 1];
				field.homoRowIndex = i;
				TbField data = _rawImage.ReadField(i);
				field.name = _rawImage.GetStringFromRawIndex(data.name);

				field.declaringTypeDef = type.aotTypeDef;
				field.declaringIl2CppType = type.aotIl2CppType;
				if (type.aotTypeDef == nullptr)
				{
					continue;
				}

				BlobReader br = _rawImage.GetBlobReaderByRawIndex(data.signature);
				FieldRefSig frs;
				ReadFieldRefSig(br, nullptr, frs);
				frs.type.attrs = data.flags;
				field.type = frs.type;

				field.aotFieldDef = FindMatchField(type.aotKlass, field);
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
		if (!method->body)
		{
			uint32_t rowIndex = method->homoRowIndex;
			TbMethod methodData = _rawImage.ReadMethod(rowIndex);
			MethodBody* body = new (IL2CPP_MALLOC_ZERO(sizeof(MethodBody))) MethodBody();
			ReadMethodBody(*method->aotMethodDef, methodData, *body);
			method->body = body;
		}
		return method->body;
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
		const Il2CppTypeDefinition* type = it->second->aotTypeDef;
		if (type == nullptr)
		{
			return nullptr;
		}
		return (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(type->genericContainerIndex);
	}

	const Il2CppMethodDefinition* SuperSetAOTHomologousImage::GetMethodDefinitionFromRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index < _methodDefs.size());
		SuperSetMethodDefDetail& method = _methodDefs[index];
		const Il2CppMethodDefinition* methodDef = method.aotMethodDef;
		if (!methodDef)
		{
			TEMP_FORMAT(errMsg, "method:%s rowIndex:%d not exist", method.name, method.homoRowIndex);
			RaiseExecutionEngineException("find");
		}
		return methodDef;
	}

	void SuperSetAOTHomologousImage::ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret)
	{
		IL2CPP_ASSERT(rowIndex > 0);
		SuperSetFieldDefDetail& fd = _fields[rowIndex - 1];
		ret.containerType = *fd.declaringIl2CppType;
		ret.field = fd.aotFieldDef;
	}

	void SuperSetAOTHomologousImage::ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName, Il2CppType& type)
	{
		TableType tokenType;
		uint32_t rawIndex;
		DecodeResolutionScopeCodedIndex(scope, tokenType, rawIndex);
		switch (tokenType)
		{
		case TableType::MODULE:
		{
			if (!GetModuleIl2CppType(type, rawIndex, typeNamespace, typeName, false))
			{
				type = _defaultIl2CppType;
			}
			break;
		}
		case TableType::MODULEREF:
		{
			RaiseNotSupportedException("Image::ReadTypeFromResolutionScope not support ResolutionScore.MODULEREF");
			break;
		}
		case TableType::ASSEMBLYREF:
		{
			TbAssemblyRef assRef = _rawImage.ReadAssemblyRef(rawIndex);
			const Il2CppType* refType = GetIl2CppType(rawIndex, typeNamespace, typeName, false);
			if (refType)
			{
				type.type = refType->type;
				type.data = refType->data;
			}
			else
			{
				type = _defaultIl2CppType;
			}
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
				//TEMP_FORMAT(errMsg, "Image::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF enclosingType:%s", name);
				//RaiseExecutionEngineException(errMsg);
				type = _defaultIl2CppType;
				break;
			}
			bool find = false;
			for (const Il2CppTypeDefinition* nextTypeDef; (nextTypeDef = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetNestedTypes(enclosingTypeDef, &iter));)
			{
				const char* nestedTypeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(nextTypeDef->nameIndex);
				IL2CPP_ASSERT(nestedTypeName);
				if (!std::strcmp(name, nestedTypeName))
				{
					GetIl2CppTypeFromTypeDefinition(nextTypeDef, type);
					find = true;
					break;
				}
			}
			if (!find)
			{
				//std::string enclosingTypeName = GetKlassCStringFullName(&enClosingType);
				//TEMP_FORMAT(errMsg, "Image::ReadTypeFromResolutionScope ReadTypeFromResolutionScope.TYPEREF fail. type:%s.%s", enclosingTypeName.c_str(), name);
				//RaiseExecutionEngineException(errMsg);
				type = _defaultIl2CppType;
				break;
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
}
}

