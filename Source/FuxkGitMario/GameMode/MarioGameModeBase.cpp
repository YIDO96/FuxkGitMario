// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "UI/LifeWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void AMarioGameModeBase::MinusLife(int32 point)
{
	currentLife -= point;

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

			UGameplayStatics::SetGamePaused(GetWorld(), true); // 게임 포즈
		}
	}
}