// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_UpDown.h"

void ATrap_UpDown::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_UpDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsActiveTrap)
	{
        FVector CurrentLocation = GetActorLocation();

        // X 좌표를 속도에 따라 증가시킵니다.
        float Speed = 1000.0f; // X축 이동 속도
        CurrentLocation.Z += Speed * DeltaTime;

        // Y 좌표를 사인파 형태로 변경합니다.
        float Amplitude = 700.0f; // 사인파의 진폭
        float Frequency = 2.0f; // 사인파의 주파수
        float Time = GetWorld()->GetTimeSeconds(); // 경과 시간
        CurrentLocation.Z = Amplitude * FMath::Sin(Frequency * Time);

        // 새로운 위치로 설정합니다.
        SetActorLocation(CurrentLocation);
	}
}

void ATrap_UpDown::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}