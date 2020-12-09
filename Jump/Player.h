#ifndef Player_H
#define Player_H
#pragma once
#include "Entity.h"
#include <vector>
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
	virtual void Render() override;
	virtual void Clean() override;

private:
	float Accelerate(Direction direction);
	float Decelerate(Direction direction);

	MovementController* movementController;
};

#endif // !Player_H


