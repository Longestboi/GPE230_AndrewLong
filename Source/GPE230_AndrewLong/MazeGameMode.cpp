// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGameMode.h"
#include "GameFramework/DefaultPawn.h"

void AMazeGameMode::InitGameState() {
    // run init from inherited class
    Super::InitGameState();
 
    if (DefaultPawnClass == ADefaultPawn::StaticClass()) {
        // Set the default Pawn to my pawn
        DefaultPawnClass = DefaultPlayerCharacter;
    }
}

