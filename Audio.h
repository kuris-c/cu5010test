// Header Guard
#pragma once

// Header Files
#include "Utility.h"

// C++ Libraries
#include <algorithm>
#include <string>

// SDL Libraries
#include <SDL_mixer.h>

class Audio
{
public:
	//Initialise and Load Audio
	bool Initialise(int frequency = 44100, int chunksize = 1024);
	bool Load(const std::string& filename, bool fileIsMusic);

	//Shutdown Audio
	void Unload();
	void CloseAudio();

	//Adjust Audio
	void SetVolume(float volume);

	//Looping Enum
	enum class Loop
	{
		Once = 1,
		Ongoing = -1
	};

	//Adjust Audio
	bool Play(Loop loop = Loop::Once);
	void Pause();
	void Resume();
	void Stop();

private:
	//For Music Generation
	Mix_Music* music{ nullptr };
	bool isFileMusic{ false };

	//For Sound Generation
	Mix_Chunk* sound{ nullptr };
};