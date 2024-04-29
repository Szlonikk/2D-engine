#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;

Map* map;


SDL_Renderer* Game::renderer=nullptr;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
		std::cout << "Subsystem initialized" << std::endl;
		if (window = SDL_CreateWindow(title, xpos, ypos, width, height, flags)) {
			std::cout << "Window created" << std::endl;
		}
		else {
			std::cout << "Window creation error" << std::endl;
		}

		if (renderer = SDL_CreateRenderer(window, -1, 0)) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		else {
			
			std::cout << "Renderer creation error" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/dog.png",0,0);
	map = new Map();
	


}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	player->update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->drawMap();
	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::running() {
	return isRunning;
}