//// "Copyright 2018 Jan_of_Empires"
/**
 * @file common.hpp
 * @author Alex Siqueira (siqueiralex@github.com)
 * @author Alexander André (Alexander-1995@github.com)
 * @author Arthur Veiga (arthurveiga@github.com)
 * @author Matheus Veleci (matheusvsantos@github.com)
 * @author Luis Luz (lightguy875@github.com)
 * @brief
 * @version 0.1
 * @date 2018-12-01
 *
 * @copyright Copyright (c) 2018
 *
 */
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
extern Button pauseButton[2], chooseButton[2];
extern Button creditsBackButton;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern Texture menu_screen;
extern Texture credit_screen;
extern Texture pause_screen;
extern Texture round_screen;
extern Texture knight[2], solider[2], archer[2];
extern Texture map_screen, chooseScreen;
extern Texture ganhou_screen[2];
extern TTF_Font * font;
extern Texture textActiveItem, textHP, textBones, textMetal, textRound;
extern Texture pilar_archer[2],pilar_knight[2],pilar_solider[2];
extern Texture bones[20],metal[20];
extern int ativo_x_jog, ativo_y_jog, ativo_x_cpu, ativo_y_cpu, ganhou_time;
extern bool cpu_or_player;
#endif
