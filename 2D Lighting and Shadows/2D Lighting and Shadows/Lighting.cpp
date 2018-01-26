#include "Lighting.h"
Lighting::Lighting()
{
}

Lighting::~Lighting()
{
}

void Lighting::init(SDL_Renderer * render, char c[100])
{
	light = SDL_LoadBMP(c);
	lightTex = SDL_CreateTextureFromSurface(render, light);

	centreX = rect->x + rect->w / 2;
	centreY = rect->y + rect->h / 2;

	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_ADD);
}

void Lighting::LightSettings(int intensity, int red, int green, int blue)
{
	r = red;
	g = green;
	b = blue;
	strength = intensity;
	SDL_SetTextureColorMod(lightTex, r, g, b);

}

void Lighting::Surface(SDL_Texture * tex)
{
	SDL_SetTextureColorMod(tex, r, g, b);
}

void Lighting::CircleLight(SDL_Renderer * render, SDL_Rect gameObjects[], int range)
{
	SDL_Rect fillRect;
	float lineDist = sqrt((centreX - endX)*(centreX - endX) +(centreY - endY)*(centreY - endY));

	SDL_SetRenderDrawColor(render, r, g, b, strength);
	centreX = rect->x + rect->w / 2;
	centreY = rect->y + rect->h / 2;

	for (angle = 0; angle <= 2 * 3.14; angle += 0.001)
	{
		endX = centreX + range * cos(angle);
		endY = centreY + range * sin(angle);
		for (int i = 0; i < 5; i++)
		{
			if (SDL_IntersectRectAndLine(&gameObjects[i], &centreX, &centreY, &endX, &endY))
			{
				centreX = rect->x + rect->w / 2;
				centreY = rect->y + rect->h / 2;
			}
		}
		SDL_RenderDrawLine(render, centreX, centreY, endX, endY);
	}
}
void Lighting::PointLight(SDL_Renderer * render, SDL_Rect gameObjects[], int range,double pointAngle)
{
	SDL_Rect fillRect;
	float lineDist = sqrt((centreX - endX)*(centreX - endX) + (centreY - endY)*(centreY - endY));

	SDL_SetRenderDrawColor(render, r, g, b, strength);
	centreX = rect->x + rect->w / 2;
	centreY = rect->y + rect->h / 2;

	for (angle = 0; angle <= pointAngle * 3.14; angle += 0.001)
	{
		endX = centreX + range * cos(angle);
		endY = centreY + range * sin(angle);
		for (int i = 0; i < 5; i++)
		{
			if (SDL_IntersectRectAndLine(&gameObjects[i], &centreX, &centreY, &endX, &endY))
			{
				centreX = rect->x + rect->w / 2;
				centreY = rect->y + rect->h / 2;
			}
		}
		SDL_RenderDrawLine(render, centreX, centreY, endX, endY);

	}
}
	

void Lighting::Update()
{
}

void Lighting::Render(SDL_Renderer * render,int x, int y, int w, int h)
{

	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;


	SDL_RenderCopy(render, lightTex, NULL, rect);
	
}
