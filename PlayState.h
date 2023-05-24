// Header Files
#pragma once

// Header Files
#include "Background.h"
#include "GameState.h"

class PlayState : public GameState
{
public:
	// Constructor + Destructor
	PlayState() {}
	virtual ~PlayState() {}

	// On Enter + Exit
	virtual bool OnEnter();
	virtual void OnExit();

	// Update
	virtual GameState* Update(int deltaTime);

	// Render
	virtual bool Render();

private:
	Background background;
};