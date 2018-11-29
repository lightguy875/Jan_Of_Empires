#include "../include/Personage.hpp"

Personage::Personage(){
    position_x = 0;
    position_y = 0;
    width = 0;
    height = 0;
}

void Personage::handleEvent(SDL_Event * e){
    if( e->type == SDL_KEYDOWN )
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_UP:
            move(position_x, position_y-10);
            break;
        case SDLK_DOWN:
            move(position_x, position_y+10);
            break;
        case SDLK_LEFT:
            move(position_x-10, position_y);
            break;
        case SDLK_RIGHT:
            move(position_x+10, position_y);
            break;
        }
    }
}

void Personage::setWidthHeight(int x, int y){
    width = x;
    height = y;
}

void Personage::move(int x, int y){
    position_x = x;
    position_y = y;
    if (x < width/4)
    {
        position_x = width/4 + 1;
    }else if(x > SCREEN_WIDTH - width - (width/4)){
        position_x = SCREEN_WIDTH - width - (width/4);
    }

    if (y < 0)
    {
        position_y = 0;
    }else if(y > SCREEN_HEIGHT - height - 15){
        position_y = SCREEN_HEIGHT - height -15;
    }
}

void Personage::render(Texture * texture){
    texture->render(position_x,position_y);
    textActiveItem.loadFromRenderedText("P1");
    textActiveItem.render(position_x-(width/4),position_y+height+3);
}

int Personage::getPositionX(){
    return position_x;
}

int Personage::getPositionY(){
    return position_y;
}

int Personage::getWidth(){
    return width;
}

int Personage::getHeight(){
    return height;
}

void Personage::setPositionX(int x){
    position_x = x;
}

void Personage::setPositionY(int y){
    position_y = y;
}

void Personage::setWidth(int w){
    width = w;
}

void Personage::setHeight(int h){
    height = h;
}
