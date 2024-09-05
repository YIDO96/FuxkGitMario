// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interface/GameModeInterface.h"

#include "MarioGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AMarioGameModeBase : public AGameModeBase , public IGameModeInterface
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ULifeWidget> LifeWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UStartWidget> StartWidget;

	virtual void MinusLife(int32 point) override;
	virtual void GameOver() override;
	virtual void BeginPlay() override;

	int32 currentLife = 1;

	// 현재 뷰 포트에 로드된 위젯 저장용 변수
	UPROPERTY()
	class ULifeWidget* LifeUI;
	UPROPERTY()
	class UStartWidget* StartUI;

	void PrintLife();

	// 타이머 핸들
	FTimerHandle RestartTimerHandle;

	void HideUIAndRestart(); // UI 숨기고 게임을 재시작하는 함수
};