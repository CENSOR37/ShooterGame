// Copyright Metee Tanatip, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShooterGameEditorTarget : TargetRules
{
    public ShooterGameEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        bOverrideBuildEnvironment = true;
        bWithPushModel = true;

        ExtraModuleNames.AddRange(new string[] { "ShooterGame" });
    }
}
