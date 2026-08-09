// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "NovaCore//AbilitySystem/NovaAbilitySet.h"
#include "NovaCharacter.generated.h"

class UNovaPawnData;
class UNovaAbilitySystemComponent;

UCLASS()
class NOVACORE_API ANovaCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ANovaCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	void SetPawnData(const UNovaPawnData* InPawnData);

protected:
	UFUNCTION()
	virtual void OnRep_PawnData();

	UPROPERTY(EditInstanceOnly, ReplicatedUsing = OnRep_PawnData)
	TObjectPtr<const UNovaPawnData> PawnData;

private:
	FNovaAbilitySet_GrantedHandles GrantedHandles;
};
