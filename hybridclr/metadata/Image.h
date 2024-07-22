#pragma once

#include <vector>
#include <unordered_map>
#include <tuple>

#include "vm/GlobalMetadataFileInternals.h"
#include "vm/Assembly.h"
#include "gc/GarbageCollector.h"
#include "gc/Allocator.h"
#include "gc/AppendOnlyGCHashMap.h"
#include "utils/Il2CppHashMap.h"

#include "RawImage.h"
#include "VTableSetup.h"
#include "MetadataUtil.h"
#include "PDBImage.h"


namespace hybridclr
{
namespace metadata
{

	typedef std::tuple<uint32_t, const Il2CppGenericContext*> TokenGenericContextType;

	struct TokenGenericContextTypeHash {
		size_t operator()(const TokenGenericContextType x) const noexcept {
			return std::get<0>(x) * 0x9e3779b9 + (size_t)std::get<1>(x);
		}
	};

	struct TokenGenericContextTypeEqual
	{
		bool operator()(const TokenGenericContextType a, const TokenGenericContextType b) const {
			return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
		}
	};

	typedef Il2CppHashMap<std::tuple<uint32_t, const Il2CppGenericContext*>, void*, TokenGenericContextTypeHash, TokenGenericContextTypeEqual> Token2RuntimeHandleMap;

	class Image
	{
	public:

		RawImage& GetRawImage() const
		{
			return *_rawImage;
		}

		PDBImage* GetPDBImage() const
		{
			return _pdbImage;
		}

		LoadImageErrorCode LoadPDB(const void* pdbBytes, size_t pdbLength)
		{
			_pdbImage = new PDBImage();
			LoadImageErrorCode err = _pdbImage->Load(pdbBytes, pdbLength);
			if (err != LoadImageErrorCode::OK)
			{
				delete _pdbImage;
				_pdbImage = nullptr;
				return LoadImageErrorCode::PDB_BAD_FILE;
			}
			return LoadImageErrorCode::OK;
		}

		// misc
		bool IsValueTypeFromToken(TableType tableType, uint32_t rowIndex);
		bool IsThreadStaticCtorToken(TableType tableType, uint32_t rowIndex);
		void ReadMemberRefParentFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, ResolveMemberRefParent& ret);
		const Il2CppType* ReadTypeFromMemberRefParent(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex);

		const Il2CppType* GetIl2CppType(uint32_t assemblyRefIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound);
		// type
		const Il2CppType* ReadType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer);

