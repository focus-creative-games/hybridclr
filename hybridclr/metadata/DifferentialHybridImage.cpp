#include "DifferentialHybridImage.h"

#include "vm/Image.h"

#include "MetadataModule.h"

namespace hybridclr
{
namespace metadata
{


	void DifferentialHybridImage::BuildIl2CppImage(Il2CppImage* image, Il2CppAssembly* originAssembly)
	{
		InterpreterImage::BuildIl2CppImage(image);
		image->assembly->originAssembly = originAssembly;
		_originAssembly = originAssembly;
		_originImage = originAssembly->image;
	}

	void DifferentialHybridImage::InitTypeMapping(TypeMapping& type)
	{
		if (type.inited)
		{
			return;
		}
		type.inited = true;
		if (type.interpType->declaringTypeIndex != kTypeDefinitionIndexInvalid)
		{
			const Il2CppTypeDefinition* declaringTypeDef = (const Il2CppTypeDefinition*)GetIl2CppTypeFromRawIndex(DecodeMetadataIndex(type.interpType->declaringTypeIndex))->data.typeHandle;
			uint32_t declaringTypeIndex = GetTypeRawIndex(declaringTypeDef);
			TypeMapping& declaringTm = _typeMappings[declaringTypeIndex];
			InitTypeMapping(declaringTm);
			if (declaringTm.aotType == nullptr)
			{
				return;
			}
			void* iter = nullptr;
			for (const Il2CppTypeDefinition* nextTypeDef; (nextTypeDef = (const Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetNestedTypes((Il2CppMetadataTypeHandle)declaringTm.aotType, &iter));)
			{
				const char* nestedTypeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(nextTypeDef->nameIndex);
				IL2CPP_ASSERT(nestedTypeName);
				if (!std::strcmp(type.name, nestedTypeName))
				{
					type.aotType = nextTypeDef;
					break;
				}
			}
		}
		else
		{
			const char* namespaze = il2cpp::vm::GlobalMetadata::GetStringFromIndex(type.interpType->namespaceIndex);
			const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)il2cpp::vm::Image::TypeHandleFromName(_originImage, namespaze, type.name);
			type.aotType = typeDef;
		}
	}

	void DifferentialHybridImage::InitTypeMappings()
	{
		_typeMappings.resize(_typeDetails.size());
		for (TypeDefinitionDetail& td : _typeDetails)
		{
			TypeMapping& tm = _typeMappings[td.index];
			tm.inited = false;
			tm.name = _rawImage.GetStringFromRawIndex(DecodeMetadataIndex(td.typeDef->nameIndex));
			tm.interpType = td.typeDef;
			tm.aotType = nullptr;
		}
		for (TypeMapping& type : _typeMappings)
		{
			InitTypeMapping(type);
		}
	}

	Il2CppMetadataTypeHandle GetOriginAOTTypeHandle(Il2CppMetadataTypeHandle typeHandle)
	{
		const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)typeHandle;
		if (IsInterpreterType(typeDef))
		{
			InterpreterImage* image = MetadataModule::GetImage(typeDef);
			if (image->IsHotPatch())
			{
				const Il2CppTypeDefinition* originTypeDef = ((DifferentialHybridImage*)image)->GetOriginType(typeDef);
				if (originTypeDef)
				{
					return (Il2CppMetadataTypeHandle)originTypeDef;
				}
			}
		}
		return typeHandle;
	}

