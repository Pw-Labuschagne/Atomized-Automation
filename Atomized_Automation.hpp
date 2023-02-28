#ifndef GAME_HPP
#define GAME_HPP
/*Game class for Atomized Automation*/

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class Game {

	public:
		Game();
		~Game();
		
		void Game_Init(int x_pos, int y_pos, int width, int height, bool fullscreen);
		void Game_Update();
		void Game_Handler();
		void Game_Render();
		void Cleanup();
		bool Active_Game(){ return Is_Active; }

		static SDL_Renderer *Game_Renderer;

	private:
		bool Is_Active;
		SDL_Window *Game_Window;
};

#endif

