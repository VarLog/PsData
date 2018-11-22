// Copyright 2015-2018 Mail.Ru Group. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PsEvent.h"
#include "PsSerialization.h"
#include "PsData.generated.h"

DEFINE_LOG_CATEGORY_STATIC(LogData, VeryVerbose, All);

DECLARE_DYNAMIC_DELEGATE_OneParam(FPsDataDynamicDelegate, UPsEvent*, Event); // TBaseDynamicDelegate
DECLARE_DELEGATE_OneParam(FPsDataDelegate, UPsEvent*); // TBaseDelegate

namespace FDataReflectionTools
{
	struct PSDATAPLUGIN_API FPsDataFriend
	{
		static void ChangeDataName(class UPsData* Data, const FString& Name);
		static void AddChild(class UPsData* Parent, class UPsData* Data);
		static void RemoveChild(class UPsData* Parent, class UPsData* Data);
		static bool IsChanged(class UPsData* Data);
		static void SetIsChanged(class UPsData* Data, bool NewValue);
	};
}

UCLASS(BlueprintType, Blueprintable)
class PSDATAPLUGIN_API UPsData : public UObject
{
	GENERATED_UCLASS_BODY()
	
private:
	friend struct FDataReflectionTools::FPsDataFriend;
	
	/** Data name */
	FString Name;
	
	/** Parent */
	UPROPERTY()
	UPsData* Parent;
	
	/** Children */
	UPROPERTY()
	TSet<UPsData*> Children;
	
	/** Broadcast in progress (necessary for correct iteration by delegates) */
	int32 BroadcastInProgress;
	
	/** Changed flag */
	bool bChanged;
	
	/** Map of dynamic delegates for blueprint */
	TMap<FString, TSet<FPsDataDynamicDelegate>> DynamicDelegates;
	
	/** Map of delegates */
	TMap<FString, TArray<FPsDataDelegate>> Delegates;
	
	
public:
	/** Post init properties */
	virtual void PostInitProperties() override;
	
	/***********************************
	 * Event system
	 ***********************************/
	
	/** Broadcat */
	void Broadcast(UPsEvent* Event);
	
	/** Bind */
	void Bind(FString Type, const FPsDataDynamicDelegate& Delegate);
	
	/** Bind */
	void Bind(FString Type, const FPsDataDelegate& Delegate);
	
	/** Bind */
	void Unbind(FString Type, const FPsDataDynamicDelegate& Delegate);
	
	/** Bind */
	void Unbind(FString Type, const FPsDataDelegate& Delegate);
	
	/** Blueprint bind */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Bind", Category = "PsData"))
	void BlueprintBind(const FString& Type, const FPsDataDynamicDelegate& Delegate);
	
	/** Blueprint unbind */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Unbind", Category = "PsData"))
	void BlueprintUnbind(const FString& Type, const FPsDataDynamicDelegate& Delegate);

private:
	/** Update delegates */
	void UpdateDelegates();
	
	/** Broadcast internal */
	void BroadcastInternal(UPsEvent* Event);
	
public:
	/***********************************
	 * Serialize
	 ***********************************/
	
	void DataSerialize(FDataSerializer& Ser);
	
public:
	/***********************************
	 * Data property
	 ***********************************/
	
	/** Get name */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	FString GetName() const;
	
	/** Get parent */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	UPsData* GetParent() const;
	
	/** Get root */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	UPsData* GetRoot() const;
	
public:
	/***********************************
	 * Property
	 ***********************************/
	
	/** Get data property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	UPsData* GetDataProperty(const FString& PropertyName);
	
	/** Set data property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetDataProperty(const FString& PropertyName, UPsData* Value);
	
	/** Get int property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	int32 GetIntProperty(const FString& PropertyName);
	
	/** Set int property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetIntProperty(const FString& PropertyName, int32 Value);
	
	/** Get float property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	float GetFloatProperty(const FString& PropertyName);
	
	/** Set float property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetFloatProperty(const FString& PropertyName, float Value);
	
	/** Get string property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	FString GetStringProperty(const FString& PropertyName);
	
	/** Set string property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetStringProperty(const FString& PropertyName, UPARAM(ref) FString& Value);
	
	/** Get bool property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	bool GetBoolProperty(const FString& PropertyName);
	
	/** Set bool property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetBoolProperty(const FString& PropertyName, bool Value);
	
	/***********************************
	 * Array property
	 ***********************************/
	
	/** Get data array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TArray<UPsData*> GetDataArrayProperty(const FString& PropertyName);
	
	/** Set data array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetDataArrayProperty(const FString& PropertyName, UPARAM(ref) TArray<UPsData*>& Value);
	
	/** Get int array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TArray<int32> GetIntArrayProperty(const FString& PropertyName);
	
	/** Set int array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetIntArrayProperty(const FString& PropertyName, UPARAM(ref) TArray<int32>& Value);
	
	/** Get float array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TArray<float> GetFloatArrayProperty(const FString& PropertyName);
	
	/** Set float array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetFloatArrayProperty(const FString& PropertyName, UPARAM(ref) TArray<float>& Value);
	
	/** Get string array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TArray<FString> GetStringArrayProperty(const FString& PropertyName);
	
	/** Set string array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetStringArrayProperty(const FString& PropertyName, UPARAM(ref) TArray<FString>& Value);
	
	/** Get bool array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TArray<bool> GetBoolArrayProperty(const FString& PropertyName);
	
	/** Set bool array property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetBoolArrayProperty(const FString& PropertyName, UPARAM(ref) TArray<bool>& Value);
	
	/***********************************
	 * Map property
	 ***********************************/
	
	/** Get data map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TMap<FString, UPsData*> GetDataMapProperty(const FString& PropertyName);
	
	/** Set data map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetDataMapProperty(const FString& PropertyName, UPARAM(ref) TMap<FString, UPsData*>& Value);
	
	/** Get int map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TMap<FString, int32> GetIntMapProperty(const FString& PropertyName);
	
	/** Set int map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetIntMapProperty(const FString& PropertyName, UPARAM(ref) TMap<FString, int32>& Value);
	
	/** Get float map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TMap<FString, float> GetFloatMapProperty(const FString& PropertyName);
	
	/** Set float map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetFloatMapProperty(const FString& PropertyName, UPARAM(ref) TMap<FString, float>& Value);
	
	/** Get string map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TMap<FString, FString> GetStringMapProperty(const FString& PropertyName);
	
	/** Set string map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetStringMapProperty(const FString& PropertyName, UPARAM(ref) TMap<FString, FString>& Value);
	
	/** Get bool map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TMap<FString, bool> GetBoolMapProperty(const FString& PropertyName);
	
	/** Set bool map property */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	void SetBoolMapProperty(const FString& PropertyName, UPARAM(ref) TMap<FString, bool>& Value);

	/***********************************
	 * Link
	 ***********************************/
	
	/** Get data property by Path */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	UPsData* GetDataProperty_Link(const FString& Path, const FString& PropertyNameWithPathAppend);

	/** Get data array by Path */
	UFUNCTION(BlueprintCallable, Category = "PsData|Data")
	TArray<UPsData*> GetDataArrayProperty_Link(const FString& Path, const FString& PropertyNameWithPathAppend);

};