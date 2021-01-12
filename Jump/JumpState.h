#ifndef JumpState_H
#define JumpState_H
#include "RunningState.h"
#pragma once

class JumpState : public RunningState {
public:
	JumpState();
	JumpState(const char* texturePath, Player* p);

	virtual void OnEnter() override;
	virtual void OnExit() override;

protected:
	void Update(double DT) override;
	virtual void HandleEvents(const SDL_Event& evt) override;
	virtual void HandleJump(const SDL_Event& evt) override;
private:
	bool hasDoubleJumped = false;
};




#endif // !JumpState_H