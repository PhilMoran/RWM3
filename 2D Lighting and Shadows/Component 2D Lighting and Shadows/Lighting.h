#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Lighting
{
public:
	Lighting();
	~Lighting();

	void init(SDL_Renderer *render, char c[100]);

	//Places the light in the scene with a custom position intensity and color
	void LightSettings(int intensity,int red,int green,int blue);

	void Surface(SDL_Texture* tex);
	//Displays shadows in the scene with gameObjects that are passed in.
	void CircleLight(SDL_Renderer * render, SDL_Rect gameObjects[],int range);//Pass GameObjects
	void PointLight(SDL_Renderer * render, SDL_Rect gameObjects[], int range,double pointAngle);//Pass GameObjects


	//Add this to game.update
	void Update();

	//And add this to game.render after rendering all other game objects
	void Render(SDL_Renderer *render,int x, int y, int w, int h);

	int r = 255;
	int g = 255;
	int b = 255;
	int strength = 1;
	int centreX;
	int centreY;
	int endX;
	int endY;
	int i;
private:
	SDL_Surface* light;
	SDL_Texture* lightTex;
	SDL_Surface* intense;
	SDL_Texture* intenseTex;
	double angle;
	SDL_Rect* rect = new SDL_Rect();

};

