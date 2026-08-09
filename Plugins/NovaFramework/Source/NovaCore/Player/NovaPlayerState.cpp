// Copyright MeteeTanathip. All Rights Reserved.

#include "NovaPlayerState.h"

#include "NovaCore/AbilitySystem/NovaAbilitySystemComponent.h"
#include "NovaCore/AbilitySystem/NovaPlayerAttributeSet.h"
#include "NovaCore/AbilitySystem/NovaVitalAttributeSet.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NovaPlayerState)

ANovaPlayerState::ANovaPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UNovaAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	VitalAttributeSet = CreateDefaultSubobject<UNovaVitalAttributeSet>("VitalAttributeSet");
	PlayerAttributeSet = CreateDefaultSubobject<UNovaPlayerAttributeSet>("PlayerAttributeSet");

	SetNetUpdateFrequency(100.0f);
}

void ANovaPlayerState::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void ANovaPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

UAbilitySystemComponent* ANovaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
