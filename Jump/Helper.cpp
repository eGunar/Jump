#include "Helper.h"


bool Helper::EntitiesIntersectX(Entity* e1, Entity* e2)
{
    return !(e1->Left() >= e2->Right() || e2->Left() >= e1->Right());
}

bool Helper::EntitiesIntersectY(Entity* e1, Entity* e2)
{
    return !(e1->Top() <= e2->Top() || e2->Top() <= e1->Top());
}

bool Helper::EntitiesIntersect(Entity* e1, Entity* e2)
{
    return EntitiesIntersectX(e1, e2) && EntitiesIntersectY(e1, e2);
}
