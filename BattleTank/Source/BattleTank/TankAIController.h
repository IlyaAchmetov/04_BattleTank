// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"

// Forward declarations
class UTankAimingComponent;
class APawn;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

protected:

	UPROPERTY(EditAnywhere, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptenceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnPossesedTankDeath();
	//How close can the AI tank get to the player

};