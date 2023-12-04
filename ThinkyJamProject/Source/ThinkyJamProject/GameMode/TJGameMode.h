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


    //Change Modifiers

    //Increase
    //Modifier that has the AffectionMultiplier added to it, used for increase of affection
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier | Increase")
    float AffectionIncreaseMod;

    //Modifier that has the TrustMultiplier added to it, used for increase of trust
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier | Increase")
    float TrustIncreaseMod;

    //Modifier that has the AnnoyanceMultiplier added to it, used for increase of annoyance
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier | Increase")
    float AnnoyanceIncreaseMod;


    //Decrease
    //Modifier that has the AffectionMultiplier added to it, used for decrease of affection
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier | Decrease")
    float AffectionDecreaseMod;

    //Modifier that has the TrustMultiplier added to it, used for decrease of trust
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier | Decrease")
    float TrustDecreaseMod;

    //Modifier that has the AnnoyanceMultiplier added to it, used for decrease of annoyance
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier | Decrease")
    float AnnoyanceDecreaseMod;



    //Increases Affection meter based on value multiplied with the AffectionMultiplier
    UFUNCTION(BlueprintCallable)
    void IncreaseAffection(int value);

    //Decreases Affection meter based on value multiplied with the AffectionMultiplier
    UFUNCTION(BlueprintCallable)
    void DecreaseAffection(int value);

    //Increases Trust meter based on value multiplied with the TrustMultiplier
    UFUNCTION(BlueprintCallable)
    void IncreaseTrust(int value);

    //Decreases Trust meter based on value multiplied with the TrustMultiplier
    UFUNCTION(BlueprintCallable)
    void DecreaseTrust(int value);

    //Increases Annoyance meter based on value multiplied with the AnnoyanceMultiplier
    UFUNCTION(BlueprintCallable)
    void IncreaseAnnoyance(int value);

    //Decreases Annoyance meter based on value multiplied with the AnnoyanceMultiplier
    UFUNCTION(BlueprintCallable)
    void DecreaseAnnoyance(int value);


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
