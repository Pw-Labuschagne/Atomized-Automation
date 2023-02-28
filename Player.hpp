#ifndef PLAYER_H
#define PLAYER_H

#include "Atomized_Automation.hpp"

class Player {

	public:
		Player(const char * path);
		~Player();

		void Player_Update();
		void Player_Render();

	private:

		SDL_Texture* Player_Tex;
		SDL_Rect Player_Src_Rect, Player_Dest_Rect;
		int x_pos;
		int y_pos;
		int hp;
		int lvl;		
};

#endif
