// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Tickeable.h"
#include "EnemyAIBase.generated.h"

UCLASS()
class JAM_API AEnemyAIBase : public ACharacter,public ITickeable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAIBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	int MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	int EnemyDamage;

	virtual void TickDamage_Implementation(int Damage)override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	bool IsTickeable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	int SpwanPosibility; ;
};
