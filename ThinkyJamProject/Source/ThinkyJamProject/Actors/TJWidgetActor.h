// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "TJWidgetActor.generated.h"


//Forward Decleration
class UStaticMeshComponent;
class UUserWidget;

UCLASS()
class THINKYJAMPROJECT_API ATJWidgetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATJWidgetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
    TSubclassOf<UUserWidget> WidgetTemplate;

    //Sizes the mesh to the widget's size
    UFUNCTION(BlueprintCallable)
    void ResizeMesh();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

    UUserWidget* WidgetInstance;
};
