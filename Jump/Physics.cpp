#include "Physics.h"

void Physics::ApplyGravity(int velocityY)
{
	velocityY = velocityY + gravity;
}

void Physics::Update(Entity* entity)
{
	ApplyGravity(entity)
}
