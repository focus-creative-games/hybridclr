#include "VTableSetup.h"

#include <algorithm>

#include "vm/GlobalMetadata.h"
#include "metadata/GenericMetadata.h"

#include "MetadataModule.h"

namespace hybridclr
{
namespace metadata
{
	const Il2CppType* TryInflateIfNeed(const Il2CppType* containerType, const Il2CppType* genericType, const Il2CppType* selfType)
	{
		if (selfType->type == IL2CPP_TYPE_CLASS || selfType->type == IL2CPP_TYPE_VALUETYPE)
		{
			if (genericType->data.typeHandle == selfType->data.typeHandle)
			{
				return containerType;
			}
		}
		return TryInflateIfNeed(containerType, selfType);
	}

	VTableSetUp* VTableSetUp::InflateVts(Il2CppType2TypeDeclaringTreeMap& cache, VTableSetUp* genericType, const Il2CppType* type)
	{
		IL2CPP_ASSERT(genericType->_type->data.typeHandle == type->data.generic_class->type->data.typeHandle);
		VTableSetUp* tdt = new (HYBRIDCLR_MALLOC_ZERO(sizeof(VTableSetUp))) VTableSetUp();
		tdt->_type = type;
		tdt->_typeDef = genericType->_typeDef;
		tdt->_parent = genericType->_parent ? BuildByType(cache, TryInflateIfNeed(type, genericType->_parent->_type)) : nullptr;
		tdt->_name = genericType->_name;

		for (VTableSetUp* gintf : genericType->_interfaces)
		{
			const Il2CppType* intType = TryInflateIfNeed(type, gintf->_type);
			VTableSetUp* intf = BuildByType(cache, intType);
			tdt->_interfaces.push_back(intf);
		}

		for (GenericClassMethod& gcm : genericType->_virtualMethods)
		{
			tdt->_virtualMethods.push_back({ TryInflateIfNeed(type, genericType->_type, gcm.type), gcm.method, gcm.name });
		}

		for (RawInterfaceOffsetInfo& roi : genericType->_interfaceOffsetInfos)
		{
			const Il2CppType* intType = TryInflateIfNeed(type, genericType->_type, roi.type);
			VTableSetUp* intf = BuildByType(cache, intType);
			tdt->_interfaceOffsetInfos.push_back({ intType, intf, roi.offset });
		}

		for (VirtualMethodImpl& vmi : genericType->_methodImpls)
		{
			const Il2CppType* declaringType = vmi.type ? TryInflateIfNeed(type, genericType->_type, vmi.type) : nullptr;
			tdt->_methodImpls.push_back({ vmi.method, declaringType, vmi.slot /*, vmi.name*/});
		}

		return tdt;
	}

	VTableSetUp* VTableSetUp::BuildByType(Il2CppType2TypeDeclaringTreeMap& cache, const Il2CppType* type)
	{
		auto it = cache.find(type);
		if (it != cache.end())
		{
			return it->second;
		}
		if (type->type == IL2CPP_TYPE_GENERICINST)
		{
			const Il2CppType* genericType = type->data.generic_class->type;
			IL2CPP_ASSERT(genericType);
			VTableSetUp* gdt = BuildByType(cache, genericType);
			VTableSetUp* gidt = InflateVts(cache, gdt, type);
			return cache[type] = gidt;
		}
		VTableSetUp* tdt = new (HYBRIDCLR_MALLOC_ZERO(sizeof(VTableSetUp))) VTableSetUp();
		const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
		const char* ns = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
		const char* name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
		const Il2CppType* parentType = nullptr;
		if (typeDef->parentIndex != kInvalidIndex)
		{
			parentType = il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->parentIndex);
		}
		tdt->_type = type;
		tdt->_typeDef = typeDef;
		tdt->_parent = parentType ? BuildByType(cache, parentType) : nullptr;
		tdt->_name = name;