	bool IsHotPatchTypeEqual(const Il2CppType* interpType, const Il2CppType* aotType)
	{
		if (aotType->type != interpType->type)
		{
			return false;
		}

		if (aotType->byref != interpType->byref)
		{
			return false;
		}

		switch (aotType->type)
		{
		case IL2CPP_TYPE_VALUETYPE:
		case IL2CPP_TYPE_CLASS:
			return aotType->data.typeHandle == GetOriginAOTTypeHandle(interpType->data.typeHandle);
		case IL2CPP_TYPE_PTR:
		case IL2CPP_TYPE_SZARRAY:
			return IsHotPatchTypeEqual(aotType->data.type, interpType->data.type);

		case IL2CPP_TYPE_ARRAY:
		{
			if (aotType->data.array->rank < interpType->data.array->rank)
			{
				return false;
			}
			return IsHotPatchTypeEqual(aotType->data.array->etype, interpType->data.array->etype);
		}
		case IL2CPP_TYPE_GENERICINST:
		{
			const Il2CppGenericInst* i1 = aotType->data.generic_class->context.class_inst;
			const Il2CppGenericInst* i2 = interpType->data.generic_class->context.class_inst;

			// this happens when maximum generic recursion is hit
			if (i1 == NULL || i2 == NULL)
			{
				return i1 == i2;
			}

			if (i1->type_argc != i2->type_argc)
				return false;

			if (!IsHotPatchTypeEqual(aotType->data.generic_class->type, interpType->data.generic_class->type))
				return false;

			/* FIXME: we should probably just compare the instance pointers directly.  */
			for (uint32_t i = 0; i < i1->type_argc; ++i)
			{
				if (!IsHotPatchTypeEqual(i1->type_argv[i], i2->type_argv[i]))
				{
					return false;
				}
			}

			return true;
		}
		case IL2CPP_TYPE_VAR:
		case IL2CPP_TYPE_MVAR:
		{
			const Il2CppGenericParameter* interpGenericParam = (const Il2CppGenericParameter*)interpType->data.genericParameterHandle;
			const Il2CppGenericParameter* aotGenericParam = (const Il2CppGenericParameter*)aotType->data.genericParameterHandle;
			return interpGenericParam->num == aotGenericParam->num;
		}
		default:
			return true;
		}
		return false;
	}

