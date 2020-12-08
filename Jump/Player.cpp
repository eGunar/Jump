#include "Player.h"

Player::Player() {
	texture = TextureManager::LoadTexture("assets/player.png");
	position.h = 64;
	position.w = 64;
	position.x = 100;
	position.y = 100;

	velocity.x = 0;
	velocity.y = 0;

}
Player::Player(int x, int y, int speed) {
	texture = TextureManager::LoadTexture("assets/player.png");
	position.h = 64;
	position.w = 64;
	position.x = x;
	position.y = y;

	velocity.x = 0;
	velocity.y = 0;
}
void Player::Update(double DT)
{
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
			velocity.y = Accelerate(Direction::Down);
			break;
		case (GameSettings::moveUp):
			velocity.y = Accelerate(Direction::UP);
			break;
		case (GameSettings::moveRight):
			velocity.x = Accelerate(Direction::Right);
			break;
		case (GameSettings::moveLeft):
			velocity.x = Accelerate(Direction::Left);
			break;
		}
		break;
	case (SDL_KEYUP):
		switch (evt.key.keysym.sym) {
		case(GameSettings::moveDown):
		case(GameSettings::moveUp):
			velocity.x = Decelerate(Direction::Y);
			break;
		case(GameSettings::moveRight):
		case(GameSettings::moveLeft):
			velocity.x = Decelerate(Direction::X);
			break;
		}
	}
}

float Player::Decelerate(Direction direction) {
	if (direction == Direction::X) {
		return 0;
	}
	else if (direction == Direction::Y) {
		return 0;
	}
}

float Player::Accelerate(Direction direction) {
	if (direction == Direction::UP) {
		float max = maxSpeed * -1;
		if (velocity.y >= max) {
			return max;
		}
		return velocity.y - accelerationSpeed;
	}
	else if (direction == Direction::Down) {
		float max = maxSpeed;
		if (velocity.y <= max) {
			return max;
		}
		return velocity.y + accelerationSpeed;
	}
	else if (direction == Direction::Left) {
		float max = maxSpeed * -1;
		if (velocity.x <= max) {
			return max;
		}
		return velocity.x - accelerationSpeed;
	}
	else if (direction == Direction::Right) {
		float max = maxSpeed;
		if (velocity.x >= max) {
			return max;
		}
		return velocity.x + accelerationSpeed;
	}
}

void Player::Render()
{
	TextureManager::Draw(texture, position, 0);
}

void Player::Clean()
{
}
