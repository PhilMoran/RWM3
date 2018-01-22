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
void Lighting::CastShadows()
{

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
