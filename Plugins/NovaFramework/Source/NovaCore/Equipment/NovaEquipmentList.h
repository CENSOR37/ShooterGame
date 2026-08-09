// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "NovaCore/AbilitySystem/NovaAbilitySet.h"
#include "NovaEquipmentList.generated.h"

class UNovaInventoryItemInstance;
class UNovaEquipmentManagerComponent;

/** A single piece of applied equipment */
USTRUCT(BlueprintType)
struct FNovaEquipmentEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

	FNovaEquipmentEntry() {}

	UPROPERTY()
	TObjectPtr<UObject> Instance = nullptr;

	UPROPERTY(NotReplicated)
	FNovaAbilitySet_GrantedHandles GrantedHandles;
};

/** List of applied equipment */
USTRUCT(BlueprintType)
struct FNovaEquipmentList : public FFastArraySerializer
{
	GENERATED_BODY()

	FNovaEquipmentList()
		: ManagerComponent(nullptr) {}

	FNovaEquipmentList(UNovaEquipmentManagerComponent* InManagerComponent)
		: ManagerComponent(InManagerComponent) {}

public:
	void PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	void PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize);

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FNovaEquipmentEntry, FNovaEquipmentList>(Entries, DeltaParms, *this);
	}

	FNovaEquipmentEntry* AddEntry(UNovaInventoryItemInstance* Instance);

	UPROPERTY()
	TArray<FNovaEquipmentEntry> Entries;

	UPROPERTY(NotReplicated)
	TObjectPtr<UNovaEquipmentManagerComponent> ManagerComponent;
};

template <>
struct TStructOpsTypeTraits<FNovaEquipmentList> : public TStructOpsTypeTraitsBase2<FNovaEquipmentList>
{
	enum { WithNetDeltaSerializer = true };
};
