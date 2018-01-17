#pragma once
#include <SDL.h>
#include "Lighting.h"
//#include <SDL_image.h>


class Game {
private:
	bool isRunning;
	int index;
	SDL_Renderer *renderer;
	SDL_Window* window;
public:
	void Initialize();
	void HandleEvents();
	void Update();
	void Render();
	void CleanUp();
	Lighting* light = new Lighting();
	bool IsRunning();
};