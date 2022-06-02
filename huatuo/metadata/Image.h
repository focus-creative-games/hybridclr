#pragma once

#include <vector>
#include <unordered_map>
#include <tuple>

#include "vm/GlobalMetadataFileInternals.h"
#include "gc/GarbageCollector.h"
#include "gc/Allocator.h"
#include "gc/AppendOnlyGCHashMap.h"

#include "RawImage.h"
#include "VTableSetup.h"
#include "MetadataUtil.h"


namespace huatuo
{
namespace metadata
{


	struct ParamDetail
	{
		Il2CppParameterDefinition paramDef;
		const Il2CppMethodDefinition* methodDef;
		//uint32_t methodIndex;
		uint32_t parameterIndex;
		uint32_t defaultValueIndex; // -1 for invalid
	};

	struct FieldDetail
	{
		Il2CppFieldDefinition fieldDef;
		uint32_t typeDefIndex;
		uint32_t offset;
		uint32_t defaultValueIndex; // -1 for invalid
	};

	class Image
	{
	public:

		const RawImage& GetRawImage() const
		{
			return _rawImage;
		}

		// misc
		bool IsValueTypeFromToken(TableType tableType, uint32_t rowIndex);
		bool IsThreadStaticCtorToken(TableType tableType, uint32_t rowIndex);
		void ReadMemberRefParentFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, ResolveMemberRefParent& ret);
		void ReadTypeFromMemberRefParent(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type);

		const Il2CppTypeDefinition* GetTypeDefinition(uint32_t assemblyRefIndex, uint32_t typeNamespace, uint32_t typeName);
		// type
		void ReadType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType& type);

		void ReadTypeFromTypeDef(uint32_t rowIndex, Il2CppType& type);
		void ReadTypeFromTypeRef(uint32_t rowIndex, Il2CppType& type);
		void ReadTypeFromTypeSpec(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, Il2CppType& type);
		void ReadTypeFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, Il2CppType& type);

		void ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName, Il2CppType& type);

		void ReadArrayType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppArrayType& type);
		void ReadGenericClass(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericClass& type);

		// signature
		void ReadMemberRefSig(const Il2CppGenericContainer* klassGenericContainer, TbMemberRef& data, ResolveMemberRefSig& signature);
		void ReadFieldRefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, FieldRefSig& field);
		void ReadMethodRefSig(TbMemberRef& rowData, MethodRefSig& method);
		void ReadMethodDefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppMethodDefinition& methodDef, std::vector<ParamDetail>& paramArr);
		void ReadMethodSpecInstantiation(uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst*& genericInstantiation);
		void ReadLocalVarSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppType*& vars, uint32_t& varCount);
		void ReadStandAloneSig(uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, ResolveStandAloneMethodSig& sig);

		// resolve from token
		void ReadResolveMemberRefFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, ResolveMemberRef& ret);
		void ReadMethodRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, MethodRefInfo& ret);
		void ReadMethodRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, Il2CppGenericInst* genericInstantiation, uint32_t rowIndex, MethodRefInfo& ret);

		void ReadFieldRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, FieldRefInfo& ret);
		void ReadFieldRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, FieldRefInfo& ret);

		virtual uint32_t AddIl2CppTypeCache(Il2CppType& type) = 0;
		virtual const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index) = 0;
		virtual Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index) = 0;
		virtual const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index) = 0;
		virtual const Il2CppType* GetIl2CppTypeFromRawIndex(uint32_t index) const = 0;
		virtual const Il2CppTypeDefinition* GetTypeFromRawIndex(uint32_t index) const = 0;
		virtual const FieldDetail& GetFieldDetailFromRawIndex(uint32_t index) = 0;

		virtual MethodBody* GetMethodBody(uint32_t token) = 0;
		virtual Il2CppString* GetIl2CppUserStringFromRawIndex(StringIndex index) = 0;
		virtual Il2CppClass* GetClassFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual const MethodInfo* GetMethodInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual const FieldInfo* GetFieldInfoFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual const void* GetRuntimeHandleFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext) = 0;
		virtual void GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig) = 0;
		virtual const MethodInfo* FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod) = 0;
	protected:
		RawImage _rawImage;
	};
}
}