#pragma once
#include "SDL.h";
#include <vector>

class Entity {
public:
	virtual void Update(double DT) = 0;
	virtual void HandleEvents(const SDL_Event& evt) = 0;
	virtual void Render() = 0;
	virtual void Clean() = 0;
protected:
	SDL_Rect velocity;
	SDL_Rect position;
	float maxSpeed = 100;
	float accelerationSpeed = 10;
};