// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
		void Elevate(float DegreeOfRotation);

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 35.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.0f;
};
