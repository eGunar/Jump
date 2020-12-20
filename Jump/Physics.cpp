#include "Game.h"
#include "Physics.h"
#include "Entity.h"
Physics::Physics(bool gravity, bool collision)
{
	affectedByGravity = gravity;
	detectCollision = collision;
}
Physics::~Physics()
{
}
void Physics::ApplyGravity(Entity* entity)
{
	if (entity->ShouldApplyGravity())
		entity->SetVelocityY(entity->GetVelocityY() + GameSettings::gravity);
}
void Physics::HandleCollision(Entity* entity)
{
	std::vector<Entity*> entitites = GetCollidingEntities(entity);
	if (entitites.empty()) {
		entity->CollisionsStopped();
		return;
	}

	entity->HandleCollision(entitites);
}
std::vector<Entity*> Physics::GetCollidingEntities(Entity* entity)
{
	std::vector<Entity*> collidable = Game::world->GetCollidableEntities(entity);
	std::vector<Entity*> colliding;

	for (Entity* ent : collidable) {
		if (SDL_HasIntersection(entity->GetPosition(), ent->GetPosition()))
			colliding.push_back(ent);
	}
	return colliding;
}

void Physics::Update(Entity* entity, double DT)
{
	if (affectedByGravity)
		ApplyGravity(entity);
	if (detectCollision)
		HandleCollision(entity);
}