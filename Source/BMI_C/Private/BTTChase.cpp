// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTChase.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "Navigation/PathFollowingComponent.h"


UBTTChase::UBTTChase()
{
	//Set the Default name of the Node
	NodeName = "Chase";
}

EBTNodeResult::Type UBTTChase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type ResultFromSuperExecution = Super::ExecuteTask(OwnerComp, NodeMemory);
	
	if (ResultFromSuperExecution == EBTNodeResult::Succeeded)
	{
		if (OwnerComp.GetAIOwner())
		{
			//Define Variables for MoveTo request
			AAIController* AIController = OwnerComp.GetAIOwner();
			FNavPathSharedPtr NavPathShared;
			FAIMoveRequest MoveRequest;

			//Set variables of MoveRequest
			MoveRequest.SetGoalActor(Cast<const AActor>(OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetValueAsObject(TargetActor.SelectedKeyName)));
			MoveRequest.SetAcceptanceRadius(AcceptanceRadius);

			//Run MoveTo request
			AIController->MoveTo(MoveRequest, &NavPathShared);
			
			return EBTNodeResult::Succeeded;
		}
		return EBTNodeResult::InProgress;
	}
	return EBTNodeResult::Failed;
}
