#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "Atomized_Automation.hpp"

class Texture_Manager {

	public:
		static SDL_Texture* Load_Texture(const char* path);
		static void Draw_Map(SDL_Texture* Backg_Tex, SDL_Rect Backg_Src, SDL_Rect Backg_Dest);
};

#endif
