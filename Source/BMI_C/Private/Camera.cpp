// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"

void UCamera::BeginPlay()
{
	Super::BeginPlay();

}


void UCamera::CameraShake(TSubclassOf<UCameraShakeBase> ShakeBase)
{
	GetOwner()->GetInstigator()->GetLocalViewingPlayerController()->PlayerCameraManager->StartCameraShake(ShakeBase);
}

