// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	ATank* GetControlledTank() const;
	//start the tank moving the barrel towards so that a shot would hit where crosshair intersects the world
	void AimTowardsCrosshair();

	// Return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	FVector2D ScreenLocation(float x, float y);

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5; //+

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333; //+


	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};