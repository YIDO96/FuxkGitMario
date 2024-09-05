// Fill out your copyright notice in the Description page of Project Settings.


#include "Mario.h"

// Sets default values
AMario::AMario()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMario::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

