#ifndef Phyiscs_H
#define Physics_H
#include "GameSettings.h"
#include <vector>
#pragma once

class Entity;
class Physics {

public:
	Physics(bool gravity = false, bool collision = false);
	void ApplyGravity(Entity* entity);
	void Update(Entity* entity);
	std::vector<Entity*> IsColliding(Entity* entity);
private:
	bool affectedByGravity = false;
	bool detectCollision = false;
};

#endif // !Phyiscs_H

