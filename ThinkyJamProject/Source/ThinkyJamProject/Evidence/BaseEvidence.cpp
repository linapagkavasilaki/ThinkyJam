// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEvidence.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseEvidence::ABaseEvidence()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    MeshComp->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    RootComponent = MeshComp;

    ID = 0;
    DisplayText = "";
    Position = { 0,0 };

}

// Called when the game starts or when spawned
void ABaseEvidence::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEvidence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

