#ifndef IdleState_H
#define IdleState_H
#include "IPlayerState.h"
#pragma once

class IdleState : public IPlayerState {
public:
	IdleState();
	IdleState(const char* texturePath);
	// Inherited via IPlayerState
	virtual void Update(double DT) override;
	virtual void HandleEvents(const SDL_Event& evt) override;
};



#endif // !IdleState_H