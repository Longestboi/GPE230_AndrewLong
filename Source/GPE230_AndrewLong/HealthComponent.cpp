// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	_currentHealth = maxHealth;
	UE_LOG(LogTemp, Log, TEXT("Player Health: %f"), _currentHealth);
	// ...
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType, AController *InstigateBy, AActor * DamageCauser) {
	_currentHealth -= Damage;
	
	UE_LOG(LogTemp, Log, TEXT("Player took %f damage. %f health remaining."), Damage, _currentHealth);
	
	if (_currentHealth <= 0.0) Die();
}
	
void UHealthComponent::Die() {

};
