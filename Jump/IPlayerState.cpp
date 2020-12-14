#include "IPlayerState.h"

IPlayerState::IPlayerState()
{
}

IPlayerState::IPlayerState(const char* texturePath)
{
	texture = TextureManager::LoadTexture(texturePath);
}

void IPlayerState::Render(SDL_Rect pos)
{
	TextureManager::Draw(texture, pos, 0);
}
