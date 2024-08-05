// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Engine/DataTable.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Struct.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	//Define an Array of Name and store row names of EnemyDataTable
	TArray<FName> RowNames;
	UDataTableFunctionLibrary::GetDataTableRowNames(EnemyDataTable, RowNames);

	//Create a ContextString for Enemy (useful for debugging)
	static const FString EnemyContextString = (TEXT("Enemy Context"));

	//Make a loop on row names to find the correct BehaviorTree
	for (FName RowName : RowNames)
	{
		//Find the row with RowName and store it in a variable
		FEnemyStruct* EnemyDataTableRow = EnemyDataTable->FindRow<FEnemyStruct>(RowName, EnemyContextString, true);

		//Check the EnemyClass of row whit instigator class
		if (EnemyDataTableRow->EnemyClass == GetInstigator()->GetClass())
		{
			//Run the correct Behavior Tree and break the loop
			RunBehaviorTree(EnemyDataTableRow->BehaviorTree);
			break;
		}
	}
}
