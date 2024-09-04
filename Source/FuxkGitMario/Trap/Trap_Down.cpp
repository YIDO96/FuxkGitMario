// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Down.h"

void ATrap_Down::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Down::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		FVector newLocation = GetActorLocation() + FVector::DownVector * Speed * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Down::ActiveTrap()
{
	bIsActive = true;
}