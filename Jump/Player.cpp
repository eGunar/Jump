#include "Player.h"
#include "TextureManager.h"
Player::Player() {
	texture = TextureManager::LoadTexture("assets/player.png");
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 100;
	srcRect.y = 100;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = srcRect.x;
	destRect.y = srcRect.y; 
	
}
void Player::Update(double DT)
{
}

void Player::HandleEvents(SDL_Event evt)
{
}

void Player::Render()
{
	TextureManager::Draw(texture, srcRect, destRect, 0);
}

void Player::Clean()
{
}
