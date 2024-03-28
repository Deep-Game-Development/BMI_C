// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player_1.generated.h"

class UInputMappingContext ;

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

	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Input)
	UInputMappingContext* Player_1MapingContext ;

	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Input)
	UInputAction* PlayerInputMove ;

	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Input)
	UInputAction* PlayerInputLook ;

	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Input)
    UInputAction* PlayerInputJump ; 

	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category = Input)
	UInputAction* PlayerInputDash ;

	UPROPERTY(EditAnywhere , BlueprintReadWrite , Category=Input )
	UInputAction* PlayerInputPressedF ; 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Landed(const FHitResult& Hit) override;
	
	UPROPERTY(BlueprintReadOnly)
	bool IsRunning ;
	UPROPERTY(BlueprintReadOnly)
	float DirectionX ;
	UPROPERTY(BlueprintReadOnly)
	float DirectionY ;
private:
	//Move Functions :
	void PlayerMove (const FInputActionValue& InputValue) ;
	void PlayerLook (const FInputActionValue& InputValue) ;
	void PlayerJump (const FInputActionValue& InputValue) ;
	void PlayerDash (const FInputActionValue& InputValue) ;
	void DashDelay ();
	void TurnOnGravityForDash() ;
	void calculateExtraRotationAmount () ;


	

	UCharacterMovementComponent*PlayerCharacterMovementComponent ;

	// Move Variables :
	UPROPERTY(EditAnywhere , Category="Movement")
	float CameraRotationRate = 10.0 ;
	
	UPROPERTY(EditAnywhere , Category="Movement")
	float DashDistance = 6000 ;

	UPROPERTY(EditAnywhere , Category= "Movement")
	float ForceToStopPlayerDashing  = 10 ;
		
	UPROPERTY(EditAnywhere , Category= "Movement")
	float MinSpeedAmountToStopDashing = 3000;
	
	UPROPERTY(EditAnywhere , Category= "Movement")
	float RunSpeed = 700;

	UPROPERTY(EditAnywhere , Category= "Movement")
	float WalkSpeed = 450;	

	bool IsGoingForward = false   ;
	
	
	float ExtraRotationAmount_1  ;

	FVector PlayerVelocityForDash ;
		
	FVector2d Direction ;

	bool Dashed_1 = false ;

	bool FirstJump = true ;

	int Jumps = 0 ; 
	UPROPERTY(EditAnywhere , Category="Movement") 
	float SecondJumpZvelocity  = 400.0f ;

	float PlayerVelocity ; 
		

};
