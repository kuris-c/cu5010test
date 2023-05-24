// Header Files
#include "MenuKey.h"

MenuKey::MenuKey(const std::string& filename, Alignment alignment, int menuTotal, int charWidth, int charHeight, int padding) : alignment(alignment)
{
	charDimension.x = charWidth;
	charDimension.y = charHeight;

	auto resolution = Window::Instance()->GetResolution();

	if (alignment == Alignment::Centre)
	{
		position.x = resolution.x / 2;
		position.y - static_cast<int>((resolution.y / 2) - (menuTotal / 2.0f * charHeight));
	}

	else if (alignment == Alignment::Bottom)
	{
		position.x = resolution.x / 2;
		position.y = static_cast<int>((resolution.y - resolution.y / 4) - (menuTotal / 2.0f * charHeight));
	}

	else if (alignment == Alignment::Left)
	{
		position.x += padding;
		position.y = static_cast<int>((resolution.y - resolution.y / 4) - (menuTotal / 2.0f * charHeight));
	}

	else if (alignment == Alignment::Right)
	{
		position.x = resolution.x - padding;
		position.y = static_cast<int>((resolution.y - resolution.y / 4) - (menuTotal / 2.0f * charHeight));
	}

	for (int i = 0; i < menuTotal; i++)
	{
		menuItems.push_back(Text());
	}

	Text::Load(filename, "MenuFont");
}

MenuKey::~MenuKey()
{
	menuItems.clear();
	Text::Unload("MenuFont");
}

MenuKey::Index MenuKey::GetMenuChoice() const
{
	return menuChoice;
}

void MenuKey::SetActiveColor(Uint8 r, Uint8 g, Uint8 b)
{
	activeColor = { r, g, b };
}

void MenuKey::SetInactiveColor(Uint8 r, Uint8 g, Uint8 b)
{
	inactiveColor = { r, g, b };
}

void MenuKey::SetMenuText(Index index, const std::string& text)
{
	menuItems[static_cast<int>(index)].SetFont("MenuFont");
	menuItems[static_cast<int>(index)].SetString(text);
	menuItems[static_cast<int>(index)].SetSize(text.size() * charDimension.x, charDimension.y);
	menuItems[static_cast<int>(index)].SetColor(inactiveColor.r, inactiveColor.g, inactiveColor.b);
}

void MenuKey::Update(int deltaTime)
{
	static bool isKeyPressed = false;

	if (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) && !isKeyPressed)
	{
		if (menuActive == static_cast<Index>(menuItems.size() - 1))
		{
			menuActive = Index::Index_1;
		}

		else
		{
			menuActive = static_cast<Index>(static_cast<int>(menuActive) + 1);
		}

		isDirty = true;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_UP) && !isKeyPressed)
	{
		if (menuActive == Index::Index_1)
		{
			menuActive = static_cast<Index>(menuItems.size() - 1);
		}
		else
		{
			menuActive = static_cast<Index>(static_cast<int>(menuActive) - 1);
		}

		isDirty = true;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN))
	{
		menuChoice = menuActive;
	}

	isKeyPressed = Input::Instance()->IsKeyPressed();

	if (isDirty)
	{
		for (size_t i = 0; i < menuItems.size(); i++)
		{
			menuItems[i].SetColor(inactiveColor.r, inactiveColor.g, inactiveColor.b);
		}

		menuItems[static_cast<int>(menuActive)].SetColor(activeColor.r, activeColor.g, activeColor.b);

		isDirty = false;
	}
}

bool MenuKey::Render()
{
	for (size_t i = 0; i < menuItems.size(); i++)
	{
		if (alignment == Alignment::Centre || alignment == Alignment::Bottom)
		{
			menuItems[i].Render(position.x - (menuItems[i].GetSize().x / 2),      //x
				position.y + (i * menuItems[i].GetSize().y));					  //y
		}

		else if (alignment == Alignment::Left)
		{
			menuItems[i].Render(position.x,                                       //x
				position.y + (i * menuItems[i].GetSize().y));					  //y
		}

		else if (alignment == Alignment::Right)
		{
			menuItems[i].Render(position.x - menuItems[i].GetSize().x,            //x
				position.y + (i * menuItems[i].GetSize().y));					  //y
		}
	}

	return true;
}

void MenuKey::Reset()
{
	menuActive = Index::Index_1;
	menuChoice = Index::None;
}