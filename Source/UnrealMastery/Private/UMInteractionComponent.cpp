// // Made by Javier Maria


#include "UMInteractionComponent.h"

#include "UMGameplayInterface.h"
#include "DrawDebugHelpers.h"

UUMInteractionComponent::UUMInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUMInteractionComponent::PrimaryInteract()
{
	FVector EyeLocation;
	FRotator EyeRotation;
	GetOwner()->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	const FVector End = EyeLocation + EyeRotation.Vector() * InteractionRange;
	
	FCollisionObjectQueryParams CollisionObjectQueryParams;
	CollisionObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	TArray<FHitResult> HitResults;
	const bool bBlockingHit = GetWorld()->SweepMultiByObjectType(HitResults, EyeLocation, End, FQuat::Identity, CollisionObjectQueryParams, FCollisionShape::MakeSphere(SweepSphereRadius));

	for (const FHitResult& HitResult : HitResults)
	{
		if (AActor* HitActor = HitResult.GetActor(); IsValid(HitActor))
		{
			if (HitActor->Implements<UUMGameplayInterface>())
			{
				APawn* OwnerAsPawn = Cast<APawn>(GetOwner());
				IUMGameplayInterface::Execute_Interact(HitActor, OwnerAsPawn);

				DrawDebugSphere(GetWorld(), HitResult.Location, SweepSphereRadius, 32, FColor::Green, false, 1.f, 0, 2.f);

				break; // Only activate the first interactable hit
			}
		}
	}

	DrawDebugLine(GetWorld(), EyeLocation, End, bBlockingHit ? FColor::Green : FColor::Red, false, 1.f, 0, 2.f);
}

