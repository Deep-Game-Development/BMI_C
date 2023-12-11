// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_1.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/BlendSpaceBase.h"
#include "EnhancedInputComponent.h"
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
	//Setup enhanced input
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer :: GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController -> GetLocalPlayer()))
		{
			Subsystem -> AddMappingContext(Player_1MapingContext , 0) ;
		}
	}
	
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
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Binding sprint actions 
		EnhancedInputComponent->BindAction(PlayerInputMove , ETriggerEvent::Triggered , this , &APlayer_1::PlayerMove) ;
		EnhancedInputComponent->BindAction(PlayerInputLook , ETriggerEvent::Triggered , this , &APlayer_1::PlayerLook) ;
		EnhancedInputComponent->BindAction(PlayerInputJump , ETriggerEvent::Triggered , this , &APlayer_1::PlayerJump) ;
	}
}

// Sprint functions
void APlayer_1::PlayerMove(const FInputActionValue& InputValue)
{
	FVector2d Direction = InputValue.Get<FVector2d>();
	AddMovementInput(GetActorForwardVector()*Direction.Y);
	AddMovementInput(GetActorRightVector()*Direction.X) ;
	
}
void APlayer_1::PlayerLook(const FInputActionValue& InputValue)
{
	FVector2d CameraRotation = InputValue.Get<FVector2d>();
	AddControllerPitchInput(CameraRotation.Y * -1 * RotationRate);
	AddControllerYawInput(CameraRotation.X * RotationRate);
}
void APlayer_1::PlayerJump(const FInputActionValue& InputValue)
{
	bool Jumped = InputValue.Get<bool>();
	if (Jumped)
	{
		Jump();
	}
}