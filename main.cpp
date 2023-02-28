#include "Atomized_Automation.hpp"

Game *A_AGame = nullptr;

int main(int argc, const char* argv[])
{
	A_AGame = new Game();
	/*Limiting frame rate of the game*/
	const int FPS = 60;
	const int Frame_Delay = 1000 / FPS;

	Uint32 Frame_Start;
	int Frame_Time;


	A_AGame->Game_Init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640,false);

	while(A_AGame->Active_Game())
	{
		Frame_Start = SDL_GetTicks();

		A_AGame->Game_Handler();
		A_AGame->Game_Update();
		A_AGame->Game_Render();

		Frame_Time = SDL_GetTicks() - Frame_Start;

		if(Frame_Delay > Frame_Time)
		{
			SDL_Delay(Frame_Delay - Frame_Time);
		}
	}

	A_AGame->Cleanup();

	return 0;
}
