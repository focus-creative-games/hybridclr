#pragma once

#include "InterpreterImage.h"
#include "AOTHomologousImage.h"
#include "Assembly.h"

namespace hybridclr
{

namespace metadata
{
	class MetadataModule
	{
	public:

		static void Initialize();

		static InterpreterImage* GetImage(uint32_t imageIndex)
		{
			return InterpreterImage::GetImage(imageIndex);
		}

		static InterpreterImage* GetImage(const Il2CppImage* image)
		{
			return GetImage(DecodeImageIndex(image->token));
		}

		static InterpreterImage* GetImage(const Il2CppClass* klass)
		{
			return GetImage(klass->image);
		}

		static InterpreterImage* GetImage(const Il2CppMetadataTypeHandle typeHandle)
		{
            const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)typeHandle;
			return GetImage(DecodeImageIndex(typeDef->byvalTypeIndex));
		}

		static InterpreterImage* GetImage(const Il2CppMethodDefinition& method)
		{
			return GetImage(DecodeImageIndex(method.nameIndex));
		}

		static InterpreterImage* GetImage(const MethodInfo* method)
		{
			return GetImage(method->klass->image);
		}

		static InterpreterImage* GetImageByEncodedIndex(uint32_t encodedIndex)
		{
			return GetImage(DecodeImageIndex(encodedIndex));
		}
		
		static Image* GetUnderlyingInterpreterImage(const MethodInfo* method);


		static const char* GetStringFromEncodeIndex(StringIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetStringFromRawIndex(DecodeMetadataIndex(index));
		}

		static uint32_t GetTypeEncodeIndex(const Il2CppMetadataTypeHandle typeHandle)
		{
			InterpreterImage* image = GetImage(typeHandle);
			return hybridclr::metadata::EncodeImageAndMetadataIndex(image->GetIndex(), image->GetTypeRawIndex(typeHandle));
		}

		static Il2CppMetadataTypeHandle GetAssemblyTypeHandleFromRawIndex(const Il2CppImage* image, AssemblyTypeIndex index)
		{
			return GetImage(image)->GetAssemblyTypeHandleFromRawIndex(index);
		}

		static Il2CppMetadataTypeHandle GetAssemblyTypeHandleFromEncodeIndex(TypeDefinitionIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetAssemblyTypeHandleFromRawIndex(DecodeMetadataIndex(index));
		}

