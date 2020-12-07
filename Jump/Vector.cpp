#include "Vector.h"

float Vector::Length()
{
	return (sqrtf(x_ * x_ + y_ * y_));
}
