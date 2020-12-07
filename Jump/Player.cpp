#include "Player.h"
#include "TextureManager.h"
Player::Player() {
	texture = TextureManager::LoadTexture("assets/player.png");
	position.h = 64;
	position.w = 64;
	position.x = 100;
	position.y = 100;

	velocity.x = 100;
	velocity.y = 0; 
	
}
Player::Player(int x, int y, int speed) {
	texture = TextureManager::LoadTexture("assets/player.png");
	position.h = 64;
	position.w = 64;
	position.x = x;
	position.y = y;

	velocity.x = speed;
	velocity.y = 0;
}
void Player::Update(double DT)
{
	Entity::Update(DT);
}

void Player::HandleEvents(SDL_Event evt)
{
}

void Player::Render()
{
	TextureManager::Draw(texture, position, 0);
}

void Player::Clean()
{
}
