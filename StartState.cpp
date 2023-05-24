// Header Files
#include "StartState.h"

bool StartState::OnEnter()
{
    image.Load("StartMenu.png");
    menu = std::make_unique<MenuKey>("Fonts/Gothic.ttf", MenuKey::Alignment::Bottom);
    menu->SetMenuText(MenuKey::Index::Index_1, "Play game");
    menu->SetMenuText(MenuKey::Index::Index_2, "Quit game");

    return true;
}

void StartState::OnExit()
{
    image.~Background();
}

GameState* StartState::Update(int deltaTime)
{
	menu->Update(deltaTime);

	if (menu->GetMenuChoice() == static_cast<MenuKey::Index>(MenuOption::Play))
	{
		image.StopMusic();
		return new PlayState;
	}

	if (menu->GetMenuChoice() == static_cast<MenuKey::Index>(MenuOption::Quit))
	{
		image.StopMusic();
		return nullptr;
	}

	return this;
}

bool StartState::Render()
{
	image.Render();
	menu->Render();
	return true;
}
