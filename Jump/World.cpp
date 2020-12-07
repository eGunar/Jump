#include "World.h"
#include "Player.h"
World::World()
{
	Player* player = new Player();
	Entities.push_back(player);
	Entities.push_back(new Player(700, 300, -100));
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
