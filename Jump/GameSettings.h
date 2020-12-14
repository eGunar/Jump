#ifndef GameSettings_H
#define GameSettings_H
#pragma once
#include "SDL_keycode.h"

class GameSettings {
public:
	const static SDL_KeyCode moveLeft = SDLK_a;
	const static SDL_KeyCode moveRight = SDLK_d;
	const static SDL_KeyCode moveUp = SDLK_w;
	const static SDL_KeyCode moveDown = SDLK_s;
	const static int gravity = 15;

};


#endif // !GameSettings_H
