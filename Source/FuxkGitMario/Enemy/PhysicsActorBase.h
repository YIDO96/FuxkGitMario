// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsActorBase.generated.h"

UCLASS()
class FUXKGITMARIO_API APhysicsActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicsActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PhysicsActor")
	class USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PhysicsActor")
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PhysicsActor")
	float Mass = 1.0f; //질량

	UFUNCTION(BlueprintCallable, Category = "PhysicsActor")
	void SetCustomGravity(FVector NewGravity);

	UFUNCTION(BlueprintCallable, Category = "PhysicsActor")
	void SetCustomGravityTarget(AActor* Target);
	
private:
	FVector Velocity; //현재 속도
	FVector Acceleration; //현재 가속도
	FVector PrevTickVelocity; //이전 Tick 속도
	FVector CustomGravity; //커스텀 중력

	void ApplyPhysics(float DeltaTime);
	void ApplyCustomGravity();
};
