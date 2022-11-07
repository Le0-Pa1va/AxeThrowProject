// Fill out your copyright notice in the Description page of Project Settings.


#include "Axe.h"

#include "AxeThrowProject/AxeThrowProjectCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
AAxe::AAxe()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AxeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxeMesh"));
	RootComponent = AxeMesh;
}
// Called when the game starts or when spawned
void AAxe::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAxe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAxe::ThrowAxe(AAxeThrowProjectCharacter* MainCharacter, FVector PlayerForwardVector)
{
	UE_LOG(LogTemp, Warning, TEXT("Called Throw Axe function"));
	AxeMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	UProjectileMovementComponent* ProjectileMovementComponent = NewObject<UProjectileMovementComponent>(this);
	URotatingMovementComponent* AxeRotaitonMovement = NewObject<URotatingMovementComponent>(this);
	if(ProjectileMovementComponent && AxeRotaitonMovement)
	{
		ProjectileMovementComponent->InitialSpeed = 1500.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;

		ProjectileMovementComponent->RegisterComponent();
		ProjectileMovementComponent->Velocity = PlayerForwardVector * ThrowVelocity;
		UE_LOG(LogTemp, Warning, TEXT("Velocity: %s"), *ProjectileMovementComponent->Velocity.ToString());
		
		AxeRotaitonMovement->RotationRate = FRotator(-1000.0f, 0.0f, 0.0f);
		AxeRotaitonMovement->RegisterComponent();
		UE_LOG(LogTemp, Warning, TEXT("PlayerForwardVector: %s"), *PlayerForwardVector.ToString());
	}
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}


