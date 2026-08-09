// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "NovaAttributeSet.h"
#include "NovaPlayerAttributeSet.generated.h"

/**
 *
 */
UCLASS()
class NOVACORE_API UNovaPlayerAttributeSet : public UNovaAttributeSet
{
	GENERATED_BODY()

public:
	UNovaPlayerAttributeSet();


	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing = OnRep_PrimaryWeaponLoadedAmmo)
	FGameplayAttributeData PrimaryWeaponLoadedAmmo;
	ATTRIBUTE_ACCESSORS(UNovaPlayerAttributeSet, PrimaryWeaponLoadedAmmo)

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing = OnRep_PrimaryWeaponReservedAmmo)
	FGameplayAttributeData PrimaryWeaponReservedAmmo;
	ATTRIBUTE_ACCESSORS(UNovaPlayerAttributeSet, PrimaryWeaponReservedAmmo)

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing = OnRep_SecondaryWeaponLoadedAmmo)
	FGameplayAttributeData SecondaryWeaponLoadedAmmo;
	ATTRIBUTE_ACCESSORS(UNovaPlayerAttributeSet, SecondaryWeaponLoadedAmmo)

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing = OnRep_SecondaryWeaponReservedAmmo)
	FGameplayAttributeData SecondaryWeaponReservedAmmo;
	ATTRIBUTE_ACCESSORS(UNovaPlayerAttributeSet, SecondaryWeaponReservedAmmo)

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing = OnRep_TertiaryWeaponLoadedAmmo)
	FGameplayAttributeData TertiaryWeaponLoadedAmmo;
	ATTRIBUTE_ACCESSORS(UNovaPlayerAttributeSet, TertiaryWeaponLoadedAmmo)

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing = OnRep_TertiaryWeaponReservedAmmo)
	FGameplayAttributeData TertiaryWeaponReservedAmmo;
	ATTRIBUTE_ACCESSORS(UNovaPlayerAttributeSet, TertiaryWeaponReservedAmmo)

protected:
	UFUNCTION()
	void OnRep_PrimaryWeaponLoadedAmmo(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_PrimaryWeaponReservedAmmo(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_SecondaryWeaponLoadedAmmo(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_SecondaryWeaponReservedAmmo(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TertiaryWeaponLoadedAmmo(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TertiaryWeaponReservedAmmo(const FGameplayAttributeData& OldValue);
};
