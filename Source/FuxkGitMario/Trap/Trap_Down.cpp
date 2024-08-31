// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Down.h"

void ATrap_Down::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Down::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
		FVector newLocation = GetActorLocation() + FVector::DownVector * 1000 * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Down::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}
