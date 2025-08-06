// // Made by Javier Maria


#include "UMItemChest.h"

// Sets default values
AUMItemChest::AUMItemChest()
{
	PrimaryActorTick.bCanEverTick = false;

	BodyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Body Mesh Component");
	RootComponent = BodyMeshComponent;

	LidMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Lid Mesh Component");
	LidMeshComponent->SetupAttachment(RootComponent);
}

void AUMItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMeshComponent->SetRelativeRotation(LidRelativeRotationWhenOpen);
}
