#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SDL2/SDL.h"
#include <iostream>

class Graphics{

	public:
		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 640;

	private:

		static Graphics* sInstance;
		static bool sInitialized;

		SDL_Window* Game_Window;
		SDL_Surface* Game_Surface;

	public:

		static Graphics* Instance();
		static void Release();
		static bool Initialized();
		void Render();

	private:

		Graphics();
		~Graphics();

		bool Init();

};

#endif
