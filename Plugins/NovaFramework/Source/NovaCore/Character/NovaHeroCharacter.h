// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NovaCharacter.h"
#include "NovaHeroCharacter.generated.h"

UCLASS()
class NOVACORE_API ANovaHeroCharacter : public ANovaCharacter
{
	GENERATED_BODY()

public:
	ANovaHeroCharacter();

	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	void InitializeHeroAbilitySystem();

protected:
	UPROPERTY()
	TObjectPtr<UNovaAbilitySystemComponent> AbilitySystemComponent;
};
