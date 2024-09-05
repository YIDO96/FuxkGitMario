// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_DownStraight.h"
#include "../Player/Player_Mario.h"

void ATrap_DownStraight::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_DownStraight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		if (not IsCollinear) Dir = FVector::DownVector; // 플레이어와 동일선상이 아니라면 아래로만 내려가라
		
		// 플레이어와 동일 선상이라면
		if (GetActorLocation().Z <= Target->GetActorLocation().Z)
		{
			Dir = -FVector::RightVector;
			Speed = TrapSpeed;
			IsCollinear = true; // 플레이어와 동일선상이 한번이라도 됬으면 그냥 좌측방향으로 쭉 날라가게 하기 위한 제어값
		}

		FVector newLocation = GetActorLocation() + Dir * Speed * DeltaTime;
		SetActorLocation(newLocation);
	}
}

void ATrap_DownStraight::ActiveTrap(AActor* Player)
{
	bIsActive = true;
	Target = Cast<APlayer_Mario>(Player);
	MeshComp->bHiddenInGame = false;
}
