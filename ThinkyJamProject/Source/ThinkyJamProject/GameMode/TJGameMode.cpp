// Fill out your copyright notice in the Description page of Project Settings.


#include "TJGameMode.h"

//Setting default values
ATJGameMode::ATJGameMode()
{
    AffectionMeter = 0.f;
    TrustMeter = 0.f;
    AnnoyanceMeter = 0.f;

    AffectionWeight = 1.2f;
    TrustWeight = 1.1f;
    AnnoyanceWeight = 0.9f;

    AffectionIncreaseMultiplier = 1.f;
    TrustIncreaseMultiplier = 1.f;
    AnnoyanceIncreaseMultiplier = 1.f;

    AffectionDecreaseMultiplier = 1.f;
    TrustDecreaseMultiplier = 1.f;
    AnnoyanceDecreaseMultiplier = 1.f;

    MinMeterValue = 0.f;
    MaxMeterValue = 1.f;

    OldAffection = 0.f;
    OldTrust = 0.f;
    OldAnnoyance = 0.f;
}


void ATJGameMode::IncreaseAffection(int value)
{
    //Store old value and change meter based on value and multiplier
    OldAffection = AffectionMeter;
    AffectionMeter += (value / 100) * (AffectionIncreaseMultiplier);
    AffectionMeter = FMath::Clamp(AffectionMeter, MinMeterValue, MaxMeterValue);

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (AffectionMeter - OldAffection) / OldAffection;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateTrustIncreaseRate(PercentageChange);
    CalculateTrustDecreaseRate(-PercentageChange);
    CalculateAnnoyanceIncreaseRate(-PercentageChange);
    CalculateAnnoyanceDecreaseRate(PercentageChange);
}

void ATJGameMode::DecreaseAffection(int value)
{
    //Store old value and change meter based on value and multiplier
    OldAffection = AffectionMeter;
    AffectionMeter += (value / 100.f) * (AffectionDecreaseMultiplier);
    AffectionMeter = FMath::Clamp(AffectionMeter, MinMeterValue, MaxMeterValue);

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (AffectionMeter - OldAffection) / OldAffection;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateTrustIncreaseRate(-PercentageChange);
    CalculateTrustDecreaseRate(PercentageChange);
    CalculateAnnoyanceIncreaseRate(PercentageChange);
    CalculateAnnoyanceDecreaseRate(-PercentageChange);
}

void ATJGameMode::IncreaseTrust(int value)
{
    //Store old value and change meter based on value and multiplier
    OldTrust = TrustMeter;
    TrustMeter += (value / 100.f) * (TrustIncreaseMultiplier);
    TrustMeter = FMath::Clamp(TrustMeter, MinMeterValue, MaxMeterValue);

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (TrustMeter - OldTrust) / OldTrust;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateAffectionIncreaseRate(PercentageChange);
    CalculateAffectionDecreaseRate(-PercentageChange);
    CalculateAnnoyanceIncreaseRate(-PercentageChange);
    CalculateAnnoyanceDecreaseRate(PercentageChange);
}

void ATJGameMode::DecreaseTrust(int value)
{
    //Store old value and change meter based on value and multiplier
    OldTrust = TrustMeter;
    TrustMeter += (value / 100.f) * (TrustDecreaseMultiplier);
    TrustMeter = FMath::Clamp(TrustMeter, MinMeterValue, MaxMeterValue);

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (TrustMeter - OldTrust) / OldTrust;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateAffectionIncreaseRate(-PercentageChange);
    CalculateAffectionDecreaseRate(PercentageChange);
    CalculateAnnoyanceIncreaseRate(PercentageChange);
    CalculateAnnoyanceDecreaseRate(-PercentageChange);
}

