// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioGameInstance.h"

UMarioGameInstance::UMarioGameInstance()
{
	Life = 1;
}

void UMarioGameInstance::SaveLife(int32 NewLife)
{
	Life = NewLife;
}

int32 UMarioGameInstance::LoadLife()
{
	return Life;
}
