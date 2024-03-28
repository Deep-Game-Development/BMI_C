// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonShooter_1.h"

// Sets default values
AFirstPersonShooter_1::AFirstPersonShooter_1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonShooter_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonShooter_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonShooter_1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

