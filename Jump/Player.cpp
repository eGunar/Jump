#include "Player.h"

Player::Player() : Entity(true, true, true) {
	position.h = 64;
	position.w = 64;
	position.x = 100;
	position.y = 100;

	velocity.x = 0;
	velocity.y = 0;
	InitStates();
}
Player::Player(int x, int y, int speed) {
	texture = TextureManager::LoadTexture("assets/player.png");
	position.h = 64;
	position.w = 64;
	position.x = x;
	position.y = y;

	velocity.x = 0;
	velocity.y = 0;
	InitStates();
}
void Player::InitStates() {
	idleState = IdleState("assets/player.png");
	runningState = RunningState("assets/player_running.png");

}
void Player::Update(double DT)
{
	GetCurrentState()->Update(DT);
	if (!movementController.GetMovingRight() && !movementController.GetMovingLeft())
		velocity.x = Decelerate(Direction::X);

	if (movementController.GetMovingDown())
		velocity.y = Accelerate(Direction::Down);
	if (movementController.GetMovingUp())
		velocity.y = Accelerate(Direction::UP);
	if (movementController.GetMovingLeft())
		velocity.x = Accelerate(Direction::Left);
	if (movementController.GetMovingRight())
		velocity.x = Accelerate(Direction::Right);

	Entity::Update(DT);
}

void Player::HandleEvents(const SDL_Event& evt)
{
	// TODO: Ändra om detta, insåg att endast någon form av flagga lär sättas vid olika events. 
	// Själva förflyttningen bör ske i update. 

	switch (evt.type) {
	case (SDL_KEYDOWN):
		switch (evt.key.keysym.sym) {
		case (GameSettings::moveDown):
			movementController.StartMovingDown();
			break;
		case (GameSettings::moveUp):
			movementController.StartMovingUp();
			break;
		case (GameSettings::moveRight):
			movementController.StartMovingRight();
			break;
		case (GameSettings::moveLeft):
			movementController.StartMovingLeft();
			break;
		}
		break;
	case (SDL_KEYUP):
		switch (evt.key.keysym.sym) {
		case(GameSettings::moveDown):
			movementController.StopMovingDown();
			break;
		case(GameSettings::moveUp):
			movementController.StopMovingUp();
			break;
		case(GameSettings::moveRight):
			movementController.StopMovingRight();
			break;
		case(GameSettings::moveLeft):
			movementController.StopMovingLeft();
			break;
		}
	}
}

void Player::HandleCollision(std::vector<Entity*> collidingEntities)
{
	for (Entity* entity : collidingEntities){
		if (Bottom() > entity->Top() && (Left() >= entity->Left() || Right() <= entity->Right())) {
			position = previousPosition;
			velocity.y = 0;
			//isOnGround = true;
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
	if (velocity.x != 0 || velocity.y != 0)
		return &runningState;

	return &idleState;
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

bool Player::IsOnGround()
{
	return isOnGround;
}

void Player::CollisionsStopped()
{
	//isOnGround = false;
}
