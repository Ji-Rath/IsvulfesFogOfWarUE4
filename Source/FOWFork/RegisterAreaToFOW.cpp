
#include "RegisterAreaToFOW.h"
#include "FogOfWarManager.h"
#include "Components/BoxComponent.h"

void URegisterAreaToFOW::BeginPlay()
{
	Super::BeginPlay();

	if (ensure(BoxReference.GetComponent(GetOwner())))
	{
		BoxArea = Cast<UBoxComponent>(BoxReference.GetComponent(GetOwner()));
	} 

	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Log, TEXT("I am alive %s"), *ObjectName);

	//registering the actor to the FOW Manager

	if (Manager != nullptr) {
		UE_LOG(LogTemp, Log, TEXT("Found Manager"));

		Manager->RegisterFowActor(GetOwner());
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Please attach a FOW Manager"));
	}
}

void URegisterAreaToFOW::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
