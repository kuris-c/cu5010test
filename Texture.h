// Header Guard
#pragma once

// Header Files
#include "Window.h"

// SDL Libraries
#include <SDL_image.h>

// Map
typedef std::map<std::string, SDL_Texture*> Textures;

class Texture
{
public:
	// Constructor
	Texture() {}

	// Enum Class
	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Vertical = SDL_FLIP_VERTICAL,
		Horizontal = SDL_FLIP_HORIZONTAL
	};

	// Load and Unload
	static bool Load(const std::string& filename, const std::string& tag);
	static void Unload(const std::string& tag = "");

	// Getters
	bool IsAnimationDead();
	bool IsAnimationLooping();

	// Setters
	bool SetTexture(const std::string& tag); 
	void SetDimension(int width, int height);
	void SetSourceDimension(int columns, int rows, int width, int height);
	void SetCel(int column, int row);
	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);
	void SetAnimationVelocity(float velocity);

	// Update
	void ResetAnimation();
	void Update(int deltaTime);

	// Render
	void Render(int x = 0, int y = 0, double angle = 0.0, Flip flip = Flip::None);

private:
	// Animations
	int cel{ 0 };
	float animationVelocity{ 0.0f };
	float animationRunningTime{ 0.0f };
	bool isAnimated{ false };
	bool isAnimationDead{ false };
	bool isAnimationLooping{ true };
	bool isAnimationLoopFinal{ false };

	// Texture
	SDL_Texture* texture{ nullptr };
	SDL_Point celDimension = { 0, 0 };
	SDL_Point sourceDimension = { 1, 1 };
	SDL_Point textureDimension = { 0, 0 };

	// Folder and Pointer
	static std::string rootFolder;
	static std::unique_ptr<Textures> textures;
};