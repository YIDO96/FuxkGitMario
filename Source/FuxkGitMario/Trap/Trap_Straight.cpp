// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Straight.h"

void ATrap_Straight::BeginPlay()
{
	Super::BeginPlay();

	MeshComp->bHiddenInGame = true;
	MeshComp->SetCollisionProfileName(TEXT("NoCollision"));
}

void ATrap_Straight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		//FVector newLocation = GetActorLocation() + -FVector::RightVector * Speed * DeltaTime;
		FVector newLocation = GetActorLocation() + -FVector::RightVector * TrapSpeed * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Straight::ActiveTrap()
{
	bIsActive = true;
	MeshComp->bHiddenInGame = false;
	MeshComp->SetCollisionProfileName(TEXT("Trap"));
}
