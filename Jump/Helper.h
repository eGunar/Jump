#ifndef Helper_H
#define	Helper_H
#include "Entity.h"
#pragma once

class Helper {
public:
	static bool EntitiesIntersectX(Entity* e1, Entity* e2);
	static bool EntitiesIntersectY(Entity* e1, Entity* e2);
	static bool EntitiesIntersect(Entity* e1, Entity* e2);
};




#endif // !Helper_H

