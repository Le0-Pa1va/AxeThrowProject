// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Axe.generated.h"

class AAxeThrowProjectCharacter;
UCLASS()
class AXETHROWPROJECT_API AAxe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAxe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditDefaultsOnly, Category=Mesh)
	UStaticMeshComponent* AxeMesh;

	UPROPERTY(EditAnywhere, Category=Movement)
	float ThrowVelocity = 3000.f;
	
	UPROPERTY(EditAnywhere, Category=Movement)
	FRotator AxeThrowRotation = FRotator(-1000.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, Category=Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, Category=Movement)
	URotatingMovementComponent* AxeRotationMovement;

	UPROPERTY(VisibleAnywhere, Category=Throw)
	bool bWasThrown;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Recall)
	USplineComponent* AxeRecallSpline;

	UPROPERTY(EditAnywhere, Category=Recall)
	float RecallCurveLevel = -250.0f;

	UPROPERTY(EditAnywhere, Category=RecallTimeline)
	FTimeline RecallTimeline;

	UPROPERTY(EditAnywhere, Category=RecallTimeline)
	float TimeToComplete = 1;

	UPROPERTY(EditAnywhere, Category=RecallTimeline)
	UCurveFloat* AxeCurveFloat;

	UPROPERTY(EditAnywhere, Category=PlayerCharacter)
	AAxeThrowProjectCharacter* MainCharacter;

	UPROPERTY(VisibleAnywhere, Category=PlayerCharacter)
	USkeletalMeshComponent* ThrowerMesh;
	
	UFUNCTION()
	void ThrowAxe(FVector PlayerForwardVector);

	UFUNCTION(BlueprintCallable)
	void RecallAxe();
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void AxeTimelineProgress(float TrackValue);

	UFUNCTION()
	void OnTimelineFinished();
};
