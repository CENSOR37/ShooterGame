#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"

namespace Nova
{
	template <typename T>
	T* Get(const AActor* Actor)
	{
		static_assert(TIsDerivedFrom<T, UActorComponent>::IsDerived, "T must derive from UActorComponent");

		if (IsValid(Actor))
		{
			return Actor->FindComponentByClass<T>();
		}

		return nullptr;
	}

	template <typename T>
	T* Get(const AActor* Actor, const FName Name)
	{
		static_assert(TIsDerivedFrom<T, UActorComponent>::IsDerived, "T must derive from UActorComponent");

		if (IsValid(Actor))
		{
			if (Name.IsNone())
			{
				return Actor->FindComponentByClass<T>();
			}

			for (UActorComponent* Comp : Actor->GetComponents())
			{
				if (Comp == nullptr)
					continue;

				if (Comp->GetFName() != Name)
					continue;

				if (T* TypedComp = Cast<T>(Comp))
					return TypedComp;
			}
		}

		return nullptr;
	}
}
