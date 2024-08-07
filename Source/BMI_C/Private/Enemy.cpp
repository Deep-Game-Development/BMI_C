// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemy::AEnemy()
{
	//Add PawnSensing component
	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensor"));
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	//Bind PawnSensing OnSeePawn delegate to OnPawnSeen function
	PawnSensing->OnSeePawn.AddDynamic(this, &AEnemy::OnPawnSeen);
}

void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy::OnPawnSeen(APawn* SeenPawn)
{
	//Set SeenPlayer value in Blackboard when seen a paawn
	Cast<AAIController>(GetController())->GetBlackboardComponent()->SetValueAsBool(SeenPlayerBlackBoardKeyName, true);
}
