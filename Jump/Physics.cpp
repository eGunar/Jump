#include "Physics.h"
#include "Entity.h"
void Physics::ApplyGravity(Entity* entity)
{
	entity->SetVelocityY(entity->GetVelocityY() + GameSettings::gravity);
}

void Physics::Update(Entity* entity)
{
	ApplyGravity(entity);
}
