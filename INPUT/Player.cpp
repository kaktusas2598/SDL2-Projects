#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams){
}
void Player::draw(){
	SDLGameObject::draw();
}
void Player::update(){

	m_currentFrame = int((SDL_GetTicks() / 100) % 6);

	//m_velocity.setX(1);
	//m_acceleration.setX(0.1f);//was 1
	/*if(InputHandler::Instance()->getMouseButtonState(LEFT)){
		m_velocity.setX(1);
	}*/
	//Vector2D* vec = InputHandler::Instance()->getMousePosition();

	//Follow mouse
	//m_velocity = (*vec - m_position) / 100;
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)){
		m_velocity.setX(2);
	}
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
		m_velocity.setX(-2);
	}
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)){
		m_velocity.setY(-2);
	}
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)){
		m_velocity.setY(2);
	}
	
	SDLGameObject::update();
}
void Player::clean(){
}
