#pragma once
#include <math.h>
class Vector
{
public:
	Vector(float x, float y)
	{
		x_ = x;
		y_ = y;
	}
	float x_;
	float y_;


	float Length();

};
