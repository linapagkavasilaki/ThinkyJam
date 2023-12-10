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

    ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
}

// Called every frame
void ATJWidgetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //UpdatePosition();
}

void ATJWidgetActor::ResizeMesh()
{
    if (IsValid(WidgetInstance))
    {
        FVector2D Size = WidgetInstance->GetDesiredSize();

        MeshComp->SetWorldScale3D(FVector(Size.X / 50, Size.Y / 50, 0.01));
    }
}

void ATJWidgetActor::UpdatePosition()
{
    FTransform Transf = MeshComp->GetComponentTransform();
    WidgetInstance->SetPositionInViewport(FVector2D{ Transf.GetLocation().X / ViewportSize.X, Transf.GetLocation().Y / ViewportSize.Y });
}
