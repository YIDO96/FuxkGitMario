// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrapBase.h"
#include "Trap_Block.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API ATrap_Block : public ATrapBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void ActiveTrap(AActor* Player) override;
	
	UPROPERTY(EditAnywhere)
	UMaterialInstance* ExposeMat;
	
	virtual void OnTrapMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
private:
};
