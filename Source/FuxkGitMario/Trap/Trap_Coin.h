// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap/TrapBase.h"
#include "Trap_Coin.generated.h"

/**
 * 
 */
UENUM(Blueprintable)
enum class TrapCoin : uint8
{
	Coin,
	Enemy,
	FinishFlag,
};


UCLASS()
class FUXKGITMARIO_API ATrap_Coin : public ATrapBase
{
	GENERATED_BODY()

public:
	ATrap_Coin();
	
	virtual void Tick(float DeltaTime) override;

	void CreateCoin();	// 
	void UpCoin();		// Actor가 위로올라오는

	virtual void ActiveTrap() override;
	
	UPROPERTY(EditAnywhere, Category = "Enum")
	TrapCoin Cointype;


	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TSubclassOf<class AFinishFlag> Flag;
};
