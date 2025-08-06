// // Made by Javier Maria


#include "UMExplosiveActor.h"

#include "PhysicsEngine/RadialForceComponent.h"

AUMExplosiveActor::AUMExplosiveActor()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	RootComponent = StaticMeshComponent;

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("Radial Force");
	RadialForceComponent->SetupAttachment(RootComponent);
}

void AUMExplosiveActor::BeginPlay()
{
	Super::BeginPlay();

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &AUMExplosiveActor::OnComponentHit);
}

void AUMExplosiveActor::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (HitComponent != StaticMeshComponent)
	{
		return;
	}

	RadialForceComponent->FireImpulse();
}
