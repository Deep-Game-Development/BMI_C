// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Melee.h"

#include "Components/CapsuleComponent.h"

AWeapon_Melee::AWeapon_Melee()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));
}
