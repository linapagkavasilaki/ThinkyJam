#pragma once
#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Blueprint/BlueprintSupport.h"
#include "SaveData.generated.h"

USTRUCT(BlueprintType)
struct THINKYJAMPROJECT_API FSaveData
{
    GENERATED_BODY()

    //All relevant information being stored
    //ID is most important to be saved, since it relates to all other information
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Variables")
    int ID;

    //Current position, since this can change during runtime it needs to be saved
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Variables")
    FVector2D Position;

    //Current text being displayed, since this is mainly user made it needs to be saved
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Variables")
    FString DisplayText;

    //Current connections are changable by the player so they need to be saved
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Variables")
    TArray<int> CurrentConnections;
};