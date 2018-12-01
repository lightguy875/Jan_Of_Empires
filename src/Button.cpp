//// "Copyright 2018 Jan_of_Empires"
/**
 * @file Button.cpp
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
#include "../include/Button.hpp"

/**
 * @brief Construct a new Button:: Button object
 * 
 */
Button::Button() {
    position_x = 0;
    position_y = 0;
    button_width = 0;
    button_height = 0;
}
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param width 
 * @param height 
 * @param type 
 */
void Button::setPositionSizeType(int x, int y, int width, int height, ButtonType type) {
    position_x = x;
    position_y = y;
    button_width = width;
    button_height = height;
    buttonType = type;
}

/**
 * @brief 
 * 
 * @param e 
 * @param game 
 */
void Button::handleEvent(SDL_Event* e, Game * game) {
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        // Check if mouse is in Button
        bool inside = false;
        if (y > position_y && y < (position_y + button_height)) {
            if (x > position_x && x < (position_x + button_width)) {
                inside = true;
            }
        }

        if (inside) {
            switch (e->type) {
                case SDL_MOUSEBUTTONDOWN:
                    switch (buttonType) {
                    case BUTTON_PLAY:
                        game->setGameRunning(GAME_PLAY);
                        break;
                    case BUTTON_CREDITS:
                        game->setGameRunning(GAME_CREDITS);
                        break;
                    case BUTTON_QUIT:
                        game->setGameRunning(GAME_QUIT);
                        break;
                    case BUTTON_BACK_CREDITS:
                        game->setGameRunning(GAME_MENU);
                        break;
                    case BUTTON_BACK_GAME:
                        game->setGameRunning(GAME_PLAY);
                    }
                break;
            }
        }
    }
}

/**
 * @brief 
 * 
 * @param x 
 */
void Button::setPositionX(int x) {
    position_x = x;
}

/**
 * @brief 
 * 
 * @param y 
 */
void Button::setPositionY(int y) {
    position_y = y;
}

/**
 * @brief 
 * 
 * @param width 
 */
void Button::setGeneralButtonWidth(int width) {
    button_width = width;
}

/**
 * @brief 
 * 
 * @param height 
 */
void Button::setGeneralButtonHeight(int height) {
    button_height = height;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Button::getPositionX() {
    return position_x;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Button::getPositionY() {
    return position_y;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Button::getGeneralButtonWidth() {
    return button_width;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Button::getGeneralButtonHeight() {
    return button_height;
}

/**
 * @brief 
 * 
 * @param type 
 */
void Button::setButtonType(ButtonType type) {
    buttonType = type;
}

/**
 * @brief 
 * 
 * @return ButtonType 
 */
ButtonType Button::getButtonType() {
    return buttonType;
}
