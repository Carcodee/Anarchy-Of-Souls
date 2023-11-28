// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIBase.h"

// Sets default values
AEnemyAIBase::AEnemyAIBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAIBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAIBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAIBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// void AEnemyBase::TickDamage_Implementation(int Damage)
// {
// 	if (Health > 0)
// 	{
// 		Health -= Damage;
// 		// Health=FMath::Clamp(Health, 0, MaxHealth);
// 		
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("Enemy is dead!"));
// 	}
// }