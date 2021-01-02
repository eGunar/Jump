#ifndef Player_H
#define Player_H
#include "Entity.h"
#include <algorithm>
#include "GameSettings.h"
#include "MovementController.h"
#include "IPlayerState.h"
#include "IdleState.h"
#include "RunningState.h"
#include "GameCamera.h"
#include "Physics.h"
#pragma once
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
	void CollisionsStopped() override;

private:
	void InitStates();
	int Accelerate(Direction direction);
	int Decelerate(Direction direction);
	bool isOnGround = false;
	MovementController movementController;
	IdleState idleState;
	RunningState runningState;

	IPlayerState* GetCurrentState();
};

#endif // !Player_H