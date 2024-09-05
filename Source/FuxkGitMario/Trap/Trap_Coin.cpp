// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/Trap_Coin.h"

#include "Platform/FinishFlag.h"
#include "Trap/TrapBase.h"

ATrap_Coin::ATrap_Coin()
{
	MeshComp->SetCollisionProfileName(TEXT("Platform"));
}

void ATrap_Coin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("CurrentTime = %.2f"), CurrentTime);
	if (bIsActive)
	{
		CurrentTime += DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("bIsActive True"));
		if (CurrentTime < Time)
		{
			UE_LOG(LogTemp, Warning, TEXT("CurrentTime"));

			FVector P = GetActorLocation() + GetActorUpVector() * 90 * DeltaTime;
			//SetActorLocation(P);//Block을 하기 위해서는 Sweep이 true여야 된다.
			Actor->SetActorLocation(P);

			//CurrentTime = 0;
		}
		else
		{
			bIsActive = false;
			CurrentTime = 0;
		}
		//bIsActive = false;
		//UpCoin();
	}
}

void ATrap_Coin::CreateCoin()
{
	FVector newLocation = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 10);

	if(Cointype == TrapCoin::Coin)
	{
		
	}
	else if (Cointype == TrapCoin::Enemy)
	{
		
	}
	else if (Cointype == TrapCoin::FinishFlag)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn Flag"));
		Actor = GetWorld()->SpawnActor<ATrapBase>(Flag, newLocation,GetActorRotation());
	}
}

void ATrap_Coin::UpCoin()
{
	if (CurrentTime > Time)
	{
		
	}
}

void ATrap_Coin::ActiveTrap()
{
	CreateCoin();
	bIsActive = true;
	UE_LOG(LogTemp, Warning, TEXT("Trap Coin is active"));
}
