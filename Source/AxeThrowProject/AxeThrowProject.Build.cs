// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AxeThrowProject : ModuleRules
{
	public AxeThrowProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
