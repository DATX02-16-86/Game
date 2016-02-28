// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine.h>
#include <World/World.h>
#include "VoxelTerrain.generated.h"

UCLASS()
class AVoxelTerrain : public AActor
{
	GENERATED_BODY()

	generator::World world;
	
public:	
	// Sets default values for this actor's properties
	AVoxelTerrain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
};
