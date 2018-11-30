#ifndef TEXTURE_BUTTON_HPP
#define TEXTURE_BUTTON_HPP

#include "Button.hpp"
#include "Texture.hpp"

#include <SDL2/SDL_ttf.h>

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SQUARE_SIZE 40
#define PLAYER_AREA_START_Y 40
#define PLAYER_AREA_END_Y 560
#define PLAYER_AREA_START_X 120
#define PLAYER_AREA_END_X 680

extern Button menuButtons[ TOTAL_MENU_BUTTONS ];
extern Button pauseButton[2];
extern Button creditsBackButton;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern Texture menu_screen;
extern Texture credit_screen;
extern Texture pause_screen;
extern Texture round_screen;
extern Texture knight[2], solider[2], archer[2];
extern Texture map_screen;
extern TTF_Font * font;
extern Texture textActiveItem, textHP, textBones, textMetal, textRound;
extern Texture pilar_archer[2],pilar_knight[2],pilar_solider[2];
extern Texture bones[20],metal[20];
extern int ativo_x_jog, ativo_y_jog, ativo_x_cpu, ativo_y_cpu;;

#endif
