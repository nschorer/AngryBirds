#include "AudioManager.h"
#include "irrKlang.h"
#include <assert.h>
#include <cstdlib>
#include <string>

AudioManager* AudioManager::ptrInstance = nullptr;

AudioManager::AudioManager()
{
	// initialize the sound system
	pSoundEng = irrklang::createIrrKlangDevice();

	const char* Music = "../../../../reference/reference/Asset/AngryBirds/Audio/title_theme.mp3";

	// Play looping background music
	bool loopMusic = true;
	bool startPaused = false;
	bool makeTrackable = true;

	pSong = pSoundEng->play2D(Music, loopMusic, startPaused, makeTrackable);
	pSong->setVolume(.01f);
	//ToggleMusic();
}

void AudioManager::Initialize()
{
	Instance();
}

void AudioManager::ToggleMusic()
{
	if (Instance().pSong->getIsPaused() )
	{
		Instance().pSong->setPlayPosition(0);
		Instance().pSong->setIsPaused(false);
	} 
	else
	{
		Instance().pSong->setIsPaused(true);
	}
}

void AudioManager::BirdSquawk()
{
	irrklang::ISound *pSnd = nullptr;
	int n = rand() % 5;

	switch (n)
	{
	case 0:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/bird 02 collision a1.mp3", false, false, true);
		pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
		break;
	case 1:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/bird 02 collision a2.mp3", false, false, true);
		pSnd->drop();
		break;
	case 2:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/bird 02 collision a3.mp3", false, false, true);
		pSnd->drop();
		break;
	case 3:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/bird 02 collision a4.mp3", false, false, true);
		pSnd->drop();
		break;
	case 4:
	default:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/bird 02 collision a5.mp3", false, false, true);
		pSnd->drop();
		break;
	}
	pSnd->setVolume(.1f);
}

void AudioManager::PigNoise()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/piglette_singing_1.wav", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::PigDie()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/piglette destroyed.wav", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::WoodNoise()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/wood destroyed a1.wav", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::GlassNoise()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/ice light collision a8.wav", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::StoneNoise()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/rock destroyed a1.wav", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::LevelClear()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/level clear military a1.mp3", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::BirdFlying()
{
	irrklang::ISound* pSnd = Instance().pSoundEng->play2D("../../../../reference/reference/asset/angrybirds/audio/bird_06_flying.wav", false, false, true);
	pSnd->setVolume(.1f);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
}

void AudioManager::Terminate() 
{ 
	delete ptrInstance;
}

AudioManager::~AudioManager()
{
	pSoundEng->stopAllSounds();
	pSoundEng->removeAllSoundSources();
	pSoundEng->drop();
}