#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <Box2D\Box2D.h>
class Lighting
{
public:
	Lighting();
	~Lighting();

	void init(SDL_Renderer *render);

	//Places the light in the scene with a custom position intensity and color
	void DisplayLight(int intensity,int red,int green,int blue);

	void Surface(SDL_Texture* tex);
	//Displays shadows in the scene with gameObjects that are passed in.
	void CastShadows(SDL_Renderer * render, SDL_Rect* gameObjects);//Pass GameObjects

	void Raycast(SDL_Rect gameObjects);
	//Add this to game.update
	void Update();

	//And add this to game.render after rendering all other game objects
	void Render(SDL_Renderer *render,int x, int y, int w, int h);

	int r = 255;
	int g = 255;
	int b = 255;

private:
	SDL_Surface* light;
	SDL_Texture* lightTex;
	SDL_Surface* intense;
	SDL_Texture* intenseTex;
	
	SDL_Rect* rect = new SDL_Rect();

};

