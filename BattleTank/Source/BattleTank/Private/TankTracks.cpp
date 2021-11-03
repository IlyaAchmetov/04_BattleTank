// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTracks.h"

UTankTracks::UTankTracks()

{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTracks::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)

{
	// calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	// work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	// calculate and apply sideways force (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::SetThrottle(float Throttle)

{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
};