using UnrealBuildTool;

public class NovaCore : ModuleRules
{
    public NovaCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks",
            "NetCore",
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
