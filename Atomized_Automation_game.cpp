#include "Atomized_Automation.hpp" 
#include "Texture_Manager.hpp"
#include "Player.hpp"
#include "Map.hpp"


Player* User_Playing;

Map* Cur_Map;


SDL_Renderer* Game::Game_Renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}
	
/*Used to initialize the game
 *
 *Game_Init - Function used to start up the game
 *
 * title:
 * x_pos:
 * width:
 * height:
 * fullscreen:
 */
void Game::Game_Init(int x_pos, int y_pos, int width, int height, bool fullscreen)
{
	int GFlags = 0;

	if(fullscreen)
	{
		GFlags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0 )
	{
		std::cout << "SDL Subsystems Initialized!" << std::endl;
		
		Game_Window = SDL_CreateWindow("Atomized Automation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, GFlags);

		if(Game_Window)
		{
			std::cout << "SDL_WINDOW CREATED!" << std::endl;
			Game_Renderer = SDL_CreateRenderer(Game_Window, -1, 0);

			if(Game_Renderer)
				{
					std::cout << "SDL RENDERER CREATED" << std::endl;
					SDL_SetRenderDrawColor(Game_Renderer, 255, 255, 255, 255);
					Is_Active = true;
				}
			else
				{
					Is_Active = false;
				}
		}
		else
		{
			std::cout << "SDL_ERROR! Window could not be created!" << std::endl;
		}
		
		User_Playing = new Player("Graphical_Evidence/skin_1.png");

		Cur_Map = new Map();
		
	}
}
/**/
void Game::Game_Update()
{

	User_Playing->Player_Update();	

}

/**/
void Game::Game_Handler()
{
	SDL_Event GEV;
	SDL_PollEvent(&GEV);

	switch (GEV.type){
		case SDL_QUIT:
			Is_Active = false;
			break;
		default:
			break;
	}
}

/**/
void Game::Game_Render()
{
	SDL_RenderClear(Game_Renderer);
	Cur_Map->Draw_Map();
	User_Playing->Player_Render();
	SDL_RenderPresent(Game_Renderer);
}

/**/
void Game::Cleanup()
{
	std::cout << "Destroying SDL_RENDERER!" << std::endl;
	SDL_DestroyRenderer(Game_Renderer);
	std::cout << "SDL RENDERER DESTROYED!" << std::endl;
	std::cout << "Destroying SDL_WINDOW!" << std::endl;
	SDL_DestroyWindow(Game_Window);
	std::cout << "SDL WINDOW DESTROYED!" << std::endl;
	std::cout << "Initializing SDL_Quit()" << std::endl;
	SDL_Quit();
	std::cout << "Systems successfully closed." << std::endl;
}
