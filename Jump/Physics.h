#ifndef Phyiscs_H
#define Physics_H
#include "GameSettings.h"
#include <vector>
#pragma once

class Entity;
class Physics {

public:
	Physics(bool gravity = false, bool collision = false);
	~Physics();
	void Update(Entity* entity);
	std::vector<Entity*> GetCollidingEntities(Entity* entity);
private:
	void ApplyGravity(Entity* entity);
	void HandleCollision(Entity* entity);
	bool affectedByGravity = false;
	bool detectCollision = false;
};

#endif // !Phyiscs_H

