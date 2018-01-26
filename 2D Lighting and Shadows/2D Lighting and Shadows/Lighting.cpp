#include "Lighting.h"
Lighting::Lighting()
{
}

Lighting::~Lighting()
{
}
//Initialize the texture and load it in as a BMP the origin is then set
void Lighting::init(SDL_Renderer * render, char c[100])
{
	light = SDL_LoadBMP(c);
	lightTex = SDL_CreateTextureFromSurface(render, light);

	centreX = rect->x + rect->w / 2;
	centreY = rect->y + rect->h / 2;

	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_ADD);
}
//This is used to control the lights Intensity value and the RGB values of everything in the scene
void Lighting::LightSettings(int intensity, int red, int green, int blue)
{
	r = red;
	g = green;
	b = blue;
	strength = intensity;
	SDL_SetTextureColorMod(lightTex, r, g, b);

}
//Colour in a texture to match a light in the scene
void Lighting::Surface(SDL_Texture * tex)
{
	SDL_SetTextureColorMod(tex, r, g, b);
}
//Create a circular light in the scene that will react when a gameObject is within range of the light.
void Lighting::CircleLight(SDL_Renderer * render, SDL_Rect gameObjects[], int range,int noOfObjects)
{
	SDL_Rect fillRect;
	float lineDist = sqrt((centreX - endX)*(centreX - endX) +(centreY - endY)*(centreY - endY));

	SDL_SetRenderDrawColor(render, r, g, b, strength);
	centreX = rect->x + rect->w / 2;
	centreY = rect->y + rect->h / 2;

	//Define the shape of the light as a circle
	for (angle = 0; angle <= 2 * 3.14; angle += 0.001)
	{
		endX = centreX + range * cos(angle);
		endY = centreY + range * sin(angle);
		//Check if object is witin range if so alter the light.
		for (int i = 0; i < noOfObjects; i++)
		{
			if (SDL_IntersectRectAndLine(&gameObjects[i], &centreX, &centreY, &endX, &endY))
			{
				centreX = rect->x + rect->w / 2;
				centreY = rect->y + rect->h / 2;
			}
		}
		//Draw the light
		SDL_RenderDrawLine(render, centreX, centreY, endX, endY);
	}
}
//Creates a point light which is similar to the circle light but is fed a point angle to define the size of the spotlight
void Lighting::PointLight(SDL_Renderer * render, SDL_Rect gameObjects[], int range,int noOfObjects,double pointAngle)
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
//Render the light source texture file with a custom X,Y,W,H
void Lighting::Render(SDL_Renderer * render,int x, int y, int w, int h)
{

	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;


	SDL_RenderCopy(render, lightTex, NULL, rect);
	
}
