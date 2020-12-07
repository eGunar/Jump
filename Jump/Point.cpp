#include "Point.h"

Point Point::AddVector(Vector v)
{
	Point p2;
	p2.x_ = x_ + v.x_;
	p2.y_ = y_ + v.y_;

	return p2;
}

float Point::Distance(Point a, Point b)
{
	float dx = a.x_ - b.x_;
	float dy = a.y_ - b.y_;

	return (sqrtf(dx * dx + dy * dy));
}

float Point::Get_Angle(Point a, Point b)
{
	double pi = 3.1415926535897;
	float dx = (a.x_ - b.x_);
	float dy = (a.y_ - b.y_);
	return double(atan2(dy, dx) * 180.f / pi);
}