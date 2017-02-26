// Copyright LP Creative Ventures LLC.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// TODO: remove once firing is moved to aiming component
	// The launch speed of the projectile
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
