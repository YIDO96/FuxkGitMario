// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MarioCameraActor.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AMarioCameraActor::AMarioCameraActor()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the PreviousCameraLocation and CameraFollowThreshold
	PreviousCameraLocation = FVector::ZeroVector;
	CameraFollowThreshold = 50.0f;  // Example threshold value, can be adjusted
}
void AMarioCameraActor::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the PreviousCameraLocation with the camera's starting location
	PreviousCameraLocation = GetActorLocation();

	// Optionally find the target actor in the scene, if not already set
	if (!TargetActor)
	{
		TargetActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); // Assuming the target is the player character
	}
}

void AMarioCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetActor)
	{
		// Get the current location of the camera
		FVector CurrentCameraLocation = GetActorLocation();

		// Get the current location of the target actor
		FVector TargetLocation = TargetActor->GetActorLocation();

		// Calculate the distance between the camera and the target actor in the Y direction
		float DistanceToTarget = TargetLocation.Y - CurrentCameraLocation.Y;

		// Check if the target actor is in the +Y direction relative to the camera and the camera needs to move
		if (DistanceToTarget > CameraFollowThreshold)
		{
			// Move the camera to follow the target actor
			FVector NewCameraLocation = CurrentCameraLocation;
			NewCameraLocation.Y = TargetLocation.Y - CameraFollowThreshold; // Maintain the threshold distance
			SetActorLocation(NewCameraLocation);
		}

		// Update the PreviousCameraLocation for the next frame
		PreviousCameraLocation = CurrentCameraLocation;
	}
}