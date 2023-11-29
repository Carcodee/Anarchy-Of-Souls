// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Tickeable.h"
#include "Logging/LogMacros.h"
#include "JamCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;


USTRUCT(BlueprintType)
struct FRefreshData
{
	GENERATED_BODY()

public:
	//~ The following member variable will be accessible by Blueprint Graphs:
	// This is the tooltip for our test variable.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RefreshType")
	bool IsOnRefresh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RefreshType")
	int WaitForRefresh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RefreshType")
	float CurrentTime;
};

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AJamCharacter : public ACharacter, public ITickeable
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
public:
	AJamCharacter();

protected:
	virtual void BeginPlay();

public:
		
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	bool bHasRifle;

	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetHasRifle(bool bNewHasRifle);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool GetHasRifle();

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int MaxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int MinDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float PaintingTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float HookTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float GroundGeneratorTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	bool IsTickeable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "stats")
	int TimeToRegenerateHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "stats")
	float CurrentTimeToRegenerateHp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RefreshType")
	TArray<FRefreshData> RefreshDataArray;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	bool GetCanRegeneateHP(float DeltaTime);
	
	//Util Funcs
public:
	virtual void TickDamage_Implementation(int Damage)override;

};


