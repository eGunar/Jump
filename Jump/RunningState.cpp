#include "RunningState.h"
#include "Player.h"
RunningState::RunningState()
{
	currentFlip = SDL_FLIP_NONE;
}

RunningState::RunningState(const char* texturePath, Player* p) : IPlayerState(texturePath) {
	currentFlip = SDL_FLIP_NONE;
	player = p;
	movementController = player->GetMovementController();
}

void RunningState::Update(double DT)
{
	if (!movementController->IsMoving())
		player->SetState(PlayerStates::idle);
}

void RunningState::HandleEvents(const SDL_Event& evt)
{
	RunningState::HandleMovement(evt);
}

void RunningState::Render(SDL_Rect pos)
{
	TextureManager::Draw(texture, pos, 0, currentFlip);
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
		case (GameSettings::moveRight):
			currentFlip = SDL_FLIP_HORIZONTAL;
			movementController->StartMovingRight();
			break;
		case (GameSettings::moveLeft):
			currentFlip = SDL_FLIP_NONE;
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
		case(GameSettings::moveRight):
			movementController->StopMovingRight();
			break;
		case(GameSettings::moveLeft):
			movementController->StopMovingLeft();
			break;
		}
	}
}