#include "Game.h"
#include <iostream>

int main(int argc, char* args[]){

	if(Game::Instance()->init("Game Objects", 100, 100, 640, 480, false)){

		while(Game::Instance()->running()){
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			SDL_Delay(10); //temp frime cap solution
		}
	}
	else{
		std::cout << "Game Init failure: " << SDL_GetError() << std::endl;
		return -1;
	}

	Game::Instance()->clean();
	return 0;
}
