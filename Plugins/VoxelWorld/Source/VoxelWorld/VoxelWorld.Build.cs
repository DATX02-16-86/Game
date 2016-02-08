// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VoxelWorld : ModuleRules
{
	public VoxelWorld(TargetInfo Target)
	{
		PublicIncludePaths.AddRange(new string[] { "VoxelWorld/Public" });
		PrivateIncludePaths.AddRange(new string[] { "VoxelWorld/Private" } );
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "ShaderCore" } );
	}
}
