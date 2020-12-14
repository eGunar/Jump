#include "RunningState.h"

RunningState::RunningState()
{
}

RunningState::RunningState(const char* texturePath) : IPlayerState(texturePath) {

}

void RunningState::Update(double DT)
{
}

void RunningState::HandleEvents(const SDL_Event& evt)
{
}
