// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "GunEnemy.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AGunEnemy : public AEnemyBase
{
	GENERATED_BODY()
public:
	AGunEnemy();
protected:
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Enemy")
	TSubclassOf<class APhysicsBullet> BulletFactory;

	virtual void Fire() override;
private:
	UPROPERTY(EditAnywhere, Category = "Enemy")
	float FireRate = 3.0f;
	UPROPERTY(VisibleAnywhere, Category = "Enemy")
	float FirePower = 500.0f;
	
	float CurrentTime = 0.0f;
};
