#include "Player.h"
Player::Player() : Entity(true, true, true) {
	position.h = 64;
	position.w = 64;
	position.x = 576;
	position.y = 536;

	velocity.x = 0;
	velocity.y = 0;

	stateMachine = PlayerStateMachine(this);
}
Player::Player(int x, int y, int speed) {
	texture = TextureManager::LoadTexture("assets/player.png");
	position.h = 64;
	position.w = 64;
	position.x = x;
	position.y = y;

	velocity.x = 0;
	velocity.y = 0;
	stateMachine = PlayerStateMachine(this);
}

void Player::Update(double DT)
{
	GetCurrentState()->Update(DT);
	if (!movementController.GetMovingRight() && !movementController.GetMovingLeft())
		velocity.x = Decelerate(Direction::X);

	if (movementController.GetMovingDown()) {
		velocity.y = Accelerate(Direction::Down);
	}
	if (movementController.GetMovingUp())
		velocity.y = Accelerate(Direction::UP);
	if (movementController.GetMovingLeft()) {
		velocity.x = Accelerate(Direction::Left);
	}
	if (movementController.GetMovingRight()) {
		velocity.x = Accelerate(Direction::Right);
	}

	GameCamera::MoveCamera(this);

	Entity::Update(DT);
}

void Player::HandleEvents(const SDL_Event& evt)
{
	GetCurrentState()->HandleEvents(evt);
	switch (evt.type) {
	case(SDL_KEYDOWN):
		switch (evt.key.keysym.sym) {
		case (GameSettings::moveLeft):
		case (GameSettings::moveRight):
			if (IsOnGround())
				stateMachine.SetState(PlayerStates::run);
			break;
		case (GameSettings::moveUp):
		case (SDLK_SPACE):
			if (IsOnGround())
				SetState(PlayerStates::jump);
			break;
		}

		break;
	}
}

bool Player::IsOnGround() {
	return physics->IsStandingOnBlock(this);
}

void Player::SetPreviousState()
{
	stateMachine.SetPreviousState();
}

void Player::HandleCollision(std::vector<Entity*> collidingEntities)
{
	for (Entity* entity : collidingEntities) {
		if (Bottom() > entity->Top()) {
			//if (Bottom() > entity->Top() && (Left() >= entity->Left() || Right() <= entity->Right())) {
				//position = previousPosition;
			position.y = entity->Top() - position.h;
			velocity.y = 0;
			break;
		}

	}
}

int Player::Decelerate(Direction direction) {
	const int deccSpeed = GameSettings::accelerationSpeed * 2;
	if (direction == Direction::X) {
		int currentVelocity = velocity.x;
		if (currentVelocity == 0)
			return 0;

		if (currentVelocity > 0) {
			// Här innebär det att gubben går höger, decelerera ner mot 0
			if (currentVelocity - deccSpeed < 0)
				return 0;
			return currentVelocity - deccSpeed;
		}
		else {
			// Här innebär det att gubben går vänster, decelerera upp mot 0
			if (currentVelocity + deccSpeed > 0)
				return 0;
			return currentVelocity + deccSpeed;
		}
	}
	else if (direction == Direction::Y) {
		int currentVelocity = velocity.y;
		if (currentVelocity == 0)
			return 0;

		if (currentVelocity > 0) {
			if (currentVelocity - deccSpeed < 0)
				return 0;
			return currentVelocity - deccSpeed;
		}
		else {
			if (currentVelocity + deccSpeed > 0)
				return 0;
			return currentVelocity + deccSpeed;
		}
	}
	return 0;
}

IPlayerState* Player::GetCurrentState()
{
	return stateMachine.GetCurrentState();
}

int Player::Accelerate(Direction direction) {
	if (direction == Direction::UP) {
		float max = GameSettings::maxSpeed * -1;
		if (velocity.y <= max) {
			return max;
		}
		return velocity.y - GameSettings::accelerationSpeed;
	}
	else if (direction == Direction::Down) {
		float max = GameSettings::maxSpeed;
		if (velocity.y >= max) {
			return max;
		}
		return velocity.y + GameSettings::accelerationSpeed;
	}
	else if (direction == Direction::Left) {
		float max = GameSettings::maxSpeed * -1;
		if (velocity.x <= max) {
			return max;
		}
		return velocity.x - GameSettings::accelerationSpeed;
	}
	else if (direction == Direction::Right) {
		float max = GameSettings::maxSpeed;
		if (velocity.x >= max) {
			return max;
		}
		return velocity.x + GameSettings::accelerationSpeed;
	}
	return 0;
}

void Player::Render()
{
	//Entity::Render();
	GetCurrentState()->Render(position);
}

void Player::Clean()
{
	Entity::Clean();
}

void Player::CollisionsStopped()
{
}

MovementController* Player::GetMovementController()
{
	return &movementController;
}

void Player::SetState(PlayerStates state)
{
	stateMachine.SetState(state);
}
