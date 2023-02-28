#include "Texture_Manager.hpp"

/*Making a simple texture manager*/
SDL_Texture* Texture_Manager::Load_Texture(const char* path)
{

	SDL_Surface* Temp = IMG_Load(path);
	SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::Game_Renderer, Temp);
	SDL_FreeSurface(Temp);

	return Tex;
}

void Texture_Manager::Draw_Map(SDL_Texture* Backg_Tex, SDL_Rect Backg_Src, SDL_Rect Backg_Dest)
{
	SDL_RenderCopy(Game::Game_Renderer, Backg_Tex, &Backg_Src, &Backg_Dest);
}
