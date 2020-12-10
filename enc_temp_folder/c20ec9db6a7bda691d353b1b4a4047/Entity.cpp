#include "Entity.h"

void Entity::Update(double DT) {
	position.x += velocity.x * DT;
	position.y += velocity.y * DT;
}

void Entity::HandleEvents(const SDL_Event& evt)
{
}

void Entity::Render()
{
	TextureManager::Draw(texture, position, 0);
}

void Entity::Clean()
{
}
