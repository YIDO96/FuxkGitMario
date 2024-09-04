// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "MarioCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class FUXKGITMARIO_API AMarioCameraActor : public ACameraActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AMarioCameraActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Reference to the player character (or any actor you want the camera to follow)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	AActor* TargetActor;

	// Distance threshold to start following the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraFollowThreshold;

private:
	FVector PreviousCameraLocation;
};
