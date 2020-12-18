#ifndef WORLD_H
#define WORLD_H
#pragma once

#include <vector>
#include "Entity.h"
#include "Block.h"
#include "Player.h"
#include "GameCamera.h"

class World {
public:
	World();
	~World();
	void Update(double DT);
	void HandleEvents(SDL_Event evt);
	void Render();
	std::vector<Entity*> GetCollidableEntities(Entity* entitiy);
private:
	std::vector<Entity*> Entities;
	
};
#endif