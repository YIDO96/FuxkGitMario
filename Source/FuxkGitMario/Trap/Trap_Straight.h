// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrapBase.h"
#include "Trap_Straight.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API ATrap_Straight : public ATrapBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	bool IsActiveTrap = false;

public:
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable)
	virtual void ActiveTrap(AActor* Player) override;
};
