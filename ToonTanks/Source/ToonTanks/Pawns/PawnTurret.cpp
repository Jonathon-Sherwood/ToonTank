// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());

}

void APawnTurret::CheckFireCondition()
{
	//If Player == Null || Is Dead then Stop
	if (!PlayerPawn) 
	{
		return;
	}
	//If Player IS in range Then Fire
	if (ReturnDistanceToPlayer() <= FireRange) 
	{
		//Fire
		Fire();
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	//If Player == Null || Is Dead then Stop
	if (!PlayerPawn)
	{
		return 0;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
	//If Player IS in range Then Fire
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}