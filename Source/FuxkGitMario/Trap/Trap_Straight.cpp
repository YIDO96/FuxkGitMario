// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Straight.h"

void ATrap_Straight::BeginPlay()
{
	Super::BeginPlay();

	MeshComp->bHiddenInGame = true;
	UE_LOG(LogTemp, Warning, TEXT("Mesh HiddenInGame = true"));
}

void ATrap_Straight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
		//FVector newLocation = GetActorLocation() + -FVector::RightVector * Speed * DeltaTime;
		FVector newLocation = GetActorLocation() + -FVector::RightVector * TrapSpeed * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_Straight::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
	MeshComp->bHiddenInGame = false;
	UE_LOG(LogTemp, Warning, TEXT("Mesh HiddenInGame = false"));
}
