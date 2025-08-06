// Created by Javier Maria


#include "UMCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

namespace
{
	FName ForwardAxis = FName("Forward");
	FName RightAxis = FName("Right");
	FName TurnAxis = FName("Turn");
	FName LookUpAxis = FName("LookUp");

	FName PrimaryAttackAction = FName("PrimaryAttack");
	FName SecondaryAttackAction = FName("SecondaryAttack");
	FName JumpAction = FName("Jump");
}

AUMCharacter::AUMCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;
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
	PlayerInputComponent->BindAxis(LookUpAxis, this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction(PrimaryAttackAction, IE_Pressed, this, &AUMCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction(SecondaryAttackAction, IE_Pressed, this, &AUMCharacter::SecondaryAttack);
	PlayerInputComponent->BindAction(JumpAction, IE_Pressed, this, &ACharacter::Jump);
}

void AUMCharacter::MoveForward(float Value)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.f;
	ControlRotation.Roll = 0.f;
	AddMovementInput(ControlRotation.Vector(), Value);
}

void AUMCharacter::MoveRight(float Value)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.f;
	ControlRotation.Roll = 0.f;

	AddMovementInput(FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y), Value);
}

void AUMCharacter::PrimaryAttack()
{
	FVector SpawnLocation;
	const USkeletalMeshComponent* MeshComponent = GetMesh();
	if (IsValid(MeshComponent) && MeshComponent->DoesSocketExist(PrimaryAttackSocket))
	{
		SpawnLocation = MeshComponent->GetSocketLocation(PrimaryAttackSocket);
	}
	else
	{
		SpawnLocation = GetActorLocation();
	}

	const FTransform SpawnTransform = FTransform(GetControlRotation(), SpawnLocation);
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(PrimaryAttackProjectileClass, SpawnTransform, SpawnParameters);
}

void AUMCharacter::SecondaryAttack()
{
}
