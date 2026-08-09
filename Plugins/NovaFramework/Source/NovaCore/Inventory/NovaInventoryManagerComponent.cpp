// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaInventoryManagerComponent.h"

#include "NovaInventoryItemDefinition.h"
#include "NovaInventoryItemInstance.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"

FString FNovaInventoryEntry::GetDebugString()
{
	return FString::Printf(TEXT("%s"), *GetNameSafe(Instance));
}

void FNovaInventoryList::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize)
{
	for (int32 Index : AddedIndices)
	{
		FNovaInventoryEntry& Entry = Entries[Index];
		UE_LOG(LogTemp, Log, TEXT("PostReplicatedAdd: %s"), *GetNameSafe(Entry.Instance));
	}
}

void FNovaInventoryList::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize)
{
	for (int32 Index : RemovedIndices)
	{
		FNovaInventoryEntry& Entry = Entries[Index];
		UE_LOG(LogTemp, Log, TEXT("PreReplicatedRemove: %s"), *Entry.GetDebugString());
	}
}

void FNovaInventoryList::PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize)
{
	for (int32 Index : ChangedIndices)
	{
		FNovaInventoryEntry& Entry = Entries[Index];
		// print debug message
		UE_LOG(LogTemp, Log, TEXT("PostReplicatedChange: %s"), *Entry.GetDebugString());
	}
}

UNovaInventoryItemInstance* FNovaInventoryList::AddEntry(TSubclassOf<UNovaInventoryItemDefinition> ItemDef)
{
	UNovaInventoryItemInstance* Result = nullptr;

	check(ItemDef != nullptr);
	check(OwnerComponent);

	AActor* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority());

	FNovaInventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Instance = NewObject<UNovaInventoryItemInstance>(OwnerComponent->GetOwner()); //@TODO: Using the actor instead of component as the outer due to UE-127172
	Result = NewEntry.Instance;

	MarkItemDirty(NewEntry);

	return Result;
}

void FNovaInventoryList::RemoveEntry(UNovaInventoryItemInstance* Instance)
{
	for (auto EntryIt = Entries.CreateIterator(); EntryIt; ++EntryIt)
	{
		FNovaInventoryEntry& Entry = *EntryIt;
		if (Entry.Instance == Instance)
		{
			EntryIt.RemoveCurrent();
			MarkArrayDirty();
		}
	}
}

UNovaInventoryManagerComponent::UNovaInventoryManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, InventoryList(this)
{
	SetIsReplicatedByDefault(true);
	bReplicateUsingRegisteredSubObjectList = true;
}

void UNovaInventoryManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UNovaInventoryManagerComponent, InventoryList);
}

UNovaInventoryItemInstance* UNovaInventoryManagerComponent::AddItemDefinition(TSubclassOf<UNovaInventoryItemDefinition> ItemDef)
{
	UNovaInventoryItemInstance* Result = nullptr;
	if (ItemDef != nullptr)
	{
		Result = InventoryList.AddEntry(ItemDef);

		AddReplicatedSubObjectItemInstance(Result);
	}
	return Result;
}

void UNovaInventoryManagerComponent::AddItemInstance(UNovaInventoryItemInstance* ItemInstance) {}

void UNovaInventoryManagerComponent::RemoveItemInstance(UNovaInventoryItemInstance* ItemInstance) {}

void UNovaInventoryManagerComponent::AddReplicatedSubObjectItemInstance(UNovaInventoryItemInstance* ItemInstance)
{
	if (IsUsingRegisteredSubObjectList() && IsReadyForReplication() && IsValid(ItemInstance))
	{
		AddReplicatedSubObject(ItemInstance);
	}
}

void UNovaInventoryManagerComponent::RemoveReplicatedSubObjectItemInstance(UNovaInventoryItemInstance* ItemInstance)
{
	if (ItemInstance && IsUsingRegisteredSubObjectList())
	{
		RemoveReplicatedSubObject(ItemInstance);
	}
}
