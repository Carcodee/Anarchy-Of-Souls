// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include "Jam/JamGameMode.h"
#include "MyRoundGameMode.generated.h"

/**
 * 
 */
UCLASS()
class JAM_API AMyRoundGameMode : public AJamGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnerStats")
	int MaxEnemiesPerRound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnerStats")
	int CurrentRound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnerStats")
	int EnemiesSpawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnerStats")
	int EnemiesKilled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnerStats")
	int WaitTimeBetweenRounds;	
};
