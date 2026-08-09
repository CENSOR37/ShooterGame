// Copyright MeteeTanathip. All Rights Reserved.


#include "NovaGameMode.h"

#include "NovaGameState.h"
#include "NovaCore/Character/NovaPawnData.h"
#include "NovaCore/NovaLogChannels.h"
#include "NovaCore/AbilitySystem/NovaAbilitySet.h"
#include "NovaCore/AbilitySystem/NovaAbilitySystemComponent.h"
#include "NovaCore/Player/NovaPlayerController.h"
#include "NovaCore/Player/NovaPlayerState.h"

ANovaGameMode::ANovaGameMode()
{
	PlayerStateClass = ANovaPlayerState::StaticClass();
	PlayerControllerClass = ANovaPlayerController::StaticClass();
}

UClass* ANovaGameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	UNovaPawnData* PlayerPawnData = ExperienceDefinition ? ExperienceDefinition->GetPlayerPawnData() : nullptr;
	if (PlayerPawnData && PlayerPawnData->PawnClass)
	{
		return PlayerPawnData->PawnClass;
	}

	return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void ANovaGameMode::InitGameState()
{
	Super::InitGameState();

	if (ANovaGameState* NovaGameState = Cast<ANovaGameState>(GameState))
	{
		NovaGameState->SetCurrentExperience(ExperienceDefinition);
	}
}

void ANovaGameMode::FinishRestartPlayer(AController* NewPlayer, const FRotator& StartRotation)
{
	Super::FinishRestartPlayer(NewPlayer, StartRotation);

	//check(ExperienceDefinition);

	if (HasAuthority() && ExperienceDefinition)
	{
		if (ANovaPlayerState* NovaPS = NewPlayer->GetPlayerState<ANovaPlayerState>())
		{
			UNovaPawnData* PawnData = ExperienceDefinition->GetPlayerPawnData();
			UNovaAbilitySystemComponent* ASC = Cast<UNovaAbilitySystemComponent>(NovaPS->GetAbilitySystemComponent());
			if (PawnData && ASC)
			{
				FNovaAbilitySet_GrantedHandles GrantedHandles;
				for (const TObjectPtr<UNovaAbilitySet>& AbilitySet : PawnData->AbilitySets)
				{
					AbilitySet->GiveToAbilitySystem(ASC, &GrantedHandles);
				}
			}
		}
	}
}
