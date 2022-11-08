// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
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

	UPROPERTY(VisibleAnywhere, Category=MainCharacter)
	const USkeletalMeshSocket* AxeSocket;

	UPROPERTY(VisibleAnywhere, Category=MainCharacter)
	USkeletalMeshComponent* MainCharacterMesh;

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
	
	UFUNCTION()
	void ThrowAxe(AAxeThrowProjectCharacter* MainCharacter,FVector PlayerForwardVector);

	UFUNCTION()
	void RecallAxe();

	UFUNCTION()    
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
