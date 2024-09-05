// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MarioGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API UMarioGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMarioGameInstance();
protected:
private:
	UPROPERTY()
	int32 Life = 0;
public:
	UFUNCTION(BlueprintCallable, Category = "Instance")
	void SaveLife(int32 NewLife);

	UFUNCTION(BlueprintCallable, Category = "Instance")
	int32 LoadLife();
};
