#include <stdio.h>

int lvl;


SDL_Renderer* Enemy_Rend;
SDL_Texture* Enemy_Text;
SDL_Rect Enemy_Src_Rect, Enemy_Dest_rect;

typedef struct 
{	
	SDL_Texture* Enemy_Skin;
	int hp;
	int x_pos;
	int y_pos;
	int count;
}Enemy;

void Enemy_Init()
{
	Enemy_Skin = Load_Texture("grapical_evidence/skin_1.png", Enemy_Rend);
}

void Enemy_Update()
{
}

void Enemy_Render()
{
}
