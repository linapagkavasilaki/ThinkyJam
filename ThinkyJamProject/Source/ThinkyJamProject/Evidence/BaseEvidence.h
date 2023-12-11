// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VectorTypes.h"
#include "BaseEvidence.generated.h"

//Forward Decleration
class UStaticMeshComponent;

UCLASS()
class THINKYJAMPROJECT_API ABaseEvidence : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseEvidence();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    //All components and variables needed for the base evidence.

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    //Numeral ID of the current Evidence
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Evidence Details")
    int ID;

    //Text that can will be displayed, used in sticky notes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evidence Details")
    FString DisplayText;

    //Vector2 with the current position of the evidence relative to the board
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evidence Details")
    FVector2D Position;

    //Correct connections the evidence can make
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Evidence Details")
    TArray<int> CorrectConnections;

    //Current connections the evidence has made
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Evidence Details")
    TArray<int> CurrentConnections;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
