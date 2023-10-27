// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BMI_C : ModuleRules
{
	public BMI_C(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
