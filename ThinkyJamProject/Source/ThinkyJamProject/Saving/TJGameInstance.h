// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ThinkyJamProject/Structs/SaveData.h"
#include "TJGameInstance.generated.h"

/**
 * 
 */
class UTJSaveGame;
UCLASS()
class THINKYJAMPROJECT_API UTJGameInstance : public UGameInstance
{
    GENERATED_BODY()

    void Init() override;

    FString SaveSlot = "GameData";

    UTJSaveGame* GameData;

public:

    UFUNCTION(BlueprintCallable)
    void SaveGameData(TArray<FSaveData> SavingData);

    UFUNCTION(BlueprintCallable)
    UTJSaveGame* LoadGameData();

    UFUNCTION(BlueprintCallable)
    void CreateNewSaveSlot();

};
