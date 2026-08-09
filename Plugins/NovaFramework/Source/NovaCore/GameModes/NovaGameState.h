// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "NovaGameState.generated.h"

class UNovaExperienceDefinition;

UCLASS()
class NOVACORE_API ANovaGameState : public AGameState
{
	GENERATED_BODY()

public:
	ANovaGameState();

	const UNovaExperienceDefinition* GetCurrentExperienceChecked() const;
	void SetCurrentExperience(const UNovaExperienceDefinition* NewExperience);

private:
	UFUNCTION()
	void OnRep_CurrentExperience();

private:
	UPROPERTY(ReplicatedUsing=OnRep_CurrentExperience)
	TObjectPtr<const UNovaExperienceDefinition> CurrentExperience;
};
