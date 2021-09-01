// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RotationSpeed)
{
	// Move the turret the right amount this frame
	// given a max rotation speed and the frame time
	auto Speed = FMath::Clamp<float>(RotationSpeed, -1.0f, +1.0f);
	auto RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;
	//auto Rotation = FMath::Clamp<float>(RawNewRotation, 0.f, 0.f);

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}