// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platform/PlatformBase.h"
#include "FinishHouse.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AFinishHouse : public APlatformBase
{
	GENERATED_BODY()

public:
	AFinishHouse();
	
	virtual void Tick(float DeltaTime) override;
};
