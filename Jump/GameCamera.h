#ifndef GameCamera_H
#define GameCamera_H
#include "SDL.h"
#include "TextureManager.h"
#include "GameSettings.h"
#include "Player.h"
#include <math.h>
#pragma once
class Player;
class GameCamera {
public:
	static const SDL_Rect* GetPosition();
	static void SetPosition(int x, int y);
	static void SetX(int x);
	static void SetY(int y);
	static void Render();
	static int Top();
	static int Bottom();
	static int Left();
	static int Right();
	static void MoveCamera(Player* player);
private:
	static bool ShouldMoveRight(Player* player);
	static bool ShouldMoveLeft(Player* player);
	static bool ShouldMoveUp(Player* player);
	static bool ShouldMoveDown(Player* player);
	static int LocalTop();
	static int LocalBottom();
	static int LocalLeft();
	static int LocalRight();
	GameCamera() {}
	static SDL_Rect position;
	const static int offsetX = 220;
	const static int offsetY = 100;
};

#endif // !Camera_H

