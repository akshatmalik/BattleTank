// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"



void UTankBarrel :: Elevate(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	//UE_LOG(LogTemp, Warning, TEXT("ElevationChange %f"), ElevationChange);
	UE_LOG(LogTemp, Warning, TEXT("Elevation %f"), Elevation);
	
	UE_LOG(LogTemp, Warning, TEXT("Elevation rotator %s"), *FRotator(Elevation, 0, 0).ToString());
	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
	
}
