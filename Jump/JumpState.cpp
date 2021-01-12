#include "JumpState.h"

JumpState::JumpState()
{
}

JumpState::JumpState(const char* texturePath, Player* p) : RunningState(texturePath, p)
{
}

void JumpState::OnEnter()
{
	player->SetVelocityY(GameSettings::JumpSpeed);
	hasDoubleJumped = false;
}

void JumpState::OnExit()
{
}

void JumpState::Update(double DT)
{
	if (player->IsOnGround()) {
		player->SetPreviousState();
	}
}

void JumpState::HandleEvents(const SDL_Event& evt) {
	RunningState::HandleMovement(evt);
	JumpState::HandleJump(evt);
}

void JumpState::HandleJump(const SDL_Event& evt)
{
	if (hasDoubleJumped)
		return;

	switch (evt.type) {
	case (SDL_KEYDOWN):
		switch (evt.key.keysym.sym) {
		case (GameSettings::moveUp):
		case (SDLK_SPACE):
			player->SetVelocityY(GameSettings::JumpSpeed / 2);
			hasDoubleJumped = true;
			break;
		}
	}
}
