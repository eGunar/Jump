#pragma once
#include "Vector.h"
class Point
{
public:
	Point(float x, float y)
	{
		x_ = x;
		y_ = y;
	}
	Point() {}
	Point AddVector(Vector v);
	static float Distance(Point a, Point b);
	static float Get_Angle(Point a, Point b);
	float x_;
	float y_;


};