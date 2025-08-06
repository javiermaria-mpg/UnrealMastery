// // Made by Javier Maria

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UMExplosiveActor.generated.h"

class URadialForceComponent;

UCLASS()
class UNREALMASTERY_API AUMExplosiveActor : public AActor
{
	GENERATED_BODY()

public:
	AUMExplosiveActor();
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<URadialForceComponent> RadialForceComponent = nullptr;
};
