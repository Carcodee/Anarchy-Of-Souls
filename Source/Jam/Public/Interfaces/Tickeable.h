// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Tickeable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UTickeable : public UInterface
{
	GENERATED_BODY()
		
};

class ITickeable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "TickInterface")
	void TickDamage(int Damage);
};