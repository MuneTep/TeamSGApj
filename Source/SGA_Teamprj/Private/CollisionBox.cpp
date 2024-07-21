// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionBox.h"
#include "Components/SphereComponent.h"

// Sets default values
ACollisionBox::ACollisionBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DefaultMeshComponent"));
	RootComponent = CollisionMesh;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("DefaultSphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ACollisionBox::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACollisionBox::CollisionBoxOn);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ACollisionBox::CollisionBoxOff);
}

void ACollisionBox::CollisionBoxOn(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ACollisionBox::CollisionBoxOff(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called every frame
void ACollisionBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

