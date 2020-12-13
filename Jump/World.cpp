#include "World.h"
World::World()
{
	Player* player = new Player();
	Entities.push_back(player);
	Entities.push_back(new Block());
}

World::~World()
{
	for (Entity* entity : Entities) {
		entity->Clean();
		delete entity;
	}
}

void World::Update(double DT)
{
	for (Entity *entity : Entities) {
		entity->Update(DT);
	}
}

void World::HandleEvents(SDL_Event evt)
{
	for (Entity* entity : Entities) {
		entity->HandleEvents(evt);
	}
}

void World::Render()
{
	for (Entity* entity : Entities) {
		entity->Render();
	}
}
/// <summary>
/// Get all possible entities the given entity can collide with
/// </summary>
/// <param name="entity"></param>
/// <returns></returns>
std::vector<Entity*> World::GetCollidableEntities(Entity* ent)
{
	std::vector<Entity*> entities;
	for (Entity* entity : Entities) {
		if (entity == ent)
			continue;
		if (entity->HasCollisionDetection())
			entities.push_back(entity);
	}
	return entities;
}
