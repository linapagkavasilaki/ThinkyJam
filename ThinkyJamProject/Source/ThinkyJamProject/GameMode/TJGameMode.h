// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TJGameMode.generated.h"

/**
 * 
 */
UCLASS()
class THINKYJAMPROJECT_API ATJGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

    ATJGameMode();

protected:

    //Meters

    //Meter keeping track of Affection, value ranges between 0.0 and 1.0
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meters")
    float AffectionMeter;

    //Meter keeping track of trust, value ranges between 0.0 and 1.0
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meters")
    float TrustMeter;

    //Meter keeping track of annoyance, value ranges between 0.0 and 1.0
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meters")
    float AnnoyanceMeter;


    //Weights

    //Weight that determines the importance of the Affection value
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weights")
    float AffectionWeight;

    //Weight that determines the importance of the trust value
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weights")
    float TrustWeight;

    //Weight that determines the importance of the annoyance value
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weights")
    float AnnoyanceWeight;


    //Multipliers

    //Multiplier that is multiplied with a value that is added or subtracted from a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float AffectionMultiplier;

    //Multiplier that is multiplied with a value that is added or subtracted from a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float TrustMultiplier;

    //Multiplier that is multiplied with a value that is added or subtracted from a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float AnnoyanceMultiplier;


    //Changes Affection meter based on value multiplied with the AffectionMultiplier
    UFUNCTION()
    void ChangeAffection(int value);

    //Changes Trust meter based on value multiplied with the TrustMultiplier
    UFUNCTION()
    void ChangeTrust(int value);

    //Changes Annoyance meter based on value multiplied with the AnnoyanceMultiplier
    UFUNCTION()
    void ChangeAnnoyance(int value);


private:
    //Stores old meter values for later use
    float OldAffection;
    float OldTrust;
    float OldAnnoyance;

    //Functions that calculate the new multipliers
    void CalculateAffectionRate(float change);
    void CalculateTrustRate(float change);
    void CalculateAnnoyanceRate(float change);

};
