#include "texturemanager.h"
#include "game.h"
#include "SDL_image.h"
#include "SDL.h"



SDL_Texture* TextureManager::LoadTexture(const char* filePath)
{
	SDL_Surface* tempSurface = IMG_Load(filePath);
	if (tempSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", filePath, IMG_GetError());
		return NULL;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	if (tex == NULL) {
		printf("Unable to create texture %s! SDL_Error Error: %s\n", filePath, SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, double angle)
{
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	int success = SDL_RenderCopyEx(Game::renderer, texture, &src, &dest, angle, NULL, flip);
	if (success == -1) {
		printf("Unable to draw! SDL_Error Error: %s\n", SDL_GetError());
	}
}
void TextureManager::Draw(SDL_Texture* texture, SDL_Rect dest, double angle)
{
	SDL_Rect pos;
	const SDL_Rect* camPos = GameCamera::GetPosition();
	pos.x = dest.x - camPos->x;
	pos.y = dest.y - camPos->y;
	pos.w = dest.w;
	pos.h = dest.h;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	int success = SDL_RenderCopyEx(Game::renderer, texture, NULL, &pos, angle, NULL, flip);
	if (success == -1) {
		printf("Unable to draw! SDL_Error Error: %s\n", SDL_GetError());
	}
}

void TextureManager::Draw(SDL_Rect src)
{
	int success = SDL_RenderFillRect(Game::renderer, &src);
	if (success == -1) {
		printf("Unable to draw! SDL_Error Error: %s\n", SDL_GetError());
	}
}
