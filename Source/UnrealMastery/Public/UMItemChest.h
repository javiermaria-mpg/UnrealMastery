// // Made by Javier Maria

#pragma once

#include "CoreMinimal.h"
#include "UMGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "UMItemChest.generated.h"

UCLASS()
class UNREALMASTERY_API AUMItemChest : public AActor, public IUMGameplayInterface
{
	GENERATED_BODY()

public:
	AUMItemChest();

	void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BodyMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> LidMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	FRotator LidRelativeRotationWhenClosed = FRotator(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere)
	FRotator LidRelativeRotationWhenOpen = FRotator(110.f, 0.f, 0.f);
};
