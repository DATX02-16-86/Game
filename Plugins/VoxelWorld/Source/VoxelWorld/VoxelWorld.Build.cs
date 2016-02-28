// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VoxelWorld : ModuleRules
{
    private string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

	public VoxelWorld(TargetInfo Target)
	{
		PublicIncludePaths.AddRange(new string[] { "VoxelWorld/Public" });
		PrivateIncludePaths.AddRange(new string[] { "VoxelWorld/Private", "../../../../Code/Tritium/Code/Core", "../../../../Code/Generator/Code" } );
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "ShaderCore" } );

		if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
		{
			PublicAdditionalLibraries.AddRange(new string[] { Path.Combine(ModulePath, "../Generator/Generator.lib"), Path.Combine(ModulePath, "../Tritium/TritiumCore.lib") });
		}
		else
		{
			PublicAdditionalLibraries.AddRange(new string[] { Path.Combine(ModulePath, "../Generator/libGenerator.a"), Path.Combine(ModulePath, "../Tritium/libTritiumCore.a") });
		}
    }
}
