// Created by Javier Maria


#include "UMCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

namespace
{
	FName ForwardAxis = FName("Forward");
	FName RightAxis = FName("Right");
	FName TurnAxis = FName("Turn");
}

AUMCharacter::AUMCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void AUMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(ForwardAxis, this, &AUMCharacter::MoveForward);
	PlayerInputComponent->BindAxis(RightAxis, this, &AUMCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TurnAxis, this, &APawn::AddControllerYawInput);
}

void AUMCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AUMCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

