// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIBase.h"

#include "GameFramework/GameModeBase.h"

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
	IsTickeable=true;
	
}

// Called every frame
void AEnemyAIBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//add delay

	
}

// Called to bind functionality to input
void AEnemyAIBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAIBase::TickDamage_Implementation(int Damage)
{

	if (IsTickeable)
	{
		if (Health > 0)
		{
			Health -= Damage;
			Health=FMath::Clamp(Health, 0, MaxHealth);
			// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Enemy Health: %d"), Health));
			IsTickeable=false;

		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Dead")));
			AMyRoundGameMode* const MyGameMode = GetWorld()->GetAuthGameMode<AMyRoundGameMode>();
			MyGameMode->EnemiesKilled++;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Enemies Killed: %d"), MyGameMode->EnemiesKilled));
			Destroy();
		}
	}
}