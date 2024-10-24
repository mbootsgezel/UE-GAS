

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAS_EXAMPLE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Game|Player")
    void SetMousePosition(float LocationX, float LocationY);
};
