#include "Game.h"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]){

	if(Game::Instance()->init("Game Objects", 100, 100, 640, 480, false)){

		Uint32 frameStart, frameTime;

		while(Game::Instance()->running()){

			frameStart = SDL_GetTicks();

			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			//!!!!
			//Fixed Frames Per Second
			//Good only for basic physics and small 2D games
			if(frameTime < DELAY_TIME){
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else{
		std::cout << "Game Init failure: " << SDL_GetError() << std::endl;
		return -1;
	}

	Game::Instance()->clean();
	return 0;
}
