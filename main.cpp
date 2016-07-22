#include <SDL2/SDL.h>

SDL_Window * g_pWindow = 0;
SDL_Renderer * g_pRenderer = 0;

int main(int argc, char* args[]){

	//init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		//if succeed, create the window
		g_pWindow = SDL_CreateWindow("Basic SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				640, 480, SDL_WINDOW_SHOWN);

		if(g_pWindow != 0){
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else{
		return 1; //could not init SDL
	}

	//All success, draw the window
	//set window color (RGBA)
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	//clear the window to black
	SDL_RenderClear(g_pRenderer);

	//show the window
	SDL_RenderPresent(g_pRenderer);

	//set a delay before quitting
	SDL_Delay(5000);

	//clean up SDL
	SDL_Quit();

	return 0;

}
