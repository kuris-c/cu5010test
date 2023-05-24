// Header Files
#include "Game.h"

Game::Game(GameState* initialGameState)
{
	gameState.reset(initialGameState);
}

bool Game::Initialize(const std::string& name, int screenWidth, int screenHeight, bool fullscreen)
{
	if (!Window::Instance()->Init(name.c_str(), screenWidth, screenHeight, fullscreen))
	{
		return false;
	}

	Utility::SetWindowHandle(Window::Instance()->GetWindowHandle());
	return true;
}

bool Game::Run()
{
	gameState->OnEnter();

	while (gameState)
	{

		int startTime = SDL_GetTicks();

		Window::Instance()->WipeRenderer();
		Input::Instance()->Update();

		GameState* nextState = gameState->Update(deltaTime);

		gameState->Render();

		Window::Instance()->ShowRenderer();

		if (nextState != gameState.get())
		{
			gameState->OnExit();
			gameState.reset(nextState);

			if (gameState)
			{
				gameState->OnEnter();
			}
		}

		deltaTime = SDL_GetTicks() - startTime;
	}

	return true;
}

void Game::Shutdown()
{
	Window::Instance()->CloseScreen();
}