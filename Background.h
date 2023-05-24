// Header Guard
#pragma once

// Header Files
#include "Audio.h"
#include "GameObject.h"
#include "Texture.h"
#include "Window.h"

class Background : public GameObject	
{
public:
	// Constructor + Destructor
	Background() {}
	virtual ~Background();

	// Load
	void Load(const std::string& imageFilename = "", const std::string& musicFilename = "");

	// Music
	void PlayMusic();
	void StopMusic();

	// Update
	virtual void Update(int deltaTime) {}

	// Render
	virtual bool Render();

protected:
	Audio music;
	bool isPlaying{ false };

	Texture image;
};