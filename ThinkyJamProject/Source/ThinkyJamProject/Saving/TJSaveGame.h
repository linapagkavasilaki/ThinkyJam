// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ThinkyJamProject/Structs/SaveData.h"
#include "TJSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class THINKYJAMPROJECT_API UTJSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TArray<FSaveData> StoredData;
};
