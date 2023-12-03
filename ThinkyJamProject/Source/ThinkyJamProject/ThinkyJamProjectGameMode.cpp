// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThinkyJamProjectGameMode.h"
#include "ThinkyJamProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThinkyJamProjectGameMode::AThinkyJamProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
