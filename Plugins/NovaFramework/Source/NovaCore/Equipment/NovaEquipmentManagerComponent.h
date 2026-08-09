// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NovaEquipmentList.h"
#include "Components/ActorComponent.h"
#include "NovaEquipmentManagerComponent.generated.h"

UCLASS()
class NOVACORE_API UNovaEquipmentManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UNovaEquipmentManagerComponent();

private:
	UPROPERTY(Replicated)
	FNovaEquipmentList EquipmentList;
};
