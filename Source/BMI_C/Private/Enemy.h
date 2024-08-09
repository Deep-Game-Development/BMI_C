// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "Enemy.generated.h"


UCLASS()
class AEnemy : public ACharacter
{
	GENERATED_BODY()

public:	
	AEnemy();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	//Create PawnSensing component
	UPROPERTY(EditInstanceOnly)
	UPawnSensingComponent* PawnSensing;

	//Create a function to run when see a pawn
	UFUNCTION()
	virtual	void OnPawnSeen(APawn* SeenPawn);
	
	UPROPERTY(EditDefaultsOnly)
	FName SeenPlayerBlackBoardKeyName = "SeenPlayer";

};
