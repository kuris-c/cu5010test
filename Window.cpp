// Header Files
#include "Window.h"

Window* Window::Instance()
{
	static Window* instance = new Window();
	return instance;
}

bool Window::Init(const char* gameTitle, int width, int height, int xPos, int yPos, bool fullScreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        Utility::Log(Utility::Destination::WindowsMessageBox, "SDL Did Not Intialise Successfully!", Utility::Severity::Failure);
        return false;
    }

    Uint32 fullScreenFlag = (fullScreen) ? SDL_WINDOW_FULLSCREEN : 0;
    window = SDL_CreateWindow(gameTitle, xPos, yPos, width, height, fullScreenFlag);
    if (!window)
    {
        Utility::Log(Utility::Destination::WindowsMessageBox, "Game Window Could Not Be Created!", Utility::Severity::Failure);
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        Utility::Log(Utility::Destination::WindowsMessageBox, "Game Renderer Could Not Be Created", Utility::Severity::Failure);
        return false;
    }

    this->width = width;
    this->height = height;
    return true;
}

void Window::WipeRenderer()
{
    SDL_RenderClear(renderer);
}

void Window::ShowRenderer()
{
    SDL_RenderPresent(renderer);
}

void Window::CloseScreen()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit;
}

HWND Window::GetWindowHandle()
{
    return windowHandle;
}

SDL_Window* Window::GetWindow() const
{
	return window;
}

SDL_Renderer* Window::GetRenderer() const
{
	return renderer;
}

SDL_Point Window::GetResolution() const
{
	return SDL_Point{ width, height };
}