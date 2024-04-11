// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCamera::CameraShake(ECameraShake ShakeType)
{
	//Define a Value for Selected Enum Option
	TSubclassOf<UCameraShakeBase> SelectedCameraShake;

	//Switch on CameraShakeEnum
	switch (ShakeType)
	{
	case ECameraShake::Shooting:
		SelectedCameraShake = ShootShake;
		break;
	case ECameraShake::Running:
		SelectedCameraShake = RunningShake;
		break;
	case ECameraShake::StartRunning:
		SelectedCameraShake = StartRunning;
		break;
	case ECameraShake::Jumping:
		SelectedCameraShake = JumpingShake;
		break;
	case ECameraShake::Falling:
		SelectedCameraShake = FallingShake;
		break;
	case ECameraShake::Landing:
		SelectedCameraShake = LandingShake;
		break;
	case ECameraShake::Idling:
		SelectedCameraShake = IdlingShake;
		break;
	}

	//Check SelectedCameraShake in not null
	if (SelectedCameraShake)
	{
		//Shake camera with selected shake option
		GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake, ShakeScale);
	}
	
	//Check if ShakeType is Landing
	if (ShakeType == ECameraShake::Landing)
	{
		//Reset ShakeScale Value
		ShakeScale = 1;
	}
}

void UCamera::CalculateVelocity()
{
	//Define Variables for Formula
	const float LandingVelocity = GetOwner()->GetVelocity().Z * -1;
	const float JumpVelocity = Cast<ACharacter>(GetOwner()->GetInstigator())->GetCharacterMovement()->JumpZVelocity;
	const float VelocityDifference = (LandingVelocity - JumpVelocity);
	constexpr  float DefaultShake = 1;
	constexpr  float BoostVelocityRange = 1.5;
	constexpr  float MinShake = 0.2;

	//Calculate Formula
	ShakeScale = FMath().Max(MinShake, DefaultShake + ((VelocityDifference * BoostVelocityRange) / JumpVelocity));
}
