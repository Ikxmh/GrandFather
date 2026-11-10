// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FlashlightComp.h"
#include "HorrorPlayer.generated.h"


class UInputMappingContext;
class UInputAction;
class UFlashlightComp;

UCLASS()
class GRANDFATHER_API AHorrorPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHorrorPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UFlashlightComp> FlashlightComponent;

	// getting access to the inputaction mapping. and idk if this is correct
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> CrouchAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> FlashlightAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speeds")
	float CrouchSpeed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Movement|Speeds")
	float WalkSpeed = 600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Speeds")
	float SprintSpeed = 800.0f;

	// getting access to the Move and Look from template.
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	// For the Sprint and Crouch
	void StartSprinting();
	void StopSprinting();
	void StartCrouching();
	void StopCrouching();

	void OnFlashlightButtonPressed();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
