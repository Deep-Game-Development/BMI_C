// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

AWeapon::AWeapon()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	SetRootComponent(BaseMesh);
}

void AWeapon::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, "Attack");
}
