#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "metadata/Il2CppTypeHash.h"
#include "metadata/Il2CppTypeCompare.h"

#include "../CommonDef.h"
#include "MetadataUtil.h"

namespace hybridclr
{
namespace metadata
{
	struct GenericClassMethod
	{
		const Il2CppType* type;
		const Il2CppMethodDefinition* method;
		const char* name; // TODO remove
	};

	struct VirtualMethodImpl
	{
		const Il2CppMethodDefinition* method;
		const Il2CppType* type;
		uint16_t slot;
		const char* name; //  TODO for debug
	};

	class VTableSetUp;

	struct RawInterfaceOffsetInfo
	{
		const Il2CppType* type;
		VTableSetUp* tree;
		uint32_t offset;
	};

	typedef std::unordered_map<const Il2CppType*, VTableSetUp*, Il2CppTypeHash, Il2CppTypeEqualTo> Il2CppType2TypeDeclaringTreeMap;

	class VTableSetUp
	{
	public:
		static VTableSetUp* BuildByType(Il2CppType2TypeDeclaringTreeMap& cache, const Il2CppType* type);
		static VTableSetUp* InflateVts(Il2CppType2TypeDeclaringTreeMap& cache, VTableSetUp* genericType, const Il2CppType* type);

		VTableSetUp()
		{

		}

		const VTableSetUp* GetParent() const { return _parent; }
		const Il2CppType* FindImplType(const Il2CppMethodDefinition* methodDef);
		const VTableSetUp* FindAncestorTypeTree(const Il2CppType* implType);
		const GenericClassMethod* FindImplMethod(const Il2CppType* containerType, const Il2CppMethodDefinition* methodDef, bool throwExceptionIfNotFind = true);
		const std::vector<RawInterfaceOffsetInfo>& GetInterfaceOffsetInfos() const { return _interfaceOffsetInfos; }
		const std::vector<VirtualMethodImpl>& GetVirtualMethodImpls() const { return _methodImpls; }
		const Il2CppType* GetType() const { return _type; }
		uint32_t GetTypeIndex() const { return _typeDef->byvalTypeIndex; }
		bool IsInterType() const { return hybridclr::metadata::IsInterpreterType(_typeDef); }
	private:

		void ComputeVtables(Il2CppType2TypeDeclaringTreeMap& cache);
		void ComputAotTypeVtables(Il2CppType2TypeDeclaringTreeMap& cache);
		void InitInterfaceVTable(uint16_t& curOffset, std::vector<uint16_t>& implInterfaceOffsetIdxs);
		void ComputeExplicitImpls(const std::vector<uint16_t>& implInterfaceOffsetIdxs, std::unordered_map<int32_t, uint16_t>& explicitImplToken2Slots);
		void ApplyTypeExplicitImpls(const Il2CppType* type, const std::vector<uint16_t>& implInterfaceOffsetIdxs, std::unordered_map<int32_t, uint16_t>& explicitImplToken2Slots);
		void ComputeOverrideParentVirtualMethod(uint16_t& curOffset, const std::vector<uint16_t>& implInterfaceOffsetIdxs, std::unordered_map<int32_t, uint16_t>& explicitImplToken2Slots);
		void ComputeInterfaceOverrideByParentVirtualMethod(const std::vector<uint16_t>& implInterfaceOffsetIdxs);
		void ComputeInterpTypeVtables(Il2CppType2TypeDeclaringTreeMap& cache);
		void ComputeInterfaceVtables(Il2CppType2TypeDeclaringTreeMap& cache) const;

		bool isExplicitImplInterfaceSlot(uint16_t slot) const { return _explicitImplSlots.find(slot) != _explicitImplSlots.end(); }
		uint16_t FindDefaultOverrideExplicitInterfaceSlot(GenericClassMethod& gcm, const std::unordered_set<uint16_t>& explicitImplSlots, const std::vector<uint16_t>& implInterfaceOffsetIdxs);
		uint16_t FindExplicitOverrideInterfaceSlot(GenericClassMethod& gcm, const std::unordered_map<int32_t, uint16_t>& explicitImplSlots);
		void ApplyOverrideMethod(const GenericClassMethod* beOverrideParentMethod, const Il2CppMethodDefinition* overrideMethodDef, uint16_t checkOverrideMaxIdx);
		void ApplyExplicitOverride(const std::vector<uint16_t>& implInterfaceOffsetIdxs, std::unordered_map<int32_t, uint16_t>& explicitImplToken2Slots, const Il2CppType* declaringType,
			const Il2CppMethodDefinition* decalringMethod, const Il2CppType* implType, const Il2CppMethodDefinition* implMethod);
		
		VTableSetUp* _parent;
		std::vector<VTableSetUp*> _interfaces;
		std::vector<RawInterfaceOffsetInfo> _interfaceOffsetInfos;

		const Il2CppType* _type;
		const Il2CppTypeDefinition* _typeDef;
		const char* _name; // TODO remove

		std::vector<GenericClassMethod> _virtualMethods;
		std::vector<VirtualMethodImpl> _methodImpls;

		std::unordered_set<uint16_t> _explicitImplSlots;;
	};
}
}
