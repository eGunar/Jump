#include "Entity.h"

void Entity::Update(double DT) {
	position.x += velocity.x * DT;
	position.y += velocity.y * DT;
}