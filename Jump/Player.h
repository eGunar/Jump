#ifndef Player_H
#define Player_H
#include "Entity.h"
#include <algorithm>
#include "GameSettings.h"
#include "MovementController.h"
#include "GameCamera.h"
#include "Physics.h"
#include "PlayerStateMachine.h"
#pragma once
class IdleState;
class RunningState;
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
	MovementController* GetMovementController();
	void SetState(PlayerStates state);
	bool IsOnGround();
	void SetPreviousState();

private:
	int Accelerate(Direction direction);
	int Decelerate(Direction direction);
	MovementController movementController;
	IPlayerState* GetCurrentState();
	PlayerStateMachine stateMachine;
};

#endif // !Player_H