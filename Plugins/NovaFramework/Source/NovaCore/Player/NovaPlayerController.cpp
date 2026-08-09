// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaPlayerController.h"

#include "NovaCheatManager.h"
#include "Engine/World.h"
#include "NovaCore/Character/NovaCharacter.h"
#include "NovaCore/GameModes/NovaGameMode.h"
#include "NovaCore/Inventory/NovaInventoryManagerComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NovaPlayerController)

ANovaPlayerController::ANovaPlayerController()
{
	CheatClass = UNovaCheatManager::StaticClass();

	InventoryManagerComponent = CreateDefaultSubobject<UNovaInventoryManagerComponent>(TEXT("InventoryManagerComponent"));
}
