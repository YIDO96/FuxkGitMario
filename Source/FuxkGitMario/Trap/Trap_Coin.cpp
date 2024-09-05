// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/Trap_Coin.h"

#include "Platform/FinishFlag.h"

ATrap_Coin::ATrap_Coin()
{
	MeshComp->SetCollisionProfileName(TEXT("Platform"));
}

void ATrap_Coin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		UpCoin();
	}
}

void ATrap_Coin::CreateCoin()
{
	if(Cointype == TrapCoin::Coin)
	{
		
	}
	else if (Cointype == TrapCoin::Enemy)
	{
		
	}
	else if (Cointype == TrapCoin::FinishFlag)
	{
		GetWorld()->SpawnActor<AFinishFlag>(Flag, GetActorLocation(),GetActorRotation());
	}
}

void ATrap_Coin::UpCoin()
{
	//FVector P = GetActorLocation() + GetActorUpVector() * moveSpeed * DeltaTime;
	//SetActorLocation(P);//Block을 하기 위해서는 Sweep이 true여야 된다.
}

void ATrap_Coin::ActiveTrap()
{
	CreateCoin();

	UE_LOG(LogTemp, Warning, TEXT("Trap Coin is active"));
}
