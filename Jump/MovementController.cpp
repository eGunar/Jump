#include "MovementController.h"

MovementController::MovementController() {
    movingUp = false;
    movingDown = false;
    movingLeft = false;
    movingRight = false;
}

void MovementController::StartMovingUp()
{
    movingUp = true;
    //movingDown = false;
}

void MovementController::StartMovingDown()
{
    movingDown = true;
    //movingUp = false;
}

void MovementController::StartMovingRight()
{
    //movingLeft = false;
    movingRight = true;
}

void MovementController::StartMovingLeft()
{
    //movingRight = false;
    movingLeft = true;
}

void MovementController::StopMovingUp()
{
    movingUp = false;
}

void MovementController::StopMovingDown()
{
    movingDown = false;
}

void MovementController::StopMovingRight()
{
    movingRight = false;
}

void MovementController::StopMovingLeft()
{
    movingLeft = false;
}

void MovementController::StopMoving()
{
    movingUp = false;
    movingDown = false;
    movingLeft = false;
    movingRight = false;
}

bool MovementController::GetMovingUp()
{
    return movingUp;
}

bool MovementController::GetMovingDown()
{
    return movingDown;
}

bool MovementController::GetMovingRight()
{
    return movingRight;
}

bool MovementController::GetMovingLeft()
{
    return movingLeft;
}
