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
const SDL_Rect* Entity::GetNextPosition() {
	return &nextPosition;
}
void Entity::HandleCollision(std::vector<Entity*> collidingEntities)
{
}
void Entity::CollisionsStopped()
{
}
int Entity::Top()
{
	return position.y;
}
int Entity::Bottom()
{
	return position.y + position.h;
}
int Entity::Left()
{
	return position.x;
}
int Entity::Right()
{
	return position.x + position.w;
}

bool Entity::HasCollisionDetection() {
	return hasCollision;
}

Entity::~Entity()
{
	
}

void Entity::Update(double DT) {
	previousPosition = position;
	position.x += velocity.x * DT;
	position.y += velocity.y * DT;
	nextPosition.x = position.x += velocity.x * DT;
	nextPosition.y = position.y += velocity.y * DT;
	if (physics != nullptr)
		physics->Update(this, DT);
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
	if (physics != nullptr)
		delete physics;
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
