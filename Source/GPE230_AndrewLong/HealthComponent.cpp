// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "GameFramework/Character.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UHealthComponent::BeginPlay() {
	Super::BeginPlay();
	
	_currentHealth = maxHealth;
	UE_LOG(LogTemp, Log, TEXT("Player Health: %f"), _currentHealth);
	
	// Add function to damage taking delegate 
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

/// <summary>Custom TakeDamage delagate function</summary>
void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser) {
	// if dead, return home early
	// We're not allocating memory on the heap so it's fine.
	if (_isDead) return;
	
	_currentHealth -= Damage;
	
	UE_LOG(LogTemp, Log, TEXT("Player took %f damage. %f health remaining."), Damage, _currentHealth);
	
	if (_currentHealth <= 0.0) Die();
	
	return;
}

/// <summary>The death sequence of the parent actor</summary>
void UHealthComponent::Die() {
	_isDead = true;
	_currentHealth = 0.0;
	
	// Play animation on owner
	Cast<ACharacter>(GetOwner())->GetMesh()->PlayAnimation(_deathAnim, false);
};

