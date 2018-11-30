#include "../include/Button.hpp"


Button::Button(){
    position_x = 0;
    position_y = 0;
    button_width = 0;
    button_height = 0;
}

void Button::setPositionSizeType(int x, int y, int width, int height, ButtonType type){
    position_x = x;
    position_y = y;
    button_width = width;
    button_height = height;
    buttonType = type;
}

void Button::handleEvent(SDL_Event* e, Game * game){
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        //Check if mouse is in Button
        bool inside = false;
        if (y > position_y && y < (position_y + button_height))
        {
            if (x > position_x && x < (position_x + button_width))
            {
                inside = true;
            }
        }

        if (inside)
        {
            switch( e->type )
            {
                case SDL_MOUSEBUTTONDOWN:
                    switch (buttonType)
                    {
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

void Button::setPositionX(int x){
    position_x = x;
}

void Button::setPositionY(int y){
    position_y = y;
}

void Button::setGeneralButtonWidth(int width){
    button_width = width;
}

void Button::setGeneralButtonHeight(int height){
    button_height = height;
}

int Button::getPositionX(){
    return position_x;
}

int Button::getPositionY(){
    return position_y;
}

int Button::getGeneralButtonWidth(){
    return button_width;
}

int Button::getGeneralButtonHeight(){
    return button_height;
}

void Button::setButtonType(ButtonType type){
    buttonType = type;
}

ButtonType Button::getButtonType(){
    return buttonType;
}
