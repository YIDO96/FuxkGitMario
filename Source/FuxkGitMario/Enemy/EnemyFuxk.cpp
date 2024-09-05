// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyFuxk.h"

void AEnemyFuxk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsPlayerOverlap)
	{
		FVector newLocation = GetActorLocation() + GetActorRightVector() * DeltaTime * 200;
		SetActorLocation(newLocation);
	}
}
