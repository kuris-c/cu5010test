// Header Guard
#pragma once

// Header Files
#include "Window.h"

// SDL Libraries
#include <SDL_ttf.h>

// Map
typedef std::map<std::string, TTF_Font*> Fonts;

class Text
{
public:
	// Constructor + Destructor
	Text() {}
	Text(const Text& copy);
	~Text();

	// Enum Class
	enum class FontSize
	{
		Small = 72,
		Medium = 144,
		Large = 300
	};

	// Init
	static bool Initialize();

	// Load and Unload
	static bool Load(const std::string& filename,
		const std::string& tag,
		FontSize fontSize = FontSize::Small);
	static void Unload(const std::string& tag = "");

	// Shutdown
	static void Shutdown();

	// Getters
	const SDL_Point& GetSize() const;
	const std::string& GetString() const;

	// Setters
	void SetSize(int width, int height);
	bool SetFont(const std::string& tag);
	void SetColor(Uint8 r, Uint8 g, Uint8 b);
	void SetString(const std::string& string);

	// Render
	void Render(int x = 0, int y = 0);

private:
	// Create
	void CreateText();

	// Text
	std::string string;
	bool isDirty{ true };
	SDL_Point textSize{ 0, 0 };

	// Font
	TTF_Font* font{ nullptr };
	SDL_Texture* texture{ nullptr };
	SDL_Color color{ 255, 255, 255 };

	// Folder and Pointer
	static std::string rootFolder;
	static std::unique_ptr<Fonts> fonts;
};