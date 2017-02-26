// Copyright LP Creative Ventures LLC.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"
// Depends on movement component via pathfinding system

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

	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		AimTowardsPlayer();
	}	
}

void ATankAIController::AimTowardsPlayer()
{
	if (!ensure(Tank)) { return; }
	Tank->AimAt(PlayerTank->GetActorLocation());
	Tank->Fire();
}

