// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FNovaCoreModule"

class FNovaCoreModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
	};

	virtual void ShutdownModule() override
	{
	};
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNovaCoreModule, NovaCore)
