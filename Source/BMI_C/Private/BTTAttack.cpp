// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTAttack.h"
#include "Weapon.h"

UBTTAttack::UBTTAttack()
{
	//Set the Default name of the Node
	NodeName = "Attack";
}

EBTNodeResult::Type UBTTAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetOwner()->GetInstigator())
	{
		//Get the all child of owner actor
		TArray<AActor*> ChildActors;
		OwnerComp.GetOwner()->GetInstigator()->GetAllChildActors(ChildActors, true);

		//Make a loop to run Attack func in all of owned weapons
		for (AActor* ChildActor : ChildActors)
		{
			//Check if the ChildActor is a Weapon
			if (ChildActor->GetClass()->IsChildOf(AWeapon::StaticClass()))
			{
				//Cast to AWeapon and run the Attack func
				if (AWeapon* Weapon = Cast<AWeapon>(ChildActor))
				{
					Weapon->Attack();
				}
			}
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
