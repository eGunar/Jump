#include "IdleState.h"

IdleState::IdleState()
{
}

IdleState::IdleState(const char* texturePath, Player* p) : RunningState(texturePath, p)
{
}

void IdleState::Update(double DT)
{
}

void IdleState::HandleEvents(const SDL_Event& evt)
{
	RunningState::HandleEvents(evt);
}

void IdleState::OnEnter()
{
}

void IdleState::OnExit()
{
}
