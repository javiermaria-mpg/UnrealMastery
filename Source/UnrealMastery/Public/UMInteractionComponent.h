// // Made by Javier Maria

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UMInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALMASTERY_API UUMInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UUMInteractionComponent();
	
	void PrimaryInteract();

protected:
	UPROPERTY(EditAnywhere)
	float InteractionRange = 500.f;

	UPROPERTY(EditAnywhere)
	float SweepSphereRadius = 50.f;
};
