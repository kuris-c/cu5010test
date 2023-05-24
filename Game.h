// Header Guard
#pragma once

// Header Files
#include "Audio.h"
#include "GameState.h"
#include "Input.h"
#include "Text.h"
#include "Window.h"

class Game
{
public:
	// Constructor
	Game(GameState* initialGameState);

	// Init
	bool Initialize(const std::string& name, int screenWidth, int screenHeight, bool fullscreen = false);

	// Run
	bool Run();

	// Shutdown
	void Shutdown();

private:
	int deltaTime{ 0 };
	std::unique_ptr<GameState> gameState;
};