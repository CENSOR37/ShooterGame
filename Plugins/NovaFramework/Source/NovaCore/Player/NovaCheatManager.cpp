// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaCheatManager.h"

#include "GameFramework/HUD.h"
#include "GameFramework/PlayerController.h"

UNovaCheatManager::UNovaCheatManager() {}

void UNovaCheatManager::CycleAbilitySystemDebug()
{
	APlayerController* PC = Cast<APlayerController>(GetOuterAPlayerController());

	if (PC && PC->MyHUD)
	{
		if (!PC->MyHUD->bShowDebugInfo || !PC->MyHUD->DebugDisplay.Contains(TEXT("AbilitySystem")))
		{
			PC->MyHUD->ShowDebug(TEXT("AbilitySystem"));
		}

		PC->ConsoleCommand(TEXT("AbilitySystem.Debug.NextCategory"));
	}
}
