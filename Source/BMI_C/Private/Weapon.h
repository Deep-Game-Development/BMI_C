// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

private:
	UFUNCTION()
	virtual void Attack();

	UPROPERTY(EditDefaultsOnly)
	float Damage;
	
	UPROPERTY(EditInstanceOnly)
	UStaticMeshComponent* BaseMesh;
};
