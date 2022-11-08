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

	bWasThrown = false;
}
// Called when the game starts or when spawned
void AAxe::BeginPlay()
{
	Super::BeginPlay();
	AxeMesh->OnComponentHit.AddDynamic(this, &AAxe::OnHit);
}

// Called every frame
void AAxe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAxe::ThrowAxe(AAxeThrowProjectCharacter* MainCharacter, FVector PlayerForwardVector)
{
	AxeMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	ProjectileMovementComponent = NewObject<UProjectileMovementComponent>(this);
	AxeRotationMovement = NewObject<URotatingMovementComponent>(this);
	if(ProjectileMovementComponent && AxeRotationMovement)
	{
		ProjectileMovementComponent->InitialSpeed = 1500.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->RegisterComponent();
		ProjectileMovementComponent->Velocity = PlayerForwardVector * ThrowVelocity;
		
		AxeRotationMovement->RotationRate = AxeThrowRotation;
		AxeRotationMovement->RegisterComponent();
	}
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}

void AAxe::RecallAxe()
{
	UE_LOG(LogTemp, Warning, TEXT("Recall Axe"));
}

//TODO Collide only with the blade
void AAxe::OnHit(
		UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit
	)
{
	if(OtherActor != this)
	{
		ProjectileMovementComponent->DestroyComponent();
		AxeRotationMovement->DestroyComponent();
		bWasThrown = true;
	}
}


