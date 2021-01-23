#include "PlayerStateMachine.h"
#include "RunningState.h"
#include "JumpState.h"
#include "IdleState.h"
#include "Player.h"

PlayerStateMachine::PlayerStateMachine(Player* p)
{
	previousState = nullptr;

	runningState = new RunningState("assets/magician.png", p);
	jumpState = new JumpState("assets/magician.png", p);
	idleState = new IdleState("assets/magician.png", p);
	currentState = idleState;
}


void PlayerStateMachine::SetState(PlayerStates state)
{
	SetState(GetState(state));
}

void PlayerStateMachine::SetPreviousState()
{
	SetState(previousState);
}

IPlayerState* PlayerStateMachine::GetCurrentState()
{
	return currentState;
}

void PlayerStateMachine::SetState(IPlayerState* state)
{
	if (state == currentState)
		return;

	previousState = currentState;
	if (currentState == nullptr) {
		currentState = state;
		return;
	}
	currentState->OnExit();
	currentState = state;
	currentState->OnEnter();
}

IPlayerState* PlayerStateMachine::GetState(PlayerStates state)
{
	switch (state) {
	case (PlayerStates::idle):
		return idleState;
	case (PlayerStates::run):
		return runningState;
	case (PlayerStates::jump):
		return jumpState;
	}
	return idleState;
}
