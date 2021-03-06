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
	
protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 5000;

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	void AimTowardsPlayer();
};
