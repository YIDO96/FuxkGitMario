// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Up.h"

void ATrap_Up::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Up::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		FVector newLocation = GetActorLocation() + FVector::UpVector * TrapSpeed * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Up::ActiveTrap()
{
	bIsActive = true;
}