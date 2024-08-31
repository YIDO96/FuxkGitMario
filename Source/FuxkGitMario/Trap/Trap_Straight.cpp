// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Straight.h"

void ATrap_Straight::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Straight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
		FVector newLocation = GetActorLocation() + -FVector::RightVector * 1000 * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Straight::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}
