// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAICont.h"



void ATankAICont::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAICont not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAICont possessed: %s"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank possessed: %s"), *PlayerTank->GetName());
	}
}


ATank * ATankAICont::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank *  ATankAICont::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn == nullptr)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


void  ATankAICont::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerLocation = GetPlayerTank()->GetActorLocation();
	GetPlayerTank()->AimAt(GetControlledTank()->GetName(),PlayerLocation);
	
}
