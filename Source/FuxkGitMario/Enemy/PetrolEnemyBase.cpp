// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/PetrolEnemyBase.h"

APetrolEnemyBase::APetrolEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APetrolEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();;  // 시작 위치
	EndLocation = StartLocation + FVector(0, MoveDistance, 0); // 도착 위치

}

// Called every frame
void APetrolEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 캐릭터 이동 함수 호출
	MoveCharacter(DeltaTime);
}

// 캐릭터가 Y축으로 반복해서 이동하는 함수
void APetrolEnemyBase::MoveCharacter(float DeltaTime)
{
	if(bMovingUp)
	{
		CurrentTime += DeltaTime;
	}else
	{
		CurrentTime -= DeltaTime;
	}
	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation = bMovingUp ? EndLocation : StartLocation;

	// 목표 위치로 부드럽게 이동
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, CurrentTime / MoveDuration);
	SetActorLocation(NewLocation);

	// 목표 위치에 도달했는지 확인
	if (FVector::Dist(CurrentLocation, TargetLocation) < TargetDistance)
	{
		bMovingUp = !bMovingUp;  // 방향을 반전
	}
	
}