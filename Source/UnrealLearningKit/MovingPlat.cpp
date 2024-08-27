// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlat.h"

// Sets default values
AMovingPlat::AMovingPlat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlat::BeginPlay()
{
	Super::BeginPlay();

	PosInicial = GetActorLocation();

	FString AssetName = GetName();
}

// Called every frame
void AMovingPlat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovPlataforma(DeltaTime);

	GirarPlataforma(DeltaTime);
}

void AMovingPlat::MovPlataforma(float DeltaTime)
{
	FVector Plataforma1 = GetActorLocation();
		if (VoltaOuNVolta()) 
		{
			float OverShoot = DistPercorrida - DistDeVoo;
			UE_LOG(LogTemp, Display, TEXT("Distância ultrapassada: %s, %f"), *GetName(), OverShoot); //Debug de distância
			
			FVector DirMov = VelocidadeP.GetSafeNormal();
			PosInicial = PosInicial + DirMov * DistPercorrida;
			SetActorLocation(Plataforma1);
			VelocidadeP = -VelocidadeP;
		}
		else
		{
			Plataforma1 = Plataforma1 + VelocidadeP * DeltaTime;
			SetActorLocation(Plataforma1);
		}
}

void AMovingPlat::GirarPlataforma(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("%s girando pro lado"), *GetName());
	AddActorLocalRotation(Giro * DeltaTime);
}

bool AMovingPlat::VoltaOuNVolta()const
{
	return DistMovida() > DistPercorrida;
}

float AMovingPlat::DistMovida()const
{
	return FVector::Dist(PosInicial, GetActorLocation());
}
