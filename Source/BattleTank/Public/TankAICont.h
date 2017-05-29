// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "AIController.h"
#include "TankAICont.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAICont : public AAIController
{
	GENERATED_BODY()



	ATank * GetControlledTank() const;

	ATank * GetPlayerTank() const;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
};
