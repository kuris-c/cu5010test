// Header Guard
#pragma once

// Header Files
#include "Background.h"
#include "GameState.h"
#include "MenuKey.h"
#include "PlayState.h"

// C++ Libraries
#include <memory>

class StartState : public GameState
{
public:
	// Enum Class
	enum class MenuOption
	{
		Play, 
		Quit
	};

	// Constructor + Destructor
	StartState() {}
	virtual ~StartState() {}

	// On Enter + Exit
	virtual bool OnEnter();
	virtual void OnExit();

	// Update
	virtual GameState* Update(int deltaTime);

	// Render
	virtual bool Render();

private:
	Background image;
	std::unique_ptr<MenuKey> menu;
};