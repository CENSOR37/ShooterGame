// Copyright MeteeTanathip. All Rights Reserved.

#include "NovaObject.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(NovaObject)

UNovaObject::UNovaObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {}

UWorld* UNovaObject::GetWorld() const
{
	if (const UObject* MyOuter = GetOuter())
	{
		return MyOuter->GetWorld();
	}
	return nullptr;
}

int32 UNovaObject::GetFunctionCallspace(UFunction* Function, FFrame* Stack)
{
	if (AActor* OuterActor = GetTypedOuter<AActor>())
	{
		return OuterActor->GetFunctionCallspace(Function, Stack);
	}

	return FunctionCallspace::Local;
}

bool UNovaObject::CallRemoteFunction(UFunction* Function, void* Parms, FOutParmRec* OutParms, FFrame* Stack)
{
	AActor* ActorOwner = GetTypedOuter<AActor>();

	if (UNetDriver* NetDriver = ActorOwner ? ActorOwner->GetNetDriver() : nullptr)
	{
		NetDriver->ProcessRemoteFunction(ActorOwner, Function, Parms, OutParms, Stack, this);
		return true;
	}

	return Super::CallRemoteFunction(Function, Parms, OutParms, Stack);
}

bool UNovaObject::HasAuthority() const
{
	return GetLocalRole() == ROLE_Authority;
}

ENetMode UNovaObject::GetNetMode() const
{
	if (AActor* OuterActor = GetTypedOuter<AActor>())
	{
		return OuterActor->GetNetMode();
	}

	return NM_Standalone;
}

ENetRole UNovaObject::GetLocalRole() const
{
	if (AActor* OuterActor = GetTypedOuter<AActor>())
	{
		return OuterActor->GetLocalRole();
	}

	return ROLE_None;
}

ENetRole UNovaObject::GetRemoteRole() const
{
	if (AActor* OuterActor = GetTypedOuter<AActor>())
	{
		return OuterActor->GetRemoteRole();
	}

	return ROLE_None;
}
