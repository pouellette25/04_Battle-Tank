// Copyright LP Creative Ventures LLC.

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
		MoveToActor(PlayerTank, AcceptanceRadius);
		AimTowardsPlayer();
	}	
}

void ATankAIController::AimTowardsPlayer()
{
	if (!Tank) { return; }
	Tank->AimAt(PlayerTank->GetActorLocation());
	Tank->Fire();
}

