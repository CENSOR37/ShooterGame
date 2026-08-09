// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaEquipmentManagerComponent.h"

#include "Net/UnrealNetwork.h"


UNovaEquipmentManagerComponent::UNovaEquipmentManagerComponent()
	: EquipmentList(this)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UNovaEquipmentManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UNovaEquipmentManagerComponent, EquipmentList);
}
