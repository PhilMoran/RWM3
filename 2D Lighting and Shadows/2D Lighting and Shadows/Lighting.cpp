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

	
	centreX = rect->x + rect->w / 2;
	centreY = rect->y + rect->h / 2;

	
	//SDL_BlendMode(SDL_BLENDMODE_BLEND);
}

void Lighting::LightSettings(int intensity, int red, int green, int blue)
{
	
	r = red;
	g = green;
	b = blue;
	strength = intensity;
	//SDL_SetTextureBlendMode(lightTex, SDL_BLENDMODE_ADD);
	SDL_SetTextureColorMod(lightTex, r, g, b);

}
void Lighting::Surface(SDL_Texture * tex)
{
	SDL_SetTextureColorMod(tex, r, g, b);
}
void Lighting::CastShadows(SDL_Renderer * render, SDL_Rect* gameObjects)
{
	SDL_Rect fillRect;
	float lineDist = sqrt((centreX - endX)*(centreX - endX) +(centreY - endY)*(centreY - endY));
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(render, r, g, b, strength);

	for (angle = 0; angle <= 2 * 3.14; angle += 0.0001)
	{
		endX = centreX + 1000 * cos(angle);
		endY = centreY + 1000 * sin(angle);
		
		if (SDL_IntersectRectAndLine(gameObjects, &centreX, &centreY, &endX, &endY))
		{
			centreX = rect->x + rect->w /2;
			centreY = rect->y + rect->h / 2;
			
		}

		SDL_RenderDrawLine(render, centreX, centreY, endX, endY);
	}
		std::cout << "Line " << lineDist << std::endl;
		std::cout << "Y: " << endY + gameObjects->y << std::endl;
		
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
