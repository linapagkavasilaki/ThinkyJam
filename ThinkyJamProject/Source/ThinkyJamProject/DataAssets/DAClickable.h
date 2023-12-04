#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ThinkyJamProject/Structs/ClickableChoice.h"
#include "DAClickable.generated.h"

UCLASS(BlueprintType)
class THINKYJAMPROJECT_API UDAClickable : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FClickableChoice> Choices;
};
