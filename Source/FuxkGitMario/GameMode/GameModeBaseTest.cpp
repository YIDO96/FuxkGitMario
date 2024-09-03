// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GameModeBaseTest.h"
#include "Platform/PlatformBase.h"


void AGameModeBaseTest::BeginPlay()
{
	Super::BeginPlay();
	CreateMap();
	// 10개의 Platform을 생성하기
	// 1. 10개의 Loop문
}

void AGameModeBaseTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Error, TEXT("GameModeBaseTest Tick"));
	if (IsCreate)
	{
		UE_LOG(LogTemp, Error, TEXT("GameModeBaseTest Tick"));
		IsCreate = false;
	}
}

void AGameModeBaseTest::CreateMap()
{
	TArray<bool> bTemp; // 첫째줄에 생성됬는지
	TArray<int> bFloor; // 몇층으로 구성되어있는지

	
	for (int i =0 ; i < Size ; i++)
	{
		// Platform을 생성하기
		//auto f = GetWorld()->SpawnActor<APlatformBase>(APlatformBase::StaticClass(),
		//				FVector(0,100 * i,0), FRotator::ZeroRotator);

		if (i == 0) // 처음 위치는 무조건 하나 생성
		{
			auto f = GetWorld()->SpawnActor<APlatformBase>(APlatformBase::StaticClass(),
		FVector(0,100 * i,0), FRotator::ZeroRotator);
			bTemp.Emplace(true);
			bFloor.Emplace(1);
		}
		else // 두번째 타일부터
		{
			int randomNumber = FMath::RandRange(0, 100);
			if (randomNumber >= 50) // 50% 확률로 바닥 생성
			{
				auto f = GetWorld()->SpawnActor<APlatformBase>(APlatformBase::StaticClass(),
					FVector(0,100 * i,0), FRotator::ZeroRotator);
				bTemp.Emplace(true);
				if (bFloor[i-1] >= 1) // 전 칸이 1층 이상이라면.. 
				{
					for (int j = 1 ; j < bFloor[i-1] ; j++)
					{
						auto fj = GetWorld()->SpawnActor<APlatformBase>(APlatformBase::StaticClass(),
				FVector(0,100 * i,100 * j), FRotator::ZeroRotator);
					}
				}
				if (bTemp[i-1] == false) // 전 칸 바닥이 생성되지않았다면..
				{
					int randomNumber3 = FMath::RandRange(0, 100);
					if (randomNumber3 >= 60) // 40% 확률로 높게 생성
					{
						int randomFloor = FMath::RandRange(3, 7); // 높이는 3~7까지
						bFloor.Emplace(randomFloor);
						for (int j = 1 ; j < randomFloor ; j++)
						{
							auto fj = GetWorld()->SpawnActor<APlatformBase>(APlatformBase::StaticClass(),
					FVector(0,100 * i,100 * j), FRotator::ZeroRotator);
						}
					}
				}
				bFloor.Emplace(1);
			}
			else // 50% 확률로 비 생성
			{
				bTemp.Emplace(false);
				bFloor.Emplace(0);
				int randomNumber2 = FMath::RandRange(0, 100);
				if (randomNumber2 >= 60) // 40% 확률로 높이 250 ~ 390 위치에 발판 생성
				{
					auto f = GetWorld()->SpawnActor<APlatformBase>(APlatformBase::StaticClass(),
					FVector(0,100 * i,FMath::RandRange(250,390)), FRotator::ZeroRotator);
				}
			}
		}
	}
	
}
