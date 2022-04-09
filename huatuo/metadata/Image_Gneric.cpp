#include "Image.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "il2cpp-class-internals.h"
#include "vm/GlobalMetadata.h"
#include "vm/Type.h"
#include "vm/Field.h"
#include "vm/MetadataLock.h"
#include "vm/Class.h"
#include "metadata/FieldLayout.h"
#include "metadata/Il2CppTypeCompare.h"
#include "metadata/GenericMetadata.h"

#include "MetadataModule.h"
#include "Tables.h"
#include "MetadataParser.h"
#include "TableReader.h"

#include "../interpreter/InterpreterModule.h"

namespace huatuo
{
namespace metadata
{

	void Image::InitGenericParamConstraintDefs()
	{
		Table& tb = _tables[(int)TableType::GENERICPARAMCONSTRAINT];
		_genericConstraints.resize(tb.rowNum);
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			uint32_t rowIndex = i + 1;
			TbGenericParamConstraint data = TableReader::ReadGenericParamConstraint(*this, rowIndex);
			Il2CppGenericParameter& genericParam = _genericParams[data.owner - 1];

			if (genericParam.constraintsCount == 0)
			{
				genericParam.constraintsStart = i;
			}
			++genericParam.constraintsCount;

			Il2CppType paramCons = {};

			const Il2CppGenericContainer* klassGc;
			const Il2CppGenericContainer* methodGc;
			GetClassAndMethodGenericContainerFromGenericContainerIndex(*this, genericParam.ownerIndex, klassGc, methodGc);

			MetadataParser::ReadTypeFromToken(*this, klassGc, methodGc, DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.constraint), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.constraint), paramCons);
			_genericConstraints[i] = DecodeMetadataIndex(AddIl2CppTypeCache(paramCons));
		}
	}

	void Image::InitGenericParamDefs0()
	{
		Table& tb = _tables[(int)TableType::GENERICPARAM];
		_genericParams.resize(tb.rowNum);
	}

	void Image::InitGenericParamDefs()
	{
		Table& tb = _tables[(int)TableType::GENERICPARAM];
		for (uint32_t i = 0; i < tb.rowNum; i++)
		{
			uint32_t rowIndex = i + 1;
			TbGenericParam data = TableReader::ReadGenericParam(*this, rowIndex);
			Il2CppGenericParameter& paramDef = _genericParams[i];
			paramDef.num = data.number;
			paramDef.flags = data.flags;
			paramDef.nameIndex = data.name;
			// constraintsStart 和 constrantsCount init at InitGenericParamConstrains() latter

			TableType ownerType = DecodeTypeOrMethodDefCodedIndexTableType(data.owner);
			uint32_t ownerIndex = DecodeTypeOrMethodDefCodedIndexRowIndex(data.owner);
			IL2CPP_ASSERT(ownerIndex > 0);
			Il2CppGenericContainer* geneContainer;
			int32_t interIndex = ownerIndex - 1;
			if (ownerType == TableType::TYPEDEF)
			{
				Il2CppTypeDefinition& typeDef = _typesDefines[interIndex];
				if (typeDef.genericContainerIndex == kGenericContainerIndexInvalid)
				{
					Il2CppGenericContainer c = {};
					c.ownerIndex = EncodeWithIndex(interIndex);
					c.is_method = false;
					typeDef.genericContainerIndex = AddIl2CppGenericContainers(c);
				}
				geneContainer = &_genericContainers[DecodeMetadataIndex(typeDef.genericContainerIndex)];
				paramDef.ownerIndex = typeDef.genericContainerIndex;
			}
			else
			{
				Il2CppMethodDefinition& methodDef = _methodDefines[interIndex];
				if (methodDef.genericContainerIndex == kGenericContainerIndexInvalid)
				{
					Il2CppGenericContainer c = {};
					c.ownerIndex = EncodeWithIndex(interIndex);
					c.is_method = true;
					methodDef.genericContainerIndex = AddIl2CppGenericContainers(c);
				}
				geneContainer = &_genericContainers[DecodeMetadataIndex(methodDef.genericContainerIndex)];
				paramDef.ownerIndex = methodDef.genericContainerIndex;
			}
			if (geneContainer->type_argc == 0)
			{
				geneContainer->genericParameterStart = i;
			}
			++geneContainer->type_argc;
		}
	}


	void Image::InitInterfaces()
	{
		Table& table = _tables[(int)TableType::INTERFACEIMPL];

		// interface中只包含直接继承的interface,不包括来自父类的
		// 此interface只在CastClass及Type.GetInterfaces()反射函数中
		// 发挥作用，不在callvir中发挥作用。
		// interfaceOffsets中包含了水平展开的所有interface(包括父类的)
		_interfaceDefines.resize(table.rowNum);
		uint32_t lastClassIdx = 0;
		for (uint32_t i = 0; i < table.rowNum; i++)
		{
			uint32_t rowIndex = i + 1;
			TbInterfaceImpl data = TableReader::ReadInterfaceImpl(*this, rowIndex);

			Il2CppTypeDefinition& typeDef = _typesDefines[data.classIdx - 1];
			Il2CppType intType = {};
			MetadataParser::ReadTypeFromToken(*this, GetGenericContainerByTypeDefinition(&typeDef), nullptr,
				DecodeTypeDefOrRefOrSpecCodedIndexTableType(data.interfaceIdx), DecodeTypeDefOrRefOrSpecCodedIndexRowIndex(data.interfaceIdx), intType);
			_interfaceDefines[i] = DecodeMetadataIndex(AddIl2CppTypeCache(intType));
			if (typeDef.interfaces_count == 0)
			{
				typeDef.interfacesStart = (InterfacesIndex)i;
			}
			else
			{
				// 必须连续
				IL2CPP_ASSERT(data.classIdx == lastClassIdx);
			}
			++typeDef.interfaces_count;
			lastClassIdx = data.classIdx;
		}
	}



	void Image::InitVtables()
	{
		Table& typeDefTb = _tables[(int)TableType::TYPEDEF];

		Il2CppType2TypeDeclaringTreeMap cacheTrees;

		for (TypeDefinitionDetail& td : _typeDetails)
		{
			Il2CppTypeDefinition& typeDef = *td.typeDef;
			const Il2CppType* type = GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(typeDef.byvalTypeIndex));
			VTableSetUp* typeTree = VTableSetUp::BuildByType(cacheTrees, type);

			if (IsInterface(typeDef.flags))
			{
				typeDef.interfaceOffsetsStart = EncodeWithIndex(0);
				typeDef.interface_offsets_count = 0;
				typeDef.vtableStart = EncodeWithIndex(0);
				typeDef.vtable_count = 0;
				continue;
			}

			uint32_t offsetsStart = (uint32_t)_interfaceOffsets.size();

			auto& vms = typeTree->GetVirtualMethodImpls();
			IL2CPP_ASSERT(td.vtable.empty());
			td.vtable = vms;

			auto& interfaceOffsetInfos = typeTree->GetInterfaceOffsetInfos();
			for (auto ioi : interfaceOffsetInfos)
			{
				_interfaceOffsets.push_back({ ioi.type, ioi.offset });
			}

			typeDef.vtableStart = EncodeWithIndex(0);
			typeDef.interfaceOffsetsStart = EncodeWithIndex(offsetsStart);
			typeDef.vtable_count = (uint16_t)td.vtable.size();
			typeDef.interface_offsets_count = (uint32_t)interfaceOffsetInfos.size();
		}
		for (auto& e : cacheTrees)
		{
			e.second->~VTableSetUp();
			IL2CPP_FREE(e.second);
		}
	}


	uint32_t Image::GetFieldOffset(const Il2CppClass* klass, int32_t fieldIndexInType, FieldInfo* field)
	{
		Il2CppTypeDefinition* typeDef = (Il2CppTypeDefinition*)(klass->typeMetadataHandle);
		uint32_t fieldActualIndex = DecodeMetadataIndex(typeDef->fieldStart) + fieldIndexInType;
		IL2CPP_ASSERT(fieldActualIndex < (uint32_t)_fieldDetails.size());
		return _fieldDetails[fieldActualIndex].offset;
	}

	// index => MethodDefinition -> DeclaringClass -> index - klass->methodStart -> MethodInfo*
	const MethodInfo* Image::GetMethodInfoFromMethodDefinitionRawIndex(uint32_t index)
	{
		IL2CPP_ASSERT((size_t)index <= _methodDefine2InfoCaches.size());
		if (_methodDefine2InfoCaches[index])
		{
			return _methodDefine2InfoCaches[index];
		}
		const Il2CppMethodDefinition* methodDefinition = GetMethodDefinitionFromRawIndex(index);
		const Il2CppType* type = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(methodDefinition->declaringType);
		//Il2CppClass* typeInfo = GetTypeInfoFromTypeDefinitionRawIndex(DecodeMetadataIndex());

		IL2CPP_ASSERT(type->type == IL2CPP_TYPE_VALUETYPE || type->type == IL2CPP_TYPE_CLASS);
		const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(type->data.typeHandle);
		int32_t indexInClass = index - DecodeMetadataIndex(typeDefinition->methodStart);
		IL2CPP_ASSERT(indexInClass >= 0 && indexInClass < typeDefinition->method_count);
		Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
		il2cpp::vm::Class::SetupMethods(klass);
		// il2cpp::vm::Class::Init(klass);
		return _methodDefine2InfoCaches[index] = klass->methods[indexInClass];
	}

	const MethodInfo* Image::GetMethodInfoFromMethodDefinition(const Il2CppMethodDefinition* methodDef)
	{
		uint32_t rawIndex = (uint32_t)(methodDef - &_methodDefines[0]);
		IL2CPP_ASSERT(rawIndex < (uint32_t)_methodDefines.size());
		return GetMethodInfoFromMethodDefinitionRawIndex(rawIndex);
	}

	// typeDef vTableSlot -> type virtual method index -> MethodDefinition*
	const Il2CppMethodDefinition* Image::GetMethodDefinitionFromVTableSlot(const Il2CppTypeDefinition* typeDef, int32_t vTableSlot)
	{
		uint32_t typeDefIndex = GetTypeRawIndex(typeDef);
		IL2CPP_ASSERT(typeDefIndex < (uint32_t)_typeDetails.size());
		TypeDefinitionDetail& td = _typeDetails[typeDefIndex];

		IL2CPP_ASSERT(vTableSlot >= 0 && vTableSlot < (int32_t)td.vtable.size());
		VirtualMethodImpl& vmi = td.vtable[vTableSlot];
		return vmi.method;
	}

	const MethodInfo* Image::GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot)
	{
		IL2CPP_ASSERT(!klass->generic_class);
		const Il2CppTypeDefinition* typeDef = (Il2CppTypeDefinition*)klass->typeMetadataHandle;
		//const Il2CppMethodDefinition* methodDef = GetMethodDefinitionFromVTableSlot((Il2CppTypeDefinition*)klass->typeMetadataHandle, vTableSlot);
		// FIX ME. why return null?
		//IL2CPP_ASSERT(methodDef);

		uint32_t typeDefIndex = GetTypeRawIndex(typeDef);
		IL2CPP_ASSERT(typeDefIndex < (uint32_t)_typeDetails.size());
		TypeDefinitionDetail& td = _typeDetails[typeDefIndex];

		IL2CPP_ASSERT(vTableSlot >= 0 && vTableSlot < (int32_t)td.vtable.size());
		VirtualMethodImpl& vmi = td.vtable[vTableSlot];
		if (vmi.method)
		{
			if (DecodeMetadataIndex(vmi.method->declaringType) == typeDefIndex)
			{
				return il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle((Il2CppMetadataMethodDefinitionHandle)vmi.method);
			}
			else
			{
				Il2CppClass* implClass = il2cpp::vm::Class::FromIl2CppType(vmi.type);
				IL2CPP_ASSERT(implClass != klass);
				il2cpp::vm::Class::SetupMethods(implClass);
				for (uint32_t i = 0; i < implClass->method_count; i++)
				{
					const MethodInfo* implMethod = implClass->methods[i];
					if (implMethod->token == vmi.method->token)
					{
						return implMethod;
					}
				}
				RaiseHuatuoExecutionEngineException("not find vtable method");
			}
		}
		return nullptr;
	}

	Il2CppMethodPointer Image::GetAdjustorThunk(uint32_t token)
	{
		uint32_t methodIndex = DecodeTokenRowIndex(token) - 1;
		IL2CPP_ASSERT(methodIndex < (uint32_t)_methodDefines.size());
		const Il2CppMethodDefinition* methodDef = &_methodDefines[methodIndex];
		return huatuo::interpreter::InterpreterModule::GetAdjustThunkMethodPointer(methodDef);
	}

	Il2CppMethodPointer Image::GetMethodPointer(uint32_t token)
	{
		uint32_t methodIndex = DecodeTokenRowIndex(token) - 1;
		IL2CPP_ASSERT(methodIndex < (uint32_t)_methodDefines.size());
		const Il2CppMethodDefinition* methodDef = &_methodDefines[methodIndex];
		return huatuo::interpreter::InterpreterModule::GetMethodPointer(methodDef);
	}

	InvokerMethod Image::GetMethodInvoker(uint32_t token)
	{
		uint32_t methodIndex = DecodeTokenRowIndex(token) - 1;
		IL2CPP_ASSERT(methodIndex < (uint32_t)_methodDefines.size());
		const Il2CppMethodDefinition* methodDef = &_methodDefines[methodIndex];
		return huatuo::interpreter::InterpreterModule::GetMethodInvoker(methodDef);
	}

}
}