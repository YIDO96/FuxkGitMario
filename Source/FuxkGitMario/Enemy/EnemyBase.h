// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.h"
#include "EnemyBase.generated.h"

UCLASS()
class FUXKGITMARIO_API AEnemyBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	class USphereComponent* SphereComp;
	

	UFUNCTION()
	virtual void OnTrapSphereOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
private:
	
	virtual void Fire();
};
