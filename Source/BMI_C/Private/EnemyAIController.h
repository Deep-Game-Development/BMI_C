// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	//Set the Behavior Tree in Blueprint to run that
	UPROPERTY(EditDefaultsOnly)
	UDataTable* EnemyDataTable;
};
