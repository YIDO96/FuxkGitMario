// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/FinishHouse.h"
#include "Components/BoxComponent.h"
#include "Player/Player_Mario.h"
#include "Kismet/GameplayStatics.h"

AFinishHouse::AFinishHouse()
{
	BoxComp->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxComp->SetBoxExtent(FVector(50));
	MeshComp->SetCollisionProfileName(TEXT("NoCollision"));
}

void AFinishHouse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveEvent)
	{
		auto player = Cast<APlayer_Mario>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayer_Mario::StaticClass()));
		if (player)
		{
			player->FinishHouse();
		}
		// Finish 불러오기
		UE_LOG(LogTemp, Warning, TEXT("AFinishHouse Call Finish"));

		// 임시용
		IsActiveEvent = false;
	}
}
