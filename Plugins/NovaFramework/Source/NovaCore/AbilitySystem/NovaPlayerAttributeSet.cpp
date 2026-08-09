// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaPlayerAttributeSet.h"

#include "Net/UnrealNetwork.h"

UNovaPlayerAttributeSet::UNovaPlayerAttributeSet() {}

void UNovaPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams Params{};
	Params.bIsPushBased = true;
	Params.Condition = COND_None;
	Params.RepNotifyCondition = REPNOTIFY_Always;

	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaPlayerAttributeSet, PrimaryWeaponLoadedAmmo, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaPlayerAttributeSet, PrimaryWeaponReservedAmmo, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaPlayerAttributeSet, SecondaryWeaponLoadedAmmo, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaPlayerAttributeSet, SecondaryWeaponReservedAmmo, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaPlayerAttributeSet, TertiaryWeaponLoadedAmmo, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaPlayerAttributeSet, TertiaryWeaponReservedAmmo, Params);
}

void UNovaPlayerAttributeSet::OnRep_PrimaryWeaponLoadedAmmo(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaPlayerAttributeSet, PrimaryWeaponLoadedAmmo, OldValue);
}

void UNovaPlayerAttributeSet::OnRep_PrimaryWeaponReservedAmmo(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaPlayerAttributeSet, PrimaryWeaponReservedAmmo, OldValue);
}

void UNovaPlayerAttributeSet::OnRep_SecondaryWeaponLoadedAmmo(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaPlayerAttributeSet, SecondaryWeaponLoadedAmmo, OldValue);
}

void UNovaPlayerAttributeSet::OnRep_SecondaryWeaponReservedAmmo(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaPlayerAttributeSet, SecondaryWeaponReservedAmmo, OldValue);
}

void UNovaPlayerAttributeSet::OnRep_TertiaryWeaponLoadedAmmo(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaPlayerAttributeSet, TertiaryWeaponLoadedAmmo, OldValue);
}

void UNovaPlayerAttributeSet::OnRep_TertiaryWeaponReservedAmmo(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaPlayerAttributeSet, TertiaryWeaponReservedAmmo, OldValue);
}
