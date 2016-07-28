#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include "LoaderParams.h"

//Abstract Base Class
//Look for alternative systems instead for polmotfism and inheritance with more objects
class GameObject{
	public:

		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

	protected:

		GameObject(const LoaderParams* pParams){}
		virtual ~GameObject() {}

};
#endif
