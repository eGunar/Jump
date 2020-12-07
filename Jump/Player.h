#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Player();
	Player(int x, int y, int speed);
	// Inherited via Entity
	virtual void Update(double DT) override;
	virtual void HandleEvents(SDL_Event evt) override;
	virtual void Render() override;
	virtual void Clean() override;

private:

	SDL_Texture* texture;
};