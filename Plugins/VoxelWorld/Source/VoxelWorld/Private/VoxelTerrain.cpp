// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelWorldPrivatePCH.h"
#include "VoxelTerrain.h"


// Sets default values
AVoxelTerrain::AVoxelTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoxelTerrain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVoxelTerrain::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// TODO: Load new chunks based on the camera position.
	auto player = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager;
	auto position = player->GetRootComponent()->RelativeLocation;
}
