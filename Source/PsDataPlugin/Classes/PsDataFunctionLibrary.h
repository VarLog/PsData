// Copyright 2015-2019 Mail.Ru Group. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/TextProperty.h"

#include "PsDataFunctionLibrary.generated.h"

class UPsData;
class UPsDataBlueprintMapProxy;
class UPsDataBlueprintArrayProxy;

UCLASS()
class PSDATAPLUGIN_API UPsDataFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/***********************************
	 * int32
	 ***********************************/

	/** Get int property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static int32 GetIntProperty(UPsData* Target, int32 Crc32);

	/** Set int property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetIntProperty(UPsData* Target, int32 Crc32, int32 Value);

	/** Get int array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<int32>& GetIntArrayProperty(UPsData* Target, int32 Crc32);

	/** Set int array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetIntArrayProperty(UPsData* Target, int32 Crc32, const TArray<int32>& Value);

	/** Get int map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, int32>& GetIntMapProperty(UPsData* Target, int32 Crc32);

	/** Set int map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetIntMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, int32>& Value);

	/***********************************
	 * uint8
	 ***********************************/

	/** Get uint8 property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static uint8 GetByteProperty(UPsData* Target, int32 Crc32);

	/** Set uint8 property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetByteProperty(UPsData* Target, int32 Crc32, uint8 Value);

	/** Get uint8 array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<uint8>& GetByteArrayProperty(UPsData* Target, int32 Crc32);

	/** Set uint8 array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetByteArrayProperty(UPsData* Target, int32 Crc32, const TArray<uint8>& Value);

	/** Get uint8 map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, uint8>& GetByteMapProperty(UPsData* Target, int32 Crc32);

	/** Set uint8 map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetByteMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, uint8>& Value);

	/***********************************
	 * float
	 ***********************************/

	/** Get float property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static float GetFloatProperty(UPsData* Target, int32 Crc32);

	/** Set float property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetFloatProperty(UPsData* Target, int32 Crc32, float Value);

	/** Get float array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<float>& GetFloatArrayProperty(UPsData* Target, int32 Crc32);

	/** Set float array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetFloatArrayProperty(UPsData* Target, int32 Crc32, const TArray<float>& Value);

	/** Get float map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, float>& GetFloatMapProperty(UPsData* Target, int32 Crc32);

	/** Set float map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetFloatMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, float>& Value);

	/***********************************
	 * String
	 ***********************************/

	/** Get string property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static FString GetStringProperty(UPsData* Target, int32 Crc32);

	/** Set string property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetStringProperty(UPsData* Target, int32 Crc32, const FString& Value);

	/** Get string array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<FString>& GetStringArrayProperty(UPsData* Target, int32 Crc32);

	/** Set string array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetStringArrayProperty(UPsData* Target, int32 Crc32, const TArray<FString>& Value);

	/** Get string map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, FString>& GetStringMapProperty(UPsData* Target, int32 Crc32);

	/** Set string map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetStringMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, FString>& Value);

	/***********************************
	 * bool
	 ***********************************/

	/** Get bool property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static bool GetBoolProperty(UPsData* Target, int32 Crc32);

	/** Set bool property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetBoolProperty(UPsData* Target, int32 Crc32, bool Value);

	/** Get bool array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<bool>& GetBoolArrayProperty(UPsData* Target, int32 Crc32);

	/** Set bool array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetBoolArrayProperty(UPsData* Target, int32 Crc32, const TArray<bool>& Value);

	/** Get bool map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, bool>& GetBoolMapProperty(UPsData* Target, int32 Crc32);

	/** Set bool map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetBoolMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, bool>& Value);

	/***********************************
	 * Data
	 ***********************************/

	/** Get data property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static UPsData* GetDataProperty(UPsData* Target, int32 Crc32);

	/** Set data property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetDataProperty(UPsData* Target, int32 Crc32, UPsData* Value);

	/** Get data array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<UPsData*>& GetDataArrayProperty(UPsData* Target, int32 Crc32);

	/** Set data array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetDataArrayProperty(UPsData* Target, int32 Crc32, const TArray<UPsData*>& Value);

	/** Get data map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, UPsData*>& GetDataMapProperty(UPsData* Target, int32 Crc32);

	/** Set data map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetDataMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, UPsData*>& Value);

	/***********************************
	 * TSoftObject
	 ***********************************/

	/** Get soft object property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static TSoftObjectPtr<UObject> GetSoftObjectProperty(UPsData* Target, int32 Crc32);

	/** Set soft object property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetSoftObjectProperty(UPsData* Target, int32 Crc32, const TSoftObjectPtr<UObject>& Value);

	/** Get soft object array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<TSoftObjectPtr<UObject>>& GetSoftObjectArrayProperty(UPsData* Target, int32 Crc32);

	/** Set soft object array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetSoftObjectArrayProperty(UPsData* Target, int32 Crc32, const TArray<TSoftObjectPtr<UObject>>& Value);

	/** Get soft object map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, TSoftObjectPtr<UObject>>& GetSoftObjectMapProperty(UPsData* Target, int32 Crc32);

	/** Set soft object map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetSoftObjectMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, TSoftObjectPtr<UObject>>& Value);

	/***********************************
	 * FText
	 ***********************************/

	/** Get text property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static FText GetTextProperty(UPsData* Target, int32 Crc32);

	/** Set soft object property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetTextProperty(UPsData* Target, int32 Crc32, const FText& Value);

	/** Get soft object array property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TArray<FText>& GetTextArrayProperty(UPsData* Target, int32 Crc32);

	/** Set soft object array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetTextArrayProperty(UPsData* Target, int32 Crc32, const TArray<FText>& Value);

	/** Get soft object map property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static const TMap<FString, FText>& GetTextMapProperty(UPsData* Target, int32 Crc32);

	/** Set soft object map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	static void SetTextMapProperty(UPsData* Target, int32 Crc32, const TMap<FString, FText>& Value);

	/***********************************
	 * Path
	 ***********************************/

	/** Get data property by Path */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static UPsData* GetDataByPath(UPsData* Target, const FString& PropertyName, const FString& Path);

	/** Get data array property by Path */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static TArray<UPsData*> GetDataArrayByPath(UPsData* Target, const FString& PropertyName, const FString& Path);

	/***********************************
	 * Blueprint collections proxy
	 ***********************************/

	/** Get map proxy property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static UPsDataBlueprintMapProxy* GetMapProxy(UPsData* Target, int32 Crc32);

	/** Get map proxy property */
	UFUNCTION(BlueprintPure, Category = "PsData|Data")
	static UPsDataBlueprintArrayProxy* GetArrayProxy(UPsData* Target, int32 Crc32);
};