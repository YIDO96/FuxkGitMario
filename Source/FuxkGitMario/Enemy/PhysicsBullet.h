// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/PhysicsActorBase.h"
#include "PhysicsBullet.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API APhysicsBullet : public APhysicsActorBase
{
	GENERATED_BODY()
public:
	APhysicsBullet();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnBulletOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
