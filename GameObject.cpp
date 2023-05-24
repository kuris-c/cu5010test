// Header Files
#include "GameObject.h"

bool GameObject::IsAlive() const
{
	return isAlive;
}

bool GameObject::IsActive() const
{
	return isActive;
}

bool GameObject::IsVisible() const
{
	return isVisible;
}

const std::string& GameObject::GetTag() const
{
	return tag;
}

const SDL_Point& GameObject::GetPosition() const
{
	return position;
}

const SDL_Point& GameObject::GetDimension() const
{
	return dimension;
}

void GameObject::IsAlive(bool alive)
{
	isAlive = alive;
}

void GameObject::IsActive(bool active)
{
	isActive = active;
}

void GameObject::IsVisible(bool visible)
{
	isVisible = visible;
}

void GameObject::SetTag(const std::string& tag)
{
	this->tag = tag;
}

void GameObject::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void GameObject::SetDimension(int x, int y)
{
	dimension.x = x;
	dimension.y = y;
}