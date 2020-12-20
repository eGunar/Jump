#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
World* Game::world = nullptr;
Game::Game()
{
	isRunning = false;
	window = nullptr;
}

Game::~Game()
{
}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized...\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 66, 135, 245, 100);
			std::cout << "Renderer created\n";
		}
		Game::world = new World();
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	Game::world->HandleEvents(event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::Update(double dt)
{
	Game::world->Update(dt);
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 66, 135, 245, 100);
	SDL_RenderClear(renderer);

	Game::world->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	delete Game::world;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game quit..\n";
}
