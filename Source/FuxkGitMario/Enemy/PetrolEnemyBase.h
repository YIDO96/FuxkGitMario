// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "PetrolEnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API APetrolEnemyBase : public AEnemyBase
{
	GENERATED_BODY()
public:
	APetrolEnemyBase();
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere)
	float MoveDistance = 300.0f;
	UPROPERTY(EditAnywhere)
	float TargetDistance = 10.0f;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 200.0f;
	UPROPERTY(EditAnywhere)
	bool bMovingUp = true;

	FVector StartLocation;
	FVector EndLocation;

	float CurrentTime = 0.0f;
	
	UPROPERTY(EditAnywhere)
	float MoveDuration = 3.0f;
	void MoveCharacter(float DeltaTime);
	
};
