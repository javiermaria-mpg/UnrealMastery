// // Made by Javier Maria

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UMMagicProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class UNREALMASTERY_API AUMMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AUMMagicProjectile();

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystemComponent> ParticleSystemComponent = nullptr;

	UPROPERTY(EditAnywhere)
	float InitialSpeed = 1000.f;
};
