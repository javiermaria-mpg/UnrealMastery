// Created by Javier Maria

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UMMagicProjectile.h"
#include "UMCharacter.generated.h"

class UUMInteractionComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class UNREALMASTERY_API AUMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUMCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

	void PrimaryAttack();
	void SecondaryAttack();

	void PrimaryInteract();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AUMMagicProjectile> PrimaryAttackProjectileClass = nullptr;

	UPROPERTY(EditAnywhere)
	FName PrimaryAttackSocket;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AUMMagicProjectile> SecondaryAttackProjectileClass = nullptr;

	UPROPERTY(EditAnywhere)
	FName SecondaryAttackSocket;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UUMInteractionComponent> InteractionComponent = nullptr;
};
