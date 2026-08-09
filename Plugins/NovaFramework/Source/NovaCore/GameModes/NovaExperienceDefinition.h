// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NovaExperienceDefinition.generated.h"

class UNovaPawnData;

/**
 * Minimal experience asset used to configure gameplay defaults for a match.
 */
UCLASS(BlueprintType, Const, Meta=(DisplayName="Nova Experience Definition"))
class NOVACORE_API UNovaExperienceDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UNovaExperienceDefinition();

	UFUNCTION()
	UNovaPawnData* GetPlayerPawnData() const;

protected:
	// Default pawn data used for players in this experience.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Nova|Experience")
	TObjectPtr<UNovaPawnData> PlayerPawnData;
};
