// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platform/PlatformBase.h"
#include "PlatformBase_UpDown.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API APlatformBase_UpDown : public APlatformBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	int randomNumber;
	
	UPROPERTY(EditAnywhere)
	float Speed = 4000;
	
	
};
