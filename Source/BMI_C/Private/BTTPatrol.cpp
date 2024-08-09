// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTPatrol.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"

class UNavigationSystemV1;

UBTTPatrol::UBTTPatrol()
{
	//Set the Default name of the Node
	NodeName = "Patrol";
}

EBTNodeResult::Type UBTTPatrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type ResultFromSuperExecution = Super::ExecuteTask(OwnerComp, NodeMemory);

	if (ResultFromSuperExecution == EBTNodeResult::Succeeded)
	{
		if (OwnerComp.GetWorld())
		{
			//Define a NavigationSystemV1 to use it for Get RandomReachablePoint
			UNavigationSystemV1* NavigationSystemV1 = UNavigationSystemV1::GetCurrent(OwnerComp.GetOwner()->GetWorld());
			if (NavigationSystemV1)
			{
				//Define Variables for MoveTo request
				FVector StartLocation = OwnerComp.GetOwner()->GetActorLocation();
				FNavLocation EndLocation = FNavLocation(StartLocation);
				AAIController* AIController = OwnerComp.GetAIOwner();
				FNavPathSharedPtr NavPathShared;
				FAIMoveRequest MoveRequest;
				
				//Set variables of MoveRequest
				MoveRequest.SetAcceptanceRadius(AcceptanceRadius);
				
				if (NavigationSystemV1->GetRandomReachablePointInRadius(StartLocation,SearchRadius ,EndLocation))
				{
					//Set the RandomReachablePoint for the MoveRequest goal and run the request
					MoveRequest.SetGoalLocation(EndLocation);
					AIController->MoveTo(MoveRequest, &NavPathShared);
					
					return EBTNodeResult::Succeeded;
				}
				return EBTNodeResult::Aborted;
			}
			return EBTNodeResult::InProgress;
		}
	}
	return EBTNodeResult::Failed;
}
