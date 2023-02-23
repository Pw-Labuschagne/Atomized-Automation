#include <stdio.h>

char* Username;
int x_pos;
int y_pos;
int hp;
int lvl;
SDL_Texture* Player_Skin;
SDL_Renderer* Player_Rend;
SDL_Rect Player_Src_Rect, Player_Dest_Rect;

void Player_init()
{
	Player_Skin = Load_Texture("grapical_evidence/skin_1.png", Player_Rend);
}

void Player_Render()
{
}

void Player_Update()
{
}




