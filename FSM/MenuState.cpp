#include "MenuState.h"
#include "MenuButton.h"
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update(){

	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->update();
	}
}
void MenuState::render(){

	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->draw();
	}
}
bool MenuState::onEnter(){

	if(!TextureManager::Instance()->load("assets/button.png", "play-button",
				Game::Instance()->getRenderer())){
		return false;
	}
	if(!TextureManager::Instance()->load("assets/exit.png", "exit-button",
				Game::Instance()->getRenderer())){
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100,
				400, 100, "play-button"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300,
				400, 100, "exit-button"), s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering Menu state\n";

	return true;
}
bool MenuState::onExit(){

	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("play-button");
	TextureManager::Instance()->clearFromTextureMap("exit-button");

	std::cout << "exiting Menu state\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";
	Game::Instance()->quit();
}
