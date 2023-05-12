// Copyright Epic Games, Inc. All Rights Reserved.

#include "GPE230_AndrewLongGameMode.h"
#include "GPE230_AndrewLongCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGPE230_AndrewLongGameMode::AGPE230_AndrewLongGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
