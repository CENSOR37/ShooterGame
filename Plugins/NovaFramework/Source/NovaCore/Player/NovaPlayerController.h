// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NovaPlayerController.generated.h"

class UNovaInventoryManagerComponent;

UCLASS()
class NOVACORE_API ANovaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANovaPlayerController();

protected:
	UPROPERTY()
	TObjectPtr<UNovaInventoryManagerComponent> InventoryManagerComponent;
};
