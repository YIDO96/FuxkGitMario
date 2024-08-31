// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlatformBase::APlatformBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComp);


	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComp->SetupAttachment(BoxComp);

	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (defaultMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(defaultMesh.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial>defaultMat(TEXT("/Script/Engine.Material'/Game/Materials/M_Platform.M_Platform'"));
	if (defaultMat.Succeeded())
	{
		MeshComp->SetMaterial(0, defaultMat.Object);
	}

}

// Called when the game starts or when spawned
void APlatformBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

