#ifndef TEXTURE_BUTTON_HPP
#define TEXTURE_BUTTON_HPP

#include "Button.hpp"
#include "Texture.hpp"

#include <SDL2/SDL_ttf.h>

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

extern Button menuButtons[ TOTAL_MENU_BUTTONS ];
extern Button pauseButton[2];
extern Button creditsBackButton;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern Texture menu_screen;
extern Texture credit_screen;
extern Texture pause_screen;
extern Texture round_screen;
extern Texture knight, solider, archer;
extern Texture map_screen;
extern TTF_Font * font;
extern Texture textActiveItem;
extern Texture castle[3];

#endif
