// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();

	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank: %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Controlled Tank"));
	}
}


