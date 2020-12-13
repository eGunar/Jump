#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "World.h"


class Game {

public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update(double dt);
	void Render();
	void Clean();

	bool running() { return isRunning; }

	static World* world;
	static SDL_Renderer* renderer;
private:
	bool isRunning;
	SDL_Window* window;
};



