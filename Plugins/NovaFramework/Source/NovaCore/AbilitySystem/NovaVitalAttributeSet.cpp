// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaVitalAttributeSet.h"

#include "Net/UnrealNetwork.h"

UNovaVitalAttributeSet::UNovaVitalAttributeSet()
	: Health(100.0f)
	, MaxHealth(100.0f) {}

void UNovaVitalAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams Params{};
	Params.bIsPushBased = true;
	Params.Condition = COND_None;
	Params.RepNotifyCondition = REPNOTIFY_Always;

	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaVitalAttributeSet, Health, Params);
	DOREPLIFETIME_WITH_PARAMS_FAST(UNovaVitalAttributeSet, MaxHealth, Params);
}

void UNovaVitalAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaVitalAttributeSet, Health, OldValue);
}

void UNovaVitalAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNovaVitalAttributeSet, MaxHealth, OldValue);
}
