// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "NovaInventoryManagerComponent.generated.h"

class UNovaInventoryItemInstance;
class UNovaInventoryItemDefinition;
class UNovaInventoryManagerComponent;
struct FNovaInventoryList;

/** A single entry in an inventory */
USTRUCT(BlueprintType)
struct FNovaInventoryEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

	FNovaInventoryEntry() {}

	FString GetDebugString();

private:
	friend FNovaInventoryList;
	friend UNovaInventoryManagerComponent;

	UPROPERTY()
	TObjectPtr<UNovaInventoryItemInstance> Instance = nullptr;
};

/** List of inventory items */
USTRUCT(BlueprintType)
struct FNovaInventoryList : public FFastArraySerializer
{
	GENERATED_BODY()

	FNovaInventoryList()
		: OwnerComponent(nullptr) {}

	FNovaInventoryList(UActorComponent* InOwnerComponent)
		: OwnerComponent(InOwnerComponent) {}

public:
	//~FFastArraySerializer contract
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	void PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize);
	void PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize);
	//~End of FFastArraySerializer contract

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FNovaInventoryEntry, FNovaInventoryList>(Entries, DeltaParms, *this);
	}

	UNovaInventoryItemInstance* AddEntry(TSubclassOf<UNovaInventoryItemDefinition> ItemDef);
	void RemoveEntry(UNovaInventoryItemInstance* Instance);

private:
	friend UNovaInventoryManagerComponent;

private:
	UPROPERTY()
	TArray<FNovaInventoryEntry> Entries;

	UPROPERTY(NotReplicated)
	TObjectPtr<UActorComponent> OwnerComponent;
};

template <>
struct TStructOpsTypeTraits<FNovaInventoryList> : public TStructOpsTypeTraitsBase2<FNovaInventoryList>
{
	enum { WithNetDeltaSerializer = true };
};

/** Component that manages an inventory */
UCLASS()
class NOVACORE_API UNovaInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UNovaInventoryManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category=Inventory)
	UNovaInventoryItemInstance* AddItemDefinition(TSubclassOf<UNovaInventoryItemDefinition> ItemDef);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category=Inventory)
	void AddItemInstance(UNovaInventoryItemInstance* ItemInstance);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category=Inventory)
	void RemoveItemInstance(UNovaInventoryItemInstance* ItemInstance);

private:
	void AddReplicatedSubObjectItemInstance(UNovaInventoryItemInstance* ItemInstance);
	void RemoveReplicatedSubObjectItemInstance(UNovaInventoryItemInstance* ItemInstance);

private:
	UPROPERTY(Replicated)
	FNovaInventoryList InventoryList;
};
