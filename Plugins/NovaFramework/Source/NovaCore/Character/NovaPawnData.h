// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NovaPawnData.generated.h"

class UNovaAbilitySet;

/**
 * UNovaPawnData
 *
 *	Non-mutable data asset that contains properties used to define a pawn.
 */
UCLASS(BlueprintType, Const, Meta = (DisplayName = "Nova Pawn Data", ShortTooltip = "Data asset used to define a Pawn."))
class NOVACORE_API UNovaPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UNovaPawnData();

public:
	// Class to instantiate for this pawn (should usually derive from ANovaPawn or ANovaCharacter).
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Nova|Pawn")
	TSubclassOf<APawn> PawnClass;

	// Ability sets to grant to this pawn's ability system.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Nova|Abilities")
	TArray<TObjectPtr<UNovaAbilitySet>> AbilitySets;

	// TODO: implement camera mode?
	// Default camera mode used by player controlled pawns.
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Nova|Camera")
	// TSubclassOf<UNovaCameraMode> DefaultCameraMode;
};
