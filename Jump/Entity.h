#ifndef Entity_H
#define Entity_H

#pragma once
#include "SDL.h"
#include <vector>
#include "TextureManager.h"

class Physics;
class Entity {
public:
	Entity(bool usePhysics = false, bool gravity = false, bool collision = false);
	~Entity();
	virtual void Update(double DT);
	virtual void HandleEvents(const SDL_Event& evt);
	virtual void Render();
	virtual void Clean();
	void SetVelocityY(int v);
	void SetVelocityX(int v);
	int GetVelocityY();
	int GetVelocityX();
protected:
	int maxSpeed = 500;
	int accelerationSpeed = 10;
	bool isSolid = false;
	SDL_Texture* texture;
	SDL_Rect velocity;
	SDL_Rect position;

private:
	Physics* physics;

};



#endif // !Entity_H
