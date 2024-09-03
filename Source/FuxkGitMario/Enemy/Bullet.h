// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class FUXKGITMARIO_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	class USphereComponent* SphereComp;
	
	UPROPERTY(EditAnywhere, Category = "Bullet")
	float BulletFloatDuration = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	float BulletAmplitude = 45.0f;

	UFUNCTION()
	void OnTrapSphereOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	UFUNCTION()
	void BulletCurve();
	
	FVector TargetLocation;
	
private:
	
	float CurrentTime;

	FTimerHandle BulletTimer;
};
