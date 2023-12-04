#pragma once
#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Blueprint/BlueprintSupport.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "ClickableChoice.generated.h"


USTRUCT(BlueprintType)
struct THINKYJAMPROJECT_API FClickableChoice
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ChoiceText;

	// The ID of the string that has to recorded in the savegame's UnlockStrings for this choice to unlock.
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString RequiredUnlockString = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UPrimaryDataAsset* dialogue;
};
