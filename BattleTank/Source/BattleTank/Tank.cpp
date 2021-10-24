// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// No need to protect points as added at construction
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("abc: %s Tank C++ construct"), *TankName)
}

void ATank::BeginPlay() 
{
	Super::BeginPlay(); // Needed to run BP BeginPlay();
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("abc: %s C++ Begin Play"), *TankName)
}

void ATank::Fire()
{
	if (!ensure(Barrel)){ return;}

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

	// Spawn a projectile at socket location on the barrel
	
}


void ATank::AimAt(FVector OutHitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
}