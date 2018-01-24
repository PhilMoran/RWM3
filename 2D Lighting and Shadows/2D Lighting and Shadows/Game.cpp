#include "Game.h"

using namespace std;
void Game::Initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	background = SDL_LoadBMP("images/Background.bmp");
	gameObject = SDL_LoadBMP("images/box.bmp");
	backgroundTex = SDL_CreateTextureFromSurface(renderer, background);
	gameObjectTex = SDL_CreateTextureFromSurface(renderer, gameObject);
	isRunning = true;
	light->init(renderer);

	gameObjectRect.x = 200;
	gameObjectRect.y = 400;
	gameObjectRect.w = 100;
	gameObjectRect.h = 100;


}

void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
		
	}

}

void Game::Render()
{
	// clear the screen
	gameObjectRect.x++;
	gameObjectRect.y--;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTex, 0, 0);
	SDL_RenderCopy(renderer, gameObjectTex, 0, &gameObjectRect);
	light->LightSettings(3,255,255,255);
	light->Surface(backgroundTex);

	light->Render(renderer,200,30,100,100);
	
	light->CastShadows(renderer, &gameObjectRect);
	// flip the backbuffer
	// this means that everything that we prepared behind the screens is actually shown
	SDL_RenderPresent(renderer);

}

void Game::Update()
{
	HandleEvents();
	Render();
}

void Game::CleanUp()
{
}


bool Game::IsRunning()
{
	return isRunning;
}
