// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "NovaCheatManager.generated.h"

UCLASS(config = Game, Within = PlayerController, MinimalAPI)
class UNovaCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UNovaCheatManager();

	UFUNCTION(Exec)
	virtual void CycleAbilitySystemDebug();
};
