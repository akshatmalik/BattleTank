// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	bool bGetSightRayHitLocation(FVector & HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = .5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;	

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;
	
};
