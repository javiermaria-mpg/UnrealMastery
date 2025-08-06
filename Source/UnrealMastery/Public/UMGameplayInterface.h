// // Made by Javier Maria

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UMGameplayInterface.generated.h"

UINTERFACE(MinimalAPI)
class UUMGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

class UNREALMASTERY_API IUMGameplayInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);
};
