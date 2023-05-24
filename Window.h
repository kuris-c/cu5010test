// Header Guard
#pragma once

// Header Files
#include "Utility.h"

// SDL Libraries
#include <SDL.h>

class Window
{
public:
	// Singleton
	static Window* Instance();

	// Init
	bool Init(const char* gameTitle, int width = 1600, int height = 900, int xPos = SDL_WINDOWPOS_CENTERED, int yPos = SDL_WINDOWPOS_CENTERED, bool fullScreen = false);

	// Start and End Frame
	void WipeRenderer();
	void ShowRenderer();

	// Close Screen
	void CloseScreen();

	// Getters
	HWND GetWindowHandle();
	SDL_Window* GetWindow() const;
	SDL_Renderer* GetRenderer() const;
	SDL_Point GetResolution() const;

private:
	// Constructor
	Window() {}
	Window(const Window&);
	Window& operator=(const Window&);

	// SDL Variables
	HWND windowHandle{ nullptr };
	SDL_Window* window{ nullptr };
	SDL_Renderer* renderer{ nullptr };

	// Resolution
	int width{ 0 };
	int height{ 0 };
};