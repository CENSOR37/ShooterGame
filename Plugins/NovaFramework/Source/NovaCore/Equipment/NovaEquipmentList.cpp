// Copyright MeteeTanathip. All Rights Reserved.

#include "NovaEquipmentList.h"

void FNovaEquipmentList::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize) {}

void FNovaEquipmentList::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize) {}

void FNovaEquipmentList::PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize) {}

FNovaEquipmentEntry* FNovaEquipmentList::AddEntry(UNovaInventoryItemInstance* Instance)
{
	FNovaEquipmentEntry& NewEntry = Entries.AddDefaulted_GetRef();
	return &NewEntry;
}
