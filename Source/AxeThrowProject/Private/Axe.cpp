// Fill out your copyright notice in the Description page of Project Settings.


#include "Axe.h"

#include "AxeThrowProject/AxeThrowProjectCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/ProjectileMovementComponent.h"

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

void AAxe::ThrowAxe(FVector PlayerForwardVector)
{
	UE_LOG(LogTemp, Error, TEXT("Called Throw Axe function"));
	AxeMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	UProjectileMovementComponent* ProjectileMovementComponent = NewObject<UProjectileMovementComponent>();
	if(ProjectileMovementComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Added Projectile Movement Component"));
	}
}


