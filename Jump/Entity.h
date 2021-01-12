#ifndef Entity_H
#define Entity_H

#include "SDL.h"
#include <vector>
#include "TextureManager.h"
#pragma once

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
	bool HasCollisionDetection();
	const SDL_Rect* GetPosition();
	const SDL_Rect* GetNextPosition();
	virtual void HandleCollision(std::vector<Entity*> collidingEntities);
	virtual void CollisionsStopped();
	int Top();
	int Bottom();
	int Left();
	int Right();
protected:
	bool isSolid = false;
	SDL_Texture* texture;
	SDL_Rect velocity;
	SDL_Rect position;
	SDL_Rect nextPosition;
	SDL_Rect previousPosition;
	Physics* physics;

private:
	bool hasCollision = false;
};



#endif // !Entity_H
