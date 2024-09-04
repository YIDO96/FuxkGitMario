// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interface/TrapInterface.h"
#include "GameFramework/Actor.h"
#include "TrapBase.generated.h"

UCLASS()
class FUXKGITMARIO_API ATrapBase : public AActor, public ITrapInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrapBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool bIsActive;
	
	UPROPERTY(EditAnywhere, Category = "Trap")
	float TrapSpeed = 1500.0f;

	UPROPERTY(EditAnywhere, Category = "Trap")
	float TrapRange = 1500.0f;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void ActiveTrap(AActor* Player) override;
	virtual void ActiveTrap() override;

	UPROPERTY(EditAnywhere, Category = "Trap")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere, Category = "Trap")
	class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, Category = "Trap")
	FVector StartLocation; // 처음 위치값
	
	// MeshOverlap Function
	UFUNCTION()
	virtual void OnTrapMeshOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);

	// CollisionOverlap Function
	UFUNCTION()
	void OnTrapBoxOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

private:
};
