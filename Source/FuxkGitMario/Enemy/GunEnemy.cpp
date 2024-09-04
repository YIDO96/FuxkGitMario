// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/GunEnemy.h"


AGunEnemy::AGunEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGunEnemy::BeginPlay()
{
	Super::BeginPlay();
}


void AGunEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime += DeltaTime;
	if(CurrentTime >= FireRate)
	{
		Fire();
		CurrentTime = 0.0f;
	}
}

void AGunEnemy::Fire()
{
	ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BulletFactory, GetActorLocation(), GetActorRotation());
}
