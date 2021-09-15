// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BluePrintCallable, Category = Setup)
	void SetReference(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BluePrintCallable, Category = Firing)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.0f;

	// Local barrel reference for spawning a projectile
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	

	double LastFireTime = 0;
};
