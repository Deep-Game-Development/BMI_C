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
	Idling,
	Walking,
	DoubleJumping,
};

UCLASS()
class UCamera : public UCameraComponent
{
	GENERATED_BODY()

private:
	
	//Reference Camera Shake Types
	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> ShootShake;

	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> RunningShake;

	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> StartRunning;
	
	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> JumpingShake;

	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> FallingShake;

	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> LandingShake;

	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> IdlingShake;
	
	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> WalkingShake;

	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	TSubclassOf<UCameraShakeBase> DoubleJumpingShake;

	//Camera Shake Function
	UFUNCTION(BlueprintCallable, Category= "CameraShake")
	void CameraShake(ECameraShake ShakeType, ECameraShakePlaySpace PlaySpace);

	//Scale of Camera Shakes
	UPROPERTY(EditDefaultsOnly, Category= "CameraShake")
	float ShakeScale = 1;

	//Scale of Landing Camera Shake
	float LandingShakeScale = 1;

	//Calculate Velocity Function
	UFUNCTION(BlueprintCallable, Category= "CameraShake")
	void CalculateVelocity();
	
};
