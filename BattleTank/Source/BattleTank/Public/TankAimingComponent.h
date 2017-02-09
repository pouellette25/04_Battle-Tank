// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* Barrel);
	// TODO add set barrel reference

	void AimAt(FVector Location, float LaunchSpeed);

private:
	UStaticMeshComponent* Barrel = nullptr;
	
	void MoveBarrel(FVector AimDirection);
};
