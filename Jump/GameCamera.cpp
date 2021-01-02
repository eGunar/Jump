#include "GameCamera.h"



/*
	Kamera som har en pos (0, 0);

	Player PlayerPos - CameraPos

	Hitbox (Position + offset)



*/
SDL_Rect GameCamera::position = SDL_Rect{ 0, 0, 800, 500 };
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

void GameCamera::Render()
{
	/*SDL_Point points[5] = {
		{Left(), Top()},
		{Right(), Top()},
		{Right(), Bottom()},
		{Left(), Bottom()},
		{Left(), Top()}
	};*/
	SDL_Point points[5] = {
		{offsetX, offsetY},
		{offsetX + GameCamera::position.w, offsetY},
		{offsetX + position.w, offsetY + position.h},
		{offsetX, position.h + offsetY},
		{offsetX, offsetY}
	};
	TextureManager::DrawLines(points, 5);
}

int GameCamera::Top()
{
	return GameCamera::position.y;
}

int GameCamera::Bottom()
{
	return GameCamera::position.y + GameCamera::position.h;
}

int GameCamera::Left()
{
	return GameCamera::position.x;
}

int GameCamera::Right()
{
	return GameCamera::position.x + GameCamera::position.w;
}



void GameCamera::MoveCamera(Player* player)
{
	if (ShouldMoveLeft(player))
		SetX(player->GetPosition()->x - GameCamera::offsetX);
	if (ShouldMoveRight(player))
		SetX(GameCamera::position.x + player->Right() - GameCamera::Right() - GameCamera::offsetX);
	if (ShouldMoveUp(player))
		SetY(GameCamera::position.y - GameCamera::offsetY);
	if (ShouldMoveDown(player))
		SetY(GameCamera::position.y + player->Bottom() - GameCamera::Bottom() - GameCamera::offsetY);

	//SetY(player->GetPosition()->y);
}

bool GameCamera::ShouldMoveLeft(Player* player)
{
	int cameraX = position.x;
	int playerX = player->GetPosition()->x;
	int relX = abs(cameraX - playerX);
	return (relX <= GameCamera::offsetX);
}

bool GameCamera::ShouldMoveUp(Player* player)
{
	int cameraY = position.y;
	int playerY = player->GetPosition()->y;
	int relY = abs(cameraY - playerY);
	return (relY <= GameCamera::offsetY);
}

bool GameCamera::ShouldMoveDown(Player* player)
{
	int cameraBottom = Bottom();
	int playerBottom = player->Bottom();
	int relY = playerBottom - cameraBottom;
	return (relY >= GameCamera::offsetY);
}

bool GameCamera::ShouldMoveRight(Player* player)
{
	int cameraRight = Right();
	int playerRight = player->Right();
	int relX = playerRight - cameraRight;
	return (relX >= GameCamera::offsetX);
}

int GameCamera::LocalTop()
{
	return GameCamera::Top() + GameCamera::offsetY;
}

int GameCamera::LocalBottom()
{
	return GameCamera::Bottom() + GameCamera::offsetY;
}

int GameCamera::LocalLeft()
{
	return GameCamera::Left() + GameCamera::offsetX;
}

int GameCamera::LocalRight()
{
	return GameCamera::Right() + GameCamera::offsetX;
}
