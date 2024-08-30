// Fill out your copyright notice in the Description page of Project Settings.


#include "TrapBase.h"

#include "MarioInterface.h"
#include "Components/BoxComponent.h"

// Sets default values
ATrapBase::ATrapBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrapMesh"));
	SetRootComponent(MeshComp);
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("EventTriggerBox"));
	BoxComp->SetupAttachment(MeshComp);
	BoxComp->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>InitMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	MeshComp->SetStaticMesh(InitMesh.Object);
	
	MeshComp->SetCollisionProfileName(TEXT("Trap"));
	MeshComp->SetGenerateOverlapEvents(true);
	BoxComp->SetCollisionProfileName(TEXT("Trap"));
	BoxComp->SetGenerateOverlapEvents(true);
	
}

// Called when the game starts or when spawned
void ATrapBase::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &ATrapBase::OnTrapOverlap);
}

// Called every frame
void ATrapBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrapBase::ActiveTrap(AActor* Player)
{
	
}

void ATrapBase::OnTrapOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor);
	if (Mario)
	{
		Mario->Die();
	}
}
