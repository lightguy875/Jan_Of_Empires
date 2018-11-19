#ifndef SDL_INCLUDES
#define SDL_INCLUDES
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#endif

#include "common.hpp"

class Personage {
    private:
        int position_x;
        int position_y;
        int width;
        int height;

    public:
        Personage();
        void handleEvent(SDL_Event * e);
        void setWidthHeight(int x, int y);
        void move(int x, int y);
        void render(Texture * texture);
        int getPositionX();
        int getPositionY();
        int getWidth();
        int getHeight();
        void setPositionX(int x);
        void setPositionY(int y);
        void setWidth(int w);
        void setHeight(int h);
};
