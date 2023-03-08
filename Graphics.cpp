#include "Graphics.hpp"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;


Graphics* Graphics::Instance()
{
	if(sInstance == NULL)
	{
		sInstance = new Graphics;
	}

	return sInstance;

}


void Graphics::Release()
{

	delete sInstance;
	sInstance = NULL;

	sInitialized = false;

}

bool Graphics::Initialized()
{

	return sInitialized;

}

Graphics::Graphics()
{
	Game_Surface = NULL;
	Game_Window = NULL;
	sInitialized = Init();
}

Graphics::~Graphics()
{

	SDL_DestroyWindow(Game_Window);
	Game_Window = NULL;
	SDL_Quit();
}

bool Graphics::Init()
{

	if (SDL_INIT_VIDEO < 0)
	{
		std::cout << "SDL_Initialation ERROR: " << SDL_GetError << std::endl;
		return false;
	}

	Game_Window = SDL_CreateWindow("Atomized Automation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	
	if(Game_Window == NULL)
	{
		std::cout << "SDL_Window ERROR!: " << SDL_GetError << std::endl;
		return false;
	}
	
	Game_Surface = SDL_GetWindowSurface(Game_Window);

	return true;


}

void Graphics::Render()
{
	SDL_UpdateWindowSurface(Game_Window);	
}
