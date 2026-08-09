// Copyright Metee Tanatip, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShooterGameTarget : TargetRules
{
    public ShooterGameTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        bOverrideBuildEnvironment = true;
        bWithPushModel = true;

        ExtraModuleNames.AddRange(new string[] { "ShooterGame" });
    }
}
