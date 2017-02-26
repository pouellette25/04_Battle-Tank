// Copyright LP Creative Ventures LLC.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::Initialize(UTankBarrel* BarrelIn, UTankTurret* TurretIn)
{
	Barrel = BarrelIn;
	Turret = TurretIn;
}

void UTankAimingComponent::AimAt(FVector Location)
{
	if (!ensure(Barrel)) { return; }

	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bSuggestVelocity = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		LaunchVelocity,
		StartLocation,
		Location,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bSuggestVelocity)
	{
		auto AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelAndTurret(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelAndTurret(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

