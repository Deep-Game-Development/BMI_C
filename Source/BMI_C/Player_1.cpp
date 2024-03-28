// Fill out your copyright notice in the Description page of Project Settings.
#include "Player_1.h"
#include "BMI_CPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/BlendSpaceBase.h"
#include "EnhancedInputComponent.h"
#include "DSP/IntegerDelay.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Physics/ImmediatePhysics/ImmediatePhysicsShared/ImmediatePhysicsCore.h"
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
	// Get character movement component 
	PlayerCharacterMovementComponent = GetCharacterMovement() ;
}



// Called every frame
void APlayer_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Set player speed with checking the state of player (running / walking)
	if (IsRunning)
	{
		PlayerCharacterMovementComponent -> MaxWalkSpeed = RunSpeed;
	}
	else
	{
		PlayerCharacterMovementComponent -> MaxWalkSpeed = WalkSpeed;

	}
}



//  bind functionality to input
void APlayer_1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Binding sprint actions
		//WASD
		EnhancedInputComponent->BindAction(PlayerInputMove , ETriggerEvent::Triggered , this , &APlayer_1::PlayerMove) ;
		//mouse
		EnhancedInputComponent->BindAction(PlayerInputLook , ETriggerEvent::Triggered , this , &APlayer_1::PlayerLook) ;
		//Space
		EnhancedInputComponent->BindAction(PlayerInputJump , ETriggerEvent::Started , this , &APlayer_1::PlayerJump) ;
		//Shift
		EnhancedInputComponent->BindAction(PlayerInputDash , ETriggerEvent::Triggered , this , &APlayer_1::PlayerDash ) ; 
	}
}



// Walk 
void APlayer_1::PlayerMove(const FInputActionValue& InputValue)
{
	//Getting direction of the player 
	Direction = InputValue.Get<FVector2d>();
	DirectionX = Direction.X ;
	DirectionY = Direction.Y ;
	
	// check if player can run 
	if(Direction.Y == 1)
	{
		IsGoingForward =  true ; 
	}
	else
	{
		IsGoingForward = false ;
		IsRunning = false ;
	}
	
	// Get player Velocity
	PlayerVelocity = PlayerCharacterMovementComponent -> GetLastUpdateVelocity().Size() ;
	
	//Check if player stop : player cant run 
	if (PlayerVelocity == 0 )
	{
		IsRunning = false ; 
	}
	
	//to set extra rotation amount for dash 
	calculateExtraRotationAmount() ;
	
	// Walk function 
	AddMovementInput(GetActorForwardVector()*Direction.Y);
	AddMovementInput(GetActorRightVector()*Direction.X) ;
}


// Set looking direction 
void APlayer_1::PlayerLook(const FInputActionValue& InputValue)
{
	FVector2d CameraRotation = InputValue.Get<FVector2d>();
	AddControllerPitchInput(CameraRotation.Y * -1 * CameraRotationRate);
	AddControllerYawInput(CameraRotation.X * CameraRotationRate);
}



// Jump function 
void APlayer_1::PlayerJump(const FInputActionValue& InputValue)
{
	bool Jumped = InputValue.Get<bool>();
	if (Jumped)
	{
		if (FirstJump)
		{
			Jump() ;
			FirstJump = false;
			Jumps ++ ;
		}
		else
		{
			if (Jumps == 1)
			{
				LaunchCharacter(FVector(0.0f, 0.0f , SecondJumpZvelocity) , false , true) ;
				Jumps ++ ;
			}
		}
	}
}



// Set first Jump value when player landed in the ground
void APlayer_1::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	FirstJump = true;
	Jumps = 0 ; 
}



// Dash and Running state
void APlayer_1::PlayerDash(const FInputActionValue& InputValue)
{
	if(IsGoingForward)
	{
		IsRunning = true ;
	}
	//Dash 
	/*else
	{
		bool Dashed = InputValue.Get<bool>();
		bool PlayerIsFalling = GetCharacterMovement()->IsFalling() ;
	
		if (Dashed && Dashed_1 == false && PlayerIsFalling && IsGoingForward==false )
		{
			PlayerCharacterMovementComponent ->GravityScale = 0 ;
		
			FRotator direction = GetActorRotation() ;
			direction.Yaw = direction.Yaw + ExtraRotationAmount_1 ;
			PlayerVelocityForDash = direction.Vector() ; 
			LaunchCharacter(PlayerVelocityForDash*(DashDistance / 4), true , true );
			Dashed_1 = true ;
			FTimerHandle DashTimer ;
			FTimerHandle DashFalling ;
			GetWorldTimerManager().SetTimer(DashFalling , this , &APlayer_1::TurnOnGravityForDash  , 0.3 , false ) ;	
			GetWorldTimerManager().SetTimer(DashTimer , this , &APlayer_1::DashDelay  , 1.0f , false ) ;
		}
		if (Dashed && Dashed_1 == false && PlayerIsFalling == false && IsGoingForward == false  )
		{
		
			FRotator direction = GetActorRotation() ;
			direction.Yaw = direction.Yaw + ExtraRotationAmount_1 ;
			PlayerVelocityForDash = direction.Vector() ; 
			LaunchCharacter(PlayerVelocityForDash*DashDistance , true , true );
			Dashed_1 = true ;
			FTimerHandle DashTimer ;
			GetWorldTimerManager().SetTimer(DashTimer , this , &APlayer_1::DashDelay  , 1.0f , false ) ;
		}
	}*/
}



//Turn Gravity of for dashing 
/*
void APlayer_1::TurnOnGravityForDash()
{
	PlayerCharacterMovementComponent -> GravityScale = 1 ;
	float PlayerVelocityAmount = PlayerCharacterMovementComponent->GetLastUpdateVelocity().Size();
	
	if (PlayerVelocityAmount > MinSpeedAmountToStopDashing)
	{
		PlayerCharacterMovementComponent->AddForce(PlayerVelocityForDash*ForceToStopPlayerDashing*-1) ;		
	}

}*/
//Dash counter
/*
void APlayer_1::DashDelay()
{
	Dashed_1 = false ;
}
*/



// Calculating the way of moving of the player from WASD to apply extra amount of applying movement 
void APlayer_1::calculateExtraRotationAmount()
{

	if (Direction.X== 0 && Direction.Y==1)
	{
		ExtraRotationAmount_1 = 0 ;
	}
	if (Direction.X == 1 && Direction.Y==1)
	{
		ExtraRotationAmount_1 = 45 ;
	}
	if (Direction.X == 1 && Direction.Y==0 )
	{
		ExtraRotationAmount_1 = 90 ;
	}
	if (Direction.X == 1 && Direction.Y==-1)
	{
		ExtraRotationAmount_1 = 135 ;
	}
	if (Direction.X == 0 && Direction.Y==-1)
	{
		ExtraRotationAmount_1 = 180 ;
	}
	if (Direction.X == -1 && Direction.Y==-1)
	{
		ExtraRotationAmount_1 = 225 ;
	}
	if (Direction.X == -1 && Direction.Y==0)
	{
		ExtraRotationAmount_1 = 270 ;
	}
	if (Direction.X == -1 && Direction.Y==1)
	{
		ExtraRotationAmount_1 = 315 ;
	}
	
	
}

