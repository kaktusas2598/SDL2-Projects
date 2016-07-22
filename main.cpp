#include <SDL2/SDL.h>

SDL_Window * g_pWindow = 0;
SDL_Renderer * g_pRenderer = 0;
bool g_pRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags){

	//init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		//if succeed, create the window
		g_pWindow = SDL_CreateWindow(title , xpos, ypos, height, width, flags);

		if(g_pWindow != 0){
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else{
		return false; //could not init SDL
	}
	return true;
}
void render(){

	//set window color (RGBA)
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	//clear the window to black
	SDL_RenderClear(g_pRenderer);

	//show the window
	SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[]){

	if(init("SDL2 Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)){
		g_pRunning = true;
	}
	else{
		return 1;//could not init
	}

	while(g_pRunning){
		render();
	}
	
	//clean up SDL
	SDL_Quit();

	return 0;
}
