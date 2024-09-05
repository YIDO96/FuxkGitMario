// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "EnemyFuxk.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AEnemyFuxk : public AEnemyBase
{
	GENERATED_BODY()
	

public:

	virtual void Tick(float DeltaTime) override;
};
