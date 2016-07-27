#include "Game.h"
#include "TextureManager.h"
#include <iostream>

Game* Game::s_pInstance = 0;

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

	TextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

	m_gameObjects.push_back(new Player(new LoaderParams(0, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(0, 0, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(0, 300, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(450, 450, 128, 82, "animate")));

	std::cout << "Init success!\n";
	m_bRunning = true;//start main loop
	return true;
}
void Game::render(){

	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);

	//m_go.draw(m_pRenderer);
	//m_player.draw(m_pRenderer);
	for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
		m_gameObjects[i]->draw();
	}
	
	//draw to the screen
	SDL_RenderPresent(m_pRenderer);
}
void Game::update(){
	//m_currentFrame = int((SDL_GetTicks() / 100) % 6);
	//m_go.update();
	//m_player.update();
	for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
		m_gameObjects[i]->update();
	}
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
