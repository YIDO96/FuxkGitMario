// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/FinishHouse.h"
#include "Components/BoxComponent.h"

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
		// Finish 불러오기
		UE_LOG(LogTemp, Warning, TEXT("Call Finish"));

		// 임시용
		IsActiveEvent = false;
	}
}
