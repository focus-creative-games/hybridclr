#include "VTableSetup.h"

#include <algorithm>

#include "vm/GlobalMetadata.h"
#include "metadata/GenericMetadata.h"

#include "MetadataModule.h"

namespace huatuo
{
namespace metadata
{

	VTableSetUp* VTableSetUp::BuildByType(Il2CppType2TypeDeclaringTreeMap& cache, const Il2CppType* type)
	{
		auto it = cache.find(type);
		if (it != cache.end())
		{
			return it->second;
		}
		VTableSetUp* tdt = new (IL2CPP_MALLOC_ZERO(sizeof(VTableSetUp))) VTableSetUp();
		const Il2CppTypeDefinition* typeDef = GetUnderlyingTypeDefinition(type);
		const char* ns = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->namespaceIndex);
		const char* name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDef->nameIndex);
		const Il2CppType* parentType = nullptr;
		// FIXME. cache 
		if (typeDef->parentIndex != kInvalidIndex)
		{
			parentType = TryInflateIfNeed(type, il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDef->parentIndex));
		}
		tdt->_type = type;
		tdt->_typeDef = typeDef;
		tdt->_parent = parentType ? BuildByType(cache, parentType) : nullptr;
		tdt->_name = name;

		for (uint32_t i = 0; i < typeDef->interfaces_count; i++)
		{
			const Il2CppType* intType = TryInflateIfNeed(type, il2cpp::vm::GlobalMetadata::GetInterfaceFromOffset(typeDef, i));
			VTableSetUp* intf = BuildByType(cache, intType);
			tdt->_interfaces.push_back(intf);
		}

		for (uint32_t i = 0; i < typeDef->method_count; i++)
		{
			const Il2CppMethodDefinition* methodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(typeDef->methodStart + i);
			const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(methodDef->nameIndex);
			tdt->_methods.push_back(methodDef);
			if (huatuo::metadata::IsVirtualMethod(methodDef->flags))
			{
				tdt->_virtualMethods.push_back({ type, methodDef, methodName });
			}
		}
		if (huatuo::metadata::IsInterface(typeDef->flags))
		{
			if (tdt->IsInterType())
			{
				tdt->ComputInterfaceVtables();
			}
		}
		else
		{
			tdt->ComputVtables();
		}
		cache[type] = tdt;
		return tdt;
	}


	inline bool IsOverrideMethod(const GenericClassMethod& m1, const GenericClassMethod& m2)
	{
		return huatuo::metadata::IsOverrideMethod(m1.type, m1.method, m2.type, m2.method);
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

	void VTableSetUp::ComputInterfaceVtables()
	{
		IL2CPP_ASSERT(huatuo::metadata::IsInterface(_typeDef->flags));
		uint16_t slotIdx = 0;
		for (auto& vm : _virtualMethods)
		{
			const_cast<Il2CppMethodDefinition*>(vm.method)->slot = slotIdx++;
		}
	}

	void VTableSetUp::ComputVtables()
	{
		if (IsInterType())
		{
			ComputInterpTypeVtables();
		}
		else
		{
			ComputAotTypeVtables();
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
		IL2CPP_ASSERT(false);
		return nullptr;
	}

	void VTableSetUp::ComputAotTypeVtables()
	{
		for (uint16_t i = 0; i < _typeDef->interface_offsets_count; i++)
		{
			Il2CppInterfaceOffsetInfo ioi = il2cpp::vm::GlobalMetadata::GetInterfaceOffsetInfo(_typeDef, i);
			_interfaceOffsetInfos.push_back({ TryInflateIfNeed(_type, ioi.interfaceType), nullptr, (uint16_t)ioi.offset });
		}

		for (uint16_t i = 0; i < _typeDef->vtable_count; i++)
		{
			const Il2CppMethodDefinition* overideMethodDef = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromVTableSlot(_typeDef, i);
			if (overideMethodDef == nullptr)
			{
				_methodImpls.push_back({ nullptr, nullptr, i, "==null=="});
				continue;
			}
			const Il2CppType* implType = FindImplType(overideMethodDef);
			const char* methodName = il2cpp::vm::GlobalMetadata::GetStringFromIndex(overideMethodDef->nameIndex);
			uint16_t slot = i;
			_methodImpls.push_back({ overideMethodDef, implType, slot, methodName });
		}

		IL2CPP_ASSERT(_typeDef->vtable_count == (uint16_t)_methodImpls.size());
	}

	void VTableSetUp::ComputInterpTypeVtables()
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

		const std::vector<MethodImpl>& explictImpls = MetadataModule::GetImage(_typeDef)->GetTypeMethodImplByTypeDefinition(_typeDef);
		std::vector<GenericClassMethod*> implictVirMethods;
		// override parent virtual methods and interfaces
		for (auto& vm : _virtualMethods)
		{
			if (huatuo::metadata::IsNewSlot(vm.method->flags))
			{
				if (huatuo::metadata::IsPrivateMethod(vm.method->flags))
				{
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
					_methodImpls.push_back({ vm.method, _type, curOffset, vm.name });
					IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == curOffset);
					const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
					++curOffset;

					const MethodImpl* matchImpl = nullptr;
					for (const MethodImpl& exImpl : explictImpls)
					{
						if (IsOverrideMethod(&exImpl.body.containerType, exImpl.body.methodDef, vm.type, vm.method))
						{
							matchImpl = &exImpl;
							break;
						}
					}

					IL2CPP_ASSERT(matchImpl);

					bool overrideIntMethod = false;
					for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
					{
						RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];

						if (!il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(rioi.type, &matchImpl->declaration.containerType))
						{
							continue;
						}

						for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
						{
							VirtualMethodImpl& ivmi = _methodImpls[idx];
							if (IsOverrideMethod(&matchImpl->declaration.containerType, matchImpl->declaration.methodDef, ivmi.type, ivmi.method))
							{
								ivmi.type = vm.type;
								ivmi.method = vm.method;
								overrideIntMethod = true;
								break;
							}
						}
						if (overrideIntMethod)
						{
							break;
						}
					}
					IL2CPP_ASSERT(overrideIntMethod);
				}
				else
				{
					bool overrideSelfInterface = false;
					for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
					{
						RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
						for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
						{
							VirtualMethodImpl& vmi = _methodImpls[idx];
							if (IsOverrideMethod(vm.type, vm.method, vmi.type, vmi.method))
							{
								//IL2CPP_ASSERT(impl.body.methodDef->slot == kInvalidIl2CppMethodSlot);
								vmi.type = vm.type;
								vmi.method = vm.method;
								if (!overrideSelfInterface && interfaceIdx >= (uint16_t)_parent->_interfaceOffsetInfos.size())
								{
									overrideSelfInterface = true;
									if (vm.method->slot == kInvalidIl2CppMethodSlot)
									{
										const_cast<Il2CppMethodDefinition*>(vm.method)->slot = idx;
									}
									else
									{
										IL2CPP_ASSERT(vm.method->slot == idx);
									}
								}
							}
						}
					}
					if (!overrideSelfInterface)
					{
						_methodImpls.push_back({ vm.method, _type, curOffset, vm.name });
						IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == curOffset);
						const_cast<Il2CppMethodDefinition*>(vm.method)->slot = curOffset;
						++curOffset;
					}
				}
			}
			else
			{
				// override parent virtual methods and interfaces
				// TODO what if not find override ???
				IL2CPP_ASSERT(_parent);

				// find override parent virtual methods
				bool find = false;
				for (VTableSetUp* curTdt = _parent; curTdt && !find; curTdt = curTdt->_parent)
				{
					for (int idx = (int)curTdt->_virtualMethods.size() - 1; idx >= 0; idx--)
					{
						GenericClassMethod& pvm = curTdt->_virtualMethods[idx];
						if (huatuo::metadata::IsOverrideMethod(_type, vm.method, pvm.type, pvm.method))
						{
							IL2CPP_ASSERT(vm.method->slot == kInvalidIl2CppMethodSlot || vm.method->slot == pvm.method->slot);
							const_cast<Il2CppMethodDefinition*>(vm.method)->slot = pvm.method->slot;
							find = true;
							break;
						}
					}
				}
				IL2CPP_ASSERT(find);
				IL2CPP_ASSERT(vm.method->slot != kInvalidIl2CppMethodSlot);

				uint16_t slotIdx = vm.method->slot;
				const Il2CppMethodDefinition* overrideAncestorMethod = _parent->_methodImpls[slotIdx].method;

				VirtualMethodImpl& curImpl = _methodImpls[slotIdx];
				curImpl.type = _type;
				curImpl.method = vm.method;
				// search hierarchy methods, find match method. 

				// check override parent virtual methods and
				for (uint16_t idx = 0; idx < checkOverrideMaxIdx; idx++)
				{
					VirtualMethodImpl& vmi = _methodImpls[idx];
					if (vmi.method == overrideAncestorMethod)
					{
						vmi.type = _type;
						vmi.method = vm.method;
					}
					//if (!vmi.method)
					//{
					//	continue;
					//}
					//if (vmi.method->slot == slotIdx)
					//{
					//	vmi.type = _type;
					//	vmi.method = vm.method;
					//}
				}

				// check override implicite implements interface
				for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
				{
					RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
					for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
					{
						VirtualMethodImpl& vmi = _methodImpls[idx];
						if (IsOverrideMethod(vm.type, vm.method, vmi.type, vmi.method))
						{
							//IL2CPP_ASSERT(impl.body.methodDef->slot == kInvalidIl2CppMethodSlot);
							vm.type = vm.type;
							vm.method = vm.method;
						}
					}
				}
			}
		}

		for (uint16_t interfaceIdx : implInterfaceOffsetIdxs)
		{
			RawInterfaceOffsetInfo& rioi = _interfaceOffsetInfos[interfaceIdx];
			for (uint16_t idx = rioi.offset, end = rioi.offset + (uint16_t)rioi.tree->_virtualMethods.size(); idx < end; idx++)
			{
				VirtualMethodImpl& vmi = _methodImpls[idx];
				if (vmi.type != rioi.type)
				{
					continue;
				}

				bool findOverride = false;
				for (VTableSetUp* cur = _parent; cur && !findOverride; cur = cur->_parent)
				{
					for (auto& vm : cur->_virtualMethods)
					{
						if (IsOverrideMethod(vm.type, vm.method, vmi.type, vmi.method))
						{
							//IL2CPP_ASSERT(impl.body.methodDef->slot == kInvalidIl2CppMethodSlot);
							vmi.type = vm.type;
							vmi.method = vm.method;
							findOverride = true;
							break;
						}
					}
				}
				IL2CPP_ASSERT(findOverride);
			}
		}

	}

}
}
