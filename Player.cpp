#include "Player.hpp"
#include "Texture_Manager.hpp"
/**/

Player::Player(const char* path)
{
	Player_Tex = Texture_Manager::Load_Texture(path);

}

/**/
void Player::Player_Update()
{


	x_pos = 0/*User_Player->x_pos*/;
	y_pos = 0/*User_Playing->y_pos*/;

	Player_Src_Rect.w = 32;
	Player_Src_Rect.h = 32;
	Player_Src_Rect.x = 0;
	Player_Src_Rect.y = 0;

	Player_Dest_Rect.w = Player_Src_Rect.w * 2;
	Player_Dest_Rect.h = Player_Src_Rect.h * 2;
	Player_Dest_Rect.x = x_pos;
	Player_Dest_Rect.y = y_pos;
}

/**/
void Player::Player_Render()
{
	SDL_RenderCopy(Game::Game_Renderer, Player_Tex, &Player_Src_Rect, &Player_Dest_Rect);
}
