#include "Camera.h"

void UCamera::CameraShake(ECameraShake ShakeType, ECameraShakePlaySpace PlaySpace)
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
	case ECameraShake::Walking:
		SelectedCameraShake = WalkingShake;
		break;
	case ECameraShake::DoubleJumping:
		SelectedCameraShake = DoubleJumpingShake;
		break;
	}

	//Check SelectedCameraShake in not null
	if (SelectedCameraShake)
	{
		if (ShakeType == ECameraShake::Landing)
		{
			//Landing Shake with Specific Scale
			GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake, LandingShakeScale, PlaySpace);
		}
		else
		{
			//Shake camera with selected shake option
			GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake, ShakeScale, PlaySpace);
		}
	}
}

void UCamera::CalculateVelocity()
{
	//Define Variables for Formula
	const float LandingVelocity = GetOwner()->GetVelocity().Z * -1;
	constexpr float MinShake = 1;
	constexpr float MaxShake = 4;
	constexpr float Devide = 450;

	//Limit Scale to MinShake and MaxShake
	const float Formula = FMath().Clamp(LandingVelocity / Devide, MinShake, MaxShake);
	
	LandingShakeScale = Formula;
}
