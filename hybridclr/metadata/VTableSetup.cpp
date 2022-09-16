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
		VTableSetUp* tdt = new (IL2CPP_MALLOC_ZERO(sizeof(VTableSetUp))) VTableSetUp();
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

		tdt->_methods = genericType->_methods;
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
			tdt->_methodImpls.push_back({ vmi.method, declaringType, vmi.slot, vmi.name });
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
		VTableSetUp* tdt = new (IL2CPP_MALLOC_ZERO(sizeof(VTableSetUp))) VTableSetUp();
		const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
		const char* ns = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
		const char* name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
		const Il2CppType* parentType = nullptr;
		// FIXME. cache 
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
			tdt->_methods.push_back(methodDef);
			if (hybridclr::metadata::IsVirtualMethod(methodDef->flags))
			{
				tdt->_virtualMethods.push_back({ type, methodDef, methodName });
			}
		}
		if (hybridclr::metadata::IsInterface(typeDef->flags))
		{
			if (tdt->IsInterType())
			{
				tdt->ComputInterfaceVtables(cache);
			}
		}
		else
		{
			tdt->ComputVtables(cache);
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


	bool FindType(std::vector<RawInterfaceOffsetInfo>& interfaceOffsetInfos, const Il2CppType* type, uint16_t& resultIdx)
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

	void VTableSetUp::ComputInterfaceVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		IL2CPP_ASSERT(hybridclr::metadata::IsInterface(_typeDef->flags));
		uint16_t slotIdx = 0;
		for (auto& vm : _virtualMethods)
		{
			Il2CppMethodDefinition* methodDef = const_cast<Il2CppMethodDefinition*>(vm.method);
			IL2CPP_ASSERT(methodDef->slot == slotIdx);
			slotIdx++;
		}
	}

	void VTableSetUp::ComputVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		if (IsInterType())
		{
			ComputInterpTypeVtables(cache);
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
		}
		RaiseExecutionEngineException("");
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
					_methodImpls.push_back({ nullptr, nullptr, i, nullptr });
					++nullVtableSlotCount;
				}
				continue;
			}
			const Il2CppType* implType = FindImplType(overideMethodDef);
			const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(overideMethodDef->nameIndex);
			uint16_t slot = i;
			_methodImpls.push_back({ overideMethodDef, implType, slot, methodName });
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
					vmi.name = gcm.name;
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
								vmi.name = igcm.name;
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

	void VTableSetUp::ApplyOverrideMethod(const GenericClassMethod* overrideParentMethod, const Il2CppMethodDefinition* overrideMethodDef, uint16_t checkOverrideMaxIdx, std::vector<uint16_t>& implInterfaceOffsetIdxs)
	{
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

		// check override implicite implements interface
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				VirtualMethodImpl& vmi = _methodImpls[idx];
				if (IsOverrideMethod(_type, overrideMethodDef, vmi.type, vmi.method))
				{
					//IL2CPP_ASSERT(impl.body.methodDef->slot == kInvalidIl2CppMethodSlot);
					vmi.type = _type;
					vmi.method = overrideMethodDef;
				}
			}
		}
	}

	void VTableSetUp::ComputInterpTypeVtables(Il2CppType2TypeDeclaringTreeMap& cache)
	{
		uint16_t curOffset = 0;
		if (_parent)
		{
			curOffset = (uint16_t)_parent->_methodImpls.size();
			_methodImpls = _parent->_methodImpls;
			_interfaceOffsetInfos = _parent->_interfaceOffsetInfos;
		}

		uint16_t parentMaxVtableIdx = curOffset;

		std::vector<uint16_t> implInterfaceOffsetIdxs;
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
					_methodImpls.push_back({ vm.method, intType, curOffset++, vm.name });
				}
			}
			else
			{
				implInterfaceOffsetIdxs.push_back(overrideIntIdx);
			}
		}

		uint16_t checkOverrideMaxIdx = (uint16_t)curOffset;

		// override parent virtual methods and interfaces
		for (auto& vm : _virtualMethods)
		{
			IL2CPP_ASSERT(vm.type == _type);
			uint16_t mflags = vm.method->flags;
			if (hybridclr::metadata::IsNewSlot(mflags))
			{
				_methodImpls.push_back({ vm.method, _type, curOffset, vm.name });
				IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == curOffset);
				const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
				++curOffset;
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
					ApplyOverrideMethod(overrideParentMethod, vm.method, checkOverrideMaxIdx, implInterfaceOffsetIdxs);
				}
				else
				{
					IL2CPP_ASSERT(metadata::IsPrivateMethod(mflags));
					_methodImpls.push_back({ vm.method, _type, curOffset, vm.name });
					IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == curOffset);
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
					++curOffset;
				}
			}
		}

		// interface override by 
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				VirtualMethodImpl& vmi = _methodImpls[idx];
				if (!il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(vmi.type, rioi.type))
				{
					continue;
				}

				// override by virtual method
				const GenericClassMethod* implVm = FindImplMethod(vmi.type, vmi.method, false);
				if (implVm)
				{
					vmi.type = implVm->type;
					vmi.method = implVm->method;
					vmi.name = implVm->name;
				}
			}
		}

		const std::vector<MethodImpl>& explicitImpls = MetadataModule::GetImage(_typeDef)->GetTypeMethodImplByTypeDefinition(_typeDef);
		for (const MethodImpl& mi : explicitImpls)
		{
			bool findOverride = false;
			const char* name1 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(mi.declaration.methodDef->nameIndex);
			for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
			{
				RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
				if (!il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(rioi.type, &mi.declaration.containerType))
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
					if (IsOverrideMethodIgnoreName(&mi.declaration.containerType, mi.declaration.methodDef, rvm.type, rvm.method))
					{
						VirtualMethodImpl& ivmi = _methodImpls[idx + rioi.offset];
						ivmi.type = _type;
						ivmi.method = mi.body.methodDef;
						ivmi.name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(mi.body.methodDef->nameIndex);
						findOverride = true;
						break;
					}
				}
				if (findOverride)
				{
					break;
				}
			}
			if (!findOverride)
			{
				const VTableSetUp* containerTs = FindAncestorTypeTree(&mi.declaration.containerType);
				if (containerTs != nullptr)
				{
					for (int idx = (int)containerTs->_virtualMethods.size() - 1; idx >= 0; idx--)
					{
						const GenericClassMethod& rvm = containerTs->_virtualMethods[idx];
						const char* name2 = il2cpp::vm::GlobalMetadata::GetStringFromIndex(rvm.method->nameIndex);
						if (std::strcmp(name1, name2))
						{
							continue;
						}
						if (IsOverrideMethodIgnoreName(&mi.declaration.containerType, mi.declaration.methodDef, rvm.type, rvm.method))
						{
							for (VirtualMethodImpl& ivmi : _methodImpls)
							{
								if (ivmi.method->slot == rvm.method->slot)
								{
									ivmi.type = _type;
									ivmi.method = mi.body.methodDef;
									ivmi.name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(mi.body.methodDef->nameIndex);
									findOverride = true;
								}
							}
							break;
						}
					}
				}
			}
			if (!findOverride)
			{
				const Il2CppTypeDefinition* typeDefinition = GetUnderlyingTypeDefinition(&mi.declaration.containerType);

				TEMP_FORMAT(errMsg, "VTableSetUp fail. explicit implemented method: %s::%s::%s can't be find in parent or any interface.",
					il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->namespaceIndex),
					il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->nameIndex),
					name1);
				il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetExecutionEngineException(errMsg));
			}
		}

		// check not impl interface method
		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			for (uint16_t idx = 0, end = (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				VirtualMethodImpl& ivmi = _methodImpls[idx + rioi.offset];
				if (ivmi.type == rioi.type)
				{
					//const Il2CppTypeDefinition* interType = GetUnderlyingTypeDefinition(rioi.type);
					//il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle((Il2CppMetadataMethodDefinitionHandle)ivmi.method);
					//const MethodBody* body = MetadataModule::GetImage(interType)->GetMethodBody(ivmi.method->token);

				}
			}
		}
	}

}
}
