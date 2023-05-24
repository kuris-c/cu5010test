// Header Files
#include "PlayState.h"

bool PlayState::OnEnter()
{
	background.Load("Background.png", "Assets/Audio/Soundtrack.wav");
	return true;
}

void PlayState::OnExit()
{
	background.~Background();
}

GameState* PlayState::Update(int deltaTime)
{
	background.PlayMusic();
	return this;
}

bool PlayState::Render()
{
	background.Render();
	return true;
}
