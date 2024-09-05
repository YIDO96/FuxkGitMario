// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "UI/LifeWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/Character.h"
#include "GameMode/MarioGameInstance.h"
#include "EngineUtils.h"
#include "UI/StartWidget.h"

void AMarioGameModeBase::MinusLife(int32 point)
{
	currentLife -= point;

}

void AMarioGameModeBase::StartGame()
{
	if (StartUI)
	{
		StartUI->ChangeUIToStart();
	}
}

void AMarioGameModeBase::PrintLife()
{
	if (LifeUI != nullptr)
	{
		// LifeData 텍스트 블록에 현재 점수 값을 입력
		LifeUI->LifeData->SetText(FText::AsNumber(currentLife));
	}
}

void AMarioGameModeBase::GameOver()
{
	if (LifeWidget != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Over"));

		MinusLife(1);

		// 블루프린트 파일을 메모리에 로드한다.
		LifeUI = CreateWidget<ULifeWidget>(GetWorld(), LifeWidget);

		PrintLife();

		// 메모리에 로드 시 뷰 포트에 출력
		if (LifeUI != nullptr)
		{
			LifeUI->AddToViewport();

			//UGameplayStatics::SetGamePaused(GetWorld(), true); // 게임 포즈

			// 게임 재시작
			// 3초 후에 HideUIAndRestart 함수를 호출하도록 타이머 설정
			GetWorld()->GetTimerManager().SetTimer(RestartTimerHandle, this, &AMarioGameModeBase::HideUIAndRestart, 3.0f, false);
		}
	}
}

void AMarioGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	MarioInstance = Cast<UMarioGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MarioInstance)
	{
		currentLife = MarioInstance->LoadLife();
	}
	if (currentLife > 0)
	{
		StartUI = CreateWidget<UStartWidget>(GetWorld(), StartWidget);
		if (StartUI)
		{
			StartUI->AddToViewport();
		}

		// 입력모드를 UI 로 설정해주기
		//GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	}
}

void AMarioGameModeBase::HideUIAndRestart()
{
	// UI를 제거합니다.
	if (LifeUI != nullptr)
	{
		LifeUI->RemoveFromViewport();
		LifeUI = nullptr;
	}
	if (MarioInstance)
	{
		MarioInstance->SaveLife(currentLife);
	}
	UE_LOG(LogTemp, Warning, TEXT("Game Resumed!"));
	UGameplayStatics::OpenLevel(this, FName("MapTestStage"));
}