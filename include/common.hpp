#ifndef TEXTURE_BUTTON_HPP
#define TEXTURE_BUTTON_HPP

#include "Button.hpp"
#include "Texture.hpp"

extern Button menuButtons[ TOTAL_MENU_BUTTONS ];
extern Button pauseButton[2];
extern Button creditsBackButton;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern Texture menu_screen;
extern Texture credit_screen;
extern Texture pause_screen;
extern Texture round_screen;

#endif
