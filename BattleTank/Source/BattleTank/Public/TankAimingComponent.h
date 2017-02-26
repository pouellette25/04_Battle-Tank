// Copyright LP Creative Ventures LLC.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Forward Decleration to pull in the tank barrel class
class UTankBarrel; 
class UTankTurret;
class AProjectile;

/*
* Responsible for helping the player and ai tanks aim
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankBarrel* BarrelIn, UTankTurret* TurretIn);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	void AimAt(FVector Location);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Aiming;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	void MoveBarrelAndTurret(FVector AimDirection);
	double LastFireTime = 0;
};
