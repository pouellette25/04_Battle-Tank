// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float MaxElevation)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate Called() %f"), MaxElevation);
}

