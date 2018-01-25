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
	light->init(renderer,"images/lighting.bmp");
	lightNew->init(renderer, "images/lighting.bmp");

	gameObjectRect.x = 200;
	gameObjectRect.y = 400;
	gameObjectRect.w = 100;
	gameObjectRect.h = 100;
	gameObjects[0] = gameObjectRect;

	gameObjectRect1.x = 200;
	gameObjectRect1.y = 400;
	gameObjectRect1.w = 100;
	gameObjectRect1.h = 100;
	gameObjects[1] = gameObjectRect1;

	gameObjectRect2.x = 200;
	gameObjectRect2.y = 400;
	gameObjectRect2.w = 100;
	gameObjectRect2.h = 100;
	gameObjects[2] = gameObjectRect2;


	gameObjectRect3.x = 200;
	gameObjectRect3.y = 400;
	gameObjectRect3.w = 100;
	gameObjectRect3.h = 100;
	gameObjects[3] = gameObjectRect3;

	
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
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTex, 0, 0);

	light->CircleLight(renderer, &gameObjects[index],400);
	light->LightSettings(25, 255, 255, 255);
	light->Surface(backgroundTex);
	light->Render(renderer, 200, 30, 100, 100);

	lightNew->PointLight(renderer, &gameObjects[index], 500,0.2);
	lightNew->LightSettings(25, 255, 255, 255);
	lightNew->Render(renderer, 200, 30, 100, 100);

	for (int i = 0; i < 5; i++)
	{
		SDL_RenderCopy(renderer, gameObjectTex, 0, &gameObjects[i]);
	}
	// clear the screen
	gameObjects[0].x++;
	gameObjects[1].y--;
	
	gameObjects[2].y++;
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
	Render();
}


bool Game::IsRunning()
{
	return isRunning;
}
