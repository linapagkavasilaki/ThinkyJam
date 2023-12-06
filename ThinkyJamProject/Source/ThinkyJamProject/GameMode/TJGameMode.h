// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/GameModeBase.h"
#include "TJGameMode.generated.h"

//Forward declaration

struct FMath;

UCLASS()
class THINKYJAMPROJECT_API ATJGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

    ATJGameMode();

protected:

    //Meters

    //Meter keeping track of Affection, value ranges between 0.0 and 1.0
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meters")
    float AffectionMeter;

    //Meter keeping track of trust, value ranges between 0.0 and 1.0
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meters")
    float TrustMeter;

    //Meter keeping track of annoyance, value ranges between 0.0 and 1.0
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meters")
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

    //Increase
    //Multiplier that is multiplied with a value that is added to a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float AffectionIncreaseMultiplier;

    //Multiplier that is multiplied with a value that is added to a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float TrustIncreaseMultiplier;

    //Multiplier that is multiplied with a value that is added to a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float AnnoyanceIncreaseMultiplier;

    //Decrease
    //Multiplier that is multiplied with a value that is subtracted from a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float AffectionDecreaseMultiplier;

    //Multiplier that is multiplied with a value that is subtracted from a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float TrustDecreaseMultiplier;

    //Multiplier that is multiplied with a value that is subtracted from a meter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multipliers")
    float AnnoyanceDecreaseMultiplier;


    //Clamping values
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meter Clamps")
    float MinMeterValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meter Clamps")
    float MaxMeterValue;


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
    void CalculateAffectionIncreaseRate(float change);
    void CalculateTrustIncreaseRate(float change);
    void CalculateAnnoyanceIncreaseRate(float change);

    void CalculateAffectionDecreaseRate(float change);
    void CalculateTrustDecreaseRate(float change);
    void CalculateAnnoyanceDecreaseRate(float change);

};
