#include "../include/GeneralButton.hpp"

GeneralButton::GeneralButton(){
    position_x = 0;
    position_x = 0;
    button_width = 0;
    button_height = 0;
}

void GeneralButton::setPositionSize(int x, int y, int width, int height){
    position_x = x;
    position_x = y;
    button_width = width;
    button_height = height;
}

void GeneralButton::handleEvent(SDL_Event* e, int id){
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        //Check if mouse is in GeneralButton
        bool inside = true;

        //Mouse is left of the GeneralButton
        if( x < position_x )
        {
            inside = false;
        }
        //Mouse is right of the GeneralButton
        else if( x > position_x + button_width )
        {
            inside = false;
        }
        //Mouse above the GeneralButton
        else if( y < position_y )
        {
            inside = false;
        }
        //Mouse below the GeneralButton
        else if( y > position_y + button_height )
        {
            inside = false;
        }

        if (inside)
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEBUTTONDOWN:
                printf("Clicou no botao %d\n", id);
                break;
            }
        }
    }

}

void GeneralButton::setPositionX(int x){
    position_x = x;
}

void GeneralButton::setPositionY(int y){
    position_y = y;
}

void GeneralButton::setGeneralButtonWidth(int width){
    button_width = width;
}

void GeneralButton::setGeneralButtonHeight(int height){
    button_height = height;
}

int GeneralButton::getPositionX(){
    return position_x;
}

int GeneralButton::getPositionY(){
    return position_y;
}

int GeneralButton::getGeneralButtonWidth(){
    return button_width;
}

int GeneralButton::getGeneralButtonHeight(){
    return button_height;
}
