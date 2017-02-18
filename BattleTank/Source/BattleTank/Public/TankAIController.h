// Copyright LP Creative Ventures LLC.Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

// Forward declarations
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	ATank* Tank;
	ATank* PlayerTank;

	virtual void Tick(float DeltaSeconds) override;
	void AimTowardsPlayer();

	// How close can the AI tank get
	float AcceptanceRadius = 3000;
	
};
