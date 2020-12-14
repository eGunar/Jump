#include "IdleState.h"

IdleState::IdleState()
{
}

IdleState::IdleState(const char* texturePath) : IPlayerState(texturePath)
{
}

void IdleState::Update(double DT)
{
}

void IdleState::HandleEvents(const SDL_Event& evt)
{
}
