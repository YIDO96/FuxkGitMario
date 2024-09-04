// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/PlatformBase_UpDown.h"

#include "Components/BoxComponent.h"

APlatformBase_UpDown::APlatformBase_UpDown()
{
	BoxComp->SetWorldScale3D(FVector(1,0.5,1));
	MeshComp->SetWorldScale3D(FVector(1,2,1));
}

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
		if (Type == EPlatformUPDownType::Platform_Default)
		{
			if (randomNumber > 50)
			{
				DownMove();
			}
			else
			{
				UpMove();
			}
		}
		else if(Type == EPlatformUPDownType::Platform_Down)
		{
			DownMove();
		}
		else
		{
			UpMove();
		}
	}
}

void APlatformBase_UpDown::UpMove()
{
	FVector newLocation = GetActorLocation() + FVector::UpVector * Speed * GetWorld()->DeltaTimeSeconds;
	SetActorLocation(newLocation);
}

void APlatformBase_UpDown::DownMove()
{
	FVector newLocation = GetActorLocation() + FVector::DownVector * Speed * GetWorld()->DeltaTimeSeconds;
	SetActorLocation(newLocation);
}
