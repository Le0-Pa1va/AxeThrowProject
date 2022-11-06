// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MainCharacter)
	TSubclassOf<AAxeThrowProjectCharacter> MainCharacter;

	UPROPERTY(VisibleAnywhere, Category=MainCharacter)
	USkeletalMeshComponent* MainCharacterMesh;

	UPROPERTY(EditAnywhere, Category=Movement)
	float ThrowVelocity = 3000.f;

	UFUNCTION(BlueprintCallable)
	virtual void ThrowAxe(FVector PlayerForwardVector);
};
