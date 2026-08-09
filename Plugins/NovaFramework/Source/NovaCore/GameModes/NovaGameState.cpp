// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaGameState.h"

#include "Net/UnrealNetwork.h"

ANovaGameState::ANovaGameState() {}

void ANovaGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANovaGameState, CurrentExperience);
}


const UNovaExperienceDefinition* ANovaGameState::GetCurrentExperienceChecked() const
{
	check(CurrentExperience != nullptr);
	return CurrentExperience;
}

void ANovaGameState::SetCurrentExperience(const UNovaExperienceDefinition* NewExperience)
{
	if (CurrentExperience == nullptr)
	{
		CurrentExperience = NewExperience;
		OnRep_CurrentExperience();
	}
}

void ANovaGameState::OnRep_CurrentExperience() {}
