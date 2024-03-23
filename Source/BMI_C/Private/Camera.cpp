// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"

void UCamera::BeginPlay()
{
	Super::BeginPlay();

}


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
	case ECameraShake::Jumping:
		SelectedCameraShake = JumpingShake;
		break;
	case ECameraShake::Falling:
		SelectedCameraShake = FallingShake;
		break;
	case ECameraShake::Landing:
		SelectedCameraShake = LandingShake;
		break;
	case ECameraShake::Dashing:
		SelectedCameraShake = DashingShake;
		break;
	case ECameraShake::Climbing:
		SelectedCameraShake = ClimbingShake;
		break;
	case ECameraShake::Idling:
		SelectedCameraShake = IdlingShake;
		break;
	}

	//Check SelectedCameraShake in not null
	if (SelectedCameraShake)
	{
		//Shake camera with selected shake option
		GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake);
	}
}
