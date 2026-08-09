// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NovaExperienceDefinition.h"
#include "NovaGameMode.generated.h"

class UNovaPawnData;

UCLASS()
class NOVACORE_API ANovaGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ANovaGameMode();

	//~AGameModeBase interface
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
	virtual void InitGameState() override;

protected:
	virtual void FinishRestartPlayer(AController* NewPlayer, const FRotator& StartRotation) override;

public:
	//~End of AGameModeBase interfaces

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Nova)
	TObjectPtr<UNovaExperienceDefinition> ExperienceDefinition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Nova)
	FTransform InitialPlayerTransform;
};
