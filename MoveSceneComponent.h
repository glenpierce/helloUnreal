#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT01_API UMoveSceneComponent : public USceneComponent {
	GENERATED_BODY()

public:	
	UMoveSceneComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void updateLocation(float DeltaTime);

private:
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;
	FVector StartRelativeLocation;
	FVector EndRelativeLocation;
	void updateTarget();
};
