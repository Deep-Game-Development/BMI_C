// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Melee.h"
#include "Components/CapsuleComponent.h"

AWeapon_Melee::AWeapon_Melee()
{
	//Create a Capsule Component to make a collision for the melee weapon
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));
}
