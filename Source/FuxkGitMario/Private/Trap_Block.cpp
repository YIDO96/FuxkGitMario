// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Block.h"

#include "Components/BoxComponent.h"

void ATrap_Block::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap_Block::ActiveTrap(AActor* Player)
{
	Super::ActiveTrap(Player);
	UE_LOG(LogTemp, Warning, TEXT("Trap Block Active Trap"));
	FVector PlayerUpVector = Player->GetActorUpVector();
	FVector ImpactDir = GetActorLocation() - Player->GetActorLocation();
	ImpactDir.Normalize();

	float DotProduct = FVector::DotProduct(PlayerUpVector, ImpactDir);
	if(DotProduct > 0.5f)
	{
		FVector ForwardVector = Player->GetActorForwardVector();
		float Angle = FMath::Acos(FVector::DotProduct(ImpactDir, ForwardVector));
		float AngleDegrees = FMath::RadiansToDegrees(Angle);
		if(AngleDegrees <= 15.0f)
		{
			// Trap Activation
			UE_LOG(LogTemp, Warning, TEXT("Trap Block Active Trap"));
			BoxComp->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Block);
			MeshComp->SetMaterial(0, ExposeMat);
		}
	}
}

