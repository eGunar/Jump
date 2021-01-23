#include "World.h"
World::World()
{
	Player* player = new Player();
	Entities.push_back(player);
	
	for (int i = -20; i < 50; i++) {
		Entities.push_back(new Block(32 * i, 600));
	}
	for (int i = 1; i < 50; i++) {
		Entities.push_back(new Block(500, 32 * i));
	}
	
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
	GameCamera::Render();
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
