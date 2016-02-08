// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine.h>
#include "VoxelChunk.generated.h"


UCLASS( ClassGroup=Rendering, meta=(BlueprintSpawnableComponent) )
class UCubeVoxelChunk : public UMeshComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCubeVoxelChunk();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Create the actual mesh renderer for the renderer thread.
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
};
