#include "Atomized_Automation.hpp"
#include "Texture_Manager.hpp"
class Map
{
	public:
		Map();
		~Map();

		void Load_Map(int arr[25][25]);
		void Draw_Map();

	private:

		SDL_Rect SRC, DEST;
		SDL_Texture* Material;
		SDL_Texture* Water;
		SDL_Texture* Ground;

		int Map_Arr[25][25];
};

