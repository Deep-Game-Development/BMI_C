// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"

void UCamera::BeginPlay()
{
	Super::BeginPlay();

}


void UCamera::CameraShake(ECameraShake CameraShakeEnum)
{
	//Define a Value for Selected Enum Option
	TSubclassOf<UCameraShakeBase> SelectedCameraShake;

	//Switch on CameraShakeEnum
	switch (CameraShakeEnum)
	{
	case ECameraShake::Shooting:
		SelectedCameraShake = ShootShake;
		break;
	case ECameraShake::Other:
		break;
	}

	//Check SelectedCameraShake in not null
	if (SelectedCameraShake)
	{
		//Shake camera with selected shake option
		GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(SelectedCameraShake);
	}
}
