#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP
#include "Graphics.hpp"
#include "Timer.hpp"

class Game_Manager{

	private:

		static Game_Manager* sInstance;
		
		const int FPS = 120;
		bool mQuit;
		Graphics* mGraphics;
		Timer* mTimer;
		SDL_Event GEV;

	public:

		static Game_Manager* Instance();
		static void Release();

		void Run();

	private:

		Game_Manager();
		~Game_Manager();

};

#endif
