// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player_1.generated.h"

UCLASS()
class BMI_C_API APlayer_1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayer_1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	//Move Functions :
	//Computer Controller
	void MoveForward(float AxisValue);
	void LookUp(float CameraRotation);
	void MoveRight(float AxisValue);
	void LookRight(float CameraRotation);
	void JumpAction();

	//Gamepad Controller
	void LookUpController(float CameraRotation);
	void LookRightController(float CameraRotation); 


	// Move Variables :
	UPROPERTY(EditAnywhere)
	float RotationRate = 100.0 ;

};
