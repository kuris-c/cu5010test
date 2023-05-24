// Header Files
#include "GameState.h"

bool GameState::IsAlive() const
{
	return isAlive;
}

bool GameState::IsActive() const
{
	return isActive;
}

void GameState::IsAlive(bool alive)
{
	isAlive = alive;
}

void GameState::IsActive(bool active)
{
	isActive = active;
}