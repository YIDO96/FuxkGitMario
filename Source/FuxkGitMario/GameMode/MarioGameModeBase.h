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

	void MinusLife(int32 point);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ULifeWidget> LifeWidget;

	virtual void GameOver() override;

private:
	int32 currentLife = 1;

	// 현재 뷰 포트에 로드된 위젯 저장용 변수
	class ULifeWidget* LifeUI;

	void PrintLife();
};