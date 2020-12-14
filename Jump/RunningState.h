#ifndef RunningState_H
#define RunningState_H
#pragma once
#include "IPlayerState.h"

class RunningState : public IPlayerState {
public:
	RunningState();
	RunningState(const char* texturePath);
	// Inherited via IPlayerState
	virtual void Update(double DT) override;
	virtual void HandleEvents(const SDL_Event& evt) override;
protected:
	
};



#endif // !RunningState_H
