// Fill out your copyright notice in the Description page of Project Settings.


#include "TJWidgetActor.h"
#include "VectorTypes.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATJWidgetActor::ATJWidgetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    MeshComp->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void ATJWidgetActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATJWidgetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATJWidgetActor::ResizeMesh()
{
    if (IsValid(Widget))
    {
        Widget->ForceLayoutPrepass();

        FVector2D Size = Widget->GetDesiredSize();

        MeshComp->SetWorldScale3D(FVector(Size.X, Size.Y, 1));
    }
}
