#include "MenuState.h"
#include <iostream>

const std::string MenuState::s_menuID = 0;

void MenuState::update(){
	//
}
void MenuState::render(){
	//
}

bool MenuState::onEnter(){
	std::cout << "entering Menu state\n";
	return true;
}
bool MenuState::onExit(){
	std::cout << "exiting Menu state\n";
	return true;
}
