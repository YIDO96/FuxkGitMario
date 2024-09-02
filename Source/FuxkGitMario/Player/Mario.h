// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interface/MarioInterface.h"
#include "GameFramework/Pawn.h"
#include "Mario.generated.h"

UCLASS()
class FUXKGITMARIO_API AMario : public APawn, public IMarioInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMario();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Die() override;

};
