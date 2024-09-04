// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZone.h"

#include "Components/BoxComponent.h"
#include "Interface/MarioInterface.h"
#include "Trap/TrapBase.h"

// Sets default values
AKillZone::AKillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("KillZoneBody"));
	SetRootComponent(BoxComp);
	BoxComp->SetBoxExtent(FVector(50.0f));
	
	BoxComp->SetCollisionProfileName(TEXT("KillZone"));
	BoxComp->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AKillZone::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AKillZone::OnKillZoneOverlap);
	
}

// Called every frame
void AKillZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKillZone::OnKillZoneOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 충돌한 액터가 플레이어라면
	auto player = Cast<IMarioInterface>(OtherActor);
	if (player)
	{
		player->Die();
	}

	// 충돌한 액터가 Trap이라면
	auto trap = Cast<ATrapBase>(OtherActor);
	if (trap)
	{
		OtherActor->SetActorLocation(trap->StartLocation);
	}
	//OtherActor->Destroy();
}