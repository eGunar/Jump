#ifndef Phyiscs_H
#define Physics_H
#include "GameSettings.h"
#include <vector>
#include "Helper.h"
#pragma once

class Entity;
class Physics {

public:
	Physics(bool gravity = false, bool collision = false);
	~Physics();
	void Update(Entity* entity, double DT);
	std::vector<Entity*> GetCollidingEntities(Entity* entity);
	static std::vector<Entity*> GetNextFrameCollidingEntities(Entity* entity);
	bool IsStandingOnBlock(Entity* entity);
private:
	void ApplyGravity(Entity* entity);
	void HandleCollision(Entity* entity);
	bool affectedByGravity = false;
	bool detectCollision = false;
};

#endif // !Phyiscs_H

