// Copyright Metee Tanatip, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShooterGame : ModuleRules
{
    public ShooterGame(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "UMG",
            "Slate",
            "SlateCore",
            "NetCore",
            "NetCommon",
            "Networking",
            "GameplayTags",
            "GameplayTasks",
            "GameplayAbilities",
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "AIModule",
            "GameplayAbilities",
            "GameplayTasks",
            "GameplayTags",
            "EnhancedInput",
            "CommonUI",
        });
    }
}
