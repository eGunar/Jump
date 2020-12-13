#ifndef Player_H
#define Player_H
#pragma once
#include "Entity.h"
#include <algorithm>
#include "GameSettings.h"
#include "MovementController.h"
enum class Direction {
	UP,
	Down,
	Left,
	Right,
	Y,
	X
};
class Player : public Entity {
public:
	Player();
	Player(int x, int y, int speed);
	// Inherited via Entity
	virtual void Update(double DT) override;
	virtual void HandleEvents(const SDL_Event& evt) override;
	void HandleCollision(std::vector<Entity*> collidingEntities) override;
	virtual void Render() override;
	virtual void Clean() override;
	bool IsOnGround() override;
	void CollisionsStopped() override;

private:
	int Accelerate(Direction direction);
	int Decelerate(Direction direction);
	bool isOnGround = false;
	MovementController movementController;
};

#endif // !Player_H