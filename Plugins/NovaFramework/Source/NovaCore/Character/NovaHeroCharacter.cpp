// Copyright MeteeTanathip. All Rights Reserved.

#include "NovaHeroCharacter.h"

#include "NovaPawnData.h"
#include "Engine/World.h"
#include "NovaCore/AbilitySystem/NovaAbilitySet.h"
#include "NovaCore/AbilitySystem/NovaAbilitySystemComponent.h"
#include "NovaCore/GameModes/NovaGameMode.h"
#include "NovaCore/Player/NovaPlayerState.h"

ANovaHeroCharacter::ANovaHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ANovaHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitializeHeroAbilitySystem();
}

void ANovaHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitializeHeroAbilitySystem();
}

void ANovaHeroCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ANovaHeroCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ANovaHeroCharacter::InitializeHeroAbilitySystem()
{
	ANovaPlayerState* NovaPS = GetPlayerState<ANovaPlayerState>();
	if (UNovaAbilitySystemComponent* ASC = Cast<UNovaAbilitySystemComponent>(NovaPS ? NovaPS->GetAbilitySystemComponent() : nullptr))
	{
		AbilitySystemComponent = ASC;
		ASC->InitAbilityActorInfo(NovaPS, this);
	}
}
