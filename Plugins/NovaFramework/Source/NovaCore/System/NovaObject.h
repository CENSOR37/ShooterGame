// Copyright MeteeTanathip. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NovaObject.generated.h"

/**
 * NovaObject add some helper functions to UObject
 * Only support actor as outer object for now
 */
UCLASS()
class NOVACORE_API UNovaObject : public UObject
{
	GENERATED_BODY()

public:
	UNovaObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// ~Begin UObject Interface
	virtual UWorld* GetWorld() const override;
	virtual bool IsSupportedForNetworking() const override { return true; }
	virtual int32 GetFunctionCallspace(UFunction* Function, FFrame* Stack) override;
	virtual bool CallRemoteFunction(UFunction* Function, void* Parms, FOutParmRec* OutParms, FFrame* Stack) override;
	// ~End UObject Interface

	// additional interface, not part of UObject
	virtual bool HasAuthority() const;
	virtual ENetMode GetNetMode() const;
	virtual ENetRole GetLocalRole() const;
	virtual ENetRole GetRemoteRole() const;
};
