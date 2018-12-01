//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Button.hpp
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
    BUTTON_BACK_GAME,
    BUTTON_CRIAR_PILAR_ARCO,
    BUTTON_CRIAR_PILAR_LANCA,
    BUTTON_CRIAR_PILAR_ESPADA,
    BUTTON_CRIAR_NECRO,
    BUTTON_FORT_PILAR,
    BUTTON_FORT_NECRO,
    BUTTON_CRIAR,
    CANCEL,
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
