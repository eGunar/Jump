#ifndef Phyiscs_H
#include "Player.h"
#pragma once


class Physics {

public:
	void ApplyGravity(int velocityY);
	void Update(Entity* entity);
private:
	const int gravity = 5;
};

#endif // !Phyiscs_H

