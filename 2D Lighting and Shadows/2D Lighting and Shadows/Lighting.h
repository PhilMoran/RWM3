#pragma once
#include <SDL.h>
class Lighting
{
public:
	Lighting();
	~Lighting();
	void init(SDL_Renderer *render);

	//Places the light in the scene with a custom position intensity and color
	void DisplayLight(int intensity, SDL_Color color, int x, int y);

	//Displays shadows in the scene with gameObjects that are passed in.
	void CastShadows();//Pass GameObjects

	//Add this to game.update
	void Update();

	//And add this to game.render after rendering all other game objects
	void Render();



private:

};

