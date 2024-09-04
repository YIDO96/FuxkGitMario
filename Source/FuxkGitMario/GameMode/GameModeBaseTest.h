// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBaseTest.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AGameModeBaseTest : public AGameModeBase
{
	GENERATED_BODY()

	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:

	bool IsCreate = true;

	//UPROPERTY(EditAnywhere)
	//TSubclassOf<class APlatformBase> PlatformFactory;

	UPROPERTY(EditAnywhere, Category = "Size")
	int Size = 1000;


	void CreateMap();
};
