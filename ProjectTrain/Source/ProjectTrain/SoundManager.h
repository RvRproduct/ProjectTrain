// Made By: Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "SoundManager.generated.h"

UCLASS()
class PROJECTTRAIN_API ASoundManager : public AActor
{
	GENERATED_BODY()

private:
	static ASoundManager* Instance;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* musicComponentA;
	
	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* musicComponentB;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* ambienceComponentA;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* ambienceComponentB;

	// Check for whether A or B is playing
	bool usingMusicA;
	bool usingAmbienceA;

	UPROPERTY(EditAnywhere, Category = "Music")
	TArray<USoundBase*> music;

	UPROPERTY(EditAnywhere, Category = "Ambience")
	TArray<USoundBase*> ambience;

	UPROPERTY(EditAnywhere, Category = "Sound Effects")
	TArray<USoundBase*> soundEffects;

	UPROPERTY(EditAnywhere, Category = "UI Sounds")
	TArray<USoundBase*> uiSounds;

public:	
	ASoundManager();

protected:
	virtual void BeginPlay() override;

public:
	static ASoundManager* GetInstance(UWorld* World);

	void PlayMusic(USoundBase* newMusic, float fadeTime);
	void PlayAmbience(USoundBase* newAmbience, float fadeTime);
	void PlaySoundEffect(USoundBase* soundEffect);
	void PlayUISound(USoundBase* uiSound);

};