	bool IsHotPatchMethodSigEqual(const Il2CppMethodDefinition* interpMethod, const Il2CppMethodDefinition* aotMethod)
	{
		if (interpMethod->parameterCount != aotMethod->parameterCount)
		{
			return false;
		}
		if (interpMethod->genericContainerIndex == kGenericContainerIndexInvalid)
		{
			if (aotMethod->genericContainerIndex != kGenericContainerIndexInvalid)
			{
				return false;
			}
		}
		else
		{
			if (aotMethod->genericContainerIndex == kGenericContainerIndexInvalid)
			{
				return false;
			}
			const Il2CppGenericContainer* interpMethodGenericContainer = (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(interpMethod->genericContainerIndex);
			const Il2CppGenericContainer* aotMethodGenericContainer = (Il2CppGenericContainer*)il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(aotMethod->genericContainerIndex);
			if (interpMethodGenericContainer->type_argc != aotMethodGenericContainer->type_argc)
			{
				return false;
			}
		}

		const Il2CppType* interpReturnType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(interpMethod->returnType);
		const Il2CppType* aotReturnType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(aotMethod->returnType);
		if (!IsHotPatchTypeEqual(interpReturnType, aotReturnType))
		{
			return false;
		}
		for (uint32_t i = 0; i < interpMethod->parameterCount; i++)
		{
			const Il2CppParameterDefinition* interpParam = (const Il2CppParameterDefinition*)il2cpp::vm::GlobalMetadata::GetParameterDefinitionFromIndex(interpMethod, interpMethod->parameterStart + i);
			const Il2CppParameterDefinition* aotParam = (const Il2CppParameterDefinition*)il2cpp::vm::GlobalMetadata::GetParameterDefinitionFromIndex(aotMethod, aotMethod->parameterStart + i);
			const Il2CppType* interpParamType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(interpParam->typeIndex);
			const Il2CppType* aotParamType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(aotParam->typeIndex);
			if (!IsHotPatchTypeEqual(interpParamType, aotParamType))
			{
				return false;
			}
		}
		return true;
	}

	const Il2CppMethodDefinition* FindMatchMethod(const Il2CppTypeDefinition* aotType, const Il2CppMethodDefinition* toMatchMethod)
	{
		//const Il2CppGenericContainer* klassGenContainer = aotType ? GetGenericContainerFromIl2CppType(&klass1->byval_arg) : nullptr;
		const char* toMatchMethodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(toMatchMethod->nameIndex);
		for (uint16_t i = 0; i < aotType->method_count; i++)
		{
			const Il2CppMethodDefinition* method1 = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(aotType->methodStart + i);
			const char* methodName1 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(method1->nameIndex);
			if (std::strcmp(toMatchMethodName, methodName1))
			{
				continue;
			}
			if (IsHotPatchMethodSigEqual(method1, toMatchMethod))
			{
				return method1;
			}
		}
		return nullptr;
	}

	void DifferentialHybridImage::InitMethodMappings()
	{
		_methodMappings.resize(_methodDefines.size());

		for (TypeDefinitionDetail& td : _typeDetails)
		{
			TypeMapping& tm = _typeMappings[td.index];
			for (int32_t i = DecodeMetadataIndex(tm.interpType->methodStart), n = i + tm.interpType->method_count; i < n; i++)
			{
				Il2CppMethodDefinition* methodDef = &_methodDefines[i];
				MethodMapping& mm = _methodMappings[i];
				mm.interpMethod = methodDef;

				if (tm.aotType && _notChangeMethodTokens.find(methodDef->token) != _notChangeMethodTokens.end())
				{
					const Il2CppMethodDefinition* originMethod = FindMatchMethod(tm.aotType, methodDef);
					if (originMethod)
					{
						mm.aotMethod = originMethod;
						mm.aotMethodPointer = il2cpp::vm::MetadataCache::GetMethodPointer(_originImage, originMethod->token);
						mm.aotAdjustorThunk = IsValueType(tm.aotType) ? il2cpp::vm::MetadataCache::GetAdjustorThunk(_originImage, mm.aotMethod->token) : nullptr;
						mm.aotMethodInvoker = il2cpp::vm::MetadataCache::GetMethodInvoker(_originImage, originMethod->token);
					}
				}
			}
		}
	}

	void DifferentialHybridImage::InitRuntimeMetadatas()
	{
		InterpreterImage::InitRuntimeMetadatas();
		InitTypeMappings();
		InitMethodMappings();
	}

	Il2CppMethodPointer DifferentialHybridImage::TryGetMethodPointer(const Il2CppMethodDefinition* method)
	{
		uint32_t index = (uint32_t)(method - &_methodDefines[0]);
		return _methodMappings[index].aotMethodPointer;
	}

	Il2CppMethodPointer DifferentialHybridImage::TryGetMethodPointer(const MethodInfo* method)
	{
		if (method->is_generic)
		{
			return TryGetMethodPointer((const Il2CppMethodDefinition*)method->methodMetadataHandle);
		}
		return nullptr;
	}

	Il2CppMethodPointer DifferentialHybridImage::TryGetAdjustThunkMethodPointer(const Il2CppMethodDefinition* method)
	{
		ptrdiff_t index = method - &_methodDefines[0];
		return _methodMappings[index].aotAdjustorThunk;
	}

	Il2CppMethodPointer DifferentialHybridImage::TryGetAdjustThunkMethodPointer(const MethodInfo* method)
	{
		if (method->is_generic)
		{
			return TryGetAdjustThunkMethodPointer((const Il2CppMethodDefinition*)method->methodMetadataHandle);
		}
		return nullptr;
	}

	InvokerMethod DifferentialHybridImage::TryGetMethodInvoker(const Il2CppMethodDefinition* method)
	{
		ptrdiff_t index = method - &_methodDefines[0];
		return _methodMappings[index].aotMethodInvoker;
	}
}
}