// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTChase.generated.h"

/**
 * 
 */
UCLASS()
class UBTTChase : public UBTTaskNode
{
	GENERATED_BODY()

	UBTTChase();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetActor;

	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 5;
	
};
