#include "Game.h"
#include "Physics.h"
#include "Entity.h"
Physics::Physics(bool gravity, bool collision)
{
	affectedByGravity = gravity;
	detectCollision = collision;
}
void Physics::ApplyGravity(Entity* entity)
{
	entity->SetVelocityY(entity->GetVelocityY() + GameSettings::gravity);
}
void Physics::HandleCollision(Entity* entity)
{
	std::vector<Entity*> entitites = IsColliding(entity);
	if (entitites.empty())
		return;

	entity->HandleCollision(entitites);

}
std::vector<Entity*> Physics::IsColliding(Entity* entity)
{
	std::vector<Entity*> collidable = Game::world->GetCollidableEntities(entity);
	std::vector<Entity*> colliding;

	for (Entity* ent : collidable) {
		if (SDL_HasIntersection(entity->GetPosition(), ent->GetPosition()))
			colliding.push_back(ent);
	}
	return colliding;
}

void Physics::Update(Entity* entity)
{
	if (affectedByGravity)
		ApplyGravity(entity);
	if (detectCollision)
		HandleCollision(entity);
}