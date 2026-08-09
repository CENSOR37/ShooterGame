// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "Logging/LogMacros.h"

class UObject;

NOVACORE_API DECLARE_LOG_CATEGORY_EXTERN(LogNova, Log, All);

NOVACORE_API DECLARE_LOG_CATEGORY_EXTERN(LogNovaAbilitySystem, Log, All);

NOVACORE_API FString GetClientServerContextString(UObject* ContextObject = nullptr);
