#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "RegisterAreaToFOW.generated.h"

class UBoxComponent;
class AFogOfWarManager;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FOWFORK_API URegisterAreaToFOW : public UActorComponent
{
	GENERATED_BODY()
	
public:

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*Select the FOW Manager*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FogOfWar)
		AFogOfWarManager* Manager = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FogOfWar)
		UBoxComponent* BoxArea = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FogOfWar, meta = (UseComponentPicker, AllowedClasses="BoxComponent"))
		FComponentReference BoxReference;

	/*Is the actor able to influence unfogged texels*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FogOfWar)
		bool WriteUnFog = true;
};