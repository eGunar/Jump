#pragma once
#include "SDL.h"

class TextureManager
{

public:
	static SDL_Texture* LoadTexture(const char* fileName);

	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle);

	static void Draw(SDL_Texture* texture, SDL_Rect dest, double angle);

	static void Draw(SDL_Rect rect);
};