#include "Texture_Manager.h"

SDL_Texture* Load_Texture(const char* path, SDL_Renderer* Text_Rend)
{
	SDL_Surface* temp_Surface = IMG_Load(path);
	SDL_Texture* Textures = SDL_CreateTextureFromSurface(Text_Rend, temp_Surface);
	SDL_FreeSurface(temp_Surface);
	return(Textures);

}
