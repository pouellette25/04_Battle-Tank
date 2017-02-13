// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		return Cast<ATank>(PlayerController->GetPawn());
	}

	return nullptr;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();

	if (!Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Controlled Tank"));
	}

	PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Player Tank"));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (PlayerTank)
	{
		AimTowardsPlayer();
	}	
}

void ATankAIController::AimTowardsPlayer()
{
	GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
}

