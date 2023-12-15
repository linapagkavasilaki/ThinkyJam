// Fill out your copyright notice in the Description page of Project Settings.


#include "TJWidgetActor.h"
#include "VectorTypes.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATJWidgetActor::ATJWidgetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    MeshComp->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void ATJWidgetActor::BeginPlay()
{
	Super::BeginPlay();
	
    if (IsValid(WidgetTemplate))
    {
        WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetTemplate);

        WidgetInstance->AddToViewport();
    }

}

// Called every frame
void ATJWidgetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATJWidgetActor::ResizeMesh()
{
    if (IsValid(WidgetInstance))
    {
        FVector2D Size = WidgetInstance->GetDesiredSize();

        FBox BoundBox = MeshComp->GetStaticMesh()->GetBoundingBox();

        FVector BoxSize = BoundBox.GetSize();

        MeshComp->SetWorldScale3D(FVector(Size.X / BoxSize.X, Size.Y / BoxSize.Y, 0.01));

        WidgetInstance->RemoveFromViewport();
        WidgetInstance = nullptr;
    }
}
