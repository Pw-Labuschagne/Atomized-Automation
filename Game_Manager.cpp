#include "Game_Manager.hpp"

Game_Manager* Game_Manager::sInstance = NULL;

Game_Manager* Game_Manager::Instance()
{
			
	if(sInstance == NULL)
	{
		sInstance =  new Game_Manager();
	}
	return sInstance;
}

void Game_Manager::Release()
{	
	delete sInstance;

	sInstance = NULL;

}

Game_Manager::Game_Manager()
{
	mQuit = false;
	
	mGraphics = Graphics::Instance();

	if(!Graphics::Initialized())
	{
		mQuit = true;
	}

	mTimer = Timer::Instance();
}

Game_Manager::~Game_Manager()
{
	Graphics::Release();
	mGraphics = NULL;
	Timer::Release();
	mTimer = NULL;
}

void Game_Manager::Run()
{
	while(!mQuit)
	{
		mTimer->Update();		
		while(SDL_PollEvent(&GEV) != 0)
		{
			if(GEV.type == SDL_QUIT)
			{
				mQuit = true;
			}
		}
		
		if(mTimer->DeltaTime() >= (1.0f / FPS))
		{
			mGraphics->Render();
			std::cout << mTimer->DeltaTime() << std::endl;
			mTimer->Reset();
		}

	}
}
