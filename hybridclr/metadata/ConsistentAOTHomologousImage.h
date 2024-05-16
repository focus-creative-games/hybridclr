#pragma once

#include "AOTHomologousImage.h"

namespace hybridclr
{
namespace metadata
{

	class ConsistentAOTHomologousImage : public AOTHomologousImage
	{
	public:
		ConsistentAOTHomologousImage() : AOTHomologousImage() {}

		void InitRuntimeMetadatas() override;

		void InitTypes();
		void InitMethods();
		void InitFields();

		MethodBody* GetMethodBody(uint32_t token, MethodBody& tempMethodBody) override;
		const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index) override;
		Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index) override;
		Il2CppGenericContainer* GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex) override;
		const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index) override;
		void ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret) override;
	private:
		std::vector<const Il2CppType*> _il2cppTypeForTypeDefs;
		std::vector<Il2CppTypeDefinition*> _typeDefs;

		Il2CppHashMap<uint32_t, MethodBody*, il2cpp::utils::PassThroughHash<uint32_t>> _token2MethodBodies;
		std::vector< const Il2CppMethodDefinition*> _methodDefs;

		std::vector<AOTFieldData> _fields;
	};
}
}