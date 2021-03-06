#ifndef TextureManager_H
#define TextureManager_H

#pragma once
#include "SDL.h"

class TextureManager
{

public:
	static SDL_Texture* LoadTexture(const char* fileName);
	
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle);

	static void Draw(SDL_Texture* texture, SDL_Rect dest, double angle, SDL_RendererFlip flip);

	static void Draw(SDL_Rect rect);

	static void DrawLines(const SDL_Point* points, int count);
};
#endif