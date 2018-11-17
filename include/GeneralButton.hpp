#ifndef GeneralButton_STRUCTURE
#define GeneralButton_STRUCTURE
#include "SDL2/SDL.h"
#include <stdio.h>

class GeneralButton{
    public:
    GeneralButton();
    void setPositionSize(int x, int y, int width, int height);
    void handleEvent(SDL_Event* e, int id);
    void setPositionX(int x);
    void setPositionY(int y);
    void setGeneralButtonWidth(int width);
    void setGeneralButtonHeight(int height);
    int getPositionX();
    int getPositionY();
    int getGeneralButtonWidth();
    int getGeneralButtonHeight();

    private:
    int position_x;
    int position_y;
    int button_width;
    int button_height;
};


#endif
