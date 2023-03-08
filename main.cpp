#include "Game_Manager.hpp"

int main(int argc, char* argv[])
{
	
	Game_Manager* Game = Game_Manager::Instance();

	Game->Run();

	Game->Release();

	return 0;
}
