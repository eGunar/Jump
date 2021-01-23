#ifndef RunningState_H
#define RunningState_H
#include "IPlayerState.h"
#include "GameSettings.h"
#include "MovementController.h"
#include "GameCamera.h"
#pragma once

class Player;
class RunningState : public IPlayerState {
public:
	RunningState();
	RunningState(const char* texturePath, Player* p);
	// Inherited via IPlayerState
	virtual void Update(double DT) override;
	virtual void HandleEvents(const SDL_Event& evt) override;
	virtual void Render(SDL_Rect pos) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
protected:
	Player* player;
	virtual void HandleMovement(const SDL_Event& evt);
private:
	MovementController* movementController;
	SDL_RendererFlip currentFlip;
};



#endif // !RunningState_H
