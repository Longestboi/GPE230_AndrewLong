// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerUp.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"

APowerUp::APowerUp() {
	// Attach callback function to this instance.
	OnActorBeginOverlap.AddDynamic(this, &APowerUp::CheckActorType);
}

/// <summary> Overlap callback function </summary> 
void APowerUp::CheckActorType(
	class AActor* OverlappedActor,
	class AActor* OtherActor
) {
	// Execute OnCollection if the colliding object is a maze character
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) {
		this->OnCollection(dynamic_cast<AMazeCharacter*>(OtherActor));
	}
}

// Called every frame
void APowerUp::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	// If the respawn timer is not below zero, decrement the timer. 
	if((_respawnTimer > 0.0) && isDisabled) _respawnTimer -= DeltaTime;
	// If the timer is below zero, reenable this object.
	if (_respawnTimer <= 0.0) this->Reenable();
}

/// <summary> Reveal and enable the collision of this object. </summary>
void APowerUp::Reenable() {
	// Reveal in game and enable collision
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	
	// Unset diable flag
	isDisabled = false;
}

/// <summary> If the current object is respawnable, hide it and disable collision, else destroy the object. </summary>
void APowerUp::DisableOrKill() {
	if (!isRespawnable) this->Destroy();
	
	// Hide in game and disble collision
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	
	// Set the disabled flag
	isDisabled = true;
	
	// Reset the respawn timer.
	_respawnTimer = respawnTimerStart;
}
