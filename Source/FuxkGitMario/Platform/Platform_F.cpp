// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/Platform_F.h"
#include "Components/StaticMeshComponent.h"

APlatform_F::APlatform_F()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_F(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_F.SM_Platform_F'"));
	if (defaultMesh_F.Succeeded())
	{
		PlatformMeshes.Add("F", defaultMesh_F.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_U(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_u.SM_Platform_u'"));
	if (defaultMesh_U.Succeeded())
	{
		PlatformMeshes.Add("U", defaultMesh_U.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_X(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_x.SM_Platform_x'"));
	if (defaultMesh_X.Succeeded())
	{
		PlatformMeshes.Add("X", defaultMesh_X.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_K(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_k.SM_Platform_k'"));
	if (defaultMesh_K.Succeeded())
	{
		PlatformMeshes.Add("K", defaultMesh_K.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_G(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_G.SM_Platform_G'"));
	if (defaultMesh_G.Succeeded())
	{
		PlatformMeshes.Add("G", defaultMesh_G.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_I(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_i.SM_Platform_i'"));
	if (defaultMesh_I.Succeeded())
	{
		PlatformMeshes.Add("I", defaultMesh_I.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_T(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_t.SM_Platform_t'"));
	if (defaultMesh_T.Succeeded())
	{
		PlatformMeshes.Add("T", defaultMesh_T.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_M(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_M.SM_Platform_M'"));
	if (defaultMesh_M.Succeeded())
	{
		PlatformMeshes.Add("M", defaultMesh_M.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_A(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_a.SM_Platform_a'"));
	if (defaultMesh_A.Succeeded())
	{
		PlatformMeshes.Add("A", defaultMesh_A.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_R(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_r.SM_Platform_r'"));
	if (defaultMesh_R.Succeeded())
	{
		PlatformMeshes.Add("R", defaultMesh_R.Object);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>defaultMesh_O(TEXT("/Script/Engine.StaticMesh'/Game/Blueprints/Platform/StaticMesh/SM_Platform_o.SM_Platform_o'"));
	if (defaultMesh_O.Succeeded())
	{
		PlatformMeshes.Add("O", defaultMesh_O.Object);
	}
}

void APlatform_F::BeginPlay()
{
	Super::BeginPlay();
	
	switch (PlatformType)
	{
	case EPlatformType::Platform_Default:
		break;
	case EPlatformType::Platform_F:
		MeshComp->SetStaticMesh(PlatformMeshes["F"]);
		break;
	case EPlatformType::Platform_U:
		MeshComp->SetStaticMesh(PlatformMeshes["U"]);
		break;
	case EPlatformType::Platform_X:
		MeshComp->SetStaticMesh(PlatformMeshes["X"]);
		break;
	case EPlatformType::Platform_K:
		MeshComp->SetStaticMesh(PlatformMeshes["K"]);
		break;
	case EPlatformType::Platform_G:
		MeshComp->SetStaticMesh(PlatformMeshes["G"]);
		break;
	case EPlatformType::Platform_I:
		MeshComp->SetStaticMesh(PlatformMeshes["I"]);
		break;
	case EPlatformType::Platform_T:
		MeshComp->SetStaticMesh(PlatformMeshes["T"]);
		break;
	case EPlatformType::Platform_M:
		MeshComp->SetStaticMesh(PlatformMeshes["M"]);
		break;
	case EPlatformType::Platform_A:
		MeshComp->SetStaticMesh(PlatformMeshes["A"]);
		break;
	case EPlatformType::Platform_R:
		MeshComp->SetStaticMesh(PlatformMeshes["R"]);
		break;
	case EPlatformType::Platform_O:
		MeshComp->SetStaticMesh(PlatformMeshes["O"]);
		break;
	}
}

void APlatform_F::Platform_F()
{
	
}

void APlatform_F::Platform_U()
{
	
}

void APlatform_F::Platform_X()
{
	
}

void APlatform_F::Platform_K()
{
	
}

void APlatform_F::Platform_G()
{
	
}

void APlatform_F::Platform_I()
{
	
}

void APlatform_F::Platform_T()
{
	
}

void APlatform_F::Platform_M()
{
	
}

void APlatform_F::Platform_A()
{
	
}

void APlatform_F::Platform_R()
{
	
}

void APlatform_F::Platform_O()
{
	
}
