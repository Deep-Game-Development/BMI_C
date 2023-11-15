// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_1.h"

// Sets default values
APlayer_1::APlayer_1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayer_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayer_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayer_1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent -> BindAxis(TEXT("MoveForward") , this , &APlayer_1::MoveForward);
	PlayerInputComponent -> BindAxis(TEXT("LookUp") , this , &APlayer_1::LookUp);
	PlayerInputComponent -> BindAxis(TEXT("LookRight") , this , &APlayer_1::LookRight);
	PlayerInputComponent -> BindAxis(TEXT("MoveRight") , this , &APlayer_1::MoveRight);

	PlayerInputComponent -> BindAction(TEXT("Jump") ,IE_Pressed, this , &APlayer_1::JumpAction);
	
	
}

 void APlayer_1::MoveForward(float AxisValue)
 {
	 AddMovementInput(GetActorForwardVector() * AxisValue);
 }
void APlayer_1::LookUp(float CameraRotation)
{
	AddControllerPitchInput(CameraRotation);
}
void APlayer_1::LookRight(float CameraRotation)
{
	AddControllerYawInput(CameraRotation);
}
void APlayer_1::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue) ;
}
void APlayer_1::JumpAction()
{
	Jump();
}






