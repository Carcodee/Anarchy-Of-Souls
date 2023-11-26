// Copyright Epic Games, Inc. All Rights Reserved.

#include "JamGameMode.h"
#include "JamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJamGameMode::AJamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
