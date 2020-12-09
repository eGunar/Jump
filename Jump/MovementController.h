#pragma once
#ifndef MovementController_H
#define MovementController_H

class MovementController {
public:
	MovementController();
	void StartMovingUp();
	void StartMovingDown();
	void StartMovingRight();
	void StartMovingLeft();

	void StopMovingUp();
	void StopMovingDown();
	void StopMovingRight();
	void StopMovingLeft();

	void StopMoving();

	bool GetMovingUp();
	bool GetMovingDown();
	bool GetMovingRight();
	bool GetMovingLeft();
private:
	bool movingUp;
	bool movingDown;
	bool movingLeft;
	bool movingRight;
};

#endif // !MovementController_H