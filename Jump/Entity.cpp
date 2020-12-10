#include "Entity.h"

Entity::Entity(bool usePhysics)
{
	if (usePhysics)
		physics = new Physics();
	else
		physics = nullptr;
}

Entity::~Entity()
{
	if (physics != nullptr)
		delete physics;
}

void Entity::Update(double DT) {
	position.x += velocity.x * DT;
	position.y += velocity.y * DT;
	if (physics != nullptr)
		physics->ApplyGravity(velocity.y);
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
