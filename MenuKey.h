// Header Guard
#pragma once

// Header Files
#include "GameObject.h"
#include "Input.h"
#include "Text.h"
#include "Window.h"

class MenuKey : public GameObject
{
public:
	// Enum Classes
	enum class Alignment
	{
		Centre,
		Bottom,
		Left,
		Right
	};
	enum class Index
	{
		Index_1,
		Index_2,
		Index_3,
		Index_4,
		Index_5,
		None = -1
	};

	// Constructor + Destructor
	MenuKey(const std::string& filename = "", Alignment alignment = Alignment::Centre, int menuTotal = 2, int charWidth = 25, int charHeight = 50, int padding = 10);
	virtual ~MenuKey();

	// Getter
	Index GetMenuChoice() const;

	// Setter
	void SetActiveColor(Uint8 r, Uint8 g, Uint8 b);
	void SetInactiveColor(Uint8 r, Uint8 g, Uint8 b);
	void SetMenuText(Index index, const std::string& text);

	// Update
	void Update(int deltaTime) override;

	// Render
	bool Render() override;

	// Reset
	void Reset();
	
private:
	Alignment alignment;

	SDL_Point charDimension;
	SDL_Color activeColor{ 240, 0, 0 };
	SDL_Color inactiveColor{ 0, 0, 0 };

	std::vector<Text> menuItems;
	Index menuActive{ Index::Index_1 };
	Index menuChoice{ Index::None };
};