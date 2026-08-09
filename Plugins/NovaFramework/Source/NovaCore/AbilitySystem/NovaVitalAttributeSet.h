// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "NovaAttributeSet.h"
#include "NovaVitalAttributeSet.generated.h"

/**
 *
 */
UCLASS()
class NOVACORE_API UNovaVitalAttributeSet : public UNovaAttributeSet
{
	GENERATED_BODY()

public:
	UNovaVitalAttributeSet();

	ATTRIBUTE_ACCESSORS(UNovaVitalAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UNovaVitalAttributeSet, MaxHealth);

protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Nova|Health", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Nova|Health", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
};
