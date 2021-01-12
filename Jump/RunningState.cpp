#include "RunningState.h"
#include "Player.h"
RunningState::RunningState()
{
}

RunningState::RunningState(const char* texturePath, Player* p) : IPlayerState(texturePath) {
	player = p;
	movementController = player->GetMovementController();
}

void RunningState::Update(double DT)
{
}

void RunningState::HandleEvents(const SDL_Event& evt)
{
	RunningState::HandleMovement(evt);
	RunningState::HandleJump(evt);
}

void RunningState::OnEnter()
{
}

void RunningState::OnExit()
{
}

void RunningState::HandleMovement(const SDL_Event& evt)
{
	switch (evt.type) {
	case (SDL_KEYDOWN):
		switch (evt.key.keysym.sym) {
		case (GameSettings::moveDown):
			movementController->StartMovingDown();
			break;
		case (GameSettings::moveRight):
			movementController->StartMovingRight();
			break;
		case (GameSettings::moveLeft):
			movementController->StartMovingLeft();
			break;
		case (SDLK_RIGHT):
			GameCamera::SetX(GameCamera::GetPosition()->x + 100);
			break;
		case (SDLK_LEFT):
			GameCamera::SetX(GameCamera::GetPosition()->x - 100);
			break;
		}
		break;
	case (SDL_KEYUP):
		switch (evt.key.keysym.sym) {
		case(GameSettings::moveDown):
			movementController->StopMovingDown();
			break;
		case(GameSettings::moveUp):
			movementController->StopMovingUp();
			break;
		case(GameSettings::moveRight):
			movementController->StopMovingRight();
			break;
		case(GameSettings::moveLeft):
			movementController->StopMovingLeft();
			break;
		}
	}
}

void RunningState::HandleJump(const SDL_Event& evt)
{
	switch (evt.type) {
	case (SDL_KEYDOWN):
		switch (evt.key.keysym.sym) {
		case (GameSettings::moveUp):
		case (SDLK_SPACE):
			player->SetState(PlayerStates::jump);
			break;
		}
	}
}
