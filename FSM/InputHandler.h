#ifndef __InputHandler__
#define __InputHandler__

#include <vector>
#include "Vector2D.h"
#include <SDL2/SDL.h>

enum mouse_buttons{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {
	public:
		static InputHandler* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new InputHandler();
			}
			return s_pInstance;
		};

		void update();
		void clean();

		bool getMouseButtonState(int buttonNumber){
			return m_mouseButtonStates[buttonNumber];
		}
		Vector2D* getMousePosition(){
			return m_mousePosition;
		}
		bool isKeyDown(SDL_Scancode key);

	private:

		InputHandler();
		~InputHandler(){}

		//Private function for different event types
		void onKeyDown();
		void onKeyUp();

		void onMouseMove(SDL_Event& event);
		void onMouseButtonDown(SDL_Event& event);
		void onMouseButtonUp(SDL_Event& event);

		//TODO: implement joystics and gamepad support
		std::vector<bool> m_mouseButtonStates;

		Vector2D* m_mousePosition;

		//Only works with const
		const Uint8* m_keyStates;

		static InputHandler* s_pInstance;
};
#endif