void ATJGameMode::IncreaseAnnoyance(int value)
{
    //Store old value and change meter based on value and multiplier
    OldAnnoyance = AnnoyanceMeter;
    AnnoyanceMeter += (value / 100.f) * (AnnoyanceIncreaseMultiplier);
    AnnoyanceMeter = FMath::Clamp(AnnoyanceMeter, MinMeterValue, MaxMeterValue);

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (AnnoyanceMeter - OldAnnoyance) / OldAnnoyance;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateAffectionIncreaseRate(-PercentageChange);
    CalculateAffectionDecreaseRate(PercentageChange);
}

void ATJGameMode::DecreaseAnnoyance(int value)
{
    //Store old value and change meter based on value and multiplier
    OldAnnoyance = AnnoyanceMeter;
    AnnoyanceMeter += (value / 100.f) * (AnnoyanceDecreaseMultiplier);
    AnnoyanceMeter = FMath::Clamp(AnnoyanceMeter, MinMeterValue, MaxMeterValue);

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (AnnoyanceMeter - OldAnnoyance) / OldAnnoyance;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateAffectionIncreaseRate(PercentageChange);
    CalculateAffectionDecreaseRate(-PercentageChange);
}


void ATJGameMode::CalculateAffectionIncreaseRate(float change)
{
    //How much the multiplier changes is dependant on the other two meters, up for change at a later point
    float MeterValue = (TrustMeter * TrustWeight) + (AnnoyanceMeter * AnnoyanceWeight);

    //How important is the change?
    float AffectionChange = change * AffectionWeight;

    //Set the new multiplier
    AffectionIncreaseMultiplier = AffectionIncreaseMultiplier + (AffectionChange * MeterValue);
}

void ATJGameMode::CalculateTrustIncreaseRate(float change)
{
    //How much the multiplier changes is also dependant on the current affection, up for change at a later point
    float MeterValue = AffectionMeter * AffectionWeight;

    //How important is the change?
    float TrustChange = change * TrustWeight;

    //Set the new multiplier
    TrustIncreaseMultiplier = TrustIncreaseMultiplier + (TrustChange * MeterValue);
}

void ATJGameMode::CalculateAnnoyanceIncreaseRate(float change)
{
    //How much the multiplier changes is dependant on the other two meters, up for change at a later point
    float MeterValue = (TrustMeter * TrustWeight) + (AffectionMeter * AffectionWeight);

    //How important is the change?
    float AnnoyanceChange = change * AnnoyanceWeight;

    //Set the new multiplier
    AnnoyanceIncreaseMultiplier = AnnoyanceIncreaseMultiplier + (AnnoyanceChange * MeterValue);
}


void ATJGameMode::CalculateAffectionDecreaseRate(float change)
{
    //How much the multiplier changes is dependant on the other two meters, up for change at a later point
    float MeterValue = (TrustMeter * TrustWeight) + (AnnoyanceMeter * AnnoyanceWeight);

    //How important is the change?
    float AffectionChange = change * AffectionWeight;

    //Set the new multiplier
    AffectionDecreaseMultiplier = AffectionDecreaseMultiplier + (AffectionChange * MeterValue);
}

void ATJGameMode::CalculateTrustDecreaseRate(float change)
{
    //How much the multiplier changes is also dependant on the current affection, up for change at a later point
    float MeterValue = AffectionMeter * AffectionWeight;

    //How important is the change?
    float TrustChange = change * TrustWeight;

    //Set the new multiplier
    TrustDecreaseMultiplier = TrustDecreaseMultiplier + (TrustChange * MeterValue);
}

void ATJGameMode::CalculateAnnoyanceDecreaseRate(float change)
{
    //How much the multiplier changes is dependant on the other two meters, up for change at a later point
    float MeterValue = (TrustMeter * TrustWeight) + (AffectionMeter * AffectionWeight);

    //How important is the change?
    float AnnoyanceChange = change * AnnoyanceWeight;

    //Set the new multiplier
    AnnoyanceDecreaseMultiplier = AnnoyanceDecreaseMultiplier + (AnnoyanceChange * MeterValue);
}
