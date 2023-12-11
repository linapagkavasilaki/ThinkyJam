// Fill out your copyright notice in the Description page of Project Settings.


#include "TJGameInstance.h"
#include "ThinkyJamProject/Saving/TJSaveGame.h"
#include "Engine.h"


void UTJGameInstance::Init()
{
    //Check if there is any available data to be loaded in, or create new data if needed
    GameData = Cast<UTJSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));

    if (!IsValid(GameData))
    {
        CreateNewSaveSlot();
    }
}

void UTJGameInstance::CreateNewSaveSlot()
{
    //Creating new GameData slot
    GameData = Cast<UTJSaveGame>(UGameplayStatics::CreateSaveGameObject(UTJSaveGame::StaticClass()));

    //Since there is no game slot we can save one
    UGameplayStatics::SaveGameToSlot(GameData, SaveSlot, 0);
}

void UTJGameInstance::SaveGameData(TArray<FSaveData> SavingData)
{
    if (IsValid(GameData))
    {
        GameData->StoredData = SavingData;

        UGameplayStatics::SaveGameToSlot(GameData, SaveSlot, 0);
    }
}

UTJSaveGame* UTJGameInstance::LoadGameData()
{
    if (IsValid(GameData))
    {
        return GameData;
    }
    else
    {
        return nullptr;
    }
}
