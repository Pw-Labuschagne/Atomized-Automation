#ifndef A_A_H
#define A_A_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Texture_Manager.h"

int GameActive = 0;
const int FPS = 60;
const int Frame_Delay = 1000 / FPS;
SDL_Window* win;
SDL_Texture* Player_Skin;
SDL_Renderer* rend;
SDL_Rect Src_Rect, Dest_Rect;
Uint32 Frame_Start;
int Frame_Time;
const int Screen_Width = 640;
const int Screen_Height = 480;

void GameInit(/*int hp, int lvl, int fullscreen*/);
SDL_Texture* Load_Texture(const char* path, SDL_Renderer* Text_rend);
int main(int argc, char *argv[]);
void EventHandler();
void GameUpdate();
void GameRender();
void Clean();

#endif
