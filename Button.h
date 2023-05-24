// Header Guard
#pragma once

// Header Files
#include "BoxCollider.h"
#include "GameObject.h"
#include "Input.h"
#include "Texture.h"

class Button : public GameObject
{
public:
	// Enum Class
	enum class State
	{
		Default = 1,
		Hover = 2,
		Clicked = 3
	};

	// Constructor + Destructor
	Button(const SDL_Point& position, const SDL_Point& dimension, const SDL_Rect& textureDimension, const std::string& filename = "", bool hasClickState = false, int rowIndex = 1);
	virtual ~Button() {}

	// Update
	virtual void Update(int deltaTime) override;

	// Render
	virtual bool Render() override;

private:
	Texture texture;
	SDL_Rect collider;
	State state{ State::Default };

	int rowIndex;
	bool hasClickState;
};