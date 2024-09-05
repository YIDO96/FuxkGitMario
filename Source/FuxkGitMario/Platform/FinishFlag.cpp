// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/FinishFlag.h"

#include "Components/BoxComponent.h"
#include "Player/Player_Mario.h"

// Sets default values
AFinishFlag::AFinishFlag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	SetRootComponent(BoxComp);
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
	BoxComp->SetCollisionProfileName(TEXT("OverlapAll"));
	MeshComp->SetCollisionProfileName(TEXT("NoCollision"));
	
}

// Called when the game starts or when spawned
void AFinishFlag::BeginPlay()
{
	Super::BeginPlay();

	BoxComp->OnComponentBeginOverlap.AddDynamic(this,&AFinishFlag::OnTrapBoxOverlap);
}

// Called every frame
void AFinishFlag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AFinishFlag::ActiveEvent()
{
	
}

void AFinishFlag::OnTrapBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto player = Cast<APlayer_Mario>(OtherActor);
	if(player)
	{
		UE_LOG(LogTemp, Warning, TEXT("FinishFlag Overlaps"));
		//player-> 함수구현
	}
}

