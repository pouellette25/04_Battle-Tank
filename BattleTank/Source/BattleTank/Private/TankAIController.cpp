// Copyright LP Creative Ventures LLC.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsPlayer();
}

void ATankAIController::AimTowardsPlayer()
{
	auto Tank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && Tank)) { return; }

	auto AimingComponent = Tank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->Fire();
}

