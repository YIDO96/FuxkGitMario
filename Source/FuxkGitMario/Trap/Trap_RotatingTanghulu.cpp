// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_RotatingTanghulu.h"
#include "Components/BoxComponent.h"

ATrap_RotatingTanghulu::ATrap_RotatingTanghulu()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MeshComp_Tanghulu = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TanghuluMesh"));
	MeshComp_Tanghulu->SetupAttachment(BoxComp);
	MeshComp_Tanghulu->SetCollisionProfileName(TEXT("Trap"));
	MeshComp_Tanghulu->SetGenerateOverlapEvents(true);

	MeshComp_Tanghulu->SetRelativeLocation(FVector(10, 0, 120));
	MeshComp_Tanghulu->SetRelativeScale3D(FVector(0.5f, 0.1f, 1.0f));
}

void ATrap_RotatingTanghulu::BeginPlay()
{
	Super::BeginPlay();

	MeshComp_Tanghulu->OnComponentBeginOverlap.AddDynamic(this, &ATrapBase::OnTrapMeshOverlap);
}

void ATrap_RotatingTanghulu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator newRotation = BoxComp->GetRelativeRotation() + FRotator(0, 0, 1) * TrapSpeed  * DeltaTime;
	BoxComp->SetRelativeRotation(newRotation);
}

void ATrap_RotatingTanghulu::ActiveTrap(AActor* Player)
{
}
