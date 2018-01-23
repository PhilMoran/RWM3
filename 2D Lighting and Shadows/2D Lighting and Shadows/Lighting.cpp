#include "Lighting.h"
Lighting::Lighting()
{
}

Lighting::~Lighting()
{
}

void Lighting::init(SDL_Renderer * render)
{
	light = SDL_LoadBMP("images/lighting.bmp");
	intense = SDL_LoadBMP("images/intense.bmp");
	lightTex = SDL_CreateTextureFromSurface(render, light);
	intenseTex = SDL_CreateTextureFromSurface(render, intense);
	//SDL_BlendMode(SDL_BLENDMODE_BLEND);
}

void Lighting::DisplayLight(int intensity, int red, int green, int blue)
{
	SDL_SetTextureBlendMode(lightTex, SDL_BLENDMODE_ADD);
	SDL_SetTextureColorMod(lightTex, r,g,b);
	r = red;
	g = green;
	b = blue;
	
}
void Lighting::Surface(SDL_Texture * tex)
{
	SDL_SetTextureColorMod(tex, r, g, b);
}
void Lighting::CastShadows(SDL_Renderer * render, SDL_Rect* gameObjects)
{
	int centreX = rect->x + rect->w/2;
	int centreY = rect->y + rect->h/2;
	
	for (double angle = 0; angle <= 2 * 3.14; angle += 0.1)
	{
		SDL_SetRenderDrawColor(render, 255, 255,255,255 );
		SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
		int endX = centreX + 1000 * cos(angle);
		int endY = centreY + 1000 * sin(angle);
		SDL_RenderDrawLine(render, centreX, centreY, endX, endY);

		if (SDL_IntersectRectAndLine(gameObjects, &centreX, &centreY, &endX, &endY))
		{
			centreX = rect->x + rect->w / 2;
			centreY = rect->y + rect->h / 2;
			//endX = centreX + 1000 * cos(angle);
			endY = gameObjects->y;
		}
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
	SDL_RenderCopy(render, intenseTex, NULL, NULL);
}
