#ifndef GameCamera_H
#define GameCamera_H
#include "SDL.h"
#pragma once

class GameCamera {
public:
	static const SDL_Rect* GetPosition();
	static void SetPosition(int x, int y);
	static void SetX(int x);
	static void SetY(int y);
private:
	GameCamera() {}
	static SDL_Rect position;
};

#endif // !Camera_H

