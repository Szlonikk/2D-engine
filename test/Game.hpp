#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>



class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	int cnt=0;

	static SDL_Renderer* renderer;
private:
	bool isRunning=false;
	SDL_Window* window;
};

#endif // !Game_Hpp
