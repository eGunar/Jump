#pragma once
#include "SDL.h";
#include <vector>
#include "Vector.h"
class Entity {
public:
	virtual void Update(double DT) = 0;
	virtual void HandleEvents(SDL_Event evt) = 0;
	virtual void Render() = 0;
	virtual void Clean() = 0;
private:
	Vector velocity;
	Vector position;
};