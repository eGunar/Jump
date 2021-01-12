#ifndef IPlayerState_H
#define IPlayerState_H
#include "SDL.h"
#include "TextureManager.h"
#pragma once
class IPlayerState {
public:
	IPlayerState();
	IPlayerState(const char* texturePath);
	virtual void Update(double DT) = 0;
	virtual void Render(SDL_Rect pos);
	virtual void HandleEvents(const SDL_Event& evt) = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
protected:
	SDL_Texture* texture;

};


#endif
