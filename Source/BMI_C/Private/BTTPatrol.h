// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTPatrol.generated.h"

/**
 * 
 */
UCLASS()
class UBTTPatrol : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTTPatrol();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere)
	float SearchRadius = 1000;

	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 120;
};
