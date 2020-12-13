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
std::vector<Entity*> Physics::IsColliding(Entity* entity)
{
	return std::vector<Entity*>();
}

void Physics::Update(Entity* entity)
{
	if (affectedByGravity)
		ApplyGravity(entity);
	if (detectCollision)
		IsColliding(entity);
}