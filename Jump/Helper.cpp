#include "Helper.h"


bool Helper::EntitiesIntersectX(Entity* e1, Entity* e2)
{
    return !(e1->Left() >= e2->Right() || e2->Left() >= e1->Right());
}
