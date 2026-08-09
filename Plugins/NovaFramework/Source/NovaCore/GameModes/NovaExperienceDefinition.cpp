// Copyright MeteeTanathip. All Rights Reserved.

#include "NovaExperienceDefinition.h"

UNovaExperienceDefinition::UNovaExperienceDefinition() {}

UNovaPawnData* UNovaExperienceDefinition::GetPlayerPawnData() const
{
	return PlayerPawnData.Get();
}
