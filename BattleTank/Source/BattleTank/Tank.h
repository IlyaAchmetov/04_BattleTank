// Copyright ILS Technologies Ltd

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// Forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


	UFUNCTION(BluePrintCallable, Category = "Firing")
	void Fire();

protected:

	virtual void BeginPlay() override;


private:
	
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;
	
	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr; // TODO remove

};
