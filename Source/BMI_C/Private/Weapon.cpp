// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

AWeapon::AWeapon()
{
	//Create a Static Mesh Component and make it root to set the weapon mesh to that
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	SetRootComponent(BaseMesh);
}

void AWeapon::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, "Attack");
}
