#ifndef PlayerStateMachine_H
#define PlayerStateMachine_H
#include "IPlayerState.h"

#pragma once
enum class PlayerStates {
	idle,
	run,
	jump
};
class Player;
class IdleState;
class JumpState;
class RunningState;
class PlayerStateMachine {
public:
	PlayerStateMachine() {}
	PlayerStateMachine(Player* p);
	void SetState(PlayerStates state);
	void SetPreviousState();
	IPlayerState* GetCurrentState();

private:
	IPlayerState* currentState;
	IPlayerState* previousState;
	void SetState(IPlayerState* state);
	IPlayerState* GetState(PlayerStates state);

	IdleState* idleState;
	JumpState* jumpState;
	RunningState* runningState;
};



#endif // !StateMachine_H

