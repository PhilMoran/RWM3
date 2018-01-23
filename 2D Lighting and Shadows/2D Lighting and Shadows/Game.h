#pragma once
#include <SDL.h>
#include "Lighting.h"
#include <string>
#include <Box2D\Box2D.h>
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
	int newR = 255;
	Lighting* light = new Lighting();
	bool IsRunning();
	SDL_Surface* background;
	SDL_Texture* backgroundTex;
	SDL_Surface* gameObject;
	SDL_Texture* gameObjectTex;
	SDL_Rect gameObjectRect;


};