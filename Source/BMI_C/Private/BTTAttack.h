// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTAttack.generated.h"

/**
 * 
 */
UCLASS()
class UBTTAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTAttack();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
