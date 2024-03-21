// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Camera.generated.h"

/**
 * 
 */
UCLASS()
class UCamera : public UCameraComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();
	
	//Camera Shake Func
	UFUNCTION(BlueprintCallable, Category= "CameraShake")
	void CameraShake(TSubclassOf<UCameraShakeBase> ShakeBase);
	
};
