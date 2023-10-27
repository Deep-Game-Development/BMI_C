// Copyright Epic Games, Inc. All Rights Reserved.

#include "BMI_CGameMode.h"
#include "BMI_CCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABMI_CGameMode::ABMI_CGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
