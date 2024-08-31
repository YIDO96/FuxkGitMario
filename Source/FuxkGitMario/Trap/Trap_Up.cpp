// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Up.h"

void ATrap_Up::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Up::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
		FVector newLocation = GetActorLocation() + FVector::UpVector * 1000 * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Up::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}