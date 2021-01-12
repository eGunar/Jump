#ifndef IdleState_H
#define IdleState_H
#include "RunningState.h"
#pragma once

class IdleState : public RunningState {
public:
	IdleState();
	IdleState(const char* texturePath, Player* p);
	// Inherited via IPlayerState
	virtual void Update(double DT) override;
	virtual void HandleEvents(const SDL_Event& evt) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};



#endif // !IdleState_H