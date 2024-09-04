// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platform/PlatformBase.h"
#include "PlatformBase_UpDown.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EPlatformUPDownType : uint8
{
	Platform_Default,
	Platform_Up,
	Platform_Down,
};

UCLASS()
class FUXKGITMARIO_API APlatformBase_UpDown : public APlatformBase
{
	GENERATED_BODY()

public:
	APlatformBase_UpDown();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly)
	EPlatformUPDownType Type = EPlatformUPDownType::Platform_Default;

	int randomNumber;
	
	UPROPERTY(EditAnywhere)
	float Speed = 4000;
	
	void UpMove();
	void DownMove();
};
