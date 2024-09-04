// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrapBase.h"
#include "Trap_RotatingTanghulu.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API ATrap_RotatingTanghulu : public ATrapBase
{
	GENERATED_BODY()
	
public:
	ATrap_RotatingTanghulu();

protected:
	virtual void BeginPlay() override;

private:

public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Trap")
	class UStaticMeshComponent* MeshComp_Tanghulu;
};
