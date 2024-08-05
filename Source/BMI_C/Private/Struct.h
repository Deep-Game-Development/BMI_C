#pragma once

#include "CoreMinimal.h"
#include "Struct.generated.h"

class UBehaviorTree;

//Define a Struct for enemies
USTRUCT(BlueprintType)
struct BMI_C_API FEnemyStruct: public  FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Enemy"))
	TObjectPtr<UClass> EnemyClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Weapon"))
	TObjectPtr<UClass> WeaponClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="BehaviorTree"))
	TObjectPtr<UBehaviorTree> BehaviorTree;
};
