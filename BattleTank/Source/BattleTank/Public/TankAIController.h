// Copyright LP Creative Ventures LLC.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	void AimTowardsPlayer();

	// How close can the AI tank get
	float AcceptanceRadius = 3000;
	
};
