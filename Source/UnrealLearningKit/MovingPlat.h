// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlat.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlat : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere,Category="Physics")
	FVector VelocidadeP = FVector(0,200,0);
	
	UPROPERTY(EditAnywhere,Category="Physics")
	float DistPercorrida = 500;
	
	UPROPERTY(VisibleAnywhere);
	float DistDeVoo = 0;

	UPROPERTY(EditAnywhere,Category="Physics")
	FRotator Giro;

	FVector PosInicial;

	void MovPlataforma(float DeltaTime);
	void GirarPlataforma(float DeltaTime);

	bool VoltaOuNVolta()const;
	float DistMovida()const;
};
