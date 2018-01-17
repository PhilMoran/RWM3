#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include "SDL_timer.h"
#include "Game.h"
#include "Main.h"


using namespace std;

int main(int argc, char* argv[]) 
{
	
	Game* game = new Game;

	game->Initialize();
	cout << "Game Initialized" << endl;

	while (game->IsRunning())
	{
		game->Update();
	}

	cout << "Clean Up" << endl;
	game->CleanUp();
	SDL_Quit();
	
	return 0;
}