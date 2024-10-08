// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/Player_Mario.h"

// Sets default values
APlatformBase::APlatformBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Component Setting
	{
		BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
		SetRootComponent(BoxComp);
		BoxComp->SetBoxExtent(FVector(50));


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
		BoxComp->SetCollisionProfileName(TEXT("OverlapAll"));
		BoxComp->SetBoxExtent(FVector(50));
		MeshComp->SetCollisionProfileName(TEXT("Platform"));
	}
}

// Called when the game starts or when spawned
void APlatformBase::BeginPlay()
{
	Super::BeginPlay();

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &APlatformBase::OnTrapBoxOverlap);
}

// Called every frame
void APlatformBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformBase::ActiveEvent()
{
	IsActiveEvent = true;
}

void APlatformBase::OnTrapBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor); // OtherActor를 IMarioInterface로 형변환
	if (Mario) // 형변환이 성공했다면
	{
		ActiveEvent();
	}
}

