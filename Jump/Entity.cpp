#include "Entity.h"
#include "Physics.h"
Entity::Entity(bool usePhysics, bool gravity, bool collision)
{
	if (usePhysics)
		physics = new Physics(gravity, collision);
	else
		physics = nullptr;

	hasCollision = collision;
}
const SDL_Rect* Entity::GetPosition() {
	return &position;
}
void Entity::HandleCollision(std::vector<Entity*> collidingEntities)
{
	std::printf("Colliding");
}
bool Entity::HasCollisionDetection() {
	return hasCollision;
}

Entity::~Entity()
{
	if (physics != nullptr)
		delete physics;
}

void Entity::Update(double DT) {
	previousPosition.x = position.x;
	previousPosition.y = position.y;
	
	position.x += velocity.x * DT;
	position.y += velocity.y * DT;
	if (physics != nullptr)
		physics->Update(this);
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

void Entity::SetVelocityY(int v)
{
	velocity.y = v;
}

void Entity::SetVelocityX(int v)
{
	velocity.x = v;
}

int Entity::GetVelocityY()
{
	return velocity.y;
}

int Entity::GetVelocityX()
{
	return velocity.x;
}
