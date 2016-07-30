#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

//Game singleton
class Game{
	public:

		static Game* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new Game();
				return s_pInstance;
			}
			return s_pInstance;
		}

		bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

		void render();
		void update();
		void handleEvents();
		void clean();
		void quit();

		bool running(){ return m_bRunning; }

		SDL_Renderer* getRenderer() const { return m_pRenderer; }

	private:

		Game() {}

		SDL_Window * m_pWindow;
		SDL_Renderer * m_pRenderer;

		int m_currentFrame;

		bool m_bRunning;

		std::vector<GameObject*> m_gameObjects;

		GameStateMachine* m_pGameStateMachine;

		static Game* s_pInstance;
};

#endif
