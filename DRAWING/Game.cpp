#include "Game.h"
#include "TextureManager.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen){
	int flags = 0;

	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	//init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){

		std::cout << "SDL init success!\n";
		//if succeed, create the window
		m_pWindow = SDL_CreateWindow(title , xpos, ypos, height, width, flags);

		if(m_pWindow != 0){
			std::cout << "Window creation success!\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if(m_pRenderer != 0){
				std::cout << "Renderer creation success!\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
			}
			else{
				std::cout << "Renderer init fail!\n";
				return false;
			}
		}
		else{
			std::cout << "Window init fail!\n";
			return false;
		}
	}
	else{
		std::cout << "SDL init fail!\n";
		return false; //could not init SDL
	}

	//SDL_Surface * pTempSurface = SDL_LoadBMP("assets/animate.bmp");
	//SDL_Surface * pTempSurface = IMG_Load("assets/animate-alpha.png");

	//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	//SDL_FreeSurface(pTempSurface);

	//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	TextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

	std::cout << "Init success!\n";
	m_bRunning = true;//start main loop
	return true;
}
void Game::render(){

	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);

	//SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
			//0, 0, SDL_FLIP_HORIZONTAL);
	
	TextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	TextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame,  m_pRenderer);

	TextureManager::Instance()->drawFrame("animate", 200, 200, 128, 82, 1, m_currentFrame,  m_pRenderer);

	//draw to the screen
	SDL_RenderPresent(m_pRenderer);
}
void Game::update(){
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}
void Game::handleEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
		}
	}
}
void Game::clean(){
	std::cout << "Cleaning game..\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
