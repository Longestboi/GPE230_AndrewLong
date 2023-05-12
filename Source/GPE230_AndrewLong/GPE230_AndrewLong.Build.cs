// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GPE230_AndrewLong : ModuleRules
{
	public GPE230_AndrewLong(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
