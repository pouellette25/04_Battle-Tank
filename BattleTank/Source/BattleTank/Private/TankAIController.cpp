// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(GetPawn());

	if (!Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Controlled Tank"));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		AimTowardsPlayer();
	}	
}

void ATankAIController::AimTowardsPlayer()
{
	if (!Tank) { return; }
	Tank->AimAt(PlayerTank->GetActorLocation());
	Tank->Fire();
}

