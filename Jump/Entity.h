#pragma once
#include "SDL.h";
#include <vector>
#include "TextureManager.h"

class Entity {
public:
	virtual void Update(double DT);
	virtual void HandleEvents(const SDL_Event& evt);
	virtual void Render();
	virtual void Clean();
protected:
	SDL_Rect velocity;
	SDL_Rect position;
	float maxSpeed = 500;
	float accelerationSpeed = 10;
	bool isSolid = false;
	SDL_Texture* texture;;
};