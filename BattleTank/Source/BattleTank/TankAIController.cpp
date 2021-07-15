// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing a Tank: %s"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));


	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(PlayerControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	
	return Cast<ATank>(PlayerPawn->GetPawn());
}