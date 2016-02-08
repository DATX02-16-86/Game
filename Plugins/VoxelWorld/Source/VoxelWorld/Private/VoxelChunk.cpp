// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelWorldPrivatePCH.h"
#include "VoxelChunk.h"
#include "VoxelGeometry.h"

// Sets default values for this component's properties
UCubeVoxelChunk::UCubeVoxelChunk() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCubeVoxelChunk::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCubeVoxelChunk::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

// Called to re-upload the renderer mesh data.
FPrimitiveSceneProxy* UCubeVoxelChunk::CreateSceneProxy() {
	return new CubeVoxelProxy(this);
}