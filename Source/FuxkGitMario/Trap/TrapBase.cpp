// Fill out your copyright notice in the Description page of Project Settings.


#include "TrapBase.h"

#include "../Interface/MarioInterface.h"
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
	BoxComp->SetBoxExtent(FVector(50));
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>InitMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
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
	
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &ATrapBase::OnTrapMeshOverlap);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ATrapBase::OnTrapBoxOverlap);

	StartLocation = GetActorLocation();
}

// Called every frame
void ATrapBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrapBase::ActiveTrap(AActor* Player)
{
	
}

void ATrapBase::ActiveTrap()
{
}

void ATrapBase::OnTrapMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor); // OtherActor를 IMarioInterface로 형변환
	if (Mario) // 형변환이 성공했다면
	{
		Mario->Die(); // Mario(Player_Mario)의 Die함수 호출
	}
}

void ATrapBase::OnTrapBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor); // OtherActor를 IMarioInterface로 형변환
	if (Mario) // 형변환이 성공했다면
	{
		ActiveTrap(OtherActor); //부딪힌 Trap의 ActiveTrap함수 호출 (OtherActor는 Player_Mario)
		ActiveTrap();
	}
}