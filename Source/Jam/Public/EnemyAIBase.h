// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAIBase.generated.h"

UCLASS()
class JAM_API AEnemyAIBase : public ACharacter
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
	 float Health;
	 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	 float MaxHealth;
	 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	 float Speed;
	 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyStats")
	 float Damage;
	 // void TickDamage_Implementation(int Damage);
	


};
