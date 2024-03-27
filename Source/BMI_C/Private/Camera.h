// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Camera.generated.h"

//Define a Enum for different types of Shakes
UENUM(BlueprintType)
enum class ECameraShake : uint8
{
	Shooting,
	Running,
	StartRunning,
	Jumping,
	Falling,
	Landing,
	Dashing,
	Climbing,
	Idling,
	
};

/**
 * 
 */
UCLASS()
class UCamera : public UCameraComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();
	
	//Reference Camera Shake Types
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> ShootShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> RunningShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> StartRunning;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> JumpingShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> FallingShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> LandingShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> DashingShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> ClimbingShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> IdlingShake;
	
	//Camera Shake Function
	UFUNCTION(BlueprintCallable, Category= "CameraShake")
	void CameraShake(ECameraShake ShakeType);

	//Scale of Camera Shakes
	double ShakeScale = 1;

	//Calculate Velocity Function
	UFUNCTION(BlueprintCallable, Category= "CameraShake")
	void CalculateVelocity();
	
};