		for (uint32_t i = 0; i < typeDef->interfaces_count; i++)
		{
			const Il2CppType* intType = il2cpp::vm::GlobalMetadata::GetInterfaceFromOffset(typeDef, i);
			VTableSetUp* intf = BuildByType(cache, intType);
			tdt->_interfaces.push_back(intf);
		}

		for (uint32_t i = 0; i < typeDef->method_count; i++)
		{
			const Il2CppMethodDefinition* methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(typeDef->methodStart + i);
			const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex);
			if (hybridclr::metadata::IsVirtualMethod(methodDef->flags))
			{
				tdt->_virtualMethods.push_back({ type, methodDef, methodName });
			}
		}
		if (hybridclr::metadata::IsInterface(typeDef->flags))
		{
			tdt->ComputeInterfaceVtables(cache);
		}
		else
		{
			tdt->ComputeVtables(cache);
		}
		cache[type] = tdt;
		return tdt;
	}


	inline bool IsOverrideMethod(const GenericClassMethod& m1, const GenericClassMethod& m2)
	{
		return hybridclr::metadata::IsOverrideMethod(m1.type, m1.method, m2.type, m2.method);
	}


	uint16_t FindLastSameMethod(std::vector<GenericClassMethod>& methods, uint32_t maxIdx, const GenericClassMethod& find, bool notSealed)
	{
		for (uint32_t i = std::min(maxIdx, (uint32_t)methods.size()); i > 0; i--)
		{
			uint32_t idx = i - 1;
			if (methods[idx].method == nullptr)
			{
				continue;
			}
			if (IsOverrideMethod(methods[idx], find))
			{
				return idx;
			}
		}
		return kInvalidIl2CppMethodSlot;
	}


	bool containeTdt(const std::vector<VTableSetUp*>& trees, VTableSetUp* findTree)
	{
		for (VTableSetUp* add : trees)
		{
			if (il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(add->GetType(), findTree->GetType()))
			{
				return true;
			}
		}
		return false;
	}


	bool FindType(const std::vector<RawInterfaceOffsetInfo>& interfaceOffsetInfos, const Il2CppType* type, uint16_t& resultIdx)
	{
		uint16_t idx = 0;
		for (auto& ioi : interfaceOffsetInfos)
		{
			if (il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(type, ioi.type))
			{
				resultIdx = idx;
				return true;
			}
			++idx;
		}
		resultIdx = (uint16_t)-1;
		return false;
	}

	void VTableSetUp::ComputeInterfaceVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		IL2CPP_ASSERT(hybridclr::metadata::IsInterface(_typeDef->flags));

		if (IsInterType())
		{
			uint16_t slotIdx = 0;
			for (auto& vm : _virtualMethods)
			{
				Il2CppMethodDefinition* methodDef = const_cast<Il2CppMethodDefinition*>(vm.method);
				IL2CPP_ASSERT(methodDef->slot == slotIdx);
				slotIdx++;
			}
		}
	}

	void VTableSetUp::ComputeVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		if (IsInterType())
		{
			ComputeInterpTypeVtables(cache);
		}
		else
		{
			ComputAotTypeVtables(cache);
		}

		uint16_t idx = 0;
		for (auto& vmi : _methodImpls)
		{
			IL2CPP_ASSERT(vmi.slot == idx);
			++idx;
		}
	}

	const Il2CppType* VTableSetUp::FindImplType(const Il2CppMethodDefinition* methodDef)
	{
		Il2CppTypeDefinition* declarType = (Il2CppTypeDefinition*)il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(methodDef->declaringType);
		for (VTableSetUp* cur = this; cur; cur = cur->_parent)
		{
			if (declarType == cur->_typeDef)
			{
				return cur->_type;
			}
			for(VTableSetUp* itf : cur->_interfaces)
			{
				if (declarType == itf->_typeDef)
				{
					return itf->_type;
				}
			}
		}
		TEMP_FORMAT(errMsg, "VTableSetUp::FindImplType can't find impl type for method:%s.%s::%s",
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(declarType->namespaceIndex),
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(declarType->nameIndex),
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex)
			);
		RaiseExecutionEngineException(errMsg);
		return nullptr;
	}

	const VTableSetUp* VTableSetUp::FindAncestorTypeTree(const Il2CppType* implType)
	{
		for (VTableSetUp* cur = this; cur; cur = cur->_parent)
		{
			if (il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(cur->_type, implType))
			{
				return cur;
			}
		}
		return nullptr;
	}

	static void RaiseParentOverridedMethodNotFindException(const Il2CppType* type, const char* methodName)
	{
		if (!type)
		{
			il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetTypeLoadException("type not exists"));
		}

		const Il2CppTypeDefinition* typeDefinition = GetUnderlyingTypeDefinition(type);

		TEMP_FORMAT(errMsg, "VTableSetUp fail. virtual method: %s::%s::%s can't be find in declaring type or parent. It may be stripped by il2cpp",
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->namespaceIndex), 
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->nameIndex),
			methodName);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetMissingMethodException(errMsg));
	}

	const GenericClassMethod* VTableSetUp::FindImplMethod(const Il2CppType* containerType, const Il2CppMethodDefinition* methodDef, bool throwExceptionIfNotFind)
	{
		for (VTableSetUp* curTdt = this; curTdt; curTdt = curTdt->_parent)
		{
			for (int idx = (int)curTdt->_virtualMethods.size() - 1; idx >= 0; idx--)
			{
				GenericClassMethod& pvm = curTdt->_virtualMethods[idx];
				if (hybridclr::metadata::IsOverrideMethod(containerType, methodDef, pvm.type, pvm.method))
				{
					return &pvm;
				}
			}
		}
		if (throwExceptionIfNotFind)
		{
			RaiseParentOverridedMethodNotFindException(this->_type, il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex));
		}
		return nullptr;
	}

	void VTableSetUp::ComputAotTypeVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		for (uint16_t i = 0; i < _typeDef->interface_offsets_count; i++)
		{
			Il2CppInterfaceOffsetInfo ioi = il2cpp::vm::GlobalMetadata::GetInterfaceOffsetInfo(_typeDef, i);
			_interfaceOffsetInfos.push_back({ ioi.interfaceType, BuildByType(cache, ioi.interfaceType), (uint16_t)ioi.offset });
		}

		int nullVtableSlotCount = 0;
		for (uint16_t i = 0; i < _typeDef->vtable_count; i++)
		{
			const Il2CppMethodDefinition* overideMethodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromVTableSlot(_typeDef, i);
			if (overideMethodDef == nullptr)
			{
				if (_parent && i < _parent->_typeDef->vtable_count)
				{
					IL2CPP_ASSERT(_parent->_methodImpls[i].method);
					_methodImpls.push_back(_parent->_methodImpls[i]);
				}
				else
				{
					_methodImpls.push_back({ nullptr, nullptr, i /*, nullptr*/});
					++nullVtableSlotCount;
				}
				continue;
			}
			const Il2CppType* implType = FindImplType(overideMethodDef);
			const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(overideMethodDef->nameIndex);
			uint16_t slot = i;
			_methodImpls.push_back({ overideMethodDef, implType, slot /*, methodName*/});
		}

		// il2cpp set vtable slot to nullptr if method is abstract, so we fill correct type and method
		if (nullVtableSlotCount > 0)
		{
			for (GenericClassMethod& gcm : _virtualMethods)
			{
				IL2CPP_ASSERT(gcm.method->slot != kInvalidIl2CppMethodSlot);
				VirtualMethodImpl& vmi = _methodImpls[gcm.method->slot];
				if (vmi.method == nullptr)
				{
					vmi.type = _type;
					vmi.method = gcm.method;
					//vmi.name = gcm.name;
					--nullVtableSlotCount;
				}
			}
			for (VTableSetUp* interf : _interfaces)
			{
				bool findInterf = false;
				for (RawInterfaceOffsetInfo& rioi : _interfaceOffsetInfos)
				{
					if (IsTypeEqual(interf->_type, rioi.type))
					{
						for (size_t i = 0; i < interf->_virtualMethods.size(); i++)
						{
							VirtualMethodImpl& vmi = _methodImpls[rioi.offset + i];
							if (vmi.method == nullptr)
							{
								GenericClassMethod& igcm = interf->_virtualMethods[i];
								const GenericClassMethod* implVirtualMethod = FindImplMethod(interf->_type, igcm.method);
								IL2CPP_ASSERT(implVirtualMethod);
								//vmi.name = igcm.name;
								vmi.type = implVirtualMethod->type;
								vmi.method = implVirtualMethod->method;
								--nullVtableSlotCount;
							}
						}
						findInterf = true;
						break;
					}
				}
				IL2CPP_ASSERT(findInterf);
			}
			IL2CPP_ASSERT(nullVtableSlotCount == 0);
		}

		IL2CPP_ASSERT(_typeDef->vtable_count == (uint16_t)_methodImpls.size());
	}

	void VTableSetUp::ApplyOverrideMethod(const GenericClassMethod* overrideParentMethod, const Il2CppMethodDefinition* overrideMethodDef, uint16_t checkOverrideMaxIdx)
	{
		IL2CPP_ASSERT(overrideParentMethod);
		if (overrideParentMethod)
		{
			IL2CPP_ASSERT(overrideParentMethod->method->slot != kInvalidIl2CppMethodSlot);
			//const_cast<Il2CppMethodDefinition*>(vm.method)->slot = overrideParentMethod->method->slot;
			uint16_t slotIdx = overrideParentMethod->method->slot;
			const Il2CppMethodDefinition* overrideAncestorMethod = _parent->_methodImpls[slotIdx].method;
			IL2CPP_ASSERT(overrideAncestorMethod);

			VirtualMethodImpl& curImpl = _methodImpls[slotIdx];
			curImpl.type = _type;
			curImpl.method = overrideMethodDef;
			// search hierarchy methods, find match method. 

			// check override parent virtual methods and
			for (uint16_t idx = 0; idx < checkOverrideMaxIdx; idx++)
			{
				VirtualMethodImpl& vmi = _methodImpls[idx];
				if (vmi.method == overrideAncestorMethod)
				{
					vmi.type = _type;
					vmi.method = overrideMethodDef;
				}
			}
		}
	}

	uint16_t VTableSetUp::FindDefaultOverrideExplicitInterfaceSlot(GenericClassMethod& gcm, const Uin16Set& explicitImplSlots, const std::vector<uint16_t>& implInterfaceOffsetIdxs)
	{
		uint16_t slot = kInvalidIl2CppMethodSlot;
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				if (explicitImplSlots.find(idx) != explicitImplSlots.end())
				{
					continue;
				}
				VirtualMethodImpl& vmi = _methodImpls[idx];
				if (IsOverrideMethod(_type, gcm.method, vmi.type, vmi.method))
				{
					//IL2CPP_ASSERT(impl.body.methodDef->slot == kInvalidIl2CppMethodSlot);
					vmi.type = _type;
					vmi.method = gcm.method;
					slot = idx;
				}
			}
		}
		return slot;
	}

	uint16_t VTableSetUp::FindExplicitOverrideInterfaceSlot(GenericClassMethod& gcm, const Int32ToUin16Map& explicitImplSlots)
	{
		auto it = explicitImplSlots.find(gcm.method->token);
		return it != explicitImplSlots.end() ? it->second : kInvalidIl2CppMethodSlot;
	}

	void VTableSetUp::InitInterfaceVTable(uint16_t& curOffset, std::vector<uint16_t>& implInterfaceOffsetIdxs)
	{
		for (VTableSetUp* intTree : _interfaces)
		{
			const Il2CppType* intType = intTree->_type;
			uint16_t overrideIntIdx;
			if (!FindType(_parent->_interfaceOffsetInfos, intType, overrideIntIdx))
			{
				implInterfaceOffsetIdxs.push_back((uint16_t)_interfaceOffsetInfos.size());
				_interfaceOffsetInfos.push_back({ intType, intTree, curOffset });
				// curOffset += (uint32_t)intTree->_virtualMethods.size();
				for (auto& vm : intTree->_virtualMethods)
				{
					_methodImpls.push_back({ vm.method, intType, curOffset++ /*, vm.name*/});
				}
			}
			else
			{
				implInterfaceOffsetIdxs.push_back(overrideIntIdx);
			}
		}
	}

	static bool IsExpliciteMethodNameMatch(const char* implMethodName, const Il2CppType* targetDeclaringType, const char* targetMethodName)
	{
		// end with .<methodName>
		std::string fullName;
		const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(targetDeclaringType);
		if (typeDef->namespaceIndex != kStringLiteralIndexInvalid)
		{
			fullName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
			fullName += ".";
		}
		const char* typeName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
		const char* genericQualifier = strchr(typeName, '`');
		if (genericQualifier)
		{
			fullName.append(typeName, genericQualifier);
		}
		else
		{
			fullName += typeName;
		}

		if (!std::strstr(implMethodName, fullName.c_str()))
		{
			return false;
		}
		
		size_t len1 = std::strlen(implMethodName);
		size_t len2 = std::strlen(targetMethodName);
		if (len1 < len2 + 1)
		{
			return false;
		}
		if (implMethodName[len1 - len2 - 1] != '.')
		{
			return false;
		}
		return strcmp(implMethodName + len1 - len2, targetMethodName) == 0;
	}

	void VTableSetUp::ApplyAOTInterfaceExplicitOverride(const std::vector<uint16_t>& implInterfaceOffsetIdxs, Int32ToUin16Map& explicitImplToken2Slots,
		const Il2CppType* intfType, const Il2CppType* implType, const Il2CppMethodDefinition* implMethod)
	{
		const char* name1 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(implMethod->nameIndex);
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			if (!il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(rioi.type, intfType))
			{
				continue;
			}

			for (uint16_t idx = 0, end = (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				GenericClassMethod& rvm = rioi.tree->_virtualMethods[idx];
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(rvm.method->nameIndex);
				if (!IsExpliciteMethodNameMatch(name1, intfType, name2))
				{
					continue;
				}
				if (IsOverrideMethodIgnoreName(implType, implMethod, rvm.type, rvm.method))
				{
					uint16_t slot = (uint16_t)(idx + rioi.offset);
					VirtualMethodImpl& ivmi = _methodImpls[slot];
					_explicitImplSlots.insert(slot);
					explicitImplToken2Slots.insert({ implMethod->token, slot });
					ivmi.type = implType;
					ivmi.method = implMethod;
					//ivmi.name = name1;
					return;
				}
			}
		}
	}

	void VTableSetUp::ApplyExplicitOverride(const std::vector<uint16_t>& implInterfaceOffsetIdxs, Int32ToUin16Map& explicitImplToken2Slots,
		const Il2CppType* declaringType, const Il2CppMethodDefinition* decalringMethod, const Il2CppType* implType, const Il2CppMethodDefinition* implMethod)
	{
		const char* name1 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(decalringMethod->nameIndex);
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			if (!il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(rioi.type, declaringType))
			{
				continue;
			}

			for (uint16_t idx = 0, end = (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				GenericClassMethod& rvm = rioi.tree->_virtualMethods[idx];
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(rvm.method->nameIndex);
				if (std::strcmp(name1, name2))
				{
					continue;
				}
				if (IsOverrideMethodIgnoreName(declaringType, decalringMethod, rvm.type, rvm.method))
				{
					uint16_t slot = (uint16_t)(idx + rioi.offset);
					VirtualMethodImpl& ivmi = _methodImpls[slot];
					_explicitImplSlots.insert(slot);
					explicitImplToken2Slots.insert({ implMethod->token, slot});
					ivmi.type = implType;
					ivmi.method = implMethod;
					//ivmi.name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(implMethod->nameIndex);
					return;
				}
			}
		}
		const VTableSetUp* containerTs = FindAncestorTypeTree(declaringType);
		if (containerTs)
		{
			for (int idx = (int)containerTs->_virtualMethods.size() - 1; idx >= 0; idx--)
			{
				const GenericClassMethod& rvm = containerTs->_virtualMethods[idx];
				const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(rvm.method->nameIndex);
				if (std::strcmp(name1, name2) != 0)
				{
					continue;
				}
				if (IsOverrideMethodIgnoreName(declaringType, decalringMethod, rvm.type, rvm.method))
				{
					VirtualMethodImpl& ivmi = _methodImpls[rvm.method->slot];
					_explicitImplSlots.insert(rvm.method->slot);
					explicitImplToken2Slots.insert({ implMethod->token, rvm.method->slot });
					ivmi.type = implType;
					ivmi.method = implMethod;
					//ivmi.name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(implMethod->nameIndex);
					return;
				}
			}
		}
		const Il2CppTypeDefinition* typeDefinition = GetUnderlyingTypeDefinition(declaringType);

		TEMP_FORMAT(errMsg, "VTableSetUp fail. explicit implemented method: %s::%s::%s can't be find in parent or any interface.",
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->namespaceIndex),
			il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->nameIndex),
			name1);
		il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
	}

	void VTableSetUp::ApplyTypeExplicitImpls(const Il2CppType* type, const VTableSetUp* tree, const std::vector<uint16_t>& implInterfaceOffsetIdxs, Int32ToUin16Map& explicitImplToken2Slots)
	{
		const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
		if (IsInterpreterType(typeDef))
		{
			const il2cpp::utils::dynamic_array<MethodImpl> explicitImpls = MetadataModule::GetImage(typeDef)->GetTypeMethodImplByTypeDefinition(typeDef);
			if (type->type != IL2CPP_TYPE_GENERICINST)
			{
				for (const MethodImpl& mi : explicitImpls)
				{
					ApplyExplicitOverride(implInterfaceOffsetIdxs, explicitImplToken2Slots, mi.declaration.containerType,
						mi.declaration.methodDef, mi.body.containerType, mi.body.methodDef);
				}
			}
			else
			{
				const Il2CppGenericClass* genericClass = type->data.generic_class;
				for (const MethodImpl& mi : explicitImpls)
				{
					const Il2CppType* containerType = il2cpp::metadata::GenericMetadata::InflateIfNeeded(mi.declaration.containerType, &genericClass->context, true);
					const Il2CppType* implType = TryInflateIfNeed(type, type->data.generic_class->type, mi.body.containerType);
					ApplyExplicitOverride(implInterfaceOffsetIdxs, explicitImplToken2Slots, containerType,
						mi.declaration.methodDef, implType, mi.body.methodDef);
				}
			}
		}
		else if (IsInterface(typeDef->flags))
		{
			// we only need process explicit impls in interface.
			// il2cpp doesn't provider any ways to get explicit impls in class.
			// so we can only try to find explicit impls by name matching.
			for (const GenericClassMethod& gcm : tree->_virtualMethods)
			{
				// only try to find explicit impls in private methods
				uint32_t flags = gcm.method->flags;
				if (!IsPrivateMethod(flags) || IsAbstractMethod(flags))
				{
					continue;
				}
				for (VTableSetUp* subIntf : tree->_interfaces)
				{
					ApplyAOTInterfaceExplicitOverride(implInterfaceOffsetIdxs, explicitImplToken2Slots, subIntf->_type,	tree->_type, gcm.method);
				}
			}
		}
	}

	void VTableSetUp::ComputeExplicitImpls(const std::vector<uint16_t>& implInterfaceOffsetIdxs, Int32ToUin16Map& explicitImplToken2Slots)
	{
		ApplyTypeExplicitImpls(_type, this, implInterfaceOffsetIdxs, explicitImplToken2Slots);
		
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			ApplyTypeExplicitImpls(rioi.type, rioi.tree, implInterfaceOffsetIdxs, explicitImplToken2Slots);
		}
	}

	void VTableSetUp::ComputeOverrideParentVirtualMethod(uint16_t& curOffset, const std::vector<uint16_t>& implInterfaceOffsetIdxs, Int32ToUin16Map& explicitImplToken2Slots)
	{
		const uint16_t startOffset = curOffset;
		// override parent virtual methods and interfaces
		for (auto& vm : _virtualMethods)
		{
			IL2CPP_ASSERT(vm.type == _type);
			uint16_t mflags = vm.method->flags;
			if (hybridclr::metadata::IsNewSlot(mflags))
			{
				uint16_t overrideSlotIdx = kInvalidIl2CppMethodSlot;
				if (IsSealed(mflags))
				{
					overrideSlotIdx = FindExplicitOverrideInterfaceSlot(vm, explicitImplToken2Slots);
					if (overrideSlotIdx == kInvalidIl2CppMethodSlot && IsPublicMethod(mflags))
					{
						overrideSlotIdx = FindDefaultOverrideExplicitInterfaceSlot(vm, _explicitImplSlots, implInterfaceOffsetIdxs);
					}
				}
				if (overrideSlotIdx != kInvalidIl2CppMethodSlot)
				{
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = overrideSlotIdx;
				}
				else
				{
					_methodImpls.push_back({ vm.method, _type, curOffset /*, vm.name*/});
					IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == curOffset);
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
					++curOffset;
				}
			}
			else
			{
				// It's impossible to define private virtual method in c#，but it's possible in cli.
				// so sometime can't find override in parent
				const GenericClassMethod* overrideParentMethod = _parent->FindImplMethod(_type, vm.method, false);
				if (overrideParentMethod)
				{
					IL2CPP_ASSERT(overrideParentMethod->method->slot != kInvalidIl2CppMethodSlot);
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = overrideParentMethod->method->slot;
					ApplyOverrideMethod(overrideParentMethod, vm.method, startOffset);
				}
				else
				{
					IL2CPP_ASSERT(metadata::IsPrivateMethod(mflags));
					_methodImpls.push_back({ vm.method, _type, curOffset /*, vm.name*/});
					IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == curOffset);
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
					++curOffset;
				}
			}
		}
	}

	void VTableSetUp::ComputeInterfaceOverrideByParentVirtualMethod(const std::vector<uint16_t>& implInterfaceOffsetIdxs)
	{
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				if (isExplicitImplInterfaceSlot(idx))
				{
					continue;
				}
				VirtualMethodImpl& vmi = _methodImpls[idx];
				// override by virtual method
				const GenericClassMethod* implVm = FindImplMethod(vmi.type, vmi.method, false);
				if (implVm)
				{
					vmi.type = implVm->type;
					vmi.method = implVm->method;
					//vmi.name = implVm->name;
				}
			}
		}
	}

	void VTableSetUp::ComputeInterpTypeVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		uint16_t curOffset = 0;
		if (_parent)
		{
			curOffset = (uint16_t)_parent->_methodImpls.size();
			_methodImpls = _parent->_methodImpls;
			_interfaceOffsetInfos = _parent->_interfaceOffsetInfos;
		}

		std::vector<uint16_t> implInterfaceOffsetIdxs;
		InitInterfaceVTable(curOffset, implInterfaceOffsetIdxs);
		Int32ToUin16Map explicitImplToken2Slots;
		ComputeExplicitImpls(implInterfaceOffsetIdxs, explicitImplToken2Slots);
		ComputeOverrideParentVirtualMethod(curOffset, implInterfaceOffsetIdxs, explicitImplToken2Slots);
		ComputeInterfaceOverrideByParentVirtualMethod(implInterfaceOffsetIdxs);
	}

}
}
