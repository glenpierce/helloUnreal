#include "MoveSceneComponent.h"

UMoveSceneComponent::UMoveSceneComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UMoveSceneComponent::BeginPlay() {
	Super::BeginPlay();

	StartRelativeLocation = GetAttachmentRoot()->GetRelativeLocation();
	EndRelativeLocation = StartRelativeLocation + MoveOffset;

}

void UMoveSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	updateLocation(DeltaTime);
	updateTarget();
}

void UMoveSceneComponent::updateLocation(float DeltaTime) {
	FVector CurrentRelativeLocation = GetAttachmentRoot()->GetRelativeLocation();
	FVector NewRelativeLocation = FMath::VInterpTo(CurrentRelativeLocation, EndRelativeLocation, DeltaTime, 1.0f);
	GetAttachmentRoot()->SetRelativeLocation(NewRelativeLocation);
}

void UMoveSceneComponent::updateTarget() {
	if(FVector::Dist(GetAttachmentRoot()->GetRelativeLocation(), EndRelativeLocation) < 0.1f) {
		const FVector Temp = StartRelativeLocation;
		StartRelativeLocation = EndRelativeLocation;
		EndRelativeLocation = Temp;
	}
}
