// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/PlatformBase_UpDown.h"

void APlatformBase_UpDown::BeginPlay()
{
	Super::BeginPlay();
	randomNumber = FMath::RandRange(1,100);
}

void APlatformBase_UpDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveEvent)
	{
		UE_LOG(LogTemp, Warning, TEXT("IsActiveEvent is True"));
		if (randomNumber > 50)
		{
			FVector newLocation = GetActorLocation() + FVector::DownVector * Speed * DeltaTime;
			SetActorLocation(newLocation);
		}
		else
		{
			FVector newLocation = GetActorLocation() + FVector::UpVector * Speed * DeltaTime;
			SetActorLocation(newLocation);
		}
	}
}
