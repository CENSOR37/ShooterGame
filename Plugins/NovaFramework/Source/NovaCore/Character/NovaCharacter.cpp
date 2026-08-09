// Copyright MeteeTanathip. All Rights Reserved.

#include "NovaCharacter.h"
#include "NovaPawnData.h"
#include "Net/UnrealNetwork.h"
#include "NovaCore/NovaLogChannels.h"
#include "NovaCore/AbilitySystem/NovaAbilitySet.h"
#include "NovaCore/AbilitySystem/NovaAbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NovaGameMode)

ANovaCharacter::ANovaCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ANovaCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANovaCharacter, PawnData);
}

UAbilitySystemComponent* ANovaCharacter::GetAbilitySystemComponent() const
{
	return nullptr; // do implement in sub-class
}

void ANovaCharacter::SetPawnData(const UNovaPawnData* InPawnData)
{
	check(InPawnData);

	if (this->GetLocalRole() != ROLE_Authority) { return; }

	if (PawnData)
	{
		UE_LOG(LogNova, Error, TEXT("Trying to set PawnData [%s] on pawn [%s] that already has valid PawnData [%s]."), *GetNameSafe(InPawnData), *GetNameSafe(this), *GetNameSafe(PawnData));
		return;
	}

	PawnData = InPawnData;
	OnRep_PawnData();

	ForceNetUpdate();
}

void ANovaCharacter::OnRep_PawnData() {}
