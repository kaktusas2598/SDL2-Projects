#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update(){
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void PlayState::render(){
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

}

bool PlayState::onEnter(){
	if (!TextureManager::Instance()->load("assets/helicopter.png",
     "helicopter", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);

	std::cout << "Entering Play state\n";
	return true;
}
bool PlayState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "Exiting Play state\n";
	return true;
}
