// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "NovaPlayerState.generated.h"

class UNovaPlayerAttributeSet;
class UNovaVitalAttributeSet;
class UNovaAbilitySystemComponent;

UCLASS()
class NOVACORE_API ANovaPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ANovaPlayerState();

	//~AActor interface
	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;
	//~End of AActor interface

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	TObjectPtr<UNovaAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(Transient)
	TObjectPtr<UNovaVitalAttributeSet> VitalAttributeSet;

	UPROPERTY(Transient)
	TObjectPtr<UNovaPlayerAttributeSet> PlayerAttributeSet;
};
