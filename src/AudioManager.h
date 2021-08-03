#ifndef _AudioManager
#define _AudioManager

namespace irrklang
{
	class ISoundEngine;
	class ISoundSource;
	class ISound;
}

class AudioManager
{
private:
	static AudioManager* ptrInstance;

	AudioManager();
	~AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator=(const AudioManager&) = delete;
	AudioManager(const char* windowName, const int Width, const int Height);

	/*static AudioManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new AudioManager();

		return *ptrInstance;
	}*/

	static AudioManager& Instance()
	{
		static AudioManager instance;
		return instance;
	}

	irrklang::ISoundEngine* pSoundEng;
	irrklang::ISound* pSong;

public:
	static void Initialize();
	static void Terminate();

	static void ToggleMusic();
	static void BirdSquawk();
	static void PigNoise();
	static void PigDie();
	static void WoodNoise();
	static void GlassNoise();
	static void StoneNoise();
	static void LevelClear();
	static void BirdFlying();

};


#endif _AudioManager