		static Il2CppMetadataTypeHandle GetAssemblyExportedTypeHandleFromEncodeIndex(AssemblyTypeIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetAssemblyExportedTypeHandleFromRawIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppTypeDefinition& GetTypeDefinitionFromHandle(const Il2CppMetadataTypeHandle typeHandle)
		{
			const Il2CppTypeDefinition* typeDef = (const Il2CppTypeDefinition*)typeHandle;
			return *typeDef;
        }

		static const Il2CppTypeDefinitionSizes* GetTypeDefinitionSizesFromEncodeIndex(TypeDefinitionIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetTypeDefinitionSizesFromRawIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppType* GetIl2CppTypeFromEncodeIndex(uint32_t index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			IL2CPP_ASSERT(imageIndex > 0);

			uint32_t rawIndex = DecodeMetadataIndex(index);
			return GetImage(imageIndex)->GetIl2CppTypeFromRawIndex(rawIndex);
		}

		static Il2CppClass* GetTypeInfoFromTypeDefinitionEncodeIndex(TypeDefinitionIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			IL2CPP_ASSERT(imageIndex > 0);

			uint32_t rawIndex = DecodeMetadataIndex(index);
			return GetImage(imageIndex)->GetTypeInfoFromTypeDefinitionRawIndex(rawIndex);
		}

		static Il2CppClass* GetTypeInfoFromHandle(const Il2CppMetadataTypeHandle typeHandle)
		{
			InterpreterImage* image = GetImage(typeHandle);
			return image->GetTypeInfoFromHandle(typeHandle);
		}

		static Il2CppClass* GetTypeInfoFromHandle_OnlyCached(const Il2CppMetadataTypeHandle typeHandle)
		{
			InterpreterImage* image = GetImage(typeHandle);
			return image->GetTypeInfoFromHandle_OnlyCached(typeHandle);
		}

		static const Il2CppFieldDefinition& GetFieldDefinitionFromEncodeIndex(uint32_t index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetFieldDefinitionFromRawIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppMetadataMethodDefinitionHandle GetMethodHandleFromIndex(MethodIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetMethodHandleFromRawIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppMethodDefinition& GetMethodDefinitionFromHandle(const Il2CppMetadataMethodDefinitionHandle methodHandle)
		{
			return *(const Il2CppMethodDefinition*)methodHandle;
		}

		static MethodIndex GetMethodIndexFromMethodHandle(const Il2CppMetadataMethodDefinitionHandle methodHandle)
		{
			const Il2CppMethodDefinition* methodDef = (const Il2CppMethodDefinition*)methodHandle;
			uint32_t imageIndex = DecodeImageIndex(methodDef->nameIndex);
			return GetImage(imageIndex)->GetMethodIndexFromDefinition(methodHandle);
		}

		static uint32_t GetFieldOffset(const Il2CppClass* klass, int32_t fieldIndexInType, FieldInfo* field)
		{
			return GetImage(klass)->GetFieldOffset(klass, fieldIndexInType);
		}

		static const MethodInfo* GetMethodInfoFromMethodDefinitionIndex(uint32_t index)
		{
			uint32_t imageIndex = DecodeImageIndex(index);
			return GetImage(imageIndex)->GetMethodInfoFromMethodDefinitionRawIndex(DecodeMetadataIndex(index));
		}

		static const MethodInfo* GetMethodInfoFromMethodDefinition(const Il2CppMetadataMethodDefinitionHandle methodHandle)
		{
            const Il2CppMethodDefinition* methodDef = (const Il2CppMethodDefinition*)methodHandle;
			uint32_t imageIndex = DecodeImageIndex(methodDef->nameIndex);
			return GetImage(imageIndex)->GetMethodInfoFromMethodDefinition(methodHandle);
		}

		static const MethodInfo* GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot)
		{
			return GetImage(klass)->GetMethodInfoFromVTableSlot(klass, vTableSlot);
		}

		static const Il2CppMetadataMethodDefinitionHandle GetMethodDefinitionFromVTableSlot(const Il2CppMetadataTypeHandle typeHandle, int32_t vTableSlot)
		{
			return GetImage(typeHandle)->GetMethodDefinitionFromVTableSlot(typeHandle, vTableSlot);
		}

		static Il2CppMethodPointer GetAdjustorThunk(const Il2CppImage* image, uint32_t token)
		{
			uint32_t imageIndex = DecodeImageIndex(image->token);
			return GetImage(imageIndex)->GetAdjustorThunk(token);
		}

		static Il2CppMethodPointer GetMethodPointer(const Il2CppImage* image, uint32_t token)
		{
			uint32_t imageIndex = DecodeImageIndex(image->token);
			return GetImage(imageIndex)->GetMethodPointer(token);
		}

		static InvokerMethod GetMethodInvoker(const Il2CppImage* image, uint32_t token)
		{
			uint32_t imageIndex = DecodeImageIndex(image->token);
			return GetImage(imageIndex)->GetMethodInvoker(token);
		}

		static const Il2CppParameterDefinition GetParameterDefinitionFromIndex(const Il2CppImage* image, ParameterIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(image->token);
			return GetImage(imageIndex)->GetParameterDefinitionFromIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppEventDefinition& GetEventDefinitionFromIndex(const Il2CppImage* image, EventIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(image->token);
			return GetImage(imageIndex)->GetEventDefinitionFromIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppPropertyDefinition* GetPropertyDefinitionFromIndex(const Il2CppImage* image, PropertyIndex index)
		{
			uint32_t imageIndex = DecodeImageIndex(image->token);
			return GetImage(imageIndex)->GetPropertyDefinitionFromIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppType* GetInterfaceFromIndex(const Il2CppMetadataTypeHandle typeHandle, TypeInterfaceIndex index)
		{
			return GetImage(typeHandle)->GetInterfaceFromIndex(typeHandle, index);
		}

		static const Il2CppType* GetInterfaceFromIndex(const Il2CppClass* klass, TypeInterfaceIndex index)
		{
			return GetImage(klass)->GetInterfaceFromIndex(klass, index);
		}

		static const Il2CppType* GetInterfaceFromOffset(const Il2CppClass* klass, TypeInterfaceIndex offset)
		{
			return GetImage(klass)->GetInterfaceFromOffset(klass, offset);
		}

		static const Il2CppType* GetInterfaceFromOffset(const Il2CppMetadataTypeHandle typeHandle, TypeInterfaceIndex offset)
		{
			return GetImage(typeHandle)->GetInterfaceFromOffset(typeHandle, offset);
		}

		static Il2CppInterfaceOffsetInfo GetInterfaceOffsetInfo(const Il2CppMetadataTypeHandle typeHandle, TypeInterfaceOffsetIndex index)
		{
			return GetImage(typeHandle)->GetInterfaceOffsetInfo(typeHandle, index);
		}

		static Il2CppClass* GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset)
		{
			return GetImage(klass)->GetNestedTypeFromOffset(klass, offset);
		}

		static Il2CppClass* GetNestedTypeFromOffset(const Il2CppMetadataTypeHandle typeHandle, TypeNestedTypeIndex offset)
		{
			return GetImage(typeHandle)->GetNestedTypeFromOffset(typeHandle, offset);
		}

		static Il2CppMetadataTypeHandle GetNestedTypes(Il2CppMetadataTypeHandle handle, void** iter)
		{
			return (Il2CppMetadataTypeHandle)(GetImage(handle)->GetNestedTypes(handle, iter));
		}

		static const Il2CppGenericContainer* GetGenericContainerFromEncodeIndex(uint32_t index)
		{
			return GetImage(DecodeImageIndex(index))->GetGenericContainerByRawIndex(DecodeMetadataIndex(index));

		}

		static const Il2CppFieldDefaultValue* GetFieldDefaultValueEntryByFieldIndex(uint32_t index)
		{
			return GetImage(DecodeImageIndex(index))->GetFieldDefaultValueEntryByFieldRawIndex(DecodeMetadataIndex(index));
		}

		static const uint8_t* GetFieldDefaultValueByFieldIndex(uint32_t index)
		{
			return GetImage(DecodeImageIndex(index))->GetFieldDefaultValueByFieldRawIndex(DecodeMetadataIndex(index));
		}

		static const uint8_t* GetFieldOrParameterDefaultValueByDataIndex(uint32_t index)
		{
			return GetImage(DecodeImageIndex(index))->GetFieldOrParameterDefalutValueByRawIndex(DecodeMetadataIndex(index));
		}

		static const Il2CppParameterDefaultValue* GetParameterDefaultValueEntryByParameterPosition(const MethodInfo* method, uint32_t index)
		{
			const Il2CppMethodDefinition* methodDef = (const Il2CppMethodDefinition*)method->methodMetadataHandle;
			return GetImage(method)->GetParameterDefaultValueEntryByRawIndex(methodDef->parameterStart + index);
		}

		static const Il2CppGenericParameter& GetGenericParameterFromHandle(Il2CppMetadataGenericParameterHandle handle)
		{
            return *(const Il2CppGenericParameter*)handle;
		}

		static const Il2CppGenericParameter* GetGenericParameterByRawIndex(const Il2CppGenericContainer* container, uint32_t index)
		{
			return GetImage(hybridclr::metadata::DecodeImageIndex(container->ownerIndex))->GetGenericParameterByRawIndex(container, index);
		}

		static const Il2CppType* GetGenericParameterConstraintFromIndex(GenericContainerIndex ownerIndex, GenericParameterConstraintIndex index)
		{
			return GetImage(hybridclr::metadata::DecodeImageIndex(ownerIndex))
				->GetGenericParameterConstraintFromIndex(index);
		}

#if HYBRIDCLR_UNITY_2020
		static bool HasAttribute(const Il2CppImage* image, uint32_t token, Il2CppClass* attribute)
		{
			return GetImage(image)->HasAttributeByToken(token, attribute);
		}

		static std::tuple<void*, void*> GetCustomAttributeDataRange(const Il2CppImage* image, uint32_t token)
		{
			return GetImage(image)->GetCustomAttributeDataRange(token);
		}
#endif

		static bool IsImplementedByInterpreter(MethodInfo* method)
		{
			Il2CppClass* klass = method->klass;
			Il2CppClass* parent = klass->parent;
			if (parent != il2cpp_defaults.multicastdelegate_class && parent != il2cpp_defaults.delegate_class)
			{
				return AOTHomologousImage::FindImageByAssembly(klass->image->assembly);
			}
			else
			{
				return strcmp(method->name, "Invoke") == 0;
			}
		}
	private:

	};
}

}