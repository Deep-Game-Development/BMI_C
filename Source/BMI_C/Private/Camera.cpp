#include "Camera.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

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
	}

	//Check SelectedCameraShake in not null
	if (SelectedCameraShake)
	{
		if (ShakeType == ECameraShake::Landing)
		{
			//Shake camera with selected shake option
			GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake, LandingShakeScale, PlaySpace);
		}
		else
		{
			//Shake camera with selected shake option
			GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake, ShakeScale, PlaySpace);
		}
	}
	
	//Reset LandingShakeScale Value
	LandingShakeScale = 1;
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
	LandingShakeScale = FMath().Max(MinShake, DefaultShake + ((VelocityDifference * BoostVelocityRange) / JumpVelocity));
}
