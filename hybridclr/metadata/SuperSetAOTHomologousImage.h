#pragma once

#include "AOTHomologousImage.h"

namespace hybridclr
{
	namespace metadata
	{
		struct SuperSetTypeDefDetail
		{
			bool inited;
			uint32_t homoRowIndex;
			uint32_t homoParentRowIndex;
			uint32_t homoMethodStartIndex; // start from 1
			uint32_t homoFieldStartIndex; // start from 1
			const char* name;
			const char* namespaze;
			int32_t aotTypeIndex; // il2cpp type index
			const Il2CppType* aotIl2CppType;
			const Il2CppTypeDefinition* aotTypeDef;
			const Il2CppClass* aotKlass;
		};

		struct SuperSetMethodDefDetail
		{
			uint32_t homoRowIndex;
			MethodRefSig signature;
			const Il2CppTypeDefinition* declaringTypeDef;
			const Il2CppClass* declaringKlass;
			const char* name;
			const Il2CppMethodDefinition* aotMethodDef;
			MethodBody* body;
		};

		struct SuperSetFieldDefDetail
		{
			uint32_t homoRowIndex;
			const char* name;
			Il2CppType type;
			const Il2CppTypeDefinition* declaringTypeDef;
			const Il2CppType* declaringIl2CppType;
			const Il2CppFieldDefinition* aotFieldDef;
		};

		class SuperSetAOTHomologousImage : public AOTHomologousImage
		{
		public:
			SuperSetAOTHomologousImage() : AOTHomologousImage() {}

			void InitRuntimeMetadatas() override;

			void InitTypes0();
			void InitNestedClass();
			void InitType(SuperSetTypeDefDetail& type);
			void InitTypes1();
			void ReadMethodDefSig(BlobReader& reader, MethodRefSig& method);
			void InitMethods();
			void InitFields();

			void ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName, Il2CppType& type) override;
			MethodBody* GetMethodBody(uint32_t token) override;
			const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index) override;
			Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index) override;
			Il2CppGenericContainer* GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex) override;
			const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index) override;
			void ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret) override;
		private:
			Il2CppType _defaultIl2CppType;

			std::vector<SuperSetTypeDefDetail> _typeDefs;
			std::unordered_map<int32_t, SuperSetTypeDefDetail*> _aotTypeIndex2TypeDefs;

			std::unordered_map<uint32_t, SuperSetMethodDefDetail*> _token2MethodDefs;
			std::vector<SuperSetMethodDefDetail> _methodDefs;

			std::vector<SuperSetFieldDefDetail> _fields;
		};
	}
}