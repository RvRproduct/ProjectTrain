// Made By: Roberto Valentino Reynoso (RvRproduct)

#include "SoundManager.h"
#include "Components/AudioComponent.h"
#include "EngineUtils.h"

ASoundManager* ASoundManager::Instance = nullptr;

// Sets default values
ASoundManager::ASoundManager()
{
	PrimaryActorTick.bCanEverTick = false;

	musicComponentA = CreateDefaultSubobject<UAudioComponent>(TEXT("musicComponentA"));
	musicComponentA->bAutoActivate = false;
	musicComponentA->SetupAttachment(RootComponent);

	musicComponentB = CreateDefaultSubobject<UAudioComponent>(TEXT("musicComponentB"));
	musicComponentB->bAutoActivate = false;
	musicComponentB->SetupAttachment(RootComponent);

	ambienceComponentA = CreateDefaultSubobject<UAudioComponent>(TEXT("ambienceComponentA"));
	ambienceComponentA->bAutoActivate = false;
	ambienceComponentA->SetupAttachment(RootComponent);

	ambienceComponentB = CreateDefaultSubobject<UAudioComponent>(TEXT("ambienceComponentB"));
	ambienceComponentB->bAutoActivate = false;
	ambienceComponentB->SetupAttachment(RootComponent);

	usingMusicA = true;
	usingAmbienceA = true;
}

// Called when the game starts or when spawned
void ASoundManager::BeginPlay()
{
	Super::BeginPlay();

	if (Instance && Instance != this)
	{
		Destroy();
		return;
	}

	Instance = this;
}

ASoundManager* ASoundManager::GetInstance(UWorld* World)
{
	if (Instance) { return Instance; }

	if (!World) { return nullptr; }

	for (TActorIterator<ASoundManager> It(World); It; ++It)
	{
		if (*It)
		{
			Instance = *It;
			return Instance;
		}
	}

	Instance = World->SpawnActor<ASoundManager>();
	return Instance;
}

void ASoundManager::PlayMusic(USoundBase* newMusic, float fadeTime)
{

}

void ASoundManager::PlayAmbience(USoundBase* newAmbience, float fadeTime)
{

}

void ASoundManager::PlaySoundEffect(USoundBase* soundEffect)
{

}

void ASoundManager::PlayUISound(USoundBase* uiSound)
{

}