		const Il2CppType* ReadTypeFromTypeDef(uint32_t rowIndex);
		const Il2CppType* ReadTypeFromTypeRef(uint32_t rowIndex);
		const Il2CppType* ReadTypeFromTypeSpec(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex);
		const Il2CppType* ReadTypeFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex);

		virtual const Il2CppType* ReadTypeFromResolutionScope(uint32_t scope, uint32_t typeNamespace, uint32_t typeName);

		const Il2CppType* ReadArrayType(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer);
		const Il2CppGenericClass* ReadGenericClass(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer);

		// signature
		void ReadMemberRefSig(const Il2CppGenericContainer* klassGenericContainer, TbMemberRef& data, ResolveMemberRefSig& signature);
		void ReadFieldRefSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, FieldRefSig& field);
		void ReadMethodRefSig(BlobReader& reader, MethodRefSig& method);
		const Il2CppGenericInst* ReadMethodSpecInstantiation(uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer);
		void ReadLocalVarSig(BlobReader& reader, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, il2cpp::utils::dynamic_array<const Il2CppType*>& vars);
		void ReadStandAloneSig(uint32_t signatureIdx, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, ResolveStandAloneMethodSig& sig);

		// resolve from token
		void ReadResolveMemberRefFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, ResolveMemberRef& ret);
		void ReadMethodRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, MethodRefInfo& ret);
		void ReadMethodRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, MethodRefInfo& ret);
		const MethodInfo* ResolveMethodInfo(const Il2CppType* type, const char* resolveMethodName, const MethodRefSig& resolveSig, const Il2CppGenericInst* genericInstantiation, const Il2CppGenericContext* genericContext);

		const void* ReadRuntimeHandleFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, uint32_t rowIndex);

		void ReadFieldRefInfoFromMemberRef(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, uint32_t rowIndex, FieldRefInfo& ret);
		void ReadMethodBody(const Il2CppMethodDefinition& methodDef, const TbMethod& methodData, MethodBody& body);

		Il2CppString* GetIl2CppUserStringFromRawIndex(StringIndex index);
		Il2CppClass* GetClassFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const FieldInfo* GetFieldInfoFromFieldRef(const Il2CppType& type, const Il2CppFieldDefinition* fieldDef);
		const void* GetRuntimeHandleFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const MethodInfo* FindImplMethod(Il2CppClass* klass, const MethodInfo* matchMethod);
		const FieldInfo* GetFieldInfoFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const MethodInfo* ReadMethodInfoFromToken(const Il2CppGenericContainer* klassGenericContainer,
			const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, const Il2CppGenericInst* genericInst, TableType tableType, uint32_t rowIndex);
		const MethodInfo* GetMethodInfoFromToken(Token2RuntimeHandleMap& tokenCache, uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext);
		const MethodInfo* GetMethodInfo(const Il2CppType* containerType, const Il2CppMethodDefinition* methodDef, const Il2CppGenericInst* instantiation, const Il2CppGenericContext* genericContext);
		void GetStandAloneMethodSigFromToken(uint32_t token, const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, const Il2CppGenericContext* genericContext, ResolveStandAloneMethodSig& methodSig);
		void ReadFieldRefInfoFromToken(const Il2CppGenericContainer* klassGenericContainer, const Il2CppGenericContainer* methodGenericContainer, TableType tableType, uint32_t rowIndex, FieldRefInfo& ret);

		virtual const Il2CppType* GetModuleIl2CppType(uint32_t moduleRowIndex, uint32_t typeNamespace, uint32_t typeName, bool raiseExceptionIfNotFound) = 0;
		virtual const Il2CppType* GetIl2CppTypeFromRawTypeDefIndex(uint32_t index) = 0;
		virtual Il2CppGenericContainer* GetGenericContainerByRawIndex(uint32_t index) = 0;
		virtual Il2CppGenericContainer* GetGenericContainerByTypeDefRawIndex(int32_t typeDefIndex) = 0;
		virtual const Il2CppMethodDefinition* GetMethodDefinitionFromRawIndex(uint32_t index) = 0;

		virtual MethodBody* GetMethodBody(uint32_t token, MethodBody& tempMethodBody) = 0;
		virtual void ReadFieldRefInfoFromFieldDefToken(uint32_t rowIndex, FieldRefInfo& ret) = 0;
		virtual void InitRuntimeMetadatas() = 0;
	protected:
		Image() : _rawImage(nullptr), _pdbImage(nullptr)
		{
			il2cpp::vm::AssemblyVector assemblies;
			il2cpp::vm::Assembly::GetAllAssemblies(assemblies);
			for (auto ass : assemblies)
			{
				_nameToAssemblies[ass->image->nameNoExt] = ass;
			}
		}

		virtual ~Image()
		{
			if (_rawImage)
			{
				delete _rawImage;
				_rawImage = nullptr;
			}
			if (_pdbImage)
			{
				delete _pdbImage;
				_pdbImage = nullptr;
			}
		}

		const Il2CppAssembly* GetLoadedAssembly(const char* assemblyName)
		{
			auto it = _nameToAssemblies.find(assemblyName);
			if (it != _nameToAssemblies.end())
			{
				return it->second;
			}
			// relying assembly is loaded after self
			for (const Il2CppAssembly* ass : *il2cpp::vm::Assembly::GetAllAssemblies())
			{
				if (!std::strcmp(ass->image->nameNoExt, assemblyName))
				{
					_nameToAssemblies[ass->image->nameNoExt] = ass;
					return ass;
				}
			}
			return nullptr;
		}

		Il2CppClass* FindNetStandardExportedType(const char* namespaceStr, const char* nameStr);

		RawImage* _rawImage;
		PDBImage* _pdbImage;
		Il2CppHashMap<const char*, const Il2CppAssembly*, CStringHash, CStringEqualTo> _nameToAssemblies;
		il2cpp::gc::AppendOnlyGCHashMap<uint32_t, Il2CppString*, il2cpp::utils::PassThroughHash<uint32_t>> _il2cppStringCache;
	};
}
}