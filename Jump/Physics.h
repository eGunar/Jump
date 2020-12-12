#ifndef Phyiscs_H
#define Physics_H
#include "GameSettings.h"
#pragma once

class Entity;
class Physics {

public:
	void ApplyGravity(Entity* entity);
	void Update(Entity* entity);
private:
};

#endif // !Phyiscs_H

