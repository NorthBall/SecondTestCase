// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SecondTestCase : ModuleRules
{
	public SecondTestCase(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay",
			"GameplayAbilities", "GameplayTasks",
			"AIModule"
		});
	}
}