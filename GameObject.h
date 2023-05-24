// Header Guard
#pragma once

// C++ Libraries
#include <string>

// SDL Libraries
#include <SDL.h>

class GameObject
{
public:
	// Constructor + Destructor
	GameObject() {}
	virtual ~GameObject() = 0 {}

	// Getters
	bool IsAlive() const;
	bool IsActive() const;
	bool IsVisible() const;
	const std::string& GetTag() const;
	const SDL_Point& GetPosition() const;
	const SDL_Point& GetDimension() const;

	// Setters
	void IsAlive(bool alive);
	void IsActive(bool active);
	void IsVisible(bool visible);
	void SetTag(const std::string& tag);
	void SetPosition(int x, int y);
	void SetDimension(int x, int y);

	// Update
	virtual void Update(int deltaTime) = 0;
	virtual bool Render() = 0;

protected:
	int priority{ 0 };
	std::string tag;

	bool isDirty{ true };
	bool isAlive{ true };
	bool isActive{ true };
	bool isVisible{ true };

	float angle{ 0.0f };
	SDL_Point position{ 0,0 };
	SDL_Point dimension{ 0,0 };
};