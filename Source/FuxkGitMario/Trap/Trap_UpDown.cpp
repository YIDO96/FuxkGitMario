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
        FVector currentLocation = GetActorLocation();
        Time += DeltaTime; // 0에서부터 시작하게 하기 위한 시간값
        // Z 좌표를 속도에 따라 증가시킵니다.
        //float Speed = 1000.0f; // Z축 이동 속도
        //CurrentLocation.Z += Speed * DeltaTime;

        // Z 좌표를 코사인파 형태로 변경합니다.
        float amplitude = 1200.0f; // 코사인파의 진폭
        float frequency = 3.5f; // 코사인파의 주파수
        currentLocation.Z = amplitude * -FMath::Cos(frequency * Time);

        // 새로운 위치로 설정합니다.
        SetActorLocation(currentLocation);
	}
}

void ATrap_UpDown::ActiveTrap(AActor* Player)
{
	IsActiveTrap = true;
}