// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/Tickeable.h"
#include "EnemyBase.generated.h"

UCLASS()
class JAM_API AEnemyBase : public APawn, ITickeable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	float Damage;

	virtual void TickDamage_Implementation(int Damage)override;

};
