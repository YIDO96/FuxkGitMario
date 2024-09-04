// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrapBase.h"
#include "Trap_DownStraight.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API ATrap_DownStraight : public ATrapBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	class APlayer_Mario* Target;

	FVector Dir;
	bool IsCollinear = false;
	float Speed = 3000;
public:
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable)
	virtual void ActiveTrap(AActor* Player) override;
};
