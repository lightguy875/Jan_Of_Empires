
#include "Game.hpp"

#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif

#include "common.hpp"


#ifndef Button_STRUCTURE
#define Button_STRUCTURE

#define TOTAL_MENU_BUTTONS 3

enum ButtonType {
    BUTTON_PLAY,
    BUTTON_CREDITS,
    BUTTON_QUIT,
    BUTTON_BACK_CREDITS,
};

class Button{
    public:
    Button();
    void setPositionSizeType(int x, int y, int width, int height, ButtonType type);
    void handleEvent(SDL_Event* e, Game * game);
    void setPositionX(int x);
    void setPositionY(int y);
    void setGeneralButtonWidth(int width);
    void setGeneralButtonHeight(int height);
    int getPositionX();
    int getPositionY();
    int getGeneralButtonWidth();
    int getGeneralButtonHeight();
    void setButtonType(ButtonType type);
    ButtonType getButtonType();

    private:
    int position_x;
    int position_y;
    int button_width;
    int button_height;
    ButtonType buttonType;
};


#endif
