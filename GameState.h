// Header Guard
#pragma once

class GameState
{
public:
	// Constructor + Destructor
	GameState() {}
	virtual ~GameState() = 0 {}

	// Getters
	bool IsAlive() const;
	bool IsActive() const;

	// Setters
	void IsAlive(bool alive);
	void IsActive(bool active);

	// On Enter + Exit
	virtual bool OnEnter() = 0;
	virtual void OnExit() = 0;

	// Update
	virtual GameState* Update(int deltaTime) = 0;

	// Render
	virtual bool Render() = 0;

private:
	bool isAlive{ true };
	bool isActive{ true };
	GameState* previousState{ nullptr };
};