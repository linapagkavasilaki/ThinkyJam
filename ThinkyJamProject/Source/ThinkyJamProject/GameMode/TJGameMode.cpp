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

    AffectionMultiplier = 1.f;
    TrustMultiplier = 1.f;
    AnnoyanceMultiplier = 1.f;

    OldAffection = 0.f;
    OldTrust = 0.f;
    OldAnnoyance = 0.f;
}


 void ATJGameMode::ChangeAffection(int value)
{
    //Store old value and change meter based on value and multiplier
    OldAffection = AffectionMeter;
    AffectionMeter += value * AffectionMultiplier;

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (AffectionMeter - OldAffection) / OldAffection;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateTrustRate(PercentageChange);
    CalculateAnnoyanceRate(PercentageChange);
}

void ATJGameMode::ChangeTrust(int value)
{
    //Store old value and change meter based on value and multiplier
    OldTrust = TrustMeter;
    TrustMeter += value * TrustMultiplier;

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (TrustMeter - OldTrust) / OldTrust;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateAffectionRate(PercentageChange);
    CalculateAnnoyanceRate(PercentageChange);
}

void ATJGameMode::ChangeAnnoyance(int value)
{
    //Store old value and change meter based on value and multiplier
    OldAnnoyance = AnnoyanceMeter;
    AnnoyanceMeter += value * AnnoyanceMultiplier;

    //Get the change in percentage to calculate the new multiplier with
    float PercentageChange = (AnnoyanceMeter - OldAnnoyance) / OldAnnoyance;

    //Unsure what meter needs to be changed, assumptions made for now
    CalculateAffectionRate(PercentageChange);
}


void ATJGameMode::CalculateAffectionRate(float change)
{
    //How much the multiplier changes is dependant on the other two meters, up for change at a later point
    float MeterValue = (TrustMeter * TrustWeight) + (AnnoyanceMeter * AnnoyanceWeight);

    //How important is the change?
    float AffectionChange = change * AffectionWeight;

    //Set the new multiplier
    AffectionMultiplier = AffectionMultiplier + (AffectionChange * MeterValue);
}

void ATJGameMode::CalculateTrustRate(float change)
{
    //How much the multiplier changes is also dependant on the current affection, up for change at a later point
    float MeterValue = AffectionMeter * AffectionWeight;

    //How important is the change?
    float TrustChange = change * TrustWeight;

    //Set the new multiplier
    TrustMultiplier = TrustMultiplier + (TrustChange * MeterValue);
}

void ATJGameMode::CalculateAnnoyanceRate(float change)
{
    //How much the multiplier changes is dependant on the other two meters, up for change at a later point
    float MeterValue = (TrustMeter * TrustWeight) + (AffectionMeter * AffectionWeight);

    //How important is the change?
    float AnnoyanceChange = change * AnnoyanceWeight;

    //Set the new multiplier
    AnnoyanceMultiplier = AnnoyanceMultiplier + (AnnoyanceChange * MeterValue);
}
