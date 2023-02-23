#include "A_A.h"

/**/
void GameInit(/*const char* username, int hp, int lvl,*/ int fullscreen)
{
	int Flags = 0;
	
	if (fullscreen == 1)
	{
		Flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("SDL Subsystems Initialized");

		win = SDL_CreateWindow("Atomized Automation",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				Screen_Width,
				Screen_Height,
				Flags);
		if (win)
		{
			printf("Window succesfully created\n");
		}
		else
		{
			printf("Could not create window! SDL_ERROR: %s\n", SDL_GetError());
		}
		rend = SDL_CreateRenderer(win, -1, 0);

		if (rend)
		{
			SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
			printf("Renderer succesfully created\n");
			GameActive = 1;
		}
		else
		{
			printf("Could not create renderer! SDL_ERROR: %s\n", SDL_GetError());
			GameActive = 0;
		}
		Player_Skin = Load_Texture("grapical_evidence/skin_1.png", rend);

	}
}



/**/
void EventHandler()
{
	SDL_Event GEv;
	SDL_PollEvent(&GEv);

	switch (GEv.type)
	{
		case SDL_QUIT:
			{
				GameActive = 0;
				break;
			}
		default:
			{
				break;
			}
	}
}

/**/
void GameUpdate()
{
	Dest_Rect.h = 64;
	Dest_Rect.w = 64;	
}

/**/
void GameRender()
{
	/*Redering code*/
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, Player_Skin, NULL, &Dest_Rect);
	SDL_RenderPresent(rend);
}
/**/
void Clean()
{
	printf("Starting clean");
	SDL_DestroyWindow(win);
	printf("Win dest");
	SDL_DestroyRenderer(rend);
	printf("Rend dest");
	SDL_Quit;
	printf("Game exited, all windows cleaned and exited");
}



int main(int argc, char *argv[])
{
	GameActive = 1;

	/*Constructor*/
	GameInit(0);

	while(GameActive == 1)
	{
		Frame_Start = SDL_GetTicks();

		/*Code for handling use inputs*/
		EventHandler();
		/*Code for updating objects, eg pos, hp ex*/
		GameUpdate();
		/*Code to render*/
		GameRender();

		Frame_Time = SDL_GetTicks() - Frame_Start;

		if (Frame_Delay > Frame_Time)
		{
			SDL_Delay(Frame_Delay - Frame_Time);
		}
	}
	/*Deconstructor*/
	Clean();
}

