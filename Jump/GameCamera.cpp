#include "GameCamera.h"

SDL_Rect GameCamera::position = SDL_Rect{-400, 0};
const SDL_Rect* GameCamera::GetPosition()
{
    return &GameCamera::position;
}

void GameCamera::SetPosition(int x, int y)
{
    GameCamera::position.x = x;
    GameCamera::position.y = y;
}

void GameCamera::SetX(int x)
{
    GameCamera::position.x = x;
}

void GameCamera::SetY(int y)
{
    GameCamera::position.y = y;
}
