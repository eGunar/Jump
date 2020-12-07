#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int frameTime = 1000 / FPS;
	const int windowWidth = 1280;
	const int windowHeight = 720;


	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double DT = 0;

	game = new Game();
	game->Init("Jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, false);


	while (game->running()) {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		DT = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;

		game->HandleEvents();
		game->Update(DT);
		game->Render();

		if (frameTime > DT) {
			SDL_Delay(frameTime - DT);
		}
	}

	game->Clean();

	return 0;
}