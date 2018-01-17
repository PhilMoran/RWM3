#include "Lighting.h"
Lighting::Lighting()
{
}

Lighting::~Lighting()
{
}

void Lighting::init(SDL_Renderer * render)
{
	light = IMG_Load("light.png");
	lightTexture = SDL_CreateTextureFromSurface(render, light);
}

void Lighting::DisplayLight(int intensity, SDL_Color color, int x, int y)
{
	
}

void Lighting::CastShadows()
{
}

void Lighting::Update()
{
}

void Lighting::Render(SDL_Renderer * render)
{
	SDL_RenderCopy(render, lightTexture, NULL, NULL);
}
